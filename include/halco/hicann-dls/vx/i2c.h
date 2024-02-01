#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"

#include "halco/hicann-dls/vx/jboa.h"
#include "halco/hicann-dls/vx/xboard.h"

#include "hate/visibility.h"

namespace halco::hicann_dls {
namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/***********\
    I2C
\***********/

struct GENPYBIND(inline_base("*")) I2CIdRegisterOnBoard
    : public common::detail::RantWrapper<I2CIdRegisterOnBoard, uint_fast16_t, 0, 0>
{
	constexpr explicit I2CIdRegisterOnBoard(uintmax_t const val = 0) : rant_t(val) {}
};


// multiplexer
struct GENPYBIND(inline_base("*")) I2CTCA9546RegisterOnBoard
    : public common::detail::RantWrapper<I2CTCA9546RegisterOnBoard, uint_fast16_t, 0, 0>
{
	constexpr explicit I2CTCA9546RegisterOnBoard(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*")) I2CTempRegisterOnBoard
    : public common::detail::RantWrapper<I2CTempRegisterOnBoard, uint_fast16_t, 0, 0>
{
	constexpr explicit I2CTempRegisterOnBoard(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*")) I2CINA219RoRegisterOnINA219
    : public common::detail::RantWrapper<I2CINA219RoRegisterOnINA219, uint_fast16_t, 3, 0>
{
	constexpr explicit I2CINA219RoRegisterOnINA219(uintmax_t const val = 0) : rant_t(val) {}

	static const SYMBOL_VISIBLE I2CINA219RoRegisterOnINA219 shunt;
	static const SYMBOL_VISIBLE I2CINA219RoRegisterOnINA219 bus;
	static const SYMBOL_VISIBLE I2CINA219RoRegisterOnINA219 power;
	static const SYMBOL_VISIBLE I2CINA219RoRegisterOnINA219 current;
};


struct GENPYBIND(inline_base("*")) I2CINA219RwRegisterOnINA219
    : public common::detail::RantWrapper<I2CINA219RwRegisterOnINA219, uint_fast16_t, 1, 0>
{
	constexpr explicit I2CINA219RwRegisterOnINA219(uintmax_t const val = 0) : rant_t(val) {}

	static const SYMBOL_VISIBLE I2CINA219RwRegisterOnINA219 config;
	static const SYMBOL_VISIBLE I2CINA219RwRegisterOnINA219 calibration;
};


HALCO_COORDINATE_MIXIN(INA219Mixin, INA219OnBoard, ina219)

struct GENPYBIND(inline_base("*INA219Mixin*")) I2CINA219RoRegisterOnBoard
    : public INA219Mixin<I2CINA219RoRegisterOnBoard, I2CINA219RoRegisterOnINA219>
{
	I2CINA219RoRegisterOnBoard() = default;

	explicit I2CINA219RoRegisterOnBoard(
	    I2CINA219RoRegisterOnINA219 const& reg, INA219OnBoard const& ina = INA219OnBoard()) :
	    mixin_t(reg, ina)
	{}

	explicit I2CINA219RoRegisterOnBoard(enum_type const& e) : mixin_t(e) {}

	I2CINA219RoRegisterOnINA219 toI2CINA219RoRegisterOnINA219() const
	{
		return This();
	}
};


struct GENPYBIND(inline_base("*INA219Mixin*")) I2CINA219RwRegisterOnBoard
    : public INA219Mixin<I2CINA219RwRegisterOnBoard, I2CINA219RwRegisterOnINA219>
{
	I2CINA219RwRegisterOnBoard() = default;

	explicit I2CINA219RwRegisterOnBoard(
	    I2CINA219RwRegisterOnINA219 const& reg, INA219OnBoard const& ina = INA219OnBoard()) :
	    mixin_t(reg, ina)
	{}

	explicit I2CINA219RwRegisterOnBoard(enum_type const& e) : mixin_t(e) {}

	I2CINA219RwRegisterOnINA219 toI2CINA219RwRegisterOnINA219() const
	{
		return This();
	}
};


struct GENPYBIND(inline_base("*")) I2CTCA9554RwRegisterOnTCA9554
    : public common::detail::RantWrapper<I2CTCA9554RwRegisterOnTCA9554, uint_fast16_t, 2, 0>
{
	constexpr explicit I2CTCA9554RwRegisterOnTCA9554(uintmax_t const val = 0) : rant_t(val) {}

	static const SYMBOL_VISIBLE I2CTCA9554RwRegisterOnTCA9554 outputs;
	static const SYMBOL_VISIBLE I2CTCA9554RwRegisterOnTCA9554 polarity;
	static const SYMBOL_VISIBLE I2CTCA9554RwRegisterOnTCA9554 config;
};


struct GENPYBIND(inline_base("*")) I2CTCA9554RoRegisterOnTCA9554
    : public common::detail::RantWrapper<I2CTCA9554RoRegisterOnTCA9554, uint_fast16_t, 0, 0>
{
	constexpr explicit I2CTCA9554RoRegisterOnTCA9554(uintmax_t const val = 0) : rant_t(val) {}

	static const SYMBOL_VISIBLE I2CTCA9554RoRegisterOnTCA9554 inputs;
};


HALCO_COORDINATE_MIXIN(TCA9554Mixin, TCA9554OnBoard, tca9554)

struct GENPYBIND(inline_base("*TCA9554Mixin*")) I2CTCA9554RoRegisterOnBoard
    : public TCA9554Mixin<I2CTCA9554RoRegisterOnBoard, I2CTCA9554RoRegisterOnTCA9554>
{
	I2CTCA9554RoRegisterOnBoard() = default;

	explicit I2CTCA9554RoRegisterOnBoard(
	    I2CTCA9554RoRegisterOnTCA9554 const& reg, TCA9554OnBoard const& tca = TCA9554OnBoard()) :
	    mixin_t(reg, tca)
	{}

	explicit I2CTCA9554RoRegisterOnBoard(enum_type const& e) : mixin_t(e) {}

	I2CTCA9554RoRegisterOnTCA9554 toI2CTCA9554RoRegisterOnTCA9554() const
	{
		return This();
	}
};


struct GENPYBIND(inline_base("*TCA9554Mixin*")) I2CTCA9554RwRegisterOnBoard
    : public TCA9554Mixin<I2CTCA9554RwRegisterOnBoard, I2CTCA9554RwRegisterOnTCA9554>
{
	I2CTCA9554RwRegisterOnBoard() = default;

	explicit I2CTCA9554RwRegisterOnBoard(
	    I2CTCA9554RwRegisterOnTCA9554 const& reg, TCA9554OnBoard const& tca = TCA9554OnBoard()) :
	    mixin_t(reg, tca)
	{}

	explicit I2CTCA9554RwRegisterOnBoard(enum_type const& e) : mixin_t(e) {}

	I2CTCA9554RwRegisterOnTCA9554 toI2CTCA9554RwRegisterOnTCA9554() const
	{
		return This();
	}
};


struct GENPYBIND(inline_base("*")) I2CAD5252RwRegisterOnAD5252Channel
    : public common::detail::RantWrapper<I2CAD5252RwRegisterOnAD5252Channel, uint_fast16_t, 1, 0>
{
	constexpr explicit I2CAD5252RwRegisterOnAD5252Channel(uintmax_t const val = 0) : rant_t(val) {}

	static const SYMBOL_VISIBLE I2CAD5252RwRegisterOnAD5252Channel rdac_volatile;
	static const SYMBOL_VISIBLE I2CAD5252RwRegisterOnAD5252Channel eemem_persistent;

	// Command byte prefixes for the register types
	static constexpr uint8_t rdac_volatile_prefix = 0x00;
	static constexpr uint8_t eemem_persistent_prefix = 0x20;
};


HALCO_COORDINATE_MIXIN(AD5252ChannelMixin, AD5252ChannelOnBoard, ad5252channel)

struct GENPYBIND(inline_base("*AD5252ChannelMixin*")) I2CAD5252RwRegisterOnBoard
    : public AD5252ChannelMixin<I2CAD5252RwRegisterOnBoard, I2CAD5252RwRegisterOnAD5252Channel>
{
	I2CAD5252RwRegisterOnBoard() = default;

	explicit I2CAD5252RwRegisterOnBoard(
	    I2CAD5252RwRegisterOnAD5252Channel const& reg,
	    AD5252ChannelOnBoard const& ad = AD5252ChannelOnBoard()) :
	    mixin_t(reg, ad)
	{}

	explicit I2CAD5252RwRegisterOnBoard(enum_type const& e) : mixin_t(e) {}

	I2CAD5252RwRegisterOnAD5252Channel toI2CAD5252RwRegisterOnAD5252Channel() const
	{
		return This();
	}
	AD5252ChannelOnAD5252 toAD5252ChannelOnAD5252() const
	{
		return toAD5252ChannelOnBoard().toAD5252ChannelOnAD5252();
	};
};


struct GENPYBIND(inline_base("*DAC6573Mixin*")) I2CDAC6573RwRegisterOnBoard
    : public DAC6573Mixin<I2CDAC6573RwRegisterOnBoard, DAC6573ChannelOnDAC6573>
{
	I2CDAC6573RwRegisterOnBoard() = default;

	explicit I2CDAC6573RwRegisterOnBoard(
	    DAC6573ChannelOnDAC6573 const& ch, DAC6573OnBoard const& dac = DAC6573OnBoard()) :
	    mixin_t(ch, dac)
	{}

	explicit I2CDAC6573RwRegisterOnBoard(enum_type const& e) : mixin_t(e) {}

	DAC6573ChannelOnDAC6573 toDAC6573ChannelOnDAC6573() const
	{
		return This();
	}

	// MSBs of the command byte signaling immediate update of the DAC in write mode
	static constexpr uint8_t register_base_addr = 0x10;
};

} // namespace vx
} // namespace halco::hicann_dls

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CIdRegisterOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CTCA9546RegisterOnBoard)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CTempRegisterOnBoard)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CINA219RoRegisterOnINA219)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CINA219RwRegisterOnINA219)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CINA219RoRegisterOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CINA219RwRegisterOnBoard)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CTCA9554RoRegisterOnTCA9554)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CTCA9554RwRegisterOnTCA9554)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CTCA9554RoRegisterOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CTCA9554RwRegisterOnBoard)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CAD5252RwRegisterOnAD5252Channel)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CAD5252RwRegisterOnBoard)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CDAC6573RwRegisterOnBoard)

} // namespace std
