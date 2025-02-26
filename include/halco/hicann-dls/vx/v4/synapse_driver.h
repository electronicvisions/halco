#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/synapse_driver.h"

namespace halco::hicann_dls::vx {
namespace v4 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V4 {

using SynapseDriverOnSynapseDriverBlock GENPYBIND(visible) =
    halco::hicann_dls::vx::SynapseDriverOnSynapseDriverBlock;
using SynapseDriverOnPADIBus GENPYBIND(visible) = halco::hicann_dls::vx::SynapseDriverOnPADIBus;
using SynapseDriverBlockOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SynapseDriverBlockOnDLS;
using SynapseDriverOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SynapseDriverOnDLS;
using CommonSynapseDriverConfigOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::CommonSynapseDriverConfigOnDLS;
using SynapseDriverSRAMTimingConfigOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::SynapseDriverSRAMTimingConfigOnDLS;

} // namespace v4
} // namespace halco::hicann_dls::vx
