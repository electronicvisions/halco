#pragma once

extern "C" {
#include <stdint.h>
}

#include <iosfwd>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "hate/visibility.h"
#include "pywrap/compat/macros.hpp"

namespace halco {
namespace common GENPYBIND_TAG_HALCO_COMMON {

typedef detail::XRanged<1, 0> SideHorizontal GENPYBIND(opaque);
extern SYMBOL_VISIBLE SideHorizontal const left GENPYBIND(visible);
extern SYMBOL_VISIBLE SideHorizontal const right GENPYBIND(visible);
typedef SideHorizontal Side GENPYBIND(visible);

typedef detail::YRanged<1, 0> SideVertical GENPYBIND(opaque);
extern SYMBOL_VISIBLE SideVertical const top GENPYBIND(visible);
extern SYMBOL_VISIBLE SideVertical const bottom GENPYBIND(visible);

/**
 * @brief General-purpose coordinate for things unique to the system.
 * This coordinate is used where specifying a coordinate is necessary for reasons of
 * uniformity (e.g. the byte-formatting API may expect both a coordinate and a container) but no
 * sensible coordinate exists, since the corresponding component is unique to the system.
 */
class GENPYBIND(inline_base("*")) Unique : public detail::RantWrapper<Unique, uint_fast16_t, 0, 0>
{
public:
	PYPP_CONSTEXPR explicit Unique(uintmax_t const value = 0) : rant_t(value) {}
}; // Unique

class GENPYBIND(inline_base("*")) Orientation
	: public detail::RantWrapper<Orientation, uint_fast16_t, 1, 0>
{
public:
	PYPP_CONSTEXPR explicit Orientation(uintmax_t is_vertical = false) : rant_t(is_vertical) {}
}; // Orientation

class GENPYBIND(inline_base("*")) Direction
	: public detail::RantWrapper<Direction, uint_fast16_t, 3, 0>
{
public:
	static Direction north() GENPYBIND(hidden) SYMBOL_VISIBLE;
	static Direction east() GENPYBIND(hidden) SYMBOL_VISIBLE;
	static Direction south() GENPYBIND(hidden) SYMBOL_VISIBLE;
	static Direction west() GENPYBIND(hidden) SYMBOL_VISIBLE;

	Orientation toOrientation() const SYMBOL_VISIBLE;

	PYPP_CONSTEXPR explicit Direction(uintmax_t const val = 0) : rant_t(val) {}
}; // Direction

class GENPYBIND(inline_base("*")) Parity : public detail::RantWrapper<Parity, uint_fast16_t, 1, 0>
{
public:
	PYPP_CONSTEXPR explicit Parity(uintmax_t is_odd = false) : rant_t(is_odd) {}
	static Parity from_number(uintmax_t val) SYMBOL_VISIBLE;

	static SYMBOL_VISIBLE Parity const even;
	static SYMBOL_VISIBLE Parity const odd;
}; // Parity

extern SYMBOL_VISIBLE Direction const north GENPYBIND(visible);
extern SYMBOL_VISIBLE Direction const east GENPYBIND(visible);
extern SYMBOL_VISIBLE Direction const south GENPYBIND(visible);
extern SYMBOL_VISIBLE Direction const west GENPYBIND(visible);
extern SYMBOL_VISIBLE Orientation const horizontal GENPYBIND(visible);
extern SYMBOL_VISIBLE Orientation const vertical GENPYBIND(visible);
extern SYMBOL_VISIBLE Unique const unique GENPYBIND(visible);

namespace detail {

#ifndef __ppu__
std::ostream& _write(std::ostream& os, const XRanged<1, 0>& v) SYMBOL_VISIBLE;
std::ostream& _write(std::ostream& os, const YRanged<1, 0>& v) SYMBOL_VISIBLE;
std::ostream& _write(std::ostream& os, Direction const& direction) SYMBOL_VISIBLE;
std::ostream& _write(std::ostream& os, Orientation const& orientation) SYMBOL_VISIBLE;
std::ostream& _write(std::ostream& os, Parity const& parity) SYMBOL_VISIBLE;
std::ostream& _write(std::ostream& os, Unique const&) SYMBOL_VISIBLE;
#endif

} // namespace detail
} // common
} // halco

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::common::Direction)
HALCO_GEOMETRY_HASH_CLASS(halco::common::Orientation)
HALCO_GEOMETRY_HASH_CLASS(halco::common::Parity)
HALCO_GEOMETRY_HASH_CLASS(halco::common::Unique)

} // namespace std
