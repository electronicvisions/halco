#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/cadc.h"
#include "halco/hicann-dls/vx/v2/synapse.h"

namespace halco::hicann_dls::vx::v2 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V2 {

#include "halco/hicann-dls/vx/cadc_ns_includes.h"

} // namespace halco::hicann_dls::vx::v2

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v2::CADCSampleQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v2::CADCChannelConfigOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v2::CADCChannelConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v2::CADCSampleQuadUnspecifiedReadoutOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v2::CADCSampleQuadOnSynram)

} // namespace std
