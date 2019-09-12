#pragma once

#include "halco/common/geometry.h"
#include "halco/common/relations.h"
#include "halco/common/tblr.h"

namespace halco {
namespace hicann {
namespace v2 {

struct QuadrantOnHICANN
    : public common::detail::GridCoordinate<QuadrantOnHICANN,
                                            common::SideHorizontal,
                                            common::SideVertical>,
      public common::detail::HasTopBottom<QuadrantOnHICANN>,
      public common::detail::HasLeftRight<QuadrantOnHICANN> {
	GRID_COMMON_CONSTRUCTORS(QuadrantOnHICANN)
};

} // v2
} // namespace hicann
} // namespace halco

// std::hash specializations
namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::QuadrantOnHICANN)

} // std
