#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/******\
  FPGA
\******/

/**
 * Unique identifier on FPGA.
 */
struct GENPYBIND(inline_base("*")) FPGADeviceDNAOnFPGA
    : public common::detail::RantWrapper<FPGADeviceDNAOnFPGA, uint_fast16_t, 0, 0>
{
	constexpr explicit FPGADeviceDNAOnFPGA(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*")) FPGAMemoryByteOnFPGA
    : public common::detail::RantWrapper<FPGAMemoryByteOnFPGA, uint_fast16_t, 0x20000 - 1, 0>
{
	constexpr explicit FPGAMemoryByteOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

/************\
   Loopback
\************/

/**
 * Unique coordinate for a readable entity without payload.
 * The read response is issued as fast as possible, which e.g. enables usage for synchronization of
 * from-FPGA time annotation and to-FPGA Playback time annotation.
 */
struct GENPYBIND(inline_base("*")) NullPayloadReadableOnFPGA
    : public common::detail::RantWrapper<NullPayloadReadableOnFPGA, uint_fast16_t, 0, 0>
{
	constexpr explicit NullPayloadReadableOnFPGA(uintmax_t const val = 0) : rant_t(val) {}
};

/************************************\
   Event recording control register
\************************************/

/**
 * Control register to enable/disable the "recording", i.e. forwarding, of events (spikes, MADC samples).
 * The FPGA simply drops events arriving from the chip and does not forward them to the host.
 */
struct GENPYBIND(inline_base("*")) EventRecordingConfigOnFPGA
    : public common::detail::RantWrapper<EventRecordingConfigOnFPGA, uint_fast16_t, 0, 0>
{
	constexpr explicit EventRecordingConfigOnFPGA(uintmax_t const val = 0) : rant_t(val) {}
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::FPGADeviceDNAOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NullPayloadReadableOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::EventRecordingConfigOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::FPGAMemoryByteOnFPGA)

} // namespace std
