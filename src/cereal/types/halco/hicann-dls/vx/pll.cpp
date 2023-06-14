#include "cereal/types/halco/hicann-dls/vx/pll.h"

#include "cereal/types/halco/common/geometry.h"
#include "halco/hicann-dls/vx/pll.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PLLSelfTestOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PLLSelfTestStatusOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::PLLClockOutputBlockOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ADPLLOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PLLSelfTestOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PLLSelfTestStatusOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::PLLClockOutputBlockOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(halco::common::Coordinate, halco::hicann_dls::vx::ADPLLOnDLS)

CEREAL_REGISTER_DYNAMIC_INIT(halco_hicann_dls_vx_pll)
