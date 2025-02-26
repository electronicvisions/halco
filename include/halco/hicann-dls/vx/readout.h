#pragma once
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"

namespace halco::hicann_dls { namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) PadOnDLS
    : public common::detail::RantWrapper<PadOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<PadOnDLS>
{
	constexpr explicit PadOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    PadMultiplexerConfigOnDLS
    : public common::detail::RantWrapper<PadMultiplexerConfigOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<PadMultiplexerConfigOnDLS>
{
	constexpr explicit PadMultiplexerConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    ReadoutSourceSelectionOnDLS
    : public common::detail::RantWrapper<ReadoutSourceSelectionOnDLS, uint_fast16_t, 0, 0>
    , common::CoordinateBase<ReadoutSourceSelectionOnDLS>
{
	constexpr explicit ReadoutSourceSelectionOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*")) SourceMultiplexerOnReadoutSourceSelection
    : public common::detail::RantWrapper<SourceMultiplexerOnReadoutSourceSelection, uint8_t, 1, 0>
{
	constexpr explicit SourceMultiplexerOnReadoutSourceSelection(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) ReadoutChainOnDLS
    : public common::detail::RantWrapper<ReadoutChainOnDLS, uint_fast16_t, 0, 0>
    , common::CoordinateBase<ReadoutChainOnDLS>
{
	constexpr explicit ReadoutChainOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

} // namespace vx
} // namespace halco::hicann::dls

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ReadoutChainOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PadMultiplexerConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ReadoutSourceSelectionOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SourceMultiplexerOnReadoutSourceSelection)

} // namespace std
