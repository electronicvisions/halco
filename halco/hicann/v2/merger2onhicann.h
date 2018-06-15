#pragma once

extern "C" {
#include <stdint.h>
}

#include "halco/hicann/v2/mergerproxy.h"
#include "halco/hicann/v2/merger1onhicann.h"

namespace halco {
namespace hicann {
namespace v2 {

struct Merger2OnHICANN : public common::detail::RantWrapper<Merger2OnHICANN, uint_fast16_t, 1, 0> {
	PYPP_CONSTEXPR explicit Merger2OnHICANN(uintmax_t const val = 0) : rant_t(val) {}

	typedef MergerProxy<
		Merger1OnHICANN,
		Merger1OnHICANN> inputs_t;

	inputs_t inputs() const
	{
		return inputs_t(
			Merger1OnHICANN(value()*2  ),
			Merger1OnHICANN(value()*2+1));
	}
};

} // v2
} // hicann
} // halco

namespace std {
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::Merger2OnHICANN)
} // std
