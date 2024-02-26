#!/usr/bin/env python


def depends(ctx):
    ctx('rant')
    ctx('ztl')
    ctx('pywrap') # also needed in non-python mode! (compatibility headers!)
    ctx('lib-boost-patches')
    if getattr(ctx.options, 'with_halco_on_ppu', True):
        ctx('libnux')
    ctx('hate')


def options(opt):
    opt.load('compiler_cxx')
    opt.load('boost')
    opt.recurse('pyhalco')

    hopts = opt.add_option_group('halco options')
    hopts.add_withoption('halco-python-bindings', default=True,
                         help='Toggle the generation and build of halco python bindings')
    hopts.add_withoption('halco-on-ppu', default=True,
                         help='Toggle the generation and build of halco for the PPU')


def configure(conf):
    conf.load('compiler_cxx')
    conf.load('boost')

    conf.check_cxx(mandatory=True, header_name='cereal/cereal.hpp')

    if getattr(conf.options, 'with_halco_python_bindings', True):
        conf.recurse('pyhalco')

    conf.env.CXXFLAGS_HALCO = [
        '-fvisibility=hidden',
        '-fvisibility-inlines-hidden',
    ]
    conf.env.LINKFLAGS_HALCO = [
        '-fvisibility=hidden',
        '-fvisibility-inlines-hidden',
    ]


def build(bld):
    bld.install_files(
        dest='${PREFIX}/',
        files=bld.path.ant_glob('include/halco/**/*.(h|def|tcc)'),
        name='halco_header',
        relative_trick=True
    )

    bld(
        target='halco_inc',
        export_includes=['include'],
        depends_on='halco_header',
    )

    bld.shlib(
        target='halco_common',
        source=bld.path.ant_glob('src/halco/common/*.cpp'),
        install_path='${PREFIX}/lib',
        linkflags='-Wl,-z,defs',
        uselib='HALCO',
        use=['rant', 'ZTL', 'pywrap', 'halco_inc',
             'LOG4CXX', 'boost_serialization', 'hate_inc'],
    )

    bld.shlib(
        target='halco_hicann_v2',
        source=bld.path.ant_glob('src/halco/hicann/v2/*.cpp'),
        install_path='${PREFIX}/lib',
        linkflags='-Wl,-z,defs',
        uselib='HALCO',
        use=['halco_common'],
        defines=['BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS',
                 'BOOST_MPL_LIMIT_LIST_SIZE=30'],
        export_defines=['BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS',
                        'BOOST_MPL_LIMIT_LIST_SIZE=30'],
    )

    if getattr(bld.options, 'with_halco_on_ppu', True) and bld.env.have_ppu_toolchain:
        env = bld.all_envs['nux_vx'].derive()
        env.detach()

        bld.stlib(
            target='halco_common_ppu_vx',
            source=bld.path.ant_glob('src/halco/common/*.cpp'),
            install_path='${PREFIX}/lib/ppu',
            uselib='HALCO',
            use=['halco_inc', 'ZTL', 'rant', 'pywrap_inc', 'hate_inc'],
            env=env,
            linkflags='-Wl,-z,defs',
        )

    bld.shlib(
        target='halco_hicann_dls_vx',
        source=bld.path.ant_glob('src/halco/hicann-dls/vx/*.cpp'),
        install_path='${PREFIX}/lib',
        linkflags='-Wl,-z,defs',
        use=['halco_common'],
        uselib='HALCO',
    )

    bld.shlib(
        target='halco_hicann_dls_vx_serialization',
        source=bld.path.ant_glob('src/cereal/types/halco/hicann-dls/vx/*.cpp'),
        install_path='${PREFIX}/lib',
        linkflags='-Wl,-z,defs',
        use=['halco_hicann_dls_vx'],
    )

    for hx_version in [3, 4]:
        bld.shlib(
            target='halco_hicann_dls_vx_v%s' % hx_version,
            source=bld.path.ant_glob('src/halco/hicann-dls/vx/v%s/*.cpp' % hx_version,
                                     excl=['**/py*.cpp']),
            install_path='${PREFIX}/lib',
            linkflags='-Wl,-z,defs',
            use=['halco_common', 'halco_hicann_dls_vx'],
            uselib='HALCO',
        )

        bld.shlib(
            target='halco_hicann_dls_vx_v%s_serialization' % hx_version,
            source=bld.path.ant_glob('src/cereal/types/halco/hicann-dls/vx/v%s/*.cpp' % hx_version),
            install_path='${PREFIX}/lib',
            linkflags='-Wl,-z,defs',
            use=[f'halco_hicann_dls_vx_v{hx_version}', 'halco_hicann_dls_vx_serialization'],
        )

    if getattr(bld.options, 'with_halco_on_ppu', True) and bld.env.have_ppu_toolchain:
        env = bld.all_envs['nux_vx'].derive()
        env.detach()

        bld.stlib(
            target='halco_hicann_dls_ppu_vx',
            source=bld.path.ant_glob('src/halco/hicann-dls/vx/*.cpp'),
            install_path='${PREFIX}/lib/ppu',
            linkflags='-Wl,-z,defs',
            use=['halco_common_ppu_vx'],
            uselib='HALCO',
            env = env,
        )

        for hx_version in [3, 4]:
            env = bld.all_envs['nux_vx_v%s' % hx_version].derive()
            env.detach()

            bld.stlib(
                target='halco_hicann_dls_ppu_vx_v%s' % hx_version,
                source=bld.path.ant_glob('src/halco/hicann-dls/vx/v%s/*.cpp' % hx_version,
                                         excl=['**/py*.cpp']),
                install_path='${PREFIX}/lib/ppu',
                linkflags='-Wl,-z,defs',
                use=['halco_common_ppu_vx', 'halco_hicann_dls_ppu_vx'],
                uselib='HALCO',
                env = env,
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

    for hx_version in [3, 4]:
        coordinates = list()
        coordinates_def_path = str(bld.path.get_src()) + f"/include/halco/hicann-dls/vx/v{hx_version}/coordinates.def"
        with open(coordinates_def_path) as coordinates_def:
            lines = coordinates_def.readlines()
            for line in lines:
                if not line.startswith("COORDINATE") or line.startswith("LAST_COORDINATE"):
                    continue
                typename = line.split(", ")[1].replace(")\n", "")
                coordinates.append(typename)

        common_obj_targets = []
        num_coordinates_per_obj = 10
        for i, typenames in enumerate([
                coordinates[i:i + num_coordinates_per_obj]
                for i in range(0, len(coordinates), num_coordinates_per_obj)]):
            bld(
                target=f'halco_hicann_dls_vx_v{hx_version}_tests_obj_{i}',
                features='cxx',
                source=bld.path.ant_glob('test/hicann-dls/vx/v%s/common.cpp' % hx_version),
                use=['halco_hicann_dls_vx_v%s' % hx_version, 'GTEST', 'halco_test_inc'],
                defines=[f'BUILD_ENV_COORDINATE_TYPES={", ".join(typenames)}'],
            )

        bld(
            target='halco_hicann_dls_vx_v%s_tests' % hx_version,
            features='gtest cxx cxxprogram',
            source=bld.path.ant_glob(
                'test/hicann-dls/vx/v%s/*.cpp' % hx_version,
                excl='test/hicann-dls/vx/v%s/common.cpp' % hx_version),
            use=['halco_hicann_dls_vx_v%s' % hx_version, 'GTEST', 'halco_test_inc'] + common_obj_targets,
            install_path='${PREFIX}/bin'
        )

    if getattr(bld.options, 'with_halco_python_bindings', True):
        bld.recurse('pyhalco')
