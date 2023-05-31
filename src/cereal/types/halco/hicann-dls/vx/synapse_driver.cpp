#include "cereal/types/halco/hicann-dls/vx/synapse_driver.h"

#include "halco/common/cerealization_geometry.h"
#include "halco/hicann-dls/vx/synapse_driver.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseDriverBlockOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseDriverOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CommonSynapseDriverConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseDriverSRAMTimingConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseDriverBlockOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseDriverOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CommonSynapseDriverConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseDriverSRAMTimingConfigOnDLS)

CEREAL_REGISTER_DYNAMIC_INIT(halco_hicann_dls_vx_synapse_driver)
