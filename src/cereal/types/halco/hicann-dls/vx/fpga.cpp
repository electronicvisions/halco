#include "cereal/types/halco/hicann-dls/vx/fpga.h"

#include "cereal/types/halco/common/geometry.h"
#include "halco/hicann-dls/vx/fpga.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/polymorphic.hpp>

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

CEREAL_REGISTER_DYNAMIC_INIT(halco_hicann_dls_vx_fpga)
