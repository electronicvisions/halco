#include <vector>
#include <gtest/gtest.h>

#include "halco/hicann/v2/l1.h"
#include "halco/common/iter_all.h"

using namespace halco::common;
using namespace halco::hicann::v2;

TEST(HLineOnHICANN, Compass) {
	HLineOnHICANN max{HLineOnHICANN::max};
	HLineOnHICANN min{HLineOnHICANN::min};
	ASSERT_NO_THROW(min.east());
	ASSERT_NO_THROW(max.west());

	// Lines on next HICANN:

	std::map<size_t, size_t> westwards{
		{ 0, 62}, { 1, 63}, { 2,  0}, { 3,  1}, { 4,  2}, { 5,  3}, {62, 60}, {63, 61}
	};

	for (auto p : westwards) {
		HLineOnHICANN western(p.second);
		HLineOnHICANN eastern(p.first);
		EXPECT_EQ(p.first, western.east());
		EXPECT_EQ(p.second, western.east().west());
		EXPECT_EQ(p.second, eastern.west());
		EXPECT_EQ(p.first, eastern.west().east());
	}
}

TEST(HLineOnHICANN, toVLineOnHICANN) {

	// pciked random hline from full HICANN map and corresponding Vlines
	HLineOnHICANN hline(42);
	std::array<VLineOnHICANN, 8> vlines1 = {{
		VLineOnHICANN{10},
		VLineOnHICANN{42},
		VLineOnHICANN{74},
		VLineOnHICANN{106},
		VLineOnHICANN{149},
		VLineOnHICANN{181},
		VLineOnHICANN{213},
		VLineOnHICANN{245}}};
	auto vlines2 = hline.toVLineOnHICANN();
	EXPECT_EQ(vlines1, vlines2);

	// TODO: continue...
}

TEST(VLineOnHICANN, toHLineOnHICANN)
{
	// picked random vline on left side of HICANN and corresponding hlines
	VLineOnHICANN vline(42);
	std::array<HLineOnHICANN, 2> hlines1 = {{HLineOnHICANN{42}, HLineOnHICANN{43}}};
	auto hlines2 = vline.toHLineOnHICANN();
	EXPECT_EQ(hlines1, hlines2);

	// picked random vline on right side of HICANN and corresponding hlines
	VLineOnHICANN vline2(131);
	hlines1 = {{HLineOnHICANN{6}, HLineOnHICANN{7}}};
	hlines2 = vline2.toHLineOnHICANN();
	EXPECT_EQ(hlines1, hlines2);
}

TEST(HLineOnHICANN, ImplicitConvToUInt) {
	for (size_t ii = 0; ii < HLineOnHICANN::end; ++ii) {
		HLineOnHICANN h(ii);
		EXPECT_EQ(ii, h);
	};
}

TEST(HLineOnHICANN, Printable) {
	std::stringstream ss;
	ss << HLineOnHICANN(25);
	ASSERT_EQ("HLineOnHICANN(25)", ss.str());
}

TEST(VLineOnHICANN, Compass) {
	VLineOnHICANN max{VLineOnHICANN::max};
	VLineOnHICANN min{VLineOnHICANN::min};
	ASSERT_NO_THROW(min.south());
	ASSERT_NO_THROW(max.north());

	// Lines on next HICANN:

	std::map<size_t, size_t> downwards{
		{  0, 126}, {  1, 127}, {  2,   0}, {  3,   1}, {  4,   2}, {126, 124}, {127, 125},
		{128, 130}, {129, 131}, {130, 132}, {251, 253}, {252, 254}, {253, 255}, {254, 128}, {255, 129}
	};

	ASSERT_EQ(256, VLineOnHICANN::end);

	for (auto p : downwards) {
		VLineOnHICANN southern(p.second);
		VLineOnHICANN northern(p.first);
		ASSERT_EQ(p.second, southern);
		EXPECT_EQ(p.first, southern.north());
		EXPECT_EQ(p.second, southern.north().south());
		EXPECT_EQ(p.second, northern.south());
		EXPECT_EQ(p.first, northern.south().north());
	}
}

TEST(VLineOnHICANN, Side) {
	EXPECT_EQ(left, VLineOnHICANN(0).toSideHorizontal());
	EXPECT_EQ(left, VLineOnHICANN(127).toSideHorizontal());
	EXPECT_EQ(right, VLineOnHICANN(128).toSideHorizontal());
	EXPECT_EQ(right, VLineOnHICANN(255).toSideHorizontal());
}

TEST(VLineOnHICANN, toSynapseSwitchRowOnHICANN) {
	struct data_t {
		size_t line;
		SideVertical side_vertical;
		size_t index;
		size_t expected_switch_row_index;
	};

    std::vector<data_t> data{
	    /* line,	side,	idx,	expected */
        {13,		top,	0,		6},
        {13,		top,	5,		39},
        {13,		top,	9,		71},
        {13,		top,	13,		103},
        {83,		top,	0,		8},
        {13,		bottom,	0,		120},
        {13,		bottom,	7,		169},
        {13,		bottom,	10,		200},
        {13,		bottom,	13,		217},
        {141,		top,	0,		8},
        {141,		top,	7,		57},
        {141,		top,	10,		88},
        {141,		top,	13,		105},
        {217,		top,	0,		2},
        {217,		top,	1,		3},
        {141,		bottom,	0,		118},
        {141,		bottom,	7,		167},
        {141,		bottom,	10,		198},
        {141,		bottom,	13,		215}
    };

    for (auto const& entry : data) {
	    VLineOnHICANN vline{entry.line};
		SynapseSwitchRowOnHICANN expected{vline.toSideHorizontal(),
		                                  Y(entry.expected_switch_row_index)};
		auto res = vline.toSynapseSwitchRowOnHICANN(entry.side_vertical,
		                                            Enum(entry.index));
		EXPECT_EQ(expected, res);
	}
}

TEST(RepeaterBlockOnHICANN, EnumIsBackwardsCompatible) {
	/* Old enum definition:
	PYPP_TYPED_ENUM(Type, size_t) {
		topleft,
		topright,
		CENTERleft,
		CENTERright,
		bottomleft,
		bottomright
	}; */

	RepeaterBlockOnHICANN block;

	block = RepeaterBlockOnHICANN(X(0), Y(0));
	EXPECT_EQ(0, block.toEnum());

	block = RepeaterBlockOnHICANN(X(1), Y(0));
	EXPECT_EQ(1, block.toEnum());

	block = RepeaterBlockOnHICANN(X(0), Y(1));
	EXPECT_EQ(2, block.toEnum());

	block = RepeaterBlockOnHICANN(X(1), Y(1));
	EXPECT_EQ(3, block.toEnum());

	block = RepeaterBlockOnHICANN(X(0), Y(2));
	EXPECT_EQ(4, block.toEnum());

	block = RepeaterBlockOnHICANN(X(1), Y(2));
	EXPECT_EQ(5, block.toEnum());
}

TEST(HRepeaterOnHICANN, DoesNotExistOnEveryGridPoint) {
	// „even addresses refer to the left border and odd addresses to the right“

	for (auto hline : iter_all<HLineOnHICANN>()) {
		ASSERT_NO_THROW(HRepeaterOnHICANN(hline, (hline % 2) ? right : left));
		ASSERT_ANY_THROW(HRepeaterOnHICANN(hline, (hline % 2) ? left : right));
	}

	HRepeaterOnHICANN
		rep0(HLineOnHICANN(0), left),
		rep1(HLineOnHICANN(1), right),
		rep15(HLineOnHICANN(15), right);

	EXPECT_EQ(0, rep0.toRepeaterBlockOnHICANN().x());
	EXPECT_EQ(1, rep0.toRepeaterBlockOnHICANN().y());

	EXPECT_EQ(1, rep1.toRepeaterBlockOnHICANN().x());
	EXPECT_EQ(1, rep1.toRepeaterBlockOnHICANN().y());

	EXPECT_EQ(1, rep15.toRepeaterBlockOnHICANN().x());
	EXPECT_EQ(1, rep15.toRepeaterBlockOnHICANN().y());

	EXPECT_EQ(0, rep0.toHLineOnHICANN());
	EXPECT_EQ(15, rep15.toHLineOnHICANN());
}

TEST(HRepeaterOnHICANN, toHLineOnHICANN) {
	for (auto hline : iter_all<HLineOnHICANN>()) {
		HRepeaterOnHICANN rep = hline.toHRepeaterOnHICANN();

		EXPECT_EQ(hline, rep.toHLineOnHICANN());
	}
}

TEST(HRepeaterOnHICANN, toSendingRepeaterOnHICANN) {
	for (auto rep : iter_all<HRepeaterOnHICANN>()) {
		ASSERT_EQ((rep.toHLineOnHICANN() % 8 == 6), rep.isSending());

		if (rep.isSending()) {
			SendingRepeaterOnHICANN sending;
			ASSERT_NO_THROW(sending = rep.toSendingRepeaterOnHICANN());
			EXPECT_EQ(sending.toHRepeaterOnHICANN(), rep);
		} else {
			EXPECT_ANY_THROW(rep.toSendingRepeaterOnHICANN());
		}
	}
}

TEST(HRepeaterOnHICANN, toTestPortOnRepeaterBlock)
{
	for (auto rep : iter_all<HRepeaterOnHICANN>()) {
		if (rep.isSending()) {
			EXPECT_ANY_THROW(rep.toTestPortOnRepeaterBlock());
		}
	}
}

TEST(VRepeaterOnHICANN, DoesNotExistOnEveryGridPoint) {
	/* „On the left side of the HICANN even vertical lanes connect to
	* bottom repeaters and odd lanes to top repeaters.  On the right side
	* even vertical lanes connect to top and odd to bottom repeaters.“ */

	for (auto vline : iter_all<VLineOnHICANN>()) {
		SideVertical side;

		if (vline.toSideHorizontal() == left)
			side = (vline % 2) ? top : bottom;
		else
			side = (vline % 2) ? bottom : top;

		VRepeaterOnHICANN rep(vline, side);
		EXPECT_ANY_THROW(VRepeaterOnHICANN(vline, (side == top) ? bottom : top));

		EXPECT_EQ(vline, rep.toVLineOnHICANN());
		EXPECT_EQ(vline.toVRepeaterOnHICANN(), rep);
	}

	VRepeaterOnHICANN
		rep0(VLineOnHICANN(0), bottom),
		rep1(VLineOnHICANN(1), top),
		rep130(VLineOnHICANN(130), top),
		rep131(VLineOnHICANN(131), bottom);

	EXPECT_EQ(RepeaterBlockOnHICANN(X(0), Y(2)),
	          rep0.toRepeaterBlockOnHICANN());
	EXPECT_EQ(0, rep0.toRepeaterBlockOnHICANN().x());
	EXPECT_EQ(2, rep0.toRepeaterBlockOnHICANN().y());

	EXPECT_EQ(RepeaterBlockOnHICANN(X(0), Y(0)),
	          rep1.toRepeaterBlockOnHICANN());
	EXPECT_EQ(0, rep1.toRepeaterBlockOnHICANN().x());
	EXPECT_EQ(0, rep1.toRepeaterBlockOnHICANN().y());

	EXPECT_EQ(RepeaterBlockOnHICANN(X(1), Y(0)),
	          rep130.toRepeaterBlockOnHICANN());
	EXPECT_EQ(1, rep130.toRepeaterBlockOnHICANN().x());
	EXPECT_EQ(0, rep130.toRepeaterBlockOnHICANN().y());

	EXPECT_EQ(RepeaterBlockOnHICANN(X(1), Y(2)),
	          rep131.toRepeaterBlockOnHICANN());
	EXPECT_EQ(1, rep131.toRepeaterBlockOnHICANN().x());
	EXPECT_EQ(2, rep131.toRepeaterBlockOnHICANN().y());

	EXPECT_EQ(0, rep0.toVLineOnHICANN());
	EXPECT_EQ(130, rep130.toVLineOnHICANN());
}

TEST(SendingRepeaterOnHICANN, toDNCMergerOnHICANNtoSendingRepeaterOnHICANN) {
	for (auto sending : iter_all<SendingRepeaterOnHICANN>()) {
		EXPECT_EQ(sending, sending.toDNCMergerOnHICANN().toSendingRepeaterOnHICANN());
	}
}

TEST(SendingRepeaterOnHICANN, toHRepeaterOnHICANN) {
	for (auto sending : iter_all<SendingRepeaterOnHICANN>()) {
		HRepeaterOnHICANN rep = sending.toHRepeaterOnHICANN();

		EXPECT_TRUE(rep.isSending());
		EXPECT_EQ(sending, rep.toSendingRepeaterOnHICANN());
	}
}

TEST(SendingRepeaterOnHICANN, toRepeaterBlockOnHICANN) {
	EXPECT_EQ(RepeaterBlockOnHICANN(X(0), Y(1)),
	          SendingRepeaterOnHICANN(7).toRepeaterBlockOnHICANN());
}

TEST(SendingRepeaterOnHICANN, toHLineOnHICANN) {
	EXPECT_EQ(HLineOnHICANN(6), SendingRepeaterOnHICANN(0).toHLineOnHICANN());
	EXPECT_EQ(HLineOnHICANN(62), SendingRepeaterOnHICANN(7).toHLineOnHICANN());
}

TEST(DNCMergerOnHICANN, toSendingRepeater) {
	for (auto merger : iter_all<DNCMergerOnHICANN>()) {
		EXPECT_EQ(merger, merger.toSendingRepeaterOnHICANN().toDNCMergerOnHICANN());
	}

	DNCMergerOnHICANN m7(7);
	EXPECT_EQ(
	    HLineOnHICANN(6), m7.toSendingRepeaterOnHICANN().toHRepeaterOnHICANN().toHLineOnHICANN());

	DNCMergerOnHICANN m0(0);
	EXPECT_EQ(
	    HLineOnHICANN(62), m0.toSendingRepeaterOnHICANN().toHRepeaterOnHICANN().toHLineOnHICANN());
}

TEST(HRepeaterOnWafer, toHRepeaterOnHICANN_toHICANNOnWafer_toRepeaterBlockOnWafer) {
	for (auto hicann_on_wafer : iter_all<HICANNOnWafer>()) {
		for (auto hrepeater_on_hicann : iter_all<HRepeaterOnHICANN>()) {
			HRepeaterOnWafer hrepeater_on_wafer(hrepeater_on_hicann, hicann_on_wafer);
			EXPECT_EQ(hrepeater_on_wafer.toHICANNOnWafer(), hicann_on_wafer);
			EXPECT_EQ(hrepeater_on_wafer.toHRepeaterOnHICANN(), hrepeater_on_hicann);
			EXPECT_EQ(hrepeater_on_wafer.toRepeaterBlockOnWafer(),
				RepeaterBlockOnWafer(hrepeater_on_hicann.toRepeaterBlockOnHICANN(), hicann_on_wafer));
		}
	}
}

TEST(VRepeaterOnWafer, toVRepeaterOnHICANN_toHICANNOnWafer_toRepeaterBlockOnWafer) {
	for (auto hicann_on_wafer : iter_all<HICANNOnWafer>()) {
		for (auto vrepeater_on_hicann : iter_all<VRepeaterOnHICANN>()) {
			VRepeaterOnWafer vrepeater_on_wafer(vrepeater_on_hicann, hicann_on_wafer);
			EXPECT_EQ(vrepeater_on_wafer.toHICANNOnWafer(), hicann_on_wafer);
			EXPECT_EQ(vrepeater_on_wafer.toVRepeaterOnHICANN(), vrepeater_on_hicann);
			EXPECT_EQ(vrepeater_on_wafer.toRepeaterBlockOnWafer(),
				RepeaterBlockOnWafer(vrepeater_on_hicann.toRepeaterBlockOnHICANN(), hicann_on_wafer));
		}
	}
}

TEST(RepeaterBlockOnWafer, RepeaterBlockOnHICANN_toHICANNOnWafer) {
	for (auto hicann_on_wafer : iter_all<HICANNOnWafer>()) {
		for (auto rb_on_hicann : iter_all<RepeaterBlockOnHICANN>()) {
			RepeaterBlockOnWafer rb_on_wafer(rb_on_hicann, hicann_on_wafer);
			EXPECT_EQ(rb_on_wafer.toHICANNOnWafer(), hicann_on_wafer);
			EXPECT_EQ(rb_on_wafer.toRepeaterBlockOnHICANN(), rb_on_hicann);
		}
	}
}

TEST(HRepeaterOnWafer, toHLineOnWaferLocalFirst) {
	for (auto hline_on_wafer : iter_all<HLineOnWafer>()) {
		auto const hrepeater = hline_on_wafer.toHLineOnHICANN().toHRepeaterOnHICANN();
		auto const hlines =
		    HRepeaterOnWafer(hrepeater, hline_on_wafer.toHICANNOnWafer()).toHLineOnWafer();

		EXPECT_EQ(hline_on_wafer, boost::tuples::get<0>(hlines));
	}
}

TEST(HRepeaterOnWafer, toHLineOnWaferHasNeighbor) {
	for (auto hline_on_wafer : iter_all<HLineOnWafer>()) {
		auto const hicann = hline_on_wafer.toHICANNOnWafer();
		auto const hrepeater = hline_on_wafer.toHLineOnHICANN().toHRepeaterOnHICANN();
		auto const hlines =
		    HRepeaterOnWafer(hrepeater, hline_on_wafer.toHICANNOnWafer()).toHLineOnWafer();

		if (hrepeater.isLeft()) {
			EXPECT_EQ(hicann.has_west(), boost::tuples::get<1>(hlines).has_value());
		} else {
			EXPECT_EQ(hicann.has_east(), boost::tuples::get<1>(hlines).has_value());
		}
	}
}

TEST(HRepeaterOnWafer, toHLineOnWaferMoves) {
	for (auto hline_on_wafer : iter_all<HLineOnWafer>()) {
		auto const hicann = hline_on_wafer.toHICANNOnWafer();
		auto const hrepeater = hline_on_wafer.toHLineOnHICANN().toHRepeaterOnHICANN();
		auto const hlines =
		    HRepeaterOnWafer(hrepeater, hline_on_wafer.toHICANNOnWafer()).toHLineOnWafer();

		if (hrepeater.isLeft()) {
			if (hicann.has_west()) {
				EXPECT_EQ(hicann.west(), boost::tuples::get<1>(hlines)->toHICANNOnWafer());
				EXPECT_EQ(
				    hline_on_wafer.toHLineOnHICANN().west(),
				    boost::tuples::get<1>(hlines)->toHLineOnHICANN());
			}
		} else {
			if (hicann.has_east()) {
				EXPECT_EQ(hicann.east(), boost::tuples::get<1>(hlines)->toHICANNOnWafer());
				EXPECT_EQ(
				    hline_on_wafer.toHLineOnHICANN().east(),
				    boost::tuples::get<1>(hlines)->toHLineOnHICANN());
			}
		}
	}
}

TEST(VRepeaterOnWafer, toVLineOnWaferLocalFirst) {
	for (auto vline_on_wafer : iter_all<VLineOnWafer>()) {
		auto const vrepeater = vline_on_wafer.toVLineOnHICANN().toVRepeaterOnHICANN();
		auto const vlines =
		    VRepeaterOnWafer(vrepeater, vline_on_wafer.toHICANNOnWafer()).toVLineOnWafer();

		EXPECT_EQ(vline_on_wafer, boost::tuples::get<0>(vlines));
	}
}

TEST(VRepeaterOnWafer, toVLineOnWaferHasNeighbor) {
	for (auto vline_on_wafer : iter_all<VLineOnWafer>()) {
		auto const hicann = vline_on_wafer.toHICANNOnWafer();
		auto const vrepeater = vline_on_wafer.toVLineOnHICANN().toVRepeaterOnHICANN();
		auto const vlines =
		    VRepeaterOnWafer(vrepeater, vline_on_wafer.toHICANNOnWafer()).toVLineOnWafer();

		if (vrepeater.isTop()) {
			EXPECT_EQ(hicann.has_north(), boost::tuples::get<1>(vlines).has_value());
		} else {
			EXPECT_EQ(hicann.has_south(), boost::tuples::get<1>(vlines).has_value());
		}
	}
}

TEST(VRepeaterOnWafer, toVLineOnWaferMoves) {
	for (auto vline_on_wafer : iter_all<VLineOnWafer>()) {
		auto const hicann = vline_on_wafer.toHICANNOnWafer();
		auto const vrepeater = vline_on_wafer.toVLineOnHICANN().toVRepeaterOnHICANN();
		auto const vlines =
		    VRepeaterOnWafer(vrepeater, vline_on_wafer.toHICANNOnWafer()).toVLineOnWafer();

		if (vrepeater.isBottom()) {
			if (hicann.has_south()) {
				EXPECT_EQ(hicann.south(), boost::tuples::get<1>(vlines)->toHICANNOnWafer());
				EXPECT_EQ(
				    vline_on_wafer.toVLineOnHICANN().south(),
				    boost::tuples::get<1>(vlines)->toVLineOnHICANN());
			}
		} else {
			if (hicann.has_north()) {
				EXPECT_EQ(hicann.north(), boost::tuples::get<1>(vlines)->toHICANNOnWafer());
				EXPECT_EQ(
				    vline_on_wafer.toVLineOnHICANN().north(),
				    boost::tuples::get<1>(vlines)->toVLineOnHICANN());
			}
		}
	}
}

TEST(HLineOnWafer, toHRepeaterOnWaferLocalFirst) {
	for (auto hline_on_wafer : iter_all<HRepeaterOnWafer>()) {
		auto const hrepeater = hline_on_wafer.toHRepeaterOnHICANN().toHLineOnHICANN();
		auto const hlines =
		    HLineOnWafer(hrepeater, hline_on_wafer.toHICANNOnWafer()).toHRepeaterOnWafer();

		EXPECT_EQ(hline_on_wafer, boost::tuples::get<0>(hlines));
	}
}

TEST(HLineOnWafer, toHRepeaterOnWaferHasNeighbor) {
	for (auto hrepeater_on_wafer : iter_all<HRepeaterOnWafer>()) {
		auto const hicann = hrepeater_on_wafer.toHICANNOnWafer();
		auto const hline = hrepeater_on_wafer.toHRepeaterOnHICANN().toHLineOnHICANN();
		auto const hrepeaters =
		    HLineOnWafer(hline, hrepeater_on_wafer.toHICANNOnWafer()).toHRepeaterOnWafer();

		if (hline.toHRepeaterOnHICANN().isLeft()) {
			EXPECT_EQ(hicann.has_east(), boost::tuples::get<1>(hrepeaters).has_value());
		} else {
			EXPECT_EQ(hicann.has_west(), boost::tuples::get<1>(hrepeaters).has_value());
		}
	}
}

TEST(HLineOnWafer, toHRepeaterOnWaferMoves) {
	for (auto hrepeater_on_wafer : iter_all<HRepeaterOnWafer>()) {
		auto const hicann = hrepeater_on_wafer.toHICANNOnWafer();
		auto const hline = hrepeater_on_wafer.toHRepeaterOnHICANN().toHLineOnHICANN();
		auto const hrepeaters =
		    HLineOnWafer(hline, hrepeater_on_wafer.toHICANNOnWafer()).toHRepeaterOnWafer();

		if (hline.toHRepeaterOnHICANN().isLeft()) {
			if (hicann.has_east()) {
				EXPECT_EQ(hicann.east(), boost::tuples::get<1>(hrepeaters)->toHICANNOnWafer());
				EXPECT_EQ(
				    hrepeater_on_wafer.toHRepeaterOnHICANN()
				        .toHLineOnHICANN()
				        .east()
				        .toHRepeaterOnHICANN(),
				    boost::tuples::get<1>(hrepeaters)->toHRepeaterOnHICANN());
			}
		} else {
			if (hicann.has_west()) {
				EXPECT_EQ(hicann.west(), boost::tuples::get<1>(hrepeaters)->toHICANNOnWafer());
				EXPECT_EQ(
				    hrepeater_on_wafer.toHRepeaterOnHICANN()
				        .toHLineOnHICANN()
				        .west()
				        .toHRepeaterOnHICANN(),
				    boost::tuples::get<1>(hrepeaters)->toHRepeaterOnHICANN());
			}
		}
	}
}

TEST(VLineOnWafer, toVRepeaterOnWaferLocalFirst) {
	for (auto vline_on_wafer : iter_all<VRepeaterOnWafer>()) {
		auto const vrepeater = vline_on_wafer.toVRepeaterOnHICANN().toVLineOnHICANN();
		auto const vlines =
		    VLineOnWafer(vrepeater, vline_on_wafer.toHICANNOnWafer()).toVRepeaterOnWafer();

		EXPECT_EQ(vline_on_wafer, boost::tuples::get<0>(vlines));
	}
}

TEST(VLineOnWafer, toVRepeaterOnWaferHasNeighbor) {
	for (auto vrepeater_on_wafer : iter_all<VRepeaterOnWafer>()) {
		auto const hicann = vrepeater_on_wafer.toHICANNOnWafer();
		auto const vline = vrepeater_on_wafer.toVRepeaterOnHICANN().toVLineOnHICANN();
		auto const vrepeaters =
		    VLineOnWafer(vline, vrepeater_on_wafer.toHICANNOnWafer()).toVRepeaterOnWafer();

		if (vline.toVRepeaterOnHICANN().isTop()) {
			EXPECT_EQ(hicann.has_south(), boost::tuples::get<1>(vrepeaters).has_value());
		} else {
			EXPECT_EQ(hicann.has_north(), boost::tuples::get<1>(vrepeaters).has_value());
		}
	}
}

TEST(VLineOnWafer, toVRepeaterOnWaferMoves) {
	for (auto vrepeater_on_wafer : iter_all<VRepeaterOnWafer>()) {
		auto const hicann = vrepeater_on_wafer.toHICANNOnWafer();
		auto const vline = vrepeater_on_wafer.toVRepeaterOnHICANN().toVLineOnHICANN();
		auto const vrepeaters =
		    VLineOnWafer(vline, vrepeater_on_wafer.toHICANNOnWafer()).toVRepeaterOnWafer();

		if (vline.toVRepeaterOnHICANN().isTop()) {
			if (hicann.has_south()) {
				EXPECT_EQ(hicann.south(), boost::tuples::get<1>(vrepeaters)->toHICANNOnWafer());
				EXPECT_EQ(
				    vrepeater_on_wafer.toVRepeaterOnHICANN()
				        .toVLineOnHICANN()
				        .south()
				        .toVRepeaterOnHICANN(),
				    boost::tuples::get<1>(vrepeaters)->toVRepeaterOnHICANN());
			}
		} else {
			if (hicann.has_north()) {
				EXPECT_EQ(hicann.north(), boost::tuples::get<1>(vrepeaters)->toHICANNOnWafer());
				EXPECT_EQ(
				    vrepeater_on_wafer.toVRepeaterOnHICANN()
				        .toVLineOnHICANN()
				        .north()
				        .toVRepeaterOnHICANN(),
				    boost::tuples::get<1>(vrepeaters)->toVRepeaterOnHICANN());
			}
		}
	}
}
