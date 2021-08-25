#pragma once
#include "halco/common/genpybind.h"
#include "halco/common/iter_all.h"
#include "halco/hicann-dls/vx/neuron.h"
#include "halco/hicann-dls/vx/v3/cadc.h"
#include "halco/hicann-dls/vx/v3/capmem.h"
#include "halco/hicann-dls/vx/v3/chip.h"
#include "halco/hicann-dls/vx/v3/correlation.h"
#include "halco/hicann-dls/vx/v3/padi.h"
#include "halco/hicann-dls/vx/v3/ppu.h"
#include "halco/hicann-dls/vx/v3/routing_crossbar.h"
#include "halco/hicann-dls/vx/v3/switch_rows.h"
#include "halco/hicann-dls/vx/v3/synapse.h"
#include "halco/hicann-dls/vx/v3/synapse_driver.h"
#include "halco/hicann-dls/vx/v3/synram.h"

namespace cereal {
class access;
} // namespace cereal

namespace halco::hicann_dls::vx::v3 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V3 {

#include "halco/hicann-dls/vx/neuron_ns_includes.h"

} // namespace halco::hicann_dls::vx::v3

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v3::NeuronColumnOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v3::AtomicNeuronOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v3::NeuronConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v3::NeuronBackendConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v3::NeuronResetQuadOnDLS)

} // namespace std
