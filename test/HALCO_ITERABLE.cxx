// This was extracted because gtest only supports up to 50
// type parameters for ::testing::Types.
// Include this in your implementation file and make sure
// to #define COMMON_FIXTURE_NAME to the name of an appropriate
// test fixture.

#define TEST_THAT(name) TEST_THAT_EXPAND(COMMON_FIXTURE_NAME, name)
#define TEST_THAT_EXPAND(fixture, name) TYPED_TEST(fixture, name)

TEST_THAT(iter_all)
{
	size_t count = 0;
	for (auto c : iter_all<TypeParam>()) {
		++count;
		static_cast<void>(c);
	}
	EXPECT_LE(1, count);
}

#undef TEST_THAT
#undef TEST_THAT_EXPAND
