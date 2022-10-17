#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct GENPYBIND(inline_base("*")) ExtollAddress
    : public common::detail::BaseType<ExtollAddress, uint64_t>
{
	constexpr explicit ExtollAddress(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    base_t(val)
	{}
};


/*
 *  FPGA-Event-Switch:
 */

struct GENPYBIND(inline_base("*")) EventSwitchSourceOnFPGA
    : public common::detail::RantWrapper<EventSwitchSourceOnFPGA, uint_fast8_t, 2, 0>
{
	constexpr explicit EventSwitchSourceOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const EventSwitchSourceOnFPGA to_executor;
	static const EventSwitchSourceOnFPGA to_asic;
	static const EventSwitchSourceOnFPGA to_external;
};


/*
 *  Accumulation-BUCKET:
 */

struct GENPYBIND(inline_base("*")) ExtollSpikeCommBucketTriggerConfigOnFPGA
    : public common::detail::
          RantWrapper<ExtollSpikeCommBucketTriggerConfigOnFPGA, uint_fast8_t, 7, 0>
{
	constexpr explicit ExtollSpikeCommBucketTriggerConfigOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) ExtollSpikeCommBucketDestinationConfigOnFPGA
    : public common::detail::
          RantWrapper<ExtollSpikeCommBucketDestinationConfigOnFPGA, uint_fast8_t, 7, 0>
{
	constexpr explicit ExtollSpikeCommBucketDestinationConfigOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) ExtollSpikeCommBucketNumPktsSentOnFPGA
    : public common::detail::RantWrapper<ExtollSpikeCommBucketNumPktsSentOnFPGA, uint_fast8_t, 7, 0>
{
	constexpr explicit ExtollSpikeCommBucketNumPktsSentOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) ExtollSpikeCommBucketCounterResetOnFPGA
    : public common::detail::
          RantWrapper<ExtollSpikeCommBucketCounterResetOnFPGA, uint_fast8_t, 7, 0>
{
	constexpr explicit ExtollSpikeCommBucketCounterResetOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


/*
 * SPLITs:
 */


struct GENPYBIND(inline_base("*")) ExtollSpikeCommSplitOnFPGA
    : public common::detail::RantWrapper<ExtollSpikeCommSplitOnFPGA, uint_fast8_t, 1, 0>
{
	constexpr explicit ExtollSpikeCommSplitOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


/*
 *  SpikeComm-ROUTER:
 */


HALCO_COORDINATE_MIXIN(SpikeCommSplitMixin, ExtollSpikeCommSplitOnFPGA, pulse_comm_split)


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

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*")) ExtollSpikeCommRouterLookupConfigOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommRouterLookupConfigOnFPGA,
          ExtollSpikeCommRouterLookupConfigOnSpikeCommSplit>
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

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*")) ExtollSpikeCommRouterConfigOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommRouterConfigOnFPGA,
          ExtollSpikeCommRouterConfigOnSpikeCommSplit>
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

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*")) ExtollSpikeCommRouterEventLossDisabledOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommRouterEventLossDisabledOnFPGA,
          ExtollSpikeCommRouterEventLossDisabledOnSpikeCommSplit>
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

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*")) ExtollSpikeCommRouterEventLossMisconfOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommRouterEventLossMisconfOnFPGA,
          ExtollSpikeCommRouterEventLossMisconfOnSpikeCommSplit>
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

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*")) ExtollSpikeCommRouterEventsRoutedOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommRouterEventsRoutedOnFPGA,
          ExtollSpikeCommRouterEventsRoutedOnSpikeCommSplit>
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

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*")) ExtollSpikeCommRouterCounterResetOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommRouterCounterResetOnFPGA,
          ExtollSpikeCommRouterCounterResetOnSpikeCommSplit>
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

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*")) ExtollSpikeCommDecoderNumEventsReceivedOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommDecoderNumEventsReceivedOnFPGA,
          ExtollSpikeCommDecoderNumEventsReceivedOnSpikeCommSplit>
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


struct GENPYBIND(inline_base("*")) ExtollSpikeCommDecoderCounterResetOnFPGA
    : public common::detail::
          RantWrapper<ExtollSpikeCommDecoderCounterResetOnFPGA, uint_fast8_t, 0, 0>
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

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*")) ExtollSpikeCommTimestampDelayConfigOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommTimestampDelayConfigOnFPGA,
          ExtollSpikeCommTimestampDelayConfigOnSpikeCommSplit>
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

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*"))
    ExtollSpikeCommTimestampDelayNumEventsReceivedOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommTimestampDelayNumEventsReceivedOnFPGA,
          ExtollSpikeCommTimestampDelayNumEventsReceivedOnSpikeCommSplit>
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

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*"))
    ExtollSpikeCommTimestampDelayEventLossFullOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommTimestampDelayEventLossFullOnFPGA,
          ExtollSpikeCommTimestampDelayEventLossFullOnSpikeCommSplit>
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

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*"))
    ExtollSpikeCommTimestampDelayEventLossExpiredOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommTimestampDelayEventLossExpiredOnFPGA,
          ExtollSpikeCommTimestampDelayEventLossExpiredOnSpikeCommSplit>
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

struct GENPYBIND(inline_base("*SpikeCommSplitMixin*"))
    ExtollSpikeCommTimestampDelayCounterResetOnFPGA
    : public SpikeCommSplitMixin<
          ExtollSpikeCommTimestampDelayCounterResetOnFPGA,
          ExtollSpikeCommTimestampDelayCounterResetOnSpikeCommSplit>
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


} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollAddress)


HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::EventSwitchSourceOnFPGA)


HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommBucketTriggerConfigOnFPGA)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommBucketDestinationConfigOnFPGA)

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExtollSpikeCommBucketNumPktsSentOnFPGA)

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