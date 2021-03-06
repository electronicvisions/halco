#pragma once
#include "halco/common/genpybind.h"

#include "halco/hicann-dls/vx/v2/background.h"
#include "halco/hicann-dls/vx/v2/barrier.h"
#include "halco/hicann-dls/vx/v2/cadc.h"
#include "halco/hicann-dls/vx/v2/capmem.h"
#include "halco/hicann-dls/vx/v2/chip.h"
#include "halco/hicann-dls/vx/v2/correlation.h"
#include "halco/hicann-dls/vx/v2/dac.h"
#include "halco/hicann-dls/vx/v2/event.h"
#include "halco/hicann-dls/vx/v2/fpga.h"
#include "halco/hicann-dls/vx/v2/highspeed_link.h"
#include "halco/hicann-dls/vx/v2/i2c.h"
#include "halco/hicann-dls/vx/v2/jtag.h"
#include "halco/hicann-dls/vx/v2/madc.h"
#include "halco/hicann-dls/vx/v2/neuron.h"
#include "halco/hicann-dls/vx/v2/omnibus.h"
#include "halco/hicann-dls/vx/v2/padi.h"
#include "halco/hicann-dls/vx/v2/pll.h"
#include "halco/hicann-dls/vx/v2/ppu.h"
#include "halco/hicann-dls/vx/v2/quad.h"
#include "halco/hicann-dls/vx/v2/readout.h"
#include "halco/hicann-dls/vx/v2/reset.h"
#include "halco/hicann-dls/vx/v2/routing_crossbar.h"
#include "halco/hicann-dls/vx/v2/spi.h"
#include "halco/hicann-dls/vx/v2/switch_rows.h"
#include "halco/hicann-dls/vx/v2/synapse.h"
#include "halco/hicann-dls/vx/v2/synapse_driver.h"
#include "halco/hicann-dls/vx/v2/synram.h"
#include "halco/hicann-dls/vx/v2/timing.h"
#include "halco/hicann-dls/vx/v2/ultra96.h"
#include "halco/hicann-dls/vx/v2/vector_generator.h"
#include "halco/hicann-dls/vx/v2/xboard.h"

namespace halco::hicann_dls::vx::v2 {
#define COORDINATE(Name, Type) typedef Type Name;

struct GENPYBIND(hidden) Coordinates
{
#include "halco/hicann-dls/vx/v2/coordinates.def"
};

} // halco::hicann_dsl::vx:v2
