#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/background.h"

namespace halco::hicann_dls::vx::v2 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V2 {

using BackgroundSpikeSourceOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::BackgroundSpikeSourceOnDLS;

} // namespace halco::hicann_dls::vx::v2
