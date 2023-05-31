#include "cereal/types/halco/hicann-dls/vx/extoll.h"

#include "halco/common/cerealization_geometry.h"
#include "halco/hicann-dls/vx/extoll.h"
#include <cereal/archives/json.hpp>
#include <cereal/archives/portable_binary.hpp>
#include <cereal/types/polymorphic.hpp>

CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::EventSwitchSourceOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::EventSwitchReadoutOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::EventSwitchConfigOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommBucketTriggerConfigOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommBucketDestinationConfigOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommBucketNumPktsSentOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommBucketCounterResetOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommSplitOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommRouterLookupConfigOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommRouterConfigOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommRouterEventLossDisabledOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommRouterEventLossMisconfOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommRouterEventsRoutedOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommRouterCounterResetOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommDecoderNumEventsReceivedOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommDecoderCounterResetOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayConfigOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayNumEventsReceivedOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayEventLossFullOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayEventLossExpiredOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayCounterResetOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollBarrierTriggerReachedOnExtollNetwork)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollBarrierReleasedOnExtollNetwork)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollBarrierConfigOnExtollNetwork)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollInterruptControlOnExtollNetwork)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollInterruptConfigOnExtollNetwork)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollBarrierInterruptInportErrorCountOnFPGA)
CEREAL_REGISTER_TYPE(halco::hicann_dls::vx::ExtollBarrierInterruptInportCounterResetOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::EventSwitchSourceOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::EventSwitchReadoutOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::EventSwitchConfigOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommBucketTriggerConfigOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommBucketDestinationConfigOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommBucketNumPktsSentOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommBucketCounterResetOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommSplitOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommRouterLookupConfigOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommRouterConfigOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommRouterEventLossDisabledOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommRouterEventLossMisconfOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommRouterEventsRoutedOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommRouterCounterResetOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommDecoderNumEventsReceivedOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommDecoderCounterResetOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayConfigOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate,
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayNumEventsReceivedOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate,
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayEventLossFullOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate,
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayEventLossExpiredOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate,
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayCounterResetOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollBarrierTriggerReachedOnExtollNetwork)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollBarrierReleasedOnExtollNetwork)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollBarrierConfigOnExtollNetwork)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollInterruptControlOnExtollNetwork)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollInterruptConfigOnExtollNetwork)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate, halco::hicann_dls::vx::ExtollBarrierInterruptInportErrorCountOnFPGA)
CEREAL_REGISTER_POLYMORPHIC_RELATION(
    halco::common::Coordinate,
    halco::hicann_dls::vx::ExtollBarrierInterruptInportCounterResetOnFPGA)

CEREAL_REGISTER_DYNAMIC_INIT(halco_hicann_dls_vx_extoll)
