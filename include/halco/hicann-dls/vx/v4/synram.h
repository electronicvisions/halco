#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/synram.h"

namespace halco::hicann_dls::vx {
namespace v4 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V4 {

using SynramOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SynramOnDLS;
using CommonSynramConfigOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CommonSynramConfigOnDLS;

} // namespace v4
} // namespace halco::hicann_dls::vx
