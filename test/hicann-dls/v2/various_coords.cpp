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

TEST(PPUMemoryWordOnDLS, RespectsBounds) {
	EXPECT_ANY_THROW(PPUMemoryWordOnDLS(4096));
	EXPECT_NO_THROW(PPUMemoryWordOnDLS(4095));
}
