#include "cereal/types/halco/hicann-dls/vx/highspeed_link.h"

#include "cereal/types/halco/common/geometry.h"
#include "halco/hicann-dls/vx/highspeed_link.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::HicannARQStatusOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PerfTestOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PerfTestStatusOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PhyConfigFPGAOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PhyConfigChipOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PhyStatusOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CommonPhyConfigFPGAOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CommonPhyConfigChipOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::HicannARQStatusOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PerfTestOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PerfTestStatusOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PhyConfigFPGAOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PhyConfigChipOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PhyStatusOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CommonPhyConfigFPGAOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CommonPhyConfigChipOnDLS)

CEREAL_REGISTER_DYNAMIC_INIT(halco_hicann_dls_vx_highspeed_link)
