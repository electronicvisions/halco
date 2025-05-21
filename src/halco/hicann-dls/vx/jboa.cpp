#include "halco/hicann-dls/vx/jboa.h"

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

AD5252OnBoard const AD5252OnBoard::vdd_25digital_12digital{0};
AD5252OnBoard const AD5252OnBoard::vdd_12pll_12madc{1};
AD5252OnBoard const AD5252OnBoard::vdd_12analog_25analog{2};

AD5252ChannelOnAD5252 const AD5252ChannelOnAD5252::channel_1{0};
AD5252ChannelOnAD5252 const AD5252ChannelOnAD5252::channel_3{1};

AD5252ChannelOnBoard const AD5252ChannelOnBoard::vdd_25digital{
    AD5252ChannelOnAD5252::channel_1, AD5252OnBoard::vdd_25digital_12digital};
AD5252ChannelOnBoard const AD5252ChannelOnBoard::vdd_12digital{
    AD5252ChannelOnAD5252::channel_3, AD5252OnBoard::vdd_25digital_12digital};
AD5252ChannelOnBoard const AD5252ChannelOnBoard::vdd_12pll{
    AD5252ChannelOnAD5252::channel_1, AD5252OnBoard::vdd_12pll_12madc};
AD5252ChannelOnBoard const AD5252ChannelOnBoard::vdd_12madc{
    AD5252ChannelOnAD5252::channel_3, AD5252OnBoard::vdd_12pll_12madc};
AD5252ChannelOnBoard const AD5252ChannelOnBoard::vdd_12analog{
    AD5252ChannelOnAD5252::channel_1, AD5252OnBoard::vdd_12analog_25analog};
AD5252ChannelOnBoard const AD5252ChannelOnBoard::vdd_25analog{
    AD5252ChannelOnAD5252::channel_3, AD5252OnBoard::vdd_12analog_25analog};
AD5252ChannelConfigOnBoard AD5252ChannelOnBoard::toAD5252ChannelConfigOnBoard() const
{
	return AD5252ChannelConfigOnBoard(toEnum());
}
AD5252ChannelConfigPersistentOnBoard AD5252ChannelOnBoard::toAD5252ChannelConfigPersistentOnBoard()
    const
{
	return AD5252ChannelConfigPersistentOnBoard(toEnum());
}
AD5252OnBoard AD5252ChannelOnBoard::toAD5252OnBoard() const
{
	return AD5252OnBoard(toEnum() / 2);
}


AD5252ChannelConfigOnBoard const AD5252ChannelConfigOnBoard::vdd_25digital{
    AD5252ChannelOnAD5252::channel_1, AD5252OnBoard::vdd_25digital_12digital};
AD5252ChannelConfigOnBoard const AD5252ChannelConfigOnBoard::vdd_12digital{
    AD5252ChannelOnAD5252::channel_3, AD5252OnBoard::vdd_25digital_12digital};
AD5252ChannelConfigOnBoard const AD5252ChannelConfigOnBoard::vdd_12pll{
    AD5252ChannelOnAD5252::channel_1, AD5252OnBoard::vdd_12pll_12madc};
AD5252ChannelConfigOnBoard const AD5252ChannelConfigOnBoard::vdd_12madc{
    AD5252ChannelOnAD5252::channel_3, AD5252OnBoard::vdd_12pll_12madc};
AD5252ChannelConfigOnBoard const AD5252ChannelConfigOnBoard::vdd_12analog{
    AD5252ChannelOnAD5252::channel_1, AD5252OnBoard::vdd_12analog_25analog};
AD5252ChannelConfigOnBoard const AD5252ChannelConfigOnBoard::vdd_25analog{
    AD5252ChannelOnAD5252::channel_3, AD5252OnBoard::vdd_12analog_25analog};
AD5252ChannelOnBoard AD5252ChannelConfigOnBoard::toAD5252ChannelOnBoard() const
{
	return AD5252ChannelOnBoard(toEnum());
}
AD5252ChannelConfigPersistentOnBoard
AD5252ChannelConfigOnBoard::toAD5252ChannelConfigPersistentOnBoard() const
{
	return AD5252ChannelConfigPersistentOnBoard(toEnum());
}


AD5252ChannelConfigPersistentOnBoard const AD5252ChannelConfigPersistentOnBoard::vdd_25digital{
    AD5252ChannelOnAD5252::channel_1, AD5252OnBoard::vdd_25digital_12digital};
AD5252ChannelConfigPersistentOnBoard const AD5252ChannelConfigPersistentOnBoard::vdd_12digital{
    AD5252ChannelOnAD5252::channel_3, AD5252OnBoard::vdd_25digital_12digital};
AD5252ChannelConfigPersistentOnBoard const AD5252ChannelConfigPersistentOnBoard::vdd_12pll{
    AD5252ChannelOnAD5252::channel_1, AD5252OnBoard::vdd_12pll_12madc};
AD5252ChannelConfigPersistentOnBoard const AD5252ChannelConfigPersistentOnBoard::vdd_12madc{
    AD5252ChannelOnAD5252::channel_3, AD5252OnBoard::vdd_12pll_12madc};
AD5252ChannelConfigPersistentOnBoard const AD5252ChannelConfigPersistentOnBoard::vdd_12analog{
    AD5252ChannelOnAD5252::channel_1, AD5252OnBoard::vdd_12analog_25analog};
AD5252ChannelConfigPersistentOnBoard const AD5252ChannelConfigPersistentOnBoard::vdd_25analog{
    AD5252ChannelOnAD5252::channel_3, AD5252OnBoard::vdd_12analog_25analog};
AD5252ChannelOnBoard AD5252ChannelConfigPersistentOnBoard::toAD5252ChannelOnBoard() const
{
	return AD5252ChannelOnBoard(toEnum());
}
AD5252ChannelConfigOnBoard AD5252ChannelConfigPersistentOnBoard::toAD5252ChannelConfigOnBoard()
    const
{
	return AD5252ChannelConfigOnBoard(toEnum());
}


DAC6573ChannelOnBoard const DAC6573ChannelOnBoard::v_reset{DAC6573ChannelOnDAC6573{0}};
DAC6573ChannelOnBoard const DAC6573ChannelOnBoard::i_ref_board{DAC6573ChannelOnDAC6573{1}};
DAC6573ChannelOnBoard const DAC6573ChannelOnBoard::v_res_meas{DAC6573ChannelOnDAC6573{2}};
DAC6573ChannelOnBoard const DAC6573ChannelOnBoard::v_readout{DAC6573ChannelOnDAC6573{3}};


TCA9546OnBoard TCA9546ChannelOnBoard::toTCA9546OnBoard() const
{
	// There are a 4 channels on one TCA9546 (multiplexer)
	return TCA9546OnBoard(toEnum() / 4);
}
} // namespace halco::hicann_dls::vx
