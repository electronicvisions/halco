#include <gtest/gtest.h>

#include "halco/hicann-dls/v2/coordinates.h"

using namespace halco::common;
using namespace halco::hicann_dls::v2;

TEST(CapMemColumnOnDLS, RespectsBounds) {
	EXPECT_ANY_THROW(CapMemColumnOnDLS(33));
	EXPECT_NO_THROW(CapMemColumnOnDLS(32));
}

TEST(CapMemRowOnDLS, RespectsBounds) {
	EXPECT_ANY_THROW(CapMemRowOnDLS(24));
	EXPECT_NO_THROW(CapMemRowOnDLS(23));
}

TEST(CapMemCellOnDLS, RespectsBounds) {
	EXPECT_ANY_THROW(CapMemCellOnDLS(CapMemColumnOnDLS(0), CapMemRowOnDLS(24)));
	EXPECT_ANY_THROW(CapMemCellOnDLS(CapMemColumnOnDLS(33), CapMemRowOnDLS(5)));
	EXPECT_NO_THROW(CapMemCellOnDLS(CapMemColumnOnDLS(32), CapMemRowOnDLS(23)));
	EXPECT_NO_THROW(CapMemCellOnDLS(CapMemColumnOnDLS(0), CapMemRowOnDLS(0)));
	EXPECT_ANY_THROW(CapMemCellOnDLS(Enum(792)));
	EXPECT_NO_THROW(CapMemCellOnDLS(Enum(791)));
}

TEST(CapMemCellOnDLS, HasId) {
	EXPECT_EQ(34, CapMemCellOnDLS(CapMemColumnOnDLS(1), CapMemRowOnDLS(1)).id());
	EXPECT_EQ(131, CapMemCellOnDLS(CapMemColumnOnDLS(32), CapMemRowOnDLS(3)).id());
}

TEST(CapMemCellOnDLS, toCapMemColumnOnDLS) {
	EXPECT_EQ(CapMemColumnOnDLS(0), CapMemCellOnDLS(Enum(0)).toCapMemColumnOnDLS());
	EXPECT_EQ(CapMemColumnOnDLS(32), CapMemCellOnDLS(Enum(32)).toCapMemColumnOnDLS());
	EXPECT_EQ(CapMemColumnOnDLS(0), CapMemCellOnDLS(Enum(33)).toCapMemColumnOnDLS());
}

TEST(CapMemCellOnDLS, toCapMemRowCapMem) {
	EXPECT_EQ(CapMemRowOnDLS(0), CapMemCellOnDLS(Enum(4)).toCapMemRowOnDLS());
	EXPECT_EQ(CapMemRowOnDLS(0), CapMemCellOnDLS(Enum(32)).toCapMemRowOnDLS());
	EXPECT_EQ(CapMemRowOnDLS(1), CapMemCellOnDLS(Enum(33)).toCapMemRowOnDLS());
	EXPECT_EQ(CapMemRowOnDLS(2), CapMemCellOnDLS(Enum(67)).toCapMemRowOnDLS());
}

TEST(CapMemCellOnDLS, isShared) {
	EXPECT_TRUE(CapMemCellOnDLS(Enum(32)).isShared());
	EXPECT_FALSE(CapMemCellOnDLS(Enum(31)).isShared());
	EXPECT_FALSE(CapMemCellOnDLS(Enum(0)).isShared());
}

TEST(CapMemCellOnDLS, toNeuronOnDLS) {
	EXPECT_EQ(NeuronOnDLS(4), CapMemCellOnDLS(Enum(4)).toNeuronOnDLS());
	EXPECT_EQ(NeuronOnDLS(31), CapMemCellOnDLS(Enum(31)).toNeuronOnDLS());
	EXPECT_EQ(NeuronOnDLS(0), CapMemCellOnDLS(Enum(33)).toNeuronOnDLS());
	EXPECT_THROW(CapMemCellOnDLS(Enum(32)).toNeuronOnDLS(), std::overflow_error);
}
