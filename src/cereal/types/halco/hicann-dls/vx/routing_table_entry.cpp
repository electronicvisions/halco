#include "cereal/types/halco/hicann-dls/vx/routing_table_entry.h"

#include "cereal/types/halco/common/geometry.h"
#include "halco/hicann-dls/vx/routing_table_entry.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::OutputRoutingTableEntryOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::InputRoutingTableEntryOnFPGA)

CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::OutputRoutingTableEntryOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::InputRoutingTableEntryOnFPGA)

CEREAL_REGISTER_DYNAMIC_INIT(halco_hicann_dls_vx_routing_table_entry)
