#pragma once

#include "halco/common/genpybind.h"

GENPYBIND_TAG_HALCO_HICANN_V2
GENPYBIND_MANUAL({
	parent.attr("__variant__") = "pybind11";
	parent->py::module::import("pyhalco_common_genpybind");
})

/**
 * @file
 * This file provides the HMF-specific Coordinates.
 */

#include "halco/hicann/v2/external.h"
#include "halco/hicann/v2/fg.h"
#include "halco/hicann/v2/hicann.h"
#include "halco/hicann/v2/l1.h"
#include "halco/hicann/v2/neuron.h"
#include "halco/hicann/v2/quadrant.h"
#include "halco/hicann/v2/synapse.h"
#include "halco/hicann/v2/wafer.h"
#include "halco/hicann/v2/merger0onhicann.h"
#include "halco/hicann/v2/merger1onhicann.h"
#include "halco/hicann/v2/merger2onhicann.h"
#include "halco/hicann/v2/merger3onhicann.h"
#include "halco/hicann/v2/lookup_tables.h"

#include "halco/hicann/v2/format_helper.h"

GENPYBIND(postamble, tag(hicann_v2))
GENPYBIND_MANUAL({
	parent->py::module::import("pyhalco_hicann_v2_patch_genpybind").attr("patch")(parent);
})
