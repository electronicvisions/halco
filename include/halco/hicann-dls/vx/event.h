#pragma once
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/hicann-dls/vx/neuron.h"
#include "halco/hicann-dls/vx/padi.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/***********\
    Spike
\***********/

/**
 * The chip supports packing from 1 to 3 spikes in one instruction to be processed in one clock
 * cycle by the transport layer. In order to have unique container coordinates, these are layed out
 * as separate coordinate types of length 1.
 */

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    SpikePack1ToChipOnDLS
    : public common::detail::RantWrapper<SpikePack1ToChipOnDLS, uint_fast16_t, 0, 0>
    , common::CoordinateBase<SpikePack1ToChipOnDLS>
{
	constexpr explicit SpikePack1ToChipOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    SpikePack2ToChipOnDLS
    : public common::detail::RantWrapper<SpikePack2ToChipOnDLS, uint_fast16_t, 0, 0>
    , common::CoordinateBase<SpikePack2ToChipOnDLS>
{
	constexpr explicit SpikePack2ToChipOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    SpikePack3ToChipOnDLS
    : public common::detail::RantWrapper<SpikePack3ToChipOnDLS, uint_fast16_t, 0, 0>
    , common::CoordinateBase<SpikePack3ToChipOnDLS>
{
	constexpr explicit SpikePack3ToChipOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*")) SpikePackFromFPGAOnDLS
    : public halco::common::detail::RantWrapper<SpikePackFromFPGAOnDLS, uint_fast16_t, 3, 1>
{
	constexpr explicit SpikePackFromFPGAOnDLS(uintmax_t const value = 1)
	    GENPYBIND(implicit_conversion) :
	    rant_t(value)
	{}
};


struct GENPYBIND(inline_base("*")) MADCSamplePackFromFPGAOnDLS
    : public halco::common::detail::RantWrapper<MADCSamplePackFromFPGAOnDLS, uint_fast16_t, 3, 1>
{
	constexpr explicit MADCSamplePackFromFPGAOnDLS(uintmax_t const value = 1)
	    GENPYBIND(implicit_conversion) :
	    rant_t(value)
	{}
};


/************\
    Neuron
\************/

struct GENPYBIND(inline_base("*")) NeuronLabel
    : public halco::common::detail::RantWrapper<NeuronLabel, uint16_t, 0x3fff /* 14bit */, 0>
{
	constexpr explicit NeuronLabel(uintmax_t value = 0) GENPYBIND(implicit_conversion) :
	    rant_t(value)
	{}
};


struct CrossbarInputOnDLS;
struct CrossbarL2OutputOnDLS;

/**********\
    SPL1
\**********/

struct GENPYBIND(inline_base("*")) SPL1Address
    : public halco::common::detail::RantWrapper<SPL1Address, uint16_t, 3 /* 2bit */, 0>
{
	constexpr explicit SPL1Address(uintmax_t value = 0) GENPYBIND(implicit_conversion) :
	    rant_t(value)
	{}

	CrossbarInputOnDLS toCrossbarInputOnDLS() const;
	CrossbarL2OutputOnDLS toCrossbarL2OutputOnDLS() const;
};


/****************\
    SpikeLabel
\****************/

// Forward declaration from 'halco/hicann-dls/vx/fpga.h'
struct SpikeIOOutputRouteOnFPGA;

struct GENPYBIND(inline_base("*")) SpikeLabel
    : public halco::common::detail::BaseType<SpikeLabel, uint16_t>
{
	constexpr explicit SpikeLabel(value_type const value = value_type()) : base_t(value) {}

	/** SPL1-label, bits 14-15. */
	GENPYBIND(getter_for(spl1_address))
	SPL1Address get_spl1_address() const;
	GENPYBIND(setter_for(spl1_address))
	void set_spl1_address(SPL1Address value);

	/** Label type processed by Crossbar, bits 0-13. */
	GENPYBIND(getter_for(neuron_label))
	NeuronLabel get_neuron_label() const;
	GENPYBIND(setter_for(neuron_label))
	void set_neuron_label(NeuronLabel value);

	/** Label type processed by PADI-bus, bits 0-10. */
	struct GENPYBIND(inline_base("*")) PADILabel
	    : public halco::common::detail::RantWrapper<PADILabel, uint_fast16_t, 0x3ff, 0>
	{
		constexpr explicit PADILabel(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
		    rant_t(val)
		{}
	};

	/** PADI-bus label, bits 0-10. */
	GENPYBIND(getter_for(padi_label))
	PADILabel get_padi_label() const;
	GENPYBIND(setter_for(padi_label))
	void set_padi_label(PADILabel value);

	/** Neuron event output of on-chip neurons, bits 8-10. */
	GENPYBIND(getter_for(neuron_event_output))
	NeuronEventOutputOnDLS get_neuron_event_output() const;
	GENPYBIND(setter_for(neuron_event_output))
	void set_neuron_event_output(NeuronEventOutputOnDLS value);

	/** Configurable neuron backend output label, bits 0-7. */
	GENPYBIND(getter_for(neuron_backend_address_out))
	NeuronBackendAddressOut get_neuron_backend_address_out() const;
	GENPYBIND(setter_for(neuron_backend_address_out))
	void set_neuron_backend_address_out(NeuronBackendAddressOut value);

	/** Configurable row select address on PADIBus, bits 6-10. */
	GENPYBIND(getter_for(row_select_address))
	PADIRowSelectAddress get_row_select_address() const;
	GENPYBIND(setter_for(row_select_address))
	void set_row_select_address(PADIRowSelectAddress);

	/** Configurable synapse address, bits 0-5. */
	GENPYBIND(getter_for(synapse_label))
	SynapseLabel get_synapse_label() const;
	GENPYBIND(setter_for(synapse_label))
	void set_synapse_label(SynapseLabel value);

	SpikeIOOutputRouteOnFPGA toSpikeIOOutputRouteOnFPGA() const;
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikePack1ToChipOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikePack2ToChipOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikePack3ToChipOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikePackFromFPGAOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::MADCSamplePackFromFPGAOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronLabel)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SPL1Address)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikeLabel)

} // namespace std
