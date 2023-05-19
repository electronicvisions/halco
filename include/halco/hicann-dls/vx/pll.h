#pragma once
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "hate/visibility.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/**********\
    PLL
\**********/

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) PLLSelfTestOnDLS
    : public common::detail::RantWrapper<PLLSelfTestOnDLS, uint_fast16_t, 0, 0>
    , common::CoordinateBase<PLLSelfTestOnDLS>
{
	constexpr explicit PLLSelfTestOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    PLLSelfTestStatusOnDLS
    : public common::detail::RantWrapper<PLLSelfTestStatusOnDLS, uint_fast16_t, 0, 0>
    , common::CoordinateBase<PLLSelfTestStatusOnDLS>
{
	constexpr explicit PLLSelfTestStatusOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    PLLClockOutputBlockOnDLS
    : public common::detail::RantWrapper<PLLClockOutputBlockOnDLS, uint_fast16_t, 0, 0>
    , common::CoordinateBase<PLLClockOutputBlockOnDLS>
{
	constexpr explicit PLLClockOutputBlockOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) ADPLLOnDLS
    : public common::detail::RantWrapper<ADPLLOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<ADPLLOnDLS>
{
	constexpr explicit ADPLLOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) PLLClockOutputOnDLS
    : public common::detail::RantWrapper<PLLClockOutputOnDLS, uint_fast16_t, 3, 0>
{
	constexpr explicit PLLClockOutputOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const SYMBOL_VISIBLE PLLClockOutputOnDLS serdes_ser_send_clk;
	static const SYMBOL_VISIBLE PLLClockOutputOnDLS phy_ref_clk;
	static const SYMBOL_VISIBLE PLLClockOutputOnDLS ppu_clk;
	static const SYMBOL_VISIBLE PLLClockOutputOnDLS madc_clk;
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ADPLLOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PLLClockOutputOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PLLClockOutputBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PLLSelfTestOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PLLSelfTestStatusOnDLS)

} // namespace std
