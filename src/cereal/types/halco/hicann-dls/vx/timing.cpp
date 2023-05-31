#include "cereal/types/halco/hicann-dls/vx/timing.h"

#include "halco/common/cerealization_geometry.h"
#include "halco/hicann-dls/vx/timing.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SystimeSyncOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SystimeSyncBaseOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::TimerOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SystimeSyncOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SystimeSyncBaseOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(halco::common::Coordinate, halco::hicann_dls::vx::TimerOnDLS)

CEREAL_REGISTER_DYNAMIC_INIT(halco_hicann_dls_vx_timing)
