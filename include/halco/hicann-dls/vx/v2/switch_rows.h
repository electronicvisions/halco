#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/v2/synapse.h"
#include "halco/hicann-dls/vx/v2/synram.h"

namespace halco::hicann_dls::vx::v2 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V2 {

#include "halco/hicann-dls/vx/switch_rows_ns_includes.h"

} // namespace halco::hicann_dls::vx::v2

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v2::ColumnCorrelationQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v2::ColumnCurrentQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v2::ColumnCorrelationQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v2::ColumnCurrentQuadOnDLS)

} // namespace std
