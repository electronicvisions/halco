#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/***************\
    ResetChip
\***************/

struct GENPYBIND(inline_base("*")) ResetChipOnDLS
    : public common::detail::RantWrapper<ResetChipOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit ResetChipOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ResetChipOnDLS)

} // namespace std
