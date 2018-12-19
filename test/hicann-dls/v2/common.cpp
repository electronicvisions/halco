#include <sstream>

#include <gtest/gtest.h>

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/serialization.hpp>

#ifndef PYPLUSPLUS
#include "halco/common/cerealization.h"
#endif

#include "halco/hicann-dls/v2/coordinates.h"

using namespace halco::hicann_dls::v2;

template <typename T>
class CommonCoordinateTest : public ::testing::Test {};

typedef ::testing::Types<
    CapMemCellOnDLS,
    CapMemColumnOnDLS,
    CapMemRowOnDLS,
    CapMemConfigOnDLS,
    CapMemOnDLS,
    CommonNeuronConfigOnDLS,
    ColumnBlockOnDLS,
    ColumnCorrelationSwitchOnColumnBlock,
    ColumnCorrelationSwitchOnDLS,
    ColumnCurrentSwitchOnColumnBlock,
    ColumnCurrentSwitchOnDLS,
    CorrelationConfigOnDLS,
    DACOnBoard,
    NeuronOnDLS,
    PPUMemoryWordOnDLS,
    PPUMemoryOnDLS,
    PPUControlRegisterOnDLS,
    PPUStatusRegisterOnDLS,
    SynapseBlockOnDLS,
    SynapseDriverOnDLS,
    SynapseDriverBlockOnDLS,
    SynapseColumnOnDLS,
    SynapseRowOnDLS,
    SynapseOnDLS,
    SynapseOnSynapseBlock,
    RateCounterOnDLS,
    RateCounterConfigOnDLS
> CoordinateTypes;
TYPED_TEST_CASE(CommonCoordinateTest, CoordinateTypes);

#define TEST_CEREAL
#define COMMON_FIXTURE_NAME CommonCoordinateTest
#include "test/HALCO_COMMON.cxx"
#undef COMMON_FIXTURE_NAME
#undef TEST_CEREAL
