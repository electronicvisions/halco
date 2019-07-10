#include "halco/hicann-dls/vx/coordinates.h"

namespace halco {
namespace hicann_dls {
namespace vx {

using namespace halco::common;

PPUOnDLS const PPUOnDLS::top{0};
PPUOnDLS const PPUOnDLS::bottom{1};

CADCConfigOnDLS const CADCConfigOnDLS::top{PPUOnDLS::top};
CADCConfigOnDLS const CADCConfigOnDLS::bottom{PPUOnDLS::bottom};

PPUOnDLS CADCConfigOnDLS::toPPUOnDLS() const
{
	return PPUOnDLS(toEnum());
}

PLLClockOutputOnDLS const PLLClockOutputOnDLS::serdes_ser_send_clk{0};
PLLClockOutputOnDLS const PLLClockOutputOnDLS::phy_ref_clk{1};
PLLClockOutputOnDLS const PLLClockOutputOnDLS::ppu_clk{2};
PLLClockOutputOnDLS const PLLClockOutputOnDLS::madc_clk{3};

SPIDACControlRegisterOnDAC const SPIDACControlRegisterOnDAC::gain_reference{0};
SPIDACControlRegisterOnDAC const SPIDACControlRegisterOnDAC::ldac{1};
SPIDACControlRegisterOnDAC const SPIDACControlRegisterOnDAC::power_down{2};
SPIDACControlRegisterOnDAC const SPIDACControlRegisterOnDAC::reset{3};

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

I2CINA219RoRegisterOnINA219 const I2CINA219RoRegisterOnINA219::shunt{0};
I2CINA219RoRegisterOnINA219 const I2CINA219RoRegisterOnINA219::bus{1};
I2CINA219RoRegisterOnINA219 const I2CINA219RoRegisterOnINA219::power{2};
I2CINA219RoRegisterOnINA219 const I2CINA219RoRegisterOnINA219::current{3};

I2CINA219RwRegisterOnINA219 const I2CINA219RwRegisterOnINA219::config{0};
I2CINA219RwRegisterOnINA219 const I2CINA219RwRegisterOnINA219::calibration{1};

INA219OnBoard const INA219OnBoard::vdd12_digital{0};
INA219OnBoard const INA219OnBoard::vdd25_digital{1};
INA219OnBoard const INA219OnBoard::vdd12_analog{2};
INA219OnBoard const INA219OnBoard::vdd25_analog{3};
INA219OnBoard const INA219OnBoard::vdd12_madc{4};
INA219OnBoard const INA219OnBoard::vdd12_pll{5};

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

DACChannelOnBoard const DACChannelOnBoard::v_reset{DACChannelOnDAC(0), DACOnBoard(0)};
DACChannelOnBoard const DACChannelOnBoard::v_res_meas{DACChannelOnDAC(1), DACOnBoard(0)};
DACChannelOnBoard const DACChannelOnBoard::mux_rfu_0{DACChannelOnDAC(2), DACOnBoard(0)};
DACChannelOnBoard const DACChannelOnBoard::mux_rfu_1{DACChannelOnDAC(3), DACOnBoard(0)};
DACChannelOnBoard const DACChannelOnBoard::i_ref_board{DACChannelOnDAC(4), DACOnBoard(0)};
DACChannelOnBoard const DACChannelOnBoard::ana_readout_debug_0{DACChannelOnDAC(5), DACOnBoard(0)};
DACChannelOnBoard const DACChannelOnBoard::ana_readout_debug_1{DACChannelOnDAC(6), DACOnBoard(0)};
DACChannelOnBoard const DACChannelOnBoard::mux_dac_25{DACChannelOnDAC(7), DACOnBoard(0)};

DACChannelOnBoard const DACChannelOnBoard::vdd25_digital{DACChannelOnDAC(0), DACOnBoard(1)};
DACChannelOnBoard const DACChannelOnBoard::vdd12_digital{DACChannelOnDAC(1), DACOnBoard(1)};
DACChannelOnBoard const DACChannelOnBoard::vdd25_analog{DACChannelOnDAC(2), DACOnBoard(1)};
DACChannelOnBoard const DACChannelOnBoard::vdd12_analog{DACChannelOnDAC(3), DACOnBoard(1)};
DACChannelOnBoard const DACChannelOnBoard::vdd12_madc{DACChannelOnDAC(4), DACOnBoard(1)};
DACChannelOnBoard const DACChannelOnBoard::vdd12_pll{DACChannelOnDAC(5), DACOnBoard(1)};
DACChannelOnBoard const DACChannelOnBoard::general_purpose_0{DACChannelOnDAC(6), DACOnBoard(1)};
DACChannelOnBoard const DACChannelOnBoard::general_purpose_1{DACChannelOnDAC(7), DACOnBoard(1)};

DACChannelOnBoard VDDOnBoard::toDACChannelOnBoard() const
{
	return DACChannelOnBoard(DACChannelOnDAC(toEnum()), DACOnBoard(1));
}

VDDOnBoard DACChannelOnBoard::toVDDOnBoard() const
{
	if ((toDACOnBoard() == DACOnBoard(1)) && (toDACChannelOnDAC() <= DACChannelOnDAC(5))) {
		return VDDOnBoard(toDACChannelOnDAC().toEnum());
	}
	throw std::logic_error("DAC channel not convertible to VDDOnBoard.");
}

CapMemColumnOnCapMemBlock const CapMemColumnOnCapMemBlock::SharedCapMemColumnOnCapMemBlock{
    CapMemColumnOnCapMemBlock::max};

bool CapMemCellOnCapMemBlock::isShared() const
{
	return x().isShared();
}

CommonSynramConfigOnDLS const CommonSynramConfigOnDLS::bottom{0};
CommonSynramConfigOnDLS const CommonSynramConfigOnDLS::top{1};

} // namespace vx
} // namespace hicann_dls
} // namespace halco
