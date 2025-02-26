#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/omnibus.h"

namespace halco::hicann_dls::vx { namespace v4 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V4 {

using OmnibusChipOverJTAGAddress GENPYBIND(visible) =
    halco::hicann_dls::vx::OmnibusChipOverJTAGAddress;
using OmnibusAddress GENPYBIND(visible) = halco::hicann_dls::vx::OmnibusAddress;
using PollingOmnibusBlockOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::PollingOmnibusBlockOnFPGA;
using PollingOmnibusBlockConfigOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::PollingOmnibusBlockConfigOnFPGA;

} // namespace v4
} // namespace halco::hicann_dls::vx
