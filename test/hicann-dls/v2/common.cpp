#include <sstream>

#include <gtest/gtest.h>

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/serialization.hpp>

#include <cereal/archives/json.hpp>

#include "halco/common/cerealization_geometry.h"

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
    CommonSynramConfigOnDLS,
    ColumnCorrelationBlockOnDLS,
    ColumnCorrelationSwitchOnColumnCorrelationBlock,
    ColumnCorrelationSwitchOnDLS,
    ColumnCurrentBlockOnDLS,
    ColumnCurrentSwitchOnColumnCurrentBlock,
    ColumnCurrentSwitchOnDLS,
    CorrelationConfigOnDLS,
    DACOnBoard,
    NeuronOnDLS,
    PPUMemoryWordOnDLS,
    PPUMemoryBlockOnDLS,
    PPUMemoryBlockSize,
    PPUMemoryOnDLS,
    PPUControlRegisterOnDLS,
    PPUStatusRegisterOnDLS,
    AcausalCorrelationBlockOnDLS,
    CausalCorrelationBlockOnDLS,
    SynapseBlockOnDLS,
    SynapseBlockColumnOnDLS,
    SynapseDriverOnDLS,
    SynapseDriverBlockOnDLS,
    SynapseColumnOnDLS,
    SynapseRowOnDLS,
    SynapseOnDLS,
    SynapseOnSynapseBlock,
    AcausalCorrelationOnDLS,
    AcausalCorrelationOnAcausalCorrelationBlock,
    CausalCorrelationOnDLS,
    CausalCorrelationOnCausalCorrelationBlock,
    RateCounterOnDLS,
    RateCounterConfigOnDLS>
    CoordinateTypes;
TYPED_TEST_CASE(CommonCoordinateTest, CoordinateTypes);

#define TEST_CEREAL
#define COMMON_FIXTURE_NAME CommonCoordinateTest
#include "test/HALCO_COMMON.cxx"
#undef COMMON_FIXTURE_NAME
#undef TEST_CEREAL
