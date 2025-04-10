#pragma once
#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/capmem.h"
#include "hate/visibility.h"

namespace halco::hicann_dls::vx {
namespace v3 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V3 {

using CapMemColumnOnCapMemBlock GENPYBIND(visible) =
    halco::hicann_dls::vx::CapMemColumnOnCapMemBlock;
using CapMemBlockOnHemisphere GENPYBIND(visible) = halco::hicann_dls::vx::CapMemBlockOnHemisphere;
using CapMemBlockOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CapMemBlockOnDLS;
using CapMemBlockConfigOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CapMemBlockConfigOnDLS;
using ReferenceGeneratorConfigOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::ReferenceGeneratorConfigOnDLS;
using CapMemOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CapMemOnDLS;
using CapMemSRAMTimingConfigOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::CapMemSRAMTimingConfigOnDLS;

struct GENPYBIND(inline_base("*")) CapMemRowOnCapMemBlock
    : public common::detail::RantWrapper<CapMemRowOnCapMemBlock, uint_fast16_t, 23, 0>
    , public common::detail::YRangedTrait
{
	constexpr explicit CapMemRowOnCapMemBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
	constexpr explicit CapMemRowOnCapMemBlock(common::Y const& y) GENPYBIND(implicit_conversion) :
	    rant_t(y)
	{}

	/** Leak potential. */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock v_leak;

	/** Reset potential. */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock v_reset;

	/** Threshold potential. */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock v_threshold;

	/** Reversal potential of the excitatory synaptic input. Used only in COBA mode. */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock e_synin_exc_rev;

	/** Reversal potential of the inhibitory synaptic input. Used only in COBA mode. */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock e_synin_inh_rev;

	/** Leak potential of adaptation term. */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock v_adapt_leak;

	/** Threshold voltage for the exponential term. */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock v_exp;

	/** Adaptation reference potential the adaptation state variable is pulled towards. */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock v_adapt_ref;

	/** Bias current of OTA during leak. */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock i_bias_leak;

	/** Bias current of OTA during reset. */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock i_bias_reset;

	/** Bias current for the RC circuit controlling the excitatory synaptic input time constant. */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock i_bias_synin_exc_tau;

	/**
	 * Bias current for the source follower controlling the reference voltage for the
	 * excitatory synaptic input's OTA.
	 */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock i_bias_synin_exc_shift;

	/** Bias current of excitatory synaptic input OTA for current-based input. */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock i_bias_synin_exc_gm;

	/** Bias current of excitatory synaptic input OTA for conductance-based input. */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock i_bias_synin_exc_coba;

	/** Bias current for the RC circuit controlling the inhibitory synaptic input time constant. */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock i_bias_synin_inh_tau;

	/**
	 * Bias current for the source follower controlling the reference voltage for the
	 * inhibitory synaptic input's OTA.
	 */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock i_bias_synin_inh_shift;

	/** Bias current of inhibitory synaptic input OTA for current-based input. */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock i_bias_synin_inh_gm;

	/** Bias current of inhibitory synaptic input OTA for conductance-based input. */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock i_bias_synin_inh_coba;

	/** Bias current controlling the adaptation time constant. */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock i_bias_adapt_tau;

	/** Bias current controlling the sub-threshold adaptation strength. */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock i_bias_adapt_a;

	/** Bias current controlling the spike-triggered adaptation strength. */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock i_bias_adapt_b;

	/** Bias current controlling the strength of the exponential term. */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock i_bias_exp;

	/**
	 * Positive or negative offset current onto the membrane.
	 * The sign is controlled by a digital setting.
	 */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock i_mem_offset;

	/** Bias current of inter-compartmental conductance. */
	static const SYMBOL_VISIBLE CapMemRowOnCapMemBlock i_bias_nmda;
};

struct GENPYBIND(inline_base("*")) CapMemCellOnCapMemBlock
    : public common::detail::
          GridCoordinate<CapMemCellOnCapMemBlock, CapMemColumnOnCapMemBlock, CapMemRowOnCapMemBlock>
{
	GRID_COMMON_CONSTRUCTORS(CapMemCellOnCapMemBlock)

	CapMemColumnOnCapMemBlock toCapMemColumnOnCapMemBlock() const
	{
		return x();
	}
	CapMemRowOnCapMemBlock toCapMemRowOnCapMemBlock() const
	{
		return y();
	}

	bool isShared() const SYMBOL_VISIBLE;

	/** STP vcharge target voltage for selection 0. */
	static const SYMBOL_VISIBLE CapMemCellOnCapMemBlock stp_v_charge_0;

	/** STP vcharge target voltage for selection 1. */
	static const SYMBOL_VISIBLE CapMemCellOnCapMemBlock stp_v_charge_1;

	/** STP vrecover target voltage for selection 0. */
	static const SYMBOL_VISIBLE CapMemCellOnCapMemBlock stp_v_recover_0;

	/** STP vrecover target voltage for selection 1. */
	static const SYMBOL_VISIBLE CapMemCellOnCapMemBlock stp_v_recover_1;

	/** CADC ramp offset potential. */
	static const SYMBOL_VISIBLE CapMemCellOnCapMemBlock cadc_v_ramp_offset;

	/** CADC ramp buffer bias potential. */
	static const SYMBOL_VISIBLE CapMemCellOnCapMemBlock cadc_v_bias_ramp_buf;

	/** Cascode bias potential for various OTAs within the neuron. */
	static const SYMBOL_VISIBLE CapMemCellOnCapMemBlock neuron_v_bias_casc_n;

	/** Synapse DAC bias that scales the weight of the synapses on the neuron's input globally. */
	static const SYMBOL_VISIBLE CapMemCellOnCapMemBlock syn_i_bias_dac;

	/** Current determining the time constant of the correlation measurement. */
	static const SYMBOL_VISIBLE CapMemCellOnCapMemBlock syn_i_bias_ramp;

	/** Current acting as a multiplicative factor while accumulating correlation measurements. */
	static const SYMBOL_VISIBLE CapMemCellOnCapMemBlock syn_i_bias_store;

	/**
	 * Bias current for the output buffer of the synapses' correlation voltage, which accumulates
	 * and stores the individual measurements.
	 */
	static const SYMBOL_VISIBLE CapMemCellOnCapMemBlock syn_i_bias_corout;

	/** Bias current for the comparator used for weight modulation in STP circuit. */
	static const SYMBOL_VISIBLE CapMemCellOnCapMemBlock stp_i_bias_comparator;

	/** Ramp generating current used for weight modulation in STP circuit. */
	static const SYMBOL_VISIBLE CapMemCellOnCapMemBlock stp_i_ramp;

	/** Calibration current for the ramp in the STP circuit. */
	static const SYMBOL_VISIBLE CapMemCellOnCapMemBlock stp_i_calib;

	/** Ramp generating current for the CADC circuit. */
	static const SYMBOL_VISIBLE CapMemCellOnCapMemBlock cadc_i_ramp_slope;

	/** Comparator bias current in the CADC circuit. */
	static const SYMBOL_VISIBLE CapMemCellOnCapMemBlock cadc_i_bias_comp;

	/** Bias current for the reset buffer of the CADC circuit. */
	static const SYMBOL_VISIBLE CapMemCellOnCapMemBlock cadc_i_bias_vreset_buf;

	/** Bias current for the neuron's readout amplifier. */
	static const SYMBOL_VISIBLE CapMemCellOnCapMemBlock neuron_i_bias_readout_amp;

	/**
	 * Bias current for the leak/reset input voltage drop source follower.
	 * Note that also the potentials v_adapt_ref, v_adapt_leak, v_exp,
	 * e_synin_exc_rev, e_synin_inh_rev are buffered by a source follower
	 * and affected by this parameter.*/
	static const SYMBOL_VISIBLE CapMemCellOnCapMemBlock neuron_i_bias_leak_source_follower;

	/** Bias current for the threshold comparator. */
	static const SYMBOL_VISIBLE CapMemCellOnCapMemBlock neuron_i_bias_spike_comparator;

	/**
	 * Bias current for the source followers controlling the drop of the synaptic
	 * input voltage before the OTAs' input. Applies to both excitatory and inhibitory
	 * synaptic inputs.
	 */
	static const SYMBOL_VISIBLE CapMemCellOnCapMemBlock neuron_i_bias_synin_drop;
};

HALCO_COORDINATE_MIXIN(CapMemMixin, CapMemBlockOnDLS, capmem)

struct GENPYBIND(inline_base("*CapMemMixin*"), inline_base("*CoordinateBase*")) CapMemCellOnDLS
    : public CapMemMixin<CapMemCellOnDLS, CapMemCellOnCapMemBlock>
    , common::CoordinateBase<CapMemCellOnDLS>
{
	CapMemCellOnDLS() = default;

	explicit CapMemCellOnDLS(
	    CapMemCellOnCapMemBlock const& cell, CapMemBlockOnDLS const& block = CapMemBlockOnDLS()) :
	    mixin_t(cell, block)
	{}

	explicit CapMemCellOnDLS(enum_type const& e) : mixin_t(e) {}

	CapMemCellOnCapMemBlock toCapMemCellOnCapMemBlock() const
	{
		return This();
	}

	static const SYMBOL_VISIBLE CapMemCellOnDLS readout_sc_amp_v_ref;
	static const SYMBOL_VISIBLE CapMemCellOnDLS readout_pseudo_diff_v_ref;
	static const SYMBOL_VISIBLE CapMemCellOnDLS readout_iconv_test_voltage;
	static const SYMBOL_VISIBLE CapMemCellOnDLS readout_iconv_sc_amp_v_ref;
	static const SYMBOL_VISIBLE CapMemCellOnDLS readout_iconv_sc_amp_i_bias;
	static const SYMBOL_VISIBLE CapMemCellOnDLS readout_pseudo_diff_buffer_bias;
	static const SYMBOL_VISIBLE CapMemCellOnDLS readout_out_amp_i_bias_0;
	static const SYMBOL_VISIBLE CapMemCellOnDLS readout_out_amp_i_bias_1;
	static const SYMBOL_VISIBLE CapMemCellOnDLS readout_idac_i_bias;
	static const SYMBOL_VISIBLE CapMemCellOnDLS readout_idac_i_bias_casc;
	static const SYMBOL_VISIBLE CapMemCellOnDLS readout_iconv_i_bias_buffer;
	static const SYMBOL_VISIBLE CapMemCellOnDLS readout_ac_mux_i_bias;
	static const SYMBOL_VISIBLE CapMemCellOnDLS readout_madc_in_500na;
	static const SYMBOL_VISIBLE CapMemCellOnDLS readout_sc_amp_i_bias;

	/**
	 * Bias current for the buffer in the top synapse drivers which allows readout of the STP
	 * voltage.
	 */
	static const SYMBOL_VISIBLE CapMemCellOnDLS stp_ibias_readout_top;

	/**
	 * Bias current for the buffer in the bottom synapse drivers which allows readout of the STP
	 * voltage.
	 */
	static const SYMBOL_VISIBLE CapMemCellOnDLS stp_ibias_readout_bottom;

	/**
	 * Bias current for the Hagen mode input DAC used for weight modulation of the top
	 * synapse drivers.
	 */
	static const SYMBOL_VISIBLE CapMemCellOnDLS hagen_ibias_dac_top;

	/**
	 * Bias current for the Hagen mode input DAC used for weight modulation of the bottom
	 * synapse drivers.
	 */
	static const SYMBOL_VISIBLE CapMemCellOnDLS hagen_ibias_dac_bottom;
};


struct GENPYBIND(inline_base("*")) UnusedCapMemCellOnDLS
    : public common::detail::RantWrapper<UnusedCapMemCellOnDLS, uint_fast16_t, 89, 0>
{
	constexpr explicit UnusedCapMemCellOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CapMemCellOnDLS toCapMemCellOnDLS() const SYMBOL_VISIBLE;
};

} // namespace v3
} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v3::CapMemRowOnCapMemBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v3::CapMemCellOnCapMemBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v3::CapMemCellOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v3::UnusedCapMemCellOnDLS)

} // namespace std
