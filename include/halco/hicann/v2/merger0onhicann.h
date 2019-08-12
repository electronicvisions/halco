#pragma once

extern "C" {
#include <stdint.h>
}

#include "halco/common/genpybind.h"
#include "halco/hicann/v2/l1.h"
#include "halco/hicann/v2/mergerproxy.h"

namespace halco {
namespace hicann {
namespace v2 GENPYBIND_TAG_HALCO_HICANN_V2 {

struct GENPYBIND(inline_base("*")) Merger0OnHICANN
    : public common::detail::RantWrapper<Merger0OnHICANN, uint_fast16_t, 7, 0>
{
	PYPP_CONSTEXPR explicit Merger0OnHICANN(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	typedef MergerProxy<
		BackgroundGeneratorOnHICANN,
		NeuronBlockOnHICANN> inputs_t;

	inputs_t inputs() const
	{
		// FIXME: look up real connectivity
		return inputs_t(
			BackgroundGeneratorOnHICANN(value()),
			NeuronBlockOnHICANN(value()));
	}
};

} // v2
} // hicann
} // halco

namespace std {
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::Merger0OnHICANN)
} // std
