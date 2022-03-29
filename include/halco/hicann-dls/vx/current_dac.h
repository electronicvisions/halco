#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct GENPYBIND(inline_base("*")) CurrentDACOnDLS
    : public common::detail::RantWrapper<CurrentDACOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit CurrentDACOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


} // namespace halco::hicann::dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CurrentDACOnDLS)

} // namespace std
