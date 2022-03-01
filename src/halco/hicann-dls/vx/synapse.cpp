#include "halco/hicann-dls/vx/synapse.h"

#include "halco/common/iter_all.h"
#include "halco/hicann-dls/vx/hemisphere.h"
#include "halco/hicann-dls/vx/neuron.h"
#include "halco/hicann-dls/vx/padi.h"
#include "halco/hicann-dls/vx/ppu.h"
#include "halco/hicann-dls/vx/synapse_driver.h"


namespace halco::hicann_dls::vx {

SynapseRowOnSynapseDriver const SynapseRowOnSynapseDriver::top{0};
SynapseRowOnSynapseDriver const SynapseRowOnSynapseDriver::bottom{1};

SynapseDriverOnSynapseDriverBlock SynapseRowOnSynram::toSynapseDriverOnSynapseDriverBlock() const
{
	return SynapseDriverOnSynapseDriverBlock(toEnum() / 2);
}

SynapseRowOnSynapseDriver SynapseRowOnSynram::toSynapseRowOnSynapseDriver() const
{
	return SynapseRowOnSynapseDriver(
	    (toEnum() % 2 == 1) ? SynapseRowOnSynapseDriver::top : SynapseRowOnSynapseDriver::bottom);
}

SynapticInputOnNeuron const SynapticInputOnNeuron::excitatory{0};
SynapticInputOnNeuron const SynapticInputOnNeuron::inhibitory{1};

SynapseLabelRowOnDLS SynapseRowOnDLS::toSynapseLabelRowOnDLS() const
{
	return SynapseLabelRowOnDLS(toEnum());
}

SynapseWeightRowOnDLS SynapseRowOnDLS::toSynapseWeightRowOnDLS() const
{
	return SynapseWeightRowOnDLS(toEnum());
}

SynapseCorrelationCalibRowOnDLS SynapseRowOnDLS::toSynapseCorrelationCalibRowOnDLS() const
{
	return SynapseCorrelationCalibRowOnDLS(toEnum());
}

SynapseLabelRowOnDLS SynapseWeightRowOnDLS::toSynapseLabelRowOnDLS() const
{
	return SynapseLabelRowOnDLS(toEnum());
}

SynapseRowOnDLS SynapseWeightRowOnDLS::toSynapseRowOnDLS() const
{
	return SynapseRowOnDLS(toEnum());
}

SynapseCorrelationCalibRowOnDLS SynapseWeightRowOnDLS::toSynapseCorrelationCalibRowOnDLS() const
{
	return SynapseCorrelationCalibRowOnDLS(toEnum());
}

SynapseRowOnDLS SynapseLabelRowOnDLS::toSynapseRowOnDLS() const
{
	return SynapseRowOnDLS(toEnum());
}

SynapseWeightRowOnDLS SynapseLabelRowOnDLS::toSynapseWeightRowOnDLS() const
{
	return SynapseWeightRowOnDLS(toEnum());
}

SynapseCorrelationCalibRowOnDLS SynapseLabelRowOnDLS::toSynapseCorrelationCalibRowOnDLS() const
{
	return SynapseCorrelationCalibRowOnDLS(toEnum());
}

SynapseLabelRowOnDLS SynapseCorrelationCalibRowOnDLS::toSynapseLabelRowOnDLS() const
{
	return SynapseLabelRowOnDLS(toEnum());
}

SynapseWeightRowOnDLS SynapseCorrelationCalibRowOnDLS::toSynapseWeightRowOnDLS() const
{
	return SynapseWeightRowOnDLS(toEnum());
}

SynapseRowOnDLS SynapseCorrelationCalibRowOnDLS::toSynapseRowOnDLS() const
{
	return SynapseRowOnDLS(toEnum());
}

#define HEMISPHERE_CLASS ColumnCorrelationRowOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

#define HEMISPHERE_CLASS ColumnCurrentRowOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

#define HEMISPHERE_CLASS SynapseWeightMatrixOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

#define HEMISPHERE_CLASS SynapseLabelMatrixOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

#define HEMISPHERE_CLASS SynapseCorrelationCalibMatrixOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

#define HEMISPHERE_CLASS SynapseBlockOnDLS
#include "halco/hicann-dls/vx/convert_hemisphere.h"

ColumnCorrelationRowOnDLS const ColumnCorrelationRowOnDLS::top{enum_vertical_top};
ColumnCorrelationRowOnDLS const ColumnCorrelationRowOnDLS::bottom{enum_vertical_bottom};

ColumnCurrentRowOnDLS const ColumnCurrentRowOnDLS::top{enum_vertical_top};
ColumnCurrentRowOnDLS const ColumnCurrentRowOnDLS::bottom{enum_vertical_bottom};

SynapseWeightMatrixOnDLS const SynapseWeightMatrixOnDLS::top{enum_vertical_top};
SynapseWeightMatrixOnDLS const SynapseWeightMatrixOnDLS::bottom{enum_vertical_bottom};

SynapseLabelMatrixOnDLS const SynapseLabelMatrixOnDLS::top{enum_vertical_top};
SynapseLabelMatrixOnDLS const SynapseLabelMatrixOnDLS::bottom{enum_vertical_bottom};

SynapseCorrelationCalibMatrixOnDLS const SynapseCorrelationCalibMatrixOnDLS::top{enum_vertical_top};
SynapseCorrelationCalibMatrixOnDLS const SynapseCorrelationCalibMatrixOnDLS::bottom{
    enum_vertical_bottom};

SynapseBlockOnDLS const SynapseBlockOnDLS::top{enum_vertical_top};
SynapseBlockOnDLS const SynapseBlockOnDLS::bottom{enum_vertical_bottom};

} // namespace halco::hicann_dls::vx
