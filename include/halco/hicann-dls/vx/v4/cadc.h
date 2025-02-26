#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/cadc.h"

namespace halco::hicann_dls::vx { namespace v4 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V4 {

using CADCOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CADCOnDLS;
using CADCConfigOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CADCConfigOnDLS;
using CADCChannelType GENPYBIND(visible) = halco::hicann_dls::vx::CADCChannelType;
using CADCReadoutType GENPYBIND(visible) = halco::hicann_dls::vx::CADCReadoutType;
using CADCChannelColumnOnSynram GENPYBIND(visible) =
    halco::hicann_dls::vx::CADCChannelColumnOnSynram;
using CADCSampleRowOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CADCSampleRowOnDLS;
using CADCOffsetSRAMTimingConfigOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::CADCOffsetSRAMTimingConfigOnDLS;
using CADCSamplesOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CADCSamplesOnDLS;
using CADCSampleQuadOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CADCSampleQuadOnDLS;
using CADCChannelConfigOnSynram GENPYBIND(visible) =
    halco::hicann_dls::vx::CADCChannelConfigOnSynram;
using CADCChannelConfigOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CADCChannelConfigOnDLS;
using CADCSampleQuadUnspecifiedReadoutOnSynram GENPYBIND(visible) =
    halco::hicann_dls::vx::CADCSampleQuadUnspecifiedReadoutOnSynram;
using CADCSampleQuadOnSynram GENPYBIND(visible) = halco::hicann_dls::vx::CADCSampleQuadOnSynram;

} // namespace v4
} // namespace halco::hicann_dls::vx
