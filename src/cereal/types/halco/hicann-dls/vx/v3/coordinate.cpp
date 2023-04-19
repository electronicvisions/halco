#include "cereal/types/halco/hicann-dls/vx/v3/coordinate.h"

#include "halco/hicann-dls/vx/background.h"
#include "halco/hicann-dls/vx/barrier.h"
#include "halco/hicann-dls/vx/cadc.h"
#include "halco/hicann-dls/vx/capmem.h"
#include "halco/hicann-dls/vx/chip.h"
#include "halco/hicann-dls/vx/correlation.h"
#include "halco/hicann-dls/vx/current_dac.h"
#include "halco/hicann-dls/vx/dac.h"
#include "halco/hicann-dls/vx/event.h"
#include "halco/hicann-dls/vx/extoll.h"
#include "halco/hicann-dls/vx/fpga.h"
#include "halco/hicann-dls/vx/highspeed_link.h"
#include "halco/hicann-dls/vx/jtag.h"
#include "halco/hicann-dls/vx/madc.h"
#include "halco/hicann-dls/vx/memory_timing.h"
#include "halco/hicann-dls/vx/neuron.h"
#include "halco/hicann-dls/vx/omnibus.h"
#include "halco/hicann-dls/vx/padi.h"
#include "halco/hicann-dls/vx/pll.h"
#include "halco/hicann-dls/vx/ppu.h"
#include "halco/hicann-dls/vx/readout.h"
#include "halco/hicann-dls/vx/reset.h"
#include "halco/hicann-dls/vx/routing_crossbar.h"
#include "halco/hicann-dls/vx/switch_rows.h"
#include "halco/hicann-dls/vx/synapse.h"
#include "halco/hicann-dls/vx/synapse_driver.h"
#include "halco/hicann-dls/vx/synram.h"
#include "halco/hicann-dls/vx/timing.h"
#include "halco/hicann-dls/vx/ultra96.h"
#include "halco/hicann-dls/vx/v3/capmem.h"
#include "halco/hicann-dls/vx/vector_generator.h"
#include "halco/hicann-dls/vx/xboard.h"

#include "halco/common/cerealization_geometry.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::BarrierOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ResetJTAGTapOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::JTAGClockScalerOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::JTAGIdCodeOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PadMultiplexerConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ReadoutSourceSelectionOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ReadoutChainOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PPUMemoryOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PPUControlRegisterOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PPUStatusRegisterOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PPUMemoryBlockOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PPUMemoryWordOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::MADCControlOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::MADCConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::TCA9554OnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::TCA9554InputsOnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::TCA9554ConfigOnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::TCA9554ChannelOnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::AD5252OnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::AD5252ChannelOnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::AD5252ChannelConfigOnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::AD5252ChannelConfigPersistentOnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::DAC6573OnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::DAC6573ChannelOnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PLLSelfTestOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PLLSelfTestStatusOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PLLClockOutputBlockOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ADPLLOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SpikePack1ToChipOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SpikePack2ToChipOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SpikePack3ToChipOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseRowOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseWeightRowOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseLabelRowOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseCorrelationCalibRowOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CorrelationResetRowOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseBiasSelectionOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ColumnCorrelationRowOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ColumnCurrentRowOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseWeightMatrixOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseLabelMatrixOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseCorrelationCalibMatrixOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseBlockOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseQuadOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CorrelationResetOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseWeightQuadOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseLabelQuadOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseCorrelationCalibQuadOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::v3::CapMemCellOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CurrentDACOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CommonPADIBusConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CommonSTPConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PADIEventOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::DACOnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::DACChannelOnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::DACControlBlockOnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::DACChannelBlockOnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CapMemBlockOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CapMemBlockConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ReferenceGeneratorConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CapMemOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SystimeSyncOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SystimeSyncBaseOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::TimerOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronConfigBlockOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CommonNeuronBackendConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronBackendConfigBlockOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronResetBlockOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::BlockPostPulseOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SpikeCounterReadBlockOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SpikeCounterResetBlockOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronEventOutputOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronResetOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SpikeCounterReadOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SpikeCounterResetOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronSRAMTimingConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronBackendSRAMTimingConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronBlockOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::AtomicNeuronOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::LogicalNeuronOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronBackendConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronResetQuadOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::FPGASystimeSyncNumRetriesOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::FPGASystimeSyncLastRTTOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::FPGASystimeSyncLastAsicSystimeOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::FPGASystimeSyncActiveStateOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::FPGADeviceDNAOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExternalPPUMemoryByteOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExternalPPUMemoryQuadOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExternalPPUMemoryBlockOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExternalPPUMemoryOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NullPayloadReadableOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::EventRecordingConfigOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::InstructionTimeoutConfigOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SystimeCorrectionBarrierConfigOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SpikeIOConfigOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SpikeIOInputRouteOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SpikeIOOutputRouteOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::EventSwitchSourceOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::EventSwitchReadoutOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::EventSwitchConfigOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommBucketTriggerConfigOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommBucketDestinationConfigOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommBucketNumPktsSentOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommBucketCounterResetOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommSplitOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommRouterLookupConfigOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommRouterConfigOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommRouterEventLossDisabledOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommRouterEventLossMisconfOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommRouterEventsRoutedOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommRouterCounterResetOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommDecoderNumEventsReceivedOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommDecoderCounterResetOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayConfigOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayNumEventsReceivedOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayEventLossFullOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayEventLossExpiredOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayCounterResetOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollBarrierTriggerReachedOnExtollNetwork)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollBarrierReleasedOnExtollNetwork)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollBarrierConfigOnExtollNetwork)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollInterruptControlOnExtollNetwork)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollInterruptConfigOnExtollNetwork)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollBarrierInterruptInportErrorCountOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollBarrierInterruptInportCounterResetOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ChipOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynramOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CommonSynramConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ResetChipOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CrossbarOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CrossbarOutputConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CrossbarOutputOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CrossbarInputOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CrossbarNodeOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CommonCorrelationConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::VectorGeneratorOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::VectorGeneratorControlOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::VectorGeneratorLUTOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::VectorGeneratorLUTEntryOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::VectorGeneratorNotificationAddressOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::VectorGeneratorTriggerOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::VectorGeneratorFIFOWordOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::MemoryTimingOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::HicannARQStatusOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PerfTestOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PerfTestStatusOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PhyConfigFPGAOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PhyConfigChipOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PhyStatusOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CommonPhyConfigFPGAOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CommonPhyConfigChipOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ColumnCorrelationQuadOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ColumnCurrentQuadOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ShiftRegisterOnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::INA219OnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::INA219ConfigOnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::INA219StatusOnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PollingOmnibusBlockConfigOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PollingOmnibusBlockOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseDriverBlockOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseDriverOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CommonSynapseDriverConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseDriverSRAMTimingConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::BackgroundSpikeSourceOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CADCOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CADCConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CADCSampleRowOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CADCOffsetSRAMTimingConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CADCSamplesOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CADCSampleQuadOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CADCChannelConfigOnDLS)

CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::BarrierOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ResetJTAGTapOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::JTAGClockScalerOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::JTAGIdCodeOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PadMultiplexerConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ReadoutSourceSelectionOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ReadoutChainOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PPUMemoryOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PPUControlRegisterOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PPUStatusRegisterOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PPUMemoryBlockOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PPUMemoryWordOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::MADCControlOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::MADCConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::TCA9554OnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::TCA9554InputsOnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::TCA9554ConfigOnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::TCA9554ChannelOnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::AD5252OnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::AD5252ChannelOnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::AD5252ChannelConfigOnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::AD5252ChannelConfigPersistentOnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::DAC6573OnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::DAC6573ChannelOnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PLLSelfTestOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PLLSelfTestStatusOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PLLClockOutputBlockOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(halco::common::Coordinate, halco::hicann_dls::vx::ADPLLOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SpikePack1ToChipOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SpikePack2ToChipOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SpikePack3ToChipOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseRowOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseWeightRowOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseLabelRowOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseCorrelationCalibRowOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CorrelationResetRowOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseBiasSelectionOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ColumnCorrelationRowOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ColumnCurrentRowOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseWeightMatrixOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseLabelMatrixOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseCorrelationCalibMatrixOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseBlockOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseQuadOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CorrelationResetOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseWeightQuadOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseLabelQuadOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseCorrelationCalibQuadOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::v3::CapMemCellOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CurrentDACOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CommonPADIBusConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CommonSTPConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PADIEventOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(halco::common::Coordinate, halco::hicann_dls::vx::DACOnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::DACChannelOnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::DACControlBlockOnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::DACChannelBlockOnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CapMemBlockOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CapMemBlockConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ReferenceGeneratorConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(halco::common::Coordinate, halco::hicann_dls::vx::CapMemOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SystimeSyncOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SystimeSyncBaseOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(halco::common::Coordinate, halco::hicann_dls::vx::TimerOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NeuronConfigBlockOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CommonNeuronBackendConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NeuronBackendConfigBlockOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NeuronResetBlockOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::BlockPostPulseOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SpikeCounterReadBlockOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SpikeCounterResetBlockOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NeuronEventOutputOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NeuronResetOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SpikeCounterReadOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SpikeCounterResetOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NeuronSRAMTimingConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NeuronBackendSRAMTimingConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NeuronBlockOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::AtomicNeuronOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::LogicalNeuronOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NeuronConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NeuronBackendConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NeuronResetQuadOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::FPGASystimeSyncNumRetriesOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::FPGASystimeSyncLastRTTOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::FPGASystimeSyncLastAsicSystimeOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::FPGASystimeSyncActiveStateOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::FPGADeviceDNAOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExternalPPUMemoryByteOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExternalPPUMemoryQuadOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExternalPPUMemoryBlockOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExternalPPUMemoryOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NullPayloadReadableOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::EventRecordingConfigOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::InstructionTimeoutConfigOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SystimeCorrectionBarrierConfigOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SpikeIOConfigOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SpikeIOInputRouteOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SpikeIOOutputRouteOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::EventSwitchSourceOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::EventSwitchReadoutOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::EventSwitchConfigOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommBucketTriggerConfigOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommBucketDestinationConfigOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommBucketNumPktsSentOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommBucketCounterResetOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommSplitOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommRouterLookupConfigOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommRouterConfigOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommRouterEventLossDisabledOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommRouterEventLossMisconfOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommRouterEventsRoutedOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommRouterCounterResetOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommDecoderNumEventsReceivedOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommDecoderCounterResetOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayConfigOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate,
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayNumEventsReceivedOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate,
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayEventLossFullOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate,
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayEventLossExpiredOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate,
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayCounterResetOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollBarrierTriggerReachedOnExtollNetwork)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollBarrierReleasedOnExtollNetwork)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollBarrierConfigOnExtollNetwork)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollInterruptControlOnExtollNetwork)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollInterruptConfigOnExtollNetwork)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollBarrierInterruptInportErrorCountOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate,
    halco::hicann_dls::vx::ExtollBarrierInterruptInportCounterResetOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(halco::common::Coordinate, halco::hicann_dls::vx::ChipOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(halco::common::Coordinate, halco::hicann_dls::vx::SynramOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CommonSynramConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ResetChipOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CrossbarOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CrossbarOutputConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CrossbarOutputOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CrossbarInputOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CrossbarNodeOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CommonCorrelationConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::VectorGeneratorOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::VectorGeneratorControlOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::VectorGeneratorLUTOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::VectorGeneratorLUTEntryOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::VectorGeneratorNotificationAddressOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::VectorGeneratorTriggerOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::VectorGeneratorFIFOWordOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::MemoryTimingOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::HicannARQStatusOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PerfTestOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PerfTestStatusOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PhyConfigFPGAOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PhyConfigChipOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PhyStatusOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CommonPhyConfigFPGAOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CommonPhyConfigChipOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ColumnCorrelationQuadOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ColumnCurrentQuadOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ShiftRegisterOnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::INA219OnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::INA219ConfigOnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::INA219StatusOnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PollingOmnibusBlockConfigOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PollingOmnibusBlockOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseDriverBlockOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseDriverOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CommonSynapseDriverConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseDriverSRAMTimingConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::BackgroundSpikeSourceOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(halco::common::Coordinate, halco::hicann_dls::vx::CADCOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CADCConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CADCSampleRowOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CADCOffsetSRAMTimingConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CADCSamplesOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CADCSampleQuadOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CADCChannelConfigOnDLS)

CEREAL_REGISTER_DYNAMIC_INIT(halco_hicann_dls_vx_v3)
