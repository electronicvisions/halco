#pragma once

extern "C" {
#include <stdint.h>
}

#include "halco/hicann/v2/mergerproxy.h"
#include "halco/hicann/v2/merger2onhicann.h"

namespace halco {
namespace hicann {
namespace v2 {

struct Merger3OnHICANN : public common::detail::RantWrapper<Merger3OnHICANN, uint_fast16_t, 0, 0> {
	PYPP_CONSTEXPR explicit Merger3OnHICANN(uintmax_t const val = 0) : rant_t(val) {}

	typedef MergerProxy<
		Merger2OnHICANN,
		Merger2OnHICANN> inputs_t;

	inputs_t inputs() const
	{
		return inputs_t(Merger2OnHICANN(0), Merger2OnHICANN(1));
	}
};

} // v2
} // hicann
} // halco

namespace std {
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::Merger3OnHICANN)
} // std
