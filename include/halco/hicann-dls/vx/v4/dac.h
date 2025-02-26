#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/dac.h"

namespace halco::hicann_dls::vx {
namespace v4 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V4 {

using DACOnBoard GENPYBIND(visible) = halco::hicann_dls::vx::DACOnBoard;
using DACChannelOnDAC GENPYBIND(visible) = halco::hicann_dls::vx::DACChannelOnDAC;
using DACChannelOnBoard GENPYBIND(visible) = halco::hicann_dls::vx::DACChannelOnBoard;
using DACControlBlockOnBoard GENPYBIND(visible) = halco::hicann_dls::vx::DACControlBlockOnBoard;
using DACChannelBlockOnBoard GENPYBIND(visible) = halco::hicann_dls::vx::DACChannelBlockOnBoard;

} // namespace v4
} // namespace halco::hicann_dls::vx
