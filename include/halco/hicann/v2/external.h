#pragma once

extern "C" {
#include <stdint.h>
}

#include <boost/serialization/access.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/array.h>
#include <boost/serialization/version.hpp>

#include "halco/common/geometry.h"
#include "halco/common/relations.h"
#include "halco/hicann/v2/fwd.h"
#include "halco/hicann/v2/hicann.h"
#include "halco/hicann/v2/l1.h"
#include "halco/hicann/v2/wafer.h"
#include "pywrap/compat/array.hpp"
#include "pywrap/compat/macros.hpp"

// Ensure that "pywrap/compat/array.hpp" is included before this and hope...
#define BOOST_ASIO_HAS_STD_ARRAY
#include <boost/asio/ip/address.hpp>

namespace halco {
namespace hicann {
namespace v2 {

// IP address
typedef boost::asio::ip::address_v4 IPv4;
typedef boost::asio::ip::address_v4::bytes_type IPv4_array_t;

struct AnalogOnHICANN : public common::detail::RantWrapper<AnalogOnHICANN, uint_fast16_t, 1, 0>
{
	PYPP_CONSTEXPR explicit AnalogOnHICANN(uintmax_t const val = 0) : rant_t(val) {}

	AnalogOnDNC toAnalogOnDNC() const;
};

/// corresponds to the analog outputs of each reticle, same as AnalogOnHICANN (but multiple HICANNs
/// share this)
struct AnalogOnDNC : public common::detail::RantWrapper<AnalogOnDNC, uint_fast16_t, 1, 0>
{
	explicit AnalogOnDNC(uintmax_t const val = 0) : rant_t(val) {}
};


struct WIOOnWafer : public common::detail::RantWrapper<WIOOnWafer, uint_fast16_t, 3, 0>
{
	PYPP_CONSTEXPR explicit WIOOnWafer(uintmax_t const val = 0) : rant_t(val) {}
};

struct SocketOnWIO : public common::detail::RantWrapper<SocketOnWIO, uint_fast16_t, 11, 0>
{
	PYPP_CONSTEXPR explicit SocketOnWIO(uintmax_t const val = 0) : rant_t(val) {}
};

struct GbitLinkOnHICANN
	: public common::detail::RantWrapper<GbitLinkOnHICANN, uint_fast16_t, 7, 0> {
	PYPP_CONSTEXPR explicit GbitLinkOnHICANN(uintmax_t const val = 0) : rant_t(val) {}

	DNCMergerOnHICANN toDNCMergerOnHICANN() const;
};

struct GbitLinkOnWafer : public HICANNMixin<GbitLinkOnWafer, GbitLinkOnHICANN>
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


struct DNCOnWafer
	: public common::detail::
		  GridCoordinate<DNCOnWafer, common::XRanged<8, 0>, common::YRanged<7, 0>, 48> {
	GRID_COMMON_CONSTRUCTORS(DNCOnWafer)

	FPGAOnWafer toFPGAOnWafer() const;
	PowerCoordinate toPowerCoordinate() const;
	TriggerOnWafer toTriggerOnWafer() const;
	std::array<AnanasChannelOnAnanasSlice, AnalogOnDNC::size> toAnanasChannelOnAnanasSlice() const;
	AuxPwrOnWafer toAuxPwrOnWafer() const;

	/* implementation detail, not part of public API: */
	static x_type to_x(enum_type const& e);
	static y_type to_y(enum_type const& e);
	static enum_type to_enum(x_type const& x, y_type const& y);
};

// DNC Coordinate relative to FPGA
struct DNCOnFPGA : public common::detail::RantWrapper<DNCOnFPGA, size_t, 0, 0> {
	PYPP_CONSTEXPR explicit DNCOnFPGA(uintmax_t val = 0) : rant_t(val) {}

	// TODO: rename toDNCGlobal
	DNCGlobal toDNCOnWafer(FPGAGlobal const&) const;
};

HALCO_COORDINATE_MIXIN(DNCMixin, DNCOnWafer, dnc)

struct PowerCoordinate : public common::detail::RantWrapper<PowerCoordinate, size_t, 48, 1> {
	PYPP_CONSTEXPR explicit PowerCoordinate(uintmax_t val = 1) : rant_t(val) {}
};

struct DNCGlobal : public WaferMixin<DNCGlobal, DNCOnWafer> {
private:
	typedef WaferMixin<DNCGlobal, DNCOnWafer> base;

public:
	using base::enum_type;
	typedef DNCOnWafer::x_type x_type;
	typedef DNCOnWafer::y_type y_type;

	DNCGlobal() {}
	explicit DNCGlobal(DNCOnWafer const& h, Wafer const& w = Wafer()) : base(h, w) {}
	explicit DNCGlobal(enum_type const& e) : base(e) {}

	explicit DNCGlobal(const x_type x, const y_type y, const Wafer w = Wafer())
	    : base(DNCOnWafer(x, y), w) {}

	DNCOnWafer toDNCOnWafer() const { return This(); }
	DNCOnFPGA toDNCOnFPGA() const;
	FPGAOnWafer toFPGAOnWafer() const;
	FPGAGlobal toFPGAGlobal() const;
};

// HighspeedLink coordinate between HICANN and DNC(FPGA)
struct HighspeedLinkOnDNC
    : public common::detail::RantWrapper<HighspeedLinkOnDNC, size_t, 7, 0> {
	PYPP_CONSTEXPR explicit HighspeedLinkOnDNC(uintmax_t const val = 0) : rant_t(val) {}

	HICANNOnDNC toHICANNOnDNC() const;
};

struct HighspeedLinkOnWafer : public DNCMixin<HighspeedLinkOnWafer, HighspeedLinkOnDNC>
{
private:
	typedef DNCMixin<HighspeedLinkOnWafer, HighspeedLinkOnDNC> base;

public:
	using base::enum_type;

	PYPP_DEFAULT(HighspeedLinkOnWafer());

	explicit HighspeedLinkOnWafer(
	    HighspeedLinkOnDNC const& hs_link, DNCOnWafer const& dnc = DNCOnWafer())
	    : base(hs_link, dnc)
	{}

	explicit HighspeedLinkOnWafer(enum_type const& e) : base(e) {}

	HighspeedLinkOnDNC toHighspeedLinkOnDNC() const { return This(); }
};

// IPv4 stack port number for UDP transport layer
struct UDPPort : public common::detail::BaseType<UDPPort, uint_fast16_t> {
	PYPP_CONSTEXPR explicit UDPPort(value_type val) : base_t(val) {}
	PYPP_CONSTEXPR explicit UDPPort() : base_t() {}
};

// IPv4 stack port number for TCP transport layer
struct TCPPort : public common::detail::BaseType<TCPPort, uint_fast16_t> {
	PYPP_CONSTEXPR explicit TCPPort(value_type val) : base_t(val) {}
	PYPP_CONSTEXPR explicit TCPPort() : base_t() {}
};

// Host Computer
struct Host : public common::detail::BaseType<Host, size_t> {
	PYPP_CONSTEXPR explicit Host(value_type val) : base_t(val) {}
	PYPP_CONSTEXPR explicit Host() : base_t() {}
};

// JTAG TCK Frequency in Hz
struct JTAGFrequency : public common::detail::RantWrapper<JTAGFrequency, size_t, 50000000, 10000> {
	PYPP_CONSTEXPR explicit JTAGFrequency(size_t val = 10000000) : rant_t(val) {}
};

// Power Management Unit
struct PMU : public common::detail::BaseType<PMU, size_t> {
	PYPP_CONSTEXPR explicit PMU(value_type val) : base_t(val) {}
	PYPP_CONSTEXPR explicit PMU() : base_t() {}
};

/// FPGA (FCP module) connected to a wafer module
///
/// \note: For (old) Virtex-5-based wafer modules the valid values are only in the range of
///        0..11; to avoid introducing a new type for the Kintex-7-based wafer modules we
///        check this constraint only in FPGAGlobal's constructor.
struct FPGAOnWafer : public common::detail::RantWrapper<FPGAOnWafer, size_t, 47, 0> {
	PYPP_CONSTEXPR explicit FPGAOnWafer(uintmax_t const val = 0) : rant_t(val) {}

	explicit FPGAOnWafer(WIOOnWafer const& wio, SocketOnWIO const& s);

	// master FPGA for global sysstart
	static const FPGAOnWafer Master;

	DNCOnWafer toDNCOnWafer() const;
	TriggerOnWafer toTriggerOnWafer() const;
	WIOOnWafer toWIOOnWafer() const;
	SocketOnWIO toSocketOnWIO() const;

	std::array<HICANNOnWafer, HICANNOnDNC::size> toHICANNOnWafer() const;
};

struct FPGAGlobal : public WaferMixin<FPGAGlobal, FPGAOnWafer> {
private:
	typedef WaferMixin<FPGAGlobal, FPGAOnWafer> base;

public:
	using base::enum_type;

	FPGAGlobal();
	explicit FPGAGlobal(FPGAOnWafer const& h, Wafer const& w = Wafer());
	explicit FPGAGlobal(enum_type const& e);

	std::vector<HICANNGlobal> toHICANNGlobal() const;

	FPGAOnWafer toFPGAOnWafer() const { return This(); }
};

/// ANAlog Network-Attached Sampling unit (analog membrane recording and readout based on FlySpi
/// FPGA board)
struct AnanasOnWafer : public common::detail::RantWrapper<AnanasOnWafer, size_t, 1, 0>
{
	PYPP_CONSTEXPR explicit AnanasOnWafer(uintmax_t const val = 0) : rant_t(val) {}
};

/// AnanasSlice corresponds to a HostARQ instance inside the FPGA (independently accessible by
/// multiple hosts)
struct AnanasSliceOnAnanas : public common::detail::RantWrapper<AnanasSliceOnAnanas, size_t, 5, 0>
{
	PYPP_CONSTEXPR explicit AnanasSliceOnAnanas(uintmax_t const val = 0) : rant_t(val) {}
};

HALCO_COORDINATE_MIXIN(AnanasMixin, AnanasOnWafer, ananas)

struct AnanasSliceOnWafer : public AnanasMixin<AnanasSliceOnWafer, AnanasSliceOnAnanas>
{
private:
	typedef AnanasMixin<AnanasSliceOnWafer, AnanasSliceOnAnanas> base;

public:
	typedef base::enum_type enum_type;

	AnanasSliceOnWafer();

	explicit AnanasSliceOnWafer(
	    AnanasSliceOnAnanas const& slice, AnanasOnWafer const& ananas = AnanasOnWafer());

	explicit AnanasSliceOnWafer(
	    uintmax_t const& e); // TODO FIXME uint because of AnanasChannelGlobal

	AnanasSliceOnAnanas toAnanasSliceOnAnanas() const;
};

/// AnanasChannel corresponds to an analog input to the board (physical copper trace)
struct AnanasChannelOnAnanasSlice
    : public common::detail::RantWrapper<AnanasChannelOnAnanasSlice, size_t, 7, 0>
{
	PYPP_CONSTEXPR explicit AnanasChannelOnAnanasSlice(uintmax_t const val = 0) : rant_t(val) {}
};

struct AnanasGlobal : public WaferMixin<AnanasGlobal, AnanasOnWafer>
{
private:
	typedef WaferMixin<AnanasGlobal, AnanasOnWafer> base;

public:
	using base::enum_type;

	AnanasGlobal();
	explicit AnanasGlobal(AnanasOnWafer const& h, Wafer const& w = Wafer());
	explicit AnanasGlobal(enum_type const& e);

	AnanasOnWafer toAnanasOnWafer() const;
};

struct AnanasSliceGlobal : public WaferMixin<AnanasSliceGlobal, AnanasSliceOnWafer>
{
private:
	typedef WaferMixin<AnanasSliceGlobal, AnanasSliceOnWafer> base;

public:
	using base::enum_type;

	AnanasSliceGlobal();
	explicit AnanasSliceGlobal(AnanasSliceOnWafer const& h, Wafer const& w = Wafer());
	explicit AnanasSliceGlobal(enum_type const& e);

	AnanasSliceOnWafer toAnanasSliceOnWafer() const
	{
		return This();
	}
	// TODO FIXME AnanasGlobal toAnanasGlobal() const { return }
};

struct AuxPwrOnWafer
    : public common::detail::RantWrapper<AuxPwrOnWafer, size_t, 1, 0>,
      public common::detail::YRangedTrait,
      public common::detail::HasTopBottom<AuxPwrOnWafer> {

	PYPP_CONSTEXPR explicit AuxPwrOnWafer(
	    common::SideVertical const& v = common::top)
	    : rant_t(v.value()) {}

	PYPP_CONSTEXPR explicit AuxPwrOnWafer(size_t const val) : rant_t(val) {}
};

struct AuxPwrGlobal : public WaferMixin<AuxPwrGlobal, AuxPwrOnWafer> {
private:
	typedef WaferMixin<AuxPwrGlobal, AuxPwrOnWafer> base;

public:
	using base::enum_type;

	AuxPwrGlobal();
	explicit AuxPwrGlobal(AuxPwrOnWafer const& h, Wafer const& w = Wafer());
	explicit AuxPwrGlobal(enum_type const& e);

	AuxPwrOnWafer toAuxPwrOnWafer() const { return This(); }
};

struct ChannelOnADC : public common::detail::RantWrapper<ChannelOnADC, int_fast16_t, 7, -1> {
	PYPP_CONSTEXPR explicit ChannelOnADC(intmax_t const val = 0) : rant_t(val) {}

	static const ChannelOnADC GND;
};

struct TriggerOnADC : public common::detail::RantWrapper<TriggerOnADC, uint_fast16_t, 1, 0> {
	PYPP_CONSTEXPR explicit TriggerOnADC(uintmax_t const val = 0) : rant_t(val) {}
};

struct TriggerOnWafer : public common::detail::RantWrapper<TriggerOnWafer, uint_fast16_t, 11, 0>
{
	PYPP_CONSTEXPR explicit TriggerOnWafer(uintmax_t const val = 0) : rant_t(val) {}

	AnanasOnWafer toAnanasOnWafer() const;
	AnanasSliceOnAnanas toAnanasSliceOnAnanas() const;
	AnanasSliceOnWafer toAnanasSliceOnWafer() const;
};

struct TriggerGlobal : public WaferMixin<TriggerGlobal, TriggerOnWafer>
{
private:
	typedef WaferMixin<TriggerGlobal, TriggerOnWafer> base;

public:
	using base::enum_type;

	TriggerGlobal();
	explicit TriggerGlobal(TriggerOnWafer const& h, Wafer const& w = Wafer());
	explicit TriggerGlobal(enum_type const& e);

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

template <>
struct hash<halco::hicann::v2::IPv4> {
	size_t operator()(halco::hicann::v2::IPv4 const& t) const {
		static std::string const name = typeid(t).name();
		size_t hash = boost::hash_value(t.to_string());
		boost::hash_combine(hash, name);
		return hash;
	}
};

} // std

namespace boost {
namespace serialization {

template <typename Archiver>
void serialize(Archiver& ar, halco::hicann::v2::IPv4& ipv4, unsigned int const) {
	// non-intrusive version where there is no access to private member.
	// Following http://stackoverflow.com/questions/9454307/boost-serialization-of-classes-with-private-data
	unsigned long ip_as_ulong = ipv4.to_ulong();
	ar & make_nvp("ip_as_ulong", ip_as_ulong);
	ipv4 = halco::hicann::v2::IPv4(ip_as_ulong);
}

} // namespace serialization
} // namespace boost
