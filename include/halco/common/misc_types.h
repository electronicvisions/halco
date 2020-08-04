#pragma once
#include "pywrap/compat/array.hpp"
#include "pywrap/compat/macros.hpp"

// Ensure that "pywrap/compat/array.hpp" is included before this and hope...
#ifndef BOOST_ASIO_HAS_STD_ARRAY
#define BOOST_ASIO_HAS_STD_ARRAY
#endif
#include <boost/asio/ip/address.hpp>
#include <boost/functional/hash.hpp>
#include <boost/serialization/nvp.hpp>

#include "halco/common/genpybind.h"

namespace halco {
namespace common GENPYBIND_TAG_HALCO_COMMON {

typedef boost::asio::ip::address_v4 IPv4 GENPYBIND(expose_as("IPv4"), opaque(true));
typedef boost::asio::ip::address_v4::bytes_type IPv4_array_t;

// patch in support for __hash__ and __str__ as it is a required property for coordinates
GENPYBIND_MANUAL({
	auto my_ipv4 = parent.attr("IPv4");
	auto ism = parent->py::is_method(my_ipv4);
	my_ipv4.attr("__hash__") = parent->py::cpp_function(
	    [](::halco::common::IPv4 const& self) { return self.to_ulong(); }, ism);
	my_ipv4.attr("__str__") = parent->py::cpp_function(
	    [parent](::halco::common::IPv4 const& self) {
		    return parent->std::string("IPv4(") + self.to_string() + ")";
	    },
	    ism);
	my_ipv4.attr("__repr__") = my_ipv4.attr("__str__");
})

} // common
} // halco

namespace std {

template <>
struct hash<halco::common::IPv4>
{
	size_t operator()(halco::common::IPv4 const& t) const
	{
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
void serialize(Archiver& ar, halco::common::IPv4& ipv4, unsigned int const)
{
	// non-intrusive version where there is no access to private member.
	// Following
	// http://stackoverflow.com/questions/9454307/boost-serialization-of-classes-with-private-data
	unsigned long ip_as_ulong = ipv4.to_ulong();
	ar& make_nvp("ip_as_ulong", ip_as_ulong);
	ipv4 = halco::common::IPv4(ip_as_ulong);
}

} // namespace serialization
} // namespace boost
