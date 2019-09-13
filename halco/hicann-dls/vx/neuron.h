#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/**********\
   Neuron
\**********/

struct GENPYBIND(inline_base("*")) NeuronOnNeuronBlock
    : public common::detail::RantWrapper<NeuronOnNeuronBlock, uint_fast16_t, 127, 0>
{
	constexpr explicit NeuronOnNeuronBlock(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) NeuronBlockOnDLS
    : public common::detail::RantWrapper<NeuronBlockOnDLS, uint_fast16_t, 3, 0>
{
	constexpr explicit NeuronBlockOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


HALCO_COORDINATE_MIXIN(NeuronMixin, NeuronBlockOnDLS, neuron)

struct GENPYBIND(inline_base("*NeuronMixin*")) NeuronOnDLS
    : public NeuronMixin<NeuronOnDLS, NeuronOnNeuronBlock>
{
	NeuronOnDLS() = default;

	explicit NeuronOnDLS(
	    NeuronOnNeuronBlock const& neuron, NeuronBlockOnDLS const& block = NeuronBlockOnDLS()) :
	    mixin_t(neuron, block)
	{}

	explicit NeuronOnDLS(enum_type const& e) : mixin_t(e) {}

	NeuronOnNeuronBlock toNeuronOnNeuronBlock() const { return This(); }
};


struct GENPYBIND(inline_base("*")) CommonNeuronConfigOnDLS
    : public common::detail::RantWrapper<CommonNeuronConfigOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit CommonNeuronConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronOnNeuronBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonNeuronConfigOnDLS)

} // namespace std
