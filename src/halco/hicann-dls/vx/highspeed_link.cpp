#include "halco/hicann-dls/vx/highspeed_link.h"

#include "halco/hicann-dls/vx/jtag.h"

namespace halco::hicann_dls::vx {

JTAGPhyRegisterOnDLS PhyConfigChipOnDLS::toJTAGPhyRegisterOnDLS() const
{
	return JTAGPhyRegisterOnDLS(max - toEnum());
}

} // namespace halco::hicann_dls::vx
