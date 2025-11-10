#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/routing_table.h"

namespace halco::hicann_dls::vx {
namespace v3 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V3 {

using OutputRoutingTableOnFPGA GENPYBIND(visible) = halco::hicann_dls::vx::OutputRoutingTableOnFPGA;
using InputRoutingTableOnFPGA GENPYBIND(visible) = halco::hicann_dls::vx::InputRoutingTableOnFPGA;

} // namespace v3
} // namespace halco::hicann_dls::vx
