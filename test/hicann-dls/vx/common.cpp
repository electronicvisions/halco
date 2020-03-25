#include <sstream>

#include <gtest/gtest.h>

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/serialization.hpp>

#include <cereal/archives/json.hpp>

#include "halco/common/cerealization_geometry.h"

#include "halco/hicann-dls/vx/coordinates.h"

using namespace halco::hicann_dls::vx;

template <typename T>
class CommonCoordinateTest1 : public ::testing::Test
{};

template <typename T>
class CommonCoordinateTest2 : public ::testing::Test
{};

template <typename T>
class CommonCoordinateTest3 : public ::testing::Test
{};

template <typename T>
class CommonCoordinateTest4 : public ::testing::Test
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
    PLLClockOutputBlockOnDLS,
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
    PPUStatusRegisterOnDLS,
    PPUControlRegisterOnDLS,
    CapMemCellOnDLS,
    CapMemCellOnCapMemBlock,
    CapMemColumnOnCapMemBlock,
    CapMemRowOnCapMemBlock,
    CapMemBlockConfigOnDLS,
    CapMemBlockOnDLS,
    CommonNeuronBackendConfigOnDLS,
    NeuronConfigOnNeuronConfigBlock,
    PerfTestOnFPGA,
    PerfTestStatusOnFPGA>
    CoordinateTypes1;

typedef ::testing::Types<
    PPUMemoryBlockOnPPU,
    PPUMemoryBlockOnDLS,
    PPUMemoryOnDLS,
    NeuronConfigBlockOnDLS,
    NeuronConfigOnDLS,
    PerfTestStatusOnFPGA,
    SpikePack1ToChipOnDLS,
    SpikePack2ToChipOnDLS,
    SpikePack3ToChipOnDLS,
    SystimeSyncOnFPGA,
    SystimeSyncBaseOnDLS,
    CADCConfigOnDLS,
    NeuronLabel,
    SPL1Address,
    BackgroundSpikeSourceOnDLS,
    CommonSynramConfigOnDLS,
    SpikePackFromFPGAOnDLS,
    MADCSamplePackFromFPGAOnDLS,
    NullPayloadReadableOnFPGA,
    EventRecordingConfigOnFPGA,
    HicannARQStatusOnFPGA,
    PhyStatusOnFPGA,
    I2CIdRegisterOnBoard,
    I2CINA219RoRegisterOnINA219,
    I2CINA219RwRegisterOnINA219,
    INA219OnBoard,
    I2CINA219RoRegisterOnBoard,
    I2CINA219RwRegisterOnBoard,
    FPGADeviceDNAOnFPGA,
    SynapseQuadColumnOnDLS,
    SynapseRowOnSynram,
    SynapseQuadOnSynram,
    SynramOnDLS,
    SynapseQuadOnDLS,
    SynapseDriverOnSynapseDriverBlock,
    SynapseDriverBlockOnDLS,
    SynapseDriverOnDLS,
    CommonSynapseDriverConfigOnDLS,
    PLLSelfTestOnDLS,
    PLLSelfTestStatusOnDLS,
    PADIBusBlockOnDLS,
    PADIBusOnPADIBusBlock,
    PADIEventOnDLS,
    CommonPADIBusConfigOnDLS,
    CommonSTPConfigOnDLS,
    CrossbarOutputConfigOnDLS,
    CrossbarOutputOnDLS,
    CrossbarL2OutputOnDLS,
    CrossbarInputOnDLS>
    CoordinateTypes2;

typedef ::testing::Types<
    NeuronBackendConfigBlockOnDLS,
    NeuronBackendConfigOnNeuronBackendConfigBlock,
    NeuronBackendConfigOnDLS,
    DACControlBlockOnBoard,
    DACChannelBlockOnBoard,
    EntryOnQuad,
    ColumnCorrelationQuadOnSynram,
    ColumnCurrentQuadOnSynram,
    ColumnCorrelationQuadOnDLS,
    ColumnCurrentQuadOnDLS,
    CrossbarNodeOnDLS,
    CADCChannelType,
    CADCReadoutType,
    CADCSampleQuadUnspecifiedReadoutOnSynram,
    CADCSampleQuadOnSynram,
    CADCSampleQuadOnDLS,
    CADCChannelColumnOnSynram,
    CADCChannelConfigOnSynram,
    CADCChannelConfigOnDLS,
    EventOutputOnNeuronBackendBlock,
    NeuronResetOnNeuronResetBlock,
    NeuronResetBlockOnDLS,
    NeuronResetOnDLS,
    SpikeCounterReadOnSpikeCounterReadBlock,
    SpikeCounterReadBlockOnDLS,
    SpikeCounterReadOnDLS,
    SpikeCounterResetOnSpikeCounterResetBlock,
    SpikeCounterResetBlockOnDLS,
    SpikeCounterResetOnDLS,
    CADCChannelConfigOnDLS,
    SynapseRowOnDLS,
    SynapseOnSynapseRow,
    CADCSampleRowOnDLS,
    SynapticInputOnNeuron,
    NeuronColumnOnDLS,
    NeuronRowOnDLS,
    AtomicNeuronOnDLS,
    DLSGlobal,
    HemisphereOnDLS,
    HemisphereGlobal,
    MADCControlOnDLS,
    SynapseBiasSelectionOnDLS,
    ReferenceGeneratorConfigOnDLS,
    PadMultiplexerConfigOnDLS,
    ReadoutSourceSelectionOnDLS,
    SourceMultiplexerOnReadoutSourceSelection,
    CorrelationResetOnDLS,
    NeuronResetQuadOnDLS,
    CommonCorrelationConfigOnDLS,
    ChipOnDLS>
    CoordinateTypes3;

typedef ::testing::Types<
    MADCConfigOnDLS,
    BlockPostPulseOnDLS,
    CorrelationResetRowOnDLS,
    CADCOffsetSRAMTimingConfigOnDLS,
    SynapseDriverSRAMTimingConfigOnDLS,
    NeuronSRAMTimingConfigOnDLS,
    NeuronBackendSRAMTimingConfigOnDLS>
    CoordinateTypes4;


TYPED_TEST_CASE(CommonCoordinateTest1, CoordinateTypes1);
TYPED_TEST_CASE(CommonCoordinateTest2, CoordinateTypes2);
TYPED_TEST_CASE(CommonCoordinateTest3, CoordinateTypes3);
TYPED_TEST_CASE(CommonCoordinateTest4, CoordinateTypes4);

#define TEST_CEREAL

#define COMMON_FIXTURE_NAME CommonCoordinateTest1
#include "HALCO_COMMON.cxx"
#undef COMMON_FIXTURE_NAME

#define COMMON_FIXTURE_NAME CommonCoordinateTest2
#include "HALCO_COMMON.cxx"
#undef COMMON_FIXTURE_NAME

#define COMMON_FIXTURE_NAME CommonCoordinateTest3
#include "HALCO_COMMON.cxx"
#undef COMMON_FIXTURE_NAME

#define COMMON_FIXTURE_NAME CommonCoordinateTest4
#include "HALCO_COMMON.cxx"
#undef COMMON_FIXTURE_NAME

#undef TEST_CEREAL
