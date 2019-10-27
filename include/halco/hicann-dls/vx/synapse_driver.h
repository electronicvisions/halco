#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/*****************\
   SynapseDriver
\*****************/

struct PADIBusOnPADIBusBlock;

struct GENPYBIND(inline_base("*")) SynapseDriverOnSynapseDriverBlock
    : public common::detail::RantWrapper<SynapseDriverOnSynapseDriverBlock, uint_fast16_t, 127, 0>
{
	constexpr explicit SynapseDriverOnSynapseDriverBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	PADIBusOnPADIBusBlock toPADIBusOnPADIBusBlock() const;
};


struct CommonSynapseDriverConfigOnDLS;
struct SynramOnDLS;
struct PADIEventOnDLS;

struct GENPYBIND(inline_base("*")) SynapseDriverBlockOnDLS
    : public common::detail::RantWrapper<SynapseDriverBlockOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit SynapseDriverBlockOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CommonSynapseDriverConfigOnDLS toCommonSynapseDriverConfigOnDLS() const;
	SynramOnDLS toSynramOnDLS() const;
	PADIEventOnDLS toPADIEventOnDLS() const;

	static const SynapseDriverBlockOnDLS top;
	static const SynapseDriverBlockOnDLS bottom;
};


HALCO_COORDINATE_MIXIN(SynapseDriverMixin, SynapseDriverBlockOnDLS, synapse_driver)

struct GENPYBIND(inline_base("*SynapseDriverMixin*")) SynapseDriverOnDLS
    : public SynapseDriverMixin<SynapseDriverOnDLS, SynapseDriverOnSynapseDriverBlock>
{
	SynapseDriverOnDLS() = default;

	explicit SynapseDriverOnDLS(
	    SynapseDriverOnSynapseDriverBlock const& synapse_driver,
	    SynapseDriverBlockOnDLS const& block = SynapseDriverBlockOnDLS()) :
	    mixin_t(synapse_driver, block)
	{}

	explicit SynapseDriverOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseDriverOnSynapseDriverBlock toSynapseDriverOnSynapseDriverBlock() const { return This(); }
};


struct GENPYBIND(inline_base("*")) CommonSynapseDriverConfigOnDLS
    : public common::detail::RantWrapper<CommonSynapseDriverConfigOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit CommonSynapseDriverConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}

	SynapseDriverBlockOnDLS toSynapseDriverBlockOnDLS() const
	{
		return SynapseDriverBlockOnDLS(toEnum());
	}

	static const CommonSynapseDriverConfigOnDLS top;
	static const CommonSynapseDriverConfigOnDLS bottom;
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseDriverOnSynapseDriverBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseDriverBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseDriverOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonSynapseDriverConfigOnDLS)

} // namespace std
