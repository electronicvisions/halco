#pragma once
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "hate/math.h"
#include "hate/visibility.h"

namespace halco::hicann_dls {
namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/********\
   FPGA
\********/

/**
 * Unique coordinate for a Multichip Jboa Leaf FPGA on a composition of this FPGA and a chip.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    FPGAOnChipAndMultichipJboaLeafFPGA
    : public common::detail::RantWrapper<FPGAOnChipAndMultichipJboaLeafFPGA, uint_fast16_t, 0, 0>
    , common::CoordinateBase<FPGAOnChipAndMultichipJboaLeafFPGA>
{
	constexpr explicit FPGAOnChipAndMultichipJboaLeafFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{
	}
};

/**
 * Unique coordinate for a Single Chip FPGA on a composition of this FPGA and a chip.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    FPGAOnChipAndSinglechipFPGA
    : public common::detail::RantWrapper<FPGAOnChipAndSinglechipFPGA, uint_fast16_t, 0, 0>
    , common::CoordinateBase<FPGAOnChipAndSinglechipFPGA>
{
	constexpr explicit FPGAOnChipAndSinglechipFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{
	}
};

} // namespace vx
} // namespace halco::hicann_dls

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::FPGAOnChipAndMultichipJboaLeafFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::FPGAOnChipAndSinglechipFPGA)

} // namespace std
