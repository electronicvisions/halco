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


NeuronConfigBlockOnDLS CADCChannelConfigOnDLS::toNeuronConfigBlockOnDLS() const
{
	return NeuronConfigBlockOnDLS(
	    (2 * toSynramOnDLS().toEnum()) +
	    (toSynapseOnSynapseRow() / NeuronConfigOnNeuronConfigBlock::size));
}
