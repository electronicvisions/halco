#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/madc.h"

namespace halco::hicann_dls::vx::v4 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V4 {

using MADCControlOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::MADCControlOnDLS;
using MADCConfigOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::MADCConfigOnDLS;

} // namespace halco::hicann_dls::vx::v4
