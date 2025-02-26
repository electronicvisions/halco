#pragma once
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "hate/visibility.h"

namespace halco::hicann_dls {
namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct JTAGPhyRegisterOnDLS;

/*************************\
   HicannARQStatus
\*************************/

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    HicannARQStatusOnFPGA
    : public common::detail::RantWrapper<HicannARQStatusOnFPGA, uint_fast16_t, 0, 0>
    , common::CoordinateBase<HicannARQStatusOnFPGA>
{
	constexpr explicit HicannARQStatusOnFPGA(uintmax_t const val = 0) : rant_t(val) {}
};


/************\
   PerfTest
\************/

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) PerfTestOnFPGA
    : public common::detail::RantWrapper<PerfTestOnFPGA, uint_fast16_t, 0, 0>
    , common::CoordinateBase<PerfTestOnFPGA>
{
	constexpr explicit PerfTestOnFPGA(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) PerfTestStatusOnFPGA
    : public common::detail::RantWrapper<PerfTestStatusOnFPGA, uint_fast16_t, 0, 0>
    , common::CoordinateBase<PerfTestStatusOnFPGA>
{
	constexpr explicit PerfTestStatusOnFPGA(uintmax_t const val = 0) : rant_t(val) {}
};


/**********\
    Phy
\**********/

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) PhyConfigFPGAOnDLS
    : public common::detail::RantWrapper<PhyConfigFPGAOnDLS, uint_fast16_t, 7, 0>
    , common::CoordinateBase<PhyConfigFPGAOnDLS>
{
	constexpr explicit PhyConfigFPGAOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) PhyConfigChipOnDLS
    : public common::detail::RantWrapper<PhyConfigChipOnDLS, uint_fast16_t, 7, 0>
    , common::CoordinateBase<PhyConfigChipOnDLS>
{
	constexpr explicit PhyConfigChipOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	JTAGPhyRegisterOnDLS toJTAGPhyRegisterOnDLS() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) PhyStatusOnFPGA
    : public common::detail::RantWrapper<PhyStatusOnFPGA, uint_fast16_t, 7, 0>
    , common::CoordinateBase<PhyStatusOnFPGA>
{
	constexpr explicit PhyStatusOnFPGA(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    CommonPhyConfigFPGAOnDLS
    : public common::detail::RantWrapper<CommonPhyConfigFPGAOnDLS, uint_fast16_t, 0, 0>
    , common::CoordinateBase<CommonPhyConfigFPGAOnDLS>
{
	constexpr explicit CommonPhyConfigFPGAOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    CommonPhyConfigChipOnDLS
    : public common::detail::RantWrapper<CommonPhyConfigChipOnDLS, uint_fast16_t, 0, 0>
    , common::CoordinateBase<CommonPhyConfigChipOnDLS>
{
	constexpr explicit CommonPhyConfigChipOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

} // namespace vx
} // namespace halco::hicann_dls

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
