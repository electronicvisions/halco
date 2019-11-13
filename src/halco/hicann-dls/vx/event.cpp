#include "halco/hicann-dls/vx/event.h"

#include "halco/hicann-dls/vx/background.h"
#include "halco/hicann-dls/vx/padi.h"
#include "halco/hicann-dls/vx/routing_crossbar.h"

namespace halco::hicann_dls::vx {

CrossbarInputOnDLS SPL1Address::toCrossbarInputOnDLS() const
{
	return CrossbarInputOnDLS(
	    toEnum() +
	    (CrossbarInputOnDLS::size - BackgroundSpikeSourceOnDLS::size - SPL1Address::size));
}

CrossbarL2OutputOnDLS SPL1Address::toCrossbarL2OutputOnDLS() const
{
	return CrossbarL2OutputOnDLS(toEnum());
}

} // namespace halco::hicann_dls::vx
