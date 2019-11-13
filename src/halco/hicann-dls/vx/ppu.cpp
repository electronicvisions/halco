#include "halco/hicann-dls/vx/ppu.h"

#include "halco/hicann-dls/vx/coordinates.h"

namespace halco::hicann_dls::vx {

PPUOnDLS const PPUOnDLS::top{enum_vertical_top};
PPUOnDLS const PPUOnDLS::bottom{enum_vertical_bottom};

#define HEMISPHERE_CLASS PPUOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

#define HEMISPHERE_CLASS PPUMemoryOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

#define HEMISPHERE_CLASS PPUControlRegisterOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

#define HEMISPHERE_CLASS PPUStatusRegisterOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

PPUMemoryBlockOnPPU const PPUMemoryBlockOnPPU::mailbox(
    PPUMemoryWordOnPPU(3072), PPUMemoryWordOnPPU(4095));

PPUMemoryWordOnPPU const PPUMemoryWordOnPPU::return_code(3071);

} // namespace halco::hicann_dls::vx
