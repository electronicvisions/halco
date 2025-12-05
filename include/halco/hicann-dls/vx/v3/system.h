#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/system.h"

namespace halco::hicann_dls::vx {
namespace v3 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V3 {

using ChipAndMultichipJboaLeafFPGAOnSystem GENPYBIND(visible) =
    halco::hicann_dls::vx::ChipAndMultichipJboaLeafFPGAOnSystem;

using ChipAndSinglechipFPGAOnSystem GENPYBIND(visible) =
    halco::hicann_dls::vx::ChipAndSinglechipFPGAOnSystem;

} // namespace v3
} // namespace halco::hicann_dls::vx
