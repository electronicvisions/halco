#include "halco/hicann/v2/coordinates.h"
#include "halco/hicann/v2/lookup_tables.h"

using namespace halco::common;

namespace halco {
namespace hicann {
namespace v2 {

HICANNOnWafer::x_type HICANNOnWafer::to_x(enum_type const& e) {
	return x_type(HICANNOnWaferGrid.at(e).first);
}

HICANNOnWafer::y_type HICANNOnWafer::to_y(enum_type const& e) {
	return y_type(HICANNOnWaferGrid.at(e).second);
}

HICANNOnWafer::enum_type HICANNOnWafer::to_enum(x_type const& x, y_type const& y) {
	// throws out_of_range if x or y is not available on wafer.
	int const en = HICANNOnWaferEnum.at(x).at(y);
	if (en == invalid)
		throw std::domain_error("Invalid combination of X and Y for a HICANN");
	return enum_type(en);
}

HICANNOnWafer HICANNOnWafer::move(Direction const& direction) const {
	if (direction == halco::common::east) {
		return east();
	}
	if (direction == halco::common::south) {
		return south();
	}
	if (direction == halco::common::west) {
		return west();
	}
	return north();
}

bool HICANNOnWafer::has_east() const
{
	if (x() == x_type::max) {
		return false;
	}
	return HICANNOnWaferEnum.at(x_type(x() + 1)).at(y()) != invalid;
}

bool HICANNOnWafer::has_west() const
{
	if (x() == x_type::min) {
		return false;
	}
	return HICANNOnWaferEnum.at(x_type(x() - 1)).at(y()) != invalid;
}
bool HICANNOnWafer::has_north() const
{
	if (y() == y_type::min) {
		return false;
	}
	return HICANNOnWaferEnum.at(x()).at(y_type(y() - 1)) != invalid;
}
bool HICANNOnWafer::has_south() const
{
	if (y() == y_type::max) {
		return false;
	}
	return HICANNOnWaferEnum.at(x()).at(y_type(y() + 1)) != invalid;
}

bool HICANNOnWafer::can_move(Direction const& direction) const
{
	if (direction == halco::common::east) {
		return has_east();
	}
	if (direction == halco::common::south) {
		return has_south();
	}
	if (direction == halco::common::west) {
		return has_west();
	}
	return has_north();
}

DNCOnWafer HICANNOnWafer::toDNCOnWafer() const {
	return DNCOnWafer(DNCOnWafer::x_type(x() / 4), DNCOnWafer::y_type(y() / 2));
}

FPGAOnWafer HICANNOnWafer::toFPGAOnWafer() const {
	return toDNCOnWafer().toFPGAOnWafer();
}

HICANNOnDNC HICANNOnWafer::toHICANNOnDNC() const {
	auto _x = HICANNOnDNC::x_type(x() % 4);
	auto _y = HICANNOnDNC::y_type(y() % 2);
	return HICANNOnDNC(_x, _y);
}

HighspeedLinkOnDNC HICANNOnWafer::toHighspeedLinkOnDNC() const
{
	return toHICANNOnDNC().toHighspeedLinkOnDNC();
}

HighspeedLinkOnDNC HICANNOnDNC::toHighspeedLinkOnDNC() const
{
	size_t const e = (y()) ? (x()) * 2 + 1 /*odd*/
	                       : (x()) * 2 /*even*/;
	return HighspeedLinkOnDNC(e);
}

HICANNOnWafer HICANNOnDNC::toHICANNOnWafer(const DNCOnWafer& dnc) const {
	auto _x = HICANNOnWafer::x_type(dnc.x() * 4 + x());
	auto _y = HICANNOnWafer::y_type(dnc.y() * 2 + y());
	return HICANNOnWafer(_x, _y);
}

HICANNOnWafer HICANNOnDNC::toHICANNOnWafer(const FPGAOnWafer& fpga) const
{
	return toHICANNOnWafer(fpga.toDNCOnWafer());
}

HICANNGlobal HICANNGlobal::east() const {
	return HICANNGlobal(HICANNOnWafer::east(), toWafer());
}

HICANNGlobal HICANNGlobal::west() const {
	return HICANNGlobal(HICANNOnWafer::west(), toWafer());
}

HICANNGlobal HICANNGlobal::north() const {
	return HICANNGlobal(HICANNOnWafer::north(), toWafer());
}

HICANNGlobal HICANNGlobal::south() const {
	return HICANNGlobal(HICANNOnWafer::south(), toWafer());
}

HICANNGlobal HICANNGlobal::move(Direction const& direction) const
{
	return HICANNGlobal(HICANNOnWafer::move(direction), toWafer());
}

DNCGlobal HICANNGlobal::toDNCGlobal() const {
	return DNCGlobal(HICANNOnWafer::toDNCOnWafer(), toWafer());
}

FPGAGlobal HICANNGlobal::toFPGAGlobal() const {
	return FPGAGlobal(toFPGAOnWafer(), toWafer());
}

FPGAOnWafer HICANNGlobal::toFPGAOnWafer() const {
	return gridLookupFPGAOnWafer(toDNCGlobal());
}

DNCOnFPGA HICANNGlobal::toDNCOnFPGA() const {
	return toDNCGlobal().toDNCOnFPGA();
}

} // v2
} // hicann
} // halco
