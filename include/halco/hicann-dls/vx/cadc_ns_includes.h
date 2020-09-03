struct SynapseQuadOnDLS;
struct SynapseWeightQuadOnDLS;
struct SynapseLabelQuadOnDLS;
struct SynapseCorrelationCalibQuadOnDLS;

using CADCOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CADCOnDLS;
using CADCConfigOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CADCConfigOnDLS;
using CADCChannelType GENPYBIND(visible) = halco::hicann_dls::vx::CADCChannelType;
using CADCReadoutType GENPYBIND(visible) = halco::hicann_dls::vx::CADCReadoutType;
using CADCChannelColumnOnSynram GENPYBIND(visible) =
    halco::hicann_dls::vx::CADCChannelColumnOnSynram;
using CADCSampleRowOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CADCSampleRowOnDLS;
using CADCOffsetSRAMTimingConfigOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::CADCOffsetSRAMTimingConfigOnDLS;
using CADCSamplesOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CADCSamplesOnDLS;

HALCO_COORDINATE_MIXIN(CADCChannelTypeMixin, CADCChannelType, cadc_channel_type)

struct GENPYBIND(inline_base("*CADCChannelTypeMixin*")) CADCSampleQuadUnspecifiedReadoutOnSynram
    : public CADCChannelTypeMixin<CADCSampleQuadUnspecifiedReadoutOnSynram, SynapseQuadOnSynram>
{
	CADCSampleQuadUnspecifiedReadoutOnSynram() = default;

	explicit CADCSampleQuadUnspecifiedReadoutOnSynram(
	    SynapseQuadOnSynram const& quad, CADCChannelType const& cadc_channel_type) :
	    mixin_t(quad, cadc_channel_type)
	{}

	explicit CADCSampleQuadUnspecifiedReadoutOnSynram(enum_type const& e) : mixin_t(e) {}

	SynapseQuadOnSynram toSynapseQuadOnSynram() const
	{
		return This();
	}
};


HALCO_COORDINATE_MIXIN(CADCReadoutTypeMixin, CADCReadoutType, cadc_readout_type)

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

	CADCSampleQuadOnSynram toCADCSampleQuadOnSynram() const
	{
		return This();
	}

	SynapseQuadOnDLS toSynapseQuadOnDLS() const;
	SynapseWeightQuadOnDLS toSynapseWeightQuadOnDLS() const;
	SynapseLabelQuadOnDLS toSynapseLabelQuadOnDLS() const;
	SynapseCorrelationCalibQuadOnDLS toSynapseCorrelationCalibQuadOnDLS() const;
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

	CADCChannelColumnOnSynram toCADCChannelColumnOnSynram() const
	{
		return This();
	}
	SynapseOnSynapseRow toSynapseOnSynapseRow() const
	{
		return SynapseOnSynapseRow(int(toCADCChannelColumnOnSynram().toEnum()));
	}
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

	CADCChannelConfigOnSynram toCADCChannelConfigOnSynram() const
	{
		return This();
	}
	NeuronConfigBlockOnDLS toNeuronConfigBlockOnDLS() const;
};
