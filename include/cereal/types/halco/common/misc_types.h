#pragma once
#include "halco/common/misc_types.h"
#include <cereal/cereal.hpp>

namespace cereal {

template <typename Archive>
void CEREAL_SERIALIZE_FUNCTION_NAME(Archive& ar, halco::common::IPv4& ipv4)
{
	// non-intrusive version where there is no access to private member.
	// Following
	// http://stackoverflow.com/questions/9454307/boost-serialization-of-classes-with-private-data
	unsigned long ip_as_ulong = ipv4.to_ulong();
	ar(CEREAL_NVP(ip_as_ulong));
	ipv4 = halco::common::IPv4(ip_as_ulong);
}

} // namespace cereal
