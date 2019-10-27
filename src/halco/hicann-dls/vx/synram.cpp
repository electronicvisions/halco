#include "halco/hicann-dls/vx/synram.h"

#include "halco/hicann-dls/vx/padi.h"
#include "halco/hicann-dls/vx/ppu.h"
#include "halco/hicann-dls/vx/synapse_driver.h"

namespace halco::hicann_dls::vx {

SynramOnDLS CommonSynramConfigOnDLS::toSynramOnDLS() const
{
	return SynramOnDLS(toEnum());
}

PPUOnDLS CommonSynramConfigOnDLS::toPPUOnDLS() const
{
	return PPUOnDLS(toEnum());
}

PPUOnDLS SynramOnDLS::toPPUOnDLS() const
{
	return PPUOnDLS(toEnum());
}

SynapseDriverBlockOnDLS SynramOnDLS::toSynapseDriverBlockOnDLS() const
{
	return SynapseDriverBlockOnDLS(toEnum());
}

PADIEventOnDLS SynramOnDLS::toPADIEventOnDLS() const
{
	return PADIEventOnDLS(toEnum());
}

CommonSynramConfigOnDLS SynramOnDLS::toCommonSynramConfigOnDLS() const
{
	return CommonSynramConfigOnDLS(toEnum());
}

CommonSynramConfigOnDLS const CommonSynramConfigOnDLS::top{enum_vertical_top};
CommonSynramConfigOnDLS const CommonSynramConfigOnDLS::bottom{enum_vertical_bottom};

SynramOnDLS const SynramOnDLS::top{enum_vertical_top};
SynramOnDLS const SynramOnDLS::bottom{enum_vertical_bottom};

} // namespace halco::hicann_dls::vx
