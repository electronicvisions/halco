#!/usr/bin/env python
import sys,os, re, logging, argparse

from pyplusplus.module_builder import call_policies
from pywrap.wrapper import Wrapper
from pywrap import containers, namespaces, matchers, classes
from pywrap.namespace_util import NamespaceUtil
from pygccxml.declarations import templates
from pyplusplus import decl_wrappers, messages

# FIXME: fix py++ to include our headers before boost python headers
wrap = Wrapper()
mb = wrap.mb


# Less noise
classes.log.setLevel(logging.WARN)

messages.disable(messages.W1043) # Ugly names, who cares? ...
messages.disable(messages.W1066) # Not exposed typedefs

# propagate constructor "explictness" to python
for cls in mb.classes(allow_empty=True):
    cls.constructors(lambda cpp_func: cpp_func.explicit == True, allow_empty=True).allow_implicit_conversion = False
    for base in classes.get_all_bases(cls):
        base.constructors(lambda cpp_func: cpp_func.explicit is True, allow_empty=True).allow_implicit_conversion = False

ns_coordinate  = mb.namespace("::halco::common")
ns_detail      = mb.namespace("::halco::common::detail")
ns_std         = mb.namespace("::std")

for ns in ['::boost::serialization', '::boost::archive', '::boost::mpi']:
    try:
        mb.namespace(ns).exclude()
    except matchers.declaration_not_found_t:
        pass



def is_coordinate(c):
    """
    A coordinate is anything that is contained in or has a typedef in
    the ::halco::common namespace.
    """
    m = matchers.namespace_contains_matcher_t
    if m(ns_detail.name)(c):
        return any(m(ns_coordinate.name)(x) for x in c.aliases)
    return m(ns_coordinate.name)(c)


# Special fix up
containers.extend_std_containers(mb)
namespaces.include_default_copy_constructors(mb)

# Normally included classes
for ns in [ns_coordinate]:
    ns.include()
    namespaces.extend_array_operators(ns)

    for c in ns.classes(allow_empty=True):
        if not is_coordinate(c):
            continue

        c.include()

        c.add_registration_code('def(bp::self_ns::str(bp::self_ns::self))')
        classes.add_pickle_suite(c)
        classes.add_comparison_operators(c)
        classes.expose_std_hash(c)
ns_std.exclude()

c = mb.class_('::boost::asio::ip::address_v4')
c.alias = "IPv4"
c.include()
classes.add_comparison_operators(c)
classes.expose_std_hash(c)
c.add_registration_code('def(bp::self == bp::self)')
c.include_files.append('pywrap/print_helper.hpp')
c.add_registration_code('def(pywrap::PrintNice())')
classes.add_pickle_suite(c)

for cls in ns_detail.classes():
    cls.alias = '_' + cls.alias

for ns in [ns_coordinate, ns_detail]:
    for fun in ns.free_functions("hash_value"):
        fun.exclude()

# expose only public interfaces
namespaces.exclude_by_access_type(mb, ['variables', 'calldefs', 'classes'], 'private')
namespaces.exclude_by_access_type(mb, ['variables', 'calldefs', 'classes'], 'protected')

# exclude names begining with a single underscore or ending with Cpp or are named Coordinate
namespaces.exclude_by_regex(mb, ['calldefs', 'classes', 'variables'], r'(^_[^_])|(.*Cpp$)|(^impl$)|Coordinate')

# Add python import callback
mb.add_registration_code(
    'bp::import("pyhalco_common_patch_pypp").attr("patch")(bp::scope());')

wrap.set_number_of_files(0)

wrap.finish()
