#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/barrier.h"

namespace halco::hicann_dls::vx::v2 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V2 {

using BarrierOnFPGA GENPYBIND(visible) = halco::hicann_dls::vx::BarrierOnFPGA;

} // namespace halco::hicann_dls::vx::v2
