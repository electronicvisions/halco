#include "halco/hicann-dls/vx/cadc.h"

#include "halco/hicann-dls/vx/ppu.h"

namespace halco::hicann_dls::vx {

CADCConfigOnDLS const CADCConfigOnDLS::top{enum_vertical_top};
CADCConfigOnDLS const CADCConfigOnDLS::bottom{enum_vertical_bottom};

PPUOnDLS CADCConfigOnDLS::toPPUOnDLS() const
{
	return PPUOnDLS(toEnum());
}

CADCChannelType const CADCChannelType::causal{0};
CADCChannelType const CADCChannelType::acausal{1};

CADCReadoutType const CADCReadoutType::trigger_read{0};
CADCReadoutType const CADCReadoutType::buffered{1};

} // namespace halco::hicann_dls::vx
