#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/correlation.h"

namespace halco::hicann_dls::vx::v2 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V2 {

using CommonCorrelationConfigOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::CommonCorrelationConfigOnDLS;

} // namespace halco::hicann_dls::vx::v2
