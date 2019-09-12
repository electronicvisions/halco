#include "halco/hicann/v2/fg.h"

using namespace halco::common;

namespace halco {
namespace hicann {
namespace v2 {

FGRowOnFGBlock FGCellOnFGBlock::toFGRowOnFGBlock() const { return FGRowOnFGBlock(y()); }

} // v2
} // hicann
} // halco
