#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct GENPYBIND(inline_base("*")) PadMultiplexerConfigOnDLS
    : public common::detail::RantWrapper<PadMultiplexerConfigOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit PadMultiplexerConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) ReadoutSourceSelectionOnDLS
    : public common::detail::RantWrapper<ReadoutSourceSelectionOnDLS, uint_fast16_t, 0, 0>
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


struct GENPYBIND(inline_base("*")) ReadoutChainOnDLS
    : public common::detail::RantWrapper<ReadoutChainOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit ReadoutChainOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

} // namespace halco::hicann::dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ReadoutChainOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PadMultiplexerConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ReadoutSourceSelectionOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SourceMultiplexerOnReadoutSourceSelection)

} // namespace std
