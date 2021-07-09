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

LogicalNeuronCompartments::LogicalNeuronCompartments(Compartments const& compartments)
{
	std::set<AtomicNeuronOnLogicalNeuron> unique;
	size_t n = 0;
	for (auto const& [_, compartment] : compartments) {
		unique.insert(compartment.begin(), compartment.end());
		n += compartment.size();
	}
	if (unique.size() != n) {
		throw std::runtime_error("Multiple compartments contain the same neuron(s).");
	}
	m_compartments = compartments;
}

LogicalNeuronCompartments::Compartments const& LogicalNeuronCompartments::get_compartments() const
{
	return m_compartments;
}

NeuronColumnOnLogicalNeuron LogicalNeuronCompartments::get_left_most_column() const
{
	NeuronColumnOnLogicalNeuron lmost(NeuronColumnOnLogicalNeuron::max);
	for (auto const& [_, compartment] : m_compartments) {
		auto const lm =
		    std::min_element(
		        compartment.begin(), compartment.end(),
		        [](auto const& a, auto const& b) {
			        return a.toNeuronColumnOnLogicalNeuron() < b.toNeuronColumnOnLogicalNeuron();
		        })
		        ->toNeuronColumnOnLogicalNeuron();
		lmost = std::min(lm, lmost);
	}
	return lmost;
}

NeuronColumnOnLogicalNeuron LogicalNeuronCompartments::get_right_most_column() const
{
	NeuronColumnOnLogicalNeuron rmost(NeuronColumnOnLogicalNeuron::min);
	for (auto const& [_, compartment] : m_compartments) {
		auto const rm =
		    std::max_element(
		        compartment.begin(), compartment.end(),
		        [](auto const& a, auto const& b) {
			        return a.toNeuronColumnOnLogicalNeuron() < b.toNeuronColumnOnLogicalNeuron();
		        })
		        ->toNeuronColumnOnLogicalNeuron();
		rmost = std::max(rm, rmost);
	}
	return rmost;
}

NeuronRowOnLogicalNeuron LogicalNeuronCompartments::get_top_most_row() const
{
	NeuronRowOnLogicalNeuron tmost(NeuronRowOnLogicalNeuron::max);
	for (auto const& [_, compartment] : m_compartments) {
		auto const tm =
		    std::min_element(
		        compartment.begin(), compartment.end(),
		        [](auto const& a, auto const& b) {
			        return a.toNeuronRowOnLogicalNeuron() < b.toNeuronRowOnLogicalNeuron();
		        })
		        ->toNeuronRowOnLogicalNeuron();
		tmost = std::min(tm, tmost);
	}
	return tmost;
}

NeuronRowOnLogicalNeuron LogicalNeuronCompartments::get_bottom_most_row() const
{
	NeuronRowOnLogicalNeuron bmost(NeuronRowOnLogicalNeuron::min);
	for (auto const& [_, compartment] : m_compartments) {
		auto const bm =
		    std::max_element(
		        compartment.begin(), compartment.end(),
		        [](auto const& a, auto const& b) {
			        return a.toNeuronRowOnLogicalNeuron() < b.toNeuronRowOnLogicalNeuron();
		        })
		        ->toNeuronRowOnLogicalNeuron();
		bmost = std::max(bm, bmost);
	}
	return bmost;
}

LogicalNeuronCompartments LogicalNeuronCompartments::flip_x() const
{
	Compartments flipped_compartments;
	auto const lmost = get_left_most_column();
	auto const rmost = get_right_most_column();
	for (auto const& [index, compartment] : m_compartments) {
		Compartment& flipped_compartment = flipped_compartments[index];
		for (auto const& neuron : compartment) {
			flipped_compartment.push_back(AtomicNeuronOnLogicalNeuron(
			    NeuronColumnOnLogicalNeuron(
			        lmost.value() + rmost.value() - neuron.toNeuronColumnOnLogicalNeuron().value()),
			    neuron.toNeuronRowOnLogicalNeuron()));
		}
	}
	return LogicalNeuronCompartments(flipped_compartments);
}

LogicalNeuronCompartments LogicalNeuronCompartments::flip_y() const
{
	Compartments flipped_compartments;
	auto const tmost = get_top_most_row();
	auto const bmost = get_bottom_most_row();
	for (auto const& [index, compartment] : m_compartments) {
		Compartment& flipped_compartment = flipped_compartments[index];
		for (auto const& neuron : compartment) {
			flipped_compartment.push_back(AtomicNeuronOnLogicalNeuron(
			    neuron.toNeuronColumnOnLogicalNeuron(),
			    NeuronRowOnLogicalNeuron(
			        tmost.value() + bmost.value() - neuron.toNeuronRowOnLogicalNeuron().value())));
		}
	}
	return LogicalNeuronCompartments(flipped_compartments);
}

bool LogicalNeuronCompartments::operator==(LogicalNeuronCompartments const& other) const
{
	return m_compartments == other.m_compartments;
}

bool LogicalNeuronCompartments::operator!=(LogicalNeuronCompartments const& other) const
{
	return !(*this == other);
}

bool LogicalNeuronCompartments::operator<(LogicalNeuronCompartments const& other) const
{
	return m_compartments < other.m_compartments;
}

bool LogicalNeuronCompartments::operator>(LogicalNeuronCompartments const& other) const
{
	return m_compartments > other.m_compartments;
}

bool LogicalNeuronCompartments::operator<=(LogicalNeuronCompartments const& other) const
{
	return m_compartments <= other.m_compartments;
}

bool LogicalNeuronCompartments::operator>=(LogicalNeuronCompartments const& other) const
{
	return m_compartments >= other.m_compartments;
}

std::ostream& operator<<(std::ostream& os, LogicalNeuronCompartments const& config)
{
	os << "LogicalNeuronCompartments(\n";
	for (auto const& [index, compartment] : config.m_compartments) {
		os << index << "\n";
		for (auto const& neuron : compartment) {
			os << "\t" << neuron << "\n";
		}
	}
	os << ")";
	return os;
}

template <typename Archive>
void LogicalNeuronCompartments::serialize(Archive& ar, uint32_t const)
{
	ar(m_compartments);
}

LogicalNeuronOnDLS::LogicalNeuronOnDLS(
    LogicalNeuronCompartments const& compartments, AtomicNeuronOnDLS const& anchor)
{
	auto const lmost = compartments.get_left_most_column();
	auto const rmost = compartments.get_right_most_column();
	auto const bmost = compartments.get_bottom_most_row();
	auto const tmost = compartments.get_top_most_row();
	auto const height = bmost.value() - tmost.value();
	auto const width = rmost.value() - lmost.value();

	if ((anchor.toNeuronRowOnDLS().value() + height) > NeuronRowOnDLS::max) {
		throw std::runtime_error(
		    "LogicalNeuron anchor results in placement of compartments outside of neuron grid.");
	}
	if ((((anchor.toNeuronColumnOnDLS().value()) < NeuronColumnOnLogicalNeuron::max) &&
	     ((anchor.toNeuronColumnOnDLS().value() + width) > NeuronColumnOnLogicalNeuron::max)) ||
	    (((anchor.toNeuronColumnOnDLS().value()) > NeuronColumnOnLogicalNeuron::max) &&
	     ((anchor.toNeuronColumnOnDLS().value() + width) > NeuronColumnOnDLS::max))) {
		throw std::runtime_error(
		    "LogicalNeuron anchor results in placement of compartments outside of neuron grid.");
	}
	for (auto const& [index, compartment] : compartments.get_compartments()) {
		auto& placed_compartment = m_compartments[index];
		for (auto const& neuron : compartment) {
			placed_compartment.push_back(AtomicNeuronOnDLS(
			    NeuronColumnOnDLS(
			        anchor.toNeuronColumnOnDLS().value() +
			        neuron.toNeuronColumnOnLogicalNeuron().value() - lmost.value()),
			    NeuronRowOnDLS(
			        anchor.toNeuronRowOnDLS().value() +
			        neuron.toNeuronRowOnLogicalNeuron().value() - tmost.value())));
		}
	}
}

LogicalNeuronOnDLS::PlacedCompartments LogicalNeuronOnDLS::get_placed_compartments() const
{
	return m_compartments;
}

bool LogicalNeuronOnDLS::operator==(LogicalNeuronOnDLS const& other) const
{
	return (m_compartments == other.m_compartments);
}

bool LogicalNeuronOnDLS::operator!=(LogicalNeuronOnDLS const& other) const
{
	return !(*this == other);
}

bool LogicalNeuronOnDLS::operator<(LogicalNeuronOnDLS const& other) const
{
	return m_compartments < other.m_compartments;
}

bool LogicalNeuronOnDLS::operator>(LogicalNeuronOnDLS const& other) const
{
	return m_compartments > other.m_compartments;
}

bool LogicalNeuronOnDLS::operator<=(LogicalNeuronOnDLS const& other) const
{
	return m_compartments <= other.m_compartments;
}

bool LogicalNeuronOnDLS::operator>=(LogicalNeuronOnDLS const& other) const
{
	return m_compartments >= other.m_compartments;
}

std::ostream& operator<<(std::ostream& os, LogicalNeuronOnDLS const& config)
{
	os << "LogicalNeuronOnDLS(\n";
	for (auto const& [index, compartment] : config.m_compartments) {
		os << index << "\n";
		for (auto const& neuron : compartment) {
			os << "\t" << neuron << "\n";
		}
	}
	os << ")";
	return os;
}

template <typename Archive>
void LogicalNeuronOnDLS::serialize(Archive& ar, uint32_t const)
{
	ar(m_compartments);
}
