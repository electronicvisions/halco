#include "halco/hicann/v2/wafer.h"
#include "halco/hicann/v2/external.h"
#include "halco/hicann/v2/lookup_tables.h"

using namespace halco::common;

namespace halco {
namespace hicann {
namespace v2 {

bool Wafer::isKintex() const {
	return value() > 2;
}

} // v2
} // hicann
} // halco
