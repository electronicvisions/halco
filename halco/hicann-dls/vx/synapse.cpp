#include "halco/hicann-dls/vx/synapse.h"

namespace halco::hicann_dls::vx {

NeuronBlockOnDLS SynapseQuadOnDLS::toNeuronBlockOnDLS() const
{
	bool east = toSynapseQuadColumnOnDLS() >= (SynapseQuadColumnOnDLS::size / 2);
	return NeuronBlockOnDLS(toSynramOnDLS().toEnum() * 2 + east);
}

} // namespace halco::hicann_dls::vx
