#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/fpga.h"

namespace halco::hicann_dls::vx::v2 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V2 {

using FPGADeviceDNAOnFPGA GENPYBIND(visible) = halco::hicann_dls::vx::FPGADeviceDNAOnFPGA;
using ExternalPPUMemoryByteOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExternalPPUMemoryByteOnFPGA;
using ExternalPPUMemoryBlockSize GENPYBIND(visible) =
    halco::hicann_dls::vx::ExternalPPUMemoryBlockSize;
using ExternalPPUMemoryBlockOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExternalPPUMemoryBlockOnFPGA;
using NullPayloadReadableOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::NullPayloadReadableOnFPGA;
using EventRecordingConfigOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::EventRecordingConfigOnFPGA;

} // namespace halco::hicann_dls::vx::v2
