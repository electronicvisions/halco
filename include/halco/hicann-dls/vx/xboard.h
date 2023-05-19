#pragma once
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"
#include "hate/visibility.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct DACChannelOnBoard;
struct INA219ConfigOnBoard;
struct INA219StatusOnBoard;

/************\
    xBoard
\************/

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) ShiftRegisterOnBoard
    : public common::detail::RantWrapper<ShiftRegisterOnBoard, uint_fast16_t, 0, 0>
    , common::CoordinateBase<ShiftRegisterOnBoard>
{
	constexpr explicit ShiftRegisterOnBoard(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*")) ADCSourceOnBoard
    : public common::detail::RantWrapper<ADCSourceOnBoard, uint_fast16_t, 9, 0>
{
	constexpr explicit ADCSourceOnBoard(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const SYMBOL_VISIBLE ADCSourceOnBoard readout_chain_0;
	static const SYMBOL_VISIBLE ADCSourceOnBoard readout_chain_1;
	static const SYMBOL_VISIBLE ADCSourceOnBoard mux_rfu_0;
	static const SYMBOL_VISIBLE ADCSourceOnBoard v_reset;
	static const SYMBOL_VISIBLE ADCSourceOnBoard vdd_res_meas;
	static const SYMBOL_VISIBLE ADCSourceOnBoard mux_dac_25;
	static const SYMBOL_VISIBLE ADCSourceOnBoard i_ref;
	static const SYMBOL_VISIBLE ADCSourceOnBoard mux_rfu_1;
	static const SYMBOL_VISIBLE ADCSourceOnBoard mux_rfu_2;
	static const SYMBOL_VISIBLE ADCSourceOnBoard none;
};


struct GENPYBIND(inline_base("*")) LEDOnBoard
    : public common::detail::RantWrapper<LEDOnBoard, uint_fast16_t, 5, 0>
{
	constexpr explicit LEDOnBoard(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const SYMBOL_VISIBLE LEDOnBoard led_1;
	static const SYMBOL_VISIBLE LEDOnBoard led_2;
	static const SYMBOL_VISIBLE LEDOnBoard led_3;
	static const SYMBOL_VISIBLE LEDOnBoard led_4;
	static const SYMBOL_VISIBLE LEDOnBoard led_7;
	static const SYMBOL_VISIBLE LEDOnBoard led_8;
};


struct GENPYBIND(inline_base("*")) VDDOnBoard
    : public common::detail::RantWrapper<VDDOnBoard, uint_fast16_t, 5, 0>
{
	constexpr explicit VDDOnBoard(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const SYMBOL_VISIBLE VDDOnBoard vdd25_digital;
	static const SYMBOL_VISIBLE VDDOnBoard vdd12_digital;
	static const SYMBOL_VISIBLE VDDOnBoard vdd25_analog;
	static const SYMBOL_VISIBLE VDDOnBoard vdd12_analog;
	static const SYMBOL_VISIBLE VDDOnBoard vdd12_madc;
	static const SYMBOL_VISIBLE VDDOnBoard vdd12_pll;

	DACChannelOnBoard toDACChannelOnBoard() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*")) ADCOnBoard
    : public common::detail::RantWrapper<ADCOnBoard, uint_fast16_t, 0, 0>
{
	constexpr explicit ADCOnBoard(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) INA219OnBoard
    : public common::detail::RantWrapper<INA219OnBoard, uint_fast16_t, 5, 0>
    , common::CoordinateBase<INA219OnBoard>
{
	constexpr explicit INA219OnBoard(uintmax_t const val = 0) : rant_t(val) {}

	static const SYMBOL_VISIBLE INA219OnBoard vdd12_digital;
	static const SYMBOL_VISIBLE INA219OnBoard vdd25_digital;
	static const SYMBOL_VISIBLE INA219OnBoard vdd12_analog;
	static const SYMBOL_VISIBLE INA219OnBoard vdd25_analog;
	static const SYMBOL_VISIBLE INA219OnBoard vdd12_madc;
	static const SYMBOL_VISIBLE INA219OnBoard vdd12_pll;

	INA219ConfigOnBoard toINA219ConfigOnBoard() const SYMBOL_VISIBLE;
	INA219StatusOnBoard toINA219StatusOnBoard() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) INA219ConfigOnBoard
    : public common::detail::RantWrapper<INA219ConfigOnBoard, uint_fast16_t, 5, 0>
    , common::CoordinateBase<INA219ConfigOnBoard>
{
	constexpr explicit INA219ConfigOnBoard(uintmax_t const val = 0) : rant_t(val) {}

	static const SYMBOL_VISIBLE INA219ConfigOnBoard vdd12_digital;
	static const SYMBOL_VISIBLE INA219ConfigOnBoard vdd25_digital;
	static const SYMBOL_VISIBLE INA219ConfigOnBoard vdd12_analog;
	static const SYMBOL_VISIBLE INA219ConfigOnBoard vdd25_analog;
	static const SYMBOL_VISIBLE INA219ConfigOnBoard vdd12_madc;
	static const SYMBOL_VISIBLE INA219ConfigOnBoard vdd12_pll;

	INA219OnBoard toINA219OnBoard() const SYMBOL_VISIBLE;
	INA219StatusOnBoard toINA219StatusOnBoard() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) INA219StatusOnBoard
    : public common::detail::RantWrapper<INA219StatusOnBoard, uint_fast16_t, 5, 0>
    , common::CoordinateBase<INA219StatusOnBoard>
{
	constexpr explicit INA219StatusOnBoard(uintmax_t const val = 0) : rant_t(val) {}

	static const SYMBOL_VISIBLE INA219StatusOnBoard vdd12_digital;
	static const SYMBOL_VISIBLE INA219StatusOnBoard vdd25_digital;
	static const SYMBOL_VISIBLE INA219StatusOnBoard vdd12_analog;
	static const SYMBOL_VISIBLE INA219StatusOnBoard vdd25_analog;
	static const SYMBOL_VISIBLE INA219StatusOnBoard vdd12_madc;
	static const SYMBOL_VISIBLE INA219StatusOnBoard vdd12_pll;

	INA219OnBoard toINA219OnBoard() const SYMBOL_VISIBLE;
	INA219ConfigOnBoard toINA219ConfigOnBoard() const SYMBOL_VISIBLE;
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ShiftRegisterOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ADCSourceOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::LEDOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::VDDOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ADCOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::INA219OnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::INA219ConfigOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::INA219StatusOnBoard)

} // namespace std
