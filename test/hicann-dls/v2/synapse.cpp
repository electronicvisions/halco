#include <gtest/gtest.h>

#include "halco/hicann-dls/v2/coordinates.h"

using namespace halco::common;
using namespace halco::hicann_dls::v2;

TEST(SynapseDriverOnDLS, RespectsBounds)
{
	EXPECT_ANY_THROW(SynapseDriverOnDLS(32));
	EXPECT_NO_THROW(SynapseDriverOnDLS(31));
}

TEST(SynapseDriverBlockOnDLS, RespectsBounds)
{
	EXPECT_ANY_THROW(SynapseDriverBlockOnDLS(1));
	EXPECT_NO_THROW(SynapseDriverBlockOnDLS(0));
}

TEST(SynapseBlockOnDLS, RespectsBounds)
{
	EXPECT_ANY_THROW(SynapseBlockOnDLS(X(2), Y(32)));
	EXPECT_ANY_THROW(SynapseBlockOnDLS(X(8), Y(31)));
	EXPECT_NO_THROW(SynapseBlockOnDLS(X(7), Y(31)));
}

TEST(SynapseBlockOnDLS, HasId)
{
	EXPECT_EQ(9, SynapseBlockOnDLS(X(1), Y(1)).id());
	EXPECT_EQ(31, SynapseBlockOnDLS(X(7), Y(3)).id());
	EXPECT_NE(5, SynapseBlockOnDLS(X(7), Y(1)).id());
}

TEST(SynapseBlockOnDLS, toSynapseDriverOnDLS)
{
	EXPECT_EQ(SynapseDriverOnDLS(0), SynapseBlockOnDLS(Enum(7)).toSynapseDriverOnDLS());
	EXPECT_EQ(SynapseDriverOnDLS(1), SynapseBlockOnDLS(Enum(8)).toSynapseDriverOnDLS());
	EXPECT_EQ(SynapseDriverOnDLS(3), SynapseBlockOnDLS(X(4), Y(3)).toSynapseDriverOnDLS());
	EXPECT_NE(SynapseDriverOnDLS(3), SynapseBlockOnDLS(Enum(7)).toSynapseDriverOnDLS());
}

TEST(SynapseOnSynapseBlock, RespectsBounds)
{
	EXPECT_ANY_THROW(SynapseOnSynapseBlock(4));
	EXPECT_NO_THROW(SynapseOnSynapseBlock(3));
}

TEST(SynapseOnDLS, RespectsBounds)
{
	EXPECT_ANY_THROW(SynapseOnDLS(NeuronOnDLS(0), SynapseDriverOnDLS(32)));
	EXPECT_NO_THROW(SynapseOnDLS(NeuronOnDLS(0), SynapseDriverOnDLS(31)));
	EXPECT_ANY_THROW(SynapseOnDLS(NeuronOnDLS(32), SynapseDriverOnDLS(5)));
	EXPECT_NO_THROW(SynapseOnDLS(NeuronOnDLS(31), SynapseDriverOnDLS(7)));
}

TEST(SynapseOnDLS, HasId)
{
	EXPECT_EQ(33, SynapseOnDLS(NeuronOnDLS(1), SynapseDriverOnDLS(1)).id());
	EXPECT_EQ(127, SynapseOnDLS(NeuronOnDLS(31), SynapseDriverOnDLS(3)).id());
	EXPECT_NE(0, SynapseOnDLS(NeuronOnDLS(1), SynapseDriverOnDLS(1)).id());
}

TEST(SynapseOnDLS, toNeuronOnDLS)
{
	EXPECT_EQ(NeuronOnDLS(4), SynapseOnDLS(Enum(4)).toNeuronOnDLS());
	EXPECT_EQ(NeuronOnDLS(0), SynapseOnDLS(Enum(32)).toNeuronOnDLS());
	EXPECT_NE(NeuronOnDLS(2), SynapseOnDLS(Enum(4)).toNeuronOnDLS());
}

TEST(SynapseOnDLS, toSynapseDriverOnDLS)
{
	EXPECT_EQ(SynapseDriverOnDLS(0), SynapseOnDLS(Enum(4)).toSynapseDriverOnDLS());
	EXPECT_EQ(SynapseDriverOnDLS(2), SynapseOnDLS(Enum(64)).toSynapseDriverOnDLS());
	EXPECT_NE(SynapseDriverOnDLS(1), SynapseOnDLS(Enum(0)).toSynapseDriverOnDLS());
}

TEST(SynapseOnDLS, toSynapseBlockOnDLS)
{
	EXPECT_EQ(
		SynapseBlockOnDLS(X(2), Y(6)),
		SynapseOnDLS(NeuronOnDLS(10), SynapseDriverOnDLS(6)).toSynapseBlockOnDLS());
	EXPECT_EQ(
		SynapseBlockOnDLS(X(2), Y(7)),
		SynapseOnDLS(NeuronOnDLS(11), SynapseDriverOnDLS(7)).toSynapseBlockOnDLS());
	EXPECT_NE(
		SynapseBlockOnDLS(X(1), Y(10)),
		SynapseOnDLS(NeuronOnDLS(10), SynapseDriverOnDLS(6)).toSynapseBlockOnDLS());
}

TEST(SynapseOnDLS, toSynapseOnSynapseBlock)
{
	EXPECT_EQ(SynapseOnSynapseBlock(0), SynapseOnDLS(Enum(4)).toSynapseOnSynapseBlock());
	EXPECT_EQ(SynapseOnSynapseBlock(3), SynapseOnDLS(Enum(3)).toSynapseOnSynapseBlock());
	EXPECT_EQ(SynapseOnSynapseBlock(0), SynapseOnDLS(Enum(64)).toSynapseOnSynapseBlock());
	EXPECT_NE(SynapseOnSynapseBlock(0), SynapseOnDLS(Enum(1)).toSynapseOnSynapseBlock());
}

TEST(SynapseOnDLS, toColumnCorrelationSwitchOnDLS)
{
	EXPECT_EQ(
		ColumnCorrelationSwitchOnDLS(4), SynapseOnDLS(Enum(4)).toColumnCorrelationSwitchOnDLS());
	EXPECT_NE(
		ColumnCorrelationSwitchOnDLS(2), SynapseOnDLS(Enum(4)).toColumnCorrelationSwitchOnDLS());
}

TEST(SynapseOnDLS, toColumnCurrentSwitchOnDLS)
{
	EXPECT_EQ(ColumnCurrentSwitchOnDLS(4), SynapseOnDLS(Enum(4)).toColumnCurrentSwitchOnDLS());
	EXPECT_NE(ColumnCurrentSwitchOnDLS(2), SynapseOnDLS(Enum(4)).toColumnCurrentSwitchOnDLS());
}

TEST(ColumnBlockOnDLS, RespectsBounds)
{
	EXPECT_ANY_THROW(ColumnBlockOnDLS(8));
	EXPECT_NO_THROW(ColumnBlockOnDLS(7));
}

TEST(ColumnCorrelationSwitchOnColumnBlock, RespectsBounds)
{
	EXPECT_ANY_THROW(ColumnCorrelationSwitchOnColumnBlock(4));
	EXPECT_NO_THROW(ColumnCorrelationSwitchOnColumnBlock(3));
}

TEST(ColumnCorrelationSwitchOnColumnBlock, toSynapseOnColumnBlock)
{
	EXPECT_EQ(
		SynapseOnSynapseBlock(3),
		ColumnCorrelationSwitchOnColumnBlock(Enum(3)).toSynapseOnSynapseBlock());
	EXPECT_NE(
		SynapseOnSynapseBlock(2),
		ColumnCorrelationSwitchOnColumnBlock(Enum(3)).toSynapseOnSynapseBlock());
}

TEST(ColumnCorrelationSwitchOnDLS, RespectsBounds)
{
	EXPECT_ANY_THROW(ColumnCorrelationSwitchOnDLS(32));
	EXPECT_NO_THROW(ColumnCorrelationSwitchOnDLS(31));
}

TEST(ColumnCorrelationSwitchOnDLS, toColumnCorrelationSwitchOnColumnBlock)
{
	EXPECT_EQ(
		ColumnCorrelationSwitchOnColumnBlock(3),
		ColumnCorrelationSwitchOnDLS(Enum(3)).toColumnCorrelationSwitchOnColumnBlock());
	EXPECT_EQ(
		ColumnCorrelationSwitchOnColumnBlock(0),
		ColumnCorrelationSwitchOnDLS(Enum(4)).toColumnCorrelationSwitchOnColumnBlock());
	EXPECT_NE(
		ColumnCorrelationSwitchOnColumnBlock(0),
		ColumnCorrelationSwitchOnDLS(Enum(5)).toColumnCorrelationSwitchOnColumnBlock());
}

TEST(ColumnCorrelationSwitchOnDLS, toColumnBlockOnDLS)
{
	EXPECT_EQ(ColumnBlockOnDLS(0), ColumnCorrelationSwitchOnDLS(Enum(3)).toColumnBlockOnDLS());
	EXPECT_EQ(ColumnBlockOnDLS(1), ColumnCorrelationSwitchOnDLS(Enum(4)).toColumnBlockOnDLS());
	EXPECT_NE(ColumnBlockOnDLS(1), ColumnCorrelationSwitchOnDLS(Enum(0)).toColumnBlockOnDLS());
}

TEST(ColumnCorrelationSwitchOnDLS, toColumnCurrentSwitchOnDLS)
{
	EXPECT_EQ(
		ColumnCurrentSwitchOnDLS(31),
		ColumnCorrelationSwitchOnDLS(31).toColumnCurrentSwitchOnDLS());
	EXPECT_NE(
		ColumnCurrentSwitchOnDLS(21),
		ColumnCorrelationSwitchOnDLS(31).toColumnCurrentSwitchOnDLS());
}

TEST(ColumnCorrelationSwitchOnDLS, toNeuronOnDLS)
{
	EXPECT_EQ(NeuronOnDLS(31), ColumnCorrelationSwitchOnDLS(31).toNeuronOnDLS());
	EXPECT_NE(NeuronOnDLS(21), ColumnCorrelationSwitchOnDLS(31).toNeuronOnDLS());
}

TEST(ColumnCurrentSwitchOnColumnBlock, RespectsBounds)
{
	EXPECT_ANY_THROW(ColumnCurrentSwitchOnColumnBlock(4));
	EXPECT_NO_THROW(ColumnCurrentSwitchOnColumnBlock(3));
}

TEST(ColumnCurrentSwitchOnColumnBlock, toSynapseOnSynapseBlock)
{
	EXPECT_EQ(
		SynapseOnSynapseBlock(3),
		ColumnCurrentSwitchOnColumnBlock(Enum(3)).toSynapseOnSynapseBlock());
	EXPECT_NE(
		SynapseOnSynapseBlock(2),
		ColumnCurrentSwitchOnColumnBlock(Enum(3)).toSynapseOnSynapseBlock());
}

TEST(ColumnCurrentSwitchOnDLS, RespectsBounds)
{
	EXPECT_ANY_THROW(ColumnCurrentSwitchOnDLS(32));
	EXPECT_NO_THROW(ColumnCurrentSwitchOnDLS(31));
}

TEST(ColumnCurrentSwitchOnDLS, toColumnCurrentSwitchOnColumnBlock)
{
	EXPECT_EQ(
		ColumnCurrentSwitchOnColumnBlock(3),
		ColumnCurrentSwitchOnDLS(Enum(3)).toColumnCurrentSwitchOnColumnBlock());
	EXPECT_EQ(
		ColumnCurrentSwitchOnColumnBlock(0),
		ColumnCurrentSwitchOnDLS(Enum(4)).toColumnCurrentSwitchOnColumnBlock());
	EXPECT_NE(
		ColumnCurrentSwitchOnColumnBlock(0),
		ColumnCurrentSwitchOnDLS(Enum(5)).toColumnCurrentSwitchOnColumnBlock());
}

TEST(ColumnCurrentSwitchOnDLS, toColumnBlockOnDLS)
{
	EXPECT_EQ(ColumnBlockOnDLS(0), ColumnCurrentSwitchOnDLS(Enum(3)).toColumnBlockOnDLS());
	EXPECT_EQ(ColumnBlockOnDLS(1), ColumnCurrentSwitchOnDLS(Enum(4)).toColumnBlockOnDLS());
	EXPECT_NE(ColumnBlockOnDLS(1), ColumnCurrentSwitchOnDLS(Enum(0)).toColumnBlockOnDLS());
}

TEST(ColumnCurrentSwitchOnDLS, toColumnCorrelationSwitchOnDLS)
{
	EXPECT_EQ(
		ColumnCorrelationSwitchOnDLS(31),
		ColumnCurrentSwitchOnDLS(31).toColumnCorrelationSwitchOnDLS());
	EXPECT_NE(
		ColumnCorrelationSwitchOnDLS(21),
		ColumnCurrentSwitchOnDLS(31).toColumnCorrelationSwitchOnDLS());
}

TEST(ColumnCurrentSwitchOnDLS, toNeuronOnDLS)
{
	EXPECT_EQ(NeuronOnDLS(31), ColumnCurrentSwitchOnDLS(31).toNeuronOnDLS());
	EXPECT_NE(NeuronOnDLS(21), ColumnCurrentSwitchOnDLS(31).toNeuronOnDLS());
}

TEST(CorrelationConfigOnDLS, RespectsBounds)
{
	EXPECT_ANY_THROW(CorrelationConfigOnDLS(1));
	EXPECT_NO_THROW(CorrelationConfigOnDLS(0));
}
