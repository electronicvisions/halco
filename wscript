#!/usr/bin/env python


def depends(ctx):
    ctx('rant')
    ctx('ztl')
    ctx('logger')
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

    conf.check_cxx(lib='log4cxx', uselib_store='LOG4CXXHALCO', mandatory=1)
    conf.check_cxx(mandatory=True, header_name='cereal/cereal.hpp')

    if conf.env.build_python_bindings:
        conf.recurse("pyhalco")


def build(bld):
    bld(
        target          = 'halco_common_inc',
        use             = ['ZTL', 'rant', 'pywrap_inc',  'boost_serialization'],
        export_includes = ['.'],
    )

    bld.shlib(
        target          = 'halco_common',
        source          = bld.path.ant_glob('halco/common/*.cpp'),
        install_path    = '${PREFIX}/lib',
        linkflags       = '-Wl,-z,defs',
        cxxflags        = ['-Werror'],
        use             = ['halco_common_inc', 'LOG4CXX'],
    )

    bld(
        target          = 'halco_hicann_v2_inc',
        use             = ['halco_common_inc', 'boost_serialization'],
        export_includes = ['.'],
    )

    bld.shlib(
        target          = 'halco_hicann_v2',
        source          = bld.path.ant_glob('halco/hicann/v2/*.cpp'),
        install_path    = '${PREFIX}/lib',
        linkflags      = '-Wl,-z,defs',
        use             = ['halco_hicann_v2_inc', 'halco_common', 'BOOST4HALCO'],
    )

    bld(
        target="halco_hicann_dls_v2_inc",
        use=["halco_common_inc"],
        export_includes=["."],
    )

    bld.shlib(
        target="halco_hicann_dls_v2",
        source=bld.path.ant_glob("halco/hicann-dls/v2/*.cpp"),
        install_path="${PREFIX}/lib",
        use=["halco_hicann_dls_v2_inc", "halco_common", "BOOST4HALCO"],
    )

    bld(
        target="halco_hicann_dls_vx_inc",
        use=["halco_common_inc"],
        export_includes=["."],
    )

    bld.shlib(
        target="halco_hicann_dls_vx",
        source=bld.path.ant_glob("halco/hicann-dls/vx/*.cpp"),
        install_path="${PREFIX}/lib",
        use=["halco_hicann_dls_vx_inc", "halco_common", "BOOST4HALCO"],
    )

    bld(
        target       = 'halco_hicann_v2_tests',
        features     = 'gtest cxx cxxprogram',
        source       = bld.path.ant_glob('test/hicann/v2/*.cpp'),
        use          = ['halco_hicann_v2','logger_obj', 'GTEST', 'BOOST4TOOLS', 'pythonic'],
        install_path = '${PREFIX}/bin'
    )

    bld(
        target="halco_hicann_dls_v2_tests",
        features="gtest cxx cxxprogram",
        source=bld.path.ant_glob("test/hicann-dls/v2/*.cpp"),
        use=["halco_hicann_dls_v2", "GTEST", "BOOST4TOOLS"],
        install_path="${PREFIX}/bin"
    )

    bld(
        target="halco_hicann_dls_vx_tests",
        features="gtest cxx cxxprogram",
        source=bld.path.ant_glob("test/hicann-dls/vx/*.cpp"),
        use=["halco_hicann_dls_vx", "GTEST", "BOOST4TOOLS"],
        install_path="${PREFIX}/bin"
    )

    if bld.env.build_python_bindings:
            bld.recurse("pyhalco")
