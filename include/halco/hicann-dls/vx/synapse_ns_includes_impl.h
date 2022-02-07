ColumnCorrelationQuadOnSynram SynapseQuadColumnOnDLS::toColumnCorrelationQuadOnSynram() const
{
	return ColumnCorrelationQuadOnSynram(toEnum());
}

ColumnCurrentQuadOnSynram SynapseQuadColumnOnDLS::toColumnCurrentQuadOnSynram() const
{
	return ColumnCurrentQuadOnSynram(toEnum());
}

SynapseWeightQuadOnDLS SynapseQuadOnDLS::toSynapseWeightQuadOnDLS() const
{
	return SynapseWeightQuadOnDLS(toEnum());
}

SynapseLabelQuadOnDLS SynapseQuadOnDLS::toSynapseLabelQuadOnDLS() const
{
	return SynapseLabelQuadOnDLS(toEnum());
}

SynapseCorrelationCalibQuadOnDLS SynapseQuadOnDLS::toSynapseCorrelationCalibQuadOnDLS() const
{
	return SynapseCorrelationCalibQuadOnDLS(toEnum());
}

NeuronConfigBlockOnDLS SynapseWeightQuadOnDLS::toNeuronConfigBlockOnDLS() const
{
	return toSynapseQuadOnDLS().toNeuronConfigBlockOnDLS();
}

SynapseQuadOnDLS SynapseWeightQuadOnDLS::toSynapseQuadOnDLS() const
{
	return SynapseQuadOnDLS(toEnum());
}

SynapseLabelQuadOnDLS SynapseWeightQuadOnDLS::toSynapseLabelQuadOnDLS() const
{
	return SynapseLabelQuadOnDLS(toEnum());
}

SynapseCorrelationCalibQuadOnDLS SynapseWeightQuadOnDLS::toSynapseCorrelationCalibQuadOnDLS() const
{
	return SynapseCorrelationCalibQuadOnDLS(toEnum());
}

NeuronConfigBlockOnDLS SynapseLabelQuadOnDLS::toNeuronConfigBlockOnDLS() const
{
	return toSynapseQuadOnDLS().toNeuronConfigBlockOnDLS();
}

SynapseWeightQuadOnDLS SynapseLabelQuadOnDLS::toSynapseWeightQuadOnDLS() const
{
	return SynapseWeightQuadOnDLS(toEnum());
}

SynapseQuadOnDLS SynapseLabelQuadOnDLS::toSynapseQuadOnDLS() const
{
	return SynapseQuadOnDLS(toEnum());
}

SynapseCorrelationCalibQuadOnDLS SynapseLabelQuadOnDLS::toSynapseCorrelationCalibQuadOnDLS() const
{
	return SynapseCorrelationCalibQuadOnDLS(toEnum());
}

NeuronConfigBlockOnDLS SynapseCorrelationCalibQuadOnDLS::toNeuronConfigBlockOnDLS() const
{
	return toSynapseQuadOnDLS().toNeuronConfigBlockOnDLS();
}

SynapseWeightQuadOnDLS SynapseCorrelationCalibQuadOnDLS::toSynapseWeightQuadOnDLS() const
{
	return SynapseWeightQuadOnDLS(toEnum());
}

SynapseLabelQuadOnDLS SynapseCorrelationCalibQuadOnDLS::toSynapseLabelQuadOnDLS() const
{
	return SynapseLabelQuadOnDLS(toEnum());
}

SynapseQuadOnDLS SynapseCorrelationCalibQuadOnDLS::toSynapseQuadOnDLS() const
{
	return SynapseQuadOnDLS(toEnum());
}

NeuronColumnOnDLS SynapseOnSynapseRow::toNeuronColumnOnDLS() const
{
	return NeuronColumnOnDLS(toEnum());
}

CADCChannelColumnOnSynram SynapseOnSynapseRow::toCADCChannelColumnOnSynram() const
{
	return CADCChannelColumnOnSynram(toEnum());
}
