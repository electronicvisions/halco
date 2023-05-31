#include "cereal/types/halco/hicann-dls/vx/readout.h"

#include "halco/common/cerealization_geometry.h"
#include "halco/hicann-dls/vx/readout.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PadMultiplexerConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ReadoutSourceSelectionOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ReadoutChainOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PadMultiplexerConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ReadoutSourceSelectionOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ReadoutChainOnDLS)

CEREAL_REGISTER_DYNAMIC_INIT(halco_hicann_dls_vx_readout)
