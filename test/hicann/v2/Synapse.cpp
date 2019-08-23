#include <vector>
#include <gtest/gtest.h>

#include "halco/hicann/v2/quadrant.h"
#include "halco/hicann/v2/synapse.h"
#include "halco/hicann/v2/l1.h"
#include "halco/common/iter_all.h"

using namespace halco::common;
using namespace halco::hicann::v2;

TEST(SynapseSwitchRowOnHICANN, SpotCheck) {
	typedef SynapseSwitchRowOnHICANN SWR;
	typedef SynapseDriverOnHICANN SDC;

	EXPECT_EQ(SWR(Y(0), right), SWR(Y(0), right));
	EXPECT_LT(SWR(Y(0), left),  SWR(Y(0), right));
	EXPECT_LT(SWR(Y(0), left),  SWR(Y(1), left));
	EXPECT_LT(SWR(Y(1), left),  SWR(Y(2), right));
	EXPECT_LT(SWR(Y(2), right), SWR(Y(3), left));

	EXPECT_ANY_THROW(SWR(Y(0), left).toSynapseDriverOnHICANN());
	EXPECT_EQ(SDC(Y(0), right), SWR(Y(0), right).toSynapseDriverOnHICANN());
}

TEST(SynapseDriverOnHICANN, SpotCheck) {
	typedef SynapseDriverOnHICANN SDC;

	EXPECT_EQ(SDC(Y(0), right), SDC(Y(0), right));
	EXPECT_LT(SDC(Y(0), right), SDC(Y(2), right));
	EXPECT_LT(SDC(Y(1), left),  SDC(Y(2), right));
	EXPECT_LT(SDC(Y(2), right), SDC(Y(3), left));

	EXPECT_ANY_THROW(SDC(Y(0), left));
	EXPECT_ANY_THROW(SDC(Y(1), right));

	auto sdc = SDC(Y(0), right);
	EXPECT_EQ(sdc.x(), sdc.toSideHorizontal());
	EXPECT_EQ(right, sdc.toSideHorizontal());
}

TEST(SynapseDriverOnHICANN, toQuadrantOnHICANN) {
	QuadrantOnHICANN bottom_left{bottom, left};
	EXPECT_EQ(bottom_left,
	          SynapseDriverOnHICANN(Y(112), left).toQuadrantOnHICANN());

	for (auto const drv : iter_all<SynapseDriverOnHICANN>()) {
		QuadrantOnHICANN quadr{drv.toSideHorizontal(), drv.toSideVertical()};
		EXPECT_EQ(quadr, drv.toQuadrantOnHICANN());
	}
}

TEST(SynapseDriverOnHICANN, toSynapseDriverOnQuadrant) {
	SynapseDriverOnQuadrant first{SynapseDriverOnQuadrant::min};
	SynapseDriverOnQuadrant last{SynapseDriverOnQuadrant::max};

	EXPECT_EQ(first,
	          SynapseDriverOnHICANN(Y(1), left).toSynapseDriverOnQuadrant());
	EXPECT_EQ(last,
	          SynapseDriverOnHICANN(Y(111), left).toSynapseDriverOnQuadrant());

	EXPECT_EQ(first,
	          SynapseDriverOnHICANN(Y(0), right).toSynapseDriverOnQuadrant());
	EXPECT_EQ(last,
	          SynapseDriverOnHICANN(Y(110), right).toSynapseDriverOnQuadrant());

	EXPECT_EQ(first,
	          SynapseDriverOnHICANN(Y(112), left).toSynapseDriverOnQuadrant());
	EXPECT_EQ(last,
	          SynapseDriverOnHICANN(Y(222), left).toSynapseDriverOnQuadrant());

	EXPECT_EQ(first,
	          SynapseDriverOnHICANN(Y(113), right).toSynapseDriverOnQuadrant());
	EXPECT_EQ(last,
	          SynapseDriverOnHICANN(Y(223), right).toSynapseDriverOnQuadrant());
}

TEST(SynapseDriverOnQuadrant, toSynapseDriverOnHICANN) {
	for (auto const drv : iter_all<SynapseDriverOnHICANN>()) {
		QuadrantOnHICANN quadr{drv.toQuadrantOnHICANN()};
		EXPECT_EQ(drv, drv.toSynapseDriverOnQuadrant().toSynapseDriverOnHICANN(quadr));
	}
}

TEST(SynapseRowOnHICANN, SpotCheck) {
	auto srow = SynapseRowOnHICANN(SynapseDriverOnHICANN(Y(1), left), top);

	EXPECT_EQ(Y(1), srow.toSynapseDriverOnHICANN().line());
	EXPECT_EQ(top, srow.toRowOnSynapseDriver());
}

TEST(SynapseOnHICANN, SpotCheck) {
	SynapseOnHICANN s;

	s = SynapseOnHICANN(
		SynapseRowOnHICANN(SynapseDriverOnHICANN(Y(1), left), top),
		SynapseColumnOnHICANN(15));
	EXPECT_EQ(s.toNeuronOnHICANN(), NeuronOnHICANN(X(15), Y(0)));

	s = SynapseOnHICANN(
		SynapseRowOnHICANN(SynapseDriverOnHICANN(Y(131), right), top),
		SynapseColumnOnHICANN(42));
	EXPECT_EQ(s.toNeuronOnHICANN(), NeuronOnHICANN(X(42), Y(1)));
}

TEST(SynapseRowOnHICANN, ConversionBetweenSynapseRowOnArray)
{
	for (auto srow : iter_all<SynapseRowOnHICANN>()) {
		auto srow_back =
		    SynapseRowOnHICANN(srow.toSynapseRowOnArray(), srow.toSynapseArrayOnHICANN());
		EXPECT_EQ(srow, srow_back);
	}
}

TEST(SynapseArrayOnHICANN, ConversionBetweenSynapseRowOnHICANN)
{
	for (auto srow : iter_all<SynapseRowOnArray>()) {
		for (auto synarray : iter_all<SynapseArrayOnHICANN>()) {
			auto srow_back = SynapseRowOnHICANN(srow, synarray).toSynapseRowOnArray();
			EXPECT_EQ(srow, srow_back);
		}
	}
}

TEST(SynapseSwitchOnHICANN, Columns)
{
	for (auto x : iter_all<SynapseSwitchOnHICANN::x_type>()) {
		for (auto y : SynapseSwitchOnHICANN::column(x))
		{
			EXPECT_NO_THROW(SynapseSwitchOnHICANN(x, y))
				<< " for " << x << ", " << y;
		}
	}
}

TEST(SynapseSwitchOnHICANN, Constructor)
{
	int em = 0;
	for (auto r : iter_all<SynapseSwitchRowOnHICANN>()) {
		for (auto sw : iter_all<SynapseSwitchOnSynapseSwitchRow>()) {
			EXPECT_EQ(SynapseSwitchOnHICANN(r, sw).toEnum().value(), em)
			    << " for " << r << ", " << sw;
			em++;
		}
	}
}

TEST(CrossbarSwitchOnHICANN, Columns)
{
	for (auto x : iter_all<CrossbarSwitchOnHICANN::x_type>()) {
		for (auto y : CrossbarSwitchOnHICANN::column(x)) {
			EXPECT_NO_THROW(CrossbarSwitchOnHICANN(x, y)) << " for " << x << ", " << y;
		}
	}
}


TEST(CrossbarSwitchOnHICANN, Constructor)
{
	int em = 0;
	for (auto l : iter_all<HLineOnHICANN>()) {
		for (auto s : iter_all<SideHorizontal>()) {
			for (auto sw : iter_all<CrossbarSwitchOnCrossbarSwitchRow>()) {
				EXPECT_EQ(CrossbarSwitchOnHICANN(l, s, sw).toEnum().value(), em)
				    << " for " << l << ", " << s << ", " << sw;
				em++;
			}
		}
	}
}


TEST(VLineOnHICANN, toSynapseDriverOnHICANN)
{
	for (auto line : iter_all<VLineOnHICANN>()) {
		try {
			line.toSynapseDriverOnHICANN(left);
		} catch (const std::exception & err) {
			EXPECT_TRUE(false)
				<< "line.toSynapseDriverOnHICANN(left) did throw "
				<< "'" << err.what() << "' for: "
				<< left << ", " << line;
		}
		try {
			line.toSynapseDriverOnHICANN(right);
		} catch (const std::exception & err) {
			EXPECT_TRUE(false)
				<< "line.toSynapseDriverOnHICANN(right) did throw "
				<< "'" << err.what() << "' for: "
				<< right << ", " << line;
		}
	}
}
