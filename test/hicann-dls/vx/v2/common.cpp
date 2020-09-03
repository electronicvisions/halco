#include <sstream>

#include <gtest/gtest.h>

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/serialization.hpp>

#include <cereal/archives/json.hpp>

#include "halco/common/cerealization_geometry.h"

#include "halco/hicann-dls/vx/v2/coordinates.h"

using namespace halco::hicann_dls::vx::v2;

template <typename T>
class CommonCoordinateTest : public ::testing::Test
{};

#define COORDINATE(Name, Type) Name,
#define LAST_COORDINATE(Name, Type) Name >

typedef ::testing::Types <
#include "halco/hicann-dls/vx/v2/coordinates.def"
    CoordinateTypes;


TYPED_TEST_CASE(CommonCoordinateTest, CoordinateTypes);

#define TEST_CEREAL

#define COMMON_FIXTURE_NAME CommonCoordinateTest
#include "HALCO_COMMON.cxx"
#undef COMMON_FIXTURE_NAME

#undef TEST_CEREAL
