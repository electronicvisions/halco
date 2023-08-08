#pragma once
#include "halco/common/genpybind.h"
#include "halco/hicann-dls/vx/extoll.h"

namespace halco::hicann_dls::vx::v4 GENPYBIND_TAG_HALCO_HICANN_DLS_VX_V4 {

using EventSwitchSourceOnFPGA GENPYBIND(visible) = halco::hicann_dls::vx::EventSwitchSourceOnFPGA;
using EventSwitchReadoutOnFPGA GENPYBIND(visible) = halco::hicann_dls::vx::EventSwitchReadoutOnFPGA;
using EventSwitchConfigOnFPGA GENPYBIND(visible) = halco::hicann_dls::vx::EventSwitchConfigOnFPGA;
using ExtollAddress GENPYBIND(visible) = halco::hicann_dls::vx::ExtollAddress;
using ExtollChipType GENPYBIND(visible) = halco::hicann_dls::vx::ExtollChipType;
using ExtollNodeId GENPYBIND(visible) = halco::hicann_dls::vx::ExtollNodeId;
using ExtollNodeIdOnExtollNetwork GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollNodeIdOnExtollNetwork;
using ExtollAddressOnExtollNetwork GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollAddressOnExtollNetwork;
using ExtollBarrierTriggerReachedOnExtollNodeId GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollBarrierTriggerReachedOnExtollNodeId;
using ExtollBarrierTriggerReachedOnExtollNetwork GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollBarrierTriggerReachedOnExtollNetwork;
using ExtollBarrierReleasedOnExtollNodeId GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollBarrierReleasedOnExtollNodeId;
using ExtollBarrierReleasedOnExtollNetwork GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollBarrierReleasedOnExtollNetwork;
using LinkOnExtollNode GENPYBIND(visible) = halco::hicann_dls::vx::LinkOnExtollNode;
using ExtollBarrierConfigOnExtollNodeId GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollBarrierConfigOnExtollNodeId;
using ExtollBarrierConfigOnExtollNetwork GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollBarrierConfigOnExtollNetwork;
using ExtollInterruptControlOnExtollNodeId GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollInterruptControlOnExtollNodeId;
using ExtollInterruptControlOnExtollNetwork GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollInterruptControlOnExtollNetwork;
using ExtollInterruptConfigOnExtollNodeId GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollInterruptConfigOnExtollNodeId;
using ExtollInterruptConfigOnExtollNetwork GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollInterruptConfigOnExtollNetwork;
using ExtollBarrierInterruptInportErrorCountOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollBarrierInterruptInportErrorCountOnFPGA;
using ExtollBarrierInterruptInportCounterResetOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollBarrierInterruptInportCounterResetOnFPGA;
using ExtollSpikeCommBucketTriggerConfigOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommBucketTriggerConfigOnFPGA;
using ExtollSpikeCommBucketDestinationConfigOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommBucketDestinationConfigOnFPGA;
using ExtollSpikeCommBucketNumPktsSentOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommBucketNumPktsSentOnFPGA;
using ExtollSpikeCommBucketNumEvtsRcvdOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommBucketNumEvtsRcvdOnFPGA;
using ExtollSpikeCommBucketCounterResetOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommBucketCounterResetOnFPGA;
using ExtollSpikeCommSplitOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommSplitOnFPGA;
using ExtollSpikeCommRouterLookupConfigOnSpikeCommSplit GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommRouterLookupConfigOnSpikeCommSplit;
using ExtollSpikeCommBucketNumEvtsRcvdOnSpikeCommSplit GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommBucketNumEvtsRcvdOnSpikeCommSplit;
using ExtollSpikeCommRouterLookupConfigOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommRouterLookupConfigOnFPGA;
using ExtollSpikeCommRouterConfigOnSpikeCommSplit GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommRouterConfigOnSpikeCommSplit;
using ExtollSpikeCommRouterConfigOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommRouterConfigOnFPGA;
using ExtollSpikeCommRouterEventLossDisabledOnSpikeCommSplit GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommRouterEventLossDisabledOnSpikeCommSplit;
using ExtollSpikeCommRouterEventLossDisabledOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommRouterEventLossDisabledOnFPGA;
using ExtollSpikeCommRouterEventLossMisconfOnSpikeCommSplit GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommRouterEventLossMisconfOnSpikeCommSplit;
using ExtollSpikeCommRouterEventLossMisconfOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommRouterEventLossMisconfOnFPGA;
using ExtollSpikeCommRouterEventsRoutedOnSpikeCommSplit GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommRouterEventsRoutedOnSpikeCommSplit;
using ExtollSpikeCommRouterEventsRoutedOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommRouterEventsRoutedOnFPGA;
using ExtollSpikeCommRouterCounterResetOnSpikeCommSplit GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommRouterCounterResetOnSpikeCommSplit;
using ExtollSpikeCommRouterCounterResetOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommRouterCounterResetOnFPGA;
using ExtollSpikeCommDecoderNumEventsReceivedOnSpikeCommSplit GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommDecoderNumEventsReceivedOnSpikeCommSplit;
using ExtollSpikeCommDecoderNumEventsReceivedOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommDecoderNumEventsReceivedOnFPGA;
using ExtollSpikeCommDecoderCounterResetOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommDecoderCounterResetOnFPGA;
using ExtollSpikeCommTimestampDelayConfigOnSpikeCommSplit GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayConfigOnSpikeCommSplit;
using ExtollSpikeCommTimestampDelayConfigOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayConfigOnFPGA;
using ExtollSpikeCommTimestampDelayNumEventsReceivedOnSpikeCommSplit GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayNumEventsReceivedOnSpikeCommSplit;
using ExtollSpikeCommTimestampDelayNumEventsReceivedOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayNumEventsReceivedOnFPGA;
using ExtollSpikeCommTimestampDelayEventLossFullOnSpikeCommSplit GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayEventLossFullOnSpikeCommSplit;
using ExtollSpikeCommTimestampDelayEventLossFullOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayEventLossFullOnFPGA;
using ExtollSpikeCommTimestampDelayEventLossExpiredOnSpikeCommSplit GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayEventLossExpiredOnSpikeCommSplit;
using ExtollSpikeCommTimestampDelayEventLossExpiredOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayEventLossExpiredOnFPGA;
using ExtollSpikeCommTimestampDelayCounterResetOnSpikeCommSplit GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayCounterResetOnSpikeCommSplit;
using ExtollSpikeCommTimestampDelayCounterResetOnFPGA GENPYBIND(visible) =
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayCounterResetOnFPGA;

} // namespace halco::hicann_dls::vx::v4
