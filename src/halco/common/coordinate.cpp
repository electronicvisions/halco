#include "halco/common/coordinate.h"

#ifndef __ppu__
#include <ostream>

namespace halco {
namespace common {

Coordinate::~Coordinate() {}

std::ostream& operator<<(std::ostream& os, Coordinate const& coordinate)
{
	return coordinate.print(os);
}

} // namespace common
} // namespace halco
#endif
