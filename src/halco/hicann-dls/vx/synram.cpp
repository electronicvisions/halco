#include "halco/hicann-dls/vx/synram.h"

#include "halco/hicann-dls/vx/cadc.h"
#include "halco/hicann-dls/vx/chip.h"
#include "halco/hicann-dls/vx/correlation.h"
#include "halco/hicann-dls/vx/neuron.h"
#include "halco/hicann-dls/vx/padi.h"
#include "halco/hicann-dls/vx/ppu.h"
#include "halco/hicann-dls/vx/synapse_driver.h"

namespace halco::hicann_dls::vx {

#define HEMISPHERE_CLASS SynramOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

#define HEMISPHERE_CLASS CommonSynramConfigOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

CommonSynramConfigOnDLS const CommonSynramConfigOnDLS::top{enum_vertical_top};
CommonSynramConfigOnDLS const CommonSynramConfigOnDLS::bottom{enum_vertical_bottom};

SynramOnDLS const SynramOnDLS::top{enum_vertical_top};
SynramOnDLS const SynramOnDLS::bottom{enum_vertical_bottom};

} // namespace halco::hicann_dls::vx
