#pragma once

extern "C" {
#include <stdint.h>
}

#include "pywrap/compat/macros.hpp"

#include "halco/common/geometry.h"
#include "halco/common/tblr.h"
#include "halco/common/relations.h"
#include "halco/hicann/v2/fwd.h"
#include "halco/hicann/v2/hicann.h"
#include "halco/hicann/v2/neuron.h"

namespace halco {
namespace hicann {
namespace v2 {

struct SynapseArrayOnHICANN
    : public common::detail::RantWrapper<SynapseArrayOnHICANN, size_t, 1, 0>,
      public common::detail::YRangedTrait,
	  public common::detail::HasTopBottom<SynapseArrayOnHICANN> {

	PYPP_CONSTEXPR explicit SynapseArrayOnHICANN(
	    common::SideVertical const& v = common::top)
	    : rant_t(v.value()) {}

	PYPP_CONSTEXPR explicit SynapseArrayOnHICANN(size_t const val) : rant_t(val) {}
};

/** SynapseSwitchRowOnHICANN coordinate.
 * Syndriver switch rows are accesses with a common::Side (left or right) and an index
 * within the side.
 * The index is counted from top to bottom.
 */
struct SynapseSwitchRowOnHICANN
	: public common::detail::GridCoordinate<SynapseSwitchRowOnHICANN, common::Side, common::YRanged<223, 0> >,
	  public common::detail::HasTopBottom<SynapseSwitchRowOnHICANN>,
	  public common::detail::HasLeftRight<SynapseSwitchRowOnHICANN> {
	GRID_COMMON_CONSTRUCTORS(SynapseSwitchRowOnHICANN)

	// TODO: Replace with conversion member function for consistency?
	explicit SynapseSwitchRowOnHICANN(SynapseDriverOnHICANN const& drv);

	// TODO: Adapt to new "to..." naming scheme?
	y_type line() const { return mY; }

	QuadrantOnHICANN toQuadrantOnHICANN() const;

	SynapseArrayOnHICANN toSynapseArrayOnHICANN() const;

	SynapseDriverOnHICANN toSynapseDriverOnHICANN() const;
};

/** SynapseDriverOnHICANN coordinate.
 * Synapse drivers are accesses with a common::Side (left or right) and line number,
 * which corresponds the row number of the adjacent synapse driver switch
 * matrix. The line number is counted from top to bottom.
 */
struct SynapseDriverOnHICANN
	: public common::detail::GridCoordinate<SynapseDriverOnHICANN, common::Side, common::YRanged<223, 0>, 112 * 2>,
	  public common::detail::HasTopBottom<SynapseDriverOnHICANN>,
	  public common::detail::HasLeftRight<SynapseDriverOnHICANN> {
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
	FGBlockOnHICANN toFGBlockOnHICANN() const;

	// Return the sending repeater on the same HICANN that can reach this synapse driver.
	SendingRepeaterOnHICANN toSendingRepeaterOnHICANN() const;

	QuadrantOnHICANN toQuadrantOnHICANN() const;
	SynapseDriverOnQuadrant toSynapseDriverOnQuadrant() const;

	SynapseArrayOnHICANN toSynapseArrayOnHICANN() const;

/* implementation detail, not part of public API: */

	static PYPP_CONSTEXPR x_type to_x(enum_type const& e) {
		return x_type((e + (e < y_type::end / 2 /*is_top*/)) % 2);
	}

	static PYPP_CONSTEXPR y_type to_y(enum_type const& e) { return y_type(e); }

	static enum_type to_enum(x_type const& x, y_type const& y);
};

struct SynapseDriverOnWafer
    : public HICANNMixin<SynapseDriverOnWafer, SynapseDriverOnHICANN> {
private:
	typedef HICANNMixin<SynapseDriverOnWafer, SynapseDriverOnHICANN> base;

public:
	using base::enum_type;

	PYPP_DEFAULT(SynapseDriverOnWafer());

	explicit SynapseDriverOnWafer(SynapseDriverOnHICANN const& driver,
	                              HICANNOnWafer const& h = HICANNOnWafer())
	    : base(driver, h) {}

	explicit SynapseDriverOnWafer(enum_type const& e) : base(e) {}

	SynapseDriverOnHICANN toSynapseDriverOnHICANN() const { return This(); }
};

struct SynapseSwitchRowOnWafer
    : public HICANNMixin<SynapseSwitchRowOnWafer, SynapseSwitchRowOnHICANN> {
private:
	typedef HICANNMixin<SynapseSwitchRowOnWafer, SynapseSwitchRowOnHICANN> base;

public:
	using base::enum_type;

	PYPP_DEFAULT(SynapseSwitchRowOnWafer());

	explicit SynapseSwitchRowOnWafer(SynapseSwitchRowOnHICANN const& switch_row,
	                                 HICANNOnWafer const& h = HICANNOnWafer())
	    : base(switch_row, h) {}

	explicit SynapseSwitchRowOnWafer(enum_type const& e) : base(e) {}

	SynapseSwitchRowOnHICANN toSynapseSwitchRowOnHICANN() const { return This(); }

	// returns the connected synapse driver which is either on the local or the neighbor
	// HICANN
	SynapseDriverOnWafer toSynapseDriverOnWafer() const;
};

struct SynapseDriverOnQuadrant
    : public common::detail::RantWrapper<SynapseDriverOnQuadrant, uint_fast16_t,
                                         SynapseDriverOnHICANN::y_type::end / 4 - 1, 0> {
	PYPP_CONSTEXPR explicit SynapseDriverOnQuadrant(uintmax_t const val) : rant_t(val) {}

	PYPP_DEFAULT(SynapseDriverOnQuadrant());

	SynapseDriverOnHICANN toSynapseDriverOnHICANN(QuadrantOnHICANN const&) const;
};

struct RowOnSynapseDriver
    : public common::detail::RantWrapper<RowOnSynapseDriver, uint_fast16_t, 1, 0> {
	PYPP_CONSTEXPR explicit RowOnSynapseDriver(uintmax_t const val) : rant_t(val) {}

	PYPP_CONSTEXPR RowOnSynapseDriver(common::SideVertical s) : rant_t(s) {}

	PYPP_DEFAULT(RowOnSynapseDriver());
};

/** SynapseRow coordinate.
 * Each synapse driver drives two synapse rows.
 */
struct SynapseRowOnHICANN
    : public common::detail::RantWrapper<SynapseRowOnHICANN, uint_fast16_t, 2 * 224 - 1, 0>,
      public common::detail::YRangedTrait {
	explicit SynapseRowOnHICANN(SynapseDriverOnHICANN const& drv,
	                            RowOnSynapseDriver const& row)
	    : rant_t(drv.y() * 2 + row) {}

	explicit SynapseRowOnHICANN(SynapseRowOnArray const& row, SynapseArrayOnHICANN const& synarray);

	PYPP_CONSTEXPR explicit SynapseRowOnHICANN(common::Y const& y) : rant_t(y.value()) {}
	PYPP_CONSTEXPR explicit SynapseRowOnHICANN(uintmax_t const val) : rant_t(val) {}

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

	SynapseRowOnArray toSynapseRowOnArray() const;
};

/** SynapseRow coordinate on (either top or botom) synapse array.
 * Each synapse driver drives two synapse rows.
 */
struct SynapseRowOnArray
    : public common::detail::RantWrapper<SynapseRowOnArray, uint_fast8_t, 224 - 1, 0>,
	  public common::detail::YRangedTrait {
	explicit SynapseRowOnArray(SynapseDriverOnHICANN const& drv, RowOnSynapseDriver const& row);

	PYPP_CONSTEXPR explicit SynapseRowOnArray(common::Y const& y) : rant_t(y.value()) {}
	PYPP_CONSTEXPR explicit SynapseRowOnArray(uintmax_t const val) : rant_t(val) {}

	PYPP_DEFAULT(SynapseRowOnArray());
};

struct SynapseColumnOnHICANN
    : public common::detail::RantWrapper<SynapseColumnOnHICANN, NeuronOnHICANN::x_type::value_type,
                                         NeuronOnHICANN::x_type::max, 0>,
      public common::detail::XRangedTrait {
	PYPP_CONSTEXPR explicit SynapseColumnOnHICANN(common::X const& x) : rant_t(x.value()) {}
	PYPP_CONSTEXPR explicit SynapseColumnOnHICANN(uintmax_t const val = 0) : rant_t(val) {}
};

struct SynapseOnHICANN
    : public common::detail::GridCoordinate<SynapseOnHICANN, SynapseColumnOnHICANN,
                                            SynapseRowOnHICANN> {
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

struct SynapseOnWafer : public HICANNMixin<SynapseOnWafer, SynapseOnHICANN> {
private:
	typedef HICANNMixin<SynapseOnWafer, SynapseOnHICANN> base;

public:
	using base::enum_type;

	PYPP_DEFAULT(SynapseOnWafer());

	explicit SynapseOnWafer(SynapseOnHICANN const& synapse,
							HICANNOnWafer const& h = HICANNOnWafer())
		: base(synapse, h) {}

	explicit SynapseOnWafer(enum_type const& e) : base(e) {}

	SynapseOnHICANN toSynapseOnHICANN() const { return This(); }
	NeuronOnWafer toNeuronOnWafer() const {
		return NeuronOnWafer(toNeuronOnHICANN(), toHICANNOnWafer());
	}
};


} // v2
} // hicann
} // halco

// std::hash specializations
namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SynapseArrayOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SynapseSwitchRowOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SynapseSwitchRowOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::RowOnSynapseDriver)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SynapseRowOnHICANN)
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

} // std
