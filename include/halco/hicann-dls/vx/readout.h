#pragma once
#include <stdint.h>

#include "halco/common/common.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct GENPYBIND(inline_base("*")) ReadoutMuxConfigOnDLS
    : public common::detail::RantWrapper<ReadoutMuxConfigOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit ReadoutMuxConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) ReadoutBufferConfigBlockOnDLS
    : public common::detail::RantWrapper<ReadoutBufferConfigBlockOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit ReadoutBufferConfigBlockOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*")) ReadoutBufferConfigOnReadoutBufferConfigBlock
    : public common::detail::
          RantWrapper<ReadoutBufferConfigOnReadoutBufferConfigBlock, uint_fast16_t, 1, 0>
{
	constexpr explicit ReadoutBufferConfigOnReadoutBufferConfigBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

} // namespace halco::hicann::dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ReadoutMuxConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ReadoutBufferConfigBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ReadoutBufferConfigOnReadoutBufferConfigBlock)

} // namespace std
