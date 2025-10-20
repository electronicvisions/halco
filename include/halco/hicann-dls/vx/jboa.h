#pragma once
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"
#include "hate/visibility.h"

namespace halco::hicann_dls {
namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {


/************\
    jboa
\************/

struct TCA9554ChannelOnBoard;
struct TCA9554ConfigOnBoard;
struct TCA9554InputsOnBoard;

struct AD5252OnBoard;
struct AD5252ChannelOnAD5252;
struct AD5252ChannelOnBoard;
struct AD5252ChannelConfigOnBoard;
struct AD5252ChannelConfigPersistentOnBoard;

struct DAC6573OnBoard;
struct DAC6573ChannelOnDAC6573;
struct DAC6573ChannelOnBoard;

struct TCA9546OnBoard;
struct TCA9546ChannelOnBoard;

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) TCA9554OnBoard
    : public common::detail::RantWrapper<TCA9554OnBoard, uint_fast16_t, 0, 0>
    , common::CoordinateBase<TCA9554OnBoard>
{
	constexpr explicit TCA9554OnBoard(uintmax_t const val = 0) : rant_t(val) {}

	TCA9554ConfigOnBoard toTCA9554ConfigOnBoard() const SYMBOL_VISIBLE;
	TCA9554InputsOnBoard toTCA9554InputsOnBoard() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) TCA9554InputsOnBoard
    : public common::detail::RantWrapper<TCA9554InputsOnBoard, uint_fast16_t, 0, 0>
    , common::CoordinateBase<TCA9554InputsOnBoard>
{
	constexpr explicit TCA9554InputsOnBoard(uintmax_t const val = 0) : rant_t(val) {}

	TCA9554OnBoard toTCA9554OnBoard() const SYMBOL_VISIBLE;
	TCA9554ConfigOnBoard toTCA9554ConfigOnBoard() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) TCA9554ConfigOnBoard
    : public common::detail::RantWrapper<TCA9554ConfigOnBoard, uint_fast16_t, 0, 0>
    , common::CoordinateBase<TCA9554ConfigOnBoard>
{
	constexpr explicit TCA9554ConfigOnBoard(uintmax_t const val = 0) : rant_t(val) {}

	TCA9554OnBoard toTCA9554OnBoard() const SYMBOL_VISIBLE;
	TCA9554InputsOnBoard toTCA9554InputsOnBoard() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    TCA9554ChannelOnBoard
    : public common::detail::RantWrapper<TCA9554ChannelOnBoard, uint_fast16_t, 7, 0>
    , common::CoordinateBase<TCA9554ChannelOnBoard>
{
	constexpr explicit TCA9554ChannelOnBoard(uintmax_t const val = 0) : rant_t(val) {}

	static const SYMBOL_VISIBLE TCA9554ChannelOnBoard disable_vdd25_digital;
	static const SYMBOL_VISIBLE TCA9554ChannelOnBoard disable_vdd12_digital;
	static const SYMBOL_VISIBLE TCA9554ChannelOnBoard disable_vdd12_pll;
	static const SYMBOL_VISIBLE TCA9554ChannelOnBoard disable_vdd12_madc;
	static const SYMBOL_VISIBLE TCA9554ChannelOnBoard disable_vdd25_analog;
	static const SYMBOL_VISIBLE TCA9554ChannelOnBoard disable_vdd12_analog;

	static const SYMBOL_VISIBLE TCA9554ChannelOnBoard disable_led;
	static const SYMBOL_VISIBLE TCA9554ChannelOnBoard disable_power;

	TCA9554OnBoard toTCA9554OnBoard() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) AD5252OnBoard
    : public common::detail::RantWrapper<AD5252OnBoard, uint_fast16_t, 2, 0>
    , common::CoordinateBase<AD5252OnBoard>
{
	constexpr explicit AD5252OnBoard() : rant_t(0) {}
	constexpr explicit AD5252OnBoard(uintmax_t const val) : rant_t(val) {}

	static const SYMBOL_VISIBLE AD5252OnBoard vdd_25digital_12digital;
	static const SYMBOL_VISIBLE AD5252OnBoard vdd_12pll_12madc;
	static const SYMBOL_VISIBLE AD5252OnBoard vdd_12analog_25analog;
};

struct GENPYBIND(inline_base("*")) AD5252ChannelOnAD5252
    : public common::detail::RantWrapper<AD5252ChannelOnAD5252, uint_fast16_t, 1, 0>
{
	constexpr explicit AD5252ChannelOnAD5252(uintmax_t const val = 0) : rant_t(val) {}

	// The variant we are using only has two channels (at indices 1, 3)
	static const SYMBOL_VISIBLE AD5252ChannelOnAD5252 channel_1;
	static const SYMBOL_VISIBLE AD5252ChannelOnAD5252 channel_3;
};

HALCO_COORDINATE_MIXIN(AD5252Mixin, AD5252OnBoard, ad5252)

struct GENPYBIND(inline_base("*AD5252Mixin*"), inline_base("*CoordinateBase*")) AD5252ChannelOnBoard
    : public AD5252Mixin<AD5252ChannelOnBoard, AD5252ChannelOnAD5252>
    , common::CoordinateBase<AD5252ChannelOnBoard>
{
	AD5252ChannelOnBoard() = default;

	explicit AD5252ChannelOnBoard(
	    AD5252ChannelOnAD5252 const& reg, AD5252OnBoard const& ad = AD5252OnBoard()) :
	    mixin_t(reg, ad)
	{
	}

	explicit AD5252ChannelOnBoard(enum_type const& e) : mixin_t(e) {}

	static const SYMBOL_VISIBLE AD5252ChannelOnBoard vdd_25digital;
	static const SYMBOL_VISIBLE AD5252ChannelOnBoard vdd_12digital;
	static const SYMBOL_VISIBLE AD5252ChannelOnBoard vdd_12pll;
	static const SYMBOL_VISIBLE AD5252ChannelOnBoard vdd_12madc;
	static const SYMBOL_VISIBLE AD5252ChannelOnBoard vdd_12analog;
	static const SYMBOL_VISIBLE AD5252ChannelOnBoard vdd_25analog;

	AD5252ChannelOnAD5252 toAD5252ChannelOnAD5252() const
	{
		return This();
	}
	AD5252ChannelConfigOnBoard toAD5252ChannelConfigOnBoard() const SYMBOL_VISIBLE;
	AD5252ChannelConfigPersistentOnBoard toAD5252ChannelConfigPersistentOnBoard() const
	    SYMBOL_VISIBLE;
	AD5252OnBoard toAD5252OnBoard() const SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*AD5252Mixin*"), inline_base("*CoordinateBase*"))
    AD5252ChannelConfigOnBoard
    : public AD5252Mixin<AD5252ChannelConfigOnBoard, AD5252ChannelOnAD5252>
    , common::CoordinateBase<AD5252ChannelConfigOnBoard>
{
	AD5252ChannelConfigOnBoard() = default;

	explicit AD5252ChannelConfigOnBoard(
	    AD5252ChannelOnAD5252 const& reg, AD5252OnBoard const& ad = AD5252OnBoard()) :
	    mixin_t(reg, ad)
	{
	}

	explicit AD5252ChannelConfigOnBoard(enum_type const& e) : mixin_t(e) {}

	static const SYMBOL_VISIBLE AD5252ChannelConfigOnBoard vdd_25digital;
	static const SYMBOL_VISIBLE AD5252ChannelConfigOnBoard vdd_12digital;
	static const SYMBOL_VISIBLE AD5252ChannelConfigOnBoard vdd_12pll;
	static const SYMBOL_VISIBLE AD5252ChannelConfigOnBoard vdd_12madc;
	static const SYMBOL_VISIBLE AD5252ChannelConfigOnBoard vdd_12analog;
	static const SYMBOL_VISIBLE AD5252ChannelConfigOnBoard vdd_25analog;

	AD5252ChannelOnAD5252 toAD5252ChannelOnAD5252() const
	{
		return This();
	}
	AD5252ChannelOnBoard toAD5252ChannelOnBoard() const SYMBOL_VISIBLE;
	AD5252ChannelConfigPersistentOnBoard toAD5252ChannelConfigPersistentOnBoard() const
	    SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*AD5252Mixin*"), inline_base("*CoordinateBase*"))
    AD5252ChannelConfigPersistentOnBoard
    : public AD5252Mixin<AD5252ChannelConfigPersistentOnBoard, AD5252ChannelOnAD5252>
    , common::CoordinateBase<AD5252ChannelConfigPersistentOnBoard>
{
	AD5252ChannelConfigPersistentOnBoard() = default;

	explicit AD5252ChannelConfigPersistentOnBoard(
	    AD5252ChannelOnAD5252 const& reg, AD5252OnBoard const& ad = AD5252OnBoard()) :
	    mixin_t(reg, ad)
	{
	}

	explicit AD5252ChannelConfigPersistentOnBoard(enum_type const& e) : mixin_t(e) {}

	static const SYMBOL_VISIBLE AD5252ChannelConfigPersistentOnBoard vdd_25digital;
	static const SYMBOL_VISIBLE AD5252ChannelConfigPersistentOnBoard vdd_12digital;
	static const SYMBOL_VISIBLE AD5252ChannelConfigPersistentOnBoard vdd_12pll;
	static const SYMBOL_VISIBLE AD5252ChannelConfigPersistentOnBoard vdd_12madc;
	static const SYMBOL_VISIBLE AD5252ChannelConfigPersistentOnBoard vdd_12analog;
	static const SYMBOL_VISIBLE AD5252ChannelConfigPersistentOnBoard vdd_25analog;

	AD5252ChannelOnAD5252 toAD5252ChannelOnAD5252() const
	{
		return This();
	}
	AD5252ChannelOnBoard toAD5252ChannelOnBoard() const SYMBOL_VISIBLE;
	AD5252ChannelConfigOnBoard toAD5252ChannelConfigOnBoard() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) DAC6573OnBoard
    : public common::detail::RantWrapper<DAC6573OnBoard, uint_fast16_t, 0, 0>
    , common::CoordinateBase<DAC6573OnBoard>
{
	constexpr explicit DAC6573OnBoard() : rant_t(0) {}
	constexpr explicit DAC6573OnBoard(uintmax_t const val) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) DAC6573ChannelOnDAC6573
    : public common::detail::RantWrapper<DAC6573ChannelOnDAC6573, uint_fast16_t, 3, 0>
{
	constexpr explicit DAC6573ChannelOnDAC6573() : rant_t(0) {}
	constexpr explicit DAC6573ChannelOnDAC6573(uintmax_t const val) : rant_t(val) {}
};

HALCO_COORDINATE_MIXIN(DAC6573Mixin, DAC6573OnBoard, dac6573mixin)

struct GENPYBIND(inline_base("*DAC6573Mixin*"), inline_base("*CoordinateBase*"))
    DAC6573ChannelOnBoard
    : public DAC6573Mixin<DAC6573ChannelOnBoard, DAC6573ChannelOnDAC6573>
    , common::CoordinateBase<DAC6573ChannelOnBoard>
{
	DAC6573ChannelOnBoard() = default;

	explicit DAC6573ChannelOnBoard(
	    DAC6573ChannelOnDAC6573 const& reg, DAC6573OnBoard const& dac = DAC6573OnBoard()) :
	    mixin_t(reg, dac)
	{
	}
	explicit DAC6573ChannelOnBoard(enum_type const& e) : mixin_t(e) {}

	static const SYMBOL_VISIBLE DAC6573ChannelOnBoard v_reset;
	static const SYMBOL_VISIBLE DAC6573ChannelOnBoard i_ref_board;
	static const SYMBOL_VISIBLE DAC6573ChannelOnBoard v_res_meas;
	static const SYMBOL_VISIBLE DAC6573ChannelOnBoard v_readout;

	DAC6573ChannelOnDAC6573 toDAC6573ChannelOnDAC6573() const
	{
		return This();
	}
};


// I2C multiplexer
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) TCA9546OnBoard
    : public common::detail::RantWrapper<TCA9546OnBoard, uint_fast16_t, 0, 0>
    , common::CoordinateBase<TCA9546OnBoard>
{
	constexpr explicit TCA9546OnBoard(uintmax_t const val = 0) : rant_t(val) {}
};

// The multiplexer can communicate with other slaves using 4 channels
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    TCA9546ChannelOnBoard
    : public common::detail::RantWrapper<TCA9546ChannelOnBoard, uint_fast16_t, 3, 0>
    , common::CoordinateBase<TCA9546ChannelOnBoard>
{
	constexpr explicit TCA9546ChannelOnBoard(uintmax_t const val = 0) : rant_t(val) {}
	TCA9546OnBoard toTCA9546OnBoard() const SYMBOL_VISIBLE;
};


} // namespace vx
} // namespace halco::hicann_dls

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::TCA9554OnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::TCA9554ConfigOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::TCA9554InputsOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::TCA9554ChannelOnBoard)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::AD5252OnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::AD5252ChannelOnAD5252)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::AD5252ChannelOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::AD5252ChannelConfigOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::AD5252ChannelConfigPersistentOnBoard)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::DAC6573OnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::DAC6573ChannelOnDAC6573)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::DAC6573ChannelOnBoard)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::TCA9546OnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::TCA9546ChannelOnBoard)

} // namespace std
