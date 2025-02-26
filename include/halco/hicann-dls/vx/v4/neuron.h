#pragma once
#include "halco/common/genpybind.h"
#include "halco/common/iter_all.h"
#include "halco/hicann-dls/vx/neuron.h"

namespace halco::hicann_dls::vx {
namespace v4 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V4 {

using NeuronRowOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::NeuronRowOnDLS;
using NeuronConfigOnNeuronConfigBlock GENPYBIND(visible) =
    halco::hicann_dls::vx::NeuronConfigOnNeuronConfigBlock;
using NeuronConfigBlockOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::NeuronConfigBlockOnDLS;
using NeuronBackendConfigOnNeuronBackendConfigBlock GENPYBIND(visible) =
    halco::hicann_dls::vx::NeuronBackendConfigOnNeuronBackendConfigBlock;
using NeuronBackendConfigBlockOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::NeuronBackendConfigBlockOnDLS;
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
using NeuronSRAMTimingConfigOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::NeuronSRAMTimingConfigOnDLS;
using NeuronBackendSRAMTimingConfigOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::NeuronBackendSRAMTimingConfigOnDLS;
using NeuronRowOnLogicalNeuron = halco::hicann_dls::vx::NeuronRowOnLogicalNeuron;
using NeuronBlockOnDLS = halco::hicann_dls::vx::NeuronBlockOnDLS;
using NeuronColumnOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::NeuronColumnOnDLS;
using AtomicNeuronOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::AtomicNeuronOnDLS;
using NeuronConfigOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::NeuronConfigOnDLS;
using NeuronBackendConfigOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::NeuronBackendConfigOnDLS;
using NeuronBackendAddressOut GENPYBIND(visible) = halco::hicann_dls::vx::NeuronBackendAddressOut;
using NeuronResetQuadOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::NeuronResetQuadOnDLS;
using LogicalNeuronOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::LogicalNeuronOnDLS;
using LogicalNeuronCompartments GENPYBIND(visible) =
    halco::hicann_dls::vx::LogicalNeuronCompartments;
using AtomicNeuronOnLogicalNeuron GENPYBIND(visible) =
    halco::hicann_dls::vx::AtomicNeuronOnLogicalNeuron;
using NeuronColumnOnLogicalNeuron GENPYBIND(visible) =
    halco::hicann_dls::vx::NeuronColumnOnLogicalNeuron;
using CompartmentOnLogicalNeuron GENPYBIND(visible) =
    halco::hicann_dls::vx::CompartmentOnLogicalNeuron;

} // namespace v4
} // namespace halco::hicann_dls::vx
