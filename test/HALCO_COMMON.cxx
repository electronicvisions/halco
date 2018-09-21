// This was extracted because gtest only supports up to 50
// type parameters for ::testing::Types.
// Include this in your implementation file and make sure
// to #define COMMON_FIXTURE_NAME to the name of an appropriate
// test fixture.

#define TEST_THAT(name) TEST_THAT_EXPAND(COMMON_FIXTURE_NAME, name)
#define TEST_THAT_EXPAND(fixture, name) TYPED_TEST(fixture, name)

TEST_THAT(IsDefaultConstructible)
{
	TypeParam obj;
}

TEST_THAT(IsComparable) {
	TypeParam obj1, obj2;
	ASSERT_TRUE(obj1 == obj2);
	ASSERT_FALSE(obj1 < obj2);
}

TEST_THAT(IsAssignable) {
	TypeParam obj1, obj2;
	obj2 = obj1;
}

TEST_THAT(IsCopyable) {
	TypeParam obj1;
	TypeParam obj2(obj1);
	TypeParam obj3 = obj2;
	(void)obj3;
}

TEST_THAT(IsPrintable) {
	TypeParam obj;
	std::stringstream tmp;
	tmp << obj;
	ASSERT_FALSE(tmp.str().empty());
}

TEST_THAT(HasSerialization) {
	TypeParam obj, obj2;

	std::ostringstream ostream;
	{
		boost::archive::binary_oarchive oa(ostream);
		oa << boost::serialization::make_nvp("obj", obj);
	}

	std::istringstream istream(ostream.str());
	{
		boost::archive::binary_iarchive ia(istream);
		ia >> boost::serialization::make_nvp("obj", obj2);
	}

	ASSERT_EQ(obj2, obj);
}

#ifdef TEST_CEREAL
TEST_THAT(HasCerealization) {
	TypeParam obj, obj2;

	std::ostringstream ostream;
	{
		cereal::JSONOutputArchive oa(ostream);
		oa(obj);
	}

	std::istringstream istream(ostream.str());
	{
		cereal::JSONInputArchive ia(istream);
		ia(obj2);
	}

	ASSERT_EQ(obj2, obj);
}
#endif

#undef TEST_THAT
#undef TEST_THAT_EXPAND
