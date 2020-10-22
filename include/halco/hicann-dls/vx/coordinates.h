#pragma once
#include "halco/common/genpybind.h"

GENPYBIND_TAG_HALCO_HICANN_DLS_VX
GENPYBIND_MANUAL({
	parent.attr("__variant__") = "pybind11";
	parent->py::module::import("pyhalco_common");
})

#include "halco/hicann-dls/vx/background.h"
#include "halco/hicann-dls/vx/barrier.h"
#include "halco/hicann-dls/vx/cadc.h"
#include "halco/hicann-dls/vx/capmem.h"
#include "halco/hicann-dls/vx/chip.h"
#include "halco/hicann-dls/vx/correlation.h"
#include "halco/hicann-dls/vx/dac.h"
#include "halco/hicann-dls/vx/event.h"
#include "halco/hicann-dls/vx/fpga.h"
#include "halco/hicann-dls/vx/highspeed_link.h"
#include "halco/hicann-dls/vx/i2c.h"
#include "halco/hicann-dls/vx/jtag.h"
#include "halco/hicann-dls/vx/madc.h"
#include "halco/hicann-dls/vx/neuron.h"
#include "halco/hicann-dls/vx/omnibus.h"
#include "halco/hicann-dls/vx/padi.h"
#include "halco/hicann-dls/vx/pll.h"
#include "halco/hicann-dls/vx/ppu.h"
#include "halco/hicann-dls/vx/quad.h"
#include "halco/hicann-dls/vx/readout.h"
#include "halco/hicann-dls/vx/reset.h"
#include "halco/hicann-dls/vx/routing_crossbar.h"
#include "halco/hicann-dls/vx/spi.h"
#include "halco/hicann-dls/vx/synapse.h"
#include "halco/hicann-dls/vx/synapse_driver.h"
#include "halco/hicann-dls/vx/synram.h"
#include "halco/hicann-dls/vx/timing.h"
#include "halco/hicann-dls/vx/ultra96.h"
#include "halco/hicann-dls/vx/xboard.h"

GENPYBIND(postamble, tag(hicann_dls_vx))
GENPYBIND_MANUAL({
	parent->py::module::import("pyhalco_hicann_dls_vx_patch").attr("patch")(parent);
})
