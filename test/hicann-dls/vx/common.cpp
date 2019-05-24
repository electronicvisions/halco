#include <sstream>

#include <gtest/gtest.h>

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/serialization.hpp>

#ifndef PYPLUSPLUS
#include "halco/common/cerealization.h"
#endif

#include "halco/hicann-dls/vx/coordinates.h"

using namespace halco::hicann_dls::vx;

template <typename T>
class CommonCoordinateTest1 : public ::testing::Test
{};

template <typename T>
class CommonCoordinateTest2 : public ::testing::Test
{};

typedef ::testing::Types<
    ResetChipOnDLS,
    ResetJTAGTapOnDLS,
    JTAGClockScalerOnDLS,
    JTAGIdCodeOnDLS,
    JTAGPLLRegisterOnDLS,
    JTAGPhyRegisterOnDLS,
    PhyConfigChipOnDLS,
    PhyConfigFPGAOnDLS,
    CommonPhyConfigChipOnDLS,
    CommonPhyConfigFPGAOnDLS,
    ADPLLOnDLS,
    PLLClockOutputOnDLS,
    PLLOnDLS,
    TimerOnDLS,
    OmnibusChipOverJTAGAddress,
    OmnibusChipAddress,
    OmnibusFPGAAddress,
    ShiftRegisterOnBoard,
    SPIShiftRegisterOnBoard,
    SPIDACDataRegisterOnDAC,
    SPIDACControlRegisterOnDAC,
    SPIDACDataRegisterOnBoard,
    SPIDACControlRegisterOnBoard,
    ADCSourceOnBoard,
    LEDOnBoard,
    VDDOnBoard,
    DACOnBoard,
    DACChannelOnBoard,
    DACChannelOnDAC,
    ADCOnBoard,
    PPUOnDLS,
    PPUMemoryWordOnPPU,
    PPUMemoryWordOnDLS,
    PPUStatusRegisterOnPPU,
    PPUStatusRegisterOnDLS,
    PPUControlRegisterOnPPU,
    PPUControlRegisterOnDLS,
    CapMemCellOnDLS,
    CapMemCellOnCapMemBlock,
    CapMemColumnOnCapMemBlock,
    CapMemRowOnCapMemBlock,
    CapMemColumnOnDLS,
    CapMemRowOnDLS,
    CapMemBlockConfigOnDLS,
    CapMemBlockOnDLS,
    CommonNeuronConfigOnDLS,
    NeuronOnNeuronBlock,
    PerfTestOnFPGA,
    PerfTestStatusOnFPGA>
    CoordinateTypes1;

typedef ::testing::Types<
    PPUMemoryBlockOnPPU,
    PPUMemoryBlockOnDLS,
    PPUMemoryOnPPU,
    PPUMemoryOnDLS,
    NeuronBlockOnDLS,
    NeuronOnDLS,
    PerfTestStatusOnFPGA,
    SpikePack1ToChipOnDLS,
    SpikePack2ToChipOnDLS,
    SpikePack3ToChipOnDLS,
    SystimeSyncOnFPGA,
    SystimeSyncBaseOnDLS,
    CADCConfigOnDLS,
    NeuronLabel,
    SPL1Address>
    CoordinateTypes2;


TYPED_TEST_CASE(CommonCoordinateTest1, CoordinateTypes1);
TYPED_TEST_CASE(CommonCoordinateTest2, CoordinateTypes2);

#define TEST_CEREAL
#define COMMON_FIXTURE_NAME CommonCoordinateTest1
#include "test/HALCO_COMMON.cxx"
#undef COMMON_FIXTURE_NAME
#define COMMON_FIXTURE_NAME CommonCoordinateTest2
#include "test/HALCO_COMMON.cxx"
#undef COMMON_FIXTURE_NAME
#undef TEST_CEREAL
