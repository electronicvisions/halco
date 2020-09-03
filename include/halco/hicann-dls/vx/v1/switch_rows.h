#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/v1/synapse.h"
#include "halco/hicann-dls/vx/v1/synram.h"

namespace halco::hicann_dls::vx::v1 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V1 {

#include "halco/hicann-dls/vx/switch_rows_ns_includes.h"

} // namespace halco::hicann_dls::vx::v1

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v1::ColumnCorrelationQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v1::ColumnCurrentQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v1::ColumnCorrelationQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v1::ColumnCurrentQuadOnDLS)

} // namespace std
