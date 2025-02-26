#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/current_dac.h"

namespace halco::hicann_dls::vx {
namespace v4 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V4 {

using CurrentDACOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CurrentDACOnDLS;

} // namespace vx
} // namespace halco::hicann::dls
