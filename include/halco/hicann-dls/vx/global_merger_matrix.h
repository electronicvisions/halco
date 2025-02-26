#pragma once
#include <optional>
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"
#include "hate/visibility.h"

namespace halco::hicann_dls {
namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/**********************\
   GlobalMergerMatrix
\**********************/

// taken from hicann-dls/units/hx_spl1_fabric/source/rtl/gmm_pkg.sv
constexpr size_t GMM_EDGES = 4;
constexpr size_t GMM_EMUL = 2;         // edge multiplier, i.e. parallel links per edge
constexpr size_t GMM_L2MUL = 4;        // parallel l2 lanes
constexpr size_t GMM_L1IN = 4;         // L1 to anncore
constexpr size_t GMM_L1OUT = 4;        // L1 from anncore
constexpr size_t GMM_TORLUT = 2;       // RLUT channels to rlut
constexpr size_t GMM_FROMRLUT = 2;     // RLUT channels from rlut
constexpr size_t GMM_N = GMM_EMUL * 0; // index for north cc link
constexpr size_t GMM_S = GMM_EMUL * 1; // index for south cc link
constexpr size_t GMM_E = GMM_EMUL * 2; // index for east cc link
constexpr size_t GMM_W = GMM_EMUL * 3; // index for west cc link
constexpr size_t GMM_IDXBITS = 6;

constexpr size_t GMM_COLS = GMM_EDGES * GMM_EMUL + GMM_TORLUT + GMM_L1IN;
constexpr size_t GMM_ROWS = GMM_EDGES * GMM_EMUL + GMM_FROMRLUT + GMM_L1OUT + GMM_L2MUL;


/**
 * Unique coordinate for global merger matrix configuration.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    GlobalMergerMatrixOnDLS
    : public common::detail::RantWrapper<GlobalMergerMatrixOnDLS, uint_fast16_t, 0, 0>
    , common::CoordinateBase<GlobalMergerMatrixOnDLS>
{
	constexpr explicit GlobalMergerMatrixOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

/**
 * Unique coordinate for global merger matrix output configuration.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    GlobalMergerMatrixOutputConfigOnDLS
    : public common::detail::RantWrapper<GlobalMergerMatrixOutputConfigOnDLS, uint_fast16_t, 0, 0>
    , common::CoordinateBase<GlobalMergerMatrixOutputConfigOnDLS>
{
	constexpr explicit GlobalMergerMatrixOutputConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


/**
 * Coordinate for global merger matrix output channel.
 */
struct GENPYBIND(inline_base("*RantWrapper*")) GlobalMergerMatrixOutputChannelOnDLS
    : public common::detail::RantWrapper<
          GlobalMergerMatrixOutputChannelOnDLS,
          uint_fast16_t,
          halco::hicann_dls::vx::GMM_EDGES * halco::hicann_dls::vx::GMM_EMUL +
              halco::hicann_dls::vx::GMM_TORLUT + halco::hicann_dls::vx::GMM_L1IN,
          0>
{
	constexpr explicit GlobalMergerMatrixOutputChannelOnDLS(uintmax_t const val = 0) : rant_t(val)
	{}
};


/**
 * Coordinate for global merger matrix output event counter.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    GlobalMergerMatrixOutputEventCounterOnDLS
    : public common::detail::RantWrapper<
          GlobalMergerMatrixOutputEventCounterOnDLS,
          uint_fast16_t,
          halco::hicann_dls::vx::GMM_EDGES * halco::hicann_dls::vx::GMM_EMUL +
              halco::hicann_dls::vx::GMM_TORLUT + halco::hicann_dls::vx::GMM_L1IN,
          0>
    , common::CoordinateBase<GlobalMergerMatrixOutputEventCounterOnDLS>
{
	constexpr explicit GlobalMergerMatrixOutputEventCounterOnDLS(uintmax_t const val = 0) :
	    rant_t(val)
	{}
};


/**
 * Coordinate for global merger matrix input channel.
 */
struct GENPYBIND(inline_base("*RantWrapper*")) GlobalMergerMatrixInputChannelOnDLS
    : public common::detail::RantWrapper<
          GlobalMergerMatrixInputChannelOnDLS,
          uint_fast16_t,
          halco::hicann_dls::vx::GMM_EDGES * halco::hicann_dls::vx::GMM_EMUL +
              halco::hicann_dls::vx::GMM_FROMRLUT + halco::hicann_dls::vx::GMM_L1OUT +
              halco::hicann_dls::vx::GMM_L2MUL,
          0>
{
	constexpr explicit GlobalMergerMatrixInputChannelOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


/**
 * Coordinate for global merger matrix input drop counter.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    GlobalMergerMatrixInputDropCounterOnDLS
    : public common::detail::RantWrapper<
          GlobalMergerMatrixInputDropCounterOnDLS,
          uint_fast16_t,
          halco::hicann_dls::vx::GMM_EDGES * halco::hicann_dls::vx::GMM_EMUL +
              halco::hicann_dls::vx::GMM_FROMRLUT + halco::hicann_dls::vx::GMM_L1OUT +
              halco::hicann_dls::vx::GMM_L2MUL,
          0>
    , common::CoordinateBase<GlobalMergerMatrixInputDropCounterOnDLS>
{
	constexpr explicit GlobalMergerMatrixInputDropCounterOnDLS(uintmax_t const val = 0) :
	    rant_t(val)
	{}
};


/**
 * Coordinate for lookup table from neuron labels to gl1 events in front of global merger
 * matrix rows from L2 and crossbar.
 */
struct GENPYBIND(inline_base("*RantWrapper*")) NeuronLabelToGL1EventLUTOnDLS
    : public common::detail::
          RantWrapper<NeuronLabelToGL1EventLUTOnDLS, uint_fast16_t, (GMM_L2MUL + GMM_L1OUT) - 1, 0>
{
	constexpr explicit NeuronLabelToGL1EventLUTOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


/**
 * Coordinate for lookup table entry in lookup table from neuron labels to gl1 events in front of
 * global merger matrix rows from L2 and crossbar.
 */
struct GENPYBIND(inline_base("*RantWrapper*")) NeuronLabelToGL1EventLUTEntryOnLUT
    : public common::detail::
          RantWrapper<NeuronLabelToGL1EventLUTEntryOnLUT, uint_fast16_t, GMM_IDXBITS - 1, 0>
{
	constexpr explicit NeuronLabelToGL1EventLUTEntryOnLUT(uintmax_t const val = 0) : rant_t(val) {}
};


HALCO_COORDINATE_MIXIN(NeuronLabelToGL1EventLUTMixin, NeuronLabelToGL1EventLUTOnDLS, gmm_lut)

/**
 * Coordinate for lookup table entry from neuron labels to gl1 events in front of global merger
 * matrix rows from L2 and crossbar.
 */
struct GENPYBIND(inline_base("*Mixin*"), inline_base("*CoordinateBase*"))
    NeuronLabelToGL1EventLUTEntryOnDLS
    : public NeuronLabelToGL1EventLUTMixin<
          NeuronLabelToGL1EventLUTEntryOnDLS,
          NeuronLabelToGL1EventLUTEntryOnLUT>
    , common::CoordinateBase<NeuronLabelToGL1EventLUTEntryOnDLS>
{
	NeuronLabelToGL1EventLUTEntryOnDLS() = default;

	explicit NeuronLabelToGL1EventLUTEntryOnDLS(
	    NeuronLabelToGL1EventLUTEntryOnLUT const& entry,
	    NeuronLabelToGL1EventLUTOnDLS const& lut = NeuronLabelToGL1EventLUTOnDLS()) :
	    mixin_t(entry, lut)
	{}

	explicit NeuronLabelToGL1EventLUTEntryOnDLS(enum_type const& e) : mixin_t(e) {}

	NeuronLabelToGL1EventLUTEntryOnLUT toNeuronLabelToGL1EventLUTEntryOnLUT() const
	{
		return This();
	}
};


/**
 * Coordinate of a global merger matrix output channel.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*XRangedTrait*"))
    GlobalMergerMatrixOutputOnDLS
    : public common::detail::
          RantWrapper<GlobalMergerMatrixOutputOnDLS, uint_fast16_t, GMM_COLS - 1, 0>
    , public common::detail::XRangedTrait
{
	constexpr explicit GlobalMergerMatrixOutputOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


/**
 * Coordinate of a global merger matrix input channel.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*YRangedTrait*"))
    GlobalMergerMatrixInputOnDLS
    : public common::detail::
          RantWrapper<GlobalMergerMatrixInputOnDLS, uint_fast16_t, GMM_ROWS - 1, 0>
    , public common::detail::YRangedTrait
{
	constexpr explicit GlobalMergerMatrixInputOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


/*
 * Coordinate of an intersection in the global merger matrix connecting input channel(s) with output
 channel(s).
 * The intersections are located as depicted in the following: (NxM == NxM nodes, . == no node(s))
 *
 *                           - Outputs -
 *
 *                 N    S    W    E       RLUT    Crossbar
 *
 *       N         .    2x2  2x2  2x2     2x2     2x1  .    .    .
 *       S         2x2  .    2x2  2x2     2x2     .    2x1  .    .
 *       W         2x2  2x2  .    2x2     2x2     .    .    2x1  .
 *       E         2x2  2x2  2x2  .       2x2     .    .    .    2x1
 *
 *       RLUT      2x2  2x2  2x2  2x2     2x2     2x1  2x1  2x1  2x1

 *       Crossbar  1x2  1x2  1x2  1x2     .       .    .    .    .
 *                 1x2  1x2  1x2  1x2     .       .    .    .    .
 *                 1x2  1x2  1x2  1x2     .       .    .    .    .
 *                 1x2  1x2  1x2  1x2     .       .    .    .    .

 *       L2        .    .    .    .       1x2     1x1  .    .    .
 *                 .    .    .    .       1x2     .    1x1  .    .
 *                 .    .    .    .       1x2     .    .    1x1  .
 *                 .    .    .    .       1x2     .    .    .    1x1
 *
 * The intersections are counted continuously from the top-left to the bottom-right corner of
 * the schematic.
 */
struct GENPYBIND(inline_base("*GridCoordinate*")) GlobalMergerMatrixIntersectionOnDLS
    : public common::detail::GridCoordinate<
          GlobalMergerMatrixIntersectionOnDLS,
          GlobalMergerMatrixOutputOnDLS,
          GlobalMergerMatrixInputOnDLS,
          halco::hicann_dls::vx::GMM_EDGES*(halco::hicann_dls::vx::GMM_EDGES - 1) // NSWE -> NSWE
              + halco::hicann_dls::vx::GMM_EDGES                                  // NSWE -> RLUT
              + halco::hicann_dls::vx::GMM_EDGES // NSWE -> Crossbar
              + halco::hicann_dls::vx::GMM_EDGES // RLUT -> NSWE
              + 1                                // RLUT -> RLUT
              + halco::hicann_dls::vx::GMM_L1IN  // RLUT -> Crossbar
              + halco::hicann_dls::vx::GMM_L1OUT *
                    halco::hicann_dls::vx::GMM_EDGES // Crossbar -> NSWE
              + halco::hicann_dls::vx::GMM_L2MUL     // L2 -> RLUT
              + halco::hicann_dls::vx::GMM_L2MUL     // L2 -> Crossbar
          >
{
	GRID_COMMON_CONSTRUCTORS(GlobalMergerMatrixIntersectionOnDLS)

	GlobalMergerMatrixOutputOnDLS toGlobalMergerMatrixOutputOnDLS() const
	{
		return x();
	}
	GlobalMergerMatrixInputOnDLS toGlobalMergerMatrixInputOnDLS() const
	{
		return y();
	}

	/* implementation detail, not part of public API: */

	static x_type to_x(enum_type const& e) SYMBOL_VISIBLE;
	static y_type to_y(enum_type const& e) SYMBOL_VISIBLE;
	static enum_type to_enum(x_type const& x, y_type const& y) SYMBOL_VISIBLE;
};


/**
 * Coordinate of a global merger matrix output channel.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*XRangedTrait*"))
    OutputChannelOnGlobalMergerMatrixIntersection
    : public common::detail::RantWrapper<
          OutputChannelOnGlobalMergerMatrixIntersection,
          uint_fast16_t,
          std::max(GMM_EMUL, GMM_TORLUT) - 1,
          0>
    , public common::detail::XRangedTrait
{
	constexpr explicit OutputChannelOnGlobalMergerMatrixIntersection(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


/**
 * Coordinate of a global merger matrix input channel.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*YRangedTrait*"))
    InputChannelOnGlobalMergerMatrixIntersection
    : public common::detail::RantWrapper<
          InputChannelOnGlobalMergerMatrixIntersection,
          uint_fast16_t,
          std::max(GMM_EMUL, GMM_FROMRLUT) - 1,
          0>
    , public common::detail::YRangedTrait
{
	constexpr explicit InputChannelOnGlobalMergerMatrixIntersection(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


/*
 * Coordinate of a node on an intersection in the global merger matrix connecting an input channel
 * with an output channel.
 */
struct GENPYBIND(inline_base("*GridCoordinate*")) NodeOnGlobalMergerMatrixIntersection
    : public common::detail::GridCoordinate<
          NodeOnGlobalMergerMatrixIntersection,
          OutputChannelOnGlobalMergerMatrixIntersection,
          InputChannelOnGlobalMergerMatrixIntersection>
{
	GRID_COMMON_CONSTRUCTORS(NodeOnGlobalMergerMatrixIntersection)

	OutputChannelOnGlobalMergerMatrixIntersection toOutputChannelOnGlobalMergerMatrixIntersection()
	    const
	{
		return x();
	}
	InputChannelOnGlobalMergerMatrixIntersection toInputChannelOnGlobalMergerMatrixIntersection()
	    const
	{
		return y();
	}
};


/*
 * Coordinate of a node in the global merger matrix connecting an input channel with an output
 * channel.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    GlobalMergerMatrixNodeOnDLS
    : public common::detail::RantWrapper<
          GlobalMergerMatrixNodeOnDLS,
          uint_fast16_t,
          (halco::hicann_dls::vx::GMM_EDGES * halco::hicann_dls::vx::GMM_EMUL) *
                  ((halco::hicann_dls::vx::GMM_EDGES - 1) *
                   halco::hicann_dls::vx::GMM_EMUL) // NSWE -> NSWE
              + halco::hicann_dls::vx::GMM_EDGES * halco::hicann_dls::vx::GMM_EMUL *
                    halco::hicann_dls::vx::GMM_TORLUT // NSWE -> RLUT
              +
              halco::hicann_dls::vx::GMM_EDGES * halco::hicann_dls::vx::GMM_EMUL // NSWE -> Crossbar
              + halco::hicann_dls::vx::GMM_FROMRLUT * halco::hicann_dls::vx::GMM_EDGES *
                    halco::hicann_dls::vx::GMM_EMUL // RLUT -> NSWE
              + halco::hicann_dls::vx::GMM_FROMRLUT *
                    halco::hicann_dls::vx::GMM_TORLUT // RLUT -> RLUT
              + halco::hicann_dls::vx::GMM_FROMRLUT *
                    halco::hicann_dls::vx::GMM_L1IN // RLUT -> Crossbar
              + halco::hicann_dls::vx::GMM_L1OUT * halco::hicann_dls::vx::GMM_EDGES *
                    halco::hicann_dls::vx::GMM_EMUL // Crossbar -> NSWE
              + halco::hicann_dls::vx::GMM_L2MUL * halco::hicann_dls::vx::GMM_TORLUT // L2 -> RLUT
              + halco::hicann_dls::vx::GMM_L2MUL,
          0>
    , common::CoordinateBase<GlobalMergerMatrixNodeOnDLS>
{
	constexpr explicit GlobalMergerMatrixNodeOnDLS(uintmax_t const val = 0) : rant_t(val) {}

	GlobalMergerMatrixNodeOnDLS(
	    NodeOnGlobalMergerMatrixIntersection const& node_on_intersection,
	    GlobalMergerMatrixIntersectionOnDLS const& intersection) SYMBOL_VISIBLE;

	NodeOnGlobalMergerMatrixIntersection toNodeOnGlobalMergerMatrixIntersection() const
	    SYMBOL_VISIBLE;
	GlobalMergerMatrixIntersectionOnDLS toGlobalMergerMatrixIntersectionOnDLS() const
	    SYMBOL_VISIBLE;
};

} // namespace vx
} // namespace halco::hicann_dls

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::GlobalMergerMatrixOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::GlobalMergerMatrixOutputConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::GlobalMergerMatrixOutputChannelOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::GlobalMergerMatrixOutputEventCounterOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::GlobalMergerMatrixInputChannelOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::GlobalMergerMatrixInputDropCounterOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronLabelToGL1EventLUTEntryOnLUT)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronLabelToGL1EventLUTOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronLabelToGL1EventLUTEntryOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::GlobalMergerMatrixInputOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::GlobalMergerMatrixOutputOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::GlobalMergerMatrixIntersectionOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::InputChannelOnGlobalMergerMatrixIntersection)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::OutputChannelOnGlobalMergerMatrixIntersection)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NodeOnGlobalMergerMatrixIntersection)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::GlobalMergerMatrixNodeOnDLS)

} // namespace std
