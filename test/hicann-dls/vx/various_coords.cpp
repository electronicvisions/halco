#include <gtest/gtest.h>

#include "halco/common/iter_all.h"
#include "halco/hicann-dls/vx/coordinates.h"

using namespace halco::common;
using namespace halco::hicann_dls::vx;

TEST(CrossbarL2OutputOnDLS, toCrossbarOutputOnDLS)
{
	CrossbarL2OutputOnDLS coord(3);
	EXPECT_EQ(coord.toCrossbarOutputOnDLS(), CrossbarOutputOnDLS(3 + 8));
}

TEST(PPUOnDLS, RespectsBounds)
{
	EXPECT_ANY_THROW(PPUOnDLS(2));
	EXPECT_NO_THROW(PPUOnDLS(1));
}

TEST(PPUMemoryWordOnPPU, RespectsBounds)
{
	EXPECT_ANY_THROW(PPUMemoryWordOnPPU(4096));
	EXPECT_NO_THROW(PPUMemoryWordOnPPU(4095));
}

TEST(PPUMemoryWordOnDLS, RespectsBounds)
{
	EXPECT_ANY_THROW(PPUMemoryWordOnDLS(Enum(8192)));
	EXPECT_NO_THROW(PPUMemoryWordOnDLS(Enum(8191)));
	EXPECT_EQ(PPUMemoryWordOnDLS::size, PPUMemoryWordOnPPU::size * PPUOnDLS::size);
	EXPECT_EQ(PPUMemoryWordOnDLS::min, 0);
	EXPECT_EQ(PPUMemoryWordOnDLS::max, PPUMemoryWordOnPPU::size * PPUOnDLS::size - 1);
}

TEST(PPUMemoryWordOnDLS, Conversion)
{
	PPUMemoryWordOnDLS test_coord(PPUMemoryWordOnPPU(1), PPUOnDLS(1));
	EXPECT_EQ(test_coord, PPUMemoryWordOnDLS(Enum(4097)));
	EXPECT_EQ(test_coord.toPPUMemoryWordOnPPU(), PPUMemoryWordOnPPU(1));
	EXPECT_EQ(test_coord.toPPUOnDLS(), PPUOnDLS(1));
}

TEST(DACChannelOnBoard, toVDDOnBoard)
{
	DACChannelOnBoard channel = DACChannelOnBoard::vdd12_madc;
	EXPECT_NO_THROW(channel.toVDDOnBoard());

	DACChannelOnBoard channel2 = DACChannelOnBoard::v_reset;
	EXPECT_ANY_THROW(channel2.toVDDOnBoard());
}

TEST(VDDOnBoard, toDACChannelOnBoard)
{
	for (auto vdd : iter_all<VDDOnBoard>()) {
		DACChannelOnBoard channel = vdd.toDACChannelOnBoard();
		VDDOnBoard res = channel.toVDDOnBoard();
		EXPECT_EQ(vdd, res);
	}
}

TEST(PhyConfigChipOnDLS, toJTAGPhyRegisterOnDLS)
{
	PhyConfigChipOnDLS phy_config(3);
	EXPECT_EQ(phy_config.toJTAGPhyRegisterOnDLS(), JTAGPhyRegisterOnDLS(3));
}

TEST(CapMemColumnOnCapMemBlock, isShared)
{
	CapMemColumnOnCapMemBlock shared_1(128);
	CapMemColumnOnCapMemBlock shared_2(129);
	EXPECT_TRUE(shared_1.isShared());
	EXPECT_TRUE(shared_2.isShared());

	for (size_t i = 0; i < 128; ++i) {
		CapMemColumnOnCapMemBlock not_shared(i);
		EXPECT_FALSE(not_shared.isShared());
	}
}

TEST(CrossbarNodeOnDLS, Construction)
{
	// valid node
	auto input = CrossbarInputOnDLS(3);
	auto output = CrossbarOutputOnDLS(7);

	auto node = CrossbarNodeOnDLS(output, input);
	EXPECT_EQ(node.toEnum(), Enum(3 * 3 + 1));

	// invalid combination of output and input
	EXPECT_THROW(CrossbarNodeOnDLS(output, CrossbarInputOnDLS(2)), std::domain_error);
}

TEST(PADIBusOnDLS, toCrossbarOutputOnDLS)
{
	auto bus = PADIBusOnDLS(PADIBusOnPADIBusBlock(2), PADIBusBlockOnDLS::bottom);
	EXPECT_EQ(bus.toCrossbarOutputOnDLS(), CrossbarOutputOnDLS(6));
}

TEST(BackgroundSpikeSourceOnDLS, toCrossbarInputOnDLS)
{
	auto source = BackgroundSpikeSourceOnDLS(5);
	EXPECT_EQ(source.toCrossbarInputOnDLS(), CrossbarInputOnDLS(17));
}

TEST(BackgroundSpikeSourceOnDLS, toCrossbarL2OutputOnDLS)
{
	auto source = BackgroundSpikeSourceOnDLS(5);
	EXPECT_EQ(source.toCrossbarL2OutputOnDLS(), CrossbarL2OutputOnDLS(1));
}

TEST(CADCSampleQuadOnSynram, Size)
{
	EXPECT_EQ(
	    CADCSampleQuadOnSynram::size,
	    CADCChannelType::size * CADCReadoutType::size * SynapseQuadOnSynram::size);

	EXPECT_EQ(CADCSampleQuadOnSynram::min, 0);

	EXPECT_EQ(
	    CADCSampleQuadOnSynram::max,
	    CADCChannelType::size * CADCReadoutType::size * SynapseQuadOnSynram::size - 1);

	size_t count = 0;
	for (auto coord : iter_all<CADCSampleQuadOnSynram>()) {
		static_cast<void>(coord);
		count++;
	}
	EXPECT_EQ(count++, CADCSampleQuadOnSynram::size);
}

TEST(CADCSampleQuadOnDLS, Size)
{
	EXPECT_EQ(
	    CADCSampleQuadOnDLS::size, CADCChannelType::size * CADCReadoutType::size *
	                                   SynapseQuadOnSynram::size * SynramOnDLS::size);

	EXPECT_EQ(CADCSampleQuadOnDLS::min, 0);

	EXPECT_EQ(
	    CADCSampleQuadOnDLS::max, CADCChannelType::size * CADCReadoutType::size *
	                                      SynapseQuadOnSynram::size * SynramOnDLS::size -
	                                  1);

	size_t count = 0;
	for (auto coord : iter_all<CADCSampleQuadOnDLS>()) {
		static_cast<void>(coord);
		count++;
	}
	EXPECT_EQ(count++, CADCSampleQuadOnDLS::size);
}

template <typename T>
class CommonVerticalHalfCoordinateTest : public ::testing::Test
{};

typedef ::testing::Types<
    PPUOnDLS,
    CommonSynramConfigOnDLS,
    SynramOnDLS,
    CADCConfigOnDLS,
    CommonSTPConfigOnDLS,
    CommonPADIBusConfigOnDLS,
    PADIEventOnDLS>
    CommonVerticalHalfCoordinateTypes;

TYPED_TEST_CASE(CommonVerticalHalfCoordinateTest, CommonVerticalHalfCoordinateTypes);

TYPED_TEST(CommonVerticalHalfCoordinateTest, TopBottom)
{
	TypeParam const top = TypeParam::top;
	TypeParam const bottom = TypeParam::bottom;

	EXPECT_EQ(top.toEnum(), 0);
	EXPECT_EQ(bottom.toEnum(), 1);
}
