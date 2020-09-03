NeuronResetOnDLS NeuronConfigOnDLS::toNeuronResetOnDLS() const
{
	auto block = toNeuronConfigBlockOnDLS().toNeuronResetBlockOnDLS();
	return NeuronResetOnDLS(
	    NeuronResetOnNeuronResetBlock(
	        toNeuronConfigOnNeuronConfigBlock() +
	        ((toNeuronConfigBlockOnDLS() / NeuronResetBlockOnDLS::size)
	             ? NeuronConfigOnNeuronConfigBlock::size
	             : 0)),
	    block);
}

SpikeCounterReadOnDLS NeuronConfigOnDLS::toSpikeCounterReadOnDLS() const
{
	return SpikeCounterReadOnDLS(toNeuronResetOnDLS().toEnum());
}

SpikeCounterResetOnDLS NeuronConfigOnDLS::toSpikeCounterResetOnDLS() const
{
	return SpikeCounterResetOnDLS(toNeuronResetOnDLS().toEnum());
}

SynapseOnSynapseRow NeuronColumnOnDLS::toSynapseOnSynapseRow() const
{
	return SynapseOnSynapseRow(toEnum());
}

CapMemColumnOnCapMemBlock NeuronColumnOnDLS::toCapMemColumnOnCapMemBlock() const
{
	return CapMemColumnOnCapMemBlock(toEnum() % NeuronConfigOnNeuronConfigBlock::size);
}

NeuronEventOutputOnDLS NeuronColumnOnDLS::toNeuronEventOutputOnDLS() const
{
	return NeuronEventOutputOnDLS(common::Enum(toEnum() / (size / NeuronEventOutputOnDLS::size)));
}

NeuronConfigOnDLS AtomicNeuronOnDLS::toNeuronConfigOnDLS() const
{
	return NeuronConfigOnDLS(toEnum());
}

NeuronResetOnDLS AtomicNeuronOnDLS::toNeuronResetOnDLS() const
{
	return toNeuronConfigOnDLS().toNeuronResetOnDLS();
}

SpikeCounterReadOnDLS AtomicNeuronOnDLS::toSpikeCounterReadOnDLS() const
{
	return toNeuronConfigOnDLS().toSpikeCounterReadOnDLS();
}

SpikeCounterResetOnDLS AtomicNeuronOnDLS::toSpikeCounterResetOnDLS() const
{
	return toNeuronConfigOnDLS().toSpikeCounterResetOnDLS();
}

NeuronBackendConfigOnDLS AtomicNeuronOnDLS::toNeuronBackendConfigOnDLS() const
{
	return NeuronBackendConfigOnDLS(toNeuronResetOnDLS().toEnum());
}

CapMemColumnOnCapMemBlock AtomicNeuronOnDLS::toCapMemColumnOnCapMemBlock() const
{
	return toNeuronColumnOnDLS().toCapMemColumnOnCapMemBlock();
}

CapMemBlockOnDLS AtomicNeuronOnDLS::toCapMemBlockOnDLS() const
{
	return toNeuronConfigOnDLS().toNeuronConfigBlockOnDLS().toCapMemBlockOnDLS();
}

NeuronRowOnDLS NeuronConfigOnDLS::toNeuronRowOnDLS() const
{
	return NeuronRowOnDLS(toEnum() / SynapseOnSynapseRow::size);
}

SynapseOnSynapseRow NeuronConfigOnDLS::toSynapseOnSynapseRow() const
{
	return SynapseOnSynapseRow(toEnum() % SynapseOnSynapseRow::size);
}

AtomicNeuronOnDLS NeuronConfigOnDLS::toAtomicNeuronOnDLS() const
{
	return AtomicNeuronOnDLS(toSynapseOnSynapseRow().toNeuronColumnOnDLS(), toNeuronRowOnDLS());
}

SynapseQuadColumnOnDLS NeuronConfigOnDLS::toSynapseQuadColumnOnDLS() const
{
	return toSynapseOnSynapseRow().toSynapseQuadColumnOnDLS();
}

EntryOnQuad NeuronConfigOnDLS::toEntryOnQuad() const
{
	return toSynapseOnSynapseRow().toEntryOnQuad();
}

NeuronBackendConfigBlockOnDLS NeuronConfigOnDLS::toNeuronBackendConfigBlockOnDLS() const
{
	return toAtomicNeuronOnDLS().toNeuronBackendConfigOnDLS().toNeuronBackendConfigBlockOnDLS();
}

NeuronBackendConfigOnNeuronBackendConfigBlock
NeuronConfigOnDLS::toNeuronBackendConfigOnNeuronBackendConfigBlock() const
{
	return toAtomicNeuronOnDLS()
	    .toNeuronBackendConfigOnDLS()
	    .toNeuronBackendConfigOnNeuronBackendConfigBlock();
}

NeuronBackendConfigOnDLS NeuronConfigOnDLS::toNeuronBackendConfigOnDLS() const
{
	return toAtomicNeuronOnDLS().toNeuronBackendConfigOnDLS();
}

CommonNeuronBackendConfigOnDLS NeuronConfigOnDLS::toCommonNeuronBackendConfigOnDLS() const
{
	return toNeuronBackendConfigBlockOnDLS().toCommonNeuronBackendConfigOnDLS();
}

NeuronColumnOnDLS NeuronBackendConfigOnDLS::toNeuronColumnOnDLS() const
{
	return NeuronColumnOnDLS(
	    (toNeuronBackendConfigOnNeuronBackendConfigBlock() %
	     NeuronConfigOnNeuronConfigBlock::size) +
	    (toNeuronBackendConfigBlockOnDLS() * NeuronConfigOnNeuronConfigBlock::size));
}

NeuronRowOnDLS NeuronBackendConfigOnDLS::toNeuronRowOnDLS() const
{
	return NeuronRowOnDLS(
	    toNeuronBackendConfigOnNeuronBackendConfigBlock() / NeuronConfigOnNeuronConfigBlock::size);
}

AtomicNeuronOnDLS NeuronBackendConfigOnDLS::toAtomicNeuronOnDLS() const
{
	return AtomicNeuronOnDLS(toNeuronColumnOnDLS(), toNeuronRowOnDLS());
}

NeuronConfigOnDLS NeuronBackendConfigOnDLS::toNeuronConfigOnDLS() const
{
	return toAtomicNeuronOnDLS().toNeuronConfigOnDLS();
}

SpikeCounterReadOnDLS NeuronBackendConfigOnDLS::toSpikeCounterReadOnDLS() const
{
	return toNeuronConfigOnDLS().toSpikeCounterReadOnDLS();
}

SpikeCounterResetOnDLS NeuronBackendConfigOnDLS::toSpikeCounterResetOnDLS() const
{
	return toNeuronConfigOnDLS().toSpikeCounterResetOnDLS();
}

CommonNeuronBackendConfigOnDLS NeuronBackendConfigOnDLS::toCommonNeuronBackendConfigOnDLS() const
{
	return toNeuronBackendConfigBlockOnDLS().toCommonNeuronBackendConfigOnDLS();
}

SynramOnDLS AtomicNeuronOnDLS::toSynramOnDLS() const
{
	return toNeuronRowOnDLS().toSynramOnDLS();
}

SynramOnDLS NeuronConfigOnDLS::toSynramOnDLS() const
{
	return toAtomicNeuronOnDLS().toSynramOnDLS();
}

SynramOnDLS NeuronBackendConfigOnDLS::toSynramOnDLS() const
{
	return toAtomicNeuronOnDLS().toSynramOnDLS();
}

NeuronConfigBlockOnDLS NeuronBackendConfigOnDLS::toNeuronConfigBlockOnDLS() const
{
	return toNeuronConfigOnDLS().toNeuronConfigBlockOnDLS();
}

SynapseQuadColumnOnDLS AtomicNeuronOnDLS::toSynapseQuadColumnOnDLS() const
{
	return toNeuronConfigOnDLS().toSynapseQuadColumnOnDLS();
}

ColumnCorrelationQuadOnDLS AtomicNeuronOnDLS::toColumnCorrelationQuadOnDLS() const
{
	return ColumnCorrelationQuadOnDLS(
	    toSynapseQuadColumnOnDLS().toColumnCorrelationQuadOnSynram(), toSynramOnDLS());
}

ColumnCurrentQuadOnDLS AtomicNeuronOnDLS::toColumnCurrentQuadOnDLS() const
{
	return ColumnCurrentQuadOnDLS(
	    toSynapseQuadColumnOnDLS().toColumnCurrentQuadOnSynram(), toSynramOnDLS());
}

ColumnCorrelationQuadOnDLS NeuronConfigOnDLS::toColumnCorrelationQuadOnDLS() const
{
	return toAtomicNeuronOnDLS().toColumnCorrelationQuadOnDLS();
}

ColumnCurrentQuadOnDLS NeuronConfigOnDLS::toColumnCurrentQuadOnDLS() const
{
	return toAtomicNeuronOnDLS().toColumnCurrentQuadOnDLS();
}

common::typed_array<NeuronResetOnDLS, EntryOnQuad> NeuronResetQuadOnDLS::toNeuronResetOnDLS() const
{
	common::typed_array<NeuronResetOnDLS, EntryOnQuad> ret;
	auto const columns = toSynapseQuadColumnOnDLS().toNeuronColumnOnDLS();
	for (auto const e : common::iter_all<EntryOnQuad>()) {
		ret[e] =
		    AtomicNeuronOnDLS(columns[e], toSynramOnDLS().toNeuronRowOnDLS()).toNeuronResetOnDLS();
	}
	return ret;
}
