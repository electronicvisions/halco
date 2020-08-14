#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/xboard.h"

namespace halco::hicann_dls::vx::v1 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V1 {

using ShiftRegisterOnBoard GENPYBIND(visible) = halco::hicann_dls::vx::ShiftRegisterOnBoard;
using ADCSourceOnBoard GENPYBIND(visible) = halco::hicann_dls::vx::ADCSourceOnBoard;
using LEDOnBoard GENPYBIND(visible) = halco::hicann_dls::vx::LEDOnBoard;
using VDDOnBoard GENPYBIND(visible) = halco::hicann_dls::vx::VDDOnBoard;
using ADCOnBoard GENPYBIND(visible) = halco::hicann_dls::vx::ADCOnBoard;
using INA219OnBoard GENPYBIND(visible) = halco::hicann_dls::vx::INA219OnBoard;
using INA219ConfigOnBoard GENPYBIND(visible) = halco::hicann_dls::vx::INA219ConfigOnBoard;
using INA219StatusOnBoard GENPYBIND(visible) = halco::hicann_dls::vx::INA219StatusOnBoard;

} // namespace halco::hicann_dls::vx::v1
