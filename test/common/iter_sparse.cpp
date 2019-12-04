#include <gtest/gtest.h>

#include "halco/common/geometry.h"
#include "halco/common/iter_sparse.h"

struct RantWrapperInstance
    : public halco::common::detail::RantWrapper<RantWrapperInstance, uint_fast16_t, 123, 0>
{
	constexpr explicit RantWrapperInstance(uintmax_t const val = 0) : rant_t(val) {}
};

struct UniqueRantWrapperInstance
    : public halco::common::detail::RantWrapper<UniqueRantWrapperInstance, uint_fast16_t, 0, 0>
{
	constexpr explicit UniqueRantWrapperInstance(uintmax_t const val = 0) : rant_t(val) {}
};


TEST(iter_sparse, Sparse)
{
	std::vector<RantWrapperInstance> samples;
	for (auto const val : halco::common::iter_sparse<RantWrapperInstance>(21)) {
		samples.push_back(val);
	}
	EXPECT_EQ(samples.size(), 21);
	EXPECT_NE(
	    std::find(samples.begin(), samples.end(), RantWrapperInstance(RantWrapperInstance::min)),
	    samples.end());
	EXPECT_NE(
	    std::find(samples.begin(), samples.end(), RantWrapperInstance(RantWrapperInstance::max)),
	    samples.end());
}

TEST(iter_sparse, Full)
{
	std::vector<RantWrapperInstance> samples;
	for (auto const val : halco::common::iter_sparse<RantWrapperInstance>()) {
		samples.push_back(val);
	}
	EXPECT_EQ(samples.size(), RantWrapperInstance::size);
}

TEST(iter_sparse, UniqueSparse)
{
	std::vector<UniqueRantWrapperInstance> samples;
	for (auto const val : halco::common::iter_sparse<UniqueRantWrapperInstance>(1)) {
		samples.push_back(val);
	}
	EXPECT_EQ(samples.size(), UniqueRantWrapperInstance::size);
	EXPECT_NE(
	    std::find(
	        samples.begin(), samples.end(),
	        UniqueRantWrapperInstance(UniqueRantWrapperInstance::min)),
	    samples.end());
	EXPECT_NE(
	    std::find(
	        samples.begin(), samples.end(),
	        UniqueRantWrapperInstance(UniqueRantWrapperInstance::max)),
	    samples.end());
}

TEST(iter_sparse, UniqueFull)
{
	std::vector<UniqueRantWrapperInstance> samples;
	for (auto const val : halco::common::iter_sparse<UniqueRantWrapperInstance>()) {
		samples.push_back(val);
	}
	EXPECT_EQ(samples.size(), UniqueRantWrapperInstance::size);
}

TEST(iter_sparse, Throw)
{
	EXPECT_NO_THROW(halco::common::iter_sparse<RantWrapperInstance>());
	EXPECT_NO_THROW(halco::common::iter_sparse<RantWrapperInstance>(2));
	EXPECT_THROW(halco::common::iter_sparse<RantWrapperInstance>(1), std::runtime_error);
	EXPECT_NO_THROW(halco::common::iter_sparse<UniqueRantWrapperInstance>(1));
}
