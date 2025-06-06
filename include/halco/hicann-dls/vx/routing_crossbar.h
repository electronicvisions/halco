#pragma once
#include <optional>
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "hate/visibility.h"

namespace halco::hicann_dls {
namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct NeuronEventOutputOnDLS;
struct PADIBusOnDLS;
struct SPL1Address;
struct CrossbarL2OutputOnDLS;

/************\
   Crossbar
\************/

/**
 * Unique coordinate for crossbar configuration.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) CrossbarOnDLS
    : public common::detail::RantWrapper<CrossbarOnDLS, uint_fast16_t, 0, 0>
    , common::CoordinateBase<CrossbarOnDLS>
{
	constexpr explicit CrossbarOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

/**
 * Unique coordinate for crossbar output configuration.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    CrossbarOutputConfigOnDLS
    : public common::detail::RantWrapper<CrossbarOutputConfigOnDLS, uint_fast16_t, 0, 0>
    , common::CoordinateBase<CrossbarOutputConfigOnDLS>
{
	constexpr explicit CrossbarOutputConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


/**
 * Coordinate of a crossbar output channel.
 */
struct GENPYBIND(
    inline_base("*RantWrapper*"),
    inline_base("*CoordinateBase*"),
    inline_base("*XRangedTrait*")) CrossbarOutputOnDLS
    : public common::detail::RantWrapper<CrossbarOutputOnDLS, uint_fast16_t, 11, 0>
    , public common::detail::XRangedTrait
    , public halco::common::CoordinateBase<CrossbarOutputOnDLS>
{
	constexpr explicit CrossbarOutputOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	std::optional<PADIBusOnDLS> toPADIBusOnDLS() const SYMBOL_VISIBLE;
	std::optional<CrossbarL2OutputOnDLS> toCrossbarL2OutputOnDLS() const SYMBOL_VISIBLE;
};


/**
 * Coordinate of a to-L2 crossbar output channel.
 * Describes a continuous subset of the CrossbarOutputOnDLS range.
 */
struct GENPYBIND(inline_base("*")) CrossbarL2OutputOnDLS
    : public common::detail::RantWrapper<CrossbarL2OutputOnDLS, uint_fast16_t, 3, 0>
{
	constexpr explicit CrossbarL2OutputOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CrossbarOutputOnDLS toCrossbarOutputOnDLS() const SYMBOL_VISIBLE;
};


/**
 * Coordinate of a crossbar input channel.
 */
struct GENPYBIND(
    inline_base("*RantWrapper*"),
    inline_base("*CoordinateBase*"),
    inline_base("*YRangedTrait*")) CrossbarInputOnDLS
    : public common::detail::RantWrapper<CrossbarInputOnDLS, uint_fast16_t, 19, 0>
    , common::CoordinateBase<CrossbarInputOnDLS>
    , public common::detail::YRangedTrait
{
	constexpr explicit CrossbarInputOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	std::optional<SPL1Address> toSPL1Address() const SYMBOL_VISIBLE;
	std::optional<NeuronEventOutputOnDLS> toNeuronEventOutputOnDLS() const SYMBOL_VISIBLE;
};


/*
 * Coordinate of a node in the crossbar connecting a input channel with a output channel.
 * The nodes are located as depicted in the following: (X == node, . == no node)
 *
 *                                  - Outputs -
 *
 *                         synapse driver         L2
 *                      top          bottom
 *                      0  1  2  3   0  1  2  3   0  1  2  3
 *
 *         neurons  0   X  .  .  .   X  .  .  .   X  .  .  .
 *         left of  1   .  X  .  .   .  X  .  .   .  X  .  .
 *         anncore  2   .  .  X  .   .  .  X  .   .  .  X  .
 *                  3   .  .  .  X   .  .  .  X   .  .  .  X
 *
 *         neurons  0   X  .  .  .   X  .  .  .   X  .  .  .
 *         right of 1   .  X  .  .   .  X  .  .   .  X  .  .
 *         anncore  2   .  .  X  .   .  .  X  .   .  .  X  .
 *    |             3   .  .  .  X   .  .  .  X   .  .  .  X
 *
 *         L2       0   X  X  X  X   X  X  X  X   X  .  .  .
 * Inputs           1   X  X  X  X   X  X  X  X   .  X  .  .
 *                  2   X  X  X  X   X  X  X  X   .  .  X  .
 *                  3   X  X  X  X   X  X  X  X   .  .  .  X
 *    |
 *         back-    0   X  .  .  .   .  .  .  .   X  .  .  .
 *         ground   1   .  X  .  .   .  .  .  .   .  X  .  .
 *         spike    2   .  .  X  .   .  .  .  .   .  .  X  .
 *         sources  3   .  .  .  X   .  .  .  .   .  .  .  X
 *                  4   .  .  .  .   X  .  .  .   X  .  .  .
 *                  5   .  .  .  .   .  X  .  .   .  X  .  .
 *                  6   .  .  .  .   .  .  X  .   .  .  X  .
 *                  7   .  .  .  .   .  .  .  X   .  .  .  X
 *
 * The nodes are counted continuously from the top-left to the bottom-right corner of
 * the schematic.
 */
struct GENPYBIND(inline_base("*GridCoordinate*"), inline_base("*CoordinateBase*")) CrossbarNodeOnDLS
    : public common::detail::
          GridCoordinate<CrossbarNodeOnDLS, CrossbarOutputOnDLS, CrossbarInputOnDLS, 76>
    , common::CoordinateBase<CrossbarNodeOnDLS>
{
	GRID_COMMON_CONSTRUCTORS(CrossbarNodeOnDLS)

	CrossbarOutputOnDLS toCrossbarOutputOnDLS() const { return x(); }
	CrossbarInputOnDLS toCrossbarInputOnDLS() const { return y(); }

	/* implementation detail, not part of public API: */

	static x_type to_x(enum_type const& e) SYMBOL_VISIBLE;
	static y_type to_y(enum_type const& e) SYMBOL_VISIBLE;
	static enum_type to_enum(x_type const& x, y_type const& y) SYMBOL_VISIBLE;
};

} // namespace vx
} // namespace halco::hicann_dls

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CrossbarInputOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CrossbarL2OutputOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CrossbarNodeOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CrossbarOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CrossbarOutputConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CrossbarOutputOnDLS)

} // namespace std
