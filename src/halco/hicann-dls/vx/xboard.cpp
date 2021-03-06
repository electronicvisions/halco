#include "halco/hicann-dls/vx/xboard.h"

#include "halco/hicann-dls/vx/dac.h"

namespace halco::hicann_dls::vx {

LEDOnBoard const LEDOnBoard::led_1{0};
LEDOnBoard const LEDOnBoard::led_2{1};
LEDOnBoard const LEDOnBoard::led_3{2};
LEDOnBoard const LEDOnBoard::led_4{3};
LEDOnBoard const LEDOnBoard::led_7{4};
LEDOnBoard const LEDOnBoard::led_8{5};

VDDOnBoard const VDDOnBoard::vdd25_digital{0};
VDDOnBoard const VDDOnBoard::vdd12_digital{1};
VDDOnBoard const VDDOnBoard::vdd25_analog{2};
VDDOnBoard const VDDOnBoard::vdd12_analog{3};
VDDOnBoard const VDDOnBoard::vdd12_madc{4};
VDDOnBoard const VDDOnBoard::vdd12_pll{5};

ADCSourceOnBoard const ADCSourceOnBoard::readout_chain_0{0};
ADCSourceOnBoard const ADCSourceOnBoard::readout_chain_1{1};
ADCSourceOnBoard const ADCSourceOnBoard::mux_rfu_0{2};
ADCSourceOnBoard const ADCSourceOnBoard::v_reset{3};
ADCSourceOnBoard const ADCSourceOnBoard::vdd_res_meas{4};
ADCSourceOnBoard const ADCSourceOnBoard::mux_dac_25{5};
ADCSourceOnBoard const ADCSourceOnBoard::i_ref{6};
ADCSourceOnBoard const ADCSourceOnBoard::mux_rfu_1{7};
ADCSourceOnBoard const ADCSourceOnBoard::mux_rfu_2{8};
ADCSourceOnBoard const ADCSourceOnBoard::none{9};

DACChannelOnBoard VDDOnBoard::toDACChannelOnBoard() const
{
	return DACChannelOnBoard(DACChannelOnDAC(toEnum()), DACOnBoard(1));
}

INA219OnBoard const INA219OnBoard::vdd12_digital{0};
INA219OnBoard const INA219OnBoard::vdd25_digital{1};
INA219OnBoard const INA219OnBoard::vdd12_analog{2};
INA219OnBoard const INA219OnBoard::vdd25_analog{3};
INA219OnBoard const INA219OnBoard::vdd12_madc{4};
INA219OnBoard const INA219OnBoard::vdd12_pll{5};

INA219ConfigOnBoard const INA219ConfigOnBoard::vdd12_digital{0};
INA219ConfigOnBoard const INA219ConfigOnBoard::vdd25_digital{1};
INA219ConfigOnBoard const INA219ConfigOnBoard::vdd12_analog{2};
INA219ConfigOnBoard const INA219ConfigOnBoard::vdd25_analog{3};
INA219ConfigOnBoard const INA219ConfigOnBoard::vdd12_madc{4};
INA219ConfigOnBoard const INA219ConfigOnBoard::vdd12_pll{5};

INA219StatusOnBoard const INA219StatusOnBoard::vdd12_digital{0};
INA219StatusOnBoard const INA219StatusOnBoard::vdd25_digital{1};
INA219StatusOnBoard const INA219StatusOnBoard::vdd12_analog{2};
INA219StatusOnBoard const INA219StatusOnBoard::vdd25_analog{3};
INA219StatusOnBoard const INA219StatusOnBoard::vdd12_madc{4};
INA219StatusOnBoard const INA219StatusOnBoard::vdd12_pll{5};

INA219ConfigOnBoard INA219OnBoard::toINA219ConfigOnBoard() const
{
	return INA219ConfigOnBoard(toEnum());
}

INA219StatusOnBoard INA219OnBoard::toINA219StatusOnBoard() const
{
	return INA219StatusOnBoard(toEnum());
}

INA219OnBoard INA219ConfigOnBoard::toINA219OnBoard() const
{
	return INA219OnBoard(toEnum());
}

INA219StatusOnBoard INA219ConfigOnBoard::toINA219StatusOnBoard() const
{
	return INA219StatusOnBoard(toEnum());
}

INA219OnBoard INA219StatusOnBoard::toINA219OnBoard() const
{
	return INA219OnBoard(toEnum());
}

INA219ConfigOnBoard INA219StatusOnBoard::toINA219ConfigOnBoard() const
{
	return INA219ConfigOnBoard(toEnum());
}

} // namespace halco::hicann_dls::vx
