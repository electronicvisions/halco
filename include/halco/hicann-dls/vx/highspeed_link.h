#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct JTAGPhyRegisterOnDLS;

/*************************\
   HicannARQStatus
\*************************/

struct GENPYBIND(inline_base("*")) HicannARQStatusOnFPGA
    : public common::detail::RantWrapper<HicannARQStatusOnFPGA, uint_fast16_t, 0, 0>
{
	constexpr explicit HicannARQStatusOnFPGA(uintmax_t const val = 0) : rant_t(val) {}
};


/************\
   PerfTest
\************/

struct GENPYBIND(inline_base("*")) PerfTestOnFPGA
    : public common::detail::RantWrapper<PerfTestOnFPGA, uint_fast16_t, 0, 0>
{
	constexpr explicit PerfTestOnFPGA(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*")) PerfTestStatusOnFPGA
    : public common::detail::RantWrapper<PerfTestStatusOnFPGA, uint_fast16_t, 0, 0>
{
	constexpr explicit PerfTestStatusOnFPGA(uintmax_t const val = 0) : rant_t(val) {}
};


/**********\
    Phy
\**********/

struct GENPYBIND(inline_base("*")) PhyConfigFPGAOnDLS
    : public common::detail::RantWrapper<PhyConfigFPGAOnDLS, uint_fast16_t, 7, 0>
{
	constexpr explicit PhyConfigFPGAOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) PhyConfigChipOnDLS
    : public common::detail::RantWrapper<PhyConfigChipOnDLS, uint_fast16_t, 7, 0>
{
	constexpr explicit PhyConfigChipOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	JTAGPhyRegisterOnDLS toJTAGPhyRegisterOnDLS() const;
};


struct GENPYBIND(inline_base("*")) PhyStatusOnFPGA
    : public common::detail::RantWrapper<PhyStatusOnFPGA, uint_fast16_t, 7, 0>
{
	constexpr explicit PhyStatusOnFPGA(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) CommonPhyConfigFPGAOnDLS
    : public common::detail::RantWrapper<CommonPhyConfigFPGAOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit CommonPhyConfigFPGAOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*")) CommonPhyConfigChipOnDLS
    : public common::detail::RantWrapper<CommonPhyConfigChipOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit CommonPhyConfigChipOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::HicannARQStatusOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PerfTestOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PerfTestStatusOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PhyConfigFPGAOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PhyConfigChipOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PhyStatusOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonPhyConfigFPGAOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonPhyConfigChipOnDLS)

} // namespace std
