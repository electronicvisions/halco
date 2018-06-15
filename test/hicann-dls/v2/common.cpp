#include <sstream>

#include <gtest/gtest.h>

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/serialization.hpp>

#include "halco/hicann-dls/v2/coordinates.h"

using namespace halco::hicann_dls::v2;

template <typename T>
class CommonCoordinateTest : public ::testing::Test {};

typedef ::testing::Types<
    CapMemCellOnDLS,
    CapMemColumnOnDLS,
    CapMemRowOnDLS,
    ColumnBlockOnDLS,
    ColumnCorrelationSwitchOnColumnBlock,
    ColumnCorrelationSwitchOnDLS,
    ColumnCurrentSwitchOnColumnBlock,
    ColumnCurrentSwitchOnDLS,
    DACOnBoard,
    NeuronOnDLS,
    PPUMemoryWordOnDLS,
    SynapseBlockOnDLS,
    SynapseDriverOnDLS,
    SynapseOnDLS,
    SynapseOnSynapseBlock
> CoordinateTypes;
TYPED_TEST_CASE(CommonCoordinateTest, CoordinateTypes);

#define COMMON_FIXTURE_NAME CommonCoordinateTest
#include "test/HALCO_COMMON.cxx"
#undef COMMON_FIXTURE_NAME
