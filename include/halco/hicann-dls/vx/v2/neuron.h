#pragma once
#include "halco/common/genpybind.h"
#include "halco/common/iter_all.h"
#include "halco/hicann-dls/vx/neuron.h"
#include "halco/hicann-dls/vx/v2/cadc.h"
#include "halco/hicann-dls/vx/v2/capmem.h"
#include "halco/hicann-dls/vx/v2/chip.h"
#include "halco/hicann-dls/vx/v2/correlation.h"
#include "halco/hicann-dls/vx/v2/padi.h"
#include "halco/hicann-dls/vx/v2/ppu.h"
#include "halco/hicann-dls/vx/v2/routing_crossbar.h"
#include "halco/hicann-dls/vx/v2/switch_rows.h"
#include "halco/hicann-dls/vx/v2/synapse.h"
#include "halco/hicann-dls/vx/v2/synapse_driver.h"
#include "halco/hicann-dls/vx/v2/synram.h"

namespace cereal {
class access;
} // namespace cereal

namespace halco::hicann_dls::vx::v2 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V2 {

#include "halco/hicann-dls/vx/neuron_ns_includes.h"

} // namespace halco::hicann_dls::vx::v2

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v2::NeuronColumnOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v2::AtomicNeuronOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v2::NeuronConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v2::NeuronBackendConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v2::NeuronResetQuadOnDLS)

} // namespace std
