#include "cereal/types/halco/hicann-dls/vx/ppu.h"

#include "cereal/types/halco/common/geometry.h"
#include "halco/hicann-dls/vx/ppu.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PPUMemoryOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PPUControlRegisterOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PPUStatusRegisterOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PPUMemoryBlockOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PPUMemoryWordOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PPUMemoryOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PPUControlRegisterOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PPUStatusRegisterOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PPUMemoryBlockOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PPUMemoryWordOnDLS)

CEREAL_REGISTER_DYNAMIC_INIT(halco_hicann_dls_vx_ppu)
