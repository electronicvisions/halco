#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/neuron.h"

namespace halco::hicann_dls::vx::v1 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V1 {

using NeuronColumnOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::NeuronColumnOnDLS;
using NeuronRowOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::NeuronRowOnDLS;
using AtomicNeuronOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::AtomicNeuronOnDLS;
using NeuronConfigOnNeuronConfigBlock GENPYBIND(visible) =
    halco::hicann_dls::vx::NeuronConfigOnNeuronConfigBlock;
using NeuronConfigBlockOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::NeuronConfigBlockOnDLS;
using NeuronConfigOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::NeuronConfigOnDLS;
using NeuronBackendConfigOnNeuronBackendConfigBlock GENPYBIND(visible) =
    halco::hicann_dls::vx::NeuronBackendConfigOnNeuronBackendConfigBlock;
using NeuronBackendConfigBlockOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::NeuronBackendConfigBlockOnDLS;
using NeuronBackendConfigOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::NeuronBackendConfigOnDLS;
using CommonNeuronBackendConfigOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::CommonNeuronBackendConfigOnDLS;
using NeuronResetOnNeuronResetBlock GENPYBIND(visible) =
    halco::hicann_dls::vx::NeuronResetOnNeuronResetBlock;
using NeuronResetBlockOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::NeuronResetBlockOnDLS;
using NeuronResetOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::NeuronResetOnDLS;
using BlockPostPulseOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::BlockPostPulseOnDLS;
using SpikeCounterReadOnSpikeCounterReadBlock GENPYBIND(visible) =
    halco::hicann_dls::vx::SpikeCounterReadOnSpikeCounterReadBlock;
using SpikeCounterReadBlockOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::SpikeCounterReadBlockOnDLS;
using SpikeCounterReadOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SpikeCounterReadOnDLS;
using SpikeCounterResetOnSpikeCounterResetBlock GENPYBIND(visible) =
    halco::hicann_dls::vx::SpikeCounterResetOnSpikeCounterResetBlock;
using SpikeCounterResetBlockOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::SpikeCounterResetBlockOnDLS;
using SpikeCounterResetOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SpikeCounterResetOnDLS;
using NeuronEventOutputOnNeuronBackendBlock GENPYBIND(visible) =
    halco::hicann_dls::vx::NeuronEventOutputOnNeuronBackendBlock;
using NeuronEventOutputOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::NeuronEventOutputOnDLS;
using NeuronResetQuadOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::NeuronResetQuadOnDLS;
using NeuronSRAMTimingConfigOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::NeuronSRAMTimingConfigOnDLS;
using NeuronBackendSRAMTimingConfigOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::NeuronBackendSRAMTimingConfigOnDLS;

} // namespace halco::hicann_dls::vx::v1
