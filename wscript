#!/usr/bin/env python


def depends(ctx):
    ctx('rant')
    ctx('ztl')
    ctx('pywrap')
    ctx('lib-boost-patches')


def options(opt):
    opt.load('compiler_cxx')
    opt.load('boost')
    opt.recurse("pyhalco")


def configure(conf):
    conf.load('compiler_cxx')
    conf.load('boost')
    conf.load('pytest')
    conf.check_boost(lib='program_options system',
            uselib_store='BOOST4TOOLS')
    conf.check_boost(lib='system serialization iostreams filesystem thread',
            uselib_store='BOOST4HALCO')

    conf.check_cxx(mandatory=True, header_name='cereal/cereal.hpp')

    conf.recurse("pyhalco")


def build(bld):
    bld(
        target          = 'halco_inc',
        use             = ['ZTL', 'rant', 'pywrap_inc',  'boost_serialization'],
        export_includes = ['include'],
    )

    bld.shlib(
        target          = 'halco_common',
        source          = bld.path.ant_glob('src/halco/common/*.cpp'),
        install_path    = '${PREFIX}/lib',
        linkflags       = '-Wl,-z,defs',
        use             = ['halco_inc', 'LOG4CXX'],
    )

    bld.shlib(
        target          = 'halco_hicann_v2',
        source          = bld.path.ant_glob('src/halco/hicann/v2/*.cpp'),
        install_path    = '${PREFIX}/lib',
        linkflags       = '-Wl,-z,defs',
        use             = ['halco_common', 'BOOST4HALCO'],
    )

    bld.shlib(
        target="halco_hicann_dls_v2",
        source=bld.path.ant_glob("src/halco/hicann-dls/v2/*.cpp"),
        install_path="${PREFIX}/lib",
        use=["halco_common", "BOOST4HALCO"],
    )

    bld.shlib(
        target="halco_hicann_dls_vx",
        source=bld.path.ant_glob("src/halco/hicann-dls/vx/*.cpp"),
        install_path="${PREFIX}/lib",
        use=["halco_common", "BOOST4HALCO"],
    )

    bld(
        target='halco_test_inc',
        export_includes=['test'],
    )

    bld(
        target       = 'halco_common_tests',
        features     = 'gtest cxx cxxprogram',
        source       = bld.path.ant_glob('test/common/*.cpp'),
        use          = ['halco_common', 'GTEST'],
        install_path = '${PREFIX}/bin'
    )

    bld(
        target       = 'halco_hicann_v2_tests',
        features     = 'gtest cxx cxxprogram',
        source       = bld.path.ant_glob('test/hicann/v2/*.cpp'),
        use          = ['halco_hicann_v2', 'GTEST', 'BOOST4TOOLS', 'pythonic', 'halco_test_inc'],
        install_path = '${PREFIX}/bin'
    )

    bld(
        target="halco_hicann_dls_v2_tests",
        features="gtest cxx cxxprogram",
        source=bld.path.ant_glob("test/hicann-dls/v2/*.cpp"),
        use=["halco_hicann_dls_v2", "GTEST", "BOOST4TOOLS", 'halco_test_inc'],
        install_path="${PREFIX}/bin"
    )

    bld(
        target="halco_hicann_dls_vx_tests",
        features="gtest cxx cxxprogram",
        source=bld.path.ant_glob("test/hicann-dls/vx/*.cpp"),
        use=["halco_hicann_dls_vx", "GTEST", "BOOST4TOOLS", 'halco_test_inc'],
        install_path="${PREFIX}/bin"
    )

    bld.recurse("pyhalco")
