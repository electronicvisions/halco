#!/usr/bin/env python
import sys,os, re, logging, argparse

from pyplusplus.module_builder import call_policies
from pywrap.wrapper import Wrapper
from pywrap import containers, namespaces, matchers, classes, functions
from pywrap.namespace_util import NamespaceUtil
from pygccxml.declarations import templates
from pyplusplus import decl_wrappers, messages

wrap = Wrapper()
mb = wrap.mb

classes.log.setLevel(logging.WARN)
messages.disable(messages.W1043) # Ugly names
messages.disable(messages.W1066) # Not exposed typedefs

# propagate constructor "explictness" to python
for cls in mb.classes(allow_empty=True):
    cls.constructors(lambda cpp_func: cpp_func.explicit == True, allow_empty=True).allow_implicit_conversion = False
    for base in classes.get_all_bases(cls):
        base.constructors(lambda cpp_func: cpp_func.explicit is True, allow_empty=True).allow_implicit_conversion = False

ns_coordinate  = mb.namespace("::halco::hicann::v2")
ns_common      = mb.namespace("::halco::common")
ns_detail      = mb.namespace("::halco::common::detail")

for ns in ['::boost::serialization', '::boost::archive', '::boost::mpi']:
    try:
        mb.namespace(ns).exclude()
    except matchers.declaration_not_found_t:
        pass


def is_coordinate(c):
    """
    A coordinate is anything that is contained in or has a typedef in
    the ::halco::hicann::v2 namespace.
    """
    m = matchers.namespace_contains_matcher_t
    return m(ns_coordinate.name)(c)


# Special fix up
containers.extend_std_containers(mb)
namespaces.include_default_copy_constructors(mb)

# Normally included classes
for ns in [ns_coordinate, ns_common, ns_detail]:
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


c = mb.class_('::boost::asio::ip::address_v4')
c.alias = "IPv4"
c.include()
classes.add_comparison_operators(c)
classes.expose_std_hash(c)
c.add_registration_code('def(bp::self == bp::self)')
c.include_files.append('pywrap/print_helper.hpp')
c.add_registration_code('def(pywrap::PrintNice())')
classes.add_pickle_suite(c)

for cls in ns_coordinate.classes():
    if any(cls.name.startswith(pre) for pre in ["WaferMixin", "HICANNMixin", "MergerProxy"]):
        cls.alias = '_' + cls.alias

for ns in [ns_coordinate, ns_common, ns_detail]:
    for fun in ns.free_functions("hash_value"):
        fun.exclude()

# Try to capture the std::container dependencies
std_filter = matchers.and_matcher_t([
    matchers.declaration_matcher_t(decl_type=decl_wrappers.class_t),
    matchers.namespace_contains_matcher_t("std")
])

for ns in [ns_coordinate]:
    for decl in namespaces.get_deps(ns_coordinate, matchers.namespace_contains_matcher_t("std")):
        if decl.indexing_suite or decl.name.startswith("bitset"):
            decl.include()

# std::hash specialisations are only used from within the member hash functions
mb.classes(matchers.match_std_container_t("hash"), allow_empty=True).exclude()

# include base classes
for cl in mb.classes():
    if cl.ignore:
        continue
    for cl in classes.get_all_bases(cl):
        cl.include()

# expose only public interfaces
namespaces.exclude_by_access_type(mb, ['variables', 'calldefs', 'classes'], 'private')
namespaces.exclude_by_access_type(mb, ['variables', 'calldefs', 'classes'], 'protected')

# exclude names begining with a single underscore or ending with Cpp
namespaces.exclude_by_regex(mb, ['calldefs', 'classes', 'variables'], r'(^_[^_])|(.*Cpp$)|(^impl$)')

# Add python import callback
mb.add_registration_code(
    'bp::import("pyhalco_hicann_v2_patch").attr("patch")(bp::scope());')

c = mb.typedef('::halco::hicann::v2::format_type').decl_type.declaration
c.include()

classes.add_variant_converters_for(mb, mb.typedef('::halco::hicann::v2::format_type').target_decl)

for cl in ns_coordinate.classes(allow_empty=True):
    for fun in cl.mem_funs(allow_empty=True):
        functions.return_optional_by_value(fun)

wrap.set_number_of_files(5)

wrap.finish()
