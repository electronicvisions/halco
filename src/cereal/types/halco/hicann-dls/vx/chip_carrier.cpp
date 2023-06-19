#include "cereal/types/halco/hicann-dls/vx/chip_carrier.h"

#include "halco/hicann-dls/vx/chip_carrier.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::TMP112StatusOnBoard)

CEREAL_REGISTER_DYNAMIC_INIT(halco_hicann_dls_vx_chip_carrier)
