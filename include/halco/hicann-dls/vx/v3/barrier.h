#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/barrier.h"

namespace halco::hicann_dls::vx { namespace v3 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V3 {

using BarrierOnFPGA GENPYBIND(visible) = halco::hicann_dls::vx::BarrierOnFPGA;

} // namespace v3
} // namespace halco::hicann_dls::vx
