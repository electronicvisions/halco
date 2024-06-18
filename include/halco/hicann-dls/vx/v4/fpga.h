#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/fpga.h"

namespace halco::hicann_dls::vx::v4 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V4 {

using FPGASystimeSyncNumRetriesOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::FPGASystimeSyncNumRetriesOnFPGA;
using FPGASystimeSyncLastRTTOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::FPGASystimeSyncLastRTTOnFPGA;
using FPGASystimeSyncLastAsicSystimeOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::FPGASystimeSyncLastAsicSystimeOnFPGA;
using FPGASystimeSyncActiveStateOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::FPGASystimeSyncActiveStateOnFPGA;
using FPGADeviceDNAOnFPGA GENPYBIND(visible) = halco::hicann_dls::vx::FPGADeviceDNAOnFPGA;
using ExternalPPUMemoryByteOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExternalPPUMemoryByteOnFPGA;
using ExternalPPUMemoryQuadOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExternalPPUMemoryQuadOnFPGA;
using ExternalPPUMemoryBlockSize GENPYBIND(visible) =
    halco::hicann_dls::vx::ExternalPPUMemoryBlockSize;
using ExternalPPUMemoryBlockOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExternalPPUMemoryBlockOnFPGA;
using ExternalPPUDRAMMemoryByteOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExternalPPUDRAMMemoryByteOnFPGA;
using ExternalPPUDRAMMemoryQuadOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExternalPPUDRAMMemoryQuadOnFPGA;
using ExternalPPUDRAMMemoryBlockSize GENPYBIND(visible) =
    halco::hicann_dls::vx::ExternalPPUDRAMMemoryBlockSize;
using ExternalPPUDRAMMemoryBlockOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExternalPPUDRAMMemoryBlockOnFPGA;
using ExternalPPUMemoryOnFPGA GENPYBIND(visible) = halco::hicann_dls::vx::ExternalPPUMemoryOnFPGA;
using ExternalPPUDRAMMemoryOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExternalPPUDRAMMemoryOnFPGA;
using NullPayloadReadableOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::NullPayloadReadableOnFPGA;
using EventRecordingConfigOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::EventRecordingConfigOnFPGA;
using InstructionTimeoutConfigOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::InstructionTimeoutConfigOnFPGA;
using SystimeCorrectionBarrierConfigOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::SystimeCorrectionBarrierConfigOnFPGA;
using SpikeIOAddress GENPYBIND(visible) = halco::hicann_dls::vx::SpikeIOAddress;
using SpikeIOConfigOnFPGA GENPYBIND(visible) = halco::hicann_dls::vx::SpikeIOConfigOnFPGA;
using SpikeIOInputRouteOnFPGA GENPYBIND(visible) = halco::hicann_dls::vx::SpikeIOInputRouteOnFPGA;
using SpikeIOOutputRouteOnFPGA GENPYBIND(visible) = halco::hicann_dls::vx::SpikeIOOutputRouteOnFPGA;

} // namespace halco::hicann_dls::vx::v4
