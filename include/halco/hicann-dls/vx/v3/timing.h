#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/timing.h"

namespace halco::hicann_dls::vx {
namespace v3 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V3 {

using SystimeSyncOnFPGA GENPYBIND(visible) = halco::hicann_dls::vx::SystimeSyncOnFPGA;
using SystimeSyncBaseOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SystimeSyncBaseOnDLS;
using TimerOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::TimerOnDLS;
using WaitUntilOnFPGA GENPYBIND(visible) = halco::hicann_dls::vx::WaitUntilOnFPGA;

} // namespace v3
} // namespace halco::hicann_dls::vx
