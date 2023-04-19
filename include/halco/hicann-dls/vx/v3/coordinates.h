#pragma once
#include "halco/common/genpybind.h"

#include "halco/hicann-dls/vx/v3/background.h"
#include "halco/hicann-dls/vx/v3/barrier.h"
#include "halco/hicann-dls/vx/v3/cadc.h"
#include "halco/hicann-dls/vx/v3/capmem.h"
#include "halco/hicann-dls/vx/v3/chip.h"
#include "halco/hicann-dls/vx/v3/correlation.h"
#include "halco/hicann-dls/vx/v3/current_dac.h"
#include "halco/hicann-dls/vx/v3/dac.h"
#include "halco/hicann-dls/vx/v3/event.h"
#include "halco/hicann-dls/vx/v3/extoll.h"
#include "halco/hicann-dls/vx/v3/fpga.h"
#include "halco/hicann-dls/vx/v3/highspeed_link.h"
#include "halco/hicann-dls/vx/v3/i2c.h"
#include "halco/hicann-dls/vx/v3/jtag.h"
#include "halco/hicann-dls/vx/v3/madc.h"
#include "halco/hicann-dls/vx/v3/memory_timing.h"
#include "halco/hicann-dls/vx/v3/neuron.h"
#include "halco/hicann-dls/vx/v3/omnibus.h"
#include "halco/hicann-dls/vx/v3/padi.h"
#include "halco/hicann-dls/vx/v3/pll.h"
#include "halco/hicann-dls/vx/v3/ppu.h"
#include "halco/hicann-dls/vx/v3/quad.h"
#include "halco/hicann-dls/vx/v3/readout.h"
#include "halco/hicann-dls/vx/v3/reset.h"
#include "halco/hicann-dls/vx/v3/routing_crossbar.h"
#include "halco/hicann-dls/vx/v3/spi.h"
#include "halco/hicann-dls/vx/v3/switch_rows.h"
#include "halco/hicann-dls/vx/v3/synapse.h"
#include "halco/hicann-dls/vx/v3/synapse_driver.h"
#include "halco/hicann-dls/vx/v3/synram.h"
#include "halco/hicann-dls/vx/v3/timing.h"
#include "halco/hicann-dls/vx/v3/ultra96.h"
#include "halco/hicann-dls/vx/v3/vector_generator.h"
#include "halco/hicann-dls/vx/v3/xboard.h"

namespace halco::hicann_dls::vx::v3 {
#define COORDINATE(Name, Type) typedef Type Name;

struct GENPYBIND(hidden) Coordinates
{
#include "halco/hicann-dls/vx/v3/coordinates.def"
};

typedef common::Coordinate Coordinate GENPYBIND(visible);

} // halco::hicann_dsl::vx:v3
