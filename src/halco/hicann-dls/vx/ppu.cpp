#include "halco/hicann-dls/vx/ppu.h"

#include "halco/hicann-dls/vx/coordinates.h"

namespace halco::hicann_dls::vx {

PPUOnDLS const PPUOnDLS::top{enum_vertical_top};
PPUOnDLS const PPUOnDLS::bottom{enum_vertical_bottom};

CADCConfigOnDLS PPUOnDLS::toCADCConfigOnDLS() const
{
	return CADCConfigOnDLS(toEnum());
}

PPUMemoryOnDLS PPUOnDLS::toPPUMemoryOnDLS() const
{
	return PPUMemoryOnDLS(toEnum());
}

PPUControlRegisterOnDLS PPUOnDLS::toPPUControlRegisterOnDLS() const
{
	return PPUControlRegisterOnDLS(toEnum());
}

PPUStatusRegisterOnDLS PPUOnDLS::toPPUStatusRegisterOnDLS() const
{
	return PPUStatusRegisterOnDLS(toEnum());
}

PPUOnDLS PPUMemoryOnDLS::toPPUOnDLS() const
{
	return PPUOnDLS(toEnum());
}

PPUOnDLS PPUControlRegisterOnDLS::toPPUOnDLS() const
{
	return PPUOnDLS(toEnum());
}

PPUOnDLS PPUStatusRegisterOnDLS::toPPUOnDLS() const
{
	return PPUOnDLS(toEnum());
}

PPUMemoryBlockOnPPU const PPUMemoryBlockOnPPU::mailbox(
    PPUMemoryWordOnPPU(3072), PPUMemoryWordOnPPU(4095));

PPUMemoryWordOnPPU const PPUMemoryWordOnPPU::return_code(3071);

} // namespace halco::hicann_dls::vx
