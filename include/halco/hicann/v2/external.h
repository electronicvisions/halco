#pragma once

extern "C" {
#include <stdint.h>
}

#include <boost/serialization/access.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/array.h>
#include <boost/serialization/version.hpp>

#include "halco/common/geometry.h"
#include "halco/common/misc_types.h"
#include "halco/common/relations.h"
#include "halco/hicann/v2/fwd.h"
#include "halco/hicann/v2/hicann.h"
#include "halco/hicann/v2/l1.h"
#include "halco/hicann/v2/wafer.h"
#include "hate/visibility.h"
#include "pywrap/compat/array.hpp"
#include "pywrap/compat/macros.hpp"

// Ensure that "pywrap/compat/array.hpp" is included before this and hope...
#ifndef BOOST_ASIO_HAS_STD_ARRAY
#define BOOST_ASIO_HAS_STD_ARRAY
#endif

// GCCXML has problems with atomics -> removed before boost asio is included
#ifdef PYPLUSPLUS
#undef __ATOMIC_RELAXED
#undef __ATOMIC_ACQUIRE
#undef __ATOMIC_RELEASE
#endif // PYPLUSPLUS

#include <boost/asio/ip/address.hpp>

namespace halco {
namespace hicann {
namespace v2 GENPYBIND_TAG_HALCO_HICANN_V2 {

// IP address
typedef boost::asio::ip::address_v4 IPv4 GENPYBIND(visible);
typedef boost::asio::ip::address_v4::bytes_type IPv4_array_t;

struct GENPYBIND(inline_base("*")) AnalogOnHICANN
    : public common::detail::RantWrapper<AnalogOnHICANN, uint_fast16_t, 1, 0>
{
	PYPP_CONSTEXPR explicit AnalogOnHICANN(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	AnalogOnDNC toAnalogOnDNC() const SYMBOL_VISIBLE;
};

/// corresponds to the analog outputs of each reticle, same as AnalogOnHICANN (but multiple HICANNs
/// share this)
struct GENPYBIND(inline_base("*")) AnalogOnDNC
    : public common::detail::RantWrapper<AnalogOnDNC, uint_fast16_t, 1, 0>
{
	explicit AnalogOnDNC(uintmax_t const val = 0) GENPYBIND(implicit_conversion) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*")) WIOOnWafer
    : public common::detail::RantWrapper<WIOOnWafer, uint_fast16_t, 3, 0>
{
	PYPP_CONSTEXPR explicit WIOOnWafer(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) SocketOnWIO
    : public common::detail::RantWrapper<SocketOnWIO, uint_fast16_t, 11, 0>
{
	PYPP_CONSTEXPR explicit SocketOnWIO(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) GbitLinkOnHICANN
    : public common::detail::RantWrapper<GbitLinkOnHICANN, uint_fast16_t, 7, 0>
{
	PYPP_CONSTEXPR explicit GbitLinkOnHICANN(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	DNCMergerOnHICANN toDNCMergerOnHICANN() const SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*HICANNMixin*")) GbitLinkOnWafer
    : public HICANNMixin<GbitLinkOnWafer, GbitLinkOnHICANN>
{
private:
	typedef HICANNMixin<GbitLinkOnWafer, GbitLinkOnHICANN> base;

public:
	using base::enum_type;

	PYPP_DEFAULT(GbitLinkOnWafer());

	explicit GbitLinkOnWafer(
	    GbitLinkOnHICANN const& hline, HICANNOnWafer const& h = HICANNOnWafer()) :
	    base(hline, h)
	{}

	explicit GbitLinkOnWafer(enum_type const& e) : base(e) {}

	GbitLinkOnHICANN toGbitLinkOnHICANN() const
	{
		return This();
	}
};


struct GENPYBIND(inline_base("*")) DNCOnWafer
    : public common::detail::
          GridCoordinate<DNCOnWafer, common::XRanged<8, 0>, common::YRanged<7, 0>, 48>
{
	GRID_COMMON_CONSTRUCTORS(DNCOnWafer)

	FPGAOnWafer toFPGAOnWafer() const SYMBOL_VISIBLE;
	PowerCoordinate toPowerCoordinate() const SYMBOL_VISIBLE;
	TriggerOnWafer toTriggerOnWafer() const SYMBOL_VISIBLE;
	ADCGroupOnWafer toADCGroupOnWafer() const SYMBOL_VISIBLE;
	std::array<AnanasChannelOnAnanasSlice, ::halco::hicann::v2::AnalogOnDNC::size>
	toAnanasChannelOnAnanasSlice() const SYMBOL_VISIBLE;
	AuxPwrOnWafer toAuxPwrOnWafer() const SYMBOL_VISIBLE;

	/* implementation detail, not part of public API: */
	static x_type to_x(enum_type const& e) SYMBOL_VISIBLE;
	static y_type to_y(enum_type const& e) SYMBOL_VISIBLE;
	static enum_type to_enum(x_type const& x, y_type const& y) SYMBOL_VISIBLE;
};

// DNC Coordinate relative to FPGA
struct GENPYBIND(inline_base("*")) DNCOnFPGA
    : public common::detail::RantWrapper<DNCOnFPGA, size_t, 0, 0>
{
	PYPP_CONSTEXPR explicit DNCOnFPGA(uintmax_t val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	// TODO: rename toDNCGlobal
	DNCGlobal toDNCOnWafer(FPGAGlobal const&) const SYMBOL_VISIBLE;
};

HALCO_COORDINATE_MIXIN(DNCMixin, DNCOnWafer, dnc)

struct GENPYBIND(inline_base("*")) PowerCoordinate
    : public common::detail::RantWrapper<PowerCoordinate, size_t, 48, 1>
{
	PYPP_CONSTEXPR explicit PowerCoordinate(uintmax_t val = 1) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*WaferMixin*")) DNCGlobal : public WaferMixin<DNCGlobal, DNCOnWafer>
{
private:
	typedef WaferMixin<DNCGlobal, DNCOnWafer> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));
	typedef DNCOnWafer::x_type x_type;
	typedef DNCOnWafer::y_type y_type;

	DNCGlobal() {}
	explicit DNCGlobal(DNCOnWafer const& h, Wafer const& w = Wafer()) : base(h, w) {}
	explicit DNCGlobal(enum_type const& e) : base(e) {}

	explicit DNCGlobal(const x_type x, const y_type y, const Wafer w = Wafer())
	    : base(DNCOnWafer(x, y), w) {}

	DNCOnWafer toDNCOnWafer() const { return This(); }
	DNCOnFPGA toDNCOnFPGA() const SYMBOL_VISIBLE;
	FPGAOnWafer toFPGAOnWafer() const SYMBOL_VISIBLE;
	FPGAGlobal toFPGAGlobal() const SYMBOL_VISIBLE;
};

// HighspeedLink coordinate between HICANN and DNC(FPGA)
struct GENPYBIND(inline_base("*")) HighspeedLinkOnDNC
    : public common::detail::RantWrapper<HighspeedLinkOnDNC, size_t, 7, 0>
{
	PYPP_CONSTEXPR explicit HighspeedLinkOnDNC(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	HICANNOnDNC toHICANNOnDNC() const SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*DNCMixin*")) HighspeedLinkOnWafer
    : public DNCMixin<HighspeedLinkOnWafer, HighspeedLinkOnDNC>
{
private:
	typedef DNCMixin<HighspeedLinkOnWafer, HighspeedLinkOnDNC> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	PYPP_DEFAULT(HighspeedLinkOnWafer());

	explicit HighspeedLinkOnWafer(
	    HighspeedLinkOnDNC const& hs_link, DNCOnWafer const& dnc = DNCOnWafer())
	    : base(hs_link, dnc)
	{}

	explicit HighspeedLinkOnWafer(enum_type const& e) : base(e) {}

	HighspeedLinkOnDNC toHighspeedLinkOnDNC() const { return This(); }
};

// IPv4 stack port number for UDP transport layer
struct GENPYBIND(inline_base("*")) UDPPort : public common::detail::BaseType<UDPPort, uint_fast16_t>
{
	PYPP_CONSTEXPR explicit UDPPort(value_type val) GENPYBIND(implicit_conversion) : base_t(val) {}
	PYPP_CONSTEXPR explicit UDPPort() GENPYBIND(implicit_conversion) : base_t() {}
};

// IPv4 stack port number for TCP transport layer
struct GENPYBIND(inline_base("*")) TCPPort : public common::detail::BaseType<TCPPort, uint_fast16_t>
{
	PYPP_CONSTEXPR explicit TCPPort(value_type val) GENPYBIND(implicit_conversion) : base_t(val) {}
	PYPP_CONSTEXPR explicit TCPPort() GENPYBIND(implicit_conversion) : base_t() {}
};

// Host Computer
struct GENPYBIND(inline_base("*")) Host : public common::detail::BaseType<Host, size_t>
{
	PYPP_CONSTEXPR explicit Host(value_type val) GENPYBIND(implicit_conversion) : base_t(val) {}
	PYPP_CONSTEXPR explicit Host() GENPYBIND(implicit_conversion) : base_t() {}
};

// JTAG TCK Frequency in Hz
struct GENPYBIND(inline_base("*")) JTAGFrequency
    : public common::detail::RantWrapper<JTAGFrequency, size_t, 50000000, 10000>
{
	PYPP_CONSTEXPR explicit JTAGFrequency(size_t val = 10000000) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

// Power Management Unit
struct GENPYBIND(inline_base("*")) PMU : public common::detail::BaseType<PMU, size_t>
{
	PYPP_CONSTEXPR explicit PMU(value_type val) GENPYBIND(implicit_conversion) : base_t(val) {}
	PYPP_CONSTEXPR explicit PMU() GENPYBIND(implicit_conversion) : base_t() {}
};

/// FPGA (FCP module) connected to a wafer module
///
/// \note: For (old) Virtex-5-based wafer modules the valid values are only in the range of
///        0..11; to avoid introducing a new type for the Kintex-7-based wafer modules we
///        check this constraint only in FPGAGlobal's construct GENPYBIND(inline_base("*"))or.
struct GENPYBIND(inline_base("*")) FPGAOnWafer
    : public common::detail::RantWrapper<FPGAOnWafer, size_t, 47, 0>
{
	PYPP_CONSTEXPR explicit FPGAOnWafer(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	explicit FPGAOnWafer(WIOOnWafer const& wio, SocketOnWIO const& s) SYMBOL_VISIBLE;

	// master FPGA for global sysstart
	static const SYMBOL_VISIBLE FPGAOnWafer Master;

	DNCOnWafer toDNCOnWafer() const SYMBOL_VISIBLE;
	TriggerOnWafer toTriggerOnWafer() const SYMBOL_VISIBLE;
	WIOOnWafer toWIOOnWafer() const SYMBOL_VISIBLE;
	SocketOnWIO toSocketOnWIO() const SYMBOL_VISIBLE;

	std::array<HICANNOnWafer, halco::hicann::v2::HICANNOnDNC::size> toHICANNOnWafer() const
	    SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*WaferMixin*")) FPGAGlobal
    : public WaferMixin<FPGAGlobal, FPGAOnWafer>
{
private:
	typedef WaferMixin<FPGAGlobal, FPGAOnWafer> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	FPGAGlobal() SYMBOL_VISIBLE;
	explicit FPGAGlobal(FPGAOnWafer const& h, Wafer const& w = Wafer()) SYMBOL_VISIBLE;
	explicit FPGAGlobal(enum_type const& e) SYMBOL_VISIBLE;

	std::vector<HICANNGlobal> toHICANNGlobal() const SYMBOL_VISIBLE;

	FPGAOnWafer toFPGAOnWafer() const { return This(); }
};

/// ANAlog Network-Attached Sampling unit (analog membrane recording and readout based on FlySpi
/// FPGA board)
struct GENPYBIND(inline_base("*")) AnanasOnWafer
    : public common::detail::RantWrapper<AnanasOnWafer, size_t, 1, 0>
{
	PYPP_CONSTEXPR explicit AnanasOnWafer(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

/// AnanasSlice corresponds to a HostARQ instance inside the FPGA (independently accessible by
/// multiple hosts)
struct GENPYBIND(inline_base("*")) AnanasSliceOnAnanas
    : public common::detail::RantWrapper<AnanasSliceOnAnanas, size_t, 5, 0>
{
	PYPP_CONSTEXPR explicit AnanasSliceOnAnanas(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

HALCO_COORDINATE_MIXIN(AnanasMixin, AnanasOnWafer, ananas)

struct GENPYBIND(inline_base("*AnanasMixin*")) AnanasSliceOnWafer
    : public AnanasMixin<AnanasSliceOnWafer, AnanasSliceOnAnanas>
{
private:
	typedef AnanasMixin<AnanasSliceOnWafer, AnanasSliceOnAnanas> base;

public:
	typedef base::enum_type enum_type;

	AnanasSliceOnWafer() SYMBOL_VISIBLE;

	explicit AnanasSliceOnWafer(
	    AnanasSliceOnAnanas const& slice,
	    AnanasOnWafer const& ananas = AnanasOnWafer()) SYMBOL_VISIBLE;

	explicit AnanasSliceOnWafer(uintmax_t const& e)
	    SYMBOL_VISIBLE; // TODO FIXME uint because of AnanasChannelGlobal

	AnanasSliceOnAnanas toAnanasSliceOnAnanas() const SYMBOL_VISIBLE;
};

/// AnanasChannel corresponds to an analog input to the board (physical copper trace)
struct GENPYBIND(inline_base("*")) AnanasChannelOnAnanasSlice
    : public common::detail::RantWrapper<AnanasChannelOnAnanasSlice, size_t, 7, 0>
{
	PYPP_CONSTEXPR explicit AnanasChannelOnAnanasSlice(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*WaferMixin*")) AnanasGlobal
    : public WaferMixin<AnanasGlobal, AnanasOnWafer>
{
private:
	typedef WaferMixin<AnanasGlobal, AnanasOnWafer> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	AnanasGlobal() SYMBOL_VISIBLE;
	explicit AnanasGlobal(AnanasOnWafer const& h, Wafer const& w = Wafer()) SYMBOL_VISIBLE;
	explicit AnanasGlobal(enum_type const& e) SYMBOL_VISIBLE;

	AnanasOnWafer toAnanasOnWafer() const SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*WaferMixin*")) AnanasSliceGlobal
    : public WaferMixin<AnanasSliceGlobal, AnanasSliceOnWafer>
{
private:
	typedef WaferMixin<AnanasSliceGlobal, AnanasSliceOnWafer> base;

public:
	using base::enum_type;

	AnanasSliceGlobal() SYMBOL_VISIBLE;
	explicit AnanasSliceGlobal(AnanasSliceOnWafer const& h, Wafer const& w = Wafer())
	    SYMBOL_VISIBLE;
	explicit AnanasSliceGlobal(enum_type const& e) SYMBOL_VISIBLE;

	AnanasSliceOnWafer toAnanasSliceOnWafer() const
	{
		return This();
	}
	// TODO FIXME AnanasGlobal toAnanasGlobal() const { return }
};

struct GENPYBIND(inline_base("*")) AuxPwrOnWafer
    : public common::detail::RantWrapper<AuxPwrOnWafer, size_t, 1, 0>
    , public common::detail::YRangedTrait
    , public common::detail::HasTopBottom<AuxPwrOnWafer>
{
	PYPP_CONSTEXPR explicit AuxPwrOnWafer(common::SideVertical const& v = common::top)
	    GENPYBIND(implicit_conversion) :
	    rant_t(v.value())
	{}

	PYPP_CONSTEXPR explicit AuxPwrOnWafer(size_t const val) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*WaferMixin*")) AuxPwrGlobal
    : public WaferMixin<AuxPwrGlobal, AuxPwrOnWafer>
{
private:
	typedef WaferMixin<AuxPwrGlobal, AuxPwrOnWafer> base;

public:
	using base::enum_type;

	AuxPwrGlobal() SYMBOL_VISIBLE;
	explicit AuxPwrGlobal(AuxPwrOnWafer const& h, Wafer const& w = Wafer()) SYMBOL_VISIBLE;
	explicit AuxPwrGlobal(enum_type const& e) SYMBOL_VISIBLE;

	AuxPwrOnWafer toAuxPwrOnWafer() const { return This(); }
};

struct GENPYBIND(inline_base("*")) ChannelOnADC
    : public common::detail::RantWrapper<ChannelOnADC, int_fast16_t, 7, -1>
{
	PYPP_CONSTEXPR explicit ChannelOnADC(intmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const SYMBOL_VISIBLE ChannelOnADC GND;
};

struct GENPYBIND(inline_base("*")) TriggerOnADC
    : public common::detail::RantWrapper<TriggerOnADC, uint_fast16_t, 1, 0>
{
	PYPP_CONSTEXPR explicit TriggerOnADC(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) TriggerOnWafer
    : public common::detail::RantWrapper<TriggerOnWafer, uint_fast16_t, 11, 0>
{
	PYPP_CONSTEXPR explicit TriggerOnWafer(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	AnanasOnWafer toAnanasOnWafer() const SYMBOL_VISIBLE;
	AnanasSliceOnAnanas toAnanasSliceOnAnanas() const SYMBOL_VISIBLE;
	AnanasSliceOnWafer toAnanasSliceOnWafer() const SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*")) ADCGroupOnWafer
    : public common::detail::RantWrapper<ADCGroupOnWafer, uint_fast16_t, 5, 0>
{
	PYPP_CONSTEXPR explicit ADCGroupOnWafer(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*WaferMixin*")) TriggerGlobal
    : public WaferMixin<TriggerGlobal, TriggerOnWafer>
{
private:
	typedef WaferMixin<TriggerGlobal, TriggerOnWafer> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	TriggerGlobal() SYMBOL_VISIBLE;
	explicit TriggerGlobal(TriggerOnWafer const& h, Wafer const& w = Wafer()) SYMBOL_VISIBLE;
	explicit TriggerGlobal(enum_type const& e) SYMBOL_VISIBLE;

	TriggerOnWafer toTriggerOnWafer() const { return This(); }
};

} // v2
} // hicann
} // halco

// std::hash specializations
namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::WIOOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SocketOnWIO)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::DNCOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::DNCOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::HighspeedLinkOnDNC)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::HighspeedLinkOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::FPGAOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::AnanasChannelOnAnanasSlice)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::AnanasMixin<halco::hicann::v2::AnanasSliceOnWafer BOOST_PP_COMMA()
                                       halco::hicann::v2::AnanasSliceOnAnanas>)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::AnanasOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::AnanasSliceGlobal)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::AnanasSliceOnAnanas)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::AnanasSliceOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::AuxPwrOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::TriggerOnADC)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::TriggerOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::ADCGroupOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::AnalogOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::AnalogOnDNC)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::ChannelOnADC)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::DNCGlobal)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::PowerCoordinate)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::FPGAGlobal)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::TriggerGlobal)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::AnanasGlobal)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::AuxPwrGlobal)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::GbitLinkOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::GbitLinkOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::WaferMixin<
    halco::hicann::v2::FPGAGlobal BOOST_PP_COMMA() halco::hicann::v2::FPGAOnWafer>)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::WaferMixin<halco::hicann::v2::TriggerGlobal BOOST_PP_COMMA()
    halco::hicann::v2::TriggerOnWafer>)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::WaferMixin<halco::hicann::v2::AnanasGlobal BOOST_PP_COMMA()
                                      halco::hicann::v2::AnanasOnWafer>)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::WaferMixin<halco::hicann::v2::AnanasSliceGlobal BOOST_PP_COMMA()
                                      halco::hicann::v2::AnanasSliceOnWafer>)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::WaferMixin<
    halco::hicann::v2::AuxPwrGlobal BOOST_PP_COMMA() halco::hicann::v2::AuxPwrOnWafer>)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::WaferMixin<
    halco::hicann::v2::DNCGlobal BOOST_PP_COMMA() halco::hicann::v2::DNCOnWafer>)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::DNCMixin<
    halco::hicann::v2::HighspeedLinkOnWafer BOOST_PP_COMMA() halco::hicann::v2::HighspeedLinkOnDNC>)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::HICANNMixin<halco::hicann::v2::GbitLinkOnWafer BOOST_PP_COMMA()
                                       halco::hicann::v2::GbitLinkOnHICANN>)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::UDPPort)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::TCPPort)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::PMU)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::Host)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::JTAGFrequency)

} // std
