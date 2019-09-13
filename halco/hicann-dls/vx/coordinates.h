#pragma once

extern "C"
{
#include <stdint.h>
}

#include "halco/common/common.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.th"
#include "halco/common/mixin.h"

#include "halco/hicann-dls/vx/background.h"
#include "halco/hicann-dls/vx/dac.h"
#include "halco/hicann-dls/vx/event.h"
#include "halco/hicann-dls/vx/highspeed_link.h"
#include "halco/hicann-dls/vx/i2c.h"
#include "halco/hicann-dls/vx/jtag.h"
#include "halco/hicann-dls/vx/omnibus.h"
#include "halco/hicann-dls/vx/pll.h"
#include "halco/hicann-dls/vx/ppu.h"
#include "halco/hicann-dls/vx/reset.h"
#include "halco/hicann-dls/vx/routing_crossbar.h"
#include "halco/hicann-dls/vx/spi.h"
#include "halco/hicann-dls/vx/timing.h"
#include "halco/hicann-dls/vx/xboard.h"

GENPYBIND_TAG_HALCO_HICANN_DLS_VX
GENPYBIND_MANUAL({
	parent.attr("__variant__") = "pybind11";
	parent->py::module::import("pyhalco_common");
})

namespace halco {
namespace hicann_dls {
namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/******\
  FPGA
\******/

/**
 * Unique identifier on FPGA.
 */
struct GENPYBIND(inline_base("*")) FPGADeviceDNAOnFPGA
    : public common::detail::RantWrapper<FPGADeviceDNAOnFPGA, uint_fast16_t, 0, 0>
{
	constexpr explicit FPGADeviceDNAOnFPGA(uintmax_t const val = 0) : rant_t(val) {}
};

/************\
   Loopback
\************/

/**
 * Unique coordinate for a readable entity without payload.
 * The read response is issued as fast as possible, which e.g. enables usage for synchronization of
 * from-FPGA time annotation and to-FPGA Playback time annotation.
 */
struct GENPYBIND(inline_base("*")) NullPayloadReadableOnFPGA
    : public common::detail::RantWrapper<NullPayloadReadableOnFPGA, uint_fast16_t, 0, 0>
{
	constexpr explicit NullPayloadReadableOnFPGA(uintmax_t const val = 0) : rant_t(val) {}
};

struct CrossbarInputOnDLS;
struct CrossbarL2OutputOnDLS;

/**********\
    CADC
\**********/

struct GENPYBIND(inline_base("*")) CADCConfigOnDLS
    : public common::detail::RantWrapper<CADCConfigOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit CADCConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}

	PPUOnDLS toPPUOnDLS() const;

	static const CADCConfigOnDLS top;
	static const CADCConfigOnDLS bottom;
};

/**********\
   Neuron
\**********/

struct GENPYBIND(inline_base("*")) NeuronOnNeuronBlock
    : public common::detail::RantWrapper<NeuronOnNeuronBlock, uint_fast16_t, 127, 0>
{
	constexpr explicit NeuronOnNeuronBlock(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) NeuronBlockOnDLS
    : public common::detail::RantWrapper<NeuronBlockOnDLS, uint_fast16_t, 3, 0>
{
	constexpr explicit NeuronBlockOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

HALCO_COORDINATE_MIXIN(NeuronMixin, NeuronBlockOnDLS, neuron)

struct GENPYBIND(inline_base("*NeuronMixin*")) NeuronOnDLS
    : public NeuronMixin<NeuronOnDLS, NeuronOnNeuronBlock>
{
	NeuronOnDLS() = default;

	explicit NeuronOnDLS(
	    NeuronOnNeuronBlock const& neuron, NeuronBlockOnDLS const& block = NeuronBlockOnDLS()) :
	    mixin_t(neuron, block)
	{}

	explicit NeuronOnDLS(enum_type const& e) : mixin_t(e) {}

	NeuronOnNeuronBlock toNeuronOnNeuronBlock() const { return This(); }
};

struct GENPYBIND(inline_base("*")) CommonNeuronConfigOnDLS
    : public common::detail::RantWrapper<CommonNeuronConfigOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit CommonNeuronConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

/*****************\
   SynapseDriver
\*****************/

struct CommonSynapseDriverConfigOnDLS;

struct GENPYBIND(inline_base("*")) SynapseDriverOnSynapseDriverBlock
    : public common::detail::RantWrapper<SynapseDriverOnSynapseDriverBlock, uint_fast16_t, 127, 0>
{
	constexpr explicit SynapseDriverOnSynapseDriverBlock(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) SynapseDriverBlockOnDLS
    : public common::detail::RantWrapper<SynapseDriverBlockOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit SynapseDriverBlockOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CommonSynapseDriverConfigOnDLS toCommonSynapseDriverConfigOnDLS() const;

	static const SynapseDriverBlockOnDLS top;
	static const SynapseDriverBlockOnDLS bottom;
};

HALCO_COORDINATE_MIXIN(SynapseDriverMixin, SynapseDriverBlockOnDLS, synapse_driver)

struct GENPYBIND(inline_base("*SynapseDriverMixin*")) SynapseDriverOnDLS
    : public SynapseDriverMixin<SynapseDriverOnDLS, SynapseDriverOnSynapseDriverBlock>
{
	SynapseDriverOnDLS() = default;

	explicit SynapseDriverOnDLS(
	    SynapseDriverOnSynapseDriverBlock const& synapse_driver,
	    SynapseDriverBlockOnDLS const& block = SynapseDriverBlockOnDLS()) :
	    mixin_t(synapse_driver, block)
	{}

	explicit SynapseDriverOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseDriverOnSynapseDriverBlock toSynapseDriverOnSynapseDriverBlock() const { return This(); }
};

struct GENPYBIND(inline_base("*")) CommonSynapseDriverConfigOnDLS
    : public common::detail::RantWrapper<CommonSynapseDriverConfigOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit CommonSynapseDriverConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}

	SynapseDriverBlockOnDLS toSynapseDriverBlockOnDLS() const
	{
		return SynapseDriverBlockOnDLS(toEnum());
	}

	static const CommonSynapseDriverConfigOnDLS top;
	static const CommonSynapseDriverConfigOnDLS bottom;
};


/*****************\
   PADIBus
\*****************/

struct SynramOnDLS;
struct PADIEventOnDLS;
struct CommonPADIBusConfigOnDLS;
struct CommonSTPConfigOnDLS;

struct GENPYBIND(inline_base("*")) PADIBusBlockOnDLS
    : public common::detail::RantWrapper<PADIBusBlockOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit PADIBusBlockOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	SynramOnDLS toSynramOnDLS() const;
	PADIEventOnDLS toPADIEventOnDLS() const;
	CommonPADIBusConfigOnDLS toCommonPADIBusConfigOnDLS() const;
	CommonSTPConfigOnDLS toCommonSTPConfigOnDLS() const;

	static const PADIBusBlockOnDLS top;
	static const PADIBusBlockOnDLS bottom;
};

struct GENPYBIND(inline_base("*")) PADIBusOnPADIBusBlock
    : public common::detail::RantWrapper<PADIBusOnPADIBusBlock, uint_fast16_t, 3, 0>
{
	constexpr explicit PADIBusOnPADIBusBlock(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


HALCO_COORDINATE_MIXIN(PADIBusMixin, PADIBusBlockOnDLS, padi_bus)

struct GENPYBIND(inline_base("*PADIBusMixin*")) PADIBusOnDLS
    : public PADIBusMixin<PADIBusOnDLS, PADIBusOnPADIBusBlock>
{
	PADIBusOnDLS() = default;

	explicit PADIBusOnDLS(
	    PADIBusOnPADIBusBlock const& synapse_driver,
	    PADIBusBlockOnDLS const& block = PADIBusBlockOnDLS()) :
	    mixin_t(synapse_driver, block)
	{}

	explicit PADIBusOnDLS(enum_type const& e) : mixin_t(e) {}

	PADIBusOnPADIBusBlock toPADIBusOnPADIBusBlock() const { return This(); }
	CrossbarOutputOnDLS toCrossbarOutputOnDLS() const { return CrossbarOutputOnDLS(toEnum()); }
};

struct GENPYBIND(inline_base("*")) CommonPADIBusConfigOnDLS
    : public common::detail::RantWrapper<CommonPADIBusConfigOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit CommonPADIBusConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}

	PADIBusBlockOnDLS toPADIBusBlockOnDLS() const { return PADIBusBlockOnDLS(toEnum()); }

	static const CommonPADIBusConfigOnDLS top;
	static const CommonPADIBusConfigOnDLS bottom;
};

struct GENPYBIND(inline_base("*")) CommonSTPConfigOnDLS
    : public common::detail::RantWrapper<CommonSTPConfigOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit CommonSTPConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}

	PADIBusBlockOnDLS toPADIBusBlockOnDLS() const { return PADIBusBlockOnDLS(toEnum()); }

	static const CommonSTPConfigOnDLS top;
	static const CommonSTPConfigOnDLS bottom;
};

struct GENPYBIND(inline_base("*")) PADIEventOnDLS
    : public common::detail::RantWrapper<PADIEventOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit PADIEventOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	PADIBusBlockOnDLS toPADIBusBlockOnDLS() const { return PADIBusBlockOnDLS(toEnum()); }

	static const PADIEventOnDLS top;
	static const PADIEventOnDLS bottom;
};

/**********\
   CapMem
\**********/

constexpr size_t num_block_global_capmem_column = 2;

// Max value is num_block_global_capmem_column larger than neuron max due to global capmem columns
struct GENPYBIND(inline_base("*")) CapMemColumnOnCapMemBlock
    : public common::detail::RantWrapper<
          CapMemColumnOnCapMemBlock,
          NeuronOnNeuronBlock::value_type,
          NeuronOnNeuronBlock::max + num_block_global_capmem_column,
          NeuronOnNeuronBlock::min>
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

struct GENPYBIND(inline_base("*")) CapMemBlockOnDLS
    : public common::detail::RantWrapper<CapMemBlockOnDLS, uint_fast16_t, 3, 0>
{
	constexpr explicit CapMemBlockOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) CapMemBlockConfigOnDLS
    : public common::detail::
          RantWrapper<CapMemBlockConfigOnDLS, uint_fast16_t, CapMemBlockOnDLS::max, 0>
{
	constexpr explicit CapMemBlockConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
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

/************\
    Synram
\************/

struct SynramOnDLS;

struct GENPYBIND(inline_base("*")) CommonSynramConfigOnDLS
    : public common::detail::RantWrapper<CommonSynramConfigOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit CommonSynramConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	PPUOnDLS toPPUOnDLS() const { return PPUOnDLS(toEnum()); }
	SynramOnDLS toSynramOnDLS() const;

	static const CommonSynramConfigOnDLS top;
	static const CommonSynramConfigOnDLS bottom;
};

/***********\
   Synapse
\***********/

struct GENPYBIND(inline_base("*")) SynapseQuadColumnOnDLS
    : public common::detail::RantWrapper<
          SynapseQuadColumnOnDLS,
          uint_fast16_t,
          NeuronOnNeuronBlock::size * 2 / 4 - 1,
          0>
    , public common::detail::XRangedTrait
{
	constexpr explicit SynapseQuadColumnOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	constexpr explicit SynapseQuadColumnOnDLS(common::X const& x) GENPYBIND(implicit_conversion) :
	    rant_t(x)
	{}
};

struct GENPYBIND(inline_base("*")) SynapseRowOnSynram
    : public common::detail::RantWrapper<SynapseRowOnSynram, uint_fast16_t, 255, 0>
    , public common::detail::YRangedTrait
{
	constexpr explicit SynapseRowOnSynram(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	constexpr explicit SynapseRowOnSynram(common::Y const& y) GENPYBIND(implicit_conversion) :
	    rant_t(y)
	{}
};

struct GENPYBIND(inline_base("*")) SynapseQuadOnSynram
    : public common::detail::
          GridCoordinate<SynapseQuadOnSynram, SynapseQuadColumnOnDLS, SynapseRowOnSynram>
{
	GRID_COMMON_CONSTRUCTORS(SynapseQuadOnSynram)

	SynapseQuadColumnOnDLS toSynapseQuadColumnOnDLS() const { return x(); }
	SynapseRowOnSynram toSynapseRowOnSynram() const { return y(); }
};

struct GENPYBIND(inline_base("*")) SynramOnDLS
    : public common::detail::RantWrapper<SynramOnDLS, uint_fast16_t, PPUOnDLS::max, PPUOnDLS::min>
{
	constexpr explicit SynramOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CommonSynramConfigOnDLS toCommonSynramConfigOnDLS() const
	{
		return CommonSynramConfigOnDLS(toEnum());
	}
	PPUOnDLS toPPUOnDLS() const { return PPUOnDLS(toEnum()); }

	static const SynramOnDLS top;
	static const SynramOnDLS bottom;
};

HALCO_COORDINATE_MIXIN(SynramMixin, SynramOnDLS, synram)

struct GENPYBIND(inline_base("*SynramMixin*")) SynapseQuadOnDLS
    : public SynramMixin<SynapseQuadOnDLS, SynapseQuadOnSynram>
{
	SynapseQuadOnDLS() = default;

	explicit SynapseQuadOnDLS(
	    SynapseQuadOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit SynapseQuadOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseQuadOnSynram toSynapseQuadOnSynram() const { return This(); }
};

struct GENPYBIND(inline_base("*")) SynapseOnSynapseQuad
    : public common::detail::RantWrapper<SynapseOnSynapseQuad, uint_fast16_t, 3, 0>
{
	constexpr explicit SynapseOnSynapseQuad(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

/************************\
  ColumnCorrelationQuad
\************************/

struct GENPYBIND(inline_base("*")) ColumnCorrelationQuadOnSynram
    : public common::detail::RantWrapper<
          ColumnCorrelationQuadOnSynram,
          uint_fast16_t,
          SynapseQuadColumnOnDLS::max,
          SynapseQuadColumnOnDLS::min>
    , public common::detail::XRangedTrait
{
	constexpr explicit ColumnCorrelationQuadOnSynram(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	constexpr explicit ColumnCorrelationQuadOnSynram(common::X const& x)
	    GENPYBIND(implicit_conversion) :
	    rant_t(x)
	{}

	SynapseQuadColumnOnDLS toSynapseQuadColumnOnDLS() const
	{
		return SynapseQuadColumnOnDLS(toEnum());
	}
};

struct GENPYBIND(inline_base("*SynramMixin*")) ColumnCorrelationQuadOnDLS
    : public SynramMixin<ColumnCorrelationQuadOnDLS, ColumnCorrelationQuadOnSynram>
{
	ColumnCorrelationQuadOnDLS() = default;

	explicit ColumnCorrelationQuadOnDLS(
	    ColumnCorrelationQuadOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit ColumnCorrelationQuadOnDLS(enum_type const& e) : mixin_t(e) {}

	ColumnCorrelationQuadOnSynram toColumnCorrelationQuadOnSynram() const { return This(); }
};

struct GENPYBIND(inline_base("*")) ColumnCorrelationSwitchOnColumnCorrelationQuad
    : public common::detail::
          RantWrapper<ColumnCorrelationSwitchOnColumnCorrelationQuad, uint_fast16_t, 3, 0>
{
	constexpr explicit ColumnCorrelationSwitchOnColumnCorrelationQuad(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

/********************\
  ColumnCurrentQuad
\********************/

struct GENPYBIND(inline_base("*")) ColumnCurrentQuadOnSynram
    : public common::detail::RantWrapper<
          ColumnCurrentQuadOnSynram,
          uint_fast16_t,
          SynapseQuadColumnOnDLS::max,
          SynapseQuadColumnOnDLS::min>
    , public common::detail::XRangedTrait
{
	constexpr explicit ColumnCurrentQuadOnSynram(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	constexpr explicit ColumnCurrentQuadOnSynram(common::X const& x)
	    GENPYBIND(implicit_conversion) :
	    rant_t(x)
	{}

	SynapseQuadColumnOnDLS toSynapseQuadColumnOnDLS() const
	{
		return SynapseQuadColumnOnDLS(toEnum());
	}
};

struct GENPYBIND(inline_base("*SynramMixin*")) ColumnCurrentQuadOnDLS
    : public SynramMixin<ColumnCurrentQuadOnDLS, ColumnCurrentQuadOnSynram>
{
	ColumnCurrentQuadOnDLS() = default;

	explicit ColumnCurrentQuadOnDLS(
	    ColumnCurrentQuadOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit ColumnCurrentQuadOnDLS(enum_type const& e) : mixin_t(e) {}

	ColumnCurrentQuadOnSynram toColumnCurrentQuadOnSynram() const { return This(); }
};

struct GENPYBIND(inline_base("*")) ColumnCurrentSwitchOnColumnCurrentQuad
    : public common::detail::
          RantWrapper<ColumnCurrentSwitchOnColumnCurrentQuad, uint_fast16_t, 3, 0>
{
	constexpr explicit ColumnCurrentSwitchOnColumnCurrentQuad(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

/******\
  CADC
\******/

struct GENPYBIND(inline_base("*")) CADCChannelType
    : public common::detail::RantWrapper<CADCChannelType, uint_fast16_t, 1, 0>
{
	constexpr explicit CADCChannelType(uintmax_t const val = 0) : rant_t(val) {}

	static const CADCChannelType causal;
	static const CADCChannelType acausal;
};

struct GENPYBIND(inline_base("*")) CADCReadoutType
    : public common::detail::RantWrapper<CADCReadoutType, uint_fast16_t, 1, 0>
{
	constexpr explicit CADCReadoutType(uintmax_t const val = 0) : rant_t(val) {}

	static const CADCReadoutType trigger_read;
	static const CADCReadoutType buffered;
};

HALCO_COORDINATE_MIXIN(CADCChannelTypeMixin, CADCChannelType, cadc_channel_type)
HALCO_COORDINATE_MIXIN(CADCReadoutTypeMixin, CADCReadoutType, cadc_readout_type)

struct GENPYBIND(inline_base("*CADCChannelTypeMixin*")) CADCSampleQuadUnspecifiedReadoutOnSynram
    : public CADCChannelTypeMixin<CADCSampleQuadUnspecifiedReadoutOnSynram, SynapseQuadOnSynram>
{
	CADCSampleQuadUnspecifiedReadoutOnSynram() = default;

	explicit CADCSampleQuadUnspecifiedReadoutOnSynram(
	    SynapseQuadOnSynram const& quad, CADCChannelType const& cadc_channel_type) :
	    mixin_t(quad, cadc_channel_type)
	{}

	explicit CADCSampleQuadUnspecifiedReadoutOnSynram(enum_type const& e) : mixin_t(e) {}

	SynapseQuadOnSynram toSynapseQuadOnSynram() const { return This(); }
};

struct GENPYBIND(inline_base("*CADCReadoutTypeMixin*")) CADCSampleQuadOnSynram
    : public CADCReadoutTypeMixin<CADCSampleQuadOnSynram, CADCSampleQuadUnspecifiedReadoutOnSynram>
{
	CADCSampleQuadOnSynram() = default;

	explicit CADCSampleQuadOnSynram(
	    SynapseQuadOnSynram const& quad,
	    CADCChannelType const& cadc_channel_type,
	    CADCReadoutType const& cadc_readout_type = CADCReadoutType()) :
	    mixin_t(
	        CADCSampleQuadUnspecifiedReadoutOnSynram(quad, cadc_channel_type), cadc_readout_type)
	{}

	explicit CADCSampleQuadOnSynram(enum_type const& e) : mixin_t(e) {}

	CADCSampleQuadUnspecifiedReadoutOnSynram toCADCSampleQuadUnspecifiedReadoutOnSynram() const
	{
		return This();
	}
};

struct GENPYBIND(inline_base("*SynramMixin*")) CADCSampleQuadOnDLS
    : public SynramMixin<CADCSampleQuadOnDLS, CADCSampleQuadOnSynram>
{
	CADCSampleQuadOnDLS() = default;

	explicit CADCSampleQuadOnDLS(CADCSampleQuadOnSynram const& block, SynramOnDLS const& synram) :
	    mixin_t(block, synram)
	{}

	explicit CADCSampleQuadOnDLS(enum_type const& e) : mixin_t(e) {}

	CADCSampleQuadOnSynram toCADCSampleQuadOnSynram() const { return This(); }
};

struct GENPYBIND(inline_base("*")) CADCChannelColumnOnSynram
    : public common::detail::RantWrapper<CADCChannelColumnOnSynram, uint_fast16_t, 255, 0>
{
	constexpr explicit CADCChannelColumnOnSynram(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*CADCChannelTypeMixin*")) CADCChannelConfigOnSynram
    : public CADCChannelTypeMixin<CADCChannelConfigOnSynram, CADCChannelColumnOnSynram>
{
	CADCChannelConfigOnSynram() = default;

	explicit CADCChannelConfigOnSynram(
	    CADCChannelColumnOnSynram const& quad, CADCChannelType const& cadc_channel_type) :
	    mixin_t(quad, cadc_channel_type)
	{}

	explicit CADCChannelConfigOnSynram(enum_type const& e) : mixin_t(e) {}

	CADCChannelColumnOnSynram toCADCChannelColumnOnSynram() const { return This(); }
};

struct GENPYBIND(inline_base("*SynramMixin*")) CADCChannelConfigOnDLS
    : public SynramMixin<CADCChannelConfigOnDLS, CADCChannelConfigOnSynram>
{
	CADCChannelConfigOnDLS() = default;

	explicit CADCChannelConfigOnDLS(
	    CADCChannelConfigOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit CADCChannelConfigOnDLS(enum_type const& e) : mixin_t(e) {}

	CADCChannelConfigOnSynram toCADCChannelConfigOnSynram() const { return This(); }
};

struct GENPYBIND(inline_base("*")) CADCSampleOnCADCSampleQuad
    : public common::detail::RantWrapper<CADCSampleOnCADCSampleQuad, uint_fast16_t, 3, 0>
{
	constexpr explicit CADCSampleOnCADCSampleQuad(uintmax_t const val = 0) : rant_t(val) {}
};

} // namespace vx
} // namespace hicann_dls
} // namespace halco

// std::hash specializations
namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::FPGADeviceDNAOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NullPayloadReadableOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronOnNeuronBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonNeuronConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseDriverOnSynapseDriverBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseDriverBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseDriverOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonSynapseDriverConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemColumnOnCapMemBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemRowOnCapMemBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemBlockConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemCellOnCapMemBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemCellOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonSynramConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseQuadColumnOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseRowOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynramOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseOnSynapseQuad)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PADIBusOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PADIBusBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PADIBusOnPADIBusBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PADIEventOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonPADIBusConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonSTPConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ColumnCorrelationQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ColumnCurrentQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ColumnCorrelationQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ColumnCurrentQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ColumnCorrelationSwitchOnColumnCorrelationQuad)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ColumnCurrentSwitchOnColumnCurrentQuad)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCChannelType)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCReadoutType)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCSampleQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCSampleQuadUnspecifiedReadoutOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCSampleQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCChannelColumnOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCChannelConfigOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCChannelConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCSampleOnCADCSampleQuad)

} // namespace std

GENPYBIND(postamble, tag(hicann_dls_vx))
GENPYBIND_MANUAL({
	parent->py::module::import("pyhalco_hicann_dls_vx_patch").attr("patch")(parent);
})
