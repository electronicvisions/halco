#pragma once
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/hicann-dls/vx/dac.h"
#include "hate/visibility.h"

namespace halco::hicann_dls {
namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/***********\
    SPI
\***********/

struct GENPYBIND(inline_base("*")) SPIShiftRegisterOnBoard
    : public common::detail::RantWrapper<SPIShiftRegisterOnBoard, uint_fast16_t, 0, 0>
{
	constexpr explicit SPIShiftRegisterOnBoard(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*")) SPIDACDataRegisterOnDAC
    : public common::detail::RantWrapper<SPIDACDataRegisterOnDAC, uint_fast16_t, 7, 0>
{
	constexpr explicit SPIDACDataRegisterOnDAC(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) SPIDACControlRegisterOnDAC
    : public common::detail::RantWrapper<SPIDACControlRegisterOnDAC, uint_fast16_t, 3, 0>
{
	constexpr explicit SPIDACControlRegisterOnDAC(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const SYMBOL_VISIBLE SPIDACControlRegisterOnDAC gain_reference;
	static const SYMBOL_VISIBLE SPIDACControlRegisterOnDAC ldac;
	static const SYMBOL_VISIBLE SPIDACControlRegisterOnDAC power_down;
	static const SYMBOL_VISIBLE SPIDACControlRegisterOnDAC reset;
};


struct GENPYBIND(inline_base("*DACMixin*")) SPIDACDataRegisterOnBoard
    : public DACMixin<SPIDACDataRegisterOnBoard, SPIDACDataRegisterOnDAC>
{
	SPIDACDataRegisterOnBoard() = default;

	explicit SPIDACDataRegisterOnBoard(
	    SPIDACDataRegisterOnDAC const& channel, DACOnBoard const& dac = DACOnBoard()) :
	    mixin_t(channel, dac)
	{}

	explicit SPIDACDataRegisterOnBoard(enum_type const& e) : mixin_t(e) {}

	SPIDACDataRegisterOnDAC toSPIDACDataRegisterOnDAC() const { return This(); }
};


struct GENPYBIND(inline_base("*DACMixin*")) SPIDACControlRegisterOnBoard
    : public DACMixin<SPIDACControlRegisterOnBoard, SPIDACControlRegisterOnDAC>
{
	SPIDACControlRegisterOnBoard() = default;

	explicit SPIDACControlRegisterOnBoard(
	    SPIDACControlRegisterOnDAC const& channel, DACOnBoard const& dac = DACOnBoard()) :
	    mixin_t(channel, dac)
	{}

	explicit SPIDACControlRegisterOnBoard(enum_type const& e) : mixin_t(e) {}

	SPIDACControlRegisterOnDAC toSPIDACControlRegisterOnDAC() const { return This(); }
};

} // namespace vx
} // namespace halco::hicann_dls

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SPIShiftRegisterOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SPIDACDataRegisterOnDAC)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SPIDACControlRegisterOnDAC)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SPIDACDataRegisterOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SPIDACControlRegisterOnBoard)

} // namespace std
