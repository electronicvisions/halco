#pragma once
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"
#include "hate/visibility.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct TMP112StatusOnBoard;

/************\
 CHIP CARRIER
\************/

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) TMP112StatusOnBoard
    : public common::detail::RantWrapper<TMP112StatusOnBoard, uint_fast16_t, 0, 0>
    , common::CoordinateBase<TMP112StatusOnBoard>
{
	constexpr explicit TMP112StatusOnBoard(uintmax_t const val = 0) : rant_t(val) {}
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::TMP112StatusOnBoard)

} // namespace std
