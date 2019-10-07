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

} // namespace halco::hicann_dls::vx
