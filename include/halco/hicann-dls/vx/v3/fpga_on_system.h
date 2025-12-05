#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/fpga_on_system.h"

namespace halco::hicann_dls::vx {
namespace v3 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V3 {

using FPGAOnChipAndMultichipJboaLeafFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::FPGAOnChipAndMultichipJboaLeafFPGA;

using FPGAOnChipAndSinglechipFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::FPGAOnChipAndSinglechipFPGA;

} // namespace v3
} // namespace halco::hicann_dls::vx
