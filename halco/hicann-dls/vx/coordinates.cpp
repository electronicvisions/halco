#include "halco/hicann-dls/vx/coordinates.h"

#include "halco/common/lookup_tables_helper.h"

namespace halco {
namespace hicann_dls {
namespace vx {

using namespace halco::common;

CrossbarInputOnDLS BackgroundSpikeSourceOnDLS::toCrossbarInputOnDLS() const
{
	// FIXME: Get constant from l2 and neuron input sizes once they exist
	return CrossbarInputOnDLS(toEnum() + 12);
}

CrossbarL2OutputOnDLS BackgroundSpikeSourceOnDLS::toCrossbarL2OutputOnDLS() const
{
	return CrossbarL2OutputOnDLS(toEnum() % CrossbarL2OutputOnDLS::size);
}

CrossbarOutputOnDLS CrossbarL2OutputOnDLS::toCrossbarOutputOnDLS() const
{
	return CrossbarOutputOnDLS(
	    toEnum() + (CrossbarOutputOnDLS::size - CrossbarL2OutputOnDLS::size));
}

// clang-format off
std::array<std::pair<int, int>, CrossbarNodeOnDLS::size> const CrossbarNodeOnDLSGrid = {
    {{ 0,  0},                               { 4,  0},                               { 8,  0},
               { 1,  1},                               { 5,  1},                               { 9,  1},
                         { 2,  2},                               { 6,  2},                               {10,  2},
                                   { 3,  3},                               { 7,  3},                               {11,  3},

     { 0,  4},                               { 4,  4},                               { 8,  4},
               { 1,  5},                               { 5,  5},                               { 9,  5},
                         { 2,  6},                               { 6,  6},                               {10,  6},
                                   { 3,  7},                               { 7,  7},                               {11,  7},
     { 0,  8}, { 1,  8}, { 2,  8}, { 3,  8}, { 4,  8}, { 5,  8}, { 6,  8}, { 7,  8}, { 8,  8},
     { 0,  9}, { 1,  9}, { 2,  9}, { 3,  9}, { 4,  9}, { 5,  9}, { 6,  9}, { 7,  9},           { 9,  9},
     { 0, 10}, { 1, 10}, { 2, 10}, { 3, 10}, { 4, 10}, { 5, 10}, { 6, 10}, { 7, 10},                     {10, 10},
     { 0, 11}, { 1, 11}, { 2, 11}, { 3, 11}, { 4, 11}, { 5, 11}, { 6, 11}, { 7, 11},                               {11, 11},
     { 0, 12},                                                                       { 8, 12},
               { 1, 13},                                                                       { 9, 13},
                         { 2, 14},                                                                       {10, 14},
                                   { 3, 15},                                                                       {11, 15},
                                             { 4, 16},                               { 8, 16},
                                                       { 5, 17},                               { 9, 17},
                                                                 { 6, 18},                               {10, 18},
                                                                           { 7, 19},                               {11, 19}
}};
// clang-format on

auto const CrossbarNodeOnDLSEnum = halco::common::detail::
    generateEnum<CrossbarOutputOnDLS::size, CrossbarInputOnDLS::size, CrossbarNodeOnDLS::size>(
        CrossbarNodeOnDLSGrid);

CrossbarNodeOnDLS::x_type CrossbarNodeOnDLS::to_x(enum_type const& e)
{
	return x_type(CrossbarNodeOnDLSGrid.at(e).first);
}

CrossbarNodeOnDLS::y_type CrossbarNodeOnDLS::to_y(enum_type const& e)
{
	return y_type(CrossbarNodeOnDLSGrid.at(e).second);
}

CrossbarNodeOnDLS::enum_type CrossbarNodeOnDLS::to_enum(x_type const& x, y_type const& y)
{
	// throws out_of_range if x or y is not available on wafer.
	int const en = CrossbarNodeOnDLSEnum.at(x).at(y);
	if (en == halco::common::detail::invalid)
		throw std::domain_error("Invalid combination of X and Y for a CrossbarNode");
	return enum_type(en);
}

PPUOnDLS const PPUOnDLS::top{0};
PPUOnDLS const PPUOnDLS::bottom{1};

PPUMemoryBlockOnPPU const PPUMemoryBlockOnPPU::mailbox(
    PPUMemoryWordOnPPU(3072), PPUMemoryWordOnPPU(4095));

PPUMemoryWordOnPPU const PPUMemoryWordOnPPU::return_code(3071);

CADCConfigOnDLS const CADCConfigOnDLS::top{PPUOnDLS::top.toEnum()};
CADCConfigOnDLS const CADCConfigOnDLS::bottom{PPUOnDLS::bottom.toEnum()};

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

SynramOnDLS CommonSynramConfigOnDLS::toSynramOnDLS() const
{
	return SynramOnDLS(toEnum());
}

CommonSynapseDriverConfigOnDLS SynapseDriverBlockOnDLS::toCommonSynapseDriverConfigOnDLS() const
{
	return CommonSynapseDriverConfigOnDLS(toEnum());
}

CommonSynramConfigOnDLS const CommonSynramConfigOnDLS::top{PPUOnDLS::top.toEnum()};
CommonSynramConfigOnDLS const CommonSynramConfigOnDLS::bottom{PPUOnDLS::bottom.toEnum()};

SynramOnDLS const SynramOnDLS::top{PPUOnDLS::top.toEnum()};
SynramOnDLS const SynramOnDLS::bottom{PPUOnDLS::bottom.toEnum()};

SynapseDriverBlockOnDLS const SynapseDriverBlockOnDLS::top{PPUOnDLS::top.toEnum()};
SynapseDriverBlockOnDLS const SynapseDriverBlockOnDLS::bottom{PPUOnDLS::bottom.toEnum()};

CommonSynapseDriverConfigOnDLS const CommonSynapseDriverConfigOnDLS::top{PPUOnDLS::top.toEnum()};
CommonSynapseDriverConfigOnDLS const CommonSynapseDriverConfigOnDLS::bottom{
    PPUOnDLS::bottom.toEnum()};

PADIBusBlockOnDLS const PADIBusBlockOnDLS::bottom{PPUOnDLS::bottom.toEnum()};
PADIBusBlockOnDLS const PADIBusBlockOnDLS::top{PPUOnDLS::top.toEnum()};

PADIEventOnDLS const PADIEventOnDLS::bottom{PPUOnDLS::bottom.toEnum()};
PADIEventOnDLS const PADIEventOnDLS::top{PPUOnDLS::top.toEnum()};

CommonPADIBusConfigOnDLS const CommonPADIBusConfigOnDLS::bottom{PPUOnDLS::bottom.toEnum()};
CommonPADIBusConfigOnDLS const CommonPADIBusConfigOnDLS::top{PPUOnDLS::top.toEnum()};

CommonSTPConfigOnDLS const CommonSTPConfigOnDLS::bottom{PPUOnDLS::bottom.toEnum()};
CommonSTPConfigOnDLS const CommonSTPConfigOnDLS::top{PPUOnDLS::top.toEnum()};

SynramOnDLS PADIBusBlockOnDLS::toSynramOnDLS() const
{
	return SynramOnDLS(toEnum());
}

PADIEventOnDLS PADIBusBlockOnDLS::toPADIEventOnDLS() const
{
	return PADIEventOnDLS(toEnum());
}

CommonPADIBusConfigOnDLS PADIBusBlockOnDLS::toCommonPADIBusConfigOnDLS() const
{
	return CommonPADIBusConfigOnDLS(toEnum());
}

CommonSTPConfigOnDLS PADIBusBlockOnDLS::toCommonSTPConfigOnDLS() const
{
	return CommonSTPConfigOnDLS(toEnum());
}

CADCChannelType const CADCChannelType::causal{0};
CADCChannelType const CADCChannelType::acausal{1};

CADCReadoutType const CADCReadoutType::trigger_read{0};
CADCReadoutType const CADCReadoutType::buffered{1};

CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::v_leak{0};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::v_syn_exc{1};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::v_syn_inh{3};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::v_leak_adapt{5};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::v_threshold{6};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::v_reset{7};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_leak{8};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_reset{9};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_syn_exc_res{10};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_syn_exc_gm{11};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_syn_inh_res{12};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_syn_inh_gm{13};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_adapt_sd{14};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_adapt_res{15};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_adapt_w{16};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_source_follower{18};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_offset{19};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_readout{20};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_adapt{21};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_adapt_amp{22};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_nmda{23};

} // namespace vx
} // namespace hicann_dls
} // namespace halco
