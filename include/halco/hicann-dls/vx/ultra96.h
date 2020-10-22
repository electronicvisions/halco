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

} // namespace halco::hican_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::TCA9554OnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::TCA9554ConfigOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::TCA9554InputsOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::TCA9554ChannelOnBoard)

} // namespace std