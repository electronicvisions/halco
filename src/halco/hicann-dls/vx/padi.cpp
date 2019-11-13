#include "halco/hicann-dls/vx/padi.h"

#include "halco/hicann-dls/vx/cadc.h"
#include "halco/hicann-dls/vx/chip.h"
#include "halco/hicann-dls/vx/ppu.h"
#include "halco/hicann-dls/vx/routing_crossbar.h"
#include "halco/hicann-dls/vx/synapse_driver.h"
#include "halco/hicann-dls/vx/synram.h"

namespace halco::hicann_dls::vx {

PADIBusBlockOnDLS const PADIBusBlockOnDLS::bottom{enum_vertical_bottom};
PADIBusBlockOnDLS const PADIBusBlockOnDLS::top{enum_vertical_top};

PADIEventOnDLS const PADIEventOnDLS::bottom{enum_vertical_bottom};
PADIEventOnDLS const PADIEventOnDLS::top{enum_vertical_top};

CommonPADIBusConfigOnDLS const CommonPADIBusConfigOnDLS::bottom{enum_vertical_bottom};
CommonPADIBusConfigOnDLS const CommonPADIBusConfigOnDLS::top{enum_vertical_top};

CommonSTPConfigOnDLS const CommonSTPConfigOnDLS::bottom{enum_vertical_bottom};
CommonSTPConfigOnDLS const CommonSTPConfigOnDLS::top{enum_vertical_top};

#define HEMISPHERE_CLASS PADIBusBlockOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

#define HEMISPHERE_CLASS CommonPADIBusConfigOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

#define HEMISPHERE_CLASS CommonSTPConfigOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

#define HEMISPHERE_CLASS PADIEventOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

CrossbarOutputOnDLS PADIBusOnDLS::toCrossbarOutputOnDLS() const
{
	return CrossbarOutputOnDLS(toEnum());
}

} // namespace halco::hicann_dls::vx
