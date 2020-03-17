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
	return CapMemColumnOnCapMemBlock(toEnum() % CapMemColumnOnCapMemBlock::size);
}

NeuronConfigOnDLS NeuronOnDLS::toNeuronConfigOnDLS() const
{
	return NeuronConfigOnDLS(toEnum());
}

NeuronResetOnDLS NeuronOnDLS::toNeuronResetOnDLS() const
{
	return toNeuronConfigOnDLS().toNeuronResetOnDLS();
}

SpikeCounterReadOnDLS NeuronOnDLS::toSpikeCounterReadOnDLS() const
{
	return toNeuronConfigOnDLS().toSpikeCounterReadOnDLS();
}

SpikeCounterResetOnDLS NeuronOnDLS::toSpikeCounterResetOnDLS() const
{
	return toNeuronConfigOnDLS().toSpikeCounterResetOnDLS();
}

NeuronBackendConfigOnDLS NeuronOnDLS::toNeuronBackendConfigOnDLS() const
{
	return NeuronBackendConfigOnDLS(toNeuronResetOnDLS().toEnum());
}

CapMemColumnOnCapMemBlock NeuronOnDLS::toCapMemColumnOnCapMemBlock() const
{
	return toNeuronColumnOnDLS().toCapMemColumnOnCapMemBlock();
}

CapMemBlockOnDLS NeuronOnDLS::toCapMemBlockOnDLS() const
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

NeuronOnDLS NeuronConfigOnDLS::toNeuronOnDLS() const
{
	return NeuronOnDLS(toSynapseOnSynapseRow().toNeuronColumnOnDLS(), toNeuronRowOnDLS());
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
	return toNeuronOnDLS().toNeuronBackendConfigOnDLS().toNeuronBackendConfigBlockOnDLS();
}

NeuronBackendConfigOnNeuronBackendConfigBlock
NeuronConfigOnDLS::toNeuronBackendConfigOnNeuronBackendConfigBlock() const
{
	return toNeuronOnDLS()
	    .toNeuronBackendConfigOnDLS()
	    .toNeuronBackendConfigOnNeuronBackendConfigBlock();
}

NeuronBackendConfigOnDLS NeuronConfigOnDLS::toNeuronBackendConfigOnDLS() const
{
	return toNeuronOnDLS().toNeuronBackendConfigOnDLS();
}

CommonNeuronBackendConfigOnDLS NeuronConfigOnDLS::toCommonNeuronBackendConfigOnDLS() const
{
	return toNeuronBackendConfigBlockOnDLS().toCommonNeuronBackendConfigOnDLS();
}

NeuronConfigOnDLS NeuronBackendConfigOnDLS::toNeuronConfigOnDLS() const
{
	return NeuronConfigOnDLS(toEnum());
}

NeuronOnDLS NeuronBackendConfigOnDLS::toNeuronOnDLS() const
{
	return toNeuronConfigOnDLS().toNeuronOnDLS();
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
	return CommonNeuronBackendConfigOnDLS(toEnum());
}

SynramOnDLS NeuronOnDLS::toSynramOnDLS() const
{
	return toNeuronRowOnDLS().toSynramOnDLS();
}

SynramOnDLS NeuronConfigOnDLS::toSynramOnDLS() const
{
	return toNeuronOnDLS().toSynramOnDLS();
}

SynramOnDLS NeuronBackendConfigOnDLS::toSynramOnDLS() const
{
	return toNeuronOnDLS().toSynramOnDLS();
}

NeuronConfigBlockOnDLS NeuronBackendConfigOnDLS::toNeuronConfigBlockOnDLS() const
{
	return toNeuronConfigOnDLS().toNeuronConfigBlockOnDLS();
}

SynapseQuadColumnOnDLS NeuronOnDLS::toSynapseQuadColumnOnDLS() const
{
	return toNeuronConfigOnDLS().toSynapseQuadColumnOnDLS();
}

ColumnCorrelationQuadOnDLS NeuronOnDLS::toColumnCorrelationQuadOnDLS() const
{
	return ColumnCorrelationQuadOnDLS(
	    toSynapseQuadColumnOnDLS().toColumnCorrelationQuadOnSynram(), toSynramOnDLS());
}

ColumnCurrentQuadOnDLS NeuronOnDLS::toColumnCurrentQuadOnDLS() const
{
	return ColumnCurrentQuadOnDLS(
	    toSynapseQuadColumnOnDLS().toColumnCurrentQuadOnSynram(), toSynramOnDLS());
}

ColumnCorrelationQuadOnDLS NeuronConfigOnDLS::toColumnCorrelationQuadOnDLS() const
{
	return toNeuronOnDLS().toColumnCorrelationQuadOnDLS();
}

ColumnCurrentQuadOnDLS NeuronConfigOnDLS::toColumnCurrentQuadOnDLS() const
{
	return toNeuronOnDLS().toColumnCurrentQuadOnDLS();
}

} // namespace halco::hicann_dls::vx
