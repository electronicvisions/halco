#include "cereal/types/halco/hicann-dls/vx/event.h"

#include "cereal/types/halco/common/geometry.h"
#include "halco/hicann-dls/vx/event.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SpikePack1ToChipOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SpikePack2ToChipOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SpikePack3ToChipOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SpikePack1ToChipOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SpikePack2ToChipOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SpikePack3ToChipOnDLS)

CEREAL_REGISTER_DYNAMIC_INIT(halco_hicann_dls_vx_event)
