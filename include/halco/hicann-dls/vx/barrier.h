#pragma once
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"

namespace halco::hicann_dls { namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) BarrierOnFPGA
    : public common::detail::RantWrapper<BarrierOnFPGA, uint_fast8_t, 0, 0>
    , common::CoordinateBase<BarrierOnFPGA>
{
	constexpr explicit BarrierOnFPGA(uintmax_t const val = 0) : base_t(val) {}
};

} // namespace vx
} // namespace halco::hicann_dls

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::BarrierOnFPGA)

} // namespace std
