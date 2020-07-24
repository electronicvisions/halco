#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"

#include "halco/hicann-dls/vx/neuron.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct CapMemBlockOnHemisphere;

/**********\
   CapMem
\**********/

constexpr size_t num_block_global_capmem_column = 2;

// Max value is num_block_global_capmem_column larger than neuron max due to global capmem columns
struct GENPYBIND(inline_base("*")) CapMemColumnOnCapMemBlock
    : public common::detail::RantWrapper<
          CapMemColumnOnCapMemBlock,
          NeuronConfigOnNeuronConfigBlock::value_type,
          NeuronConfigOnNeuronConfigBlock::max + num_block_global_capmem_column,
          NeuronConfigOnNeuronConfigBlock::min>
    , public common::detail::XRangedTrait
{
	constexpr explicit CapMemColumnOnCapMemBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
	constexpr explicit CapMemColumnOnCapMemBlock(common::X const& x)
	    GENPYBIND(implicit_conversion) :
	    rant_t(x)
	{}

	bool isShared() const { return value() > (max - num_block_global_capmem_column); }
};


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
	static const CapMemRowOnCapMemBlock v_leak;

	/** Synaptic excitatory current-driver reference potential. */
	static const CapMemRowOnCapMemBlock v_syn_exc;

	/** Synaptic inhibitory current-driver reference potential. */
	static const CapMemRowOnCapMemBlock v_syn_inh;

	/** Leak potential of adaptation term. */
	static const CapMemRowOnCapMemBlock v_leak_adapt;

	/** Threshold potential. */
	static const CapMemRowOnCapMemBlock v_threshold;

	/** Reset potential. */
	static const CapMemRowOnCapMemBlock v_reset;

	/** Bias current of OTA during leak. */
	static const CapMemRowOnCapMemBlock i_bias_leak;

	/** Bias current of OTA during reset. */
	static const CapMemRowOnCapMemBlock i_bias_reset;

	/**
	 * Bias current of resistor leading to decay of the excitatory synaptic input to its resting
	 * potential.
	 */
	static const CapMemRowOnCapMemBlock i_bias_syn_exc_res;

	/**
	 * Bias current of resistor leading to decay of the inhibitory synaptic input to its resting
	 * potential.
	 */
	static const CapMemRowOnCapMemBlock i_bias_syn_inh_res;

	/** Bias current of excitatory synaptic input OTA for current-based input. */
	static const CapMemRowOnCapMemBlock i_bias_syn_exc_gm;

	/** Bias current of inhibitory synaptic input OTA for current-based input. */
	static const CapMemRowOnCapMemBlock i_bias_syn_inh_gm;

	/** Bias current for source degeneration of the adaptation OTA. */
	static const CapMemRowOnCapMemBlock i_bias_adapt_sd;

	/**
	 * Bias current for the resistor connecting adaptation v_w to the membrane (leading to decay of
	 * the adaptation to zero).
	 */
	static const CapMemRowOnCapMemBlock i_bias_adapt_res;

	/** Strength of the spike-triggered adaptation. */
	static const CapMemRowOnCapMemBlock i_adapt_w;

	/** Bias current of the source follower in the leak/reset circuit. */
	static const CapMemRowOnCapMemBlock i_bias_source_follower;

	/** Offset current sink from the membrane. */
	static const CapMemRowOnCapMemBlock i_offset;

	/**
	 * Bias current for the final readout buffer at the Neuron.
	 * This buffer is after the mux that selects readout from e.g. membrane or adaptation capacitor.
	 * The bias current has to be set high when using this neuron's readout amplifier for any input,
	 * including the connections to the CADC in the ColumnCurrentSwitches or the common neuron
	 * readout line selected with enable_readout in the NeuronConfig.
	 */
	static const CapMemRowOnCapMemBlock i_bias_readout;

	/** Bias current for the Adaptation OTA. */
	static const CapMemRowOnCapMemBlock i_bias_adapt;

	/** Bias current for the amplifier between membrane and the resistor to v_w. */
	static const CapMemRowOnCapMemBlock i_bias_adapt_amp;

	/** Bias current of inter-compartmental conductance. */
	static const CapMemRowOnCapMemBlock i_bias_nmda;
};


struct GENPYBIND(inline_base("*")) CapMemBlockOnHemisphere
    : public common::detail::RantWrapper<CapMemBlockOnHemisphere, uint_fast16_t, 1, 0>
{
	constexpr explicit CapMemBlockOnHemisphere(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const CapMemBlockOnHemisphere left;
	static const CapMemBlockOnHemisphere right;
};


struct GENPYBIND(inline_base("*")) CapMemBlockOnDLS
    : public common::detail::RantWrapper<CapMemBlockOnDLS, uint_fast16_t, 3, 0>
{
	constexpr explicit CapMemBlockOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CapMemBlockOnHemisphere toCapMemBlockOnHemisphere() const;
};


struct GENPYBIND(inline_base("*")) CapMemBlockConfigOnDLS
    : public common::detail::
          RantWrapper<CapMemBlockConfigOnDLS, uint_fast16_t, CapMemBlockOnDLS::max, 0>
{
	constexpr explicit CapMemBlockConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CapMemBlockOnHemisphere toCapMemBlockOnHemisphere() const;
};


struct GENPYBIND(inline_base("*")) CapMemCellOnCapMemBlock
    : public common::detail::
          GridCoordinate<CapMemCellOnCapMemBlock, CapMemColumnOnCapMemBlock, CapMemRowOnCapMemBlock>
{
	GRID_COMMON_CONSTRUCTORS(CapMemCellOnCapMemBlock)

	CapMemColumnOnCapMemBlock toCapMemColumnOnCapMemBlock() const { return x(); }
	CapMemRowOnCapMemBlock toCapMemRowOnCapMemBlock() const { return y(); }

	bool isShared() const;

	/** STP vcharge target voltage for selection 0. */
	static const CapMemCellOnCapMemBlock stp_v_charge_0;

	/** STP vcharge target voltage for selection 1. */
	static const CapMemCellOnCapMemBlock stp_v_charge_1;

	/** STP vrecover target voltage for selection 0. */
	static const CapMemCellOnCapMemBlock stp_v_recover_0;

	/** STP vrecover target voltage for selection 1. */
	static const CapMemCellOnCapMemBlock stp_v_recover_1;

	/** CADC ramp offset potential. */
	static const CapMemCellOnCapMemBlock cadc_v_ramp_offset;

	/** CADC ramp buffer bias potential. */
	static const CapMemCellOnCapMemBlock cadc_v_bias_ramp_buf;

	/** Synapse DAC bias that scales the weight of the synapses on the neuron's input globally. */
	static const CapMemCellOnCapMemBlock syn_i_bias_dac;

	/** Current determining the time constant of the correlation measurement. */
	static const CapMemCellOnCapMemBlock syn_i_bias_ramp;

	/** Current acting as a multiplicative factor while accumulating correlation measurements. */
	static const CapMemCellOnCapMemBlock syn_i_bias_store;

	/**
	 * Bias current for the output buffer of the synapses' correlation voltage, which accumulates
	 * and stores the individual measurements.
	 */
	static const CapMemCellOnCapMemBlock syn_i_bias_corout;

	/** Bias current for the comparator used for weight modulation in STP circuit. */
	static const CapMemCellOnCapMemBlock stp_i_bias_comparator;

	/** Ramp generating current used for weight modulation in STP circuit. */
	static const CapMemCellOnCapMemBlock stp_i_ramp;

	/** Calibration current for the ramp in the STP circuit. */
	static const CapMemCellOnCapMemBlock stp_i_calib;

	/** Ramp generating current for the CADC circuit. */
	static const CapMemCellOnCapMemBlock cadc_i_ramp_slope;

	/** Comparator bias current in the CADC circuit. */
	static const CapMemCellOnCapMemBlock cadc_i_bias_comp;

	/** Bias current for the reset buffer of the CADC circuit. */
	static const CapMemCellOnCapMemBlock cadc_i_bias_vreset_buf;

	/** Source degeneration bias for the excitatory synaptic input OTA. */
	static const CapMemCellOnCapMemBlock neuron_i_bias_synin_sd_exc;

	/** Source degeneration bias for the inhibitory synaptic input OTA. */
	static const CapMemCellOnCapMemBlock neuron_i_bias_synin_sd_inh;

	/** Bias current for the threshold comparator. */
	static const CapMemCellOnCapMemBlock neuron_i_bias_threshold_comparator;
};


HALCO_COORDINATE_MIXIN(CapMemMixin, CapMemBlockOnDLS, capmem)

struct GENPYBIND(inline_base("*CapMemMixin*")) CapMemCellOnDLS
    : public CapMemMixin<CapMemCellOnDLS, CapMemCellOnCapMemBlock>
{
	CapMemCellOnDLS() = default;

	explicit CapMemCellOnDLS(
	    CapMemCellOnCapMemBlock const& cell, CapMemBlockOnDLS const& block = CapMemBlockOnDLS()) :
	    mixin_t(cell, block)
	{}

	explicit CapMemCellOnDLS(enum_type const& e) : mixin_t(e) {}

	CapMemCellOnCapMemBlock toCapMemCellOnCapMemBlock() const { return This(); }

	static const CapMemCellOnDLS readout_sc_amp_v_ref;
	static const CapMemCellOnDLS readout_pseudo_diff_v_ref;
	static const CapMemCellOnDLS readout_iconv_test_voltage;
	static const CapMemCellOnDLS readout_iconv_sc_amp_v_ref;
	static const CapMemCellOnDLS readout_iconv_sc_amp_i_bias;
	static const CapMemCellOnDLS readout_pseudo_diff_buffer_bias;
	static const CapMemCellOnDLS readout_out_amp_i_bias_0;
	static const CapMemCellOnDLS readout_out_amp_i_bias_1;
	static const CapMemCellOnDLS readout_idac_i_bias;
	static const CapMemCellOnDLS readout_idac_i_bias_casc;
	static const CapMemCellOnDLS readout_iconv_i_bias_buffer;
	static const CapMemCellOnDLS readout_ac_mux_i_bias;
	static const CapMemCellOnDLS readout_madc_in_500na;
	static const CapMemCellOnDLS readout_sc_amp_i_bias;

	/**
	 * Bias current for the buffer in the top synapse drivers which allows readout of the STP
	 * voltage.
	 */
	static const CapMemCellOnDLS stp_ibias_readout_top;

	/**
	 * Bias current for the buffer in the bottom synapse drivers which allows readout of the STP
	 * voltage.
	 */
	static const CapMemCellOnDLS stp_ibias_readout_bottom;

	/**
	 * Bias current for the Hagen mode input DAC used for weight modulation of the top
	 * synapse drivers.
	 */
	static const CapMemCellOnDLS hagen_ibias_dac_top;

	/**
	 * Bias current for the Hagen mode input DAC used for weight modulation of the bottom
	 * synapse drivers.
	 */
	static const CapMemCellOnDLS hagen_ibias_dac_bottom;
};

struct GENPYBIND(inline_base("*")) ReferenceGeneratorConfigOnDLS
    : public common::detail::RantWrapper<ReferenceGeneratorConfigOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit ReferenceGeneratorConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemColumnOnCapMemBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemRowOnCapMemBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemBlockOnHemisphere)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemBlockConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemCellOnCapMemBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemCellOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ReferenceGeneratorConfigOnDLS)

} // namespace std
