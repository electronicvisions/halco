#include <gtest/gtest.h>

#include "halco/hicann-dls/v2/coordinates.h"

using namespace halco::common;
using namespace halco::hicann_dls::v2;

TEST(SynapseDriverOnDLS, RespectsBounds)
{
	EXPECT_ANY_THROW(SynapseDriverOnDLS(32));
	EXPECT_NO_THROW(SynapseDriverOnDLS(31));
}

TEST(SynapseDriverOnDLS, toSynapseRowOnDLS)
{
	EXPECT_EQ(SynapseRowOnDLS(0), SynapseDriverOnDLS(0).toSynapseRowOnDLS());
	EXPECT_EQ(SynapseRowOnDLS(31), SynapseDriverOnDLS(31).toSynapseRowOnDLS());
	EXPECT_NE(SynapseRowOnDLS(5), SynapseDriverOnDLS(10).toSynapseRowOnDLS());
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

TEST(SynapseColumnOnDLS, RespectsBounds)
{
	EXPECT_ANY_THROW(SynapseColumnOnDLS(32));
	EXPECT_NO_THROW(SynapseColumnOnDLS(31));
	EXPECT_NO_THROW(SynapseColumnOnDLS(0));
}

TEST(SynapseColumnOnDLS, toNeuronOnDLS)
{
	for(size_t index = 0; index < NeuronOnDLS::size; index++) {
		EXPECT_EQ(SynapseColumnOnDLS(index).toNeuronOnDLS(), NeuronOnDLS(index));
	}
}

TEST(SynapseRowOnDLS, RespectsBounds)
{
	EXPECT_ANY_THROW(SynapseRowOnDLS(32));
	EXPECT_NO_THROW(SynapseRowOnDLS(31));
	EXPECT_NO_THROW(SynapseRowOnDLS(0));
}

TEST(SynapseRowOnDLS, toSynapseDriverOnDLS)
{
	for(size_t index = 0; index < SynapseDriverOnDLS::size; index++) {
		EXPECT_EQ(SynapseRowOnDLS(index).toSynapseDriverOnDLS(), SynapseDriverOnDLS(index));
	}
}

TEST(SynapseOnDLS, RespectsBounds)
{
	EXPECT_ANY_THROW(SynapseOnDLS(SynapseColumnOnDLS(0), SynapseRowOnDLS(32)));
	EXPECT_NO_THROW(SynapseOnDLS(SynapseColumnOnDLS(0), SynapseRowOnDLS(31)));
	EXPECT_ANY_THROW(SynapseOnDLS(SynapseColumnOnDLS(32), SynapseRowOnDLS(5)));
	EXPECT_NO_THROW(SynapseOnDLS(SynapseColumnOnDLS(31), SynapseRowOnDLS(7)));
}

TEST(SynapseOnDLS, HasId)
{
	EXPECT_EQ(33, SynapseOnDLS(SynapseColumnOnDLS(1), SynapseRowOnDLS(1)).id());
	EXPECT_EQ(127, SynapseOnDLS(SynapseColumnOnDLS(31), SynapseRowOnDLS(3)).id());
	EXPECT_NE(0, SynapseOnDLS(SynapseColumnOnDLS(1), SynapseRowOnDLS(1)).id());
}

TEST(SynapseOnDLS, toSynapseRowOnDLS)
{
	EXPECT_EQ(SynapseRowOnDLS(0), SynapseOnDLS(Enum(5)).toSynapseRowOnDLS());
	EXPECT_EQ(SynapseRowOnDLS(1), SynapseOnDLS(Enum(32)).toSynapseRowOnDLS());
	EXPECT_NE(SynapseRowOnDLS(0), SynapseOnDLS(Enum(64)).toSynapseRowOnDLS());
}

TEST(SynapseOnDLS, toSynapseColumnOnDLS)
{
	EXPECT_EQ(SynapseColumnOnDLS(4), SynapseOnDLS(Enum(4)).toSynapseColumnOnDLS());
	EXPECT_EQ(SynapseColumnOnDLS(0), SynapseOnDLS(Enum(32)).toSynapseColumnOnDLS());
	EXPECT_NE(SynapseColumnOnDLS(1), SynapseOnDLS(Enum(2)).toSynapseColumnOnDLS());
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
		SynapseOnDLS(SynapseColumnOnDLS(10), SynapseRowOnDLS(6)).toSynapseBlockOnDLS());
	EXPECT_EQ(
		SynapseBlockOnDLS(X(2), Y(7)),
		SynapseOnDLS(SynapseColumnOnDLS(11), SynapseRowOnDLS(7)).toSynapseBlockOnDLS());
	EXPECT_NE(
		SynapseBlockOnDLS(X(1), Y(10)),
		SynapseOnDLS(SynapseColumnOnDLS(10), SynapseRowOnDLS(6)).toSynapseBlockOnDLS());
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

TEST(ColumnCorrelationSwitchOnColumnCorrelationBlock, RespectsBounds)
{
	EXPECT_ANY_THROW(ColumnCorrelationSwitchOnColumnCorrelationBlock(4));
	EXPECT_NO_THROW(ColumnCorrelationSwitchOnColumnCorrelationBlock(3));
}

TEST(ColumnCorrelationSwitchOnColumnCorrelationBlock, toSynapseOnColumnBlock)
{
	EXPECT_EQ(
	    SynapseOnSynapseBlock(3),
	    ColumnCorrelationSwitchOnColumnCorrelationBlock(Enum(3)).toSynapseOnSynapseBlock());
	EXPECT_NE(
	    SynapseOnSynapseBlock(2),
	    ColumnCorrelationSwitchOnColumnCorrelationBlock(Enum(3)).toSynapseOnSynapseBlock());
}

TEST(ColumnCorrelationSwitchOnDLS, RespectsBounds)
{
	EXPECT_ANY_THROW(ColumnCorrelationSwitchOnDLS(32));
	EXPECT_NO_THROW(ColumnCorrelationSwitchOnDLS(31));
}

TEST(ColumnCorrelationSwitchOnDLS, toColumnCorrelationSwitchOnColumnCorrelationBlock)
{
	EXPECT_EQ(
	    ColumnCorrelationSwitchOnColumnCorrelationBlock(3),
	    ColumnCorrelationSwitchOnDLS(Enum(3)).toColumnCorrelationSwitchOnColumnCorrelationBlock());
	EXPECT_EQ(
	    ColumnCorrelationSwitchOnColumnCorrelationBlock(0),
	    ColumnCorrelationSwitchOnDLS(Enum(4)).toColumnCorrelationSwitchOnColumnCorrelationBlock());
	EXPECT_NE(
	    ColumnCorrelationSwitchOnColumnCorrelationBlock(0),
	    ColumnCorrelationSwitchOnDLS(Enum(5)).toColumnCorrelationSwitchOnColumnCorrelationBlock());
}

TEST(ColumnCorrelationSwitchOnDLS, toColumnCorrelationBlockOnDLS)
{
	EXPECT_EQ(
	    ColumnCorrelationBlockOnDLS(0),
	    ColumnCorrelationSwitchOnDLS(Enum(3)).toColumnCorrelationBlockOnDLS());
	EXPECT_EQ(
	    ColumnCorrelationBlockOnDLS(1),
	    ColumnCorrelationSwitchOnDLS(Enum(4)).toColumnCorrelationBlockOnDLS());
	EXPECT_NE(
	    ColumnCorrelationBlockOnDLS(1),
	    ColumnCorrelationSwitchOnDLS(Enum(0)).toColumnCorrelationBlockOnDLS());
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

TEST(ColumnCurrentSwitchOnColumnCurrentBlock, RespectsBounds)
{
	EXPECT_ANY_THROW(ColumnCurrentSwitchOnColumnCurrentBlock(4));
	EXPECT_NO_THROW(ColumnCurrentSwitchOnColumnCurrentBlock(3));
}

TEST(ColumnCurrentSwitchOnColumnCurrentBlock, toSynapseOnSynapseBlock)
{
	EXPECT_EQ(
	    SynapseOnSynapseBlock(3),
	    ColumnCurrentSwitchOnColumnCurrentBlock(Enum(3)).toSynapseOnSynapseBlock());
	EXPECT_NE(
	    SynapseOnSynapseBlock(2),
	    ColumnCurrentSwitchOnColumnCurrentBlock(Enum(3)).toSynapseOnSynapseBlock());
}

TEST(ColumnCurrentSwitchOnDLS, RespectsBounds)
{
	EXPECT_ANY_THROW(ColumnCurrentSwitchOnDLS(32));
	EXPECT_NO_THROW(ColumnCurrentSwitchOnDLS(31));
}

TEST(ColumnCurrentSwitchOnDLS, toColumnCurrentSwitchOnColumnCurrentBlock)
{
	EXPECT_EQ(
	    ColumnCurrentSwitchOnColumnCurrentBlock(3),
	    ColumnCurrentSwitchOnDLS(Enum(3)).toColumnCurrentSwitchOnColumnCurrentBlock());
	EXPECT_EQ(
	    ColumnCurrentSwitchOnColumnCurrentBlock(0),
	    ColumnCurrentSwitchOnDLS(Enum(4)).toColumnCurrentSwitchOnColumnCurrentBlock());
	EXPECT_NE(
	    ColumnCurrentSwitchOnColumnCurrentBlock(0),
	    ColumnCurrentSwitchOnDLS(Enum(5)).toColumnCurrentSwitchOnColumnCurrentBlock());
}

TEST(ColumnCurrentSwitchOnDLS, toColumnCurrentBlockOnDLS)
{
	EXPECT_EQ(
	    ColumnCurrentBlockOnDLS(0), ColumnCurrentSwitchOnDLS(Enum(3)).toColumnCurrentBlockOnDLS());
	EXPECT_EQ(
	    ColumnCurrentBlockOnDLS(1), ColumnCurrentSwitchOnDLS(Enum(4)).toColumnCurrentBlockOnDLS());
	EXPECT_NE(
	    ColumnCurrentBlockOnDLS(1), ColumnCurrentSwitchOnDLS(Enum(0)).toColumnCurrentBlockOnDLS());
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
