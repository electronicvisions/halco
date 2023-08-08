#pragma once
#include "halco/common/genpybind.h"

#include "halco/hicann-dls/vx/v4/background.h"
#include "halco/hicann-dls/vx/v4/barrier.h"
#include "halco/hicann-dls/vx/v4/cadc.h"
#include "halco/hicann-dls/vx/v4/capmem.h"
#include "halco/hicann-dls/vx/v4/chip.h"
#include "halco/hicann-dls/vx/v4/correlation.h"
#include "halco/hicann-dls/vx/v4/current_dac.h"
#include "halco/hicann-dls/vx/v4/dac.h"
#include "halco/hicann-dls/vx/v4/event.h"
#include "halco/hicann-dls/vx/v4/extoll.h"
#include "halco/hicann-dls/vx/v4/fpga.h"
#include "halco/hicann-dls/vx/v4/highspeed_link.h"
#include "halco/hicann-dls/vx/v4/i2c.h"
#include "halco/hicann-dls/vx/v4/jtag.h"
#include "halco/hicann-dls/vx/v4/madc.h"
#include "halco/hicann-dls/vx/v4/memory_timing.h"
#include "halco/hicann-dls/vx/v4/neuron.h"
#include "halco/hicann-dls/vx/v4/omnibus.h"
#include "halco/hicann-dls/vx/v4/padi.h"
#include "halco/hicann-dls/vx/v4/pll.h"
#include "halco/hicann-dls/vx/v4/ppu.h"
#include "halco/hicann-dls/vx/v4/quad.h"
#include "halco/hicann-dls/vx/v4/readout.h"
#include "halco/hicann-dls/vx/v4/reset.h"
#include "halco/hicann-dls/vx/v4/routing_crossbar.h"
#include "halco/hicann-dls/vx/v4/spi.h"
#include "halco/hicann-dls/vx/v4/switch_rows.h"
#include "halco/hicann-dls/vx/v4/synapse.h"
#include "halco/hicann-dls/vx/v4/synapse_driver.h"
#include "halco/hicann-dls/vx/v4/synram.h"
#include "halco/hicann-dls/vx/v4/timing.h"
#include "halco/hicann-dls/vx/v4/ultra96.h"
#include "halco/hicann-dls/vx/v4/vector_generator.h"
#include "halco/hicann-dls/vx/v4/xboard.h"

namespace halco::hicann_dls::vx::v4 {
#define COORDINATE(Name, Type) typedef Type Name;

struct GENPYBIND(hidden) Coordinates
{
#include "halco/hicann-dls/vx/v4/coordinates.def"
};

typedef common::Coordinate Coordinate GENPYBIND(visible);

} // halco::hicann_dsl::vx:v4
