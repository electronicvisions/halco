#pragma once

#include "halco/common/genpybind.h"
#include <pybind11/pybind11.h>

GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V4
GENPYBIND_MANUAL({
	parent.attr("__variant__") = "pybind11";
	parent->py::module::import("pyhalco_common");
})

#include "halco/hicann-dls/vx/v4/coordinates.h"

GENPYBIND(postamble, tag(hicann_dls_vx_v4))
GENPYBIND_MANUAL({
	parent->py::module::import("pyhalco_hicann_dls_vx_patch").attr("patch")(parent);
})
