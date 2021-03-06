#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"

#include "halco/hicann-dls/vx/neuron.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct CapMemBlockOnHemisphere;

/**********\
   CapMem
\**********/

constexpr size_t num_block_global_capmem_column = 2;

// Max value is num_block_global_capmem_column larger than neuron max due to global capmem columns
struct GENPYBIND(inline_base("*")) CapMemColumnOnCapMemBlock
    : public common::detail::RantWrapper<
          CapMemColumnOnCapMemBlock,
          NeuronConfigOnNeuronConfigBlock::value_type,
          NeuronConfigOnNeuronConfigBlock::max + num_block_global_capmem_column,
          NeuronConfigOnNeuronConfigBlock::min>
    , public common::detail::XRangedTrait
{
	constexpr explicit CapMemColumnOnCapMemBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
	constexpr explicit CapMemColumnOnCapMemBlock(common::X const& x)
	    GENPYBIND(implicit_conversion) :
	    rant_t(x)
	{}

	bool isShared() const { return value() > (max - num_block_global_capmem_column); }
};

struct GENPYBIND(inline_base("*")) CapMemBlockOnHemisphere
    : public common::detail::RantWrapper<CapMemBlockOnHemisphere, uint_fast16_t, 1, 0>
{
	constexpr explicit CapMemBlockOnHemisphere(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const CapMemBlockOnHemisphere left;
	static const CapMemBlockOnHemisphere right;
};


struct GENPYBIND(inline_base("*")) CapMemBlockOnDLS
    : public common::detail::RantWrapper<CapMemBlockOnDLS, uint_fast16_t, 3, 0>
{
	constexpr explicit CapMemBlockOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CapMemBlockOnHemisphere toCapMemBlockOnHemisphere() const;
};


struct GENPYBIND(inline_base("*")) CapMemBlockConfigOnDLS
    : public common::detail::
          RantWrapper<CapMemBlockConfigOnDLS, uint_fast16_t, CapMemBlockOnDLS::max, 0>
{
	constexpr explicit CapMemBlockConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CapMemBlockOnHemisphere toCapMemBlockOnHemisphere() const;
};


struct GENPYBIND(inline_base("*")) ReferenceGeneratorConfigOnDLS
    : public common::detail::RantWrapper<ReferenceGeneratorConfigOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit ReferenceGeneratorConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemColumnOnCapMemBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemBlockOnHemisphere)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemBlockConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ReferenceGeneratorConfigOnDLS)

} // namespace std
