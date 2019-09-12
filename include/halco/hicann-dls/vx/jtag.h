#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/***********\
    JTAG
\***********/

struct GENPYBIND(inline_base("*")) ResetJTAGTapOnDLS
    : public common::detail::RantWrapper<ResetJTAGTapOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit ResetJTAGTapOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*")) JTAGClockScalerOnDLS
    : public common::detail::RantWrapper<JTAGClockScalerOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit JTAGClockScalerOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*")) JTAGIdCodeOnDLS
    : public common::detail::RantWrapper<JTAGIdCodeOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit JTAGIdCodeOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*")) JTAGPLLRegisterOnDLS
    : public common::detail::RantWrapper<JTAGPLLRegisterOnDLS, uint_fast16_t, 7, 0>
{
	constexpr explicit JTAGPLLRegisterOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) JTAGPhyRegisterOnDLS
    : public common::detail::RantWrapper<JTAGPhyRegisterOnDLS, uint_fast16_t, 7, 0>
{
	constexpr explicit JTAGPhyRegisterOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ResetJTAGTapOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::JTAGClockScalerOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::JTAGIdCodeOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::JTAGPLLRegisterOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::JTAGPhyRegisterOnDLS)

} // namespace std
