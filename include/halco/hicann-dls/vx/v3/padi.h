#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/padi.h"

namespace halco::hicann_dls::vx {
namespace v3 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V3 {

using PADIBusBlockOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::PADIBusBlockOnDLS;
using PADIBusOnPADIBusBlock GENPYBIND(visible) = halco::hicann_dls::vx::PADIBusOnPADIBusBlock;
using PADIBusOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::PADIBusOnDLS;
using CommonPADIBusConfigOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CommonPADIBusConfigOnDLS;
using CommonSTPConfigOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CommonSTPConfigOnDLS;
using PADIEventOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::PADIEventOnDLS;
using PADIRowSelectAddress GENPYBIND(visible) = halco::hicann_dls::vx::PADIRowSelectAddress;

} // namespace v3
} // namespace halco::hicann_dls::vx
