#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {


/************\
    ultra96
\************/

struct TCA9554ChannelOnBoard;
struct TCA9554ConfigOnBoard;
struct TCA9554InputsOnBoard;

struct AD5252OnBoard;
struct AD5252ChannelOnBoard;
struct AD5252ChannelConfigOnBoard;
struct AD5252ChannelConfigPersistentOnBoard;


struct GENPYBIND(inline_base("*")) TCA9554OnBoard
    : public common::detail::RantWrapper<TCA9554OnBoard, uint_fast16_t, 0, 0>
{
	constexpr explicit TCA9554OnBoard(uintmax_t const val = 0) : rant_t(val) {}

	TCA9554ConfigOnBoard toTCA9554ConfigOnBoard() const;
	TCA9554InputsOnBoard toTCA9554InputsOnBoard() const;
};


struct GENPYBIND(inline_base("*")) TCA9554InputsOnBoard
    : public common::detail::RantWrapper<TCA9554InputsOnBoard, uint_fast16_t, 0, 0>
{
	constexpr explicit TCA9554InputsOnBoard(uintmax_t const val = 0) : rant_t(val) {}

	TCA9554OnBoard toTCA9554OnBoard() const;
	TCA9554ConfigOnBoard toTCA9554ConfigOnBoard() const;
};


struct GENPYBIND(inline_base("*")) TCA9554ConfigOnBoard
    : public common::detail::RantWrapper<TCA9554ConfigOnBoard, uint_fast16_t, 0, 0>
{
	constexpr explicit TCA9554ConfigOnBoard(uintmax_t const val = 0) : rant_t(val) {}

	TCA9554OnBoard toTCA9554OnBoard() const;
	TCA9554InputsOnBoard toTCA9554InputsOnBoard() const;
};


struct GENPYBIND(inline_base("*")) TCA9554ChannelOnBoard
    : public common::detail::RantWrapper<TCA9554ChannelOnBoard, uint_fast16_t, 7, 0>
{
	constexpr explicit TCA9554ChannelOnBoard(uintmax_t const val = 0) : rant_t(val) {}

	static const TCA9554ChannelOnBoard vdd25_digital;
	static const TCA9554ChannelOnBoard vdd12_digital;
	static const TCA9554ChannelOnBoard vdd12_pll;
	static const TCA9554ChannelOnBoard vdd12_madc;
	static const TCA9554ChannelOnBoard vdd25_analog;
	static const TCA9554ChannelOnBoard vdd12_analog;

	static const TCA9554ChannelOnBoard led1;
	static const TCA9554ChannelOnBoard led2;

	TCA9554OnBoard toTCA9554OnBoard() const;
};


struct GENPYBIND(inline_base("*")) AD5252OnBoard
    : public common::detail::RantWrapper<AD5252OnBoard, uint_fast16_t, 2, 0>
{
	constexpr explicit AD5252OnBoard() : rant_t(0) {}
	constexpr explicit AD5252OnBoard(uintmax_t const val) : rant_t(val) {}

	static const AD5252OnBoard vdd_12pll_12madc;
	static const AD5252OnBoard vdd_12analog_25analog;
	static const AD5252OnBoard vdd_25digital_12digital;
};

struct GENPYBIND(inline_base("*")) AD5252ChannelOnAD5252
    : public common::detail::RantWrapper<AD5252ChannelOnAD5252, uint_fast16_t, 1, 0>
{
	constexpr explicit AD5252ChannelOnAD5252(uintmax_t const val = 0) : rant_t(val) {}

	// The variant we are using only has two channels (at indices 1, 3)
	static const AD5252ChannelOnAD5252 channel_1;
	static const AD5252ChannelOnAD5252 channel_3;
};

HALCO_COORDINATE_MIXIN(AD5252Mixin, AD5252OnBoard, ad5252)

struct GENPYBIND(inline_base("*AD5252Mixin*")) AD5252ChannelOnBoard
    : public AD5252Mixin<AD5252ChannelOnBoard, AD5252ChannelOnAD5252>
{
	AD5252ChannelOnBoard() = default;

	explicit AD5252ChannelOnBoard(
	    AD5252ChannelOnAD5252 const& reg, AD5252OnBoard const& ad = AD5252OnBoard()) :
	    mixin_t(reg, ad)
	{}

	explicit AD5252ChannelOnBoard(enum_type const& e) : mixin_t(e) {}

	static const AD5252ChannelOnBoard vdd_12pll;
	static const AD5252ChannelOnBoard vdd_12madc;
	static const AD5252ChannelOnBoard vdd_12analog;
	static const AD5252ChannelOnBoard vdd_25analog;
	static const AD5252ChannelOnBoard vdd_25digital;
	static const AD5252ChannelOnBoard vdd_12digital;

	AD5252ChannelOnAD5252 toAD5252ChannelOnAD5252() const
	{
		return This();
	}
	AD5252ChannelConfigOnBoard toAD5252ChannelConfigOnBoard() const;
	AD5252ChannelConfigPersistentOnBoard toAD5252ChannelConfigPersistentOnBoard() const;
};

struct GENPYBIND(inline_base("*AD5252Mixin*")) AD5252ChannelConfigOnBoard
    : public AD5252Mixin<AD5252ChannelConfigOnBoard, AD5252ChannelOnAD5252>
{
	AD5252ChannelConfigOnBoard() = default;

	explicit AD5252ChannelConfigOnBoard(
	    AD5252ChannelOnAD5252 const& reg, AD5252OnBoard const& ad = AD5252OnBoard()) :
	    mixin_t(reg, ad)
	{}

	explicit AD5252ChannelConfigOnBoard(enum_type const& e) : mixin_t(e) {}

	static const AD5252ChannelConfigOnBoard vdd_12pll;
	static const AD5252ChannelConfigOnBoard vdd_12madc;
	static const AD5252ChannelConfigOnBoard vdd_12analog;
	static const AD5252ChannelConfigOnBoard vdd_25analog;
	static const AD5252ChannelConfigOnBoard vdd_25digital;
	static const AD5252ChannelConfigOnBoard vdd_12digital;

	AD5252ChannelOnAD5252 toAD5252ChannelOnAD5252() const
	{
		return This();
	}
	AD5252ChannelOnBoard toAD5252ChannelOnBoard() const;
	AD5252ChannelConfigPersistentOnBoard toAD5252ChannelConfigPersistentOnBoard() const;
};

struct GENPYBIND(inline_base("*AD5252Mixin*")) AD5252ChannelConfigPersistentOnBoard
    : public AD5252Mixin<AD5252ChannelConfigPersistentOnBoard, AD5252ChannelOnAD5252>
{
	AD5252ChannelConfigPersistentOnBoard() = default;

	explicit AD5252ChannelConfigPersistentOnBoard(
	    AD5252ChannelOnAD5252 const& reg, AD5252OnBoard const& ad = AD5252OnBoard()) :
	    mixin_t(reg, ad)
	{}

	explicit AD5252ChannelConfigPersistentOnBoard(enum_type const& e) : mixin_t(e) {}

	static const AD5252ChannelConfigPersistentOnBoard vdd_12pll;
	static const AD5252ChannelConfigPersistentOnBoard vdd_12madc;
	static const AD5252ChannelConfigPersistentOnBoard vdd_12analog;
	static const AD5252ChannelConfigPersistentOnBoard vdd_25analog;
	static const AD5252ChannelConfigPersistentOnBoard vdd_25digital;
	static const AD5252ChannelConfigPersistentOnBoard vdd_12digital;

	AD5252ChannelOnAD5252 toAD5252ChannelOnAD5252() const
	{
		return This();
	}
	AD5252ChannelOnBoard toAD5252ChannelOnBoard() const;
	AD5252ChannelConfigOnBoard toAD5252ChannelConfigOnBoard() const;
};


} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::TCA9554OnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::TCA9554ConfigOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::TCA9554InputsOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::TCA9554ChannelOnBoard)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::AD5252OnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::AD5252ChannelOnAD5252)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::AD5252ChannelOnBoard)

}
