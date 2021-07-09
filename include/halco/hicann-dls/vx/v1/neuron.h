#pragma once
#include "halco/common/genpybind.h"
#include "halco/common/iter_all.h"
#include "halco/hicann-dls/vx/neuron.h"
#include "halco/hicann-dls/vx/v1/cadc.h"
#include "halco/hicann-dls/vx/v1/capmem.h"
#include "halco/hicann-dls/vx/v1/chip.h"
#include "halco/hicann-dls/vx/v1/correlation.h"
#include "halco/hicann-dls/vx/v1/padi.h"
#include "halco/hicann-dls/vx/v1/ppu.h"
#include "halco/hicann-dls/vx/v1/routing_crossbar.h"
#include "halco/hicann-dls/vx/v1/switch_rows.h"
#include "halco/hicann-dls/vx/v1/synapse.h"
#include "halco/hicann-dls/vx/v1/synapse_driver.h"
#include "halco/hicann-dls/vx/v1/synram.h"

namespace cereal {
class access;
} // namespace cereal

namespace halco::hicann_dls::vx::v1 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V1 {

#include "halco/hicann-dls/vx/neuron_ns_includes.h"

} // namespace halco::hicann_dls::vx::v1

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v1::NeuronColumnOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v1::AtomicNeuronOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v1::NeuronConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v1::NeuronBackendConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::v1::NeuronResetQuadOnDLS)

} // namespace std
