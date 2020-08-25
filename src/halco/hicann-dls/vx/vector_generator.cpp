#include "halco/hicann-dls/vx/vector_generator.h"

#include "halco/hicann-dls/vx/cadc.h"
#include "halco/hicann-dls/vx/chip.h"
#include "halco/hicann-dls/vx/correlation.h"
#include "halco/hicann-dls/vx/neuron.h"
#include "halco/hicann-dls/vx/padi.h"
#include "halco/hicann-dls/vx/ppu.h"
#include "halco/hicann-dls/vx/synapse_driver.h"
#include "halco/hicann-dls/vx/synram.h"

namespace halco::hicann_dls::vx {

#define HEMISPHERE_CLASS VectorGeneratorOnFPGA
#include "halco/hicann-dls/vx/convert_hemisphere.h"

#define HEMISPHERE_CLASS VectorGeneratorControlOnFPGA
#include "halco/hicann-dls/vx/convert_hemisphere.h"

#define HEMISPHERE_CLASS VectorGeneratorLUTOnFPGA
#include "halco/hicann-dls/vx/convert_hemisphere.h"

#define HEMISPHERE_CLASS VectorGeneratorNotificationAddressOnFPGA
#include "halco/hicann-dls/vx/convert_hemisphere.h"

#define HEMISPHERE_CLASS VectorGeneratorTriggerOnFPGA
#include "halco/hicann-dls/vx/convert_hemisphere.h"

#define HEMISPHERE_CLASS VectorGeneratorFIFOWordOnFPGA
#include "halco/hicann-dls/vx/convert_hemisphere.h"

VectorGeneratorOnFPGA const VectorGeneratorOnFPGA::top{enum_vertical_top};
VectorGeneratorOnFPGA const VectorGeneratorOnFPGA::bottom{enum_vertical_bottom};

VectorGeneratorControlOnFPGA const VectorGeneratorControlOnFPGA::top{enum_vertical_top};
VectorGeneratorControlOnFPGA const VectorGeneratorControlOnFPGA::bottom{enum_vertical_bottom};

VectorGeneratorLUTOnFPGA const VectorGeneratorLUTOnFPGA::top{enum_vertical_top};
VectorGeneratorLUTOnFPGA const VectorGeneratorLUTOnFPGA::bottom{enum_vertical_bottom};

VectorGeneratorNotificationAddressOnFPGA const VectorGeneratorNotificationAddressOnFPGA::top{
    enum_vertical_top};
VectorGeneratorNotificationAddressOnFPGA const VectorGeneratorNotificationAddressOnFPGA::bottom{
    enum_vertical_bottom};

VectorGeneratorTriggerOnFPGA const VectorGeneratorTriggerOnFPGA::top{enum_vertical_top};
VectorGeneratorTriggerOnFPGA const VectorGeneratorTriggerOnFPGA::bottom{enum_vertical_bottom};

VectorGeneratorFIFOWordOnFPGA const VectorGeneratorFIFOWordOnFPGA::top{enum_vertical_top};
VectorGeneratorFIFOWordOnFPGA const VectorGeneratorFIFOWordOnFPGA::bottom{enum_vertical_bottom};

} // namespace halco::hicann_dls::vx
