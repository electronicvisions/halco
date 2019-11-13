#include "halco/hicann-dls/vx/synapse_driver.h"

#include "halco/hicann-dls/vx/padi.h"
#include "halco/hicann-dls/vx/ppu.h"
#include "halco/hicann-dls/vx/synram.h"

namespace halco::hicann_dls::vx {

CommonSynapseDriverConfigOnDLS SynapseDriverBlockOnDLS::toCommonSynapseDriverConfigOnDLS() const
{
	return CommonSynapseDriverConfigOnDLS(toEnum());
}

SynapseDriverBlockOnDLS const SynapseDriverBlockOnDLS::top{enum_vertical_top};
SynapseDriverBlockOnDLS const SynapseDriverBlockOnDLS::bottom{enum_vertical_bottom};

CommonSynapseDriverConfigOnDLS const CommonSynapseDriverConfigOnDLS::top{enum_vertical_top};
CommonSynapseDriverConfigOnDLS const CommonSynapseDriverConfigOnDLS::bottom{enum_vertical_bottom};

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
