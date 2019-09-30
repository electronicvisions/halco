#include "halco/hicann/v2/external.h"
#include "halco/hicann/v2/l1.h"
#include "halco/hicann/v2/neuron.h"
#include "halco/hicann/v2/synapse.h"

#include "halco/common/iter_all.h"

using namespace halco::common;

namespace halco {
namespace hicann {
namespace v2 {

const CrossbarSwitchOnHICANN::enum_type::value_type CrossbarSwitchOnHICANN::periods;
const CrossbarSwitchOnHICANN::enum_type::value_type CrossbarSwitchOnHICANN::period;
const CrossbarSwitchOnHICANN::enum_type::value_type CrossbarSwitchOnHICANN::period_length;
const CrossbarSwitchOnHICANN::enum_type::value_type CrossbarSwitchOnHICANN::v_period_length;
const CrossbarSwitchOnHICANN::enum_type::value_type CrossbarSwitchOnHICANN::per_column;
const CrossbarSwitchOnHICANN::enum_type::value_type CrossbarSwitchOnHICANN::per_row;
const CrossbarSwitchOnHICANN::enum_type::value_type CrossbarSwitchOnHICANN::per_side;
const CrossbarSwitchOnHICANN::enum_type::value_type CrossbarSwitchOnHICANN::per_half;

CrossbarSwitchOnHICANN::CrossbarSwitchOnHICANN(
    HLineOnHICANN const& l, common::SideHorizontal const& s, CrossbarSwitchOnCrossbarSwitchRow const& switch_num)
{
	mX = to_x(enum_type(l.value() * per_row + s.value() * per_side + switch_num.x().value()));
	mY = y_type(l.value());
}

std::array<CrossbarSwitchOnHICANN::y_type, CrossbarSwitchOnHICANN::per_column>
CrossbarSwitchOnHICANN::column(x_type x)
{
	auto offset = x.value() % period * v_period_length;
	if (x < x_type::size / 2) {
		offset = y_type::size - v_period_length - offset;
	}
	// clang-format off
	return std::array<y_type, per_column>{{
		y_type(offset),
		y_type(offset + 1)
	}};
	// clang-format on
}

bool CrossbarSwitchOnHICANN::exists(x_type x, y_type y)
{
	auto possible_y_value = x.value() % period * v_period_length;
	if (x < x_type::size / 2) {
		possible_y_value = y_type::size - v_period_length - possible_y_value;
	}
	return y.value() == possible_y_value || y.value() == possible_y_value + 1;
}


CrossbarSwitchOnHICANN::x_type CrossbarSwitchOnHICANN::to_x(enum_type const& e)
{
	const auto row = e.value() / per_row;
	const auto h_position = e.value() % per_row;
	if (h_position < per_side) {
		// left side
		return x_type(h_position * period + period - 1 - row / v_period_length);
	} else {
		// right side
		return x_type(h_position * period + row / v_period_length);
	}
}

CrossbarSwitchOnHICANN::y_type CrossbarSwitchOnHICANN::to_y(enum_type const& e)
{
	return y_type(e.value() / per_row);
}

CrossbarSwitchOnHICANN::enum_type CrossbarSwitchOnHICANN::to_enum(x_type const& x, y_type const& y)
{
	if (!exists(x, y))
		throw std::domain_error("Invalid combination of X and Y for a CrossbarSwitch");
	return enum_type(y.value() * per_row + x.value() / period);
}

const SynapseSwitchOnHICANN::enum_type::value_type SynapseSwitchOnHICANN::periods;
const SynapseSwitchOnHICANN::enum_type::value_type SynapseSwitchOnHICANN::period;
const SynapseSwitchOnHICANN::enum_type::value_type SynapseSwitchOnHICANN::period_length;
const SynapseSwitchOnHICANN::enum_type::value_type SynapseSwitchOnHICANN::per_column;
const SynapseSwitchOnHICANN::enum_type::value_type SynapseSwitchOnHICANN::per_row;
const SynapseSwitchOnHICANN::enum_type::value_type SynapseSwitchOnHICANN::per_side;
const SynapseSwitchOnHICANN::enum_type::value_type SynapseSwitchOnHICANN::per_half;
const SynapseSwitchOnHICANN::enum_type::value_type SynapseSwitchOnHICANN::v_period;
const SynapseSwitchOnHICANN::enum_type::value_type SynapseSwitchOnHICANN::v_period_length;

SynapseSwitchOnHICANN::SynapseSwitchOnHICANN(
    SynapseSwitchRowOnHICANN const& r, SynapseSwitchOnSynapseSwitchRow const& switch_in_row)
{
	mX = to_x(enum_type(r.y().value() * per_row + r.x().value() * per_side + switch_in_row.x().value()));
	mY = y_type(r.y());
}

std::array<SynapseSwitchOnHICANN::y_type, SynapseSwitchOnHICANN::per_column>
SynapseSwitchOnHICANN::column(x_type x)
{
	auto offset = x.value() % period / period_length * v_period_length;
	if (x >= x_type::size/2)
		offset = v_period - v_period_length - offset;

	// clang-format off
	return std::array<y_type, per_column>{{
		y_type(0   + offset),
		y_type(1   + offset),
		y_type(16  + offset),
		y_type(17  + offset),
		y_type(32  + offset),
		y_type(33  + offset),
		y_type(48  + offset),
		y_type(49  + offset),
		y_type(64  + offset),
		y_type(65  + offset),
		y_type(80  + offset),
		y_type(81  + offset),
		y_type(96  + offset),
		y_type(97  + offset),
		y_type(126 - offset),
		y_type(127 - offset),
		y_type(142 - offset),
		y_type(143 - offset),
		y_type(158 - offset),
		y_type(159 - offset),
		y_type(174 - offset),
		y_type(175 - offset),
		y_type(190 - offset),
		y_type(191 - offset),
		y_type(206 - offset),
		y_type(207 - offset),
		y_type(222 - offset),
		y_type(223 - offset)
	}};
	// clang-format on
}

bool SynapseSwitchOnHICANN::exists(x_type x, y_type y)
{
	// Synapse switches are grouped in groups of 4 (=period_length)
	// the pattern is repeated every 32 (=period)
	size_t x_mod = (x % period) / period_length;
	size_t y_mod = (y % v_period) / v_period_length;

	// top left or bottom right
	if ((x.value() < x_type::size/2) ^ (y.value() >= y_type::size/2))
		return y_mod == x_mod;
	else
		return (7-y_mod) == x_mod;
}

SynapseSwitchOnHICANN::x_type
SynapseSwitchOnHICANN::to_x(enum_type const& e)
{
	const auto row = e.value() / per_row;
	const auto dense_column = e.value() % per_row;
	const auto x = (dense_column / period_length) * period + dense_column % period_length;
	const auto offset = ((row/2) % periods) * period_length;

	// top left or bottom right
	if ((dense_column < per_side) ^ (e.value() >= per_half))
		return x_type(x + offset);
	else
		return x_type(period - offset + x - period_length);
}

SynapseSwitchOnHICANN::y_type
SynapseSwitchOnHICANN::to_y(enum_type const& e)
{
	return y_type(e.value() / per_row);
}

SynapseSwitchOnHICANN::enum_type
SynapseSwitchOnHICANN::to_enum(x_type const& x, y_type const& y)
{
	if (!exists(x,y))
		throw std::domain_error(
				"Invalid combination of X and Y for a SynapseSwitch");
	// Synapse switches are grouped in groups of 4 (=period_length)
	// the pattern is repeated every 32 (=period)
	const auto offset = x.value() % period_length;
	const auto in_period = x.value() / period;
	const auto column = in_period * period_length + offset;
	return enum_type(y.value() * per_row + column);
}

HRepeaterOnHICANN HLineOnHICANN::toHRepeaterOnHICANN() const {
	return HRepeaterOnHICANN(*this, (value() % 2) ? right : left);
}

HRepeaterOnHICANN HLineOnHICANN::toRepeaterOnHICANN() const {
	return toHRepeaterOnHICANN();
}

TestPortOnRepeaterBlock HRepeaterOnHICANN::toTestPortOnRepeaterBlock() const {
	static const size_t tps[4] = {1, 1, 0, 0};
	if (!isSending()) {
		return TestPortOnRepeaterBlock(tps[y().value() % 4]);
	}
	throw std::runtime_error("test port not available for sending repeater");
}

size_t const VLineOnHICANN::switches_per_side;

std::array<VLineOnHICANN, 8> HLineOnHICANN::toVLineOnHICANN() const {
	const VLineOnHICANN::value_type offset_l = (31 - value() / 2);
	const VLineOnHICANN::value_type offset_r = (value() / 2);

	// clang-format off
	return std::array<VLineOnHICANN, 8>{{
		VLineOnHICANN{0   + offset_l},
		VLineOnHICANN{32  + offset_l},
		VLineOnHICANN{64  + offset_l},
		VLineOnHICANN{96  + offset_l},
		VLineOnHICANN{128 + offset_r},
		VLineOnHICANN{160 + offset_r},
		VLineOnHICANN{192 + offset_r},
		VLineOnHICANN{224 + offset_r}}};
	// clang-format on
}

std::array<VLineOnHICANN, 4> HLineOnHICANN::toVLineOnHICANN(SideHorizontal s) const {
	if (s == left) {
		const VLineOnHICANN::value_type offset_l = (31 - value() / 2);

		// clang-format off
		return std::array<VLineOnHICANN, 4>{{
			VLineOnHICANN{0   + offset_l},
			VLineOnHICANN{32  + offset_l},
			VLineOnHICANN{64  + offset_l},
			VLineOnHICANN{96  + offset_l}}};
		// clang-format on
	} else {
		const VLineOnHICANN::value_type offset_r = (value() / 2);

		// clang-format off
		return std::array<VLineOnHICANN, 4>{{
			VLineOnHICANN{128 + offset_r},
			VLineOnHICANN{160 + offset_r},
			VLineOnHICANN{192 + offset_r},
			VLineOnHICANN{224 + offset_r}}};
		// clang-format on
	}
}

VLineOnHICANN HLineOnHICANN::toVLineOnHICANN(SideHorizontal const side, size_t const num) const {
	if (num > 3)
		throw std::invalid_argument("non-existent vertical line");

	if (side == left)
		return VLineOnHICANN(127 - value() / 2 - (3 - num) * 32);
	else
		return VLineOnHICANN(128 + value() / 2 + num * 32);
}

VRepeaterOnHICANN VLineOnHICANN::toVRepeaterOnHICANN() const {
	if (toSideHorizontal() == left)
		return VRepeaterOnHICANN(*this, (value() % 2) ? top : bottom);
	else
		return VRepeaterOnHICANN(*this, (value() % 2) ? bottom : top);
}

VRepeaterOnHICANN VLineOnHICANN::toRepeaterOnHICANN() const {
	return toVRepeaterOnHICANN();
}

SynapseSwitchRowOnHICANN VLineOnHICANN::toSynapseSwitchRowOnHICANN(
	SideVertical const side_vert, size_t const num) const
{
	if (!(num < switches_per_side))
		throw std::invalid_argument("non-existent switch row");

	const size_t distance = 16;
	const size_t length = 2;
	auto side =	toSideHorizontal();

	if (side == left) {
		if (side_vert == top) {
			size_t y = (num / length) * distance;
			y += num % length;
			y += ((value() % 32) / 4) * 2;
			return SynapseSwitchRowOnHICANN(side, Y(y));
		} else {
			size_t y = 223 - toSynapseSwitchRowOnHICANN(top, Enum(13 - num)).line();
			return SynapseSwitchRowOnHICANN(side, Y(y));
		}
	} else {
		VLineOnHICANN temp(max - value());
		auto temp2 = temp.toSynapseSwitchRowOnHICANN(side_vert, num);
		return SynapseSwitchRowOnHICANN(side, temp2.line());
	}
}

std::array<SynapseSwitchRowOnHICANN, VLineOnHICANN::switches_per_side>
VLineOnHICANN::toSynapseSwitchRowOnHICANN(SideVertical const side_vert) const
{
	std::array<SynapseSwitchRowOnHICANN, switches_per_side> synapse_switch_rows;
	for (size_t num = 0; num != switches_per_side; ++num) {
		synapse_switch_rows[num] = toSynapseSwitchRowOnHICANN(side_vert, num);
	}
	return synapse_switch_rows;
}

std::array<SynapseSwitchRowOnHICANN, 2 * VLineOnHICANN::switches_per_side>
VLineOnHICANN::toSynapseSwitchRowOnHICANN() const
{
	std::array<SynapseSwitchRowOnHICANN, 2 * switches_per_side> synapse_switch_rows;
	for (size_t num = 0; num != switches_per_side; ++num) {
		synapse_switch_rows[num] = toSynapseSwitchRowOnHICANN(top, num);
		synapse_switch_rows[num + switches_per_side] =
		    toSynapseSwitchRowOnHICANN(bottom, num);
	}
	return synapse_switch_rows;
}

std::array<SynapseDriverOnHICANN, VLineOnHICANN::switches_per_side>
VLineOnHICANN::toSynapseDriverOnHICANN(SideHorizontal const& side) const
{
	const auto column = SynapseSwitchOnHICANN::column(X(value()));
	// Check which of the to adjacent rows to select to determine the
	// correct synapse driver
	const size_t offset = (side == left) ? 1 : 0;

	// clang-format off
	return std::array<SynapseDriverOnHICANN, column.size() / 2>{{
		SynapseDriverOnHICANN(side, column[ 0 + offset]),
		SynapseDriverOnHICANN(side, column[ 2 + offset]),
		SynapseDriverOnHICANN(side, column[ 4 + offset]),
		SynapseDriverOnHICANN(side, column[ 6 + offset]),
		SynapseDriverOnHICANN(side, column[ 8 + offset]),
		SynapseDriverOnHICANN(side, column[10 + offset]),
		SynapseDriverOnHICANN(side, column[12 + offset]),
		SynapseDriverOnHICANN(side, column[15 - offset]),
		SynapseDriverOnHICANN(side, column[17 - offset]),
		SynapseDriverOnHICANN(side, column[19 - offset]),
		SynapseDriverOnHICANN(side, column[21 - offset]),
		SynapseDriverOnHICANN(side, column[23 - offset]),
		SynapseDriverOnHICANN(side, column[25 - offset]),
		SynapseDriverOnHICANN(side, column[27 - offset])
	}};
	// clang-format on
}
HRepeaterOnHICANN SendingRepeaterOnHICANN::toHRepeaterOnHICANN() const {
	return HRepeaterOnHICANN(*this);
}

HLineOnHICANN SendingRepeaterOnHICANN::toHLineOnHICANN() const {
	return toHRepeaterOnHICANN().toHLineOnHICANN();
}
DNCMergerOnHICANN SendingRepeaterOnHICANN::toDNCMergerOnHICANN() const {
	return DNCMergerOnHICANN(max - value());
}

GbitLinkOnHICANN SendingRepeaterOnHICANN::toGbitLinkOnHICANN() const {
	return GbitLinkOnHICANN(max - value());
}
RepeaterBlockOnHICANN SendingRepeaterOnHICANN::toRepeaterBlockOnHICANN() const {
	return toHRepeaterOnHICANN().toRepeaterBlockOnHICANN();
}

bool HRepeaterOnHICANN::isSending() const {
	return std::find(spl1.begin(), spl1.end(), toHLineOnHICANN()) != spl1.end();
}

SendingRepeaterOnHICANN HRepeaterOnHICANN::toSendingRepeaterOnHICANN() const {
	auto it = std::find(spl1.begin(), spl1.end(), toHLineOnHICANN());

	if (it == spl1.end())
		throw std::runtime_error("sending() used on non-sending repeater");

	return SendingRepeaterOnHICANN(std::distance(spl1.begin(), it));
}


// clang-format off
typedef HLineOnHICANN _h;
std::array<HLineOnHICANN, 8> const HRepeaterOnHICANN::spl1 =
	{{ _h{6}, _h{14}, _h{22}, _h{30}, _h{38}, _h{46}, _h{54}, _h{62} }};
// clang-format on

NeuronBlockOnHICANN BackgroundGeneratorOnHICANN::toNeuronBlockOnHICANN() const {
	return NeuronBlockOnHICANN(value());
}

SendingRepeaterOnHICANN DNCMergerOnHICANN::toSendingRepeaterOnHICANN() const {
	// DNC merger 0 corresponds to sending repater 7 and so on...
	return SendingRepeaterOnHICANN(max - value());
}

HRepeaterOnWafer HLineOnWafer::toHRepeaterOnWafer() const
{
	return HRepeaterOnWafer(toHLineOnHICANN().toHRepeaterOnHICANN(), toHICANNOnWafer());
}

VRepeaterOnWafer VLineOnWafer::toVRepeaterOnWafer() const
{
	return VRepeaterOnWafer(toVLineOnHICANN().toVRepeaterOnHICANN(), toHICANNOnWafer());
}

} // v2
} // hicann
} // halco
