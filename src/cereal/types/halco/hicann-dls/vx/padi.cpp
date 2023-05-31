#include "cereal/types/halco/hicann-dls/vx/padi.h"

#include "halco/common/cerealization_geometry.h"
#include "halco/hicann-dls/vx/padi.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CommonPADIBusConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CommonSTPConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PADIEventOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CommonPADIBusConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CommonSTPConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PADIEventOnDLS)

CEREAL_REGISTER_DYNAMIC_INIT(halco_hicann_dls_vx_padi)
