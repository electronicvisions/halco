#include <gtest/gtest.h>

#include "halco/common/iter_all.h"
#include "halco/hicann/v2/coordinates.h"

using namespace halco::common;
using namespace halco::hicann::v2;

template <typename T>
class IterableCoordinateTestAtoM : public ::testing::Test
{};
template <typename T>
class IterableCoordinateTestNtoZ : public ::testing::Test
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
    Merger2OnHICANN>
    CoordinateIterableTypesAtoM;
TYPED_TEST_CASE(IterableCoordinateTestAtoM, CoordinateIterableTypesAtoM);

typedef ::testing::Types<
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
    SocketOnWIO,
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
    VRepeaterOnHICANN,
    WIOOnWafer>
    CoordinateIterableTypesNtoZ;
TYPED_TEST_CASE(IterableCoordinateTestNtoZ, CoordinateIterableTypesNtoZ);

#define COMMON_FIXTURE_NAME IterableCoordinateTestAtoM
#include "HALCO_ITERABLE.cxx"
#undef COMMON_FIXTURE_NAME
#define COMMON_FIXTURE_NAME IterableCoordinateTestNtoZ
#include "HALCO_ITERABLE.cxx"
#undef COMMON_FIXTURE_NAME

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
