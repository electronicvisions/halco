#pragma once

extern "C" {
#include <stdint.h>
}

#include <boost/serialization/access.hpp>
#include <boost/serialization/nvp.hpp>

#include "pywrap/compat/macros.hpp"

#include "halco/common/geometry.h"
#include "halco/common/relations.h"
#include "halco/common/tblr.h"

namespace halco {
namespace hicann {
namespace v2 {

struct FGRowOnFGBlock
    : public common::detail::RantWrapper<FGRowOnFGBlock, uint_fast16_t, 23, 0>
    , public common::detail::YRangedTrait {
	PYPP_CONSTEXPR explicit FGRowOnFGBlock(common::Y const& y) : rant_t(y.value()) {}
	PYPP_CONSTEXPR explicit FGRowOnFGBlock(uintmax_t const val = 0) : rant_t(val) {}
};

struct FGCellOnFGBlock
	: public common::detail::
		  GridCoordinate<FGCellOnFGBlock, common::XRanged<128, 0>, FGRowOnFGBlock> {
	GRID_COMMON_CONSTRUCTORS(FGCellOnFGBlock)

	FGRowOnFGBlock toFGRowOnFGBlock() const;
};

struct FGBlockOnHICANN
    : public common::detail::GridCoordinate<FGBlockOnHICANN, common::XRanged<1, 0>,
                                            common::YRanged<1, 0> >,
      common::detail::HasTopBottom<FGBlockOnHICANN>,
      common::detail::HasLeftRight<FGBlockOnHICANN> {
	GRID_COMMON_CONSTRUCTORS(FGBlockOnHICANN)
};

} // v2
} // hicann
} // halco

// std::hash specializations
namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::FGBlockOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::FGRowOnFGBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::FGCellOnFGBlock)

} // std
