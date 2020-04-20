#include "halco/hicann-dls/vx/cadc.h"

#include "halco/hicann-dls/vx/chip.h"
#include "halco/hicann-dls/vx/correlation.h"
#include "halco/hicann-dls/vx/neuron.h"
#include "halco/hicann-dls/vx/padi.h"
#include "halco/hicann-dls/vx/ppu.h"
#include "halco/hicann-dls/vx/synapse.h"
#include "halco/hicann-dls/vx/synapse_driver.h"
#include "halco/hicann-dls/vx/synram.h"

namespace halco::hicann_dls::vx {

#define HEMISPHERE_CLASS CADCConfigOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

CADCConfigOnDLS const CADCConfigOnDLS::top{enum_vertical_top};
CADCConfigOnDLS const CADCConfigOnDLS::bottom{enum_vertical_bottom};

CADCChannelType const CADCChannelType::causal{0};
CADCChannelType const CADCChannelType::acausal{1};

CADCReadoutType const CADCReadoutType::trigger_read{0};
CADCReadoutType const CADCReadoutType::buffered{1};

SynapseQuadOnDLS CADCSampleQuadOnDLS::toSynapseQuadOnDLS() const
{
	return SynapseQuadOnDLS(
	    toCADCSampleQuadOnSynram()
	        .toCADCSampleQuadUnspecifiedReadoutOnSynram()
	        .toSynapseQuadOnSynram(),
	    toSynramOnDLS());
}

SynapseWeightQuadOnDLS CADCSampleQuadOnDLS::toSynapseWeightQuadOnDLS() const
{
	return toSynapseQuadOnDLS().toSynapseWeightQuadOnDLS();
}

SynapseLabelQuadOnDLS CADCSampleQuadOnDLS::toSynapseLabelQuadOnDLS() const
{
	return toSynapseQuadOnDLS().toSynapseLabelQuadOnDLS();
}

SynapseCorrelationCalibQuadOnDLS CADCSampleQuadOnDLS::toSynapseCorrelationCalibQuadOnDLS() const
{
	return toSynapseQuadOnDLS().toSynapseCorrelationCalibQuadOnDLS();
}

SynapseRowOnDLS CADCSampleRowOnDLS::toSynapseRowOnDLS() const
{
	return SynapseRowOnDLS(toEnum());
}

SynapseWeightRowOnDLS CADCSampleRowOnDLS::toSynapseWeightRowOnDLS() const
{
	return SynapseWeightRowOnDLS(toEnum());
}

SynapseLabelRowOnDLS CADCSampleRowOnDLS::toSynapseLabelRowOnDLS() const
{
	return SynapseLabelRowOnDLS(toEnum());
}

SynapseCorrelationCalibRowOnDLS CADCSampleRowOnDLS::toSynapseCorrelationCalibRowOnDLS() const
{
	return SynapseCorrelationCalibRowOnDLS(toEnum());
}

NeuronConfigBlockOnDLS CADCChannelConfigOnDLS::toNeuronConfigBlockOnDLS() const
{
	return NeuronConfigBlockOnDLS(
	    (2 * toSynramOnDLS().toEnum()) +
	    (toSynapseOnSynapseRow() / NeuronConfigOnNeuronConfigBlock::size));
}
} // namespace halco::hicann_dls::vx
