#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/*****************\
   MADC
\*****************/

struct GENPYBIND(inline_base("*")) MADCControlOnDLS
    : public common::detail::RantWrapper<MADCControlOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit MADCControlOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::MADCControlOnDLS)

} // namespace std
