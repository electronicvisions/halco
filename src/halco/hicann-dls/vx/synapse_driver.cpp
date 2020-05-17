#include "halco/hicann-dls/vx/synapse_driver.h"

#include <array>

#include "halco/hicann-dls/vx/cadc.h"
#include "halco/hicann-dls/vx/capmem.h"
#include "halco/hicann-dls/vx/chip.h"
#include "halco/hicann-dls/vx/correlation.h"
#include "halco/hicann-dls/vx/neuron.h"
#include "halco/hicann-dls/vx/padi.h"
#include "halco/hicann-dls/vx/ppu.h"
#include "halco/hicann-dls/vx/synapse.h"
#include "halco/hicann-dls/vx/synram.h"

namespace halco::hicann_dls::vx {

SynapseDriverBlockOnDLS const SynapseDriverBlockOnDLS::top{enum_vertical_top};
SynapseDriverBlockOnDLS const SynapseDriverBlockOnDLS::bottom{enum_vertical_bottom};

CommonSynapseDriverConfigOnDLS const CommonSynapseDriverConfigOnDLS::top{enum_vertical_top};
CommonSynapseDriverConfigOnDLS const CommonSynapseDriverConfigOnDLS::bottom{enum_vertical_bottom};

SynapseDriverSRAMTimingConfigOnDLS const SynapseDriverSRAMTimingConfigOnDLS::top{enum_vertical_top};
SynapseDriverSRAMTimingConfigOnDLS const SynapseDriverSRAMTimingConfigOnDLS::bottom{
    enum_vertical_bottom};

#define HEMISPHERE_CLASS SynapseDriverBlockOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

#define HEMISPHERE_CLASS CommonSynapseDriverConfigOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

#define HEMISPHERE_CLASS SynapseDriverSRAMTimingConfigOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

PADIBusOnPADIBusBlock SynapseDriverOnSynapseDriverBlock::toPADIBusOnPADIBusBlock() const
{
	return PADIBusOnPADIBusBlock(toEnum() % PADIBusOnPADIBusBlock::size);
}

SynapseDriverOnPADIBus SynapseDriverOnSynapseDriverBlock::toSynapseDriverOnPADIBus() const
{
	return SynapseDriverOnPADIBus(toEnum() / PADIBusOnPADIBusBlock::size);
}

CapMemBlockOnDLS SynapseDriverOnDLS::toCapMemBlockOnDLS() const
{
	int const hemisphere_id = toSynapseDriverBlockOnDLS().toHemisphereOnDLS().toEnum();
	bool const is_odd = toSynapseDriverOnSynapseDriverBlock().toEnum() % 2;

	int const capmem_block_id = (2 * hemisphere_id) + is_odd;
	return CapMemBlockOnDLS(capmem_block_id);
}

std::array<SynapseRowOnDLS, SynapseRowOnDLS::size / SynapseDriverOnDLS::size>
SynapseDriverOnDLS::toSynapseRowOnDLS() const
{
	constexpr int rows_per_driver = SynapseRowOnDLS::size / SynapseDriverOnDLS::size;
	return {SynapseRowOnDLS(halco::common::Enum(toEnum() * rows_per_driver)),
	        SynapseRowOnDLS(halco::common::Enum((toEnum() * rows_per_driver) + 1))};
}
} // namespace halco::hicann_dls::vx
