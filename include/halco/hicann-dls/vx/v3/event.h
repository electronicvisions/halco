#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/event.h"

namespace halco::hicann_dls::vx { namespace v3 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V3 {

using SpikePack1ToChipOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SpikePack1ToChipOnDLS;
using SpikePack2ToChipOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SpikePack2ToChipOnDLS;
using SpikePack3ToChipOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SpikePack3ToChipOnDLS;
using SpikePackFromFPGAOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SpikePackFromFPGAOnDLS;
using MADCSamplePackFromFPGAOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::MADCSamplePackFromFPGAOnDLS;
using NeuronLabel GENPYBIND(visible) = halco::hicann_dls::vx::NeuronLabel;
using SPL1Address GENPYBIND(visible) = halco::hicann_dls::vx::SPL1Address;
using SpikeLabel GENPYBIND(visible) = halco::hicann_dls::vx::SpikeLabel;

} // namespace v3
} // namespace halco::hicann_dls::vx
