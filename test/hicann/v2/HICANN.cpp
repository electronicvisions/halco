#include <vector>
#include <gtest/gtest.h>

#include "halco/hicann/v2/hicann.h"

using namespace halco::common;
using namespace halco::hicann::v2;

TEST(HICANNOnWafer, DoesNotExistForAllCombinations) {
	ASSERT_ANY_THROW(HICANNOnWafer(X(0), Y(0)));
	ASSERT_NO_THROW(HICANNOnWafer(Enum(0)));
}

TEST(HICANNGlobal, EnumCtorIsBackwardsCompatible) {
	ASSERT_EQ(Wafer(0), HICANNGlobal(Enum(HICANNOnWafer::enum_type::min)).toWafer());
	ASSERT_EQ(Wafer(0), HICANNGlobal(Enum(HICANNOnWafer::enum_type::max)).toWafer());
}

TEST(HICANNGlobal, HasGlobalEnumOverAllWafers) {
	HICANNGlobal hicann1{Enum(HICANNOnWafer::enum_type::size + 1)};
	HICANNGlobal hicann2{Enum(2 * HICANNOnWafer::enum_type::size + 1)};

	ASSERT_EQ(Wafer(1), hicann1.toWafer());
	ASSERT_EQ(Enum(HICANNOnWafer::enum_type::size + 1), hicann1.toEnum());
	ASSERT_EQ(Wafer(2), hicann2.toWafer());
	ASSERT_EQ(Enum(2 * HICANNOnWafer::enum_type::size + 1), hicann2.toEnum());
}

TEST(HICANNGlobal, DefaultsToWaferZeroForXYCtor) {
	X x(12);
	Y y(12);

	HICANNGlobal c(x, y);
	EXPECT_EQ(c.toWafer(), 0); // by default
	EXPECT_EQ(c.toEnum(), 324);
	EXPECT_EQ(c.x(), 12);
	EXPECT_EQ(c.y(), 12);

	EXPECT_ANY_THROW(HICANNGlobal(X(0), Y(0)));
	EXPECT_ANY_THROW(HICANNGlobal(X(234), Y(0)));
	EXPECT_ANY_THROW(HICANNGlobal(X(35), Y(15)));
}

TEST(HICANNGlobal, CanBeTraversedDownwards) {
	Wafer wafer(25);
	HICANNGlobal hh(X(10), Y(5), wafer);
	try {
		// this loop is only left by throw when hicann
		// coordinate gets out of range.
		while (true) {
			ASSERT_EQ(wafer, hh.toWafer());
			auto xx = hh.south();
			EXPECT_NE(hh, xx);
			EXPECT_EQ(hh, xx.north());
			hh = xx;
		}
	} catch (...) {
	}
}

TEST(HICANNGlobal, CanBeTraversedToTheRight) {
	Wafer wafer(25);
	HICANNGlobal hh(X(10), Y(5), wafer);
	try {
		// this loop is only left by throw when hicann
		// coordinate gets out of range.
		while (true) {
			ASSERT_EQ(wafer, hh.toWafer());
			auto xx = hh.east();
			EXPECT_NE(hh, xx);
			EXPECT_EQ(hh, xx.west());
			hh = xx;
		}
	} catch (...) {
	}
}
