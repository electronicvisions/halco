struct ColumnCorrelationQuadOnSynram;
struct ColumnCurrentQuadOnSynram;
struct NeuronColumnOnDLS;
struct SynapseQuadOnDLS;
struct SynapseWeightQuadOnDLS;
struct SynapseLabelQuadOnDLS;
struct SynapseCorrelationCalibQuadOnDLS;

using SynapseRowOnSynapseDriver GENPYBIND(visible) =
    halco::hicann_dls::vx::SynapseRowOnSynapseDriver;
using SynapseRowOnSynram GENPYBIND(visible) = halco::hicann_dls::vx::SynapseRowOnSynram;
using SynapseRowOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SynapseRowOnDLS;
using SynapseWeightRowOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SynapseWeightRowOnDLS;
using SynapseLabelRowOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SynapseLabelRowOnDLS;
using SynapseCorrelationCalibRowOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::SynapseCorrelationCalibRowOnDLS;
using CorrelationResetRowOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CorrelationResetRowOnDLS;
using SynapticInputOnNeuron GENPYBIND(visible) = halco::hicann_dls::vx::SynapticInputOnNeuron;
using SynapseBiasSelectionOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::SynapseBiasSelectionOnDLS;
using SynapseWeightMatrixOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SynapseWeightMatrixOnDLS;
using SynapseLabelMatrixOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SynapseLabelMatrixOnDLS;
using SynapseCorrelationCalibMatrixOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::SynapseCorrelationCalibMatrixOnDLS;

struct GENPYBIND(inline_base("*")) SynapseQuadColumnOnDLS
    : public common::detail::RantWrapper<SynapseQuadColumnOnDLS, uint_fast16_t, 63, 0>
    , public common::detail::XRangedTrait
{
	constexpr explicit SynapseQuadColumnOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	constexpr explicit SynapseQuadColumnOnDLS(common::X const& x) GENPYBIND(implicit_conversion) :
	    rant_t(x)
	{}

	ColumnCorrelationQuadOnSynram toColumnCorrelationQuadOnSynram() const;
	ColumnCurrentQuadOnSynram toColumnCurrentQuadOnSynram() const;
	common::typed_array<NeuronColumnOnDLS, EntryOnQuad> toNeuronColumnOnDLS() const;
};

struct GENPYBIND(inline_base("*")) SynapseQuadOnSynram
    : public common::detail::
          GridCoordinate<SynapseQuadOnSynram, SynapseQuadColumnOnDLS, SynapseRowOnSynram>
{
	GRID_COMMON_CONSTRUCTORS(SynapseQuadOnSynram)

	SynapseQuadColumnOnDLS toSynapseQuadColumnOnDLS() const
	{
		return x();
	}
	SynapseRowOnSynram toSynapseRowOnSynram() const
	{
		return y();
	}
};

struct GENPYBIND(inline_base("*SynramMixin*")) SynapseQuadOnDLS
    : public SynramMixin<SynapseQuadOnDLS, SynapseQuadOnSynram>
{
	SynapseQuadOnDLS() = default;

	explicit SynapseQuadOnDLS(
	    SynapseQuadOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit SynapseQuadOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseQuadOnSynram toSynapseQuadOnSynram() const
	{
		return This();
	}

	NeuronConfigBlockOnDLS toNeuronConfigBlockOnDLS() const;
	SynapseWeightQuadOnDLS toSynapseWeightQuadOnDLS() const;
	SynapseLabelQuadOnDLS toSynapseLabelQuadOnDLS() const;
	SynapseCorrelationCalibQuadOnDLS toSynapseCorrelationCalibQuadOnDLS() const;
};

struct GENPYBIND(inline_base("*SynramMixin*")) CorrelationResetOnDLS
    : public SynramMixin<CorrelationResetOnDLS, SynapseQuadOnSynram>
{
	CorrelationResetOnDLS() = default;

	explicit CorrelationResetOnDLS(
	    SynapseQuadOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit CorrelationResetOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseQuadOnSynram toSynapseQuadOnSynram() const
	{
		return This();
	}
};

struct GENPYBIND(inline_base("*SynramMixin*")) SynapseWeightQuadOnDLS
    : public SynramMixin<SynapseWeightQuadOnDLS, SynapseQuadOnSynram>
{
	SynapseWeightQuadOnDLS() = default;

	explicit SynapseWeightQuadOnDLS(
	    SynapseQuadOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit SynapseWeightQuadOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseQuadOnSynram toSynapseQuadOnSynram() const
	{
		return This();
	}

	NeuronConfigBlockOnDLS toNeuronConfigBlockOnDLS() const;
	SynapseQuadOnDLS toSynapseQuadOnDLS() const;
	SynapseLabelQuadOnDLS toSynapseLabelQuadOnDLS() const;
	SynapseCorrelationCalibQuadOnDLS toSynapseCorrelationCalibQuadOnDLS() const;
};


struct GENPYBIND(inline_base("*SynramMixin*")) SynapseLabelQuadOnDLS
    : public SynramMixin<SynapseLabelQuadOnDLS, SynapseQuadOnSynram>
{
	SynapseLabelQuadOnDLS() = default;

	explicit SynapseLabelQuadOnDLS(
	    SynapseQuadOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit SynapseLabelQuadOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseQuadOnSynram toSynapseQuadOnSynram() const
	{
		return This();
	}

	NeuronConfigBlockOnDLS toNeuronConfigBlockOnDLS() const;
	SynapseWeightQuadOnDLS toSynapseWeightQuadOnDLS() const;
	SynapseQuadOnDLS toSynapseQuadOnDLS() const;
	SynapseCorrelationCalibQuadOnDLS toSynapseCorrelationCalibQuadOnDLS() const;
};


struct GENPYBIND(inline_base("*SynramMixin*")) SynapseCorrelationCalibQuadOnDLS
    : public SynramMixin<SynapseCorrelationCalibQuadOnDLS, SynapseQuadOnSynram>
{
	SynapseCorrelationCalibQuadOnDLS() = default;

	explicit SynapseCorrelationCalibQuadOnDLS(
	    SynapseQuadOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit SynapseCorrelationCalibQuadOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseQuadOnSynram toSynapseQuadOnSynram() const
	{
		return This();
	}

	NeuronConfigBlockOnDLS toNeuronConfigBlockOnDLS() const;
	SynapseWeightQuadOnDLS toSynapseWeightQuadOnDLS() const;
	SynapseLabelQuadOnDLS toSynapseLabelQuadOnDLS() const;
	SynapseQuadOnDLS toSynapseQuadOnDLS() const;
};
