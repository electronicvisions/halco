#include "halco/hicann-dls/vx/event.h"

#include "halco/hicann-dls/vx/background.h"
#include "halco/hicann-dls/vx/fpga.h"
#include "halco/hicann-dls/vx/padi.h"
#include "halco/hicann-dls/vx/routing_crossbar.h"

#include "hate/math.h"

namespace halco::hicann_dls::vx {

CrossbarInputOnDLS SPL1Address::toCrossbarInputOnDLS() const
{
	return CrossbarInputOnDLS(
	    toEnum() +
	    (CrossbarInputOnDLS::size - BackgroundSpikeSourceOnDLS::size - SPL1Address::size));
}

CrossbarL2OutputOnDLS SPL1Address::toCrossbarL2OutputOnDLS() const
{
	return CrossbarL2OutputOnDLS(toEnum());
}

halco::hicann_dls::vx::SPL1Address SpikeLabel::get_spl1_address() const
{
	return halco::hicann_dls::vx::SPL1Address(value() >> 14);
}

void SpikeLabel::set_spl1_address(halco::hicann_dls::vx::SPL1Address const value)
{
	operator=(SpikeLabel(
	    (this->value() & halco::hicann_dls::vx::NeuronLabel::max) |
	    (static_cast<uint16_t>(value) << 14)));
}

halco::hicann_dls::vx::NeuronLabel SpikeLabel::get_neuron_label() const
{
	return halco::hicann_dls::vx::NeuronLabel(value() & halco::hicann_dls::vx::NeuronLabel::max);
}

void SpikeLabel::set_neuron_label(halco::hicann_dls::vx::NeuronLabel const value)
{
	operator=(SpikeLabel(
	    (static_cast<uint16_t>(value) & halco::hicann_dls::vx::NeuronLabel::max) |
	    (this->value() & 0xc000)));
}

SpikeLabel::PADILabel SpikeLabel::get_padi_label() const
{
	return PADILabel(value() & 0x3ff);
}

void SpikeLabel::set_padi_label(PADILabel const value)
{
	operator=(SpikeLabel((static_cast<uint16_t>(value) & 0x3ff) | (this->value() & 0xfc00)));
}

halco::hicann_dls::vx::NeuronEventOutputOnDLS SpikeLabel::get_neuron_event_output() const
{
	return halco::hicann_dls::vx::NeuronEventOutputOnDLS(
	    halco::common::Enum((value() >> hate::math::num_bits(NeuronBackendAddressOut::max)) & 0x7));
}

void SpikeLabel::set_neuron_event_output(halco::hicann_dls::vx::NeuronEventOutputOnDLS const value)
{
	operator=(SpikeLabel(
	    (static_cast<uint16_t>(value.toEnum())
	     << hate::math::num_bits(NeuronBackendAddressOut::max)) |
	    (this->value() & (~0x700))));
}

NeuronBackendAddressOut SpikeLabel::get_neuron_backend_address_out() const
{
	return NeuronBackendAddressOut(value() & 0xff);
}

void SpikeLabel::set_neuron_backend_address_out(NeuronBackendAddressOut const value)
{
	operator=(SpikeLabel((static_cast<uint16_t>(value) & 0xff) | (this->value() & 0xff00)));
}

PADIRowSelectAddress SpikeLabel::get_row_select_address() const
{
	return PADIRowSelectAddress((value() & (static_cast<uint16_t>(0b11111) << 6)) >> 6);
}

void SpikeLabel::set_row_select_address(PADIRowSelectAddress const value)
{
	operator=(SpikeLabel(
	    (static_cast<uint16_t>(value) << 6) |
	    (this->value() & ~(static_cast<uint16_t>(0b11111) << 6))));
}

SynapseLabel SpikeLabel::get_synapse_label() const
{
	return SynapseLabel(value() & 0x3f);
}

void SpikeLabel::set_synapse_label(SynapseLabel const value)
{
	operator=(SpikeLabel((static_cast<uint16_t>(value) & 0x3f) | (this->value() & 0xffc0)));
}

SpikeIOOutputRouteOnFPGA SpikeLabel::toSpikeIOOutputRouteOnFPGA() const
{
	return SpikeIOOutputRouteOnFPGA(toEnum());
}

} // namespace halco::hicann_dls::vx
