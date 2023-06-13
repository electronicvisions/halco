#include <sstream>

#include <gtest/gtest.h>

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/serialization.hpp>

#include <cereal/archives/json.hpp>

#include "cereal/types/halco/common/geometry.h"

#include "halco/hicann-dls/vx/v3/coordinates.h"

using namespace halco::hicann_dls::vx::v3;

template <typename T>
class CommonCoordinateTest : public ::testing::Test
{};

#ifndef BUILD_ENV_COORDINATE_TYPES
#error "Requires comma separated list of coordinate types via build environment."
#endif

typedef ::testing::Types<BUILD_ENV_COORDINATE_TYPES> CoordinateTypes;


TYPED_TEST_CASE(CommonCoordinateTest, CoordinateTypes);

#define TEST_CEREAL

#define COMMON_FIXTURE_NAME CommonCoordinateTest
#include "HALCO_COMMON.cxx"
#undef COMMON_FIXTURE_NAME

#undef TEST_CEREAL
