#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/global_merger_matrix.h"

namespace halco::hicann_dls::vx { namespace v4 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V4 {

using GlobalMergerMatrixOnDLS GENPYBIND(visible) = halco::hicann_dls::vx::GlobalMergerMatrixOnDLS;
using GlobalMergerMatrixOutputConfigOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::GlobalMergerMatrixOutputConfigOnDLS;
using GlobalMergerMatrixOutputChannelOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::GlobalMergerMatrixOutputChannelOnDLS;
using GlobalMergerMatrixOutputEventCounterOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::GlobalMergerMatrixOutputEventCounterOnDLS;
using GlobalMergerMatrixInputChannelOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::GlobalMergerMatrixInputChannelOnDLS;
using GlobalMergerMatrixInputDropCounterOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::GlobalMergerMatrixInputDropCounterOnDLS;
using NeuronLabelToGL1EventLUTEntryOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::NeuronLabelToGL1EventLUTEntryOnDLS;
using GlobalMergerMatrixOutputOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::GlobalMergerMatrixOutputOnDLS;
using GlobalMergerMatrixInputOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::GlobalMergerMatrixInputOnDLS;
using GlobalMergerMatrixIntersectionOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::GlobalMergerMatrixIntersectionOnDLS;
using InputChannelOnGlobalMergerMatrixIntersection GENPYBIND(visible) =
    halco::hicann_dls::vx::InputChannelOnGlobalMergerMatrixIntersection;
using OutputChannelOnGlobalMergerMatrixIntersection GENPYBIND(visible) =
    halco::hicann_dls::vx::OutputChannelOnGlobalMergerMatrixIntersection;
using NodeOnGlobalMergerMatrixIntersection GENPYBIND(visible) =
    halco::hicann_dls::vx::NodeOnGlobalMergerMatrixIntersection;
using GlobalMergerMatrixNodeOnDLS GENPYBIND(visible) =
    halco::hicann_dls::vx::GlobalMergerMatrixNodeOnDLS;

} // namespace v4
} // namespace halco::hicann_dls::vx
