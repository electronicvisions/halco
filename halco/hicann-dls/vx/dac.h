#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct VDDOnBoard;

/*****\
  DAC
\*****/

struct GENPYBIND(inline_base("*")) DACOnBoard
    : public common::detail::RantWrapper<DACOnBoard, uint_fast16_t, 1, 0>
{
	constexpr explicit DACOnBoard(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) DACChannelOnDAC
    : public common::detail::RantWrapper<DACChannelOnDAC, uint_fast16_t, 7, 0>
{
	constexpr explicit DACChannelOnDAC(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


HALCO_COORDINATE_MIXIN(DACMixin, DACOnBoard, dac)

struct GENPYBIND(inline_base("*DACMixin*")) DACChannelOnBoard
    : public DACMixin<DACChannelOnBoard, DACChannelOnDAC>
{
	DACChannelOnBoard() = default;

	explicit DACChannelOnBoard(
	    DACChannelOnDAC const& channel, DACOnBoard const& dac = DACOnBoard()) :
	    mixin_t(channel, dac)
	{}

	explicit DACChannelOnBoard(enum_type const& e) : mixin_t(e) {}

	DACChannelOnDAC toDACChannelOnDAC() const { return This(); }

	static const DACChannelOnBoard v_reset;
	static const DACChannelOnBoard v_res_meas;
	static const DACChannelOnBoard mux_rfu_0;
	static const DACChannelOnBoard mux_rfu_1;
	static const DACChannelOnBoard i_ref_board;
	static const DACChannelOnBoard ana_readout_debug_0;
	static const DACChannelOnBoard ana_readout_debug_1;
	static const DACChannelOnBoard mux_dac_25;

	static const DACChannelOnBoard vdd25_digital;
	static const DACChannelOnBoard vdd12_digital;
	static const DACChannelOnBoard vdd25_analog;
	static const DACChannelOnBoard vdd12_analog;
	static const DACChannelOnBoard vdd12_madc;
	static const DACChannelOnBoard vdd12_pll;
	static const DACChannelOnBoard general_purpose_0;
	static const DACChannelOnBoard general_purpose_1;

	VDDOnBoard toVDDOnBoard() const;
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::DACOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::DACChannelOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::DACChannelOnDAC)

} // namespace std
