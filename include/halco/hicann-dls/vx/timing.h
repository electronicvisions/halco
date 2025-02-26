#pragma once
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"

namespace halco::hicann_dls { namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/************\
    Systime
\************/

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) SystimeSyncOnFPGA
    : public common::detail::RantWrapper<SystimeSyncOnFPGA, uint_fast16_t, 0, 0>
    , common::CoordinateBase<SystimeSyncOnFPGA>
{
	constexpr explicit SystimeSyncOnFPGA(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) SystimeSyncBaseOnDLS
    : public common::detail::RantWrapper<SystimeSyncBaseOnDLS, uint_fast16_t, 0, 0>
    , common::CoordinateBase<SystimeSyncBaseOnDLS>
{
	constexpr explicit SystimeSyncBaseOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


/************\
    Timer
\************/

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) TimerOnDLS
    : public common::detail::RantWrapper<TimerOnDLS, uint_fast16_t, 0, 0>
    , common::CoordinateBase<TimerOnDLS>
{
	constexpr explicit TimerOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*")) WaitUntilOnFPGA
    : public common::detail::RantWrapper<WaitUntilOnFPGA, uint_fast16_t, 0, 0>
{
	constexpr explicit WaitUntilOnFPGA(uintmax_t const val = 0) : rant_t(val) {}
};

} // namespace vx
} // namespace halco::hicann_dls

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SystimeSyncOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SystimeSyncBaseOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::TimerOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::WaitUntilOnFPGA)

} // namespace std
