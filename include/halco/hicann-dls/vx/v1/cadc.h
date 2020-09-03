#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/cadc.h"
#include "halco/hicann-dls/vx/v1/synapse.h"

namespace halco::hicann_dls::vx::v1 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V1 {

#include "halco/hicann-dls/vx/cadc_ns_includes.h"

} // namespace halco::hicann_dls::vx::v1

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v1::CADCSampleQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v1::CADCChannelConfigOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v1::CADCChannelConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v1::CADCSampleQuadUnspecifiedReadoutOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v1::CADCSampleQuadOnSynram)

} // namespace std
