#pragma once
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "hate/math.h"
#include "hate/visibility.h"

namespace halco::hicann_dls {
namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/**********\
   System
\**********/

/**
 * Unique coordinate for a composition containing a Multichip Jboa Leaf FPGA and a chip.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    ChipAndMultichipJboaLeafFPGAOnSystem
    : public common::detail::RantWrapper<ChipAndMultichipJboaLeafFPGAOnSystem, uint_fast16_t, 0, 0>
    , common::CoordinateBase<ChipAndMultichipJboaLeafFPGAOnSystem>
{
	constexpr explicit ChipAndMultichipJboaLeafFPGAOnSystem(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{
	}
};

/**
 * Unique coordinate for a composition containing a Singlechip FPGA and a chip.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    ChipAndSinglechipFPGAOnSystem
    : public common::detail::RantWrapper<ChipAndSinglechipFPGAOnSystem, uint_fast16_t, 0, 0>
    , common::CoordinateBase<ChipAndSinglechipFPGAOnSystem>
{
	constexpr explicit ChipAndSinglechipFPGAOnSystem(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{
	}
};

} // namespace vx
} // namespace halco::hicann_dls

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ChipAndMultichipJboaLeafFPGAOnSystem)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ChipAndSinglechipFPGAOnSystem)

} // namespace std
