struct NeuronConfigOnDLS;
struct NeuronBackendConfigOnDLS;

using NeuronRowOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::NeuronRowOnDLS;
using NeuronConfigOnNeuronConfigBlock GENPYBIND(visible) =
    halco::hicann_dls::vx::NeuronConfigOnNeuronConfigBlock;
using NeuronConfigBlockOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::NeuronConfigBlockOnDLS;
using NeuronBackendConfigOnNeuronBackendConfigBlock GENPYBIND(visible) =
    halco::hicann_dls::vx::NeuronBackendConfigOnNeuronBackendConfigBlock;
using NeuronBackendConfigBlockOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::NeuronBackendConfigBlockOnDLS;
using CommonNeuronBackendConfigOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::CommonNeuronBackendConfigOnDLS;
using NeuronResetOnNeuronResetBlock GENPYBIND(visible) =
    halco::hicann_dls::vx::NeuronResetOnNeuronResetBlock;
using NeuronResetBlockOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::NeuronResetBlockOnDLS;
using NeuronResetOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::NeuronResetOnDLS;
using BlockPostPulseOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::BlockPostPulseOnDLS;
using SpikeCounterReadOnSpikeCounterReadBlock GENPYBIND(visible) =
    halco::hicann_dls::vx::SpikeCounterReadOnSpikeCounterReadBlock;
using SpikeCounterReadBlockOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::SpikeCounterReadBlockOnDLS;
using SpikeCounterReadOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SpikeCounterReadOnDLS;
using SpikeCounterResetOnSpikeCounterResetBlock GENPYBIND(visible) =
    halco::hicann_dls::vx::SpikeCounterResetOnSpikeCounterResetBlock;
using SpikeCounterResetBlockOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::SpikeCounterResetBlockOnDLS;
using SpikeCounterResetOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SpikeCounterResetOnDLS;
using NeuronEventOutputOnNeuronBackendBlock GENPYBIND(visible) =
    halco::hicann_dls::vx::NeuronEventOutputOnNeuronBackendBlock;
using NeuronEventOutputOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::NeuronEventOutputOnDLS;
using NeuronSRAMTimingConfigOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::NeuronSRAMTimingConfigOnDLS;
using NeuronBackendSRAMTimingConfigOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::NeuronBackendSRAMTimingConfigOnDLS;

/**
 * Horizontal neuron location on the two dimensional neuron grid.
 */
struct GENPYBIND(inline_base("*")) NeuronColumnOnDLS
    : public common::detail::RantWrapper<NeuronColumnOnDLS, uint_fast16_t, 255, 0>
    , public common::detail::XRangedTrait
{
	constexpr explicit NeuronColumnOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	SynapseOnSynapseRow toSynapseOnSynapseRow() const;
	CapMemColumnOnCapMemBlock toCapMemColumnOnCapMemBlock() const;
	NeuronEventOutputOnDLS toNeuronEventOutputOnDLS() const;
};

/**
 * DLS-global neuron location on the two dimensional neuron grid.
 */
struct GENPYBIND(inline_base("*")) AtomicNeuronOnDLS
    : public common::detail::GridCoordinate<AtomicNeuronOnDLS, NeuronColumnOnDLS, NeuronRowOnDLS>
{
	GRID_COMMON_CONSTRUCTORS(AtomicNeuronOnDLS)

	NeuronColumnOnDLS toNeuronColumnOnDLS() const
	{
		return x();
	}
	NeuronRowOnDLS toNeuronRowOnDLS() const
	{
		return y();
	}

	NeuronResetOnDLS toNeuronResetOnDLS() const;
	SpikeCounterReadOnDLS toSpikeCounterReadOnDLS() const;
	SpikeCounterResetOnDLS toSpikeCounterResetOnDLS() const;
	NeuronConfigOnDLS toNeuronConfigOnDLS() const;
	NeuronBackendConfigOnDLS toNeuronBackendConfigOnDLS() const;

	CapMemBlockOnDLS toCapMemBlockOnDLS() const;
	CapMemColumnOnCapMemBlock toCapMemColumnOnCapMemBlock() const;
	SynramOnDLS toSynramOnDLS() const;
	SynapseQuadColumnOnDLS toSynapseQuadColumnOnDLS() const;
	ColumnCorrelationQuadOnDLS toColumnCorrelationQuadOnDLS() const;
	ColumnCurrentQuadOnDLS toColumnCurrentQuadOnDLS() const;
};

HALCO_COORDINATE_MIXIN(NeuronConfigMixin, NeuronConfigBlockOnDLS, neuron)

struct GENPYBIND(inline_base("*NeuronConfigMixin*")) NeuronConfigOnDLS
    : public NeuronConfigMixin<NeuronConfigOnDLS, NeuronConfigOnNeuronConfigBlock>
{
	NeuronConfigOnDLS() = default;

	explicit NeuronConfigOnDLS(
	    NeuronConfigOnNeuronConfigBlock const& neuron,
	    NeuronConfigBlockOnDLS const& block = NeuronConfigBlockOnDLS()) :
	    mixin_t(neuron, block)
	{}

	explicit NeuronConfigOnDLS(enum_type const& e) : mixin_t(e) {}

	NeuronConfigOnNeuronConfigBlock toNeuronConfigOnNeuronConfigBlock() const
	{
		return This();
	}
	NeuronResetOnDLS toNeuronResetOnDLS() const;
	SpikeCounterReadOnDLS toSpikeCounterReadOnDLS() const;
	SpikeCounterResetOnDLS toSpikeCounterResetOnDLS() const;
	AtomicNeuronOnDLS toAtomicNeuronOnDLS() const;
	SynapseQuadColumnOnDLS toSynapseQuadColumnOnDLS() const;
	EntryOnQuad toEntryOnQuad() const;
	NeuronRowOnDLS toNeuronRowOnDLS() const;
	SynapseOnSynapseRow toSynapseOnSynapseRow() const;
	NeuronBackendConfigBlockOnDLS toNeuronBackendConfigBlockOnDLS() const;
	NeuronBackendConfigOnNeuronBackendConfigBlock toNeuronBackendConfigOnNeuronBackendConfigBlock()
	    const;
	CommonNeuronBackendConfigOnDLS toCommonNeuronBackendConfigOnDLS() const;
	NeuronBackendConfigOnDLS toNeuronBackendConfigOnDLS() const;
	SynramOnDLS toSynramOnDLS() const;
	ColumnCorrelationQuadOnDLS toColumnCorrelationQuadOnDLS() const;
	ColumnCurrentQuadOnDLS toColumnCurrentQuadOnDLS() const;
};

struct GENPYBIND(inline_base("*NeuronBackendConfigMixin*")) NeuronBackendConfigOnDLS
    : public NeuronBackendConfigMixin<
          NeuronBackendConfigOnDLS,
          NeuronBackendConfigOnNeuronBackendConfigBlock>
{
	NeuronBackendConfigOnDLS() = default;

	explicit NeuronBackendConfigOnDLS(
	    NeuronBackendConfigOnNeuronBackendConfigBlock const& neuron,
	    NeuronBackendConfigBlockOnDLS const& block = NeuronBackendConfigBlockOnDLS()) :
	    mixin_t(neuron, block)
	{}

	explicit NeuronBackendConfigOnDLS(enum_type const& e) : mixin_t(e) {}

	NeuronBackendConfigOnNeuronBackendConfigBlock toNeuronBackendConfigOnNeuronBackendConfigBlock()
	    const
	{
		return This();
	}

	NeuronColumnOnDLS toNeuronColumnOnDLS() const;
	NeuronRowOnDLS toNeuronRowOnDLS() const;
	CommonNeuronBackendConfigOnDLS toCommonNeuronBackendConfigOnDLS() const;
	SpikeCounterReadOnDLS toSpikeCounterReadOnDLS() const;
	SpikeCounterResetOnDLS toSpikeCounterResetOnDLS() const;
	NeuronConfigOnDLS toNeuronConfigOnDLS() const;
	AtomicNeuronOnDLS toAtomicNeuronOnDLS() const;
	SynramOnDLS toSynramOnDLS() const;
	NeuronConfigBlockOnDLS toNeuronConfigBlockOnDLS() const;
};

struct GENPYBIND(inline_base("*SynramMixin*")) NeuronResetQuadOnDLS
    : public SynramMixin<NeuronResetQuadOnDLS, SynapseQuadColumnOnDLS>
{
	NeuronResetQuadOnDLS() = default;

	explicit NeuronResetQuadOnDLS(
	    SynapseQuadColumnOnDLS const& quad, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(quad, synram)
	{}

	explicit NeuronResetQuadOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseQuadColumnOnDLS toSynapseQuadColumnOnDLS() const
	{
		return This();
	}
	typedef common::typed_array<NeuronResetOnDLS, EntryOnQuad> neuron_reset_type
	    GENPYBIND(opaque(false));
	neuron_reset_type toNeuronResetOnDLS() const;
};
