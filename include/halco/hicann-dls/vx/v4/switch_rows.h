#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/switch_rows.h"

namespace halco::hicann_dls::vx::v4 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V4 {

using ColumnCorrelationQuadOnSynram GENPYBIND(visible) =
    halco::hicann_dls::vx::ColumnCorrelationQuadOnSynram;
using ColumnCurrentQuadOnSynram GENPYBIND(visible) =
    halco::hicann_dls::vx::ColumnCurrentQuadOnSynram;
using ColumnCorrelationQuadOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::ColumnCorrelationQuadOnDLS;
using ColumnCurrentQuadOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::ColumnCurrentQuadOnDLS;

} // namespace halco::hicann_dls::vx::v4
