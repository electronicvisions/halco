#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/synapse.h"
#include "halco/hicann-dls/vx/v1/quad.h"
#include "halco/hicann-dls/vx/v1/synram.h"

namespace halco::hicann_dls::vx::v1 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V1 {

#include "halco/hicann-dls/vx/synapse_ns_includes.h"

HALCO_COORDINATE_MIXIN(SynapseQuadColumnMixin, SynapseQuadColumnOnDLS, synapse_quad_column)

struct GENPYBIND(inline_base("*SynapseQuadColumnMixin*")) SynapseOnSynapseRow
    : public SynapseQuadColumnMixin<SynapseOnSynapseRow, EntryOnQuad>
{
	SynapseOnSynapseRow() = default;

	explicit SynapseOnSynapseRow(
	    EntryOnQuad const& syn_on_quad, SynapseQuadColumnOnDLS const& quad) :
	    mixin_t(syn_on_quad, quad)
	{}

	explicit SynapseOnSynapseRow(uintmax_t const value) GENPYBIND(implicit_conversion) :
	    mixin_t(enum_type(value))
	{}

	EntryOnQuad toEntryOnQuad() const
	{
		return This();
	}
	NeuronColumnOnDLS toNeuronColumnOnDLS() const;
};


} // namespace halco::hicann_dls::vx::v1

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v1::SynapseQuadColumnOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v1::SynapseQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v1::SynapseOnSynapseRow)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v1::SynapseQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v1::SynapseWeightQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v1::SynapseLabelQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v1::SynapseCorrelationCalibQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v1::CorrelationResetOnDLS)

} // namespace std
