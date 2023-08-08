#pragma once

#if defined(__has_include) && !defined(PYPLUSPLUS)
#if __has_include(<genpybind.h>)
#include <genpybind.h>
#else
#define GENPYBIND(...)
#define GENPYBIND_MANUAL(...)
#endif
#else
#define GENPYBIND(...)
#define GENPYBIND_MANUAL(...)
#endif

#define GENPYBIND_TAG_HALCO_COMMON GENPYBIND(tag(common))
#define GENPYBIND_TAG_HALCO_HICANN_V2 GENPYBIND(tag(hicann_v2))
#define GENPYBIND_TAG_HALCO_HICANN_DLS_VX GENPYBIND(tag(hicann_dls_vx))
#define GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V2 GENPYBIND(tag(hicann_dls_vx_v2))
#define GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V3 GENPYBIND(tag(hicann_dls_vx_v3))
#define GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V4 GENPYBIND(tag(hicann_dls_vx_v4))
