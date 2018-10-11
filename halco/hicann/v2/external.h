#pragma once

extern "C" {
#include <stdint.h>
}

#include <boost/serialization/access.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/array.h>
#include <boost/serialization/version.hpp>

#include "pywrap/compat/array.hpp"
#include "pywrap/compat/macros.hpp"
#include "halco/common/geometry.h"
#include "halco/common/relations.h"
#include "halco/hicann/v2/fwd.h"
#include "halco/hicann/v2/l1.h"
#include "halco/hicann/v2/wafer.h"

// Ensure that "pywrap/compat/array.hpp" is included before this and hope...
#define BOOST_ASIO_HAS_STD_ARRAY
#include <boost/asio/ip/address.hpp>

namespace halco {
namespace hicann {
namespace v2 {

// IP address
typedef boost::asio::ip::address_v4 IPv4;
typedef boost::asio::ip::address_v4::bytes_type IPv4_array_t;

struct GbitLinkOnHICANN
	: public common::detail::RantWrapper<GbitLinkOnHICANN, uint_fast16_t, 7, 0> {
	PYPP_CONSTEXPR explicit GbitLinkOnHICANN(uintmax_t const val = 0) : rant_t(val) {}

	DNCMergerOnHICANN toDNCMergerOnHICANN() const;
};

struct DNCOnWafer
	: public common::detail::
		  GridCoordinate<DNCOnWafer, common::XRanged<8, 0>, common::YRanged<7, 0>, 48> {
	GRID_COMMON_CONSTRUCTORS(DNCOnWafer)

	FPGAOnWafer toFPGAOnWafer() const;
	PowerCoordinate toPowerCoordinate() const;
	TriggerOnWafer toTriggerOnWafer() const;

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

	// master FPGA for global sysstart
	static const FPGAOnWafer Master;

	DNCOnWafer toDNCOnWafer() const;
	TriggerOnWafer toTriggerOnWafer() const;
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

struct ANANASOnWafer : public common::detail::RantWrapper<ANANASOnWafer, size_t, 1, 0> {
	PYPP_CONSTEXPR explicit ANANASOnWafer(uintmax_t const val = 0) : rant_t(val) {}
};

struct ANANASGlobal : public WaferMixin<ANANASGlobal, ANANASOnWafer> {
private:
	typedef WaferMixin<ANANASGlobal, ANANASOnWafer> base;

public:
	using base::enum_type;

	ANANASGlobal();
	explicit ANANASGlobal(ANANASOnWafer const& h, Wafer const& w = Wafer());
	explicit ANANASGlobal(enum_type const& e);

	ANANASOnWafer toANANASOnWafer() const { return This(); }
};

struct AnalogOnHICANN : public common::detail::RantWrapper<AnalogOnHICANN, uint_fast16_t, 1, 0> {
	PYPP_CONSTEXPR explicit AnalogOnHICANN(uintmax_t const val = 0) : rant_t(val) {}
};

struct ChannelOnADC : public common::detail::RantWrapper<ChannelOnADC, int_fast16_t, 7, -1> {
	PYPP_CONSTEXPR explicit ChannelOnADC(intmax_t const val = 0) : rant_t(val) {}

	static const ChannelOnADC GND;
};

struct TriggerOnADC : public common::detail::RantWrapper<TriggerOnADC, uint_fast16_t, 1, 0> {
	PYPP_CONSTEXPR explicit TriggerOnADC(uintmax_t const val = 0) : rant_t(val) {}
};

struct TriggerOnWafer : public common::detail::RantWrapper<TriggerOnWafer, uint_fast16_t, 12, 0>
{
	PYPP_CONSTEXPR explicit TriggerOnWafer(uintmax_t const val = 0) : rant_t(val) {}

	ANANASOnWafer toANANASOnWafer() const;
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

HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::DNCOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::DNCOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::FPGAOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::ANANASOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::TriggerOnADC)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::TriggerOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::AnalogOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::ChannelOnADC)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::DNCGlobal)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::PowerCoordinate)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::FPGAGlobal)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::TriggerGlobal)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::ANANASGlobal)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::GbitLinkOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::WaferMixin<
    halco::hicann::v2::FPGAGlobal BOOST_PP_COMMA() halco::hicann::v2::FPGAOnWafer>)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::WaferMixin<halco::hicann::v2::TriggerGlobal BOOST_PP_COMMA()
    halco::hicann::v2::TriggerOnWafer>)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::WaferMixin<
    halco::hicann::v2::ANANASGlobal BOOST_PP_COMMA() halco::hicann::v2::ANANASOnWafer>)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::WaferMixin<
    halco::hicann::v2::DNCGlobal BOOST_PP_COMMA() halco::hicann::v2::DNCOnWafer>)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::UDPPort)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::TCPPort)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::PMU)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::Host)

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
