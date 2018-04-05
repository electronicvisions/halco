#include <algorithm>
#include <gtest/gtest.h>

#include "halco/hicann/v2/coordinates.h"

using namespace halco::common;
using namespace halco::hicann::v2;

template<typename T>
class GlobalCoordinateTest : public ::testing::Test
{};

// clang-format off
typedef ::testing::Types<
	DNCGlobal,
	FPGAGlobal,
	ANANASGlobal,
	HICANNGlobal,
	NeuronBlockGlobal,
	NeuronGlobal,
	TriggerGlobal
> CoordinateGlobalTypes;
// clang-format on

TYPED_TEST_CASE(GlobalCoordinateTest, CoordinateGlobalTypes);

TYPED_TEST(GlobalCoordinateTest, toWafer) {
	TypeParam coord;
	EXPECT_EQ(Wafer(0), coord.toWafer());
}
