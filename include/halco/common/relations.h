#pragma once

extern "C" {
#include <stdint.h>
}

#include <iosfwd>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "pywrap/compat/macros.hpp"

namespace halco {
namespace common GENPYBIND_TAG_HALCO_COMMON {

typedef detail::XRanged<1, 0> SideHorizontal GENPYBIND(opaque);
extern SideHorizontal const left GENPYBIND(visible);
extern SideHorizontal const right GENPYBIND(visible);
typedef SideHorizontal Side GENPYBIND(visible);

typedef detail::YRanged<1, 0> SideVertical GENPYBIND(opaque);
extern SideVertical const top GENPYBIND(visible);
extern SideVertical const bottom GENPYBIND(visible);

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
	static Direction north() GENPYBIND(hidden);
	static Direction east() GENPYBIND(hidden);
	static Direction south() GENPYBIND(hidden);
	static Direction west() GENPYBIND(hidden);

	Orientation toOrientation() const;

	PYPP_CONSTEXPR explicit Direction(uintmax_t const val = 0) : rant_t(val) {}
}; // Direction

class GENPYBIND(inline_base("*")) Parity : public detail::RantWrapper<Parity, uint_fast16_t, 1, 0>
{
public:
	PYPP_CONSTEXPR explicit Parity(uintmax_t is_odd = false) : rant_t(is_odd) {}
	static Parity from_number(uintmax_t val);

	static Parity const even;
	static Parity const odd;
}; // Parity

extern Direction const north GENPYBIND(visible);
extern Direction const east GENPYBIND(visible);
extern Direction const south GENPYBIND(visible);
extern Direction const west GENPYBIND(visible);
extern Orientation const horizontal GENPYBIND(visible);
extern Orientation const vertical GENPYBIND(visible);
extern Unique const unique GENPYBIND(visible);

namespace detail {

#ifndef __ppu__
std::ostream& _write(std::ostream& os, const XRanged<1, 0>& v);
std::ostream& _write(std::ostream& os, const YRanged<1, 0>& v);
std::ostream& _write(std::ostream& os, Direction const& direction);
std::ostream& _write(std::ostream& os, Orientation const& orientation);
std::ostream& _write(std::ostream& os, Parity const& parity);
std::ostream& _write(std::ostream& os, Unique const&);
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
