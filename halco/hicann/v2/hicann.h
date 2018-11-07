#pragma once

#include "pywrap/compat/macros.hpp"

#include "halco/common/geometry.h"
#include "halco/common/mixin.h"
#include "halco/common/relations.h"

#include "halco/hicann/v2/fwd.h"
#include "halco/hicann/v2/wafer.h"

namespace halco {
namespace hicann {
namespace v2 {

// HICANN coordinate
struct HICANNOnWafer
	: public common::detail::
		  GridCoordinate<HICANNOnWafer, common::XRanged<35, 0>, common::YRanged<15, 0>, 384> {
	GRID_COMMON_CONSTRUCTORS(HICANNOnWafer)

	HICANNOnWafer east() const { return HICANNOnWafer(x_type(x() + 1), y()); }
	HICANNOnWafer west() const { return HICANNOnWafer(x_type(x() - 1), y()); }
	HICANNOnWafer north() const { return HICANNOnWafer(x(), y_type(y() - 1)); }
	HICANNOnWafer south() const { return HICANNOnWafer(x(), y_type(y() + 1)); }
	HICANNOnWafer move(common::Direction const& direction) const;

	DNCOnWafer toDNCOnWafer() const;
	HICANNOnDNC toHICANNOnDNC() const;
	HICANNOnHS toHICANNOnHS() const;


/* implementation detail, not part of public API: */

	static x_type to_x(enum_type const& e);
	static y_type to_y(enum_type const& e);
	static enum_type to_enum(x_type const& x, y_type const& y);
};

// HICANN Coordinate relative to DNC
struct HICANNOnDNC
    : public common::detail::GridCoordinate<HICANNOnDNC, common::XRanged<3, 0>, common::YRanged<1, 0> > {
	GRID_COMMON_CONSTRUCTORS(HICANNOnDNC)

	HICANNOnWafer toHICANNOnWafer(const DNCOnWafer& dnc) const;
	HICANNOnHS toHICANNOnHS() const;
};

// HICANN Coordinate relative to highspeed
struct HICANNOnHS
    : public common::detail::RantWrapper<HICANNOnHS, size_t, 7, 0> {
	PYPP_CONSTEXPR explicit HICANNOnHS(uintmax_t const val = 0) : rant_t(val) {}

	HICANNOnDNC toHICANNOnDNC() const;
};

struct HICANNGlobal : public WaferMixin<HICANNGlobal, HICANNOnWafer> {
private:
	typedef WaferMixin<HICANNGlobal, HICANNOnWafer> base;

public:
	using base::enum_type;
	typedef HICANNOnWafer::x_type x_type;
	typedef HICANNOnWafer::y_type y_type;

	PYPP_DEFAULT(HICANNGlobal());

	explicit HICANNGlobal(HICANNOnWafer const& h, Wafer const& w = Wafer())
	    : base(h, w) {}

	explicit HICANNGlobal(enum_type const& e)
	    : base(e) {}

	explicit HICANNGlobal(x_type const& x, y_type const& y, Wafer const& w = Wafer())
	    : base(HICANNOnWafer(x, y), w) {}


	HICANNGlobal east() const;
	HICANNGlobal west() const;
	HICANNGlobal north() const;
	HICANNGlobal south() const;
	HICANNGlobal move(common::Direction const& direction) const;

	DNCGlobal toDNCGlobal() const;
	FPGAGlobal toFPGAGlobal() const;
	FPGAOnWafer toFPGAOnWafer() const;
	DNCOnFPGA toDNCOnFPGA() const;
	HICANNOnWafer toHICANNOnWafer() const { return This(); }
};

HALCO_COORDINATE_MIXIN(HICANNMixin, HICANNOnWafer, hicann)

} // v2
} // hicann
} // halco

// std::hash specializations
namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::HICANNGlobal)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::HICANNOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::HICANNOnDNC)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::HICANNOnHS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::WaferMixin<
    halco::hicann::v2::HICANNGlobal BOOST_PP_COMMA() halco::hicann::v2::HICANNOnWafer>)

} // std
