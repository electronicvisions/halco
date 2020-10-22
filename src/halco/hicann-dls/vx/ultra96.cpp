#include "halco/hicann-dls/vx/ultra96.h"

namespace halco::hicann_dls::vx {

TCA9554ChannelOnBoard const TCA9554ChannelOnBoard::vdd25_digital{0};
TCA9554ChannelOnBoard const TCA9554ChannelOnBoard::vdd12_digital{1};
TCA9554ChannelOnBoard const TCA9554ChannelOnBoard::vdd12_pll{2};
TCA9554ChannelOnBoard const TCA9554ChannelOnBoard::vdd12_madc{3};
TCA9554ChannelOnBoard const TCA9554ChannelOnBoard::vdd25_analog{4};
TCA9554ChannelOnBoard const TCA9554ChannelOnBoard::vdd12_analog{5};
TCA9554ChannelOnBoard const TCA9554ChannelOnBoard::led1{6};
TCA9554ChannelOnBoard const TCA9554ChannelOnBoard::led2{7};

TCA9554OnBoard TCA9554ChannelOnBoard::toTCA9554OnBoard() const
{
	// There are a 8 channels on one TCA9554-chip
	return TCA9554OnBoard(toEnum() / 8);
}

TCA9554InputsOnBoard TCA9554OnBoard::toTCA9554InputsOnBoard() const
{
	return TCA9554InputsOnBoard(toEnum());
}

TCA9554ConfigOnBoard TCA9554OnBoard::toTCA9554ConfigOnBoard() const
{
	return TCA9554ConfigOnBoard(toEnum());
}

TCA9554OnBoard TCA9554InputsOnBoard::toTCA9554OnBoard() const
{
	return TCA9554OnBoard(toEnum());
}

TCA9554ConfigOnBoard TCA9554InputsOnBoard::toTCA9554ConfigOnBoard() const
{
	return TCA9554ConfigOnBoard(toEnum());
}

TCA9554OnBoard TCA9554ConfigOnBoard::toTCA9554OnBoard() const
{
	return TCA9554OnBoard(toEnum());
}

TCA9554InputsOnBoard TCA9554ConfigOnBoard::toTCA9554InputsOnBoard() const
{
	return TCA9554InputsOnBoard(toEnum());
}

} // namspace halco::hicann_dls::vx