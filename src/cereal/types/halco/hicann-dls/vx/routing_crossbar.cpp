#include "cereal/types/halco/hicann-dls/vx/routing_crossbar.h"

#include "cereal/types/halco/common/geometry.h"
#include "halco/hicann-dls/vx/routing_crossbar.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CrossbarOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CrossbarOutputConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CrossbarOutputOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CrossbarInputOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CrossbarNodeOnDLS)

CEREAL_REGISTER_DYNAMIC_INIT(halco_hicann_dls_vx_routing_crossbar)
