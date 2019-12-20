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
	AuxPwrGlobal,
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

TYPED_TEST(GlobalCoordinateTest, explicit_cast)
{
	// use some wafer != 0
	typedef typename TypeParam::local_type lt;
	TypeParam coord(lt(), Wafer(1));
	ASSERT_EQ(static_cast<size_t>(coord), coord.toEnum().value());

	ASSERT_NE(
	    static_cast<size_t>(TypeParam(lt(), Wafer(0))),
	    static_cast<size_t>(TypeParam(lt(), Wafer(1))));
}
