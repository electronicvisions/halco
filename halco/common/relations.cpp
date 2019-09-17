#include "halco/common/relations.h"

namespace halco {
namespace common {

SideHorizontal const left  {X{0}};
SideHorizontal const right {X{1}};

SideVertical const top     {Y{0}};
SideVertical const bottom  {Y{1}};

Direction const north = Direction::north();
Direction const east = Direction::east();
Direction const south = Direction::south();
Direction const west = Direction::west();

Orientation const horizontal{0};
Orientation const vertical{1};

Unique const unique{};

Parity const Parity::even{0};
Parity const Parity::odd{1};

Direction Direction::north() {
	return Direction(0u);
}

Direction Direction::east() {
	return Direction(1u);
}

Direction Direction::south() {
	return Direction(2u);
}

Direction Direction::west() {
	return Direction(3u);
}

Orientation Direction::toOrientation() const {
	if (*this == north() || *this == south()) {
		return vertical;
	}
	return horizontal;
}

Parity Parity::from_number(uintmax_t val) {
	return Parity(val % 2);
}

namespace detail {

std::ostream& _write(std::ostream& os, const XRanged<1, 0>& v) {
	return os << (v.value() ? "right" : "left");
}

std::ostream& _write(std::ostream& os, const YRanged<1, 0>& v) {
	return os << (v.value() ? "bottom" : "top");
}

std::ostream& _write(std::ostream& os, Direction const& direction) {
	// clang-format off
	return os << (direction == east ? "east" :
	              direction == south ? "south" :
	              direction == west ? "west" : "north");
	// clang-format on
}

std::ostream& _write(std::ostream& os, Orientation const& orientation) {
	return os << (orientation == horizontal ? "horizontal" : "vertical");
}

std::ostream& _write(std::ostream& os, Parity const& parity) {
	return os << (parity == Parity::even ? "even" : "odd");
}

std::ostream& _write(std::ostream& os, Unique const&) {
	return os << "unique";
}

} // namespace detail
} // namespace common
} // namespace halco
