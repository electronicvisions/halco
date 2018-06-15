#include <vector>
#include <gtest/gtest.h>

#include "halco/hicann/v2/neuron.h"
#include "halco/common/iter_all.h"

using namespace halco::common;
using namespace halco::hicann::v2;

TEST(NeuronOnQuad, RespectsBounds) {
	EXPECT_ANY_THROW(NeuronOnQuad(X(0), Y(2)));
	EXPECT_ANY_THROW(NeuronOnQuad(X(2), Y(1)));
	EXPECT_ANY_THROW(NeuronOnQuad(X(5), Y(42)));
}

TEST(NeuronOnQuad, HasId) {
	EXPECT_EQ(3, NeuronOnQuad(X(1), Y(1)).id());
}

TEST(QuadOnHICANN, RespectsBounds) {
	EXPECT_ANY_THROW(QuadOnHICANN(128));
}

TEST(QuadOnHICANN, HasId) {
	EXPECT_EQ(127, QuadOnHICANN(127));
}

TEST(NeuronOnHICANN, RespectsBounds) {
	EXPECT_ANY_THROW(NeuronOnHICANN(X(256), Y(0)));
	EXPECT_ANY_THROW(NeuronOnHICANN(X(42), Y(2)));
}

TEST(NeuronOnHICANN, toQuadOnHICANN) {
	NeuronOnHICANN noh{Enum(511)};
	EXPECT_EQ(511, noh.id());
	EXPECT_EQ(QuadOnHICANN(127), noh.toQuadOnHICANN());
}

TEST(NeuronOnHICANN, toNeuronOnQuad) {
	NeuronOnHICANN noh{Enum(511)};
	EXPECT_EQ(NeuronOnQuad(X(1), Y(1)), noh.toNeuronOnQuad());
}

TEST(NeuronOnHICANN, toNeuronOnFGBlock) {
	NeuronOnHICANN noh{Enum(5)};
	EXPECT_EQ(FGBlockOnHICANN(Enum(0)), noh.toNeuronFGBlock());
	EXPECT_EQ(NeuronOnFGBlock(5), noh.toNeuronOnFGBlock());

	noh = NeuronOnHICANN(Enum(132));
	EXPECT_EQ(FGBlockOnHICANN(Enum(1)), noh.toNeuronFGBlock());
	EXPECT_EQ(NeuronOnFGBlock(4), noh.toNeuronOnFGBlock());
}

TEST(NeuronOnHICANN, toNeuronOnNeuronBlock) {
	NeuronOnHICANN noh{X(11), Y(0)};
	EXPECT_EQ(0, noh.toNeuronBlockOnHICANN());
	EXPECT_EQ(NeuronOnNeuronBlock(X(11), Y(0)), noh.toNeuronOnNeuronBlock());

	noh = NeuronOnHICANN{X(44), Y(1)};
	EXPECT_EQ(1, noh.toNeuronBlockOnHICANN());
	EXPECT_EQ(NeuronOnNeuronBlock(X(12), Y(1)), noh.toNeuronOnNeuronBlock());

	for (auto const nrn : iter_all<NeuronOnHICANN>()) {
		auto const nbl = nrn.toNeuronOnNeuronBlock();
		auto const block = nrn.toNeuronBlockOnHICANN();
		EXPECT_EQ(nrn, nbl.toNeuronOnHICANN(block));
	}
}
