#include "halco/hicann-dls/vx/synapse.h"

#include "halco/hicann-dls/vx/neuron.h"
#include "halco/hicann-dls/vx/synapse_driver.h"

namespace halco::hicann_dls::vx {

NeuronConfigBlockOnDLS SynapseQuadOnDLS::toNeuronConfigBlockOnDLS() const
{
	bool east = toSynapseQuadColumnOnDLS() >= (SynapseQuadColumnOnDLS::size / 2);
	return NeuronConfigBlockOnDLS(toSynramOnDLS().toEnum() * 2 + east);
}

SynapseDriverOnSynapseDriverBlock SynapseRowOnSynram::toSynapseDriverOnSynapseDriverBlock() const
{
	return SynapseDriverOnSynapseDriverBlock(toEnum() / 2);
}

SynapticInputOnNeuron const SynapticInputOnNeuron::excitatory{0};
SynapticInputOnNeuron const SynapticInputOnNeuron::inhibitory{1};

} // namespace halco::hicann_dls::vx
