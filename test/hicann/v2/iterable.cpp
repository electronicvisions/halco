#include <gtest/gtest.h>

#include "halco/common/iter_all.h"
#include "halco/hicann/v2/coordinates.h"

using namespace halco::common;
using namespace halco::hicann::v2;

template<typename T>
class IterableCoordinateTest : public ::testing::Test
{};

typedef ::testing::Types<
    AnalogOnHICANN,
    BackgroundGeneratorOnHICANN,
    ChannelOnADC,
    CrossbarSwitchOnHICANN,
    CrossbarSwitchOnCrossbarSwitchRow,
    DNCMergerOnHICANN,
    DNCMergerOnWafer,
    DNCOnFPGA,
    DNCOnWafer,
    Direction,
    FGBlockOnHICANN,
    FGCellOnFGBlock,
    FGRowOnFGBlock,
    FPGAOnWafer,
    GbitLinkOnHICANN,
    HICANNOnDNC,
    HighspeedLinkOnDNC,
    HICANNOnWafer,
    HLineOnHICANN,
    HRepeaterOnHICANN,
    Merger0OnHICANN,
    Merger1OnHICANN,
    Merger2OnHICANN,
    NeuronBlockOnHICANN,
    NeuronBlockOnWafer,
    NeuronOnFGBlock,
    NeuronOnHICANN,
    NeuronOnNeuronBlock,
    NeuronOnQuad,
    Orientation,
    Parity,
    QuadOnHICANN,
    QuadrantOnHICANN,
    RepeaterBlockOnHICANN,
    RowOnSynapseDriver,
    SendingRepeaterOnHICANN,
    SideHorizontal,
    SideVertical,
    SynapseColumnOnHICANN,
    SynapseDriverOnHICANN,
    SynapseDriverOnQuadrant,
    SynapseOnHICANN,
    // Note: Tested in separation below (full iteration takes too long)
    // SynapseOnWafer,
    SynapseRowOnHICANN,
    SynapseRowOnArray,
    SynapseSwitchOnHICANN,
    SynapseSwitchOnSynapseSwitchRow,
    SynapseSwitchRowOnHICANN,
    TriggerOnADC,
    VLineOnHICANN,
    VRepeaterOnHICANN>
    CoordinateIterableTypes;

TYPED_TEST_CASE(IterableCoordinateTest, CoordinateIterableTypes);

TYPED_TEST(IterableCoordinateTest, iter_all) {
	size_t count = 0;
	for (auto c : iter_all<TypeParam>()) {
		++count;
		static_cast<void>(c);
	}
	EXPECT_LE(1, count);
}

TEST(Merger3OnHICANN, iter_all) {
	size_t count = 0;
	for (auto c : iter_all<Merger3OnHICANN>()) {
		++count;
		static_cast<void>(c);
	}
	EXPECT_EQ(1, count);
}

TEST(DNCMergerOnWafer, iter_all) {
	EXPECT_EQ(HICANNOnWafer::enum_type::size * DNCMergerOnHICANN::size,
	          DNCMergerOnWafer::enum_type::size);
	size_t count = 0;
	for (auto c : iter_all<DNCMergerOnWafer>()) {
		EXPECT_EQ(count, c.toEnum());
		EXPECT_EQ(count % DNCMergerOnHICANN::size, c.toDNCMergerOnHICANN().toEnum());
		EXPECT_EQ(count / DNCMergerOnHICANN::size, c.toHICANNOnWafer().toEnum());
		EXPECT_EQ(c, DNCMergerOnWafer(Enum(c.toEnum())));
		EXPECT_EQ(c, DNCMergerOnWafer(c.toEnum()));
		++count;
	}
	EXPECT_EQ(count, DNCMergerOnWafer::enum_type::size);
}

TEST(SynapseOnWafer, iter_all) {
	EXPECT_EQ(HICANNOnWafer::enum_type::size * SynapseOnHICANN::size,
	          SynapseOnWafer::enum_type::size);
	auto range = iter_all<SynapseOnWafer>();

	size_t const n_hicanns = 42;
	size_t count = 0;
	for (auto it = range.begin(), eit = range.end(); it != eit; ++it) {
		if (count > n_hicanns * SynapseOnHICANN::size)
			break;
		EXPECT_EQ(count, it->toEnum());
		EXPECT_EQ(count % SynapseOnHICANN::size, it->toSynapseOnHICANN().toEnum());
		EXPECT_EQ(count / SynapseOnHICANN::size, it->toHICANNOnWafer().toEnum());
		++count;
	}

	EXPECT_LT(n_hicanns * SynapseOnHICANN::size, count);
}
