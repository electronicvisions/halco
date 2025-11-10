#include "halco/hicann-dls/vx/routing_table_entry.h"

#include "halco/hicann-dls/vx/event.h"

namespace halco::hicann_dls::vx {

SpikeLabel OutputRoutingTableEntryOnFPGA::toSpikeLabel() const
{
	return SpikeLabel(toEnum());
}

} // namespace halco::hicann_dls::vx
