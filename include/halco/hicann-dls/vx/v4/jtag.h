#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/jtag.h"

namespace halco::hicann_dls::vx::v4 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V4 {

using ResetJTAGTapOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::ResetJTAGTapOnDLS;
using JTAGClockScalerOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::JTAGClockScalerOnDLS;
using JTAGIdCodeOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::JTAGIdCodeOnDLS;
using JTAGPLLRegisterOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::JTAGPLLRegisterOnDLS;
using JTAGPhyRegisterOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::JTAGPhyRegisterOnDLS;

} // namespace halco::hicann_dls::vx::v4
