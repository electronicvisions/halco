#include "halco/hicann-dls/vx/v2/capmem.h"

namespace halco::hicann_dls::vx::v2 {

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
CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::neuron_v_bias_casc_n{
    CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(7)};
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
CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::neuron_i_bias_readout_amp{
    CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(18)};
CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::neuron_i_bias_leak_source_follower{
    CapMemColumnOnCapMemBlock(128), CapMemRowOnCapMemBlock(19)};
CapMemCellOnCapMemBlock const CapMemCellOnCapMemBlock::neuron_i_bias_spike_comparator{
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

CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::v_leak{0};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::v_reset{1};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::v_threshold{2};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::e_synin_exc_rev{3};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::e_synin_inh_rev{4};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::v_adapt_leak{5};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::v_exp{6};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::v_adapt_ref{7};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_leak{8};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_reset{9};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_synin_exc_tau{10};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_synin_exc_drop{11};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_synin_exc_shift{12};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_synin_exc_gm{13};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_synin_inh_tau{14};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_synin_inh_drop{15};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_synin_inh_shift{16};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_synin_inh_gm{17};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_adapt_tau{18};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_adapt_a{19};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_adapt_b{20};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_exp{21};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_mem_offset{22};
CapMemRowOnCapMemBlock const CapMemRowOnCapMemBlock::i_bias_nmda{23};

} // namespace halco::hicann_dls::vx
