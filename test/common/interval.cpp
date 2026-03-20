#include "halco/common/geometry.h"

#include "cereal/types/halco/common/geometry.h"
#include <cereal/archives/json.hpp>
#include <gtest/gtest.h>


namespace halco_common_interval_tests {

struct IntInterval : public halco::common::detail::Interval<IntInterval, int>
{
	IntInterval() = default;
	IntInterval(int min, int max) : interval_type(min, max) {}
};

struct FloatInterval : public halco::common::detail::Interval<FloatInterval, float>
{
	FloatInterval() = default;
	FloatInterval(float min, float max) : interval_type(min, max) {}
};

} // namespace halco_common_interval_tests

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco_common_interval_tests::IntInterval);
HALCO_GEOMETRY_HASH_CLASS(halco_common_interval_tests::FloatInterval);

} // namespace std

using namespace halco_common_interval_tests;


TEST(Interval, Integer)
{
	IntInterval interval_a;

	IntInterval interval_b(2, 4);

	EXPECT_LT(interval_a, interval_b);
	EXPECT_FALSE(interval_a > interval_b);
	EXPECT_NE(std::hash<IntInterval>{}(interval_a), std::hash<IntInterval>{}(interval_b));

	EXPECT_TRUE(interval_a.is_interval);

	EXPECT_EQ(interval_b.toMin(), 2);
	EXPECT_EQ(interval_b.toMax(), 4);

	EXPECT_NE(interval_a, interval_b);

	interval_a = IntInterval(2, 4);
	EXPECT_EQ(interval_a, interval_b);

	EXPECT_THROW(IntInterval(4, 2), std::runtime_error);

	EXPECT_TRUE(interval_b.contains(2));
	EXPECT_TRUE(interval_b.contains(3));
	EXPECT_TRUE(interval_b.contains(4));
	EXPECT_FALSE(interval_b.contains(1));
	EXPECT_FALSE(interval_b.contains(5));

	std::stringstream ss;
	ss << interval_b;
	EXPECT_EQ(ss.str(), "IntInterval([2, 4])");
}

TEST(Interval, Float)
{
	FloatInterval interval_a;

	FloatInterval interval_b(2., 4.);

	EXPECT_LT(interval_a, interval_b);
	EXPECT_FALSE(interval_a > interval_b);
	EXPECT_NE(std::hash<FloatInterval>{}(interval_a), std::hash<FloatInterval>{}(interval_b));

	EXPECT_EQ(interval_b.toMin(), 2.);
	EXPECT_EQ(interval_b.toMax(), 4.);

	EXPECT_NE(interval_a, interval_b);

	interval_a = FloatInterval(2., 4.);
	EXPECT_EQ(interval_a, interval_b);

	EXPECT_THROW(FloatInterval(4., 2.), std::runtime_error);

	EXPECT_TRUE(interval_b.contains(2.));
	EXPECT_TRUE(interval_b.contains(3.));
	EXPECT_TRUE(interval_b.contains(4.));
	EXPECT_FALSE(interval_b.contains(1.9));
	EXPECT_FALSE(interval_b.contains(4.1));

	std::stringstream ss;
	ss << interval_b;
	EXPECT_EQ(ss.str(), "FloatInterval([2, 4])");
}

TEST(Interval, CerealizeCoverage)
{
	IntInterval obj1(2, 4);
	IntInterval obj2;

	std::ostringstream ostream;
	{
		cereal::JSONOutputArchive oa(ostream);
		oa(obj1);
	}

	std::istringstream istream(ostream.str());
	{
		cereal::JSONInputArchive ia(istream);
		ia(obj2);
	}
	ASSERT_EQ(obj1, obj2);
}