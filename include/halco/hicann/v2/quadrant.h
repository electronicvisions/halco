#pragma once

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/relations.h"
#include "halco/common/tblr.h"

namespace halco {
namespace hicann {
namespace v2 GENPYBIND_TAG_HALCO_HICANN_V2 {

struct GENPYBIND(inline_base("*")) QuadrantOnHICANN
    : public common::detail::
          GridCoordinate<QuadrantOnHICANN, common::SideHorizontal, common::SideVertical>
    , public common::detail::HasTopBottom<QuadrantOnHICANN>
    , public common::detail::HasLeftRight<QuadrantOnHICANN>
{
	GRID_COMMON_CONSTRUCTORS(QuadrantOnHICANN)
};

} // v2
} // namespace hicann
} // namespace halco

// std::hash specializations
namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::QuadrantOnHICANN)

} // std
