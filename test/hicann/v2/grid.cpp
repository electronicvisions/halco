#include <algorithm>
#include <gtest/gtest.h>

#include "halco/hicann/v2/hicann.h"
#include "halco/hicann/v2/l1.h"
#include "halco/common/iter_all.h"

using namespace halco::common;
using namespace halco::hicann::v2;

template<typename T>
class GridCoordinateTest : public ::testing::Test
{};

typedef ::testing::Types<
	HICANNOnWafer,
	SynapseSwitchOnHICANN
> CoordinateGridTypes;

TYPED_TEST_CASE(GridCoordinateTest, CoordinateGridTypes);

template<typename T>
struct GridOrder
{
	bool operator()(T a, T b) const {
		return a.y() == b.y() ? (a.x() < b.x()) : (a.y() < b.y());
	}
};

TYPED_TEST(GridCoordinateTest, test_order) {
	std::vector< TypeParam > p;
	for (auto c : iter_all<TypeParam>()) {
		p.push_back(c);
	}
	EXPECT_TRUE(std::is_sorted(p.begin(), p.end()));
	EXPECT_TRUE(std::is_sorted(p.begin(), p.end(), GridOrder<TypeParam>()));
}

TYPED_TEST(GridCoordinateTest, test_xy_to_enum_to_xy) {
	using namespace halco::hicann::v2;
	for (auto c : iter_all<TypeParam>()) {
		TypeParam xy(c.x(), c.y());
		TypeParam e(xy.toEnum());
		EXPECT_EQ(c, xy) << c << " -> " << xy << " via x, y constructor failed";
		EXPECT_EQ(c, e) << c << " -> " << e << "via enum, via x, y constructor failed";
	}
}
