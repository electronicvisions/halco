#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/routing_crossbar.h"

namespace halco::hicann_dls::vx::v3 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V3 {

using CrossbarOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CrossbarOnDLS;
using CrossbarOutputConfigOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::CrossbarOutputConfigOnDLS;
using CrossbarOutputOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CrossbarOutputOnDLS;
using CrossbarL2OutputOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CrossbarL2OutputOnDLS;
using CrossbarInputOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CrossbarInputOnDLS;
using CrossbarNodeOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CrossbarNodeOnDLS;

} // namespace halco::hicann_dls::vx::v3
