#include "cereal/types/halco/hicann-dls/vx/switch_rows.h"

#include "cereal/types/halco/common/geometry.h"
#include "halco/hicann-dls/vx/switch_rows.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ColumnCorrelationQuadOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ColumnCurrentQuadOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ColumnCorrelationQuadOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ColumnCurrentQuadOnDLS)

CEREAL_REGISTER_DYNAMIC_INIT(halco_hicann_dls_vx_switch_rows)
