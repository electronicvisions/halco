#include <gtest/gtest.h>

#include <numeric>
#include <sstream>

#include <boost/serialization/nvp.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>

#include "halco/hicann/v2/neuron.h"
#include "halco/common/typed_array.h"
#include "halco/common/iter_all.h"

using namespace halco::common;
using namespace halco::hicann::v2;

typedef typed_array<size_t, NeuronBlockOnHICANN> nb_array_type;

static_assert(sizeof(nb_array_type) == sizeof(size_t) * NeuronBlockOnHICANN::size,
              "typed array has wrong size.");

static_assert(std::is_same<nb_array_type::key_type, NeuronBlockOnHICANN>::value,
	"typed array has wrong key_type.");
static_assert(std::is_same<nb_array_type::value_type, size_t>::value,
	"typed array has wrong value_type.");
static_assert(std::is_same<nb_array_type::reference, size_t&>::value,
	"typed array has wrong reference type.");
static_assert(std::is_same<nb_array_type::pointer, size_t*>::value,
	"typed array has wrong pointer type.");

TEST(TypedArray, IsComparable) {
	typed_array<bool, QuadOnHICANN> test;
	test.fill(false);
	test[QuadOnHICANN(0)] = true;
	typed_array<bool, QuadOnHICANN> other;
	other.fill(false);
	EXPECT_TRUE(other < test);
	other.fill(true);
	EXPECT_TRUE(test < other);
}

TEST(TypedArray, CanBeDefaultConstructed) {
	nb_array_type test;
	EXPECT_EQ(8, test.size());
}

TEST(TypedArray, CanBeAggregateInitialized) {
	nb_array_type test{{0, 1, 2, 3, 4, 5, 6, 7}};
	EXPECT_EQ(7, test.back());
}

TEST(TypedArray, CanBeCopied) {
	nb_array_type no_const{{0, 1, 2, 3, 4, 5, 6, 7}};
	const nb_array_type yes_const{{0, 1, 2, 3, 4, 5, 6, 7}};

	nb_array_type copy1 = no_const;
	EXPECT_EQ(7, copy1.back());
	nb_array_type copy2 = yes_const;
	EXPECT_EQ(7, copy2.back());
}

TEST(TypedArray, HasSerialization) {
	nb_array_type in, out;

	std::iota(in.begin(), in.end(), 42);

	std::ostringstream ostream;
	{
		boost::archive::binary_oarchive oa(ostream);
		oa << in;
	}

	std::istringstream istream(ostream.str());
	{
		boost::archive::binary_iarchive ia(istream);
		ia >> out;
	}

	ASSERT_EQ(in, out);
}

TEST(TypedArray, HasSerializationXML) {
	nb_array_type in, out;

	std::iota(in.begin(), in.end(), 42);

	std::ostringstream ostream;
	{
		boost::archive::xml_oarchive oa(ostream);
		oa << boost::serialization::make_nvp("obj", in);
	}

	std::istringstream istream(ostream.str());
	{
		boost::archive::xml_iarchive ia(istream);
		ia >> boost::serialization::make_nvp("obj", out);
	}

	ASSERT_EQ(in, out);
}

TEST(TypedArray, IsIterableInSameOrderAsIterAll) {
	typed_array<size_t, QuadOnHICANN> positions;

	size_t current = 0;
	for (QuadOnHICANN quad : iter_all<QuadOnHICANN>()) {
		positions[quad] = current++;
	}

	current = 0;
	for (size_t pos : positions) {
		EXPECT_EQ(current++, pos);
	}
}

TEST(TypedArray, WorksWithRantType) {
	typed_array<bool, QuadOnHICANN> test;
	test.fill(false);
	test[QuadOnHICANN(0)] = true;
	EXPECT_TRUE(test.at(QuadOnHICANN(0)));
	EXPECT_FALSE(test.at(QuadOnHICANN(1)));
	test.at(QuadOnHICANN(1)) = true;
	EXPECT_TRUE(test.at(QuadOnHICANN(1)));
	EXPECT_EQ(QuadOnHICANN::size, test.size());
}

TEST(TypedArray, WorksWithGridCoordinate) {
	typed_array<bool, NeuronOnHICANN> test;
	test.fill(false);
	test[NeuronOnHICANN(X(3), Y(1))] = true;
	EXPECT_TRUE(test.at(NeuronOnHICANN(X(3), Y(1))));
}

struct RantTypeWithOffset
    : public detail::RantWrapper<RantTypeWithOffset, size_t, 20, 10> {
	RantTypeWithOffset(size_t val) : rant_t(val) {}
};

TEST(TypedArray, WorksWithRantTypeWithOffset) {
	typed_array<bool, RantTypeWithOffset> test;
	test.fill(false);
	test[RantTypeWithOffset(10)] = true;
	EXPECT_TRUE(test.at(RantTypeWithOffset(10)));
	EXPECT_TRUE(*test.data());
}

enum class ABC : size_t {
	A, B, C, END
};

TEST(TypedArray, WorksWithEnum)
{
	typed_array<bool, ABC, typed_array_enum_support::limits<ABC, ABC::END>> test;
	test.fill(false);
	EXPECT_EQ(3, test.size());
	test[ABC::A] = true;
	EXPECT_TRUE(test.at(ABC::A));
}
