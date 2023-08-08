#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/readout.h"

namespace halco::hicann_dls::vx::v4 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V4 {

using PadMultiplexerConfigOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::PadMultiplexerConfigOnDLS;
using ReadoutSourceSelectionOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::ReadoutSourceSelectionOnDLS;
using SourceMultiplexerOnReadoutSourceSelection GENPYBIND(visible) =
    halco::hicann_dls::vx::SourceMultiplexerOnReadoutSourceSelection;
using ReadoutChainOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::ReadoutChainOnDLS;

} // namespace halco::hicann::dls::vx
