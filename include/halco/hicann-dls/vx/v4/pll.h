#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/pll.h"

namespace halco::hicann_dls::vx {
namespace v4 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V4 {

using PLLSelfTestOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::PLLSelfTestOnDLS;
using PLLSelfTestStatusOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::PLLSelfTestStatusOnDLS;
using PLLClockOutputBlockOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::PLLClockOutputBlockOnDLS;
using ADPLLOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::ADPLLOnDLS;
using PLLClockOutputOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::PLLClockOutputOnDLS;

} // namespace v4
} // namespace halco::hicann_dls::vx
