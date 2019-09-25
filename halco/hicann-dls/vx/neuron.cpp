#include "halco/hicann-dls/vx/neuron.h"

#include "halco/hicann-dls/vx/capmem.h"

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

} // namespace halco::hicann_dls::vx
