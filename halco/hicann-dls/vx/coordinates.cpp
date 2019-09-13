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

CommonSynapseDriverConfigOnDLS SynapseDriverBlockOnDLS::toCommonSynapseDriverConfigOnDLS() const
{
	return CommonSynapseDriverConfigOnDLS(toEnum());
}

SynapseDriverBlockOnDLS const SynapseDriverBlockOnDLS::top{enum_vertical_top};
SynapseDriverBlockOnDLS const SynapseDriverBlockOnDLS::bottom{enum_vertical_bottom};

CommonSynapseDriverConfigOnDLS const CommonSynapseDriverConfigOnDLS::top{enum_vertical_top};
CommonSynapseDriverConfigOnDLS const CommonSynapseDriverConfigOnDLS::bottom{
    enum_vertical_bottom};

PADIBusBlockOnDLS const PADIBusBlockOnDLS::bottom{enum_vertical_bottom};
PADIBusBlockOnDLS const PADIBusBlockOnDLS::top{enum_vertical_top};

PADIEventOnDLS const PADIEventOnDLS::bottom{enum_vertical_bottom};
PADIEventOnDLS const PADIEventOnDLS::top{enum_vertical_top};

CommonPADIBusConfigOnDLS const CommonPADIBusConfigOnDLS::bottom{enum_vertical_bottom};
CommonPADIBusConfigOnDLS const CommonPADIBusConfigOnDLS::top{enum_vertical_top};

CommonSTPConfigOnDLS const CommonSTPConfigOnDLS::bottom{enum_vertical_bottom};
CommonSTPConfigOnDLS const CommonSTPConfigOnDLS::top{enum_vertical_top};

SynramOnDLS PADIBusBlockOnDLS::toSynramOnDLS() const
{
	return SynramOnDLS(toEnum());
}

PADIEventOnDLS PADIBusBlockOnDLS::toPADIEventOnDLS() const
{
	return PADIEventOnDLS(toEnum());
}

CommonPADIBusConfigOnDLS PADIBusBlockOnDLS::toCommonPADIBusConfigOnDLS() const
{
	return CommonPADIBusConfigOnDLS(toEnum());
}

CommonSTPConfigOnDLS PADIBusBlockOnDLS::toCommonSTPConfigOnDLS() const
{
	return CommonSTPConfigOnDLS(toEnum());
}

CADCChannelType const CADCChannelType::causal{0};
CADCChannelType const CADCChannelType::acausal{1};

CADCReadoutType const CADCReadoutType::trigger_read{0};
CADCReadoutType const CADCReadoutType::buffered{1};

} // namespace vx
} // namespace hicann_dls
} // namespace halco
