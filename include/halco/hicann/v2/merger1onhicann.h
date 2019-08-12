#pragma once

extern "C" {
#include <stdint.h>
}

#include "halco/common/genpybind.h"
#include "halco/hicann/v2/merger0onhicann.h"
#include "halco/hicann/v2/mergerproxy.h"

namespace halco {
namespace hicann {
namespace v2 GENPYBIND_TAG_HALCO_HICANN_V2 {

struct GENPYBIND(inline_base("*")) Merger1OnHICANN
    : public common::detail::RantWrapper<Merger1OnHICANN, uint_fast16_t, 3, 0>
{
	PYPP_CONSTEXPR explicit Merger1OnHICANN(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	typedef MergerProxy<
		Merger0OnHICANN,
		Merger0OnHICANN> inputs_t;

	inputs_t inputs() const
	{
		return inputs_t(
			Merger0OnHICANN(value()*2  ),
			Merger0OnHICANN(value()*2+1));
	}
};

} // v2
} // hicann
} // halco

namespace std {
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::Merger1OnHICANN)
} // std
