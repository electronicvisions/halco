#include <gtest/gtest.h>

#include "halco/hicann/v2/coordinates.h"
#include "halco/common/iter_all.h"

using namespace halco::common;
using namespace halco::hicann::v2;

static_assert(detail::limits<NeuronBlockOnHICANN>::size
              == NeuronBlockOnHICANN::size,
	"NeuronBlockOnHICANN 'size' limit does not match.");
static_assert(detail::limits<NeuronBlockOnHICANN>::min
              == NeuronBlockOnHICANN::min,
	"NeuronBlockOnHICANN 'min' limit does not match.");
static_assert(detail::limits<NeuronBlockOnHICANN>::max
              == NeuronBlockOnHICANN::max,
	"NeuronBlockOnHICANN 'max' limit does not match.");
static_assert(detail::limits<NeuronBlockOnHICANN>::begin
              == NeuronBlockOnHICANN::begin,
	"NeuronBlockOnHICANN 'begin' limit does not match.");
static_assert(detail::limits<NeuronBlockOnHICANN>::end
              == NeuronBlockOnHICANN::end,
	"NeuronBlockOnHICANN 'end' limit does not match.");

static_assert(detail::limits<NeuronOnHICANN>::size
              == NeuronOnHICANN::enum_type::size,
	"NeuronOnHICANN 'size' limit does not match.");
static_assert(detail::limits<NeuronOnHICANN>::min
              == NeuronOnHICANN::enum_type::min,
	"NeuronOnHICANN 'min' limit does not match.");
static_assert(detail::limits<NeuronOnHICANN>::max
              == NeuronOnHICANN::enum_type::max,
	"NeuronOnHICANN 'max' limit does not match.");
static_assert(detail::limits<NeuronOnHICANN>::begin
              == NeuronOnHICANN::enum_type::begin,
	"NeuronOnHICANN 'begin' limit does not match.");
static_assert(detail::limits<NeuronOnHICANN>::end
              == NeuronOnHICANN::enum_type::end,
	"NeuronOnHICANN 'end' limit does not match.");

TEST(CoordinateTraits, FromNumber) {
	NeuronOnHICANN nrn;
	detail::from_number(nrn, 123);
	EXPECT_EQ(NeuronOnHICANN(Enum(123)), nrn);
	NeuronBlockOnHICANN nb;
	detail::from_number(nb, 2);
	EXPECT_EQ(NeuronBlockOnHICANN(2), nb);
}

TEST(CoordinateTraits, ToNumber) {
	EXPECT_EQ(123,
	          detail::to_number(NeuronOnHICANN(Enum(123))));
	EXPECT_EQ(0,
	          detail::to_number(NeuronOnHICANN(Enum(0))));
}
