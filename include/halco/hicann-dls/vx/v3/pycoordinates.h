#pragma once

#include "halco/common/genpybind.h"
#include <pybind11/pybind11.h>

GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V3
GENPYBIND_MANUAL({
	parent.attr("__variant__") = "pybind11";
	parent->py::module::import("pyhalco_common");
})

#include "halco/hicann-dls/vx/v3/coordinates.h"

GENPYBIND(postamble, tag(hicann_dls_vx_v3))
GENPYBIND_MANUAL({
	parent->py::module::import("pyhalco_hicann_dls_vx_patch").attr("patch")(parent);
})

namespace halco::hicann_dls::vx::v3 {

pybind11::list get_coordinates_list(pybind11::module& m);

GENPYBIND_MANUAL({
	parent.attr("coordinates") = [&parent]() {
		return halco::hicann_dls::vx::v3::get_coordinates_list(parent);
	}();
})

} // halco::hicann_dls::vx::v3
