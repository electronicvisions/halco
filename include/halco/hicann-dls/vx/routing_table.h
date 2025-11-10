#pragma once
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "hate/visibility.h"

namespace halco::hicann_dls {
namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/************************\
   RoutingTableOutput
\************************/

/**
 * Unique coordinate for the outgoing routing table on the FPGA.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    OutputRoutingTableOnFPGA
    : public common::detail::RantWrapper<OutputRoutingTableOnFPGA, uint_fast16_t, 0, 0>
    , common::CoordinateBase<OutputRoutingTableOnFPGA>
{
	constexpr explicit OutputRoutingTableOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{
	}
};

/**
 * Unique coordinate for the incoming routing table on the FPGA.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    InputRoutingTableOnFPGA
    : public common::detail::RantWrapper<InputRoutingTableOnFPGA, uint_fast16_t, 0, 0>
    , common::CoordinateBase<InputRoutingTableOnFPGA>
{
	constexpr explicit InputRoutingTableOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{
	}
};

} // namespace vx
} // namespace halco::hicann_dls

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::OutputRoutingTableOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::InputRoutingTableOnFPGA)

} // namespace std
