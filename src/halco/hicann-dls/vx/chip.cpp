#include "halco/hicann-dls/vx/chip.h"

#include "halco/hicann-dls/vx/hemisphere.h"

namespace halco::hicann_dls::vx {

HemisphereOnDLS const HemisphereOnDLS::top{0};
HemisphereOnDLS const HemisphereOnDLS::bottom{1};

#define HEMISPHERE_CLASS HemisphereOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

} // namespace halco::hicann_dls::vx
