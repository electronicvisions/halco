#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/***********\
    Spike
\***********/

/**
 * The chip supports packing from 1 to 3 spikes in one instruction to be processed in one clock
 * cycle by the transport layer. In order to have unique container coordinates, these are layed out
 * as separate coordinate types of length 1.
 */

struct GENPYBIND(inline_base("*")) SpikePack1ToChipOnDLS
    : public common::detail::RantWrapper<SpikePack1ToChipOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit SpikePack1ToChipOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*")) SpikePack2ToChipOnDLS
    : public common::detail::RantWrapper<SpikePack2ToChipOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit SpikePack2ToChipOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*")) SpikePack3ToChipOnDLS
    : public common::detail::RantWrapper<SpikePack3ToChipOnDLS, uint_fast16_t, 0, 0>
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


/**********\
    SPL1
\**********/

struct GENPYBIND(inline_base("*")) SPL1Address
    : public halco::common::detail::RantWrapper<SPL1Address, uint16_t, 3 /* 2bit */, 0>
{
	constexpr explicit SPL1Address(uintmax_t value = 0) GENPYBIND(implicit_conversion) :
	    rant_t(value)
	{}
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

} // namespace std
