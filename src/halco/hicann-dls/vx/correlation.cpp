#include "halco/hicann-dls/vx/correlation.h"

#include "halco/hicann-dls/vx/coordinates.h"

namespace halco::hicann_dls::vx {

#define HEMISPHERE_CLASS CommonCorrelationConfigOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

CommonCorrelationConfigOnDLS const CommonCorrelationConfigOnDLS::top{enum_vertical_top};
CommonCorrelationConfigOnDLS const CommonCorrelationConfigOnDLS::bottom{enum_vertical_bottom};

}
