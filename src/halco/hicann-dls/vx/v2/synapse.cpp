#include "halco/hicann-dls/vx/v2/synapse.h"

#include "halco/common/iter_all.h"
#include "halco/hicann-dls/vx/v2/cadc.h"
#include "halco/hicann-dls/vx/v2/chip.h"
#include "halco/hicann-dls/vx/v2/correlation.h"
#include "halco/hicann-dls/vx/v2/neuron.h"
#include "halco/hicann-dls/vx/v2/padi.h"
#include "halco/hicann-dls/vx/v2/ppu.h"
#include "halco/hicann-dls/vx/v2/switch_rows.h"
#include "halco/hicann-dls/vx/v2/synapse_driver.h"


namespace halco::hicann_dls::vx::v2 {

#include "halco/hicann-dls/vx/synapse_ns_includes_impl.h"

common::typed_array<NeuronColumnOnDLS, EntryOnQuad> SynapseQuadColumnOnDLS::toNeuronColumnOnDLS()
    const
{
	common::typed_array<NeuronColumnOnDLS, EntryOnQuad> ret;
	for (auto const e : common::iter_all<EntryOnQuad>()) {
		ret[e] = NeuronColumnOnDLS(
		    ((toEnum() % (size / 2)) * EntryOnQuad::size + e.toEnum()) * 2 +
		    (toEnum() / (size / 2)));
	}
	return ret;
}

NeuronConfigBlockOnDLS SynapseQuadOnDLS::toNeuronConfigBlockOnDLS() const
{
	bool east = toSynapseQuadColumnOnDLS() % (SynapseQuadColumnOnDLS::size / 2) >=
	            (SynapseQuadColumnOnDLS::size / 4);
	return NeuronConfigBlockOnDLS(toSynramOnDLS().toEnum() * 2 + east);
}

SynapseOnSynapseRow::SynapseOnSynapseRow(
    EntryOnQuad const& syn_on_quad, SynapseQuadColumnOnDLS const& quad) :
    rant_t(
        (3 - syn_on_quad.toEnum()) * 2 +
        (quad.toEnum() % (SynapseQuadColumnOnDLS::size / 2)) * EntryOnQuad::size * 2 +
        quad.toEnum() / (SynapseQuadColumnOnDLS::size / 2))
{}

EntryOnQuad SynapseOnSynapseRow::toEntryOnQuad() const
{
	return EntryOnQuad(3 - ((toEnum() / 2) % EntryOnQuad::size));
}

SynapseQuadColumnOnDLS SynapseOnSynapseRow::toSynapseQuadColumnOnDLS() const
{
	return SynapseQuadColumnOnDLS(
	    ((toEnum() % 2) * SynapseQuadColumnOnDLS::size / 2) + (toEnum() / (2 * EntryOnQuad::size)));
}

} // namespace halco::hicann_dls::vx
