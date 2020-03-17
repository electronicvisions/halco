#include "halco/hicann-dls/vx/chip.h"

#include "halco/hicann-dls/vx/cadc.h"
#include "halco/hicann-dls/vx/correlation.h"
#include "halco/hicann-dls/vx/neuron.h"
#include "halco/hicann-dls/vx/padi.h"
#include "halco/hicann-dls/vx/ppu.h"
#include "halco/hicann-dls/vx/synapse_driver.h"
#include "halco/hicann-dls/vx/synram.h"

namespace halco::hicann_dls::vx {

#define HEMISPHERE_CLASS HemisphereOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

} // namespace halco::hicann_dls::vx
