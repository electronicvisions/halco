#include "halco/hicann-dls/vx/neuron.h"

#include "halco/hicann-dls/vx/cadc.h"
#include "halco/hicann-dls/vx/capmem.h"
#include "halco/hicann-dls/vx/chip.h"
#include "halco/hicann-dls/vx/correlation.h"
#include "halco/hicann-dls/vx/padi.h"
#include "halco/hicann-dls/vx/ppu.h"
#include "halco/hicann-dls/vx/switch_rows.h"
#include "halco/hicann-dls/vx/synapse.h"
#include "halco/hicann-dls/vx/synapse_driver.h"
#include "halco/hicann-dls/vx/synram.h"

namespace halco::hicann_dls::vx {

#define HEMISPHERE_CLASS NeuronRowOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

NeuronRowOnDLS const NeuronRowOnDLS::top{enum_vertical_top};
NeuronRowOnDLS const NeuronRowOnDLS::bottom{enum_vertical_bottom};

CapMemColumnOnCapMemBlock NeuronConfigOnNeuronConfigBlock::toCapMemColumnOnCapMemBlock() const
{
	return CapMemColumnOnCapMemBlock(toEnum());
}

CapMemBlockOnDLS NeuronConfigBlockOnDLS::toCapMemBlockOnDLS() const
{
	return CapMemBlockOnDLS(toEnum());
}

NeuronResetBlockOnDLS NeuronConfigBlockOnDLS::toNeuronResetBlockOnDLS() const
{
	return NeuronResetBlockOnDLS(toEnum() % NeuronResetBlockOnDLS::size);
}

NeuronResetOnDLS NeuronConfigOnDLS::toNeuronResetOnDLS() const
{
	auto block = toNeuronConfigBlockOnDLS().toNeuronResetBlockOnDLS();
	return NeuronResetOnDLS(
	    NeuronResetOnNeuronResetBlock(
	        toNeuronConfigOnNeuronConfigBlock() +
	        ((toNeuronConfigBlockOnDLS() / NeuronResetBlockOnDLS::size)
	             ? NeuronConfigOnNeuronConfigBlock::size
	             : 0)),
	    block);
}

NeuronBackendConfigBlockOnDLS BlockPostPulseOnDLS::toNeuronBackendConfigBlockOnDLS() const
{
	return NeuronBackendConfigBlockOnDLS(toEnum());
}

NeuronBackendConfigBlockOnDLS CommonNeuronBackendConfigOnDLS::toNeuronBackendConfigBlockOnDLS()
    const
{
	return NeuronBackendConfigBlockOnDLS(toEnum());
}

CommonNeuronBackendConfigOnDLS NeuronBackendConfigBlockOnDLS::toCommonNeuronBackendConfigOnDLS()
    const
{
	return CommonNeuronBackendConfigOnDLS(toEnum());
}

BlockPostPulseOnDLS NeuronBackendConfigBlockOnDLS::toBlockPostPulseOnDLS() const
{
	return BlockPostPulseOnDLS(toEnum());
}

SpikeCounterReadBlockOnDLS NeuronConfigBlockOnDLS::toSpikeCounterReadBlockOnDLS() const
{
	return SpikeCounterReadBlockOnDLS(toEnum() % SpikeCounterReadBlockOnDLS::size);
}

SpikeCounterReadOnDLS NeuronConfigOnDLS::toSpikeCounterReadOnDLS() const
{
	return SpikeCounterReadOnDLS(toNeuronResetOnDLS().toEnum());
}

SpikeCounterResetBlockOnDLS NeuronConfigBlockOnDLS::toSpikeCounterResetBlockOnDLS() const
{
	return SpikeCounterResetBlockOnDLS(toEnum() % SpikeCounterResetBlockOnDLS::size);
}

SpikeCounterResetOnDLS NeuronConfigOnDLS::toSpikeCounterResetOnDLS() const
{
	return SpikeCounterResetOnDLS(toNeuronResetOnDLS().toEnum());
}

SynapseOnSynapseRow NeuronColumnOnDLS::toSynapseOnSynapseRow() const
{
	return SynapseOnSynapseRow(toEnum());
}

CapMemColumnOnCapMemBlock NeuronColumnOnDLS::toCapMemColumnOnCapMemBlock() const
{
	return CapMemColumnOnCapMemBlock(toEnum() % NeuronConfigOnNeuronConfigBlock::size);
}

NeuronConfigOnDLS AtomicNeuronOnDLS::toNeuronConfigOnDLS() const
{
	return NeuronConfigOnDLS(toEnum());
}

NeuronResetOnDLS AtomicNeuronOnDLS::toNeuronResetOnDLS() const
{
	return toNeuronConfigOnDLS().toNeuronResetOnDLS();
}

SpikeCounterReadOnDLS AtomicNeuronOnDLS::toSpikeCounterReadOnDLS() const
{
	return toNeuronConfigOnDLS().toSpikeCounterReadOnDLS();
}

SpikeCounterResetOnDLS AtomicNeuronOnDLS::toSpikeCounterResetOnDLS() const
{
	return toNeuronConfigOnDLS().toSpikeCounterResetOnDLS();
}

NeuronBackendConfigOnDLS AtomicNeuronOnDLS::toNeuronBackendConfigOnDLS() const
{
	return NeuronBackendConfigOnDLS(toNeuronResetOnDLS().toEnum());
}

CapMemColumnOnCapMemBlock AtomicNeuronOnDLS::toCapMemColumnOnCapMemBlock() const
{
	return toNeuronColumnOnDLS().toCapMemColumnOnCapMemBlock();
}

CapMemBlockOnDLS AtomicNeuronOnDLS::toCapMemBlockOnDLS() const
{
	return toNeuronConfigOnDLS().toNeuronConfigBlockOnDLS().toCapMemBlockOnDLS();
}

NeuronRowOnDLS NeuronConfigOnDLS::toNeuronRowOnDLS() const
{
	return NeuronRowOnDLS(toEnum() / SynapseOnSynapseRow::size);
}

SynapseOnSynapseRow NeuronConfigOnDLS::toSynapseOnSynapseRow() const
{
	return SynapseOnSynapseRow(toEnum() % SynapseOnSynapseRow::size);
}

AtomicNeuronOnDLS NeuronConfigOnDLS::toAtomicNeuronOnDLS() const
{
	return AtomicNeuronOnDLS(toSynapseOnSynapseRow().toNeuronColumnOnDLS(), toNeuronRowOnDLS());
}

SynapseQuadColumnOnDLS NeuronConfigOnDLS::toSynapseQuadColumnOnDLS() const
{
	return toSynapseOnSynapseRow().toSynapseQuadColumnOnDLS();
}

EntryOnQuad NeuronConfigOnDLS::toEntryOnQuad() const
{
	return toSynapseOnSynapseRow().toEntryOnQuad();
}

NeuronBackendConfigBlockOnDLS NeuronConfigOnDLS::toNeuronBackendConfigBlockOnDLS() const
{
	return toAtomicNeuronOnDLS().toNeuronBackendConfigOnDLS().toNeuronBackendConfigBlockOnDLS();
}

NeuronBackendConfigOnNeuronBackendConfigBlock
NeuronConfigOnDLS::toNeuronBackendConfigOnNeuronBackendConfigBlock() const
{
	return toAtomicNeuronOnDLS()
	    .toNeuronBackendConfigOnDLS()
	    .toNeuronBackendConfigOnNeuronBackendConfigBlock();
}

NeuronBackendConfigOnDLS NeuronConfigOnDLS::toNeuronBackendConfigOnDLS() const
{
	return toAtomicNeuronOnDLS().toNeuronBackendConfigOnDLS();
}

CommonNeuronBackendConfigOnDLS NeuronConfigOnDLS::toCommonNeuronBackendConfigOnDLS() const
{
	return toNeuronBackendConfigBlockOnDLS().toCommonNeuronBackendConfigOnDLS();
}

NeuronColumnOnDLS NeuronBackendConfigOnDLS::toNeuronColumnOnDLS() const
{
	return NeuronColumnOnDLS(
	    (toNeuronBackendConfigOnNeuronBackendConfigBlock() %
	     NeuronConfigOnNeuronConfigBlock::size) +
	    (toNeuronBackendConfigBlockOnDLS() * NeuronConfigOnNeuronConfigBlock::size));
}

NeuronRowOnDLS NeuronBackendConfigOnDLS::toNeuronRowOnDLS() const
{
	return NeuronRowOnDLS(
	    toNeuronBackendConfigOnNeuronBackendConfigBlock() / NeuronConfigOnNeuronConfigBlock::size);
}

AtomicNeuronOnDLS NeuronBackendConfigOnDLS::toAtomicNeuronOnDLS() const
{
	return AtomicNeuronOnDLS(toNeuronColumnOnDLS(), toNeuronRowOnDLS());
}

NeuronConfigOnDLS NeuronBackendConfigOnDLS::toNeuronConfigOnDLS() const
{
	return toAtomicNeuronOnDLS().toNeuronConfigOnDLS();
}

SpikeCounterReadOnDLS NeuronBackendConfigOnDLS::toSpikeCounterReadOnDLS() const
{
	return toNeuronConfigOnDLS().toSpikeCounterReadOnDLS();
}

SpikeCounterResetOnDLS NeuronBackendConfigOnDLS::toSpikeCounterResetOnDLS() const
{
	return toNeuronConfigOnDLS().toSpikeCounterResetOnDLS();
}

CommonNeuronBackendConfigOnDLS NeuronBackendConfigOnDLS::toCommonNeuronBackendConfigOnDLS() const
{
	return toNeuronBackendConfigBlockOnDLS().toCommonNeuronBackendConfigOnDLS();
}

SynramOnDLS AtomicNeuronOnDLS::toSynramOnDLS() const
{
	return toNeuronRowOnDLS().toSynramOnDLS();
}

SynramOnDLS NeuronConfigOnDLS::toSynramOnDLS() const
{
	return toAtomicNeuronOnDLS().toSynramOnDLS();
}

SynramOnDLS NeuronBackendConfigOnDLS::toSynramOnDLS() const
{
	return toAtomicNeuronOnDLS().toSynramOnDLS();
}

NeuronConfigBlockOnDLS NeuronBackendConfigOnDLS::toNeuronConfigBlockOnDLS() const
{
	return toNeuronConfigOnDLS().toNeuronConfigBlockOnDLS();
}

SynapseQuadColumnOnDLS AtomicNeuronOnDLS::toSynapseQuadColumnOnDLS() const
{
	return toNeuronConfigOnDLS().toSynapseQuadColumnOnDLS();
}

ColumnCorrelationQuadOnDLS AtomicNeuronOnDLS::toColumnCorrelationQuadOnDLS() const
{
	return ColumnCorrelationQuadOnDLS(
	    toSynapseQuadColumnOnDLS().toColumnCorrelationQuadOnSynram(), toSynramOnDLS());
}

ColumnCurrentQuadOnDLS AtomicNeuronOnDLS::toColumnCurrentQuadOnDLS() const
{
	return ColumnCurrentQuadOnDLS(
	    toSynapseQuadColumnOnDLS().toColumnCurrentQuadOnSynram(), toSynramOnDLS());
}

ColumnCorrelationQuadOnDLS NeuronConfigOnDLS::toColumnCorrelationQuadOnDLS() const
{
	return toAtomicNeuronOnDLS().toColumnCorrelationQuadOnDLS();
}

ColumnCurrentQuadOnDLS NeuronConfigOnDLS::toColumnCurrentQuadOnDLS() const
{
	return toAtomicNeuronOnDLS().toColumnCurrentQuadOnDLS();
}

} // namespace halco::hicann_dls::vx
