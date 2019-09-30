#pragma once

extern "C" {
#include <stdint.h>
}

// std::array for pypp
#include "pywrap/compat/array.hpp"

#include "pywrap/compat/macros.hpp"

#include "halco/common/geometry.h"
#include "halco/common/tblr.h"
#include "halco/common/relations.h"

#include "halco/hicann/v2/fwd.h"
#include "halco/hicann/v2/hicann.h"
#include "halco/hicann/v2/synapse.h"

namespace halco {
namespace hicann {
namespace v2 {


struct CrossbarSwitchOnCrossbarSwitchRow
    : public common::detail::GridCoordinate<
          CrossbarSwitchOnCrossbarSwitchRow,
          common::XRanged<4, 0>,
          common::YRanged<1, 0>,
          4>
{
	GRID_COMMON_CONSTRUCTORS(CrossbarSwitchOnCrossbarSwitchRow)
};

struct SynapseSwitchOnSynapseSwitchRow
    : public common::detail::GridCoordinate<
          SynapseSwitchOnSynapseSwitchRow,
          common::XRanged<16, 0>,
          common::YRanged<1, 0>,
          16>
{
	GRID_COMMON_CONSTRUCTORS(SynapseSwitchOnSynapseSwitchRow)
};

struct CrossbarSwitchOnHICANN
    : public common::detail::GridCoordinate<
          CrossbarSwitchOnHICANN,
          common::XRanged<255, 0>,
          common::YRanged<63, 0>,
          8 * 64>
{
	GRID_COMMON_CONSTRUCTORS(CrossbarSwitchOnHICANN)

	// get CrossbarSwitch from Hline, Side and number of switch in row on side
	CrossbarSwitchOnHICANN(
	    HLineOnHICANN const& l, common::SideHorizontal const& s, CrossbarSwitchOnCrossbarSwitchRow const& switch_num);

	static const enum_type::value_type periods = 8;
	static const enum_type::value_type period = x_type::size / periods;
	static const enum_type::value_type period_length = 1;
	static const enum_type::value_type v_period_length = 2;
	static const enum_type::value_type per_row = 8;
	static const enum_type::value_type per_column = 2;
	static const enum_type::value_type per_side = per_row / 2;
	static const enum_type::value_type per_half = enum_type::size / 2;

	static std::array<y_type, per_column> column(x_type x);
	static bool exists(x_type x, y_type y);
	static x_type to_x(enum_type const& e);
	static y_type to_y(enum_type const& e);
	static enum_type to_enum(x_type const& x, y_type const& y);
};

struct SynapseSwitchOnHICANN
	: public common::detail::GridCoordinate<SynapseSwitchOnHICANN, common::XRanged<255, 0>,
	                                        common::YRanged<223, 0>, 32 * 224> {
	GRID_COMMON_CONSTRUCTORS(SynapseSwitchOnHICANN)

	// get SynapseSwitch from SynapseSwitchRow and number of switch in SynapseSwitchRow
	SynapseSwitchOnHICANN(SynapseSwitchRowOnHICANN const& r, SynapseSwitchOnSynapseSwitchRow const& switch_in_row);

	static const enum_type::value_type periods = 8;
	static const enum_type::value_type period  = x_type::size / periods;
	static const enum_type::value_type period_length = 4;
	static const enum_type::value_type v_period = 16;
	static const enum_type::value_type v_period_length = 2;
	static const enum_type::value_type per_row = 32;
	static const enum_type::value_type per_column = 28;
	static const enum_type::value_type per_side = per_row/2;
	static const enum_type::value_type per_half = enum_type::size/2;

	static std::array<y_type, per_column> column(x_type x);
	static bool exists(x_type x, y_type y);
	static x_type to_x(enum_type const& e);
	static y_type to_y(enum_type const& e);
	static enum_type to_enum(x_type const& x, y_type const& y);
};


struct HLineOnHICANN : public common::detail::RantWrapper<HLineOnHICANN, size_t, 63, 0>,
                       public common::detail::YRangedTrait {
	PYPP_CONSTEXPR explicit HLineOnHICANN(common::Y const& y) : rant_t(y.value()) {}
	PYPP_CONSTEXPR explicit HLineOnHICANN(uintmax_t const val = 0) : rant_t(val) {}

	HLineOnHICANN east() const { return HLineOnHICANN((value() + 2) % end); }
	HLineOnHICANN west() const { return HLineOnHICANN((value() + end - 2) % end); }

	HRepeaterOnHICANN toHRepeaterOnHICANN() const;
	HRepeaterOnHICANN toRepeaterOnHICANN() const;

	// TODO: Add simple consistency test for this set of functions
	std::array<VLineOnHICANN, 8> toVLineOnHICANN() const;
	std::array<VLineOnHICANN, 4> toVLineOnHICANN(common::SideHorizontal s) const;

	/**
	 * @brief Return the N-th connected vertical line on the given side of the HICANN.
	 * @param side Determines which crossbar switch matrix to use (left or right)
	 * @param num Index to select one of the four available vertical lines
	 * @throw std::invalid_argument When the index is out of range
	 */
	VLineOnHICANN toVLineOnHICANN(common::SideHorizontal side, size_t num) const;
};

struct VLineOnHICANN : public common::detail::RantWrapper<VLineOnHICANN, size_t, 255, 0>,
                       public common::detail::XRangedTrait,
                       public common::detail::HasLeftRight<VLineOnHICANN> {
	PYPP_CONSTEXPR explicit VLineOnHICANN(common::X const& x) : rant_t(x.value()) {}
	PYPP_CONSTEXPR explicit VLineOnHICANN(uintmax_t const val = 0) : rant_t(val) {}

	static size_t const switches_per_side = 14;

	VRepeaterOnHICANN toVRepeaterOnHICANN() const;
	VRepeaterOnHICANN toRepeaterOnHICANN() const;

	VLineOnHICANN south() const {
		if (value() < end / 2) {
			return VLineOnHICANN((value() + end / 2 - 2) % (end / 2));
		} else {
			return VLineOnHICANN(end / 2 + (value() - end / 2 + 2) % (end / 2));
		}
	}

	VLineOnHICANN north() const {
		if (value() < end / 2) {
			return VLineOnHICANN((value() + 2) % (end / 2));
		} else {
			return VLineOnHICANN(end / 2 + (value() - end / 2 - 2) % (end / 2));
		}
	}

	/**
	 * @brief Return the N-th connected synapse switch row on the top/bottom of the HICANN.
	 * @param side_vert Determines which synapse switch matrix to use (top or bottom)
	 * @param num Index to select one of the fourteen available switch rows
	 * @throw std::invalid_argument When the index is out of range
	 */
	SynapseSwitchRowOnHICANN toSynapseSwitchRowOnHICANN(
		common::SideVertical side_vert, size_t num) const;

	std::array<SynapseSwitchRowOnHICANN, switches_per_side> toSynapseSwitchRowOnHICANN(
	    common::SideVertical side_vert) const;

	std::array<SynapseSwitchRowOnHICANN, 2 * switches_per_side>
	toSynapseSwitchRowOnHICANN() const;

	/// Return synapse drivers reachable from this vline that are on the
	/// specified side of this or the adjacent hicann.
	std::array<SynapseDriverOnHICANN, switches_per_side> toSynapseDriverOnHICANN(
		common::SideHorizontal const& side) const;
};

class HRepeaterOnWafer;

struct HLineOnWafer : public HICANNMixin<HLineOnWafer, HLineOnHICANN>
{
private:
	typedef HICANNMixin<HLineOnWafer, HLineOnHICANN> base;

public:
	using base::enum_type;

	PYPP_DEFAULT(HLineOnWafer());

	explicit HLineOnWafer(
	    HLineOnHICANN const& hline, HICANNOnWafer const& h = HICANNOnWafer())
	    : base(hline, h)
	{}

	explicit HLineOnWafer(enum_type const& e) : base(e) {}

	HLineOnHICANN toHLineOnHICANN() const { return This(); }
	HRepeaterOnWafer toHRepeaterOnWafer() const;
};

class VRepeaterOnWafer;

struct VLineOnWafer : public HICANNMixin<VLineOnWafer, VLineOnHICANN>
{
private:
	typedef HICANNMixin<VLineOnWafer, VLineOnHICANN> base;

public:
	using base::enum_type;

	PYPP_DEFAULT(VLineOnWafer());

	explicit VLineOnWafer(
	    VLineOnHICANN const& hline, HICANNOnWafer const& h = HICANNOnWafer())
	    : base(hline, h)
	{}

	explicit VLineOnWafer(enum_type const& e) : base(e) {}

	VLineOnHICANN toVLineOnHICANN() const { return This(); }
	VRepeaterOnWafer toVRepeaterOnWafer() const;
};


struct BackgroundGeneratorOnHICANN
    : public common::detail::RantWrapper<BackgroundGeneratorOnHICANN, uint_fast16_t, 7, 0> {
	PYPP_CONSTEXPR explicit BackgroundGeneratorOnHICANN(uintmax_t const val = 0)
	    : rant_t(val) {}

	NeuronBlockOnHICANN toNeuronBlockOnHICANN() const;
};

struct DNCMergerOnHICANN : public common::detail::RantWrapper<DNCMergerOnHICANN, uint_fast16_t, 7, 0> {
	PYPP_CONSTEXPR explicit DNCMergerOnHICANN(uintmax_t const val = 0) : rant_t(val) {}

	SendingRepeaterOnHICANN toSendingRepeaterOnHICANN() const;
};

struct DNCMergerOnWafer : public HICANNMixin<DNCMergerOnWafer, DNCMergerOnHICANN> {
private:
	typedef HICANNMixin<DNCMergerOnWafer, DNCMergerOnHICANN> base;

public:
	using base::enum_type;

	PYPP_DEFAULT(DNCMergerOnWafer());

	explicit DNCMergerOnWafer(DNCMergerOnHICANN const& merger,
	                          HICANNOnWafer const& h = HICANNOnWafer())
		: base(merger, h) {}

	explicit DNCMergerOnWafer(enum_type const& e) : base(e) {}

	DNCMergerOnHICANN toDNCMergerOnHICANN() const { return This(); }
};

struct TestPortOnRepeaterBlock : public common::detail::RantWrapper<TestPortOnRepeaterBlock, size_t, 1, 0> {
	PYPP_CONSTEXPR explicit TestPortOnRepeaterBlock(uintmax_t const val = 0) : rant_t(val) {}
};

struct RepeaterBlockOnHICANN
    : public common::detail::GridCoordinate<RepeaterBlockOnHICANN, common::XRanged<1, 0>,
                                            common::YRanged<2, 0> > {
	GRID_COMMON_CONSTRUCTORS(RepeaterBlockOnHICANN)
};

struct SendingRepeaterOnHICANN
    : public common::detail::RantWrapper<SendingRepeaterOnHICANN, size_t, 7, 0> {
	PYPP_CONSTEXPR explicit SendingRepeaterOnHICANN(uintmax_t const val = 0) : rant_t(val) {}

	GbitLinkOnHICANN toGbitLinkOnHICANN() const;
	HLineOnHICANN toHLineOnHICANN() const;
	HRepeaterOnHICANN toHRepeaterOnHICANN() const;
	RepeaterBlockOnHICANN toRepeaterBlockOnHICANN() const;
	DNCMergerOnHICANN toDNCMergerOnHICANN() const;
};

struct HRepeaterOnHICANN
	: public common::detail::GridCoordinate<HRepeaterOnHICANN, common::SideHorizontal,
	                                        HLineOnHICANN, HLineOnHICANN::size>,
	  public common::detail::HasLeftRight<HRepeaterOnHICANN> {
	GRID_COMMON_CONSTRUCTORS(HRepeaterOnHICANN)

	// TODO: Replace with conversion member function for consistency
	explicit HRepeaterOnHICANN(SendingRepeaterOnHICANN const& s)
	    : grid_type(common::left, spl1[s]) {}

	HLineOnHICANN toHLineOnHICANN() const { return mY; }

	RepeaterBlockOnHICANN toRepeaterBlockOnHICANN() const {
		return RepeaterBlockOnHICANN(toSideHorizontal(), common::Y(1));
	}

	TestPortOnRepeaterBlock toTestPortOnRepeaterBlock() const;

	SendingRepeaterOnHICANN toSendingRepeaterOnHICANN() const;

	bool isSending() const;

/* implementation detail, not part of public API: */

	// „even addresses refer to the left border and odd addresses to the right“
	static x_type to_x(enum_type const& e) { return x_type(e % 2); }

	static y_type to_y(enum_type const& e) { return y_type(e); }

	static enum_type to_enum(x_type const& x, y_type const& y) {
		if (x xor y % 2) {
			throw std::invalid_argument(
			    "HRepeaterOnHICANN: Invalid combination of line and side");
		}
		return enum_type(y);
	}

private:
	static std::array<HLineOnHICANN, 8> const spl1;
};


struct HRepeaterOnWafer : public HICANNMixin<HRepeaterOnWafer, HRepeaterOnHICANN>
{
private:
	typedef HICANNMixin<HRepeaterOnWafer, HRepeaterOnHICANN> base;

public:
	using base::enum_type;

	PYPP_DEFAULT(HRepeaterOnWafer());

	explicit HRepeaterOnWafer(
	    HRepeaterOnHICANN const& vrepeater, HICANNOnWafer const& h = HICANNOnWafer())
	    : base(vrepeater, h)
	{}

	explicit HRepeaterOnWafer(enum_type const& e) : base(e) {}

	HRepeaterOnHICANN toHRepeaterOnHICANN() const { return This(); }
};


struct VRepeaterOnHICANN
	: public common::detail::GridCoordinate<VRepeaterOnHICANN, VLineOnHICANN, common::SideVertical,
	                                        VLineOnHICANN::size>,
	  public common::detail::HasTopBottom<VRepeaterOnHICANN> {
	GRID_COMMON_CONSTRUCTORS(VRepeaterOnHICANN)

	VLineOnHICANN toVLineOnHICANN() const { return mX; }

	RepeaterBlockOnHICANN toRepeaterBlockOnHICANN() const {
		return RepeaterBlockOnHICANN(toVLineOnHICANN().toSideHorizontal(),
		                             common::Y(toSideVertical() == common::top ? 0 : 2));
	}

	TestPortOnRepeaterBlock toTestPortOnRepeaterBlock() const {
		// on the common::right hicann.half the hardware channel is counted
		// down from 255
		const size_t channel =
		    x().isLeft() ? x().value()
		                 : (VLineOnHICANN::max + VLineOnHICANN::end / 2) - x().value();
		// channel | test port
		// 0       | 1
		// 1       | 1
		// 2       | 0
		// 3       | 0
		// 4       | 1
		// 5       | 1
		// ...
		const size_t tp = 1-(channel/2)%2;
		return TestPortOnRepeaterBlock(tp);
	}

/* implementation detail, not part of public API: */

	/* „On the left side of the HICANN even vertical lanes connect to
	 * bottom repeaters and odd lanes to top repeaters.  On the right side
	 * even vertical lanes connect to top and odd to bottom repeaters.“
	 * */

	static x_type to_x(enum_type const& e) {
		size_t const addr = e % (enum_type::end / 2);
		bool const is_bottom = e / (enum_type::end / 2);
		bool const is_left = addr < (enum_type::end / 4);

		return x_type(addr * 2 + (is_bottom xor is_left));
	}

	static y_type to_y(enum_type const& e) { return y_type(e / (enum_type::end / 2)); }

	static enum_type to_enum(x_type const& x, y_type const& y) {
		bool const is_bottom = y;
		bool const is_right = x.toSideHorizontal();
		bool const is_even = !(x % 2);

		if ((is_bottom xor !is_right) xor is_even)
			return enum_type(y * enum_type::end / 2 + x / 2);
		throw std::invalid_argument(
		    "VRepeaterOnHICANN: Invalid combination of line and side");
	}
};

struct VRepeaterOnWafer : public HICANNMixin<VRepeaterOnWafer, VRepeaterOnHICANN>
{
private:
	typedef HICANNMixin<VRepeaterOnWafer, VRepeaterOnHICANN> base;

public:
	using base::enum_type;

	PYPP_DEFAULT(VRepeaterOnWafer());

	explicit VRepeaterOnWafer(
	    VRepeaterOnHICANN const& vrepeater, HICANNOnWafer const& h = HICANNOnWafer())
	    : base(vrepeater, h)
	{}

	explicit VRepeaterOnWafer(enum_type const& e) : base(e) {}

	VRepeaterOnHICANN toVRepeaterOnHICANN() const { return This(); }
};

} // v2
} // hicann
} // halco

// std::hash specializations
namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::HLineOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::VLineOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::HLineOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::VLineOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::CrossbarSwitchOnCrossbarSwitchRow)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SynapseSwitchOnSynapseSwitchRow)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::CrossbarSwitchOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SynapseSwitchOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::HRepeaterOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::HRepeaterOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::VRepeaterOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::VRepeaterOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::TestPortOnRepeaterBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::RepeaterBlockOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SendingRepeaterOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::BackgroundGeneratorOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::DNCMergerOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::DNCMergerOnWafer)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::HICANNMixin<halco::hicann::v2::DNCMergerOnWafer BOOST_PP_COMMA()
    halco::hicann::v2::DNCMergerOnHICANN>)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::HICANNMixin<halco::hicann::v2::VRepeaterOnWafer BOOST_PP_COMMA()
    halco::hicann::v2::VRepeaterOnHICANN>)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::HICANNMixin<halco::hicann::v2::HRepeaterOnWafer BOOST_PP_COMMA()
    halco::hicann::v2::HRepeaterOnHICANN>)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::HICANNMixin<halco::hicann::v2::HLineOnWafer BOOST_PP_COMMA()
    halco::hicann::v2::HLineOnHICANN>)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::HICANNMixin<halco::hicann::v2::VLineOnWafer BOOST_PP_COMMA()
    halco::hicann::v2::VLineOnHICANN>)

} // std
