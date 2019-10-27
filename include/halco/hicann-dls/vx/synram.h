#pragma once
#include <stdint.h>

#include "halco/common/common.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.th"
#include "halco/common/mixin.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/************\
    Synram
\************/

struct CommonSynramConfigOnDLS;
struct PPUOnDLS;
struct SynapseDriverBlockOnDLS;
struct PADIEventOnDLS;

struct GENPYBIND(inline_base("*")) SynramOnDLS
    : public common::detail::RantWrapper<SynramOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit SynramOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CommonSynramConfigOnDLS toCommonSynramConfigOnDLS() const;
	PPUOnDLS toPPUOnDLS() const;
	SynapseDriverBlockOnDLS toSynapseDriverBlockOnDLS() const;
	PADIEventOnDLS toPADIEventOnDLS() const;

	static const SynramOnDLS top;
	static const SynramOnDLS bottom;
};

HALCO_COORDINATE_MIXIN(SynramMixin, SynramOnDLS, synram)


struct GENPYBIND(inline_base("*")) CommonSynramConfigOnDLS
    : public common::detail::RantWrapper<CommonSynramConfigOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit CommonSynramConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	PPUOnDLS toPPUOnDLS() const;
	SynramOnDLS toSynramOnDLS() const;

	static const CommonSynramConfigOnDLS top;
	static const CommonSynramConfigOnDLS bottom;
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynramOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonSynramConfigOnDLS)

} // namespace std
