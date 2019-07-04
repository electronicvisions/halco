#include <gtest/gtest.h>

#include "halco/common/iter_all.h"
#include "halco/hicann-dls/vx/coordinates.h"

using namespace halco::common;
using namespace halco::hicann_dls::vx;

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
