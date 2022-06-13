#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/cadc.h"
#include "halco/hicann-dls/vx/synapse.h"

namespace halco::hicann_dls::vx::v3 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V3 {

using SynapseRowOnSynapseDriver GENPYBIND(visible) =
    halco::hicann_dls::vx::SynapseRowOnSynapseDriver;
using SynapseRowOnSynram GENPYBIND(visible) = halco::hicann_dls::vx::SynapseRowOnSynram;
using SynapseRowOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SynapseRowOnDLS;
using SynapseWeightRowOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SynapseWeightRowOnDLS;
using SynapseLabelRowOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SynapseLabelRowOnDLS;
using SynapseCorrelationCalibRowOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::SynapseCorrelationCalibRowOnDLS;
using CorrelationResetRowOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CorrelationResetRowOnDLS;
using ColumnCorrelationRowOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::ColumnCorrelationRowOnDLS;
using ColumnCurrentRowOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::ColumnCurrentRowOnDLS;
using SynapticInputOnNeuron GENPYBIND(visible) = halco::hicann_dls::vx::SynapticInputOnNeuron;
using SynapseBiasSelectionOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::SynapseBiasSelectionOnDLS;
using SynapseWeightMatrixOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SynapseWeightMatrixOnDLS;
using SynapseLabelMatrixOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SynapseLabelMatrixOnDLS;
using SynapseCorrelationCalibMatrixOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::SynapseCorrelationCalibMatrixOnDLS;
using SynapseBlockOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SynapseBlockOnDLS;
using SynapseQuadColumnOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SynapseQuadColumnOnDLS;
using SynapseQuadOnSynram GENPYBIND(visible) = halco::hicann_dls::vx::SynapseQuadOnSynram;
using SynapseOnSynapseRow GENPYBIND(visible) = halco::hicann_dls::vx::SynapseOnSynapseRow;
using SynapseOnSynram GENPYBIND(visible) = halco::hicann_dls::vx::SynapseOnSynram;
using SynapseOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SynapseOnDLS;
using SynapseQuadOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SynapseQuadOnDLS;
using SynapseWeightQuadOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SynapseWeightQuadOnDLS;
using SynapseLabelQuadOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::SynapseLabelQuadOnDLS;
using SynapseCorrelationCalibQuadOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::SynapseCorrelationCalibQuadOnDLS;
using CorrelationResetOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::CorrelationResetOnDLS;

} // namespace halco::hicann_dls::vx::v3
