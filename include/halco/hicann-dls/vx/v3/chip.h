#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/chip.h"

namespace halco::hicann_dls::vx {
namespace v3 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V3 {

using HemisphereOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::HemisphereOnDLS;
using ChipOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::ChipOnDLS;
using DLSGlobal GENPYBIND(visible) = halco::hicann_dls::vx::DLSGlobal;
using HemisphereGlobal GENPYBIND(visible) = halco::hicann_dls::vx::HemisphereGlobal;

} // namespace v3
} // namespace halco::hicann_dls::vx
