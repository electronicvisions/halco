#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/ultra96.h"

namespace halco::hicann_dls::vx::v2 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V2 {

using TCA9554OnBoard GENPYBIND(visible) = halco::hicann_dls::vx::TCA9554OnBoard;
using TCA9554ConfigOnBoard GENPYBIND(visible) = halco::hicann_dls::vx::TCA9554ConfigOnBoard;
using TCA9554InputsOnBoard GENPYBIND(visible) = halco::hicann_dls::vx::TCA9554InputsOnBoard;
using TCA9554ChannelOnBoard GENPYBIND(visible) = halco::hicann_dls::vx::TCA9554ChannelOnBoard;
using AD5252OnBoard GENPYBIND(visible) = halco::hicann_dls::vx::AD5252OnBoard;
using AD5252ChannelOnBoard GENPYBIND(visible) = halco::hicann_dls::vx::AD5252ChannelOnBoard;
using AD5252ChannelConfigOnBoard GENPYBIND(visible) =
    halco::hicann_dls::vx::AD5252ChannelConfigOnBoard;
using AD5252ChannelConfigPersistentOnBoard GENPYBIND(visible) =
    halco::hicann_dls::vx::AD5252ChannelConfigPersistentOnBoard;

} // namespace halco::hicann_dls::vx::v2
