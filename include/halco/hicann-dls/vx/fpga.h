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


struct GENPYBIND(inline_base("*")) ExternalPPUMemoryByteOnFPGA
    : public common::detail::RantWrapper<ExternalPPUMemoryByteOnFPGA, uint_fast16_t, 0x20000 - 1, 0>
{
	constexpr explicit ExternalPPUMemoryByteOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) ExternalPPUMemoryQuadOnFPGA
    : public common::detail::RantWrapper<ExternalPPUMemoryQuadOnFPGA, uint_fast16_t, 0x08000 - 1, 0>
{
	constexpr explicit ExternalPPUMemoryQuadOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) ExternalPPUMemoryBlockSize
    : public common::detail::RantWrapper<
          ExternalPPUMemoryBlockSize,
          uint_fast16_t,
          ExternalPPUMemoryByteOnFPGA::size,
          1>
{
	constexpr explicit ExternalPPUMemoryBlockSize(uintmax_t const val = 1)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) ExternalPPUMemoryBlockOnFPGA
    : public common::detail::
          IntervalCoordinate<ExternalPPUMemoryBlockOnFPGA, ExternalPPUMemoryByteOnFPGA>
{
	INTERVAL_COMMON_CONSTRUCTORS(ExternalPPUMemoryBlockOnFPGA)

	ExternalPPUMemoryBlockSize toExternalPPUMemoryBlockSize() const
	{
		return ExternalPPUMemoryBlockSize(length());
	}
};


struct GENPYBIND(inline_base("*")) ExternalPPUMemoryOnFPGA
    : public common::detail::RantWrapper<ExternalPPUMemoryOnFPGA, uint_fast16_t, 0, 0>
{
	constexpr explicit ExternalPPUMemoryOnFPGA(uintmax_t const val = 0) : rant_t(val) {}
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

/******************************\
   Instruction timeout config
\******************************/

/**
 * Configuration register of instruction timeout duration of playback executor.
 */
struct GENPYBIND(inline_base("*")) InstructionTimeoutConfigOnFPGA
    : public common::detail::RantWrapper<InstructionTimeoutConfigOnFPGA, uint_fast16_t, 0, 0>
{
	constexpr explicit InstructionTimeoutConfigOnFPGA(uintmax_t const val = 0) : rant_t(val) {}
};

/***********\
   SpikeIO
\***********/

/**
 * Serial width of the on-FPGA SpikeIO module, in bits.
 */
static constexpr size_t GENPYBIND(visible) spikeio_serial_bits = 8;

// Forward declaration from 'halco/hicann-dls/vx/fpga.h'
struct SpikeIOInputRouteOnFPGA;

// Forward declaration from 'halco/hicann-dls/vx/event.h'
struct SpikeLabel;

/**
 * Serial address/label value for a single event transferred via SpikeIO.
 */
struct GENPYBIND(inline_base("*")) SpikeIOAddress
    : public halco::common::detail::
          RantWrapper<SpikeIOAddress, uint_fast16_t, (1 << spikeio_serial_bits) - 1, 0>
{
	constexpr explicit SpikeIOAddress(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	SpikeIOInputRouteOnFPGA toSpikeIOInputRouteOnFPGA() const;
};

/**
 * Configuration register for on-FPGA SpikeIO module.
 */
struct GENPYBIND(inline_base("*")) SpikeIOConfigOnFPGA
    : public common::detail::RantWrapper<SpikeIOConfigOnFPGA, uint_fast16_t, 0, 0>
{
	constexpr explicit SpikeIOConfigOnFPGA(uintmax_t const val = 0) : rant_t(val) {}
};

/**
 * (Serial) address of spikes received through the on-FPGA SpikeIO module.
 */
struct GENPYBIND(inline_base("*")) SpikeIOInputRouteOnFPGA
    : public halco::common::detail::
          RantWrapper<SpikeIOInputRouteOnFPGA, uint_fast16_t, (1u << spikeio_serial_bits) - 1, 0>
{
	constexpr explicit SpikeIOInputRouteOnFPGA(uintmax_t value = 0) : rant_t(value) {}

	SpikeIOAddress toSpikeIOAddress() const;
};

/**
 * SpikeLabel of event to be sent via the on-FPGA SpikeIO module.
 */
struct GENPYBIND(inline_base("*")) SpikeIOOutputRouteOnFPGA
    : public halco::common::detail::
          RantWrapper<SpikeIOOutputRouteOnFPGA, uint_fast32_t, (1u << 16) - 1, 0>
{
	constexpr explicit SpikeIOOutputRouteOnFPGA(uintmax_t value = 0) : rant_t(value) {}

	SpikeLabel toSpikeLabel() const;
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::FPGADeviceDNAOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NullPayloadReadableOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::EventRecordingConfigOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::InstructionTimeoutConfigOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExternalPPUMemoryByteOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExternalPPUMemoryQuadOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExternalPPUMemoryBlockSize)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExternalPPUMemoryBlockOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ExternalPPUMemoryOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikeIOAddress)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikeIOConfigOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikeIOInputRouteOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikeIOOutputRouteOnFPGA)

} // namespace std
