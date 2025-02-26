#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/readout.h"

namespace halco::hicann_dls::vx {
namespace v3 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V3 {

using PadMultiplexerConfigOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::PadMultiplexerConfigOnDLS;
using PadOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::PadOnDLS;
using ReadoutSourceSelectionOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::ReadoutSourceSelectionOnDLS;
using SourceMultiplexerOnReadoutSourceSelection GENPYBIND(visible) =
    halco::hicann_dls::vx::SourceMultiplexerOnReadoutSourceSelection;
using ReadoutChainOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::ReadoutChainOnDLS;

} // namespace vx
} // namespace halco::hicann::dls
