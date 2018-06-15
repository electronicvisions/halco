#include <gtest/gtest.h>

#include <boost/preprocessor/stringize.hpp>
#include <sstream>
#include <iostream>
#include <map>

#include "halco/hicann/v2/coordinates.h"

using namespace halco::common;

namespace halco {
namespace hicann {
namespace v2 {


TEST(HMFGeometryTest, HICANNOrdering)
{
	std::vector<HICANNGlobal> hicanns;
	for (size_t ii=0; ii<384; ++ii)
	{
		hicanns.push_back(HICANNGlobal(Enum(ii)));
	}

	for (size_t ii=0; ii<383; ++ii)
	{
		ASSERT_TRUE(hicanns[ii] < hicanns[ii+1]
			|| (hicanns[ii].y()+1 == hicanns[ii+1].y()));
	}
}

struct A
    : public detail::GridCoordinate<A, XRanged<10, 2>, YRanged<2, 0>> {};

struct RantCharFromChar : public detail::RantWrapper<RantCharFromChar, uint8_t, 42, 0> {
	constexpr explicit RantCharFromChar(uint8_t const val) : rant_t(val) {}
};

struct RantCharFromSize : public detail::RantWrapper<RantCharFromSize, uint8_t, 42, 0> {
	constexpr explicit RantCharFromSize(size_t const val) : rant_t(val) {}
};

struct RantCharFromY : public detail::RantWrapper<RantCharFromY, uint8_t, 42, 0> {
	constexpr explicit RantCharFromY(common::Y const& y) : rant_t(y.value()) {}
};

TEST(HMFGeometryTest, Overflow) {
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconstant-conversion"
#pragma clang diagnostic ignored "-Woverflow"
#elif __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Woverflow"
#endif
	EXPECT_NO_THROW(RantCharFromChar(RantCharFromChar::max + 0));
	EXPECT_ANY_THROW(RantCharFromChar(RantCharFromChar::max + 1));
	// As the overflow/narrowing will happen in the constructor of RantCharFromChar
	// it is expected that the following call does not throw during the check in rant.
	EXPECT_NO_THROW(RantCharFromChar(255 + RantCharFromChar::max + 1));

	EXPECT_NO_THROW(RantCharFromSize(RantCharFromSize::max + 0));
	EXPECT_ANY_THROW(RantCharFromSize(RantCharFromSize::max + 1));
	EXPECT_ANY_THROW(RantCharFromSize(255 + RantCharFromSize::max + 1));

	EXPECT_NO_THROW(RantCharFromY(Y(RantCharFromY::max + 0)));
	EXPECT_ANY_THROW(RantCharFromY(Y(RantCharFromY::max + 1)));
	EXPECT_ANY_THROW(RantCharFromY(Y(255 + RantCharFromY::max + 1)));

	EXPECT_NO_THROW(GbitLinkOnHICANN(GbitLinkOnHICANN::max + 0));
	EXPECT_ANY_THROW(GbitLinkOnHICANN(GbitLinkOnHICANN::max + 1));
	EXPECT_ANY_THROW(GbitLinkOnHICANN((1ull << 8) + GbitLinkOnHICANN::max));
	EXPECT_ANY_THROW(GbitLinkOnHICANN((1ull << 8) + GbitLinkOnHICANN::max + 1));
	EXPECT_ANY_THROW(GbitLinkOnHICANN((1ull << 16) + GbitLinkOnHICANN::max));
	EXPECT_ANY_THROW(GbitLinkOnHICANN((1ull << 32) + GbitLinkOnHICANN::max));

	EXPECT_NO_THROW(FGRowOnFGBlock(FGRowOnFGBlock::max + 0));
	EXPECT_ANY_THROW(FGRowOnFGBlock(FGRowOnFGBlock::max + 1));
	EXPECT_ANY_THROW(FGRowOnFGBlock((1ull << 8) + FGRowOnFGBlock::max));
	EXPECT_ANY_THROW(FGRowOnFGBlock((1ull << 16) + FGRowOnFGBlock::max));
	EXPECT_ANY_THROW(FGRowOnFGBlock((1ull << 32) + FGRowOnFGBlock::max));
#ifdef __clang__
#pragma clang diagnostic pop
#elif __GNUC__
#pragma GCC diagnostic pop
#endif
}

TEST(HMFGeometryTest, ImplicitConversion) {
	DNCMergerOnHICANN dnc(5);
	GbitLinkOnHICANN link(dnc);
	DNCMergerOnHICANN dnc_(link);
	EXPECT_EQ(5u, link);
	EXPECT_EQ(5u, link.value());
	EXPECT_EQ(5u, dnc_.value());
}

TEST(HMFGeometryTest, GridCoordinate) {
	typedef A::x_type x_type;
	typedef A::y_type y_type;

	typedef detail::GridCoordinate<A, x_type, y_type > grid_t;

	ASSERT_EQ(grid_t::x_type::size, 9);
	ASSERT_EQ(grid_t::y_type::size, 3);

	ASSERT_EQ(grid_t::enum_type::min, 0);
	ASSERT_EQ(grid_t::enum_type::size, 27);
	ASSERT_EQ(grid_t::enum_type::end, 27);
	ASSERT_EQ(grid_t::enum_type::max, 26);

	grid_t g0(X(2), Y(0));
	EXPECT_EQ(g0.id(), 0);
	EXPECT_EQ(g0.x(), 2);
	EXPECT_EQ(g0.y(), 0);

	grid_t g1(Enum(1));
	EXPECT_EQ(g1.id(), 1);
	EXPECT_EQ(g1.x(), 3);
	EXPECT_EQ(g1.y(), 0);

	grid_t g5(Enum(5));
	EXPECT_EQ(g5.id(), 5);
	EXPECT_EQ(g5.x(), 7);
	EXPECT_EQ(g5.y(), 0);

	grid_t g8(Enum(8));
	EXPECT_EQ(g8.id(), 8);
	EXPECT_EQ(g8.x(), 10);
	EXPECT_EQ(g8.y(), 0);

	grid_t g12(Enum(12));
	EXPECT_EQ(g12.id(), 12);
	EXPECT_EQ(g12.x(), 5);
	EXPECT_EQ(g12.y(), 1);

	grid_t g26(Enum(26));
	EXPECT_EQ(g26.id(), 26);
	EXPECT_EQ(g26.x(), 10);
	EXPECT_EQ(g26.y(), 2);
}

TEST(HMFGeometryTest, DNC) {
	X x(4);
	Y y(5);

	DNCGlobal c(x,y);
	EXPECT_EQ(c.toWafer(), 0); // by default
	EXPECT_EQ(c.toEnum(), 36); // ?
	EXPECT_EQ(c.x(), 4);
	EXPECT_EQ(c.y(), 5);

	EXPECT_ANY_THROW( DNCGlobal(X(0), Y(0)) );
	EXPECT_ANY_THROW( DNCGlobal(X(234), Y(0)) );
	EXPECT_ANY_THROW( DNCGlobal(X(9), Y(8)) );
}

#define TEST_PRINT_SIDE(STR) \
	{ \
		auto side = STR; \
		std::stringstream tmp; \
		tmp << side; \
		EXPECT_EQ(tmp.str(), BOOST_PP_STRINGIZE(STR)); \
	}

TEST(HMFGeometryTest, SidePrettyPrint) {
	TEST_PRINT_SIDE(left)
	TEST_PRINT_SIDE(right)
	TEST_PRINT_SIDE(top)
	TEST_PRINT_SIDE(bottom)
}

} // namespace v2
} // namespace hicann
} // namespace halco
