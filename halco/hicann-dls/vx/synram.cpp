#include "halco/hicann-dls/vx/synram.h"

namespace halco::hicann_dls::vx {

SynramOnDLS CommonSynramConfigOnDLS::toSynramOnDLS() const
{
	return SynramOnDLS(toEnum());
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
