#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/************\
    Systime
\************/

struct GENPYBIND(inline_base("*")) SystimeSyncOnFPGA
    : public common::detail::RantWrapper<SystimeSyncOnFPGA, uint_fast16_t, 0, 0>
{
	constexpr explicit SystimeSyncOnFPGA(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*")) SystimeSyncBaseOnDLS
    : public common::detail::RantWrapper<SystimeSyncBaseOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit SystimeSyncBaseOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


/************\
    Timer
\************/

struct GENPYBIND(inline_base("*")) TimerOnDLS
    : public common::detail::RantWrapper<TimerOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit TimerOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SystimeSyncOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SystimeSyncBaseOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::TimerOnDLS)

} // namespace std
