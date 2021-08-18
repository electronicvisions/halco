#!/usr/bin/env python


def depends(ctx):
    ctx('rant')
    ctx('ztl')
    ctx('pywrap') # also needed in non-python mode! (compatibility headers!)
    ctx('lib-boost-patches')


def options(opt):
    opt.load('compiler_cxx')
    opt.load('boost')
    opt.recurse('pyhalco')

    hopts = opt.add_option_group('halco options')
    hopts.add_withoption('halco-python-bindings', default=True,
                         help='Toggle the generation and build of halco python bindings')


def configure(conf):
    conf.load('compiler_cxx')
    conf.load('boost')

    conf.check_cxx(mandatory=True, header_name='cereal/cereal.hpp')

    if getattr(conf.options, 'with_halco_python_bindings', True):
        conf.recurse('pyhalco')


def build(bld):
    bld(
        target='halco_inc',
        export_includes=['include'],
    )

    bld.shlib(
        target='halco_common',
        source=bld.path.ant_glob('src/halco/common/*.cpp'),
        install_path='${PREFIX}/lib',
        linkflags='-Wl,-z,defs',
        use=['rant', 'ZTL', 'pywrap', 'halco_inc',
             'LOG4CXX', 'boost_serialization'],
    )

    bld.shlib(
        target='halco_hicann_v2',
        source=bld.path.ant_glob('src/halco/hicann/v2/*.cpp'),
        install_path='${PREFIX}/lib',
        linkflags='-Wl,-z,defs',
        use=['halco_common'],
        defines=['BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS',
                 'BOOST_MPL_LIMIT_LIST_SIZE=30'],
        export_defines=['BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS',
                        'BOOST_MPL_LIMIT_LIST_SIZE=30'],
    )

    bld.shlib(
        target='halco_hicann_dls_vx',
        source=bld.path.ant_glob('src/halco/hicann-dls/vx/*.cpp'),
        install_path='${PREFIX}/lib',
        linkflags='-Wl,-z,defs',
        use=['halco_common'],
    )

    for hx_version in [1, 2]:
        bld.shlib(
            target='halco_hicann_dls_vx_v%s' % hx_version,
            source=bld.path.ant_glob('src/halco/hicann-dls/vx/v%s/*.cpp' % hx_version,
                                     excl=['**/py*.cpp']),
            install_path='${PREFIX}/lib',
            linkflags='-Wl,-z,defs',
            use=['halco_common', 'halco_hicann_dls_vx'],
        )

    bld(
        target='halco_test_inc',
        export_includes=['test'],
    )

    bld(
        target='halco_common_tests',
        features='gtest cxx cxxprogram',
        source=bld.path.ant_glob('test/common/*.cpp'),
        use=['halco_common', 'GTEST'],
        install_path='${PREFIX}/bin'
    )

    bld(
        target='halco_hicann_v2_tests',
        features='gtest cxx cxxprogram',
        source=bld.path.ant_glob('test/hicann/v2/*.cpp'),
        use=['halco_hicann_v2', 'GTEST', 'halco_test_inc'],
        install_path='${PREFIX}/bin'
    )

    for hx_version in [1, 2]:
        bld(
            target='halco_hicann_dls_vx_v%s_tests' % hx_version,
            features='gtest cxx cxxprogram',
            source=bld.path.ant_glob('test/hicann-dls/vx/v%s/*.cpp' % hx_version),
            use=['halco_hicann_dls_vx_v%s' % hx_version, 'GTEST', 'halco_test_inc'],
            install_path='${PREFIX}/bin'
        )

    if getattr(bld.options, 'with_halco_python_bindings', True):
        bld.recurse('pyhalco')
