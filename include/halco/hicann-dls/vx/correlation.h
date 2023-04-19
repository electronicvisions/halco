#pragma once
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

#include "halco/hicann-dls/vx/hemisphere_fwd.h"

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    CommonCorrelationConfigOnDLS
    : public common::detail::RantWrapper<CommonCorrelationConfigOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<CommonCorrelationConfigOnDLS>
{
	constexpr explicit CommonCorrelationConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const CommonCorrelationConfigOnDLS top;
	static const CommonCorrelationConfigOnDLS bottom;
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonCorrelationConfigOnDLS)

} // namespace std
