#include "cereal/types/halco/hicann-dls/vx/neuron.h"

#include "cereal/types/halco/common/geometry.h"
#include "halco/hicann-dls/vx/neuron.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronConfigBlockOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CommonNeuronBackendConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronBackendConfigBlockOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronResetBlockOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::BlockPostPulseOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SpikeCounterReadBlockOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SpikeCounterResetBlockOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronEventOutputOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronResetOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SpikeCounterReadOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SpikeCounterResetOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronSRAMTimingConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronBackendSRAMTimingConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronBlockOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::AtomicNeuronOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::LogicalNeuronOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronBackendConfigOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::NeuronResetQuadOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NeuronConfigBlockOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CommonNeuronBackendConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NeuronBackendConfigBlockOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NeuronResetBlockOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::BlockPostPulseOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SpikeCounterReadBlockOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SpikeCounterResetBlockOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NeuronEventOutputOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NeuronResetOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SpikeCounterReadOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SpikeCounterResetOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NeuronSRAMTimingConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NeuronBackendSRAMTimingConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NeuronBlockOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::AtomicNeuronOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::LogicalNeuronOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NeuronConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NeuronBackendConfigOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::NeuronResetQuadOnDLS)

CEREAL_REGISTER_DYNAMIC_INIT(halco_hicann_dls_vx_neuron)
