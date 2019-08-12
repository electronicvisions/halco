#pragma once

#include "pywrap/compat/macros.hpp"

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"
#include "halco/common/relations.h"

#include "halco/hicann/v2/fwd.h"

namespace halco {
namespace hicann {
namespace v2 GENPYBIND_TAG_HALCO_HICANN_V2 {

/// Wafer coordinate
struct GENPYBIND(inline_base("*")) Wafer : public common::detail::BaseType<Wafer, size_t>
{
	PYPP_CONSTEXPR explicit Wafer(value_type val) GENPYBIND(implicit_conversion) : base_t(val) {}
	PYPP_CONSTEXPR explicit Wafer() GENPYBIND(implicit_conversion) : base_t() {}
};

HALCO_COORDINATE_MIXIN(WaferMixin, Wafer, wafer)

} // v2
} // hicann
} // halco

// std::hash specializations
namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::Wafer)

} // std
