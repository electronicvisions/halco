#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"

#include "halco/hicann-dls/vx/xboard.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/***********\
    I2C
\***********/

struct GENPYBIND(inline_base("*")) I2CIdRegisterOnBoard
    : public common::detail::RantWrapper<I2CIdRegisterOnBoard, uint_fast16_t, 0, 0>
{
	constexpr explicit I2CIdRegisterOnBoard(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*")) I2CINA219RoRegisterOnINA219
    : public common::detail::RantWrapper<I2CINA219RoRegisterOnINA219, uint_fast16_t, 3, 0>
{
	constexpr explicit I2CINA219RoRegisterOnINA219(uintmax_t const val = 0) : rant_t(val) {}

	static const I2CINA219RoRegisterOnINA219 shunt;
	static const I2CINA219RoRegisterOnINA219 bus;
	static const I2CINA219RoRegisterOnINA219 power;
	static const I2CINA219RoRegisterOnINA219 current;
};


struct GENPYBIND(inline_base("*")) I2CINA219RwRegisterOnINA219
    : public common::detail::RantWrapper<I2CINA219RwRegisterOnINA219, uint_fast16_t, 1, 0>
{
	constexpr explicit I2CINA219RwRegisterOnINA219(uintmax_t const val = 0) : rant_t(val) {}

	static const I2CINA219RwRegisterOnINA219 config;
	static const I2CINA219RwRegisterOnINA219 calibration;
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

	I2CINA219RoRegisterOnINA219 toI2CINA219RoRegisterOnINA219() const { return This(); }
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

	I2CINA219RwRegisterOnINA219 toI2CINA219RwRegisterOnINA219() const { return This(); }
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CIdRegisterOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CINA219RoRegisterOnINA219)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CINA219RwRegisterOnINA219)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CINA219RoRegisterOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CINA219RwRegisterOnBoard)

} // namespace std
