#include "cereal/types/halco/hicann-dls/vx/cadc.h"

#include "cereal/types/halco/common/geometry.h"
#include "halco/hicann-dls/vx/cadc.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CADCOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CADCConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CADCSampleRowOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CADCOffsetSRAMTimingConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CADCSamplesOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CADCSampleQuadOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CADCChannelConfigOnDLS)

CEREAL_REGISTER_POLYMORPHIC_RELATION(halco::common::Coordinate, halco::hicann_dls::vx::CADCOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CADCConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CADCSampleRowOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CADCOffsetSRAMTimingConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CADCSamplesOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CADCSampleQuadOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CADCChannelConfigOnDLS)

CEREAL_REGISTER_DYNAMIC_INIT(halco_hicann_dls_vx_cadc)
