#pragma once
#include <stdint.h>

#include "halco/common/common.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"

#include "halco/hicann-dls/vx/neuron.h"
#include "halco/hicann-dls/vx/synram.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/***********\
   Synapse
\***********/

struct GENPYBIND(inline_base("*")) SynapseQuadColumnOnDLS
    : public common::detail::RantWrapper<
          SynapseQuadColumnOnDLS,
          uint_fast16_t,
          NeuronOnNeuronBlock::size * 2 / 4 - 1,
          0>
    , public common::detail::XRangedTrait
{
	constexpr explicit SynapseQuadColumnOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	constexpr explicit SynapseQuadColumnOnDLS(common::X const& x) GENPYBIND(implicit_conversion) :
	    rant_t(x)
	{}
};


struct GENPYBIND(inline_base("*")) SynapseRowOnSynram
    : public common::detail::RantWrapper<SynapseRowOnSynram, uint_fast16_t, 255, 0>
    , public common::detail::YRangedTrait
{
	constexpr explicit SynapseRowOnSynram(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	constexpr explicit SynapseRowOnSynram(common::Y const& y) GENPYBIND(implicit_conversion) :
	    rant_t(y)
	{}
};


struct GENPYBIND(inline_base("*")) SynapseQuadOnSynram
    : public common::detail::
          GridCoordinate<SynapseQuadOnSynram, SynapseQuadColumnOnDLS, SynapseRowOnSynram>
{
	GRID_COMMON_CONSTRUCTORS(SynapseQuadOnSynram)

	SynapseQuadColumnOnDLS toSynapseQuadColumnOnDLS() const { return x(); }
	SynapseRowOnSynram toSynapseRowOnSynram() const { return y(); }
};


struct GENPYBIND(inline_base("*SynramMixin*")) SynapseQuadOnDLS
    : public SynramMixin<SynapseQuadOnDLS, SynapseQuadOnSynram>
{
	SynapseQuadOnDLS() = default;

	explicit SynapseQuadOnDLS(
	    SynapseQuadOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit SynapseQuadOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseQuadOnSynram toSynapseQuadOnSynram() const { return This(); }
};


struct GENPYBIND(inline_base("*")) SynapseOnSynapseQuad
    : public common::detail::RantWrapper<SynapseOnSynapseQuad, uint_fast16_t, 3, 0>
{
	constexpr explicit SynapseOnSynapseQuad(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseQuadColumnOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseRowOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseOnSynapseQuad)

} // namespace std
