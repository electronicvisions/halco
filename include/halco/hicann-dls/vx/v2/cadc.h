#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/cadc.h"

namespace halco::hicann_dls::vx::v2 GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

using CADCOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CADCOnDLS;
using CADCConfigOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CADCConfigOnDLS;
using CADCChannelType GENPYBIND(visible) = halco::hicann_dls::vx::CADCChannelType;
using CADCReadoutType GENPYBIND(visible) = halco::hicann_dls::vx::CADCReadoutType;
using CADCSampleQuadUnspecifiedReadoutOnSynram GENPYBIND(visible) =
    halco::hicann_dls::vx::CADCSampleQuadUnspecifiedReadoutOnSynram;
using CADCSampleQuadOnSynram GENPYBIND(visible) = halco::hicann_dls::vx::CADCSampleQuadOnSynram;
using CADCSampleQuadOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CADCSampleQuadOnDLS;
using CADCChannelColumnOnSynram GENPYBIND(visible) =
    halco::hicann_dls::vx::CADCChannelColumnOnSynram;
using CADCChannelConfigOnSynram GENPYBIND(visible) =
    halco::hicann_dls::vx::CADCChannelConfigOnSynram;
using CADCChannelConfigOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CADCChannelConfigOnDLS;
using CADCSampleRowOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CADCSampleRowOnDLS;
using CADCOffsetSRAMTimingConfigOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::CADCOffsetSRAMTimingConfigOnDLS;
using CADCSamplesOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CADCSamplesOnDLS;

} // namespace halco::hicann_dls::vx::v2
