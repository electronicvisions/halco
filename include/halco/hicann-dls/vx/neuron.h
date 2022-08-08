#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"
#include "halco/common/typed_array.h"

#include "halco/hicann-dls/vx/quad.h"
#include "halco/hicann-dls/vx/synapse.h"
#include "halco/hicann-dls/vx/synram.h"

namespace cereal {
struct access;
} // namespace cereal

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

#include "halco/hicann-dls/vx/hemisphere_fwd.h"
struct CapMemColumnOnCapMemBlock;
struct CapMemBlockOnDLS;
struct NeuronResetBlockOnDLS;
struct NeuronResetOnDLS;
struct SpikeCounterReadBlockOnDLS;
struct SpikeCounterReadOnDLS;
struct SpikeCounterResetBlockOnDLS;
struct SpikeCounterResetOnDLS;
struct SynapseOnSynapseRow;
struct NeuronEventOutputOnNeuronBackendBlock;
struct NeuronEventOutputOnDLS;
struct CrossbarInputOnDLS;
struct NeuronBackendConfigBlockOnDLS;
struct BlockPostPulseOnDLS;
struct ColumnCorrelationQuadOnDLS;
struct ColumnCurrentQuadOnDLS;
struct NeuronConfigOnDLS;
struct NeuronBackendConfigOnDLS;

/**********\
   Neuron
\**********/

/**
 * Vertical neuron location on the two dimensional neuron grid.
 */
struct GENPYBIND(inline_base("*")) NeuronRowOnDLS
    : public common::detail::RantWrapper<NeuronRowOnDLS, uint_fast16_t, 1, 0>
    , public common::detail::YRangedTrait
{
	constexpr explicit NeuronRowOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const NeuronRowOnDLS top;
	static const NeuronRowOnDLS bottom;
};


struct GENPYBIND(inline_base("*")) NeuronConfigOnNeuronConfigBlock
    : public common::detail::RantWrapper<NeuronConfigOnNeuronConfigBlock, uint_fast16_t, 127, 0>
{
	constexpr explicit NeuronConfigOnNeuronConfigBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CapMemColumnOnCapMemBlock toCapMemColumnOnCapMemBlock() const;
};


struct GENPYBIND(inline_base("*")) NeuronConfigBlockOnDLS
    : public common::detail::RantWrapper<NeuronConfigBlockOnDLS, uint_fast16_t, 3, 0>
{
	constexpr explicit NeuronConfigBlockOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CapMemBlockOnDLS toCapMemBlockOnDLS() const;
	NeuronResetBlockOnDLS toNeuronResetBlockOnDLS() const;
	SpikeCounterReadBlockOnDLS toSpikeCounterReadBlockOnDLS() const;
	SpikeCounterResetBlockOnDLS toSpikeCounterResetBlockOnDLS() const;
};


struct GENPYBIND(inline_base("*")) NeuronBackendConfigOnNeuronBackendConfigBlock
    : public common::detail::
          RantWrapper<NeuronBackendConfigOnNeuronBackendConfigBlock, uint_fast16_t, 255, 0>
{
	constexpr explicit NeuronBackendConfigOnNeuronBackendConfigBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	NeuronEventOutputOnNeuronBackendBlock toNeuronEventOutputOnNeuronBackendBlock() const;
};

struct GENPYBIND(inline_base("*")) CommonNeuronBackendConfigOnDLS
    : public common::detail::RantWrapper<CommonNeuronBackendConfigOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit CommonNeuronBackendConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	NeuronBackendConfigBlockOnDLS toNeuronBackendConfigBlockOnDLS() const;
};

struct GENPYBIND(inline_base("*")) NeuronBackendConfigBlockOnDLS
    : public common::detail::RantWrapper<NeuronBackendConfigBlockOnDLS, uint_fast8_t, 1, 0>
{
	constexpr explicit NeuronBackendConfigBlockOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	BlockPostPulseOnDLS toBlockPostPulseOnDLS() const;
	CommonNeuronBackendConfigOnDLS toCommonNeuronBackendConfigOnDLS() const;
};


struct GENPYBIND(inline_base("*")) NeuronResetOnNeuronResetBlock
    : public common::detail::RantWrapper<NeuronResetOnNeuronResetBlock, uint_fast16_t, 255, 0>
{
	constexpr explicit NeuronResetOnNeuronResetBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) NeuronResetBlockOnDLS
    : public common::detail::RantWrapper<NeuronResetBlockOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit NeuronResetBlockOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) BlockPostPulseOnDLS
    : public common::detail::RantWrapper<BlockPostPulseOnDLS, uint_fast8_t, 1, 0>
{
	constexpr explicit BlockPostPulseOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	NeuronBackendConfigBlockOnDLS toNeuronBackendConfigBlockOnDLS() const;
};


struct GENPYBIND(inline_base("*")) SpikeCounterReadOnSpikeCounterReadBlock
    : public common::detail::
          RantWrapper<SpikeCounterReadOnSpikeCounterReadBlock, uint_fast16_t, 255, 0>
{
	constexpr explicit SpikeCounterReadOnSpikeCounterReadBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) SpikeCounterReadBlockOnDLS
    : public common::detail::RantWrapper<SpikeCounterReadBlockOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit SpikeCounterReadBlockOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) SpikeCounterResetOnSpikeCounterResetBlock
    : public common::detail::
          RantWrapper<SpikeCounterResetOnSpikeCounterResetBlock, uint_fast16_t, 255, 0>
{
	constexpr explicit SpikeCounterResetOnSpikeCounterResetBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) SpikeCounterResetBlockOnDLS
    : public common::detail::RantWrapper<SpikeCounterResetBlockOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit SpikeCounterResetBlockOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) NeuronEventOutputOnNeuronBackendBlock
    : public common::detail::RantWrapper<NeuronEventOutputOnNeuronBackendBlock, uint_fast16_t, 3, 0>
{
	constexpr explicit NeuronEventOutputOnNeuronBackendBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

HALCO_COORDINATE_MIXIN(NeuronBackendConfigMixin, NeuronBackendConfigBlockOnDLS, neuron_backend)

struct GENPYBIND(inline_base("*NeuronBackendConfigMixin*")) NeuronEventOutputOnDLS
    : public NeuronBackendConfigMixin<NeuronEventOutputOnDLS, NeuronEventOutputOnNeuronBackendBlock>
{
	NeuronEventOutputOnDLS() = default;

	explicit NeuronEventOutputOnDLS(
	    NeuronEventOutputOnNeuronBackendBlock const& output,
	    NeuronBackendConfigBlockOnDLS const& block = NeuronBackendConfigBlockOnDLS()) :
	    mixin_t(output, block)
	{}

	explicit NeuronEventOutputOnDLS(enum_type const& e) : mixin_t(e) {}

	NeuronEventOutputOnNeuronBackendBlock toNeuronEventOutputOnNeuronBackendBlock() const
	{
		return This();
	}

	CrossbarInputOnDLS toCrossbarInputOnDLS() const;
};

HALCO_COORDINATE_MIXIN(NeuronResetMixin, NeuronResetBlockOnDLS, neuron)

struct GENPYBIND(inline_base("*NeuronResetMixin*")) NeuronResetOnDLS
    : public NeuronResetMixin<NeuronResetOnDLS, NeuronResetOnNeuronResetBlock>
{
	NeuronResetOnDLS() = default;

	explicit NeuronResetOnDLS(
	    NeuronResetOnNeuronResetBlock const& neuron,
	    NeuronResetBlockOnDLS const& block = NeuronResetBlockOnDLS()) :
	    mixin_t(neuron, block)
	{}

	explicit NeuronResetOnDLS(enum_type const& e) : mixin_t(e) {}

	NeuronResetOnNeuronResetBlock toNeuronResetOnNeuronResetBlock() const { return This(); }
};


HALCO_COORDINATE_MIXIN(SpikeCounterReadMixin, SpikeCounterReadBlockOnDLS, neuron)

struct GENPYBIND(inline_base("*SpikeCounterReadMixin*")) SpikeCounterReadOnDLS
    : public SpikeCounterReadMixin<SpikeCounterReadOnDLS, SpikeCounterReadOnSpikeCounterReadBlock>
{
	SpikeCounterReadOnDLS() = default;

	explicit SpikeCounterReadOnDLS(
	    SpikeCounterReadOnSpikeCounterReadBlock const& neuron,
	    SpikeCounterReadBlockOnDLS const& block = SpikeCounterReadBlockOnDLS()) :
	    mixin_t(neuron, block)
	{}

	explicit SpikeCounterReadOnDLS(enum_type const& e) : mixin_t(e) {}

	SpikeCounterReadOnSpikeCounterReadBlock toSpikeCounterReadOnSpikeCounterReadBlock() const
	{
		return This();
	}
};


HALCO_COORDINATE_MIXIN(SpikeCounterResetMixin, SpikeCounterResetBlockOnDLS, neuron)

struct GENPYBIND(inline_base("*SpikeCounterResetMixin*")) SpikeCounterResetOnDLS
    : public SpikeCounterResetMixin<
          SpikeCounterResetOnDLS,
          SpikeCounterResetOnSpikeCounterResetBlock>
{
	SpikeCounterResetOnDLS() = default;

	explicit SpikeCounterResetOnDLS(
	    SpikeCounterResetOnSpikeCounterResetBlock const& neuron,
	    SpikeCounterResetBlockOnDLS const& block = SpikeCounterResetBlockOnDLS()) :
	    mixin_t(neuron, block)
	{}

	explicit SpikeCounterResetOnDLS(enum_type const& e) : mixin_t(e) {}

	SpikeCounterResetOnSpikeCounterResetBlock toSpikeCounterResetOnSpikeCounterResetBlock() const
	{
		return This();
	}
};


struct GENPYBIND(inline_base("*")) NeuronSRAMTimingConfigOnDLS
    : public common::detail::RantWrapper<NeuronSRAMTimingConfigOnDLS, uint_fast16_t, 3, 0>
{
	constexpr explicit NeuronSRAMTimingConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) NeuronBackendSRAMTimingConfigOnDLS
    : public common::detail::RantWrapper<NeuronBackendSRAMTimingConfigOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit NeuronBackendSRAMTimingConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


/**
 * Vertical neuron location on a logical neuron.
 */
struct GENPYBIND(inline_base("*")) NeuronRowOnLogicalNeuron
    : public common::detail::RantWrapper<
          NeuronRowOnLogicalNeuron,
          uint_fast16_t,
          NeuronRowOnDLS::max,
          NeuronRowOnDLS::min>
    , public common::detail::YRangedTrait
{
	constexpr explicit NeuronRowOnLogicalNeuron(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) NeuronBlockOnDLS
    : public common::detail::RantWrapper<NeuronBlockOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit NeuronBlockOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


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
	friend struct cereal::access;
	template <typename Archive>
	void serialize(Archive& ar, uint32_t);

	Compartments m_compartments;
};


/**
 * Logical neuron location on the neuron grid.
 */
struct GENPYBIND(visible) LogicalNeuronOnDLS
{
	typedef std::vector<AtomicNeuronOnDLS> AtomicNeuronList;
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

	/**
	 * Get all AtomicNeuronOnDLS which are involved in this logical neuron.
	 * @return List of AtomicNeuronOnDLS which are part of the logical neuron.
	 */
	AtomicNeuronList get_atomic_neurons() const;

	bool operator==(LogicalNeuronOnDLS const& other) const;
	bool operator!=(LogicalNeuronOnDLS const& other) const;

	GENPYBIND(stringstream)
	friend std::ostream& operator<<(std::ostream& os, LogicalNeuronOnDLS const& config);

	bool operator<(LogicalNeuronOnDLS const& other) const;
	bool operator>(LogicalNeuronOnDLS const& other) const;
	bool operator<=(LogicalNeuronOnDLS const& other) const;
	bool operator>=(LogicalNeuronOnDLS const& other) const;

private:
	friend struct cereal::access;
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

/**
 * Address of the spikes sent out by a neuron.
 */
struct GENPYBIND(inline_base("*")) NeuronBackendAddressOut
    : public halco::common::detail::RantWrapper<NeuronBackendAddressOut, uint_fast16_t, 255, 0>
{
	constexpr explicit NeuronBackendAddressOut(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronRowOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronConfigOnNeuronConfigBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronConfigBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonNeuronBackendConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronBackendConfigOnNeuronBackendConfigBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronBackendConfigBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronEventOutputOnNeuronBackendBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronEventOutputOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronResetOnNeuronResetBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronResetBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronResetOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::BlockPostPulseOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikeCounterReadOnSpikeCounterReadBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikeCounterReadBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikeCounterReadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikeCounterResetOnSpikeCounterResetBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikeCounterResetBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikeCounterResetOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronSRAMTimingConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronBackendSRAMTimingConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronRowOnLogicalNeuron)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronColumnOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::AtomicNeuronOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronColumnOnLogicalNeuron)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::AtomicNeuronOnLogicalNeuron)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CompartmentOnLogicalNeuron)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronBackendConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronResetQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronBackendAddressOut)

} // namespace std
