#include "halco/hicann/v2/neuron.h"

using namespace halco::common;

namespace halco {
namespace hicann {
namespace v2 {

HICANNGlobal NeuronBlockGlobal::toHICANNGlobal() const {
	return HICANNGlobal(toHICANNOnWafer(), toWafer());
}

NeuronOnHICANN NeuronOnNeuronBlock::toNeuronOnHICANN(
	NeuronBlockOnHICANN const& block) const {
	return NeuronOnHICANN(X(block * x_type::end + x()), y());
}

NeuronOnWafer NeuronOnNeuronBlock::toNeuronOnWafer(NeuronBlockOnWafer const& block) const {
	return NeuronOnWafer(toNeuronOnHICANN(block), block.toHICANNOnWafer());
}

NeuronGlobal NeuronOnNeuronBlock::toNeuronGlobal(NeuronBlockGlobal const& block) const {
	return NeuronGlobal(toNeuronOnHICANN(block), block.toHICANNGlobal());
}

NeuronOnHICANN NeuronOnFGBlock::toNeuronOnHICANN(const FGBlockOnHICANN& block) const {
	X x(value() + 128 * block.x().value());
	return NeuronOnHICANN(x, block.y());
}

NeuronBlockOnWafer NeuronOnWafer::toNeuronBlockOnWafer() const {
	return NeuronBlockOnWafer{toNeuronBlockOnHICANN(), toHICANNOnWafer()};
}

HICANNGlobal NeuronGlobal::toHICANNGlobal() const {
	return HICANNGlobal(toHICANNOnWafer(), toWafer());
}

NeuronBlockGlobal NeuronGlobal::toNeuronBlockGlobal() const {
	return NeuronBlockGlobal{toNeuronBlockOnHICANN(), toHICANNGlobal()};
}

SynapticInputOnNeuron const SynapticInputOnNeuron::default_inh{0};
SynapticInputOnNeuron const SynapticInputOnNeuron::default_exc{1};

} // v2
} // hicann
} // halco
