#include "halco/hicann-dls/vx/coordinates.h"

namespace halco {
namespace hicann_dls {
namespace vx {

using namespace halco::common;

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

} // namespace vx
} // namespace hicann_dls
} // namespace halco
