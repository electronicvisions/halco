#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct CrossbarInputOnDLS;
struct CrossbarL2OutputOnDLS;

/*************************\
   BackgroundSpikeSource
\*************************/

struct GENPYBIND(inline_base("*")) BackgroundSpikeSourceOnDLS
    : public common::detail::RantWrapper<BackgroundSpikeSourceOnDLS, uint_fast16_t, 7, 0>
{
	constexpr explicit BackgroundSpikeSourceOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CrossbarInputOnDLS toCrossbarInputOnDLS() const;
	CrossbarL2OutputOnDLS toCrossbarL2OutputOnDLS() const;
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::BackgroundSpikeSourceOnDLS)

} // namespace std
