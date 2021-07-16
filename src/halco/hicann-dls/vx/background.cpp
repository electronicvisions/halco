#include "halco/hicann-dls/vx/background.h"

#include "halco/hicann-dls/vx/padi.h"
#include "halco/hicann-dls/vx/routing_crossbar.h"

namespace halco::hicann_dls::vx {

CrossbarInputOnDLS BackgroundSpikeSourceOnDLS::toCrossbarInputOnDLS() const
{
	// FIXME: Get constant from l2 and neuron input sizes once they exist
	return CrossbarInputOnDLS(toEnum() + 12);
}

CrossbarL2OutputOnDLS BackgroundSpikeSourceOnDLS::toCrossbarL2OutputOnDLS() const
{
	return CrossbarL2OutputOnDLS(toEnum() % CrossbarL2OutputOnDLS::size);
}

PADIBusOnDLS BackgroundSpikeSourceOnDLS::toPADIBusOnDLS() const
{
	return PADIBusOnDLS(toEnum());
}

} // namespace halco::hicann_dls::vx
