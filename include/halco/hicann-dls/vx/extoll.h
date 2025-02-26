#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"
#include "halco/hicann-dls/vx/omnibus.h"
#include "hate/visibility.h"

namespace halco::hicann_dls { namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

// the RantWrapper is needed, as BaseType is not supported for mixins.
// We limit the range to the size of the Tourmalet-RF which has 23-bit address-space.
struct GENPYBIND(inline_base("*")) ExtollAddress
    : public common::detail::RantWrapper<ExtollAddress, uint64_t, 0x007f'ffffull, 0>
{
	constexpr explicit ExtollAddress(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) ExtollChipType
    : public common::detail::RantWrapper<ExtollChipType, uint8_t, 1, 0>
{
	constexpr explicit ExtollChipType(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const SYMBOL_VISIBLE ExtollChipType fpga;
	static const SYMBOL_VISIBLE ExtollChipType tourmalet;
};

HALCO_COORDINATE_MIXIN(ChipTypeMixin, ExtollChipType, chip_type)

struct GENPYBIND(inline_base("*")) ExtollNodeId
    : public common::detail::RantWrapper<ExtollNodeId, uint32_t, 0x1'0000ull, 0>
{
	constexpr explicit ExtollNodeId(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const SYMBOL_VISIBLE ExtollNodeId self;
};

struct GENPYBIND(inline_base("*ChipTypeMixin*")) ExtollNodeIdOnExtollNetwork
    : public ChipTypeMixin<ExtollNodeIdOnExtollNetwork, ExtollNodeId>
{
	explicit ExtollNodeIdOnExtollNetwork(
	    ExtollNodeId const& nodeid = ExtollNodeId(halco::hicann_dls::vx::ExtollNodeId::self),
	    ExtollChipType const& chiptype =
	        ExtollChipType(halco::hicann_dls::vx::ExtollChipType::fpga)) :
	    mixin_t(nodeid, chiptype)
	{}

	explicit ExtollNodeIdOnExtollNetwork(enum_type const& e) : mixin_t(e) {}

	ExtollNodeId toExtollNodeId() const
	{
		return This();
	}
};

HALCO_COORDINATE_MIXIN(NodeIdMixin, ExtollNodeIdOnExtollNetwork, node_id)

struct GENPYBIND(inline_base("*NodeIdMixin*")) ExtollAddressOnExtollNetwork
    : public NodeIdMixin<ExtollAddressOnExtollNetwork, ExtollAddress>
{
	ExtollAddressOnExtollNetwork() = default;

	explicit ExtollAddressOnExtollNetwork(
	    ExtollAddress const& extaddr,
	    ExtollNodeIdOnExtollNetwork const& nodeid =
	        ExtollNodeIdOnExtollNetwork(halco::hicann_dls::vx::ExtollNodeIdOnExtollNetwork::self)) :
	    mixin_t(extaddr, nodeid)
	{}

	explicit ExtollAddressOnExtollNetwork(enum_type const& e) : mixin_t(e) {}

	ExtollAddress toExtollAddress() const
	{
		return This();
	}
};

/*
 *  FPGA-Event-Switch:
 */

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    EventSwitchSourceOnFPGA
    : public common::detail::RantWrapper<EventSwitchSourceOnFPGA, uint_fast8_t, 2, 0>
    , common::CoordinateBase<EventSwitchSourceOnFPGA>
{
	constexpr explicit EventSwitchSourceOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const SYMBOL_VISIBLE EventSwitchSourceOnFPGA to_executor;
	static const SYMBOL_VISIBLE EventSwitchSourceOnFPGA to_asic;
	static const SYMBOL_VISIBLE EventSwitchSourceOnFPGA to_external;
};

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    EventSwitchReadoutOnFPGA
    : public common::detail::RantWrapper<EventSwitchReadoutOnFPGA, uint_fast8_t, 2, 0>
    , common::CoordinateBase<EventSwitchReadoutOnFPGA>
{
	constexpr explicit EventSwitchReadoutOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const SYMBOL_VISIBLE EventSwitchReadoutOnFPGA systime_offset;
	static const SYMBOL_VISIBLE EventSwitchReadoutOnFPGA global_systime;
	static const SYMBOL_VISIBLE EventSwitchReadoutOnFPGA last_global_systime;
};

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    EventSwitchConfigOnFPGA
    : public common::detail::RantWrapper<EventSwitchConfigOnFPGA, uint_fast8_t, 0, 0>
    , common::CoordinateBase<EventSwitchConfigOnFPGA>
{
	constexpr explicit EventSwitchConfigOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


/*
 * SPLITs:
 */


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    ExtollSpikeCommSplitOnFPGA
    : public common::detail::RantWrapper<ExtollSpikeCommSplitOnFPGA, uint_fast8_t, 1, 0>
    , common::CoordinateBase<ExtollSpikeCommSplitOnFPGA>
{
	constexpr explicit ExtollSpikeCommSplitOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


HALCO_COORDINATE_MIXIN(SpikeCommSplitMixin, ExtollSpikeCommSplitOnFPGA, pulse_comm_split)


/*
 *  Accumulation-BUCKET:
 */

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    ExtollSpikeCommBucketTriggerConfigOnFPGA
    : public common::detail::
          RantWrapper<ExtollSpikeCommBucketTriggerConfigOnFPGA, uint_fast8_t, 7, 0>
    , common::CoordinateBase<ExtollSpikeCommBucketTriggerConfigOnFPGA>
{
	constexpr explicit ExtollSpikeCommBucketTriggerConfigOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    ExtollSpikeCommBucketDestinationConfigOnFPGA
    : public common::detail::
          RantWrapper<ExtollSpikeCommBucketDestinationConfigOnFPGA, uint_fast8_t, 7, 0>
    , common::CoordinateBase<ExtollSpikeCommBucketDestinationConfigOnFPGA>
{
	constexpr explicit ExtollSpikeCommBucketDestinationConfigOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    ExtollSpikeCommBucketNumPktsSentOnFPGA
    : public common::detail::RantWrapper<ExtollSpikeCommBucketNumPktsSentOnFPGA, uint_fast8_t, 7, 0>
    , common::CoordinateBase<ExtollSpikeCommBucketNumPktsSentOnFPGA>
{
	constexpr explicit ExtollSpikeCommBucketNumPktsSentOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    ExtollSpikeCommBucketCounterResetOnFPGA
    : public common::detail::
          RantWrapper<ExtollSpikeCommBucketCounterResetOnFPGA, uint_fast8_t, 7, 0>
    , common::CoordinateBase<ExtollSpikeCommBucketCounterResetOnFPGA>
{
	constexpr explicit ExtollSpikeCommBucketCounterResetOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) ExtollSpikeCommBucketNumEvtsRcvdOnSpikeCommSplit
    : public common::detail::
          RantWrapper<ExtollSpikeCommBucketNumEvtsRcvdOnSpikeCommSplit, uint_fast8_t, 7, 0>
{
	constexpr explicit ExtollSpikeCommBucketNumEvtsRcvdOnSpikeCommSplit(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*"), inline_base("*CoordinateBase*"))
    ExtollSpikeCommBucketNumEvtsRcvdOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommBucketNumEvtsRcvdOnFPGA,
          ExtollSpikeCommBucketNumEvtsRcvdOnSpikeCommSplit>
    , common::CoordinateBase<ExtollSpikeCommBucketNumEvtsRcvdOnFPGA>
{
	ExtollSpikeCommBucketNumEvtsRcvdOnFPGA() = default;

	explicit ExtollSpikeCommBucketNumEvtsRcvdOnFPGA(
	    ExtollSpikeCommBucketNumEvtsRcvdOnSpikeCommSplit const& cnt_evts_rcvd,
	    ExtollSpikeCommSplitOnFPGA const& split = ExtollSpikeCommSplitOnFPGA()) :
	    mixin_t(cnt_evts_rcvd, split)
	{}

	explicit ExtollSpikeCommBucketNumEvtsRcvdOnFPGA(enum_type const& e) : mixin_t(e) {}

	ExtollSpikeCommBucketNumEvtsRcvdOnSpikeCommSplit
	toExtollSpikeCommBucketNumEvtsRcvdOnSpikeCommSplit() const
	{
		return This();
	}
};


/*
 *  SpikeComm-ROUTER:
 */


struct GENPYBIND(inline_base("*")) ExtollSpikeCommRouterLookupConfigOnSpikeCommSplit
    : public common::detail::RantWrapper<
          ExtollSpikeCommRouterLookupConfigOnSpikeCommSplit,
          uint_fast16_t,
          0x4000 - 1,
          0>
{
	constexpr explicit ExtollSpikeCommRouterLookupConfigOnSpikeCommSplit(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*"), inline_base("*CoordinateBase*"))
    ExtollSpikeCommRouterLookupConfigOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommRouterLookupConfigOnFPGA,
          ExtollSpikeCommRouterLookupConfigOnSpikeCommSplit>
    , common::CoordinateBase<ExtollSpikeCommRouterLookupConfigOnFPGA>
{
	ExtollSpikeCommRouterLookupConfigOnFPGA() = default;

	explicit ExtollSpikeCommRouterLookupConfigOnFPGA(
	    ExtollSpikeCommRouterLookupConfigOnSpikeCommSplit const& lookup_conf,
	    ExtollSpikeCommSplitOnFPGA const& split = ExtollSpikeCommSplitOnFPGA()) :
	    mixin_t(lookup_conf, split)
	{}

	explicit ExtollSpikeCommRouterLookupConfigOnFPGA(enum_type const& e) : mixin_t(e) {}

	ExtollSpikeCommRouterLookupConfigOnSpikeCommSplit
	toExtollSpikeCommRouterLookupConfigOnSpikeCommSplit() const
	{
		return This();
	}
};


struct GENPYBIND(inline_base("*")) ExtollSpikeCommRouterConfigOnSpikeCommSplit
    : public common::detail::
          RantWrapper<ExtollSpikeCommRouterConfigOnSpikeCommSplit, uint_fast8_t, 0, 0>
{
	constexpr explicit ExtollSpikeCommRouterConfigOnSpikeCommSplit(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*"), inline_base("*CoordinateBase*"))
    ExtollSpikeCommRouterConfigOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommRouterConfigOnFPGA,
          ExtollSpikeCommRouterConfigOnSpikeCommSplit>
    , common::CoordinateBase<ExtollSpikeCommRouterConfigOnFPGA>
{
	explicit ExtollSpikeCommRouterConfigOnFPGA(
	    ExtollSpikeCommSplitOnFPGA const& split = ExtollSpikeCommSplitOnFPGA()) :
	    mixin_t(ExtollSpikeCommRouterConfigOnSpikeCommSplit(), split)
	{}

	explicit ExtollSpikeCommRouterConfigOnFPGA(enum_type const& e) : mixin_t(e) {}

	ExtollSpikeCommRouterConfigOnSpikeCommSplit toExtollSpikeCommRouterConfigOnSpikeCommSplit()
	    const
	{
		return This();
	}
};


struct GENPYBIND(inline_base("*")) ExtollSpikeCommRouterEventLossDisabledOnSpikeCommSplit
    : public common::detail::
          RantWrapper<ExtollSpikeCommRouterEventLossDisabledOnSpikeCommSplit, uint_fast8_t, 0, 0>
{
	constexpr explicit ExtollSpikeCommRouterEventLossDisabledOnSpikeCommSplit(
	    uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*"), inline_base("*CoordinateBase*"))
    ExtollSpikeCommRouterEventLossDisabledOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommRouterEventLossDisabledOnFPGA,
          ExtollSpikeCommRouterEventLossDisabledOnSpikeCommSplit>
    , common::CoordinateBase<ExtollSpikeCommRouterEventLossDisabledOnFPGA>
{
	explicit ExtollSpikeCommRouterEventLossDisabledOnFPGA(
	    ExtollSpikeCommSplitOnFPGA const& split = ExtollSpikeCommSplitOnFPGA()) :
	    mixin_t(ExtollSpikeCommRouterEventLossDisabledOnSpikeCommSplit(), split)
	{}

	explicit ExtollSpikeCommRouterEventLossDisabledOnFPGA(enum_type const& e) : mixin_t(e) {}

	ExtollSpikeCommRouterEventLossDisabledOnSpikeCommSplit
	toExtollSpikeCommRouterEventLossDisabledOnSpikeCommSplit() const
	{
		return This();
	}
};


struct GENPYBIND(inline_base("*")) ExtollSpikeCommRouterEventLossMisconfOnSpikeCommSplit
    : public common::detail::
          RantWrapper<ExtollSpikeCommRouterEventLossMisconfOnSpikeCommSplit, uint_fast8_t, 0, 0>
{
	constexpr explicit ExtollSpikeCommRouterEventLossMisconfOnSpikeCommSplit(
	    uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*"), inline_base("*CoordinateBase*"))
    ExtollSpikeCommRouterEventLossMisconfOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommRouterEventLossMisconfOnFPGA,
          ExtollSpikeCommRouterEventLossMisconfOnSpikeCommSplit>
    , common::CoordinateBase<ExtollSpikeCommRouterEventLossMisconfOnFPGA>
{
	explicit ExtollSpikeCommRouterEventLossMisconfOnFPGA(
	    ExtollSpikeCommSplitOnFPGA const& split = ExtollSpikeCommSplitOnFPGA()) :
	    mixin_t(ExtollSpikeCommRouterEventLossMisconfOnSpikeCommSplit(), split)
	{}

	explicit ExtollSpikeCommRouterEventLossMisconfOnFPGA(enum_type const& e) : mixin_t(e) {}

	ExtollSpikeCommRouterEventLossMisconfOnSpikeCommSplit
	toExtollSpikeCommRouterEventLossMisconfOnSpikeCommSplit() const
	{
		return This();
	}
};

struct GENPYBIND(inline_base("*")) ExtollSpikeCommRouterEventsRoutedOnSpikeCommSplit
    : public common::detail::
          RantWrapper<ExtollSpikeCommRouterEventsRoutedOnSpikeCommSplit, uint_fast8_t, 0, 0>
{
	constexpr explicit ExtollSpikeCommRouterEventsRoutedOnSpikeCommSplit(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*"), inline_base("*CoordinateBase*"))
    ExtollSpikeCommRouterEventsRoutedOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommRouterEventsRoutedOnFPGA,
          ExtollSpikeCommRouterEventsRoutedOnSpikeCommSplit>
    , common::CoordinateBase<ExtollSpikeCommRouterEventsRoutedOnFPGA>
{
	explicit ExtollSpikeCommRouterEventsRoutedOnFPGA(
	    ExtollSpikeCommSplitOnFPGA const& split = ExtollSpikeCommSplitOnFPGA()) :
	    mixin_t(ExtollSpikeCommRouterEventsRoutedOnSpikeCommSplit(), split)
	{}

	explicit ExtollSpikeCommRouterEventsRoutedOnFPGA(enum_type const& e) : mixin_t(e) {}

	ExtollSpikeCommRouterEventsRoutedOnSpikeCommSplit
	toExtollSpikeCommRouterEventsRoutedOnSpikeCommSplit() const
	{
		return This();
	}
};

struct GENPYBIND(inline_base("*")) ExtollSpikeCommRouterCounterResetOnSpikeCommSplit
    : public common::detail::
          RantWrapper<ExtollSpikeCommRouterCounterResetOnSpikeCommSplit, uint_fast8_t, 0, 0>
{
	constexpr explicit ExtollSpikeCommRouterCounterResetOnSpikeCommSplit(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*"), inline_base("*CoordinateBase*"))
    ExtollSpikeCommRouterCounterResetOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommRouterCounterResetOnFPGA,
          ExtollSpikeCommRouterCounterResetOnSpikeCommSplit>
    , common::CoordinateBase<ExtollSpikeCommRouterCounterResetOnFPGA>
{
	explicit ExtollSpikeCommRouterCounterResetOnFPGA(
	    ExtollSpikeCommSplitOnFPGA const& split = ExtollSpikeCommSplitOnFPGA()) :
	    mixin_t(ExtollSpikeCommRouterCounterResetOnSpikeCommSplit(), split)
	{}

	explicit ExtollSpikeCommRouterCounterResetOnFPGA(enum_type const& e) : mixin_t(e) {}

	ExtollSpikeCommRouterCounterResetOnSpikeCommSplit
	toExtollSpikeCommRouterCounterResetOnSpikeCommSplit() const
	{
		return This();
	}
};


/*
 *  SpikeComm-DECODER:
 */

struct GENPYBIND(inline_base("*")) ExtollSpikeCommDecoderNumEventsReceivedOnSpikeCommSplit
    : public common::detail::
          RantWrapper<ExtollSpikeCommDecoderNumEventsReceivedOnSpikeCommSplit, uint_fast8_t, 0, 0>
{
	constexpr explicit ExtollSpikeCommDecoderNumEventsReceivedOnSpikeCommSplit(
	    uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*"), inline_base("*CoordinateBase*"))
    ExtollSpikeCommDecoderNumEventsReceivedOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommDecoderNumEventsReceivedOnFPGA,
          ExtollSpikeCommDecoderNumEventsReceivedOnSpikeCommSplit>
    , common::CoordinateBase<ExtollSpikeCommDecoderNumEventsReceivedOnFPGA>
{
	explicit ExtollSpikeCommDecoderNumEventsReceivedOnFPGA(
	    ExtollSpikeCommSplitOnFPGA const& split = ExtollSpikeCommSplitOnFPGA()) :
	    mixin_t(ExtollSpikeCommDecoderNumEventsReceivedOnSpikeCommSplit(), split)
	{}

	explicit ExtollSpikeCommDecoderNumEventsReceivedOnFPGA(enum_type const& e) : mixin_t(e) {}

	ExtollSpikeCommDecoderNumEventsReceivedOnSpikeCommSplit
	toExtollSpikeCommDecoderNumEventsReceivedOnSpikeCommSplit() const
	{
		return This();
	}
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    ExtollSpikeCommDecoderCounterResetOnFPGA
    : public common::detail::
          RantWrapper<ExtollSpikeCommDecoderCounterResetOnFPGA, uint_fast8_t, 0, 0>
    , halco::common::CoordinateBase<ExtollSpikeCommDecoderCounterResetOnFPGA>
{
	constexpr explicit ExtollSpikeCommDecoderCounterResetOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


/*
 *  SpikeComm-Timestamp-DELAYBUF:
 */

struct GENPYBIND(inline_base("*")) ExtollSpikeCommTimestampDelayConfigOnSpikeCommSplit
    : public common::detail::
          RantWrapper<ExtollSpikeCommTimestampDelayConfigOnSpikeCommSplit, uint_fast8_t, 0, 0>
{
	constexpr explicit ExtollSpikeCommTimestampDelayConfigOnSpikeCommSplit(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*"), inline_base("*CoordinateBase*"))
    ExtollSpikeCommTimestampDelayConfigOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommTimestampDelayConfigOnFPGA,
          ExtollSpikeCommTimestampDelayConfigOnSpikeCommSplit>
    , common::CoordinateBase<ExtollSpikeCommTimestampDelayConfigOnFPGA>
{
	explicit ExtollSpikeCommTimestampDelayConfigOnFPGA(
	    ExtollSpikeCommSplitOnFPGA const& split = ExtollSpikeCommSplitOnFPGA()) :
	    mixin_t(ExtollSpikeCommTimestampDelayConfigOnSpikeCommSplit(), split)
	{}

	explicit ExtollSpikeCommTimestampDelayConfigOnFPGA(enum_type const& e) : mixin_t(e) {}

	ExtollSpikeCommTimestampDelayConfigOnSpikeCommSplit
	toExtollSpikeCommTimestampDelayConfigOnSpikeCommSplit() const
	{
		return This();
	}
};


struct GENPYBIND(inline_base("*")) ExtollSpikeCommTimestampDelayNumEventsReceivedOnSpikeCommSplit
    : public common::detail::RantWrapper<
          ExtollSpikeCommTimestampDelayNumEventsReceivedOnSpikeCommSplit,
          uint_fast8_t,
          0,
          0>
{
	constexpr explicit ExtollSpikeCommTimestampDelayNumEventsReceivedOnSpikeCommSplit(
	    uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*"), inline_base("*CoordinateBase*"))
    ExtollSpikeCommTimestampDelayNumEventsReceivedOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommTimestampDelayNumEventsReceivedOnFPGA,
          ExtollSpikeCommTimestampDelayNumEventsReceivedOnSpikeCommSplit>
    , common::CoordinateBase<ExtollSpikeCommTimestampDelayNumEventsReceivedOnFPGA>
{
	explicit ExtollSpikeCommTimestampDelayNumEventsReceivedOnFPGA(
	    ExtollSpikeCommSplitOnFPGA const& split = ExtollSpikeCommSplitOnFPGA()) :
	    mixin_t(ExtollSpikeCommTimestampDelayNumEventsReceivedOnSpikeCommSplit(), split)
	{}

	explicit ExtollSpikeCommTimestampDelayNumEventsReceivedOnFPGA(enum_type const& e) : mixin_t(e)
	{}

	ExtollSpikeCommTimestampDelayNumEventsReceivedOnSpikeCommSplit
	toExtollSpikeCommTimestampDelayNumEventsReceivedOnSpikeCommSplit() const
	{
		return This();
	}
};


struct GENPYBIND(inline_base("*")) ExtollSpikeCommTimestampDelayEventLossFullOnSpikeCommSplit
    : public common::detail::RantWrapper<
          ExtollSpikeCommTimestampDelayEventLossFullOnSpikeCommSplit,
          uint_fast8_t,
          0,
          0>
{
	constexpr explicit ExtollSpikeCommTimestampDelayEventLossFullOnSpikeCommSplit(
	    uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*"), inline_base("*CoordinateBase*"))
    ExtollSpikeCommTimestampDelayEventLossFullOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommTimestampDelayEventLossFullOnFPGA,
          ExtollSpikeCommTimestampDelayEventLossFullOnSpikeCommSplit>
    , common::CoordinateBase<ExtollSpikeCommTimestampDelayEventLossFullOnFPGA>
{
	explicit ExtollSpikeCommTimestampDelayEventLossFullOnFPGA(
	    ExtollSpikeCommSplitOnFPGA const& split = ExtollSpikeCommSplitOnFPGA()) :
	    mixin_t(ExtollSpikeCommTimestampDelayEventLossFullOnSpikeCommSplit(), split)
	{}

	explicit ExtollSpikeCommTimestampDelayEventLossFullOnFPGA(enum_type const& e) : mixin_t(e) {}

	ExtollSpikeCommTimestampDelayEventLossFullOnSpikeCommSplit
	toExtollSpikeCommTimestampDelayEventLossFullOnSpikeCommSplit() const
	{
		return This();
	}
};


struct GENPYBIND(inline_base("*")) ExtollSpikeCommTimestampDelayEventLossExpiredOnSpikeCommSplit
    : public common::detail::RantWrapper<
          ExtollSpikeCommTimestampDelayEventLossExpiredOnSpikeCommSplit,
          uint_fast8_t,
          0,
          0>
{
	constexpr explicit ExtollSpikeCommTimestampDelayEventLossExpiredOnSpikeCommSplit(
	    uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*"), inline_base("*CoordinateBase*"))
    ExtollSpikeCommTimestampDelayEventLossExpiredOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommTimestampDelayEventLossExpiredOnFPGA,
          ExtollSpikeCommTimestampDelayEventLossExpiredOnSpikeCommSplit>
    , common::CoordinateBase<ExtollSpikeCommTimestampDelayEventLossExpiredOnFPGA>
{
	explicit ExtollSpikeCommTimestampDelayEventLossExpiredOnFPGA(
	    ExtollSpikeCommSplitOnFPGA const& split = ExtollSpikeCommSplitOnFPGA()) :
	    mixin_t(ExtollSpikeCommTimestampDelayEventLossExpiredOnSpikeCommSplit(), split)
	{}

	explicit ExtollSpikeCommTimestampDelayEventLossExpiredOnFPGA(enum_type const& e) : mixin_t(e) {}

	ExtollSpikeCommTimestampDelayEventLossExpiredOnSpikeCommSplit
	toExtollSpikeCommTimestampDelayEventLossExpiredOnSpikeCommSplit() const
	{
		return This();
	}
};


struct GENPYBIND(inline_base("*")) ExtollSpikeCommTimestampDelayCounterResetOnSpikeCommSplit
    : public common::detail::
          RantWrapper<ExtollSpikeCommTimestampDelayCounterResetOnSpikeCommSplit, uint_fast8_t, 0, 0>
{
	constexpr explicit ExtollSpikeCommTimestampDelayCounterResetOnSpikeCommSplit(
	    uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*"), inline_base("*CoordinateBase*"))
    ExtollSpikeCommTimestampDelayCounterResetOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommTimestampDelayCounterResetOnFPGA,
          ExtollSpikeCommTimestampDelayCounterResetOnSpikeCommSplit>
    , common::CoordinateBase<ExtollSpikeCommTimestampDelayCounterResetOnFPGA>
{
	explicit ExtollSpikeCommTimestampDelayCounterResetOnFPGA(
	    ExtollSpikeCommSplitOnFPGA const& split = ExtollSpikeCommSplitOnFPGA()) :
	    mixin_t(ExtollSpikeCommTimestampDelayCounterResetOnSpikeCommSplit(), split)
	{}

	explicit ExtollSpikeCommTimestampDelayCounterResetOnFPGA(enum_type const& e) : mixin_t(e) {}

	ExtollSpikeCommTimestampDelayCounterResetOnSpikeCommSplit
	toExtollSpikeCommTimestampDelayCounterResetOnSpikeCommSplit() const
	{
		return This();
	}
};


/*
 *  BARRIER & INTERRUPT:
 */


struct GENPYBIND(inline_base("*")) ExtollBarrierTriggerReachedOnExtollNodeId
    : public common::detail::
          RantWrapper<ExtollBarrierTriggerReachedOnExtollNodeId, uint_fast8_t, 15, 0>
{
	constexpr explicit ExtollBarrierTriggerReachedOnExtollNodeId(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*NodeIdMixin*"), inline_base("*CoordinateBase*"))
    ExtollBarrierTriggerReachedOnExtollNetwork
    : public NodeIdMixin<
          ExtollBarrierTriggerReachedOnExtollNetwork,
          ExtollBarrierTriggerReachedOnExtollNodeId>
    , halco::common::CoordinateBase<ExtollBarrierTriggerReachedOnExtollNetwork>
{
	ExtollBarrierTriggerReachedOnExtollNetwork() = default;

	explicit ExtollBarrierTriggerReachedOnExtollNetwork(
	    ExtollBarrierTriggerReachedOnExtollNodeId const& control,
	    ExtollNodeIdOnExtollNetwork const& nodeid =
	        ExtollNodeIdOnExtollNetwork(halco::hicann_dls::vx::ExtollNodeIdOnExtollNetwork::self)) :
	    mixin_t(control, nodeid)
	{}

	explicit ExtollBarrierTriggerReachedOnExtollNetwork(enum_type const& e) : mixin_t(e) {}

	ExtollBarrierTriggerReachedOnExtollNodeId toExtollBarrierTriggerReachedOnExtollNodeId() const
	{
		return This();
	}
};


struct GENPYBIND(inline_base("*")) ExtollBarrierReleasedOnExtollNodeId
    : public common::detail::RantWrapper<ExtollBarrierReleasedOnExtollNodeId, uint_fast8_t, 15, 0>
{
	constexpr explicit ExtollBarrierReleasedOnExtollNodeId(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*NodeIdMixin*"), inline_base("*CoordinateBase*"))
    ExtollBarrierReleasedOnExtollNetwork
    : public NodeIdMixin<ExtollBarrierReleasedOnExtollNetwork, ExtollBarrierReleasedOnExtollNodeId>
    , halco::common::CoordinateBase<ExtollBarrierReleasedOnExtollNetwork>
{
	ExtollBarrierReleasedOnExtollNetwork() = default;

	explicit ExtollBarrierReleasedOnExtollNetwork(
	    ExtollBarrierReleasedOnExtollNodeId const& control,
	    ExtollNodeIdOnExtollNetwork const& nodeid =
	        ExtollNodeIdOnExtollNetwork(halco::hicann_dls::vx::ExtollNodeIdOnExtollNetwork::self)) :
	    mixin_t(control, nodeid)
	{}

	explicit ExtollBarrierReleasedOnExtollNetwork(enum_type const& e) : mixin_t(e) {}

	ExtollBarrierReleasedOnExtollNodeId toExtollBarrierReleasedOnExtollNodeId() const
	{
		return This();
	}
};


struct GENPYBIND(inline_base("*")) LinkOnExtollNode
    : public common::detail::RantWrapper<LinkOnExtollNode, uint_fast8_t, 6, 0>
{
	constexpr explicit LinkOnExtollNode(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) ExtollBarrierConfigOnExtollNodeId
    : public common::detail::RantWrapper<ExtollBarrierConfigOnExtollNodeId, uint_fast8_t, 15, 0>
{
	constexpr explicit ExtollBarrierConfigOnExtollNodeId(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*NodeIdMixin*"), inline_base("*CoordinateBase*"))
    ExtollBarrierConfigOnExtollNetwork
    : public NodeIdMixin<ExtollBarrierConfigOnExtollNetwork, ExtollBarrierConfigOnExtollNodeId>
    , halco::common::CoordinateBase<ExtollBarrierConfigOnExtollNetwork>
{
	ExtollBarrierConfigOnExtollNetwork() = default;

	explicit ExtollBarrierConfigOnExtollNetwork(
	    ExtollBarrierConfigOnExtollNodeId const& config,
	    ExtollNodeIdOnExtollNetwork const& nodeid =
	        ExtollNodeIdOnExtollNetwork(halco::hicann_dls::vx::ExtollNodeIdOnExtollNetwork::self)) :
	    mixin_t(config, nodeid)
	{}

	explicit ExtollBarrierConfigOnExtollNetwork(enum_type const& e) : mixin_t(e) {}

	ExtollBarrierConfigOnExtollNodeId toExtollBarrierConfigOnExtollNodeId() const
	{
		return This();
	}
};


struct GENPYBIND(inline_base("*")) ExtollInterruptControlOnExtollNodeId
    : public common::detail::RantWrapper<ExtollInterruptControlOnExtollNodeId, uint_fast8_t, 3, 0>
{
	constexpr explicit ExtollInterruptControlOnExtollNodeId(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*NodeIdMixin*"), inline_base("*CoordinateBase*"))
    ExtollInterruptControlOnExtollNetwork
    : public NodeIdMixin<
          ExtollInterruptControlOnExtollNetwork,
          ExtollInterruptControlOnExtollNodeId>
    , halco::common::CoordinateBase<ExtollInterruptControlOnExtollNetwork>
{
	ExtollInterruptControlOnExtollNetwork() = default;

	explicit ExtollInterruptControlOnExtollNetwork(
	    ExtollInterruptControlOnExtollNodeId const& control,
	    ExtollNodeIdOnExtollNetwork const& nodeid =
	        ExtollNodeIdOnExtollNetwork(halco::hicann_dls::vx::ExtollNodeIdOnExtollNetwork::self)) :
	    mixin_t(control, nodeid)
	{}

	explicit ExtollInterruptControlOnExtollNetwork(enum_type const& e) : mixin_t(e) {}

	ExtollInterruptControlOnExtollNodeId toExtollInterruptControlOnExtollNodeId() const
	{
		return This();
	}
};


struct GENPYBIND(inline_base("*")) ExtollInterruptConfigOnExtollNodeId
    : public common::detail::RantWrapper<ExtollInterruptConfigOnExtollNodeId, uint_fast8_t, 15, 0>
{
	constexpr explicit ExtollInterruptConfigOnExtollNodeId(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*NodeIdMixin*"), inline_base("*CoordinateBase*"))
    ExtollInterruptConfigOnExtollNetwork
    : public NodeIdMixin<ExtollInterruptConfigOnExtollNetwork, ExtollInterruptConfigOnExtollNodeId>
    , halco::common::CoordinateBase<ExtollInterruptConfigOnExtollNetwork>
{
	ExtollInterruptConfigOnExtollNetwork() = default;

	explicit ExtollInterruptConfigOnExtollNetwork(
	    ExtollInterruptConfigOnExtollNodeId const& config,
	    ExtollNodeIdOnExtollNetwork const& nodeid =
	        ExtollNodeIdOnExtollNetwork(halco::hicann_dls::vx::ExtollNodeIdOnExtollNetwork::self)) :
	    mixin_t(config, nodeid)
	{}

	explicit ExtollInterruptConfigOnExtollNetwork(enum_type const& e) : mixin_t(e) {}

	ExtollInterruptConfigOnExtollNodeId toExtollInterruptConfigOnExtollNodeId() const
	{
		return This();
	}
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    ExtollBarrierInterruptInportErrorCountOnFPGA
    : public common::detail::
          RantWrapper<ExtollBarrierInterruptInportErrorCountOnFPGA, uint_fast8_t, 0, 0>
    , halco::common::CoordinateBase<ExtollBarrierInterruptInportErrorCountOnFPGA>
{
	constexpr explicit ExtollBarrierInterruptInportErrorCountOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    ExtollBarrierInterruptInportCounterResetOnFPGA
    : public common::detail::
          RantWrapper<ExtollBarrierInterruptInportCounterResetOnFPGA, uint_fast8_t, 0, 0>
    , common::CoordinateBase<ExtollBarrierInterruptInportCounterResetOnFPGA>
{
	constexpr explicit ExtollBarrierInterruptInportCounterResetOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


} // namespace vx
} // namespace halco::hicann_dls

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollAddress)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollNodeId)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollChipType)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollNodeIdOnExtollNetwork)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollAddressOnExtollNetwork)


HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollBarrierTriggerReachedOnExtollNodeId)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollBarrierTriggerReachedOnExtollNetwork)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollBarrierReleasedOnExtollNodeId)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollBarrierReleasedOnExtollNetwork)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::LinkOnExtollNode)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollBarrierConfigOnExtollNodeId)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollBarrierConfigOnExtollNetwork)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollInterruptControlOnExtollNodeId)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollInterruptControlOnExtollNetwork)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollInterruptConfigOnExtollNodeId)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollInterruptConfigOnExtollNetwork)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollBarrierInterruptInportErrorCountOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollBarrierInterruptInportCounterResetOnFPGA)


HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::EventSwitchSourceOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::EventSwitchReadoutOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::EventSwitchConfigOnFPGA)


HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommBucketTriggerConfigOnFPGA)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommBucketDestinationConfigOnFPGA)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommBucketNumPktsSentOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommBucketNumEvtsRcvdOnSpikeCommSplit)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommBucketNumEvtsRcvdOnFPGA)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommBucketCounterResetOnFPGA)


HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommSplitOnFPGA)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommRouterLookupConfigOnSpikeCommSplit)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommRouterLookupConfigOnFPGA)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommRouterConfigOnSpikeCommSplit)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommRouterConfigOnFPGA)

HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann_dls::vx::ExtollSpikeCommRouterEventLossDisabledOnSpikeCommSplit)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommRouterEventLossDisabledOnFPGA)

HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann_dls::vx::ExtollSpikeCommRouterEventLossMisconfOnSpikeCommSplit)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommRouterEventLossMisconfOnFPGA)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommRouterEventsRoutedOnSpikeCommSplit)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommRouterEventsRoutedOnFPGA)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommRouterCounterResetOnSpikeCommSplit)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommRouterCounterResetOnFPGA)


HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann_dls::vx::ExtollSpikeCommDecoderNumEventsReceivedOnSpikeCommSplit)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommDecoderNumEventsReceivedOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommDecoderCounterResetOnFPGA)


HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayConfigOnSpikeCommSplit)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayConfigOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayNumEventsReceivedOnSpikeCommSplit)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayNumEventsReceivedOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayEventLossFullOnSpikeCommSplit)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayEventLossFullOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayEventLossExpiredOnSpikeCommSplit)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayEventLossExpiredOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayCounterResetOnSpikeCommSplit)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommTimestampDelayCounterResetOnFPGA)

} // namespace std
