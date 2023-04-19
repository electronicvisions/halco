#pragma once
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

#include "halco/hicann-dls/vx/hemisphere_fwd.h"

/************\
    Synram
\************/

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) SynramOnDLS
    : public common::detail::RantWrapper<SynramOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<SynramOnDLS>
{
	constexpr explicit SynramOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const SynramOnDLS top;
	static const SynramOnDLS bottom;
};

HALCO_COORDINATE_MIXIN(SynramMixin, SynramOnDLS, synram)


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    CommonSynramConfigOnDLS
    : public common::detail::RantWrapper<CommonSynramConfigOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<CommonSynramConfigOnDLS>
{
	constexpr explicit CommonSynramConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const CommonSynramConfigOnDLS top;
	static const CommonSynramConfigOnDLS bottom;
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynramOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonSynramConfigOnDLS)

} // namespace std
