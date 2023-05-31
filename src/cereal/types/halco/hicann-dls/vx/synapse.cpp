#include "cereal/types/halco/hicann-dls/vx/synapse.h"

#include "halco/common/cerealization_geometry.h"
#include "halco/hicann-dls/vx/synapse.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseRowOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseWeightRowOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseLabelRowOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseCorrelationCalibRowOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CorrelationResetRowOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseBiasSelectionOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ColumnCorrelationRowOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ColumnCurrentRowOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseWeightMatrixOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseLabelMatrixOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseCorrelationCalibMatrixOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseBlockOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseQuadOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::CorrelationResetOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseWeightQuadOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseLabelQuadOnDLS)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::SynapseCorrelationCalibQuadOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseRowOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseWeightRowOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseLabelRowOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseCorrelationCalibRowOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CorrelationResetRowOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseBiasSelectionOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ColumnCorrelationRowOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ColumnCurrentRowOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseWeightMatrixOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseLabelMatrixOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseCorrelationCalibMatrixOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseBlockOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseQuadOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::CorrelationResetOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseWeightQuadOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseLabelQuadOnDLS)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::SynapseCorrelationCalibQuadOnDLS)

CEREAL_REGISTER_DYNAMIC_INIT(halco_hicann_dls_vx_synapse)
