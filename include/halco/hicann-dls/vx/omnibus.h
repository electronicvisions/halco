#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/**************\
    Omnibus
\**************/

struct GENPYBIND(inline_base("*")) OmnibusChipOverJTAGAddress
    : public common::detail::BaseType<OmnibusChipOverJTAGAddress, uint32_t>
{
	constexpr explicit OmnibusChipOverJTAGAddress(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    base_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) OmnibusAddress
    : public common::detail::BaseType<OmnibusAddress, uint32_t>
{
	constexpr explicit OmnibusAddress(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    base_t(val)
	{}
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::OmnibusChipOverJTAGAddress)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::OmnibusAddress)

} // namespace std
