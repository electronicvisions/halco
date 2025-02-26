#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/reset.h"

namespace halco::hicann_dls::vx {
namespace v4 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V4 {

using ResetChipOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::ResetChipOnDLS;

} // namespace v4
} // namespace halco::hicann_dls::vx
