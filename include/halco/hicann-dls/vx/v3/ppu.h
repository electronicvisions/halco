#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/ppu.h"

namespace halco::hicann_dls::vx::v3 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V3 {

using PPUOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::PPUOnDLS;
using PPUMemoryWordOnPPU GENPYBIND(visible) = halco::hicann_dls::vx::PPUMemoryWordOnPPU;
using PPUMemoryWordOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::PPUMemoryWordOnDLS;
using PPUMemoryBlockSize GENPYBIND(visible) = halco::hicann_dls::vx::PPUMemoryBlockSize;
using PPUMemoryBlockOnPPU GENPYBIND(visible) = halco::hicann_dls::vx::PPUMemoryBlockOnPPU;
using PPUMemoryBlockOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::PPUMemoryBlockOnDLS;
using PPUMemoryOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::PPUMemoryOnDLS;
using PPUControlRegisterOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::PPUControlRegisterOnDLS;
using PPUStatusRegisterOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::PPUStatusRegisterOnDLS;

} // namespace halco::hicann_dls::vx::v3
