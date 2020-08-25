#include "halco/hicann-dls/vx/neuron.h"

#include "halco/common/iter_all.h"
#include "halco/hicann-dls/vx/capmem.h"
#include "halco/hicann-dls/vx/hemisphere.h"
#include "halco/hicann-dls/vx/routing_crossbar.h"
#include "halco/hicann-dls/vx/synapse.h"

namespace halco::hicann_dls::vx {

#define HEMISPHERE_CLASS NeuronRowOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

NeuronRowOnDLS const NeuronRowOnDLS::top{enum_vertical_top};
NeuronRowOnDLS const NeuronRowOnDLS::bottom{enum_vertical_bottom};

CapMemColumnOnCapMemBlock NeuronConfigOnNeuronConfigBlock::toCapMemColumnOnCapMemBlock() const
{
	return CapMemColumnOnCapMemBlock(toEnum());
}

CapMemBlockOnDLS NeuronConfigBlockOnDLS::toCapMemBlockOnDLS() const
{
	return CapMemBlockOnDLS(toEnum());
}

NeuronResetBlockOnDLS NeuronConfigBlockOnDLS::toNeuronResetBlockOnDLS() const
{
	return NeuronResetBlockOnDLS(toEnum() % NeuronResetBlockOnDLS::size);
}

NeuronBackendConfigBlockOnDLS BlockPostPulseOnDLS::toNeuronBackendConfigBlockOnDLS() const
{
	return NeuronBackendConfigBlockOnDLS(toEnum());
}

NeuronBackendConfigBlockOnDLS CommonNeuronBackendConfigOnDLS::toNeuronBackendConfigBlockOnDLS()
    const
{
	return NeuronBackendConfigBlockOnDLS(toEnum());
}

CommonNeuronBackendConfigOnDLS NeuronBackendConfigBlockOnDLS::toCommonNeuronBackendConfigOnDLS()
    const
{
	return CommonNeuronBackendConfigOnDLS(toEnum());
}

BlockPostPulseOnDLS NeuronBackendConfigBlockOnDLS::toBlockPostPulseOnDLS() const
{
	return BlockPostPulseOnDLS(toEnum());
}

SpikeCounterReadBlockOnDLS NeuronConfigBlockOnDLS::toSpikeCounterReadBlockOnDLS() const
{
	return SpikeCounterReadBlockOnDLS(toEnum() % SpikeCounterReadBlockOnDLS::size);
}

SpikeCounterResetBlockOnDLS NeuronConfigBlockOnDLS::toSpikeCounterResetBlockOnDLS() const
{
	return SpikeCounterResetBlockOnDLS(toEnum() % SpikeCounterResetBlockOnDLS::size);
}

NeuronEventOutputOnNeuronBackendBlock
NeuronBackendConfigOnNeuronBackendConfigBlock::toNeuronEventOutputOnNeuronBackendBlock() const
{
	return NeuronEventOutputOnNeuronBackendBlock(
	    (toEnum() % NeuronConfigOnNeuronConfigBlock::size) /
	    (NeuronConfigOnNeuronConfigBlock::size / NeuronEventOutputOnNeuronBackendBlock::size));
}

CrossbarInputOnDLS NeuronEventOutputOnDLS::toCrossbarInputOnDLS() const
{
	return CrossbarInputOnDLS(toEnum());
}

} // namespace halco::hicann_dls::vx
