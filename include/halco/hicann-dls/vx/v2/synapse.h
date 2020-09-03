#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/synapse.h"
#include "halco/hicann-dls/vx/v2/quad.h"
#include "halco/hicann-dls/vx/v2/synram.h"

namespace halco::hicann_dls::vx::v2 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V2 {

#include "halco/hicann-dls/vx/synapse_ns_includes.h"

struct GENPYBIND(inline_base("*")) SynapseOnSynapseRow
    : public common::detail::RantWrapper<SynapseOnSynapseRow, uint_fast16_t, 255, 0>
{
	constexpr explicit SynapseOnSynapseRow(uintmax_t const value = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(value)
	{}

	explicit SynapseOnSynapseRow(
	    EntryOnQuad const& syn_on_quad, SynapseQuadColumnOnDLS const& quad);

	EntryOnQuad toEntryOnQuad() const;
	SynapseQuadColumnOnDLS toSynapseQuadColumnOnDLS() const;
	NeuronColumnOnDLS toNeuronColumnOnDLS() const;
};

} // namespace halco::hicann_dls::vx::v2

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v2::SynapseQuadColumnOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v2::SynapseQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v2::SynapseOnSynapseRow)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v2::SynapseQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v2::SynapseWeightQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v2::SynapseLabelQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v2::SynapseCorrelationCalibQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v2::CorrelationResetOnDLS)

} // namespace std
