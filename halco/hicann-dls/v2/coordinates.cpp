#include "halco/hicann-dls/v2/coordinates.h"

namespace halco {
namespace hicann_dls {
namespace v2 {

using namespace halco::common;

ColumnCorrelationSwitchOnDLS NeuronOnDLS::toColumnCorrelationSwitchOnDLS() const
{
	return ColumnCorrelationSwitchOnDLS(value());
}

ColumnCurrentSwitchOnDLS NeuronOnDLS::toColumnCurrentSwitchOnDLS() const
{
	return ColumnCurrentSwitchOnDLS(value());
}

SynapseColumnOnDLS NeuronOnDLS::toSynapseColumnOnDLS() const
{
	return SynapseColumnOnDLS(value());
}

SynapseRowOnDLS SynapseDriverOnDLS::toSynapseRowOnDLS() const
{
	return SynapseRowOnDLS(value());
}

SynapseBlockOnDLS SynapseOnDLS::toSynapseBlockOnDLS() const
{
	return SynapseBlockOnDLS(
		ColumnBlockOnDLS(x() / SynapseOnSynapseBlock::size), SynapseDriverOnDLS(y()));
}

SynapseOnSynapseBlock SynapseOnDLS::toSynapseOnSynapseBlock() const
{
	return SynapseOnSynapseBlock(x() % SynapseOnSynapseBlock::size);
}

ColumnCorrelationSwitchOnDLS SynapseOnDLS::toColumnCorrelationSwitchOnDLS() const
{
	return ColumnCorrelationSwitchOnDLS(x());
}

ColumnCurrentSwitchOnDLS SynapseOnDLS::toColumnCurrentSwitchOnDLS() const
{
	return ColumnCurrentSwitchOnDLS(x());
}

ColumnCorrelationSwitchOnColumnCorrelationBlock
ColumnCorrelationSwitchOnDLS::toColumnCorrelationSwitchOnColumnCorrelationBlock() const
{
	return ColumnCorrelationSwitchOnColumnCorrelationBlock(
	    value() % ColumnCorrelationSwitchOnColumnCorrelationBlock::size);
}

ColumnCorrelationBlockOnDLS ColumnCorrelationSwitchOnDLS::toColumnCorrelationBlockOnDLS() const
{
	return ColumnCorrelationBlockOnDLS(
	    value() / ColumnCorrelationSwitchOnColumnCorrelationBlock::size);
}

ColumnCurrentSwitchOnDLS ColumnCorrelationSwitchOnDLS::toColumnCurrentSwitchOnDLS() const
{
	return ColumnCurrentSwitchOnDLS(value());
}

ColumnCurrentSwitchOnColumnCurrentBlock
ColumnCurrentSwitchOnDLS::toColumnCurrentSwitchOnColumnCurrentBlock() const
{
	return ColumnCurrentSwitchOnColumnCurrentBlock(
	    value() % ColumnCurrentSwitchOnColumnCurrentBlock::size);
}

ColumnCurrentBlockOnDLS ColumnCurrentSwitchOnDLS::toColumnCurrentBlockOnDLS() const
{
	return ColumnCurrentBlockOnDLS(value() / ColumnCurrentSwitchOnColumnCurrentBlock::size);
}

ColumnCorrelationSwitchOnDLS ColumnCurrentSwitchOnDLS::toColumnCorrelationSwitchOnDLS() const
{
	return ColumnCorrelationSwitchOnDLS(value());
}

CapMemColumnOnDLS NeuronOnDLS::toCapMemColumnOnDLS() const
{
	return CapMemColumnOnDLS(value());
}

CapMemCellOnDLS::CapMemCellOnDLS(NeuronOnDLS const& neuron, NeuronParameter const& parameter)
	: CapMemCellOnDLS(CapMemColumnOnDLS(neuron), CapMemRowOnDLS(static_cast<std::size_t>(parameter))) {}

CapMemCellOnDLS::CapMemCellOnDLS(CommonNeuronParameter const& parameter)
    : CapMemCellOnDLS(CapMemColumnOnDLS::SharedCapMemColumnOnDLS(),
                      CapMemRowOnDLS(static_cast<std::size_t>(parameter))) {}

bool CapMemCellOnDLS::isShared() const
{
	return x().isShared();
}

NeuronOnDLS CapMemCellOnDLS::toNeuronOnDLS() const
{
	if (isShared())
		throw std::overflow_error("Global CapMem cell has no corresponding NeuronOnDLS");
	return NeuronOnDLS(x());
}

DACOnBoard const DACOnBoard::DAC_25_DECIVOLT{0};
DACOnBoard const DACOnBoard::DAC_12_DECIVOLT{1};

} // namespace v2
} // namespace hicann_dls
} // namespace halco
