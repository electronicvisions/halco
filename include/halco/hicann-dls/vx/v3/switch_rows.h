#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/v3/synapse.h"
#include "halco/hicann-dls/vx/v3/synram.h"

namespace halco::hicann_dls::vx::v3 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V3 {

#include "halco/hicann-dls/vx/switch_rows_ns_includes.h"

} // namespace halco::hicann_dls::vx::v3

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v3::ColumnCorrelationQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v3::ColumnCurrentQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v3::ColumnCorrelationQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v3::ColumnCurrentQuadOnDLS)

} // namespace std
