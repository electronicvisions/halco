#include "halco/hicann-dls/vx/v1/synapse.h"

#include "halco/common/iter_all.h"
#include "halco/hicann-dls/vx/v1/cadc.h"
#include "halco/hicann-dls/vx/v1/chip.h"
#include "halco/hicann-dls/vx/v1/correlation.h"
#include "halco/hicann-dls/vx/v1/neuron.h"
#include "halco/hicann-dls/vx/v1/padi.h"
#include "halco/hicann-dls/vx/v1/ppu.h"
#include "halco/hicann-dls/vx/v1/switch_rows.h"
#include "halco/hicann-dls/vx/v1/synapse_driver.h"


namespace halco::hicann_dls::vx::v1 {

#include "halco/hicann-dls/vx/synapse_ns_includes_impl.h"

common::typed_array<NeuronColumnOnDLS, EntryOnQuad> SynapseQuadColumnOnDLS::toNeuronColumnOnDLS()
    const
{
	common::typed_array<NeuronColumnOnDLS, EntryOnQuad> ret;
	for (auto const e : common::iter_all<EntryOnQuad>()) {
		ret[e] = NeuronColumnOnDLS(toEnum() * EntryOnQuad::size + e.toEnum());
	}
	return ret;
}

NeuronConfigBlockOnDLS SynapseQuadOnDLS::toNeuronConfigBlockOnDLS() const
{
	bool east = toSynapseQuadColumnOnDLS() >= (SynapseQuadColumnOnDLS::size / 2);
	return NeuronConfigBlockOnDLS(toSynramOnDLS().toEnum() * 2 + east);
}

} // namespace halco::hicann_dls::vx::v1
