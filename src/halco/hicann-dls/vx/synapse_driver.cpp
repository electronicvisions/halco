#include "halco/hicann-dls/vx/synapse_driver.h"

#include "halco/hicann-dls/vx/cadc.h"
#include "halco/hicann-dls/vx/chip.h"
#include "halco/hicann-dls/vx/padi.h"
#include "halco/hicann-dls/vx/ppu.h"
#include "halco/hicann-dls/vx/synram.h"

namespace halco::hicann_dls::vx {

SynapseDriverBlockOnDLS const SynapseDriverBlockOnDLS::top{enum_vertical_top};
SynapseDriverBlockOnDLS const SynapseDriverBlockOnDLS::bottom{enum_vertical_bottom};

CommonSynapseDriverConfigOnDLS const CommonSynapseDriverConfigOnDLS::top{enum_vertical_top};
CommonSynapseDriverConfigOnDLS const CommonSynapseDriverConfigOnDLS::bottom{enum_vertical_bottom};

#define HEMISPHERE_CLASS SynapseDriverBlockOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

#define HEMISPHERE_CLASS CommonSynapseDriverConfigOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

PADIBusOnPADIBusBlock SynapseDriverOnSynapseDriverBlock::toPADIBusOnPADIBusBlock() const
{
	return PADIBusOnPADIBusBlock(toEnum() % PADIBusOnPADIBusBlock::size);
}

} // namespace halco::hicann_dls::vx
