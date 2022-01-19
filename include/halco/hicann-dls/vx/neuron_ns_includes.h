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
using NeuronRowOnLogicalNeuron = halco::hicann_dls::vx::NeuronRowOnLogicalNeuron;


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


/**
 * Horizontal neuron location on a logical neuron.
 */
struct GENPYBIND(inline_base("*")) NeuronColumnOnLogicalNeuron
    : public common::detail::RantWrapper<
          NeuronColumnOnLogicalNeuron,
          uint_fast16_t,
          (NeuronColumnOnDLS::size / NeuronBackendConfigBlockOnDLS::size) - 1,
          0>
    , public common::detail::XRangedTrait
{
	constexpr explicit NeuronColumnOnLogicalNeuron(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


/**
 * Local neuron location on a logical neuron.
 */
struct GENPYBIND(inline_base("*")) AtomicNeuronOnLogicalNeuron
    : public common::detail::GridCoordinate<
          AtomicNeuronOnLogicalNeuron,
          NeuronColumnOnLogicalNeuron,
          NeuronRowOnLogicalNeuron>
{
	GRID_COMMON_CONSTRUCTORS(AtomicNeuronOnLogicalNeuron)

	NeuronColumnOnLogicalNeuron toNeuronColumnOnLogicalNeuron() const
	{
		return x();
	}
	NeuronRowOnLogicalNeuron toNeuronRowOnLogicalNeuron() const
	{
		return y();
	}

	enum class Direction
	{
		left,
		right,
		opposite_row
	};

	/**
	 * Get neighbor if it exists on the chip.
	 * @throws OverflowError if neighbor does not exist
	 * @return AtomicNeuronOnLogicalNeuron
	 */
	AtomicNeuronOnLogicalNeuron get_neighbor(Direction const& direction) const;
};


/**
 * Compartment index.
 * Its range is chosen such that the maximally possible number of compartments in a neuron backend
 * block can be created. This is size-2, because one compartment has to connect top and bottom row
 * and therefore consists of two atomic neuron circuits.
 */
struct GENPYBIND(inline_base("*")) CompartmentOnLogicalNeuron
    : public common::detail::RantWrapper<
          CompartmentOnLogicalNeuron,
          uint_fast16_t,
          (AtomicNeuronOnDLS::size / NeuronBackendConfigBlockOnDLS::size) - 2,
          0>
{
	constexpr explicit CompartmentOnLogicalNeuron(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


/**
 * Logical neuron compartments.
 */
struct GENPYBIND(visible) LogicalNeuronCompartments
{
	typedef std::vector<AtomicNeuronOnLogicalNeuron> Compartment;
	typedef std::map<CompartmentOnLogicalNeuron, Compartment> Compartments;

	LogicalNeuronCompartments() = default;
	/**
	 * Construct logical neuron compartments from compartments.
	 * The compartment members are to be unique.
	 * @param compartments Compartments to construct neuron from
	 */
	explicit LogicalNeuronCompartments(Compartments const& compartments);

	Compartments const& get_compartments() const;

	/**
	 * Flip locations in the x dimension.
	 * 1 2 3 4 becomes 4 3 2 1
	 * 5 6                 6 5
	 * @return Flipped compartments
	 */
	LogicalNeuronCompartments flip_x() const;

	/**
	 * Flip locations in the y dimension.
	 * 1 2 3 4 becomes 5 6
	 * 5 6             1 2 3 4
	 * @return Flipped compartments
	 */
	LogicalNeuronCompartments flip_y() const;

	NeuronColumnOnLogicalNeuron get_left_most_column() const;
	NeuronColumnOnLogicalNeuron get_right_most_column() const;

	NeuronRowOnLogicalNeuron get_top_most_row() const;
	NeuronRowOnLogicalNeuron get_bottom_most_row() const;

	bool operator==(LogicalNeuronCompartments const& other) const;
	bool operator!=(LogicalNeuronCompartments const& other) const;

	bool operator<(LogicalNeuronCompartments const& other) const;
	bool operator>(LogicalNeuronCompartments const& other) const;
	bool operator<=(LogicalNeuronCompartments const& other) const;
	bool operator>=(LogicalNeuronCompartments const& other) const;

	GENPYBIND(stringstream)
	friend std::ostream& operator<<(std::ostream& os, LogicalNeuronCompartments const& config);

private:
	friend class cereal::access;
	template <typename Archive>
	void serialize(Archive& ar, uint32_t);

	Compartments m_compartments;
};


/**
 * Logical neuron location on the neuron grid.
 */
struct GENPYBIND(visible) LogicalNeuronOnDLS
{
	typedef std::map<CompartmentOnLogicalNeuron, std::vector<AtomicNeuronOnDLS>> PlacedCompartments;

	LogicalNeuronOnDLS() = default;

	/**
	 * Construct logical neuron location from compartments and global anchor.
	 * The compartments' relative coordinates are anchored at the left top corner.
	 * @param compartments Compartments to construct neuron from
	 * @param anchor Anchor to construct neuron from
	 */
	LogicalNeuronOnDLS(
	    LogicalNeuronCompartments const& compartments, AtomicNeuronOnDLS const& anchor);

	/**
	 * Get compartments placed by anchor.
	 * @return Placed compartments
	 */
	PlacedCompartments get_placed_compartments() const;

	bool operator==(LogicalNeuronOnDLS const& other) const;
	bool operator!=(LogicalNeuronOnDLS const& other) const;

	GENPYBIND(stringstream)
	friend std::ostream& operator<<(std::ostream& os, LogicalNeuronOnDLS const& config);

	bool operator<(LogicalNeuronOnDLS const& other) const;
	bool operator>(LogicalNeuronOnDLS const& other) const;
	bool operator<=(LogicalNeuronOnDLS const& other) const;
	bool operator>=(LogicalNeuronOnDLS const& other) const;

private:
	friend class cereal::access;
	template <typename Archive>
	void serialize(Archive& ar, uint32_t);

	PlacedCompartments m_compartments;
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
