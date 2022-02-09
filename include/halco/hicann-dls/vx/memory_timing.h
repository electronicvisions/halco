#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/***************\
  MemoryTiming
\***************/

struct GENPYBIND(inline_base("*")) MemoryTimingOnDLS
    : public common::detail::RantWrapper<MemoryTimingOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit MemoryTimingOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::MemoryTimingOnDLS)

} // namespace std
