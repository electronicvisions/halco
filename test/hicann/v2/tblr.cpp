#include <gtest/gtest.h>
#include <type_traits>

#include "halco/hicann/v2/coordinates.h"

using namespace halco::common;
using namespace halco::hicann::v2;

template<typename T>
class TopBottomCoordinateTest : public ::testing::Test
{};

typedef ::testing::Types<
	NeuronOnHICANN,
	NeuronOnNeuronBlock,
	NeuronOnQuad,
	QuadrantOnHICANN,
	SynapseDriverOnHICANN,
	SynapseSwitchRowOnHICANN,
	VRepeaterOnHICANN,
	FGBlockOnHICANN
> CoordinateTopBottomTypes;

TYPED_TEST_CASE(TopBottomCoordinateTest, CoordinateTopBottomTypes);

TYPED_TEST(TopBottomCoordinateTest, WorksForExtremeValues) {
	TypeParam top{Enum{TypeParam::enum_type::min}};
	ASSERT_TRUE(top.isTop());
	ASSERT_FALSE(top.isBottom());

	TypeParam bot{Enum{TypeParam::enum_type::max}};
	ASSERT_FALSE(bot.isTop());
	ASSERT_TRUE(bot.isBottom());
}

template<typename T>
class LeftRightCoordinateTest : public ::testing::Test
{};

typedef ::testing::Types<
	HRepeaterOnHICANN,
	QuadrantOnHICANN,
	SynapseDriverOnHICANN,
	SynapseSwitchRowOnHICANN,
	FGBlockOnHICANN
> CoordinateLeftRightTypes;

TYPED_TEST_CASE(LeftRightCoordinateTest, CoordinateLeftRightTypes);

TEST(LeftRightCoordinateTest, VLineOnHICANNWorksForExtremeValues) {
	VLineOnHICANN left{VLineOnHICANN::min};
	ASSERT_TRUE(left.isLeft());
	ASSERT_FALSE(left.isRight());

	VLineOnHICANN right{VLineOnHICANN::max};
	ASSERT_FALSE(right.isLeft());
	ASSERT_TRUE(right.isRight());
}

TYPED_TEST(LeftRightCoordinateTest, WorksForExtremeValues) {
	// In general, coordinates follow left-to-right, top-to-bottom schema, but
	// SynapseDriverOnHICANN with smallest enum is on the right.
	auto min = TypeParam::enum_type::min +
	           (std::is_same<TypeParam, SynapseDriverOnHICANN>::value ? 1 : 0);
	TypeParam left{Enum{min}};
	ASSERT_TRUE(left.isLeft());
	ASSERT_FALSE(left.isRight());

	TypeParam right{Enum{TypeParam::enum_type::max}};
	ASSERT_FALSE(right.isLeft());
	ASSERT_TRUE(right.isRight());
}
