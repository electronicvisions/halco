#pragma once

#include "pywrap/compat/macros.hpp"

#include "halco/common/geometry.h"
#include "halco/common/mixin.h"
#include "halco/common/relations.h"

#include "halco/hicann/v2/fwd.h"

namespace halco {
namespace hicann {
namespace v2 {

/// Wafer coordinate
/// The Wafer coordinate is also used to determine the FPGA type. We define
/// old (Virtex) wafers/vsetups are using a value <= 2.
struct Wafer : public common::detail::BaseType<Wafer, size_t> {
	PYPP_CONSTEXPR explicit Wafer(value_type val) : base_t(val) {}
	PYPP_CONSTEXPR explicit Wafer() : base_t() {}
};

HALCO_COORDINATE_MIXIN(WaferMixin, Wafer, wafer)

} // v2
} // hicann
} // halco

// std::hash specializations
namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::Wafer)

} // std
