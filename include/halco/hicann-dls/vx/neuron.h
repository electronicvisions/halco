#pragma once
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"
#include "halco/common/typed_array.h"

#include "halco/hicann-dls/vx/quad.h"
#include "halco/hicann-dls/vx/synapse.h"
#include "halco/hicann-dls/vx/synram.h"

#include "hate/visibility.h"

namespace cereal {
struct access;
class JSONOutputArchive;
class JSONInputArchive;
class PortableBinaryOutputArchive;
class PortableBinaryInputArchive;
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

	static const SYMBOL_VISIBLE NeuronRowOnDLS top;
	static const SYMBOL_VISIBLE NeuronRowOnDLS bottom;
};


struct GENPYBIND(inline_base("*")) NeuronConfigOnNeuronConfigBlock
    : public common::detail::RantWrapper<NeuronConfigOnNeuronConfigBlock, uint_fast16_t, 127, 0>
{
	constexpr explicit NeuronConfigOnNeuronConfigBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CapMemColumnOnCapMemBlock toCapMemColumnOnCapMemBlock() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    NeuronConfigBlockOnDLS
    : public common::detail::RantWrapper<NeuronConfigBlockOnDLS, uint_fast16_t, 3, 0>
    , common::CoordinateBase<NeuronConfigBlockOnDLS>
{
	constexpr explicit NeuronConfigBlockOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CapMemBlockOnDLS toCapMemBlockOnDLS() const SYMBOL_VISIBLE;
	NeuronResetBlockOnDLS toNeuronResetBlockOnDLS() const SYMBOL_VISIBLE;
	SpikeCounterReadBlockOnDLS toSpikeCounterReadBlockOnDLS() const SYMBOL_VISIBLE;
	SpikeCounterResetBlockOnDLS toSpikeCounterResetBlockOnDLS() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*")) NeuronBackendConfigOnNeuronBackendConfigBlock
    : public common::detail::
          RantWrapper<NeuronBackendConfigOnNeuronBackendConfigBlock, uint_fast16_t, 255, 0>
{
	constexpr explicit NeuronBackendConfigOnNeuronBackendConfigBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	NeuronEventOutputOnNeuronBackendBlock toNeuronEventOutputOnNeuronBackendBlock() const
	    SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    CommonNeuronBackendConfigOnDLS
    : public common::detail::RantWrapper<CommonNeuronBackendConfigOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<CommonNeuronBackendConfigOnDLS>
{
	constexpr explicit CommonNeuronBackendConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	NeuronBackendConfigBlockOnDLS toNeuronBackendConfigBlockOnDLS() const SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    NeuronBackendConfigBlockOnDLS
    : public common::detail::RantWrapper<NeuronBackendConfigBlockOnDLS, uint_fast8_t, 1, 0>
    , common::CoordinateBase<NeuronBackendConfigBlockOnDLS>
{
	constexpr explicit NeuronBackendConfigBlockOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	BlockPostPulseOnDLS toBlockPostPulseOnDLS() const SYMBOL_VISIBLE;
	CommonNeuronBackendConfigOnDLS toCommonNeuronBackendConfigOnDLS() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*")) NeuronResetOnNeuronResetBlock
    : public common::detail::RantWrapper<NeuronResetOnNeuronResetBlock, uint_fast16_t, 255, 0>
{
	constexpr explicit NeuronResetOnNeuronResetBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    NeuronResetBlockOnDLS
    : public common::detail::RantWrapper<NeuronResetBlockOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<NeuronResetBlockOnDLS>
{
	constexpr explicit NeuronResetBlockOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) BlockPostPulseOnDLS
    : public common::detail::RantWrapper<BlockPostPulseOnDLS, uint_fast8_t, 1, 0>
    , common::CoordinateBase<BlockPostPulseOnDLS>
{
	constexpr explicit BlockPostPulseOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	NeuronBackendConfigBlockOnDLS toNeuronBackendConfigBlockOnDLS() const SYMBOL_VISIBLE;
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

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    SpikeCounterReadBlockOnDLS
    : public common::detail::RantWrapper<SpikeCounterReadBlockOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<SpikeCounterReadBlockOnDLS>
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

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    SpikeCounterResetBlockOnDLS
    : public common::detail::RantWrapper<SpikeCounterResetBlockOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<SpikeCounterResetBlockOnDLS>
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

struct GENPYBIND(inline_base("*NeuronBackendConfigMixin*"), inline_base("*CoordinateBase*"))
    NeuronEventOutputOnDLS
    : public NeuronBackendConfigMixin<NeuronEventOutputOnDLS, NeuronEventOutputOnNeuronBackendBlock>
    , common::CoordinateBase<NeuronEventOutputOnDLS>
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

	CrossbarInputOnDLS toCrossbarInputOnDLS() const SYMBOL_VISIBLE;
};

HALCO_COORDINATE_MIXIN(NeuronResetMixin, NeuronResetBlockOnDLS, neuron)

struct GENPYBIND(inline_base("*NeuronResetMixin*"), inline_base("*CoordinateBase*"))
    NeuronResetOnDLS
    : public NeuronResetMixin<NeuronResetOnDLS, NeuronResetOnNeuronResetBlock>
    , public halco::common::CoordinateBase<NeuronResetOnDLS>
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

struct GENPYBIND(inline_base("*SpikeCounterReadMixin*"), inline_base("*CoordinateBase*"))
    SpikeCounterReadOnDLS
    : public SpikeCounterReadMixin<SpikeCounterReadOnDLS, SpikeCounterReadOnSpikeCounterReadBlock>
    , common::CoordinateBase<SpikeCounterReadOnDLS>
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

struct GENPYBIND(inline_base("*SpikeCounterResetMixin*"), inline_base("*CoordinateBase*"))
    SpikeCounterResetOnDLS
    : public SpikeCounterResetMixin<
          SpikeCounterResetOnDLS,
          SpikeCounterResetOnSpikeCounterResetBlock>
    , common::CoordinateBase<SpikeCounterResetOnDLS>
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


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    NeuronSRAMTimingConfigOnDLS
    : public common::detail::RantWrapper<NeuronSRAMTimingConfigOnDLS, uint_fast16_t, 3, 0>
    , common::CoordinateBase<NeuronSRAMTimingConfigOnDLS>
{
	constexpr explicit NeuronSRAMTimingConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    NeuronBackendSRAMTimingConfigOnDLS
    : public common::detail::RantWrapper<NeuronBackendSRAMTimingConfigOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<NeuronBackendSRAMTimingConfigOnDLS>
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


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) NeuronBlockOnDLS
    : public common::detail::RantWrapper<NeuronBlockOnDLS, uint_fast16_t, 0, 0>
    , common::CoordinateBase<NeuronBlockOnDLS>
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

	SynapseOnSynapseRow toSynapseOnSynapseRow() const SYMBOL_VISIBLE;
	CapMemColumnOnCapMemBlock toCapMemColumnOnCapMemBlock() const SYMBOL_VISIBLE;
	NeuronEventOutputOnDLS toNeuronEventOutputOnDLS() const SYMBOL_VISIBLE;
};

/**
 * DLS-global neuron location on the two dimensional neuron grid.
 */
struct GENPYBIND(inline_base("*GridCoordinate*"), inline_base("*CoordinateBase*")) AtomicNeuronOnDLS
    : public common::detail::GridCoordinate<AtomicNeuronOnDLS, NeuronColumnOnDLS, NeuronRowOnDLS>
    , common::CoordinateBase<AtomicNeuronOnDLS>
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

	NeuronResetOnDLS toNeuronResetOnDLS() const SYMBOL_VISIBLE;
	SpikeCounterReadOnDLS toSpikeCounterReadOnDLS() const SYMBOL_VISIBLE;
	SpikeCounterResetOnDLS toSpikeCounterResetOnDLS() const SYMBOL_VISIBLE;
	NeuronConfigOnDLS toNeuronConfigOnDLS() const SYMBOL_VISIBLE;
	NeuronBackendConfigOnDLS toNeuronBackendConfigOnDLS() const SYMBOL_VISIBLE;

	CapMemBlockOnDLS toCapMemBlockOnDLS() const SYMBOL_VISIBLE;
	CapMemColumnOnCapMemBlock toCapMemColumnOnCapMemBlock() const SYMBOL_VISIBLE;
	SynramOnDLS toSynramOnDLS() const SYMBOL_VISIBLE;
	SynapseQuadColumnOnDLS toSynapseQuadColumnOnDLS() const SYMBOL_VISIBLE;
	ColumnCorrelationQuadOnDLS toColumnCorrelationQuadOnDLS() const SYMBOL_VISIBLE;
	ColumnCurrentQuadOnDLS toColumnCurrentQuadOnDLS() const SYMBOL_VISIBLE;
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
	AtomicNeuronOnLogicalNeuron get_neighbor(Direction const& direction) const SYMBOL_VISIBLE;
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
	explicit LogicalNeuronCompartments(Compartments const& compartments) SYMBOL_VISIBLE;

	Compartments const& get_compartments() const SYMBOL_VISIBLE;

	/**
	 * Flip locations in the x dimension.
	 * 1 2 3 4 becomes 4 3 2 1
	 * 5 6                 6 5
	 * @return Flipped compartments
	 */
	LogicalNeuronCompartments flip_x() const SYMBOL_VISIBLE;

	/**
	 * Flip locations in the y dimension.
	 * 1 2 3 4 becomes 5 6
	 * 5 6             1 2 3 4
	 * @return Flipped compartments
	 */
	LogicalNeuronCompartments flip_y() const SYMBOL_VISIBLE;

	NeuronColumnOnLogicalNeuron get_left_most_column() const SYMBOL_VISIBLE;
	NeuronColumnOnLogicalNeuron get_right_most_column() const SYMBOL_VISIBLE;

	NeuronRowOnLogicalNeuron get_top_most_row() const SYMBOL_VISIBLE;
	NeuronRowOnLogicalNeuron get_bottom_most_row() const SYMBOL_VISIBLE;

	bool operator==(LogicalNeuronCompartments const& other) const SYMBOL_VISIBLE;
	bool operator!=(LogicalNeuronCompartments const& other) const SYMBOL_VISIBLE;

	bool operator<(LogicalNeuronCompartments const& other) const SYMBOL_VISIBLE;
	bool operator>(LogicalNeuronCompartments const& other) const SYMBOL_VISIBLE;
	bool operator<=(LogicalNeuronCompartments const& other) const SYMBOL_VISIBLE;
	bool operator>=(LogicalNeuronCompartments const& other) const SYMBOL_VISIBLE;

	GENPYBIND(stringstream)
	friend std::ostream& operator<<(std::ostream& os, LogicalNeuronCompartments const& config)
	    SYMBOL_VISIBLE;

private:
	friend struct cereal::access;
	template <typename Archive>
	void serialize(Archive& ar, uint32_t);

	Compartments m_compartments;
};


struct LogicalNeuronOnDLS;
size_t hash_value(LogicalNeuronOnDLS const& ln);
/**
 * Logical neuron location on the neuron grid.
 */
struct GENPYBIND(inline_base("*CoordinateBase*")) LogicalNeuronOnDLS
    : common::CoordinateBase<LogicalNeuronOnDLS>
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
	    LogicalNeuronCompartments const& compartments,
	    AtomicNeuronOnDLS const& anchor) SYMBOL_VISIBLE;

	/**
	 * Get compartments placed by anchor.
	 * @return Placed compartments
	 */
	PlacedCompartments get_placed_compartments() const SYMBOL_VISIBLE;

	/**
	 * Get all AtomicNeuronOnDLS which are involved in this logical neuron.
	 * @return List of AtomicNeuronOnDLS which are part of the logical neuron.
	 */
	AtomicNeuronList get_atomic_neurons() const SYMBOL_VISIBLE;

	bool operator==(LogicalNeuronOnDLS const& other) const SYMBOL_VISIBLE;
	bool operator!=(LogicalNeuronOnDLS const& other) const SYMBOL_VISIBLE;

	GENPYBIND(stringstream)
	friend std::ostream& operator<<(std::ostream& os, LogicalNeuronOnDLS const& config)
	    SYMBOL_VISIBLE;

	friend size_t hash_value(LogicalNeuronOnDLS const& ln) SYMBOL_VISIBLE;

	GENPYBIND(expose_as(__hash__))
	size_t hash() const SYMBOL_VISIBLE;

	bool operator<(LogicalNeuronOnDLS const& other) const SYMBOL_VISIBLE;
	bool operator>(LogicalNeuronOnDLS const& other) const SYMBOL_VISIBLE;
	bool operator<=(LogicalNeuronOnDLS const& other) const SYMBOL_VISIBLE;
	bool operator>=(LogicalNeuronOnDLS const& other) const SYMBOL_VISIBLE;

private:
	friend struct cereal::access;
	template <typename Archive>
	void serialize(Archive& ar, uint32_t);

	PlacedCompartments m_compartments;
};


HALCO_COORDINATE_MIXIN(NeuronConfigMixin, NeuronConfigBlockOnDLS, neuron)

struct GENPYBIND(inline_base("*NeuronConfigMixin*"), inline_base("*CoordinateBase*"))
    NeuronConfigOnDLS
    : public NeuronConfigMixin<NeuronConfigOnDLS, NeuronConfigOnNeuronConfigBlock>
    , common::CoordinateBase<NeuronConfigOnDLS>
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
	NeuronResetOnDLS toNeuronResetOnDLS() const SYMBOL_VISIBLE;
	SpikeCounterReadOnDLS toSpikeCounterReadOnDLS() const SYMBOL_VISIBLE;
	SpikeCounterResetOnDLS toSpikeCounterResetOnDLS() const SYMBOL_VISIBLE;
	AtomicNeuronOnDLS toAtomicNeuronOnDLS() const SYMBOL_VISIBLE;
	SynapseQuadColumnOnDLS toSynapseQuadColumnOnDLS() const SYMBOL_VISIBLE;
	EntryOnQuad toEntryOnQuad() const SYMBOL_VISIBLE;
	NeuronRowOnDLS toNeuronRowOnDLS() const SYMBOL_VISIBLE;
	SynapseOnSynapseRow toSynapseOnSynapseRow() const SYMBOL_VISIBLE;
	NeuronBackendConfigBlockOnDLS toNeuronBackendConfigBlockOnDLS() const SYMBOL_VISIBLE;
	NeuronBackendConfigOnNeuronBackendConfigBlock toNeuronBackendConfigOnNeuronBackendConfigBlock()
	    const SYMBOL_VISIBLE;
	CommonNeuronBackendConfigOnDLS toCommonNeuronBackendConfigOnDLS() const SYMBOL_VISIBLE;
	NeuronBackendConfigOnDLS toNeuronBackendConfigOnDLS() const SYMBOL_VISIBLE;
	SynramOnDLS toSynramOnDLS() const SYMBOL_VISIBLE;
	ColumnCorrelationQuadOnDLS toColumnCorrelationQuadOnDLS() const SYMBOL_VISIBLE;
	ColumnCurrentQuadOnDLS toColumnCurrentQuadOnDLS() const SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*NeuronBackendConfigMixin*"), inline_base("*CoordinateBase*"))
    NeuronBackendConfigOnDLS
    : public NeuronBackendConfigMixin<
          NeuronBackendConfigOnDLS,
          NeuronBackendConfigOnNeuronBackendConfigBlock>
    , common::CoordinateBase<NeuronBackendConfigOnDLS>
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

	NeuronColumnOnDLS toNeuronColumnOnDLS() const SYMBOL_VISIBLE;
	NeuronRowOnDLS toNeuronRowOnDLS() const SYMBOL_VISIBLE;
	CommonNeuronBackendConfigOnDLS toCommonNeuronBackendConfigOnDLS() const SYMBOL_VISIBLE;
	SpikeCounterReadOnDLS toSpikeCounterReadOnDLS() const SYMBOL_VISIBLE;
	SpikeCounterResetOnDLS toSpikeCounterResetOnDLS() const SYMBOL_VISIBLE;
	NeuronConfigOnDLS toNeuronConfigOnDLS() const SYMBOL_VISIBLE;
	AtomicNeuronOnDLS toAtomicNeuronOnDLS() const SYMBOL_VISIBLE;
	SynramOnDLS toSynramOnDLS() const SYMBOL_VISIBLE;
	NeuronConfigBlockOnDLS toNeuronConfigBlockOnDLS() const SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*SynramMixin*"), inline_base("*CoordinateBase*")) NeuronResetQuadOnDLS
    : public SynramMixin<NeuronResetQuadOnDLS, SynapseQuadColumnOnDLS>
    , common::CoordinateBase<NeuronResetQuadOnDLS>
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
	neuron_reset_type toNeuronResetOnDLS() const SYMBOL_VISIBLE;
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
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::LogicalNeuronOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronColumnOnLogicalNeuron)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::AtomicNeuronOnLogicalNeuron)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CompartmentOnLogicalNeuron)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronBackendConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronResetQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronBackendAddressOut)

} // namespace std

#ifndef __ppu__
extern template SYMBOL_VISIBLE void halco::hicann_dls::vx::LogicalNeuronCompartments::serialize(
    cereal::JSONOutputArchive&, std::uint32_t const);
extern template SYMBOL_VISIBLE void halco::hicann_dls::vx::LogicalNeuronCompartments::serialize(
    cereal::JSONInputArchive&, std::uint32_t const);
extern template SYMBOL_VISIBLE void halco::hicann_dls::vx::LogicalNeuronCompartments::serialize(
    cereal::PortableBinaryOutputArchive&, std::uint32_t const);
extern template SYMBOL_VISIBLE void halco::hicann_dls::vx::LogicalNeuronCompartments::serialize(
    cereal::PortableBinaryInputArchive&, std::uint32_t const);
extern template SYMBOL_VISIBLE void halco::hicann_dls::vx::LogicalNeuronOnDLS::serialize(
    cereal::JSONOutputArchive&, std::uint32_t const);
extern template SYMBOL_VISIBLE void halco::hicann_dls::vx::LogicalNeuronOnDLS::serialize(
    cereal::JSONInputArchive&, std::uint32_t const);
extern template SYMBOL_VISIBLE void halco::hicann_dls::vx::LogicalNeuronOnDLS::serialize(
    cereal::PortableBinaryOutputArchive&, std::uint32_t const);
extern template SYMBOL_VISIBLE void halco::hicann_dls::vx::LogicalNeuronOnDLS::serialize(
    cereal::PortableBinaryInputArchive&, std::uint32_t const);
#endif
