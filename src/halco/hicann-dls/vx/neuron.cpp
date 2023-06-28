#include "halco/hicann-dls/vx/neuron.h"

#include "halco/common/iter_all.h"
#include "halco/hicann-dls/vx/capmem.h"
#include "halco/hicann-dls/vx/hemisphere.h"
#include "halco/hicann-dls/vx/routing_crossbar.h"
#include "halco/hicann-dls/vx/switch_rows.h"
#include "halco/hicann-dls/vx/synapse.h"

#include "hate/type_index.h"

#include <set>

#ifndef __ppu__
#include "cereal/types/halco/common/geometry.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/cereal.hpp>
#include <cereal/types/map.hpp>
#include <cereal/types/vector.hpp>
#endif

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

AtomicNeuronOnLogicalNeuron AtomicNeuronOnLogicalNeuron::get_neighbor(
    Direction const& direction) const
{
	switch (direction) {
		case Direction::left: {
			AtomicNeuronOnLogicalNeuron neighbor(NeuronColumnOnLogicalNeuron(x().value() - 1), y());
			return neighbor;
		}
		case Direction::right: {
			AtomicNeuronOnLogicalNeuron neighbor(NeuronColumnOnLogicalNeuron(x().value() + 1), y());
			return neighbor;
		}
		case Direction::opposite_row: {
			AtomicNeuronOnLogicalNeuron neighbor(
			    x(), NeuronRowOnLogicalNeuron((y().value() + 1) % NeuronRowOnLogicalNeuron::size));
			return neighbor;
		}
		default: {
#ifndef __ppu__
			throw std::logic_error(
			    "Unsupported direction for neighbor for AtomicNeuronOnLogicalNeuron was chosen.");
#else
			exit(1);
#endif
		}
	}
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
#ifndef __ppu__
		throw std::runtime_error("Multiple compartments contain the same neuron(s).");
#else
		exit(1);
#endif
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

#ifndef __ppu__
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
#endif

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
#ifndef __ppu__
		throw std::runtime_error(
		    "LogicalNeuron anchor results in placement of compartments outside of neuron grid.");
#else
		exit(1);
#endif
	}
	if ((((anchor.toNeuronColumnOnDLS().value()) <= NeuronColumnOnLogicalNeuron::max) &&
	     ((anchor.toNeuronColumnOnDLS().value() + width) > NeuronColumnOnLogicalNeuron::max)) ||
	    (((anchor.toNeuronColumnOnDLS().value()) > NeuronColumnOnLogicalNeuron::max) &&
	     ((anchor.toNeuronColumnOnDLS().value() + width) > NeuronColumnOnDLS::max))) {
#ifndef __ppu__
		throw std::runtime_error(
		    "LogicalNeuron anchor results in placement of compartments outside of neuron grid.");
#else
		exit(1);
#endif
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

LogicalNeuronOnDLS::AtomicNeuronList LogicalNeuronOnDLS::get_atomic_neurons() const
{
	AtomicNeuronList neurons;
	for (auto const& entry : m_compartments) {
		neurons.insert(neurons.end(), entry.second.begin(), entry.second.end());
	}
	return neurons;
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

size_t hash_value(LogicalNeuronOnDLS const& ln)
{
	size_t hash = 0;
	for (auto const& [compartment, atomic_neurons] : ln.get_placed_compartments()) {
		boost::hash_combine(
		    hash, boost::hash<halco::hicann_dls::vx::CompartmentOnLogicalNeuron>()(compartment));
		for (auto const& neuron : atomic_neurons) {
			boost::hash_combine(hash, boost::hash<AtomicNeuronOnDLS>()(neuron));
		}
	}
	return hash;
}

size_t LogicalNeuronOnDLS::hash() const
{
#ifndef __ppu__
	static const size_t seed = boost::hash_value(hate::full_name<LogicalNeuronOnDLS>());
	size_t hash = seed;
#else
	size_t hash = 0;
#endif
	boost::hash_combine(hash, hash_value(*this));
	return hash;
}

#ifndef __ppu__
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
#endif

#ifndef __ppu__
#define EXPLICIT_INSTANTIATE_CEREAL_SERIALIZE(CLASS_NAME)                                          \
	template void CLASS_NAME ::CEREAL_SERIALIZE_FUNCTION_NAME(                                     \
	    cereal::JSONOutputArchive&, std::uint32_t const);                                          \
	template void CLASS_NAME ::CEREAL_SERIALIZE_FUNCTION_NAME(                                     \
	    cereal::JSONInputArchive&, std::uint32_t const);                                           \
	template void CLASS_NAME ::CEREAL_SERIALIZE_FUNCTION_NAME(                                     \
	    cereal::PortableBinaryOutputArchive&, std::uint32_t const);                                \
	template void CLASS_NAME ::CEREAL_SERIALIZE_FUNCTION_NAME(                                     \
	    cereal::PortableBinaryInputArchive&, std::uint32_t const);

EXPLICIT_INSTANTIATE_CEREAL_SERIALIZE(LogicalNeuronCompartments)
EXPLICIT_INSTANTIATE_CEREAL_SERIALIZE(LogicalNeuronOnDLS)
#endif
} // namespace halco::hicann_dls::vx
