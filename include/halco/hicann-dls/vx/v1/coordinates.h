#pragma once
#include "halco/common/genpybind.h"

#include "halco/hicann-dls/vx/v1/background.h"
#include "halco/hicann-dls/vx/v1/barrier.h"
#include "halco/hicann-dls/vx/v1/cadc.h"
#include "halco/hicann-dls/vx/v1/capmem.h"
#include "halco/hicann-dls/vx/v1/chip.h"
#include "halco/hicann-dls/vx/v1/correlation.h"
#include "halco/hicann-dls/vx/v1/current_dac.h"
#include "halco/hicann-dls/vx/v1/dac.h"
#include "halco/hicann-dls/vx/v1/event.h"
#include "halco/hicann-dls/vx/v1/fpga.h"
#include "halco/hicann-dls/vx/v1/highspeed_link.h"
#include "halco/hicann-dls/vx/v1/i2c.h"
#include "halco/hicann-dls/vx/v1/jtag.h"
#include "halco/hicann-dls/vx/v1/madc.h"
#include "halco/hicann-dls/vx/v1/memory_timing.h"
#include "halco/hicann-dls/vx/v1/neuron.h"
#include "halco/hicann-dls/vx/v1/omnibus.h"
#include "halco/hicann-dls/vx/v1/padi.h"
#include "halco/hicann-dls/vx/v1/pll.h"
#include "halco/hicann-dls/vx/v1/ppu.h"
#include "halco/hicann-dls/vx/v1/quad.h"
#include "halco/hicann-dls/vx/v1/readout.h"
#include "halco/hicann-dls/vx/v1/reset.h"
#include "halco/hicann-dls/vx/v1/routing_crossbar.h"
#include "halco/hicann-dls/vx/v1/spi.h"
#include "halco/hicann-dls/vx/v1/switch_rows.h"
#include "halco/hicann-dls/vx/v1/synapse.h"
#include "halco/hicann-dls/vx/v1/synapse_driver.h"
#include "halco/hicann-dls/vx/v1/synram.h"
#include "halco/hicann-dls/vx/v1/timing.h"
#include "halco/hicann-dls/vx/v1/ultra96.h"
#include "halco/hicann-dls/vx/v1/vector_generator.h"
#include "halco/hicann-dls/vx/v1/xboard.h"

namespace halco::hicann_dls::vx::v1 {
#define COORDINATE(Name, Type) typedef Type Name;

struct GENPYBIND(hidden) Coordinates
{
#include "halco/hicann-dls/vx/v1/coordinates.def"
};

} // halco::hicann_dls::vx:v1
