#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/spi.h"

namespace halco::hicann_dls::vx::v4 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V4 {

using SPIShiftRegisterOnBoard GENPYBIND(visible) = halco::hicann_dls::vx::SPIShiftRegisterOnBoard;
using SPIDACDataRegisterOnDAC GENPYBIND(visible) = halco::hicann_dls::vx::SPIDACDataRegisterOnDAC;
using SPIDACControlRegisterOnDAC GENPYBIND(visible) =
    halco::hicann_dls::vx::SPIDACControlRegisterOnDAC;
using SPIDACControlRegisterOnBoard GENPYBIND(visible) =
    halco::hicann_dls::vx::SPIDACControlRegisterOnBoard;
using SPIDACDataRegisterOnBoard GENPYBIND(visible) =
    halco::hicann_dls::vx::SPIDACDataRegisterOnBoard;


} // namespace halco::hicann_dls::vx::v4
