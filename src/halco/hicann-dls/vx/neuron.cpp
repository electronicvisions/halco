#include "halco/hicann-dls/vx/neuron.h"

#include "halco/hicann-dls/vx/capmem.h"
#include "halco/hicann-dls/vx/synapse.h"

namespace halco::hicann_dls::vx {

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

} // namespace halco::hicann_dls::vx
