#include "cereal/types/halco/hicann-dls/vx/ultra96.h"

#include "cereal/types/halco/common/geometry.h"
#include "halco/hicann-dls/vx/ultra96.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::TCA9554OnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::TCA9554InputsOnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::TCA9554ConfigOnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::TCA9554ChannelOnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::AD5252OnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::AD5252ChannelOnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::AD5252ChannelConfigOnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::AD5252ChannelConfigPersistentOnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::DAC6573OnBoard)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::DAC6573ChannelOnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::TCA9554OnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::TCA9554InputsOnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::TCA9554ConfigOnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::TCA9554ChannelOnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::AD5252OnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::AD5252ChannelOnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::AD5252ChannelConfigOnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::AD5252ChannelConfigPersistentOnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::DAC6573OnBoard)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::DAC6573ChannelOnBoard)

CEREAL_REGISTER_DYNAMIC_INIT(halco_hicann_dls_vx_ultra96)
