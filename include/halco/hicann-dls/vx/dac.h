#pragma once
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"
#include "hate/visibility.h"

namespace halco::hicann_dls { namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct VDDOnBoard;

/**
 * Coordinate describing the location of a DAC instance on the xBoard.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) DACOnBoard
    : public common::detail::RantWrapper<DACOnBoard, uint_fast16_t, 1, 0>
    , common::CoordinateBase<DACOnBoard>
{
	constexpr explicit DACOnBoard(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


/**
 * Coordinate describing the location of a DAC channel on a DAC.
 */
struct GENPYBIND(inline_base("*")) DACChannelOnDAC
    : public common::detail::RantWrapper<DACChannelOnDAC, uint_fast16_t, 7, 0>
{
	constexpr explicit DACChannelOnDAC(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


HALCO_COORDINATE_MIXIN(DACMixin, DACOnBoard, dac)

/**
 * Coordinate describing the location of a DAC channel on the xBoard.
 */
struct GENPYBIND(inline_base("*DACMixin*"), inline_base("*CoordinateBase*")) DACChannelOnBoard
    : public DACMixin<DACChannelOnBoard, DACChannelOnDAC>
    , common::CoordinateBase<DACChannelOnBoard>
{
	DACChannelOnBoard() = default;

	explicit DACChannelOnBoard(
	    DACChannelOnDAC const& channel, DACOnBoard const& dac = DACOnBoard()) :
	    mixin_t(channel, dac)
	{}

	explicit DACChannelOnBoard(enum_type const& e) : mixin_t(e) {}

	DACChannelOnDAC toDACChannelOnDAC() const { return This(); }

	static const SYMBOL_VISIBLE DACChannelOnBoard v_reset;
	static const SYMBOL_VISIBLE DACChannelOnBoard v_res_meas;
	static const SYMBOL_VISIBLE DACChannelOnBoard mux_rfu_0;
	static const SYMBOL_VISIBLE DACChannelOnBoard mux_rfu_1;
	static const SYMBOL_VISIBLE DACChannelOnBoard i_ref_board;
	static const SYMBOL_VISIBLE DACChannelOnBoard ana_readout_debug_0;
	static const SYMBOL_VISIBLE DACChannelOnBoard ana_readout_debug_1;
	static const SYMBOL_VISIBLE DACChannelOnBoard mux_dac_25;

	static const SYMBOL_VISIBLE DACChannelOnBoard vdd25_digital;
	static const SYMBOL_VISIBLE DACChannelOnBoard vdd12_digital;
	static const SYMBOL_VISIBLE DACChannelOnBoard vdd25_analog;
	static const SYMBOL_VISIBLE DACChannelOnBoard vdd12_analog;
	static const SYMBOL_VISIBLE DACChannelOnBoard vdd12_madc;
	static const SYMBOL_VISIBLE DACChannelOnBoard vdd12_pll;
	static const SYMBOL_VISIBLE DACChannelOnBoard general_purpose_0;
	static const SYMBOL_VISIBLE DACChannelOnBoard general_purpose_1;

	VDDOnBoard toVDDOnBoard() const SYMBOL_VISIBLE;
};


/**
 * Unique coordinate describing the location of the collection of all DAC control instances on the
 * xBoard.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    DACControlBlockOnBoard
    : public common::detail::RantWrapper<DACControlBlockOnBoard, uint_fast16_t, 0, 0>
    , common::CoordinateBase<DACControlBlockOnBoard>
{
	constexpr explicit DACControlBlockOnBoard(uintmax_t const val = 0) : rant_t(val) {}
};


/**
 * Unique coordinate describing the location of the collection of all DAC channel instances on the
 * xBoard.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    DACChannelBlockOnBoard
    : public common::detail::RantWrapper<DACChannelBlockOnBoard, uint_fast16_t, 0, 0>
    , common::CoordinateBase<DACChannelBlockOnBoard>
{
	constexpr explicit DACChannelBlockOnBoard(uintmax_t const val = 0) : rant_t(val) {}
};

} // namespace vx
} // namespace halco::hicann_dls

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::DACOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::DACChannelOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::DACChannelOnDAC)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::DACControlBlockOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::DACChannelBlockOnBoard)

} // namespace std
