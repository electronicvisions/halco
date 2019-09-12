#pragma once

#include "halco/common/genpybind.h"

/**
 * @file
 * This file provides coordinates common to all chips.
 */

GENPYBIND_TAG_HALCO_COMMON
GENPYBIND_MANUAL({ parent.attr("__variant__") = "pybind11"; })

#include "halco/common/relations.h"
#include "halco/common/geometry.h"
#include "halco/common/iter_all.h"
#include "halco/common/tblr.h"
#include "halco/common/traits.h"
#include "halco/common/typed_array.h"

GENPYBIND(postamble, tag(common))
GENPYBIND_MANUAL({ parent->py::module::import("pyhalco_common_patch").attr("patch")(parent); })
