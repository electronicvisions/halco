#include "halco/hicann-dls/vx/coordinates.h"

namespace halco {
namespace hicann_dls {
namespace vx {

using namespace halco::common;

CADCConfigOnDLS const CADCConfigOnDLS::top{enum_vertical_top};
CADCConfigOnDLS const CADCConfigOnDLS::bottom{enum_vertical_bottom};

PPUOnDLS CADCConfigOnDLS::toPPUOnDLS() const
{
	return PPUOnDLS(toEnum());
}

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

DACChannelOnBoard VDDOnBoard::toDACChannelOnBoard() const
{
	return DACChannelOnBoard(DACChannelOnDAC(toEnum()), DACOnBoard(1));
}

bool CapMemCellOnCapMemBlock::isShared() const
{
	return x().isShared();
}

CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::stp_v_charge_0{
    CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(0)};
CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::stp_v_charge_1{
    CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(1)};
CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::stp_v_recover_0{
    CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(2)};
CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::stp_v_recover_1{
    CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(3)};
CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::cadc_v_ramp_offset{
    CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(4)};
CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::cadc_v_bias_ramp_buf{
    CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(5)};
CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::syn_i_bias_dac{
    CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(8)};
CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::syn_i_bias_ramp{
    CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(9)};
CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::syn_i_bias_store{
    CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(10)};
CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::syn_i_bias_corout{
    CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(11)};
CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::stp_i_bias_comparator{
    CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(12)};
CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::stp_i_ramp{CapMemColumnOnCapMemBlock(128),
                                                                  CapMemRowOnCapMemBlock(13)};
CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::stp_i_calib{CapMemColumnOnCapMemBlock(128),
                                                                   CapMemRowOnCapMemBlock(14)};
CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::cadc_i_ramp_slope{
    CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(15)};
CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::cadc_i_bias_comp{
    CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(16)};
CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::cadc_i_bias_vreset_buf{
    CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(17)};
CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::neuron_i_bias_synin_sd_exc{
    CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(18)};
CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::neuron_i_bias_synin_sd_inh{
    CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(19)};
CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::neuron_i_bias_threshold_comparator{
    CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(20)};

CapMemCellOnDLS const CapMemCellOnDLS::readout_sc_amp_v_ref{
    CapMemCellOnCapMemBlock(CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(6)),
    CapMemBlockOnDLS(0)};
CapMemCellOnDLS const CapMemCellOnDLS::readout_pseudo_diff_v_ref{
    CapMemCellOnCapMemBlock(CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(6)),
    CapMemBlockOnDLS(1)};
CapMemCellOnDLS const CapMemCellOnDLS::readout_iconv_test_voltage{
    CapMemCellOnCapMemBlock(CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(6)),
    CapMemBlockOnDLS(2)};
CapMemCellOnDLS const CapMemCellOnDLS::readout_iconv_sc_amp_v_ref{
    CapMemCellOnCapMemBlock(CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(6)),
    CapMemBlockOnDLS(3)};
CapMemCellOnDLS const CapMemCellOnDLS::readout_iconv_sc_amp_i_bias{
    CapMemCellOnCapMemBlock(CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(21)),
    CapMemBlockOnDLS(0)};
CapMemCellOnDLS const CapMemCellOnDLS::readout_pseudo_diff_buffer_bias{
    CapMemCellOnCapMemBlock(CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(22)),
    CapMemBlockOnDLS(0)};
CapMemCellOnDLS const CapMemCellOnDLS::readout_out_amp_i_bias_0{
    CapMemCellOnCapMemBlock(CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(23)),
    CapMemBlockOnDLS(0)};
CapMemCellOnDLS const CapMemCellOnDLS::readout_out_amp_i_bias_1{
    CapMemCellOnCapMemBlock(CapMemColumnOnCapMemBlock(129), CapMemRowOnCapMemBlock(8)),
    CapMemBlockOnDLS(0)};
CapMemCellOnDLS const CapMemCellOnDLS::readout_idac_i_bias{
    CapMemCellOnCapMemBlock(CapMemColumnOnCapMemBlock(129), CapMemRowOnCapMemBlock(9)),
    CapMemBlockOnDLS(0)};
CapMemCellOnDLS const CapMemCellOnDLS::readout_idac_i_bias_casc{
    CapMemCellOnCapMemBlock(CapMemColumnOnCapMemBlock(129), CapMemRowOnCapMemBlock(10)),
    CapMemBlockOnDLS(0)};
CapMemCellOnDLS const CapMemCellOnDLS::readout_iconv_i_bias_buffer{
    CapMemCellOnCapMemBlock(CapMemColumnOnCapMemBlock(129), CapMemRowOnCapMemBlock(11)),
    CapMemBlockOnDLS(0)};
CapMemCellOnDLS const CapMemCellOnDLS::readout_ac_mux_i_bias{
    CapMemCellOnCapMemBlock(CapMemColumnOnCapMemBlock(129), CapMemRowOnCapMemBlock(12)),
    CapMemBlockOnDLS(0)};
CapMemCellOnDLS const CapMemCellOnDLS::readout_madc_in_500na{
    CapMemCellOnCapMemBlock(CapMemColumnOnCapMemBlock(129), CapMemRowOnCapMemBlock(13)),
    CapMemBlockOnDLS(0)};
CapMemCellOnDLS const CapMemCellOnDLS::readout_sc_amp_i_bias{
    CapMemCellOnCapMemBlock(CapMemColumnOnCapMemBlock(129), CapMemRowOnCapMemBlock(14)),
    CapMemBlockOnDLS(0)};
CapMemCellOnDLS const CapMemCellOnDLS::stp_ibias_readout_top{
    CapMemCellOnCapMemBlock(CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(21)),
    CapMemBlockOnDLS(1)};
CapMemCellOnDLS const CapMemCellOnDLS::stp_ibias_readout_bottom{
    CapMemCellOnCapMemBlock(CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(21)),
    CapMemBlockOnDLS(3)};
CapMemCellOnDLS const CapMemCellOnDLS::hagen_ibias_dac_top{
    CapMemCellOnCapMemBlock(CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(22)),
    CapMemBlockOnDLS(1)};
CapMemCellOnDLS const CapMemCellOnDLS::hagen_ibias_dac_bottom{
    CapMemCellOnCapMemBlock(CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(22)),
    CapMemBlockOnDLS(3)};

SynramOnDLS CommonSynramConfigOnDLS::toSynramOnDLS() const
{
	return SynramOnDLS(toEnum());
}

CommonSynapseDriverConfigOnDLS SynapseDriverBlockOnDLS::toCommonSynapseDriverConfigOnDLS() const
{
	return CommonSynapseDriverConfigOnDLS(toEnum());
}

CommonSynramConfigOnDLS const CommonSynramConfigOnDLS::top{enum_vertical_top};
CommonSynramConfigOnDLS const CommonSynramConfigOnDLS::bottom{enum_vertical_bottom};

SynramOnDLS const SynramOnDLS::top{enum_vertical_top};
SynramOnDLS const SynramOnDLS::bottom{enum_vertical_bottom};

SynapseDriverBlockOnDLS const SynapseDriverBlockOnDLS::top{enum_vertical_top};
SynapseDriverBlockOnDLS const SynapseDriverBlockOnDLS::bottom{enum_vertical_bottom};

CommonSynapseDriverConfigOnDLS const CommonSynapseDriverConfigOnDLS::top{enum_vertical_top};
CommonSynapseDriverConfigOnDLS const CommonSynapseDriverConfigOnDLS::bottom{
    enum_vertical_bottom};

PADIBusBlockOnDLS const PADIBusBlockOnDLS::bottom{enum_vertical_bottom};
PADIBusBlockOnDLS const PADIBusBlockOnDLS::top{enum_vertical_top};

PADIEventOnDLS const PADIEventOnDLS::bottom{enum_vertical_bottom};
PADIEventOnDLS const PADIEventOnDLS::top{enum_vertical_top};

CommonPADIBusConfigOnDLS const CommonPADIBusConfigOnDLS::bottom{enum_vertical_bottom};
CommonPADIBusConfigOnDLS const CommonPADIBusConfigOnDLS::top{enum_vertical_top};

CommonSTPConfigOnDLS const CommonSTPConfigOnDLS::bottom{enum_vertical_bottom};
CommonSTPConfigOnDLS const CommonSTPConfigOnDLS::top{enum_vertical_top};

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
