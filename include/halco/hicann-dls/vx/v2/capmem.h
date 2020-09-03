#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/capmem.h"

namespace halco::hicann_dls::vx::v2 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V2 {

using CapMemColumnOnCapMemBlock GENPYBIND(visible) =
    halco::hicann_dls::vx::CapMemColumnOnCapMemBlock;
using CapMemRowOnCapMemBlock GENPYBIND(visible) = halco::hicann_dls::vx::CapMemRowOnCapMemBlock;
using CapMemBlockOnHemisphere GENPYBIND(visible) = halco::hicann_dls::vx::CapMemBlockOnHemisphere;
using CapMemBlockOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CapMemBlockOnDLS;
using CapMemBlockConfigOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CapMemBlockConfigOnDLS;
using CapMemCellOnCapMemBlock GENPYBIND(visible) = halco::hicann_dls::vx::CapMemCellOnCapMemBlock;
using CapMemCellOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CapMemCellOnDLS;
using ReferenceGeneratorConfigOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::ReferenceGeneratorConfigOnDLS;

} // namespace halco::hicann_dls::vx::v2
