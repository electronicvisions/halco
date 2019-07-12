#include "halco/hicann/v2/external.h"
#include "halco/hicann/v2/synapse.h"
#include "halco/hicann/v2/l1.h"
#include "halco/hicann/v2/quadrant.h"

using namespace halco::common;

namespace halco {
namespace hicann {
namespace v2 {

SynapseSwitchRowOnHICANN::SynapseSwitchRowOnHICANN(SynapseDriverOnHICANN const& drv)
    : grid_type(drv.x(), drv.y()) {}

QuadrantOnHICANN SynapseSwitchRowOnHICANN::toQuadrantOnHICANN() const {
	return QuadrantOnHICANN(X(toSideHorizontal()), Y(toSideVertical()));
}

SynapseDriverOnHICANN SynapseSwitchRowOnHICANN::toSynapseDriverOnHICANN() const {
	return SynapseDriverOnHICANN(y(), x());
}

SynapseDriverOnWafer SynapseSwitchRowOnWafer::toSynapseDriverOnWafer() const {
	auto const hicann = toHICANNOnWafer();
	auto const quadrant = toQuadrantOnHICANN();
	auto const side_horizontal = toSideHorizontal();

	bool const even_line = (y() % 2 == 0);
	bool const odd_line = !even_line;

	bool const has_local_driver =
	    ((quadrant == QuadrantOnHICANN(left, top)) && odd_line) ||
	    ((quadrant == QuadrantOnHICANN(right, top)) && even_line) ||
	    ((quadrant == QuadrantOnHICANN(left, bottom)) && even_line) ||
	    ((quadrant == QuadrantOnHICANN(right, bottom)) && odd_line);

	return has_local_driver
	           ? SynapseDriverOnWafer(toSynapseDriverOnHICANN(), hicann)
	           : SynapseDriverOnWafer(
	                 SynapseDriverOnHICANN(y(),
	                                       (side_horizontal == left) ? right : left),
	                 (side_horizontal == left) ? hicann.west() : hicann.east());
}

SynapseArrayOnHICANN SynapseSwitchRowOnHICANN::toSynapseArrayOnHICANN() const {
	return SynapseArrayOnHICANN(toSideVertical());
}

SendingRepeaterOnHICANN SynapseDriverOnHICANN::toSendingRepeaterOnHICANN() const {
	if (y() < 112)
		return SendingRepeaterOnHICANN(7 - ((y() / 2) % 8));
	else
		return SendingRepeaterOnHICANN((y() / 2) % 8);
}

SynapseDriverOnQuadrant SynapseDriverOnHICANN::toSynapseDriverOnQuadrant() const {
	return SynapseDriverOnQuadrant((y() / 2) % (y_type::end / 4));
}

QuadrantOnHICANN SynapseDriverOnHICANN::toQuadrantOnHICANN() const {
	return QuadrantOnHICANN(X(toSideHorizontal()), Y(toSideVertical()));
}

SynapseDriverOnHICANN SynapseDriverOnQuadrant::toSynapseDriverOnHICANN(
	QuadrantOnHICANN const& qq) const {

	return SynapseDriverOnHICANN(
		qq.x(), Y((qq.y() * end + *this) * 2 + ((!qq.x() xor qq.y()) ? 1 : 0)));
}

FGBlockOnHICANN SynapseDriverOnHICANN::toFGBlockOnHICANN() const {
	return FGBlockOnHICANN(X(toSideHorizontal()), Y(line() < 112 ? 0 : 1));
}

SynapseDriverOnHICANN::enum_type
SynapseDriverOnHICANN::to_enum(x_type const& x, y_type const& y) {
	bool const is_bottom = y / (y_type::end / 2);
	bool const is_even = !(y % 2);
	if (is_even == (!is_bottom xor x)) {
		std::stringstream err;
		err << "SynapseDriverOnHICANN: Invalid combination of line and side: ";
		err << x << ", ";
		err << y;
		throw std::invalid_argument(err.str());
//			"SynapseDriverOnHICANN: Invalid combination of line and side");
	}
	return enum_type(y);
}

SynapseArrayOnHICANN SynapseDriverOnHICANN::toSynapseArrayOnHICANN() const {
	return SynapseArrayOnHICANN(toSideVertical());
}

SynapseRowOnArray SynapseRowOnHICANN::toSynapseRowOnArray() const
{
	if (toSynapseArrayOnHICANN().isTop()) {
		return SynapseRowOnArray(value());
	} else {
		return SynapseRowOnArray(value() - SynapseRowOnArray::end);
	}
}

SynapseRowOnHICANN::SynapseRowOnHICANN(SynapseRowOnArray const& row,
                                       SynapseArrayOnHICANN const& synarray)
{
	if (synarray.isTop()) {
		*this = SynapseRowOnHICANN(row.value());
	} else {
		*this = SynapseRowOnHICANN(SynapseRowOnArray::end + row.value());
	}
}

SynapseRowOnArray::SynapseRowOnArray(SynapseDriverOnHICANN const& drv,
                                     RowOnSynapseDriver const& row)
{
	if (drv.y() < (SynapseRowOnArray::end / 2)) {
		*this = SynapseRowOnArray(drv.y() * 2 + row);
	} else {
		*this = SynapseRowOnArray(drv.y() * 2 + row - SynapseRowOnArray::end);
	}
}

} // v2
} // hicann
} // halco
