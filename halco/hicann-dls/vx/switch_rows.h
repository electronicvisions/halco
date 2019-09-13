#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"

#include "halco/hicann-dls/vx/synapse.h"
#include "halco/hicann-dls/vx/synram.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/************************\
  ColumnCorrelationQuad
\************************/

struct GENPYBIND(inline_base("*")) ColumnCorrelationQuadOnSynram
    : public common::detail::RantWrapper<
          ColumnCorrelationQuadOnSynram,
          uint_fast16_t,
          SynapseQuadColumnOnDLS::max,
          SynapseQuadColumnOnDLS::min>
    , public common::detail::XRangedTrait
{
	constexpr explicit ColumnCorrelationQuadOnSynram(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	constexpr explicit ColumnCorrelationQuadOnSynram(common::X const& x)
	    GENPYBIND(implicit_conversion) :
	    rant_t(x)
	{}

	SynapseQuadColumnOnDLS toSynapseQuadColumnOnDLS() const
	{
		return SynapseQuadColumnOnDLS(toEnum());
	}
};


struct GENPYBIND(inline_base("*SynramMixin*")) ColumnCorrelationQuadOnDLS
    : public SynramMixin<ColumnCorrelationQuadOnDLS, ColumnCorrelationQuadOnSynram>
{
	ColumnCorrelationQuadOnDLS() = default;

	explicit ColumnCorrelationQuadOnDLS(
	    ColumnCorrelationQuadOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit ColumnCorrelationQuadOnDLS(enum_type const& e) : mixin_t(e) {}

	ColumnCorrelationQuadOnSynram toColumnCorrelationQuadOnSynram() const { return This(); }
};


struct GENPYBIND(inline_base("*")) ColumnCorrelationSwitchOnColumnCorrelationQuad
    : public common::detail::
          RantWrapper<ColumnCorrelationSwitchOnColumnCorrelationQuad, uint_fast16_t, 3, 0>
{
	constexpr explicit ColumnCorrelationSwitchOnColumnCorrelationQuad(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


/********************\
  ColumnCurrentQuad
\********************/

struct GENPYBIND(inline_base("*")) ColumnCurrentQuadOnSynram
    : public common::detail::RantWrapper<
          ColumnCurrentQuadOnSynram,
          uint_fast16_t,
          SynapseQuadColumnOnDLS::max,
          SynapseQuadColumnOnDLS::min>
    , public common::detail::XRangedTrait
{
	constexpr explicit ColumnCurrentQuadOnSynram(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	constexpr explicit ColumnCurrentQuadOnSynram(common::X const& x)
	    GENPYBIND(implicit_conversion) :
	    rant_t(x)
	{}

	SynapseQuadColumnOnDLS toSynapseQuadColumnOnDLS() const
	{
		return SynapseQuadColumnOnDLS(toEnum());
	}
};


struct GENPYBIND(inline_base("*SynramMixin*")) ColumnCurrentQuadOnDLS
    : public SynramMixin<ColumnCurrentQuadOnDLS, ColumnCurrentQuadOnSynram>
{
	ColumnCurrentQuadOnDLS() = default;

	explicit ColumnCurrentQuadOnDLS(
	    ColumnCurrentQuadOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit ColumnCurrentQuadOnDLS(enum_type const& e) : mixin_t(e) {}

	ColumnCurrentQuadOnSynram toColumnCurrentQuadOnSynram() const { return This(); }
};


struct GENPYBIND(inline_base("*")) ColumnCurrentSwitchOnColumnCurrentQuad
    : public common::detail::
          RantWrapper<ColumnCurrentSwitchOnColumnCurrentQuad, uint_fast16_t, 3, 0>
{
	constexpr explicit ColumnCurrentSwitchOnColumnCurrentQuad(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ColumnCorrelationQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ColumnCurrentQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ColumnCorrelationQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ColumnCurrentQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ColumnCorrelationSwitchOnColumnCorrelationQuad)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ColumnCurrentSwitchOnColumnCurrentQuad)

} // namespace std
