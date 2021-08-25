#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/cadc.h"
#include "halco/hicann-dls/vx/v3/synapse.h"

namespace halco::hicann_dls::vx::v3 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V3 {

#include "halco/hicann-dls/vx/cadc_ns_includes.h"

} // namespace halco::hicann_dls::vx::v3

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v3::CADCSampleQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v3::CADCChannelConfigOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v3::CADCChannelConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v3::CADCSampleQuadUnspecifiedReadoutOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v3::CADCSampleQuadOnSynram)

} // namespace std
