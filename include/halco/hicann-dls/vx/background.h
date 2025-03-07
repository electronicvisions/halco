#pragma once
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "hate/visibility.h"

namespace halco::hicann_dls {
namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct CrossbarInputOnDLS;
struct CrossbarL2OutputOnDLS;
struct PADIBusOnDLS;

/*************************\
   BackgroundSpikeSource
\*************************/

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    BackgroundSpikeSourceOnDLS
    : public common::detail::RantWrapper<BackgroundSpikeSourceOnDLS, uint_fast16_t, 7, 0>
    , common::CoordinateBase<BackgroundSpikeSourceOnDLS>
{
	constexpr explicit BackgroundSpikeSourceOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CrossbarInputOnDLS toCrossbarInputOnDLS() const SYMBOL_VISIBLE;
	CrossbarL2OutputOnDLS toCrossbarL2OutputOnDLS() const SYMBOL_VISIBLE;
	PADIBusOnDLS toPADIBusOnDLS() const SYMBOL_VISIBLE;
};

} // namespace vx
} // namespace halco::hicann_dls

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::BackgroundSpikeSourceOnDLS)

} // namespace std
