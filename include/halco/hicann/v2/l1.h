#pragma once

extern "C" {
#include <stdint.h>
}

// std::array for pypp
#include "pywrap/compat/array.hpp"

#include "pywrap/compat/macros.hpp"

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/relations.h"
#include "halco/common/tblr.h"

#include "halco/hicann/v2/fwd.h"
#include "halco/hicann/v2/hicann.h"
#include "halco/hicann/v2/synapse.h"

#include "boost/optional.hpp"
#include "boost/tuple/tuple.hpp"

#include "hate/visibility.h"

#if defined(__GENPYBIND__) || defined(__GENPYBIND_GENERATED__)
#include <pybind11/stl.h>
namespace pybind11 {
namespace detail {
template <typename T>
struct type_caster<boost::optional<T>> : optional_caster<boost::optional<T>>
{};
}
}
#endif

namespace halco {
namespace hicann {
namespace v2 GENPYBIND_TAG_HALCO_HICANN_V2 {

struct GENPYBIND(inline_base("*")) CrossbarSwitchOnCrossbarSwitchRow
    : public common::detail::GridCoordinate<
          CrossbarSwitchOnCrossbarSwitchRow,
          common::XRanged<4, 0>,
          common::YRanged<1, 0>,
          4>
{
	GRID_COMMON_CONSTRUCTORS(CrossbarSwitchOnCrossbarSwitchRow)
};

struct GENPYBIND(inline_base("*")) SynapseSwitchOnSynapseSwitchRow
    : public common::detail::GridCoordinate<
          SynapseSwitchOnSynapseSwitchRow,
          common::XRanged<16, 0>,
          common::YRanged<1, 0>,
          16>
{
	GRID_COMMON_CONSTRUCTORS(SynapseSwitchOnSynapseSwitchRow)
};

struct GENPYBIND(inline_base("*")) CrossbarSwitchOnHICANN
    : public common::detail::GridCoordinate<
          CrossbarSwitchOnHICANN,
          common::XRanged<255, 0>,
          common::YRanged<63, 0>,
          8 * 64>
{
	GRID_COMMON_CONSTRUCTORS(CrossbarSwitchOnHICANN)

	// get CrossbarSwitch from Hline, Side and number of switch in row on side
	CrossbarSwitchOnHICANN(
	    HLineOnHICANN const& l,
	    common::SideHorizontal const& s,
	    CrossbarSwitchOnCrossbarSwitchRow const& switch_num) SYMBOL_VISIBLE;

	static const SYMBOL_VISIBLE enum_type::value_type periods = 8;
	static const SYMBOL_VISIBLE enum_type::value_type period = x_type::size / periods;
	static const SYMBOL_VISIBLE enum_type::value_type period_length = 1;
	static const SYMBOL_VISIBLE enum_type::value_type v_period_length = 2;
	static const SYMBOL_VISIBLE enum_type::value_type per_row = 8;
	static const SYMBOL_VISIBLE enum_type::value_type per_column = 2;
	static const SYMBOL_VISIBLE enum_type::value_type per_side = per_row / 2;
	static const SYMBOL_VISIBLE enum_type::value_type per_half = enum_type::size / 2;

	static std::array<y_type, halco::hicann::v2::CrossbarSwitchOnHICANN::per_column> column(
	    x_type x) SYMBOL_VISIBLE;
	static bool exists(x_type x, y_type y) SYMBOL_VISIBLE;
	static x_type to_x(enum_type const& e) SYMBOL_VISIBLE;
	static y_type to_y(enum_type const& e) SYMBOL_VISIBLE;
	static enum_type to_enum(x_type const& x, y_type const& y) SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*")) SynapseSwitchOnHICANN
    : public common::detail::GridCoordinate<
          SynapseSwitchOnHICANN,
          common::XRanged<255, 0>,
          common::YRanged<223, 0>,
          32 * 224>
{
	GRID_COMMON_CONSTRUCTORS(SynapseSwitchOnHICANN)

	// get SynapseSwitch from SynapseSwitchRow and number of switch in SynapseSwitchRow
	SynapseSwitchOnHICANN(
	    SynapseSwitchRowOnHICANN const& r,
	    SynapseSwitchOnSynapseSwitchRow const& switch_in_row) SYMBOL_VISIBLE;

	static const SYMBOL_VISIBLE enum_type::value_type periods = 8;
	static const SYMBOL_VISIBLE enum_type::value_type period = x_type::size / periods;
	static const SYMBOL_VISIBLE enum_type::value_type period_length = 4;
	static const SYMBOL_VISIBLE enum_type::value_type v_period = 16;
	static const SYMBOL_VISIBLE enum_type::value_type v_period_length = 2;
	static const SYMBOL_VISIBLE enum_type::value_type per_row = 32;
	static const SYMBOL_VISIBLE enum_type::value_type per_column = 28;
	static const SYMBOL_VISIBLE enum_type::value_type per_side = per_row / 2;
	static const SYMBOL_VISIBLE enum_type::value_type per_half = enum_type::size / 2;

	static std::array<y_type, halco::hicann::v2::SynapseSwitchOnHICANN::per_column> column(x_type y)
	    SYMBOL_VISIBLE;
	static bool exists(x_type x, y_type y) SYMBOL_VISIBLE;
	static x_type to_x(enum_type const& e) SYMBOL_VISIBLE;
	static y_type to_y(enum_type const& e) SYMBOL_VISIBLE;
	static enum_type to_enum(x_type const& x, y_type const& y) SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*")) HLineOnHICANN
    : public common::detail::RantWrapper<HLineOnHICANN, size_t, 63, 0>
    , public common::detail::YRangedTrait
{
	PYPP_CONSTEXPR explicit HLineOnHICANN(common::Y const& y) GENPYBIND(implicit_conversion) :
	    rant_t(y.value())
	{}
	PYPP_CONSTEXPR explicit HLineOnHICANN(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	HLineOnHICANN east() const { return HLineOnHICANN((value() + 2) % end); }
	HLineOnHICANN west() const { return HLineOnHICANN((value() + end - 2) % end); }

	HRepeaterOnHICANN toHRepeaterOnHICANN() const SYMBOL_VISIBLE;
	HRepeaterOnHICANN toRepeaterOnHICANN() const SYMBOL_VISIBLE;

	// TODO: Add simple consistency test for this set of functions
	std::array<VLineOnHICANN, 8> toVLineOnHICANN() const SYMBOL_VISIBLE;
	std::array<VLineOnHICANN, 4> toVLineOnHICANN(common::SideHorizontal s) const SYMBOL_VISIBLE;

	/**
	 * @brief Return the N-th connected vertical line on the given side of the HICANN.
	 * @param side Determines which crossbar switch matrix to use (left or right)
	 * @param num Index to select one of the four available vertical lines
	 * @throw std::invalid_argument When the index is out of range
	 */
	VLineOnHICANN toVLineOnHICANN(common::SideHorizontal side, size_t num) const SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*")) VLineOnHICANN
    : public common::detail::RantWrapper<VLineOnHICANN, size_t, 255, 0>
    , public common::detail::XRangedTrait
    , public common::detail::HasLeftRight<VLineOnHICANN>
{
	PYPP_CONSTEXPR explicit VLineOnHICANN(common::X const& x) GENPYBIND(implicit_conversion) :
	    rant_t(x.value())
	{}
	PYPP_CONSTEXPR explicit VLineOnHICANN(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static SYMBOL_VISIBLE size_t const switches_per_side = 14;

	VRepeaterOnHICANN toVRepeaterOnHICANN() const SYMBOL_VISIBLE;
	VRepeaterOnHICANN toRepeaterOnHICANN() const SYMBOL_VISIBLE;

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
	    common::SideVertical side_vert, size_t num) const SYMBOL_VISIBLE;

	std::array<SynapseSwitchRowOnHICANN, halco::hicann::v2::VLineOnHICANN::switches_per_side>
	toSynapseSwitchRowOnHICANN(common::SideVertical side_vert) const SYMBOL_VISIBLE;

	std::array<SynapseSwitchRowOnHICANN, 2 * halco::hicann::v2::VLineOnHICANN::switches_per_side>
	toSynapseSwitchRowOnHICANN() const SYMBOL_VISIBLE;

	/// Return synapse drivers reachable from this vline that are on the
	/// specified side of this or the adjacent hicann.
	std::array<SynapseDriverOnHICANN, halco::hicann::v2::VLineOnHICANN::switches_per_side>
	toSynapseDriverOnHICANN(common::SideHorizontal const& side) const SYMBOL_VISIBLE;

	std::array<HLineOnHICANN, 2> toHLineOnHICANN() const SYMBOL_VISIBLE;
};

struct HRepeaterOnWafer;

struct GENPYBIND(inline_base("*HICANNMixin*")) HLineOnWafer
    : public HICANNMixin<HLineOnWafer, HLineOnHICANN>
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

	/* L1 lines are connected to two L1 repeaters. One on the local
	   HICANN, the other on a neighboring HICANN.

	   The HRepeater on the local HICANN is guaranteed to be in the first element of the tuple.
	 */
	// clang-format off
	boost::tuple<HRepeaterOnWafer, boost::optional<HRepeaterOnWafer> > GENPYBIND(hidden)
	    toHRepeaterOnWafer() const SYMBOL_VISIBLE;
	// clang-format on
	GENPYBIND_MANUAL({
		parent.def("toHRepeaterOnWafer", [](GENPYBIND_PARENT_TYPE const& self) {
			auto const t = self.toHRepeaterOnWafer();
			return std::tuple{t.template get<0>(), t.template get<1>()};
		});
	})
};

struct VRepeaterOnWafer;

struct GENPYBIND(inline_base("*HICANNMixin*")) VLineOnWafer
    : public HICANNMixin<VLineOnWafer, VLineOnHICANN>
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

	/* L1 lines are connected to two L1 repeaters. One on the local
	   HICANN, the other on a neighboring HICANN.

	   The VRepeater on the local HICANN is guaranteed to be in the first element of the tuple.
	 */
	// clang-format off
	boost::tuple<VRepeaterOnWafer, boost::optional<VRepeaterOnWafer> > GENPYBIND(hidden)
	    toVRepeaterOnWafer() const SYMBOL_VISIBLE;
	// clang-format on
	GENPYBIND_MANUAL({
		parent.def("toVRepeaterOnWafer", [](GENPYBIND_PARENT_TYPE const& self) {
			auto const t = self.toVRepeaterOnWafer();
			return std::tuple{t.template get<0>(), t.template get<1>()};
		});
	})
};

struct GENPYBIND(inline_base("*")) BackgroundGeneratorOnHICANN
    : public common::detail::RantWrapper<BackgroundGeneratorOnHICANN, uint_fast16_t, 7, 0>
{
	PYPP_CONSTEXPR explicit BackgroundGeneratorOnHICANN(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	NeuronBlockOnHICANN toNeuronBlockOnHICANN() const SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*")) DNCMergerOnHICANN
    : public common::detail::RantWrapper<DNCMergerOnHICANN, uint_fast16_t, 7, 0>
{
	PYPP_CONSTEXPR explicit DNCMergerOnHICANN(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	SendingRepeaterOnHICANN toSendingRepeaterOnHICANN() const SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*HICANNMixin*")) DNCMergerOnWafer
    : public HICANNMixin<DNCMergerOnWafer, DNCMergerOnHICANN>
{
private:
	typedef HICANNMixin<DNCMergerOnWafer, DNCMergerOnHICANN> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	PYPP_DEFAULT(DNCMergerOnWafer());

	explicit DNCMergerOnWafer(DNCMergerOnHICANN const& merger,
	                          HICANNOnWafer const& h = HICANNOnWafer())
		: base(merger, h) {}

	explicit DNCMergerOnWafer(enum_type const& e) : base(e) {}

	DNCMergerOnHICANN toDNCMergerOnHICANN() const { return This(); }
};

struct GENPYBIND(inline_base("*")) TestPortOnRepeaterBlock
    : public common::detail::RantWrapper<TestPortOnRepeaterBlock, size_t, 1, 0>
{
	PYPP_CONSTEXPR explicit TestPortOnRepeaterBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

// clang-format off
struct GENPYBIND(inline_base("*")) RepeaterBlockOnHICANN
    : public common::detail::
          GridCoordinate<RepeaterBlockOnHICANN, common::XRanged<1, 0>, common::YRanged<2, 0> >
// clang-format on
{
	GRID_COMMON_CONSTRUCTORS(RepeaterBlockOnHICANN)
};

struct GENPYBIND(inline_base("*HICANNMixin*")) RepeaterBlockOnWafer
    : public HICANNMixin<RepeaterBlockOnWafer, RepeaterBlockOnHICANN>
{
private:
	typedef HICANNMixin<RepeaterBlockOnWafer, RepeaterBlockOnHICANN> base;

public:
	using base::enum_type;

	PYPP_DEFAULT(RepeaterBlockOnWafer());

	explicit RepeaterBlockOnWafer(
	    RepeaterBlockOnHICANN const& repeater_block, HICANNOnWafer const& h = HICANNOnWafer())
	    : base(repeater_block, h)
	{}

	explicit RepeaterBlockOnWafer(enum_type const& e) : base(e) {}

	RepeaterBlockOnHICANN toRepeaterBlockOnHICANN() const { return This(); }

};

struct GENPYBIND(inline_base("*")) SendingRepeaterOnHICANN
    : public common::detail::RantWrapper<SendingRepeaterOnHICANN, size_t, 7, 0>
{
	PYPP_CONSTEXPR explicit SendingRepeaterOnHICANN(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	GbitLinkOnHICANN toGbitLinkOnHICANN() const SYMBOL_VISIBLE;
	HLineOnHICANN toHLineOnHICANN() const SYMBOL_VISIBLE;
	HRepeaterOnHICANN toHRepeaterOnHICANN() const SYMBOL_VISIBLE;
	RepeaterBlockOnHICANN toRepeaterBlockOnHICANN() const SYMBOL_VISIBLE;
	DNCMergerOnHICANN toDNCMergerOnHICANN() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*HICANNMixin*")) SendingRepeaterOnWafer
    : public HICANNMixin<SendingRepeaterOnWafer, SendingRepeaterOnHICANN>
{
private:
	typedef HICANNMixin<SendingRepeaterOnWafer, SendingRepeaterOnHICANN> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	PYPP_DEFAULT(SendingRepeaterOnWafer());

	explicit SendingRepeaterOnWafer(
	    SendingRepeaterOnHICANN const& sending_repeater, HICANNOnWafer const& h = HICANNOnWafer()) :
	    base(sending_repeater, h)
	{}

	explicit SendingRepeaterOnWafer(enum_type const& e) : base(e) {}

	SendingRepeaterOnHICANN toSendingRepeaterOnHICANN() const
	{
		return This();
	}
};


struct GENPYBIND(inline_base("*")) HRepeaterOnHICANN
    : public common::detail::GridCoordinate<
          HRepeaterOnHICANN,
          common::SideHorizontal,
          HLineOnHICANN,
          HLineOnHICANN::size>
    , public common::detail::HasLeftRight<HRepeaterOnHICANN>
{
	GRID_COMMON_CONSTRUCTORS(HRepeaterOnHICANN)

	// TODO: Replace with conversion member function for consistency
	explicit HRepeaterOnHICANN(SendingRepeaterOnHICANN const& s)
	    : grid_type(common::left, spl1[s]) {}

	HLineOnHICANN toHLineOnHICANN() const { return mY; }

	RepeaterBlockOnHICANN toRepeaterBlockOnHICANN() const {
		return RepeaterBlockOnHICANN(toSideHorizontal(), common::Y(1));
	}

	TestPortOnRepeaterBlock toTestPortOnRepeaterBlock() const SYMBOL_VISIBLE;

	SendingRepeaterOnHICANN toSendingRepeaterOnHICANN() const SYMBOL_VISIBLE;

	bool isSending() const SYMBOL_VISIBLE;

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
	static SYMBOL_VISIBLE std::array<HLineOnHICANN, 8> const spl1;
};


struct GENPYBIND(inline_base("*HICANNMixin*")) HRepeaterOnWafer
    : public HICANNMixin<HRepeaterOnWafer, HRepeaterOnHICANN>
{
private:
	typedef HICANNMixin<HRepeaterOnWafer, HRepeaterOnHICANN> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	PYPP_DEFAULT(HRepeaterOnWafer());

	explicit HRepeaterOnWafer(
	    HRepeaterOnHICANN const& vrepeater, HICANNOnWafer const& h = HICANNOnWafer())
	    : base(vrepeater, h)
	{}

	explicit HRepeaterOnWafer(enum_type const& e) : base(e) {}

	HRepeaterOnHICANN toHRepeaterOnHICANN() const { return This(); }
	RepeaterBlockOnWafer toRepeaterBlockOnWafer() const {
		return RepeaterBlockOnWafer(toHRepeaterOnHICANN().toRepeaterBlockOnHICANN(),
		                            toHICANNOnWafer());
	}


	/* L1 repeaters are connected to two L1 lines. One on the local
	   HICANN, the other on a neighboring HICANN.

	   The HLine on the local HICANN is guaranteed to be in the first element of the tuple.
	 */
	// clang-format off
	boost::tuple<HLineOnWafer, boost::optional<HLineOnWafer> > GENPYBIND(hidden)
	    toHLineOnWafer() const SYMBOL_VISIBLE;
	// clang-format on
	GENPYBIND_MANUAL({
		parent.def("toHLineOnWafer", [](GENPYBIND_PARENT_TYPE const& self) {
			auto const t = self.toHLineOnWafer();
			return std::tuple{t.template get<0>(), t.template get<1>()};
		});
	})

	boost::optional<HRepeaterOnWafer> east() const SYMBOL_VISIBLE;
	boost::optional<HRepeaterOnWafer> west() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*")) VRepeaterOnHICANN
    : public common::detail::GridCoordinate<
          VRepeaterOnHICANN,
          VLineOnHICANN,
          common::SideVertical,
          VLineOnHICANN::size>
    , public common::detail::HasTopBottom<VRepeaterOnHICANN>
{
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

struct GENPYBIND(inline_base("*HICANNMixin*")) VRepeaterOnWafer
    : public HICANNMixin<VRepeaterOnWafer, VRepeaterOnHICANN>
{
private:
	typedef HICANNMixin<VRepeaterOnWafer, VRepeaterOnHICANN> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	PYPP_DEFAULT(VRepeaterOnWafer());

	explicit VRepeaterOnWafer(
	    VRepeaterOnHICANN const& vrepeater, HICANNOnWafer const& h = HICANNOnWafer())
	    : base(vrepeater, h)
	{}

	explicit VRepeaterOnWafer(enum_type const& e) : base(e) {}

	VRepeaterOnHICANN toVRepeaterOnHICANN() const { return This(); }
	RepeaterBlockOnWafer toRepeaterBlockOnWafer() const {
		return RepeaterBlockOnWafer(toVRepeaterOnHICANN().toRepeaterBlockOnHICANN(),
		                            toHICANNOnWafer());
	}

	/* L1 repeaters are connected to two L1 lines. One on the local
	   HICANN, the other on a neighboring HICANN.

	   The VLine on the local HICANN is guaranteed to be in the first element of the tuple.
	 */
	// clang-format off
	boost::tuple<VLineOnWafer, boost::optional<VLineOnWafer> > GENPYBIND(hidden)
	    toVLineOnWafer() const SYMBOL_VISIBLE;
	// clang-format on
	GENPYBIND_MANUAL({
		parent.def("toVLineOnWafer", [](GENPYBIND_PARENT_TYPE const& self) {
			auto const t = self.toVLineOnWafer();
			return std::tuple{t.template get<0>(), t.template get<1>()};
		});
	})

	boost::optional<VRepeaterOnWafer> north() const SYMBOL_VISIBLE;
	boost::optional<VRepeaterOnWafer> south() const SYMBOL_VISIBLE;
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
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::RepeaterBlockOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SendingRepeaterOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SendingRepeaterOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::BackgroundGeneratorOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::DNCMergerOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::DNCMergerOnWafer)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::HICANNMixin<halco::hicann::v2::DNCMergerOnWafer BOOST_PP_COMMA()
    halco::hicann::v2::DNCMergerOnHICANN>)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::HICANNMixin<halco::hicann::v2::RepeaterBlockOnWafer BOOST_PP_COMMA()
    halco::hicann::v2::RepeaterBlockOnHICANN>)
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
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::HICANNMixin<halco::hicann::v2::SendingRepeaterOnWafer BOOST_PP_COMMA()
                                       halco::hicann::v2::SendingRepeaterOnHICANN>)

} // std
