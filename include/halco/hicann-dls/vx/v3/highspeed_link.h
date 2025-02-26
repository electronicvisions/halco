#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/highspeed_link.h"

namespace halco::hicann_dls::vx {
namespace v3 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V3 {

using HicannARQStatusOnFPGA GENPYBIND(visible) = halco::hicann_dls::vx::HicannARQStatusOnFPGA;
using PerfTestOnFPGA GENPYBIND(visible) = halco::hicann_dls::vx::PerfTestOnFPGA;
using PerfTestStatusOnFPGA GENPYBIND(visible) = halco::hicann_dls::vx::PerfTestStatusOnFPGA;
using PhyConfigFPGAOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::PhyConfigFPGAOnDLS;
using PhyConfigChipOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::PhyConfigChipOnDLS;
using PhyStatusOnFPGA GENPYBIND(visible) = halco::hicann_dls::vx::PhyStatusOnFPGA;
using CommonPhyConfigFPGAOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CommonPhyConfigFPGAOnDLS;
using CommonPhyConfigChipOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CommonPhyConfigChipOnDLS;

} // namespace v3
} // namespace halco::hicann_dls::vx
