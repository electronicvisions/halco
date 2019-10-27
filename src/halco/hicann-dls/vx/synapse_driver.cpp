#include "halco/hicann-dls/vx/synapse_driver.h"

#include "halco/hicann-dls/vx/padi.h"
#include "halco/hicann-dls/vx/synram.h"

namespace halco::hicann_dls::vx {

SynramOnDLS SynapseDriverBlockOnDLS::toSynramOnDLS() const
{
	return SynramOnDLS(toEnum());
}

PADIEventOnDLS SynapseDriverBlockOnDLS::toPADIEventOnDLS() const
{
	return PADIEventOnDLS(toEnum());
}

PADIBusOnPADIBusBlock SynapseDriverOnSynapseDriverBlock::toPADIBusOnPADIBusBlock() const
{
	return PADIBusOnPADIBusBlock(toEnum() % PADIBusOnPADIBusBlock::size);
}

} // namespace halco::hicann_dls::vx
