#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/readout.h"

namespace halco::hicann_dls::vx::v1 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V1 {

using PadMultiplexerConfigOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::PadMultiplexerConfigOnDLS;
using ReadoutSourceSelectionOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::ReadoutSourceSelectionOnDLS;
using SourceMultiplexerOnReadoutSourceSelection GENPYBIND(visible) =
    halco::hicann_dls::vx::SourceMultiplexerOnReadoutSourceSelection;

} // namespace halco::hicann::dls::vx
