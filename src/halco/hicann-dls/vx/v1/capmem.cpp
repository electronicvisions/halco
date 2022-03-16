#include "halco/hicann-dls/vx/v1/capmem.h"

#include "halco/common/iter_all.h"

namespace halco::hicann_dls::vx::v1 {

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

CapMemCellOnDLS UnusedCapMemCellOnDLS::toCapMemCellOnDLS() const
{
	using namespace halco::common;
	static const std::array<CapMemCellOnDLS, size> cells = []() {
		std::array<CapMemCellOnDLS, size> cs;
		size_t i = 0;
		// unused rows in every column
		for (auto const block : iter_all<CapMemBlockOnDLS>()) {
			for (size_t c = 0; c < 128; ++c) {
				cs.at(i) = CapMemCellOnDLS(
				    CapMemCellOnCapMemBlock(
				        CapMemRowOnCapMemBlock(2), CapMemColumnOnCapMemBlock(c)),
				    block);
				i++;
				cs.at(i) = CapMemCellOnDLS(
				    CapMemCellOnCapMemBlock(
				        CapMemRowOnCapMemBlock(4), CapMemColumnOnCapMemBlock(c)),
				    block);
				i++;
				cs.at(i) = CapMemCellOnDLS(
				    CapMemCellOnCapMemBlock(
				        CapMemRowOnCapMemBlock(17), CapMemColumnOnCapMemBlock(c)),
				    block);
				i++;
			}
			cs.at(i) = CapMemCellOnDLS(
			    CapMemCellOnCapMemBlock(CapMemRowOnCapMemBlock(7), CapMemColumnOnCapMemBlock(128)),
			    block);
			i++;
		}
		// unused rows in column 128
		cs.at(i) = CapMemCellOnDLS(
		    CapMemCellOnCapMemBlock(CapMemRowOnCapMemBlock(23), CapMemColumnOnCapMemBlock(128)),
		    CapMemBlockOnDLS(1));
		i++;
		cs.at(i) = CapMemCellOnDLS(
		    CapMemCellOnCapMemBlock(CapMemRowOnCapMemBlock(23), CapMemColumnOnCapMemBlock(128)),
		    CapMemBlockOnDLS(3));
		i++;
		for (size_t j = 21; j < 24; ++j) {
			cs.at(i) = CapMemCellOnDLS(
			    CapMemCellOnCapMemBlock(CapMemRowOnCapMemBlock(j), CapMemColumnOnCapMemBlock(128)),
			    CapMemBlockOnDLS(2));
			i++;
		}
		// unused rows in column 129
		for (size_t j = 0; j < 8; ++j) {
			cs.at(i) = CapMemCellOnDLS(
			    CapMemCellOnCapMemBlock(CapMemRowOnCapMemBlock(j), CapMemColumnOnCapMemBlock(129)),
			    CapMemBlockOnDLS(0));
			i++;
		}
		for (size_t j = 15; j < 24; ++j) {
			cs.at(i) = CapMemCellOnDLS(
			    CapMemCellOnCapMemBlock(CapMemRowOnCapMemBlock(j), CapMemColumnOnCapMemBlock(129)),
			    CapMemBlockOnDLS(0));
			i++;
		}
		for (size_t b = 1; b < 4; ++b) {
			for (auto const row : iter_all<CapMemRowOnCapMemBlock>()) {
				cs.at(i) = CapMemCellOnDLS(
				    CapMemCellOnCapMemBlock(row, CapMemColumnOnCapMemBlock(129)),
				    CapMemBlockOnDLS(b));
				i++;
			}
		}
		return cs;
	}();
	return cells.at(value());
}

} // namespace halco::hicann_dls::vx::v1
