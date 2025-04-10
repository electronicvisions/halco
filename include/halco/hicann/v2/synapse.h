#pragma once

extern "C" {
#include <stdint.h>
}

#include "pywrap/compat/macros.hpp"

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/relations.h"
#include "halco/common/tblr.h"
#include "halco/hicann/v2/fwd.h"
#include "halco/hicann/v2/hicann.h"
#include "halco/hicann/v2/neuron.h"

#include "hate/visibility.h"

namespace halco {
namespace hicann {
namespace v2 GENPYBIND_TAG_HALCO_HICANN_V2 {

struct GENPYBIND(inline_base("*")) SynapseArrayOnHICANN
    : public common::detail::RantWrapper<SynapseArrayOnHICANN, size_t, 1, 0>
    , public common::detail::YRangedTrait
    , public common::detail::HasTopBottom<SynapseArrayOnHICANN>
{
	PYPP_CONSTEXPR explicit SynapseArrayOnHICANN(common::SideVertical const& v = common::top)
	    GENPYBIND(implicit_conversion) :
	    rant_t(v.value())
	{}

	PYPP_CONSTEXPR explicit SynapseArrayOnHICANN(size_t const val) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*HICANNMixin*")) SynapseArrayOnWafer
    : public HICANNMixin<SynapseArrayOnWafer, SynapseArrayOnHICANN>
{
private:
	typedef HICANNMixin<SynapseArrayOnWafer, SynapseArrayOnHICANN> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	PYPP_DEFAULT(SynapseArrayOnWafer());

	explicit SynapseArrayOnWafer(
	    SynapseArrayOnHICANN const& array, HICANNOnWafer const& h = HICANNOnWafer()) :
	    base(array, h)
	{}

	explicit SynapseArrayOnWafer(enum_type const& e) : base(e) {}

	SynapseArrayOnHICANN toSynapseArrayOnHICANN() const
	{
		return This();
	}
};

/** SynapseSwitchRowOnHICANN coordinate.
 * Syndriver switch rows are accesses with a common::Side (left or right) and an index
 * within the side.
 * The index is counted from top to bottom.
 */
struct GENPYBIND(inline_base("*")) SynapseSwitchRowOnHICANN
    : public common::detail::
          GridCoordinate<SynapseSwitchRowOnHICANN, common::Side, common::YRanged<223, 0> >
    , public common::detail::HasTopBottom<SynapseSwitchRowOnHICANN>
    , public common::detail::HasLeftRight<SynapseSwitchRowOnHICANN>
{
	GRID_COMMON_CONSTRUCTORS(SynapseSwitchRowOnHICANN)

	// TODO: Replace with conversion member function for consistency?
	explicit SynapseSwitchRowOnHICANN(SynapseDriverOnHICANN const& drv) SYMBOL_VISIBLE;

	// TODO: Adapt to new "to..." naming scheme?
	y_type line() const { return mY; }

	QuadrantOnHICANN toQuadrantOnHICANN() const SYMBOL_VISIBLE;

	SynapseArrayOnHICANN toSynapseArrayOnHICANN() const SYMBOL_VISIBLE;

	SynapseDriverOnHICANN toSynapseDriverOnHICANN() const SYMBOL_VISIBLE;
};

/** SynapseDriverOnHICANN coordinate.
 * Synapse drivers are accesses with a common::Side (left or right) and line number,
 * which corresponds the row number of the adjacent synapse driver switch
 * matrix. The line number is counted from top to bottom.
 */
struct GENPYBIND(inline_base("*")) SynapseDriverOnHICANN
    : public common::detail::
          GridCoordinate<SynapseDriverOnHICANN, common::Side, common::YRanged<223, 0>, 112 * 2>
    , public common::detail::HasTopBottom<SynapseDriverOnHICANN>
    , public common::detail::HasLeftRight<SynapseDriverOnHICANN>
{
	GRID_COMMON_CONSTRUCTORS(SynapseDriverOnHICANN)

	// TODO: Replace with conversion member function for consistency?
	explicit SynapseDriverOnHICANN(SynapseSwitchRowOnHICANN const& row)
		: grid_type(row.x(), row.y()) {}

	// TODO: Adapt to new "to..." naming scheme?
	y_type line() const { return mY; }

	SynapseSwitchRowOnHICANN toSynapseSwitchRowOnHICANN() const {
		return SynapseSwitchRowOnHICANN(y(), x());
	}

	// returns the FGBlock which holds the shared params of this driver
	// TODO: check if this is correct
	FGBlockOnHICANN toFGBlockOnHICANN() const SYMBOL_VISIBLE;

	// Return the sending repeater on the same HICANN that can reach this synapse driver.
	SendingRepeaterOnHICANN toSendingRepeaterOnHICANN() const SYMBOL_VISIBLE;

	QuadrantOnHICANN toQuadrantOnHICANN() const SYMBOL_VISIBLE;
	SynapseDriverOnQuadrant toSynapseDriverOnQuadrant() const SYMBOL_VISIBLE;

	SynapseArrayOnHICANN toSynapseArrayOnHICANN() const SYMBOL_VISIBLE;

	/* implementation detail, not part of public API: */

	static PYPP_CONSTEXPR x_type to_x(enum_type const& e) {
		return x_type((e + (e < y_type::end / 2 /*is_top*/)) % 2);
	}

	static PYPP_CONSTEXPR y_type to_y(enum_type const& e) { return y_type(e); }

	static enum_type to_enum(x_type const& x, y_type const& y) SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*HICANNMixin*")) SynapseDriverOnWafer
    : public HICANNMixin<SynapseDriverOnWafer, SynapseDriverOnHICANN>
{
private:
	typedef HICANNMixin<SynapseDriverOnWafer, SynapseDriverOnHICANN> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	PYPP_DEFAULT(SynapseDriverOnWafer());

	explicit SynapseDriverOnWafer(SynapseDriverOnHICANN const& driver,
	                              HICANNOnWafer const& h = HICANNOnWafer())
	    : base(driver, h) {}

	explicit SynapseDriverOnWafer(enum_type const& e) : base(e) {}

	SynapseDriverOnHICANN toSynapseDriverOnHICANN() const { return This(); }
};

struct GENPYBIND(inline_base("*HICANNMixin*")) SynapseSwitchRowOnWafer
    : public HICANNMixin<SynapseSwitchRowOnWafer, SynapseSwitchRowOnHICANN>
{
private:
	typedef HICANNMixin<SynapseSwitchRowOnWafer, SynapseSwitchRowOnHICANN> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	PYPP_DEFAULT(SynapseSwitchRowOnWafer());

	explicit SynapseSwitchRowOnWafer(SynapseSwitchRowOnHICANN const& switch_row,
	                                 HICANNOnWafer const& h = HICANNOnWafer())
	    : base(switch_row, h) {}

	explicit SynapseSwitchRowOnWafer(enum_type const& e) : base(e) {}

	SynapseSwitchRowOnHICANN toSynapseSwitchRowOnHICANN() const { return This(); }

	// returns the connected synapse driver which is either on the local or the neighbor
	// HICANN
	SynapseDriverOnWafer toSynapseDriverOnWafer() const SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*")) SynapseDriverOnQuadrant
    : public common::detail::RantWrapper<
          SynapseDriverOnQuadrant,
          uint_fast16_t,
          SynapseDriverOnHICANN::y_type::end / 4 - 1,
          0>
{
	PYPP_CONSTEXPR explicit SynapseDriverOnQuadrant(uintmax_t const val)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	PYPP_DEFAULT(SynapseDriverOnQuadrant());

	SynapseDriverOnHICANN toSynapseDriverOnHICANN(QuadrantOnHICANN const&) const SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*")) RowOnSynapseDriver
    : public common::detail::RantWrapper<RowOnSynapseDriver, uint_fast16_t, 1, 0>
{
	PYPP_CONSTEXPR explicit RowOnSynapseDriver(uintmax_t const val) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	PYPP_CONSTEXPR RowOnSynapseDriver(common::SideVertical s) GENPYBIND(implicit_conversion) :
	    rant_t(s)
	{}

	PYPP_DEFAULT(RowOnSynapseDriver());
};

/** SynapseRow coordinate.
 * Each synapse driver drives two synapse rows.
 */
struct GENPYBIND(inline_base("*")) SynapseRowOnHICANN
    : public common::detail::RantWrapper<SynapseRowOnHICANN, uint_fast16_t, 2 * 224 - 1, 0>
    , public common::detail::YRangedTrait
{
	explicit SynapseRowOnHICANN(SynapseDriverOnHICANN const& drv, RowOnSynapseDriver const& row)
	    GENPYBIND(implicit_conversion) :
	    rant_t(drv.y() * 2 + row)
	{}

	explicit SynapseRowOnHICANN(SynapseRowOnArray const& row, SynapseArrayOnHICANN const& synarray)
	    SYMBOL_VISIBLE;

	PYPP_CONSTEXPR explicit SynapseRowOnHICANN(common::Y const& y) GENPYBIND(implicit_conversion) :
	    rant_t(y.value())
	{}
	PYPP_CONSTEXPR explicit SynapseRowOnHICANN(uintmax_t const val) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	PYPP_DEFAULT(SynapseRowOnHICANN());

	SynapseDriverOnHICANN toSynapseDriverOnHICANN() const {
		return SynapseDriverOnHICANN(common::Enum(value() / 2));
	}

	RowOnSynapseDriver toRowOnSynapseDriver() const {
		return RowOnSynapseDriver(value() % 2);
	}

	SynapseArrayOnHICANN toSynapseArrayOnHICANN() const {
		return toSynapseDriverOnHICANN().toSynapseArrayOnHICANN();
	}

	SynapseRowOnArray toSynapseRowOnArray() const SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*HICANNMixin*")) SynapseRowOnWafer
    : public HICANNMixin<SynapseRowOnWafer, SynapseRowOnHICANN>
{
private:
	typedef HICANNMixin<SynapseRowOnWafer, SynapseRowOnHICANN> base;

public:
	using base::enum_type;

	PYPP_DEFAULT(SynapseRowOnWafer());

	explicit SynapseRowOnWafer(
	    SynapseRowOnHICANN const& synapse, HICANNOnWafer const& h = HICANNOnWafer()) :
	    base(synapse, h)
	{}

	explicit SynapseRowOnWafer(enum_type const& e) : base(e) {}

	SynapseRowOnHICANN toSynapseRowOnHICANN() const
	{
		return This();
	}
	SynapseDriverOnWafer toSynapseDriverOnWafer() const
	{
		return SynapseDriverOnWafer(toSynapseDriverOnHICANN(), toHICANNOnWafer());
	}
};

/** SynapseRow coordinate on (either top or botom) synapse array.
 * Each synapse driver drives two synapse rows.
 */
struct GENPYBIND(inline_base("*")) SynapseRowOnArray
    : public common::detail::RantWrapper<SynapseRowOnArray, uint_fast16_t, 224 - 1, 0>
    , public common::detail::YRangedTrait
{
	explicit SynapseRowOnArray(SynapseDriverOnHICANN const& drv, RowOnSynapseDriver const& row)
	    SYMBOL_VISIBLE;

	PYPP_CONSTEXPR explicit SynapseRowOnArray(common::Y const& y) GENPYBIND(implicit_conversion) :
	    rant_t(y.value())
	{}
	PYPP_CONSTEXPR explicit SynapseRowOnArray(uintmax_t const val) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	PYPP_DEFAULT(SynapseRowOnArray());
};

struct GENPYBIND(inline_base("*")) SynapseColumnOnHICANN
    : public common::detail::RantWrapper<
          SynapseColumnOnHICANN,
          NeuronOnHICANN::x_type::value_type,
          NeuronOnHICANN::x_type::max,
          0>
    , public common::detail::XRangedTrait
{
	PYPP_CONSTEXPR explicit SynapseColumnOnHICANN(common::X const& x)
	    GENPYBIND(implicit_conversion) :
	    rant_t(x.value())
	{}
	PYPP_CONSTEXPR explicit SynapseColumnOnHICANN(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) SynapseOnHICANN
    : public common::detail::
          GridCoordinate<SynapseOnHICANN, SynapseColumnOnHICANN, SynapseRowOnHICANN>
{
	GRID_COMMON_CONSTRUCTORS(SynapseOnHICANN)

	SynapseRowOnHICANN toSynapseRowOnHICANN() const { return y(); }

	SynapseColumnOnHICANN toSynapseColumnOnHICANN() const { return x(); }

	SynapseDriverOnHICANN toSynapseDriverOnHICANN() const {
		return toSynapseRowOnHICANN().toSynapseDriverOnHICANN();
	}

	NeuronOnHICANN toNeuronOnHICANN() const {
		return NeuronOnHICANN(common::X(x()), common::Y(y() >= y_type::end / 2));
	}
};

struct GENPYBIND(inline_base("*HICANNMixin*")) SynapseOnWafer
    : public HICANNMixin<SynapseOnWafer, SynapseOnHICANN>
{
private:
	typedef HICANNMixin<SynapseOnWafer, SynapseOnHICANN> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	PYPP_DEFAULT(SynapseOnWafer());

	explicit SynapseOnWafer(SynapseOnHICANN const& synapse,
							HICANNOnWafer const& h = HICANNOnWafer())
		: base(synapse, h) {}

	explicit SynapseOnWafer(enum_type const& e) : base(e) {}

	SynapseOnHICANN toSynapseOnHICANN() const { return This(); }
	NeuronOnWafer toNeuronOnWafer() const {
		return NeuronOnWafer(toNeuronOnHICANN(), toHICANNOnWafer());
	}
	SynapseRowOnWafer toSynapseRowOnWafer() const
	{
		return SynapseRowOnWafer(toSynapseRowOnHICANN(), toHICANNOnWafer());
	}
};


} // v2
} // hicann
} // halco

// std::hash specializations
namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SynapseArrayOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SynapseArrayOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SynapseSwitchRowOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SynapseSwitchRowOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::RowOnSynapseDriver)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SynapseRowOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SynapseRowOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SynapseRowOnArray)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SynapseColumnOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SynapseOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SynapseOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SynapseDriverOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SynapseDriverOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SynapseDriverOnQuadrant)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::HICANNMixin<halco::hicann::v2::SynapseOnWafer BOOST_PP_COMMA()
    halco::hicann::v2::SynapseOnHICANN>)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::HICANNMixin<halco::hicann::v2::SynapseSwitchRowOnWafer BOOST_PP_COMMA()
    halco::hicann::v2::SynapseSwitchRowOnHICANN>)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::HICANNMixin<halco::hicann::v2::SynapseDriverOnWafer BOOST_PP_COMMA()
    halco::hicann::v2::SynapseDriverOnHICANN>)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::HICANNMixin<halco::hicann::v2::SynapseRowOnWafer BOOST_PP_COMMA()
                                       halco::hicann::v2::SynapseRowOnHICANN>)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::HICANNMixin<halco::hicann::v2::SynapseArrayOnWafer BOOST_PP_COMMA()
                                       halco::hicann::v2::SynapseArrayOnHICANN>)

} // std
