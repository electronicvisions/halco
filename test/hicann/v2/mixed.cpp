#include <gtest/gtest.h>

#include "halco/hicann/v2/coordinates.h"

using namespace halco::common;
using namespace halco::hicann::v2;

template<typename T>
class MixedGlobalCoordinateTest : public ::testing::Test
{};

typedef ::testing::Types<
	DNCGlobal,
	FPGAGlobal,
	HICANNGlobal,
	NeuronBlockGlobal,
	NeuronGlobal
> CoordinateGlobalTypes;

TYPED_TEST_CASE(MixedGlobalCoordinateTest, CoordinateGlobalTypes);

template<typename T>
class MixedOnWaferCoordinateTest : public ::testing::Test
{};

typedef ::testing::Types<
	DNCMergerOnWafer,
	NeuronBlockOnWafer,
	NeuronOnWafer,
	SynapseOnWafer
> CoordinateOnWaferTypes;

TYPED_TEST_CASE(MixedOnWaferCoordinateTest, CoordinateOnWaferTypes);

TEST(MixedCoordinateTest, HICANNGlobalCanBeSplitted) {
	HICANNGlobal mixed;

	Wafer wafer;
	HICANNOnWafer hicann;

	std::tie(wafer, hicann) = mixed.split();
	ASSERT_EQ(mixed.toWafer(), wafer);
	ASSERT_EQ(mixed.toHICANNOnWafer(), hicann);
}

TYPED_TEST(MixedGlobalCoordinateTest, CanBeSplitted) {
	TypeParam mixed;
	auto pair = mixed.split();
	TypeParam reconstructed{pair.second, pair.first};
	ASSERT_EQ(mixed, reconstructed);
}

TYPED_TEST(MixedOnWaferCoordinateTest, CanBeSplitted) {
	TypeParam mixed;
	auto pair = mixed.split();
	TypeParam reconstructed{pair.second, pair.first};
	ASSERT_EQ(mixed, reconstructed);
}

TYPED_TEST(MixedGlobalCoordinateTest, ProvidesTypedefs) {
	TypeParam mixed(typename TypeParam::local_type(), typename TypeParam::mixed_in_type());
}

TYPED_TEST(MixedOnWaferCoordinateTest, ProvidesTypedefs) {
	TypeParam mixed(typename TypeParam::local_type(), typename TypeParam::mixed_in_type());
}

TYPED_TEST(MixedGlobalCoordinateTest, DoesNotIgnoreMixedInTypeInComparison) {
	TypeParam a(typename TypeParam::local_type(), typename TypeParam::mixed_in_type(Enum(2)));
	TypeParam b(typename TypeParam::local_type(), typename TypeParam::mixed_in_type(Enum(3)));
	ASSERT_NE(a, b);
}
