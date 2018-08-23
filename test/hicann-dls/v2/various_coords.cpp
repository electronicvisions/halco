#include <gtest/gtest.h>

#include "halco/common/iter_all.h"
#include "halco/hicann-dls/v2/coordinates.h"

using namespace halco::common;
using namespace halco::hicann_dls::v2;

TEST(NeuronOnDLS, RespectsBounds) {
	EXPECT_ANY_THROW(NeuronOnDLS(32));
	EXPECT_NO_THROW(NeuronOnDLS(31));
}

TEST(NeuronOnDLS, toCapMemColumnOnDLS) {
	EXPECT_EQ(CapMemColumnOnDLS(3), NeuronOnDLS(3).toCapMemColumnOnDLS());
}

TEST(NeuronOnDLS, toSynapseColumnOnDLS) {
	EXPECT_EQ(SynapseColumnOnDLS(3), NeuronOnDLS(3).toSynapseColumnOnDLS());
}

TEST(PPUMemoryWordOnDLS, RespectsBounds) {
	EXPECT_ANY_THROW(PPUMemoryWordOnDLS(4096));
	EXPECT_NO_THROW(PPUMemoryWordOnDLS(4095));
}

TEST(PPUMemoryOnDLS, RespectsBounds) {
	EXPECT_ANY_THROW(PPUMemoryOnDLS(1));
	EXPECT_NO_THROW(PPUMemoryOnDLS(0));
}

TEST(RateCounterOnDLS, RespectsBounds) {
	EXPECT_ANY_THROW(RateCounterOnDLS(1));
	EXPECT_NO_THROW(RateCounterOnDLS(0));
}

TEST(PPUControlRegisterOnDLS, RespectsBounds) {
	EXPECT_ANY_THROW(PPUControlRegisterOnDLS(1));
	EXPECT_NO_THROW(PPUControlRegisterOnDLS(0));
}

TEST(PPUStatusRegisterOnDLS, RespectsBounds) {
	EXPECT_ANY_THROW(PPUStatusRegisterOnDLS(1));
	EXPECT_NO_THROW(PPUStatusRegisterOnDLS(0));
}
