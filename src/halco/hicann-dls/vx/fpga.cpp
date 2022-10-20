#include "halco/hicann-dls/vx/fpga.h"

#include "halco/hicann-dls/vx/event.h"

namespace halco::hicann_dls::vx {

SpikeIOInputRouteOnFPGA SpikeIOAddress::toSpikeIOInputRouteOnFPGA() const
{
	return SpikeIOInputRouteOnFPGA(toEnum());
}

SpikeIOAddress SpikeIOInputRouteOnFPGA::toSpikeIOAddress() const
{
	return SpikeIOAddress(toEnum());
}

SpikeLabel SpikeIOOutputRouteOnFPGA::toSpikeLabel() const
{
	return SpikeLabel(toEnum());
}

} // namespace halco::hicann_dls::vx
