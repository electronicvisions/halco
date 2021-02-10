#include <gtest/gtest.h>

#include "halco/hicann/v2/coordinates.h"

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

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

TYPED_TEST_SUITE(MixedGlobalCoordinateTest, CoordinateGlobalTypes);

template<typename T>
class MixedOnWaferCoordinateTest : public ::testing::Test
{};

typedef ::testing::Types<
    DNCMergerOnWafer,
    NeuronBlockOnWafer,
    NeuronOnWafer,
    SynapseOnWafer,
    SendingRepeaterOnWafer>
    CoordinateOnWaferTypes;

TYPED_TEST_SUITE(MixedOnWaferCoordinateTest, CoordinateOnWaferTypes);

template<typename T>
class MixedOnHICANNCoordinateTest : public ::testing::Test
{};

typedef ::testing::Types<
	SynapticInputOnHICANN
> CoordinateOnHICANNTypes;

TYPED_TEST_SUITE(MixedOnHICANNCoordinateTest, CoordinateOnHICANNTypes);

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

TYPED_TEST(MixedOnHICANNCoordinateTest, CanBeSplitted) {
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

TYPED_TEST(MixedOnHICANNCoordinateTest, ProvidesTypedefs) {
	TypeParam mixed(typename TypeParam::local_type(), typename TypeParam::mixed_in_type());
}

TYPED_TEST(MixedGlobalCoordinateTest, DoesNotIgnoreMixedInTypeInComparison) {
	TypeParam a(typename TypeParam::local_type(), typename TypeParam::mixed_in_type(Enum(2)));
	TypeParam b(typename TypeParam::local_type(), typename TypeParam::mixed_in_type(Enum(3)));
	ASSERT_NE(a, b);
}

TEST(SynapseOnWafer, Cerealization)
{
	SynapseOnWafer obj1(Enum(512 * 224 * 2));
	SynapseOnWafer obj2;

	std::ostringstream ostream;
	{
		boost::archive::text_oarchive oa(ostream);
		oa& obj1;
	}

	std::istringstream istream(ostream.str());
	{
		boost::archive::text_iarchive ia(istream);
		ia& obj2;
	}
	EXPECT_EQ(obj2, obj1);
}
