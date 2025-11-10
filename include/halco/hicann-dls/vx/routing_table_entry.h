#pragma once
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "hate/math.h"
#include "hate/visibility.h"

namespace halco::hicann_dls {
namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/***************************\
   RoutingTableOutputEntry
\***************************/

// Forward declaration from halco/hicann-dls/vx/event.h
struct SpikeLabel;

/**
 * Unique coordinate for an entry in the outgoing routing table on the FPGA.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    OutputRoutingTableEntryOnFPGA
    : public common::detail::
          RantWrapper<OutputRoutingTableEntryOnFPGA, uint_fast32_t, hate::math::pow(2, 16) - 1, 0>
    , common::CoordinateBase<OutputRoutingTableEntryOnFPGA>
{
	constexpr explicit OutputRoutingTableEntryOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{
	}

	SpikeLabel toSpikeLabel() const SYMBOL_VISIBLE;
};

/**
 * Unique coordinate for an entry in the incoming routing table on the FPGA.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    InputRoutingTableEntryOnFPGA
    : public common::detail::
          RantWrapper<InputRoutingTableEntryOnFPGA, uint_fast32_t, hate::math::pow(2, 15) - 1, 0>
    , common::CoordinateBase<InputRoutingTableEntryOnFPGA>
{
	constexpr explicit InputRoutingTableEntryOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{
	}
};

} // namespace vx
} // namespace halco::hicann_dls

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::OutputRoutingTableEntryOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::InputRoutingTableEntryOnFPGA)

} // namespace std
