#pragma once

extern "C"
{
#include <stdint.h>
}

#include "halco/common/common.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.th"
#include "halco/common/mixin.h"

GENPYBIND_TAG_HALCO_HICANN_DLS_VX
GENPYBIND_MANUAL({
	parent.attr("__variant__") = "pybind11";
	parent->py::module::import("pyhalco_common");
})

namespace halco {
namespace hicann_dls {
namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct PPUOnDLS;

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

/*************************\
   HicannARQStatus
\*************************/

struct GENPYBIND(inline_base("*")) HicannARQStatusOnFPGA
    : public common::detail::RantWrapper<HicannARQStatusOnFPGA, uint_fast16_t, 0, 0>
{
	constexpr explicit HicannARQStatusOnFPGA(uintmax_t const val = 0) : rant_t(val) {}
};

/*************************\
   BackgroundSpikeSource
\*************************/

struct CrossbarInputOnDLS;
struct CrossbarL2OutputOnDLS;

struct GENPYBIND(inline_base("*")) BackgroundSpikeSourceOnDLS
    : public common::detail::RantWrapper<BackgroundSpikeSourceOnDLS, uint_fast16_t, 7, 0>
{
	constexpr explicit BackgroundSpikeSourceOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CrossbarInputOnDLS toCrossbarInputOnDLS() const;
	CrossbarL2OutputOnDLS toCrossbarL2OutputOnDLS() const;
};

/************\
   Crossbar
\************/

/**
 * Unique coordinate for crossbar output configuration.
 */
struct GENPYBIND(inline_base("*")) CrossbarOutputConfigOnDLS
    : public common::detail::RantWrapper<CrossbarOutputConfigOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit CrossbarOutputConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

/**
 * Coordinate of a crossbar output channel.
 */
struct GENPYBIND(inline_base("*")) CrossbarOutputOnDLS
    : public common::detail::RantWrapper<CrossbarOutputOnDLS, uint_fast16_t, 11, 0>
    , public common::detail::XRangedTrait
{
	constexpr explicit CrossbarOutputOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

/**
 * Coordinate of a to-L2 crossbar output channel.
 * Describes a continuous subset of the CrossbarOutputOnDLS range.
 */
struct GENPYBIND(inline_base("*")) CrossbarL2OutputOnDLS
    : public common::detail::RantWrapper<CrossbarL2OutputOnDLS, uint_fast16_t, 3, 0>
{
	constexpr explicit CrossbarL2OutputOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CrossbarOutputOnDLS toCrossbarOutputOnDLS() const;
};

/**
 * Coordinate of a crossbar input channel.
 */
struct GENPYBIND(inline_base("*")) CrossbarInputOnDLS
    : public common::detail::RantWrapper<CrossbarInputOnDLS, uint_fast16_t, 19, 0>
    , public common::detail::YRangedTrait
{
	constexpr explicit CrossbarInputOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

/*
 * Coordinate of a node in the crossbar connecting a input channel with a output channel.
 * The nodes are located as depicted in the following: (X == node, . == no node)
 *
 *                                  - Outputs -
 *
 *                         synapse driver         L2
 *                      top          bottom
 *                      0  1  2  3   0  1  2  3   0  1  2  3
 *
 *         neurons  0   X  .  .  .   X  .  .  .   X  .  .  .
 *         left of  1   .  X  .  .   .  X  .  .   .  X  .  .
 *         anncore  2   .  .  X  .   .  .  X  .   .  .  X  .
 *                  3   .  .  .  X   .  .  .  X   .  .  .  X
 *
 *         neurons  0   X  .  .  .   X  .  .  .   X  .  .  .
 *         right of 1   .  X  .  .   .  X  .  .   .  X  .  .
 *         anncore  2   .  .  X  .   .  .  X  .   .  .  X  .
 *    |             3   .  .  .  X   .  .  .  X   .  .  .  X
 *
 *         L2       0   X  X  X  X   X  X  X  X   X  .  .  .
 * Inputs           1   X  X  X  X   X  X  X  X   .  X  .  .
 *                  2   X  X  X  X   X  X  X  X   .  .  X  .
 *                  3   X  X  X  X   X  X  X  X   .  .  .  X
 *    |
 *         back-    0   X  .  .  .   .  .  .  .   X  .  .  .
 *         ground   1   .  X  .  .   .  .  .  .   .  X  .  .
 *         spike    2   .  .  X  .   .  .  .  .   .  .  X  .
 *         sources  3   .  .  .  X   .  .  .  .   .  .  .  X
 *                  4   .  .  .  .   X  .  .  .   X  .  .  .
 *                  5   .  .  .  .   .  X  .  .   .  X  .  .
 *                  6   .  .  .  .   .  .  X  .   .  .  X  .
 *                  7   .  .  .  .   .  .  .  X   .  .  .  X
 *
 * The nodes are counted continuously from the top-left to the bottom-right corner of
 * the schematic.
 */
struct GENPYBIND(inline_base("*")) CrossbarNodeOnDLS
    : public common::detail::
          GridCoordinate<CrossbarNodeOnDLS, CrossbarOutputOnDLS, CrossbarInputOnDLS, 76>
{
	GRID_COMMON_CONSTRUCTORS(CrossbarNodeOnDLS)

	CrossbarOutputOnDLS toCrossbarOutputOnDLS() const { return x(); }
	CrossbarInputOnDLS toCrossbarInputOnDLS() const { return y(); }

	/* implementation detail, not part of public API: */

	static x_type to_x(enum_type const& e);
	static y_type to_y(enum_type const& e);
	static enum_type to_enum(x_type const& x, y_type const& y);
};

/************\
   PerfTest
\************/

struct GENPYBIND(inline_base("*")) PerfTestOnFPGA
    : public common::detail::RantWrapper<PerfTestOnFPGA, uint_fast16_t, 0, 0>
{
	constexpr explicit PerfTestOnFPGA(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) PerfTestStatusOnFPGA
    : public common::detail::RantWrapper<PerfTestStatusOnFPGA, uint_fast16_t, 0, 0>
{
	constexpr explicit PerfTestStatusOnFPGA(uintmax_t const val = 0) : rant_t(val) {}
};

/***********\
    Spike
\***********/

/**
 * The chip supports packing from 1 to 3 spikes in one instruction to be processed in one clock
 * cycle by the transport layer. In order to have unique container coordinates, these are layed out
 * as separate coordinate types of length 1.
 */

struct GENPYBIND(inline_base("*")) SpikePack1ToChipOnDLS
    : public common::detail::RantWrapper<SpikePack1ToChipOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit SpikePack1ToChipOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) SpikePack2ToChipOnDLS
    : public common::detail::RantWrapper<SpikePack2ToChipOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit SpikePack2ToChipOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) SpikePack3ToChipOnDLS
    : public common::detail::RantWrapper<SpikePack3ToChipOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit SpikePack3ToChipOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) SpikePackFromFPGAOnDLS
    : public halco::common::detail::RantWrapper<SpikePackFromFPGAOnDLS, uint_fast16_t, 3, 1>
{
	explicit SpikePackFromFPGAOnDLS(uintmax_t const value = 1) GENPYBIND(implicit_conversion) :
	    rant_t(value)
	{}
};

struct GENPYBIND(inline_base("*")) MADCSamplePackFromFPGAOnDLS
    : public halco::common::detail::RantWrapper<MADCSamplePackFromFPGAOnDLS, uint_fast16_t, 3, 1>
{
	explicit MADCSamplePackFromFPGAOnDLS(uintmax_t const value = 1) GENPYBIND(implicit_conversion) :
	    rant_t(value)
	{}
};

/************\
    Systime
\************/

struct GENPYBIND(inline_base("*")) SystimeSyncOnFPGA
    : public common::detail::RantWrapper<SystimeSyncOnFPGA, uint_fast16_t, 0, 0>
{
	constexpr explicit SystimeSyncOnFPGA(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) SystimeSyncBaseOnDLS
    : public common::detail::RantWrapper<SystimeSyncBaseOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit SystimeSyncBaseOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

/**********\
    CADC
\**********/

struct GENPYBIND(inline_base("*")) CADCConfigOnDLS
    : public common::detail::RantWrapper<CADCConfigOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit CADCConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}

	PPUOnDLS toPPUOnDLS() const;

	static const CADCConfigOnDLS top;
	static const CADCConfigOnDLS bottom;
};

/**********\
    PPU
\**********/

struct GENPYBIND(inline_base("*")) PPUOnDLS
    : public common::detail::RantWrapper<PPUOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit PPUOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CADCConfigOnDLS toCADCConfigOnDLS() const { return CADCConfigOnDLS(toEnum()); }

	static const PPUOnDLS top;
	static const PPUOnDLS bottom;
};

struct GENPYBIND(inline_base("*")) PPUMemoryWordOnPPU
    : public common::detail::RantWrapper<PPUMemoryWordOnPPU, uint_fast16_t, 0x1000 - 1, 0>
{
	constexpr explicit PPUMemoryWordOnPPU(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) PPUMemoryBlockSize
    : public common::detail::
          RantWrapper<PPUMemoryBlockSize, uint_fast16_t, PPUMemoryWordOnPPU::size, 1>
{
	constexpr explicit PPUMemoryBlockSize(uintmax_t const val = 1) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) PPUMemoryBlockOnPPU
    : public common::detail::IntervalCoordinate<PPUMemoryBlockOnPPU, PPUMemoryWordOnPPU>
{
	INTERVAL_COMMON_CONSTRUCTORS(PPUMemoryBlockOnPPU)

	PPUMemoryBlockSize toPPUMemoryBlockSize() const { return PPUMemoryBlockSize(length()); }
	PPUMemoryWordOnPPU toMin() const { return min(); }
	PPUMemoryWordOnPPU toMax() const { return max(); }
};

struct GENPYBIND(inline_base("*")) PPUMemoryOnPPU
    : public common::detail::RantWrapper<PPUMemoryOnPPU, uint_fast16_t, 0, 0>
{
	constexpr explicit PPUMemoryOnPPU(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) PPUControlRegisterOnPPU
    : public common::detail::RantWrapper<PPUControlRegisterOnPPU, uint_fast16_t, 0, 0>
{
	constexpr explicit PPUControlRegisterOnPPU(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) PPUStatusRegisterOnPPU
    : public common::detail::RantWrapper<PPUStatusRegisterOnPPU, uint_fast16_t, 0, 0>
{
	constexpr explicit PPUStatusRegisterOnPPU(uintmax_t const val = 0) : rant_t(val) {}
};

HALCO_COORDINATE_MIXIN(PPUMixin, PPUOnDLS, ppu)

struct GENPYBIND(inline_base("*PPUMixin*")) PPUMemoryBlockOnDLS
    : public PPUMixin<PPUMemoryBlockOnDLS, PPUMemoryBlockOnPPU>
{
private:
	typedef PPUMixin<PPUMemoryBlockOnDLS, PPUMemoryBlockOnPPU> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	PPUMemoryBlockOnDLS() = default;

	explicit PPUMemoryBlockOnDLS(PPUMemoryBlockOnPPU const& reg, PPUOnDLS const& ppu = PPUOnDLS()) :
	    base(reg, ppu)
	{}

	explicit PPUMemoryBlockOnDLS(enum_type const& e) : base(e) {}

	PPUMemoryBlockOnPPU toPPUMemoryBlockOnPPU() const { return This(); }
	PPUOnDLS toPPUOnDLS() const { return split().first; }
};

struct GENPYBIND(inline_base("*PPUMixin*")) PPUMemoryOnDLS
    : public PPUMixin<PPUMemoryOnDLS, PPUMemoryOnPPU>
{
private:
	typedef PPUMixin<PPUMemoryOnDLS, PPUMemoryOnPPU> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	PPUMemoryOnDLS() = default;

	explicit PPUMemoryOnDLS(PPUMemoryOnPPU const& reg, PPUOnDLS const& ppu = PPUOnDLS()) :
	    base(reg, ppu)
	{}

	explicit PPUMemoryOnDLS(enum_type const& e) : base(e) {}

	PPUMemoryOnPPU toPPUMemoryOnPPU() const { return This(); }
	PPUOnDLS toPPUOnDLS() const { return split().first; }
};

struct GENPYBIND(inline_base("*PPUMixin*")) PPUControlRegisterOnDLS
    : public PPUMixin<PPUControlRegisterOnDLS, PPUControlRegisterOnPPU>
{
private:
	typedef PPUMixin<PPUControlRegisterOnDLS, PPUControlRegisterOnPPU> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	PPUControlRegisterOnDLS() = default;

	explicit PPUControlRegisterOnDLS(
	    PPUControlRegisterOnPPU const& reg, PPUOnDLS const& ppu = PPUOnDLS()) :
	    base(reg, ppu)
	{}

	explicit PPUControlRegisterOnDLS(enum_type const& e) : base(e) {}

	PPUControlRegisterOnPPU toPPUControlRegisterOnPPU() const { return This(); }
	PPUOnDLS toPPUOnDLS() const { return split().first; }
};

struct GENPYBIND(inline_base("*PPUMixin*")) PPUStatusRegisterOnDLS
    : public PPUMixin<PPUStatusRegisterOnDLS, PPUStatusRegisterOnPPU>
{
private:
	typedef PPUMixin<PPUStatusRegisterOnDLS, PPUStatusRegisterOnPPU> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	PPUStatusRegisterOnDLS() = default;

	explicit PPUStatusRegisterOnDLS(
	    PPUStatusRegisterOnPPU const& reg, PPUOnDLS const& ppu = PPUOnDLS()) :
	    base(reg, ppu)
	{}

	explicit PPUStatusRegisterOnDLS(enum_type const& e) : base(e) {}

	PPUStatusRegisterOnPPU toPPUStatusRegisterOnPPU() const { return This(); }
	PPUOnDLS toPPUOnDLS() const { return split().first; }
};

struct GENPYBIND(inline_base("*PPUMixin*")) PPUMemoryWordOnDLS
    : public PPUMixin<PPUMemoryWordOnDLS, PPUMemoryWordOnPPU>
{
private:
	typedef PPUMixin<PPUMemoryWordOnDLS, PPUMemoryWordOnPPU> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque);

	PPUMemoryWordOnDLS() = default;

	explicit PPUMemoryWordOnDLS(PPUMemoryWordOnPPU const& word, PPUOnDLS const& ppu = PPUOnDLS()) :
	    base(word, ppu)
	{}

	explicit PPUMemoryWordOnDLS(enum_type const& e) : base(e) {}

	PPUMemoryWordOnPPU toPPUMemoryWordOnPPU() const { return This(); }
	PPUOnDLS toPPUOnDLS() const { return split().first; }
};

/************\
    Neuron
\************/

struct GENPYBIND(inline_base("*")) NeuronLabel
    : public halco::common::detail::RantWrapper<NeuronLabel, uint16_t, 0x3fff /* 14bit */, 0>
{
	NeuronLabel(uintmax_t value = 0) GENPYBIND(implicit_conversion) : rant_t(value) {}
};

/**********\
    SPL1
\**********/

struct GENPYBIND(inline_base("*")) SPL1Address
    : public halco::common::detail::RantWrapper<SPL1Address, uint16_t, 3 /* 2bit */, 0>
{
	SPL1Address(uintmax_t value = 0) GENPYBIND(implicit_conversion) : rant_t(value) {}
};

/***************\
    ResetChip
\***************/

struct GENPYBIND(inline_base("*")) ResetChipOnDLS
    : public common::detail::RantWrapper<ResetChipOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit ResetChipOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

/************\
    Timer
\************/

struct GENPYBIND(inline_base("*")) TimerOnDLS
    : public common::detail::RantWrapper<TimerOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit TimerOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

/***********\
    JTAG
\***********/

struct GENPYBIND(inline_base("*")) ResetJTAGTapOnDLS
    : public common::detail::RantWrapper<ResetJTAGTapOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit ResetJTAGTapOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) JTAGClockScalerOnDLS
    : public common::detail::RantWrapper<JTAGClockScalerOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit JTAGClockScalerOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) JTAGIdCodeOnDLS
    : public common::detail::RantWrapper<JTAGIdCodeOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit JTAGIdCodeOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) JTAGPLLRegisterOnDLS
    : public common::detail::RantWrapper<JTAGPLLRegisterOnDLS, uint_fast16_t, 7, 0>
{
	constexpr explicit JTAGPLLRegisterOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) JTAGPhyRegisterOnDLS
    : public common::detail::RantWrapper<JTAGPhyRegisterOnDLS, uint_fast16_t, 7, 0>
{
	constexpr explicit JTAGPhyRegisterOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

/**********\
    Phy
\**********/

struct GENPYBIND(inline_base("*")) PhyConfigFPGAOnDLS
    : public common::detail::RantWrapper<PhyConfigFPGAOnDLS, uint_fast16_t, 7, 0>
{
	constexpr explicit PhyConfigFPGAOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) PhyConfigChipOnDLS
    : public common::detail::RantWrapper<PhyConfigChipOnDLS, uint_fast16_t, 7, 0>
{
	constexpr explicit PhyConfigChipOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	JTAGPhyRegisterOnDLS toJTAGPhyRegisterOnDLS() const { return JTAGPhyRegisterOnDLS(toEnum()); }
};

struct GENPYBIND(inline_base("*")) PhyStatusOnFPGA
    : public common::detail::RantWrapper<PhyStatusOnFPGA, uint_fast16_t, 7, 0>
{
	constexpr explicit PhyStatusOnFPGA(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) CommonPhyConfigFPGAOnDLS
    : public common::detail::RantWrapper<CommonPhyConfigFPGAOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit CommonPhyConfigFPGAOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) CommonPhyConfigChipOnDLS
    : public common::detail::RantWrapper<CommonPhyConfigChipOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit CommonPhyConfigChipOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

/**********\
    PLL
\**********/

struct GENPYBIND(inline_base("*")) PLLSelfTestOnDLS
    : public common::detail::RantWrapper<PLLSelfTestOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit PLLSelfTestOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) PLLSelfTestStatusOnDLS
    : public common::detail::RantWrapper<PLLSelfTestStatusOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit PLLSelfTestStatusOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) PLLClockOutputBlockOnDLS
    : public common::detail::RantWrapper<PLLClockOutputBlockOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit PLLClockOutputBlockOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) ADPLLOnDLS
    : public common::detail::RantWrapper<ADPLLOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit ADPLLOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) PLLClockOutputOnDLS
    : public common::detail::RantWrapper<PLLClockOutputOnDLS, uint_fast16_t, 3, 0>
{
	constexpr explicit PLLClockOutputOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const PLLClockOutputOnDLS serdes_ser_send_clk;
	static const PLLClockOutputOnDLS phy_ref_clk;
	static const PLLClockOutputOnDLS ppu_clk;
	static const PLLClockOutputOnDLS madc_clk;
};

/**************\
    Omnibus
\**************/

struct GENPYBIND(inline_base("*")) OmnibusChipOverJTAGAddress
    : public common::detail::BaseType<OmnibusChipOverJTAGAddress, uint32_t>
{
	constexpr explicit OmnibusChipOverJTAGAddress(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    base_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) OmnibusChipAddress
    : public common::detail::BaseType<OmnibusChipAddress, uint32_t>
{
	constexpr explicit OmnibusChipAddress(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    base_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) OmnibusFPGAAddress
    : public common::detail::BaseType<OmnibusFPGAAddress, uint32_t>
{
	constexpr explicit OmnibusFPGAAddress(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    base_t(val)
	{}
};

/***********\
    I2C
\***********/

struct GENPYBIND(inline_base("*")) I2CIdRegisterOnBoard
    : public common::detail::RantWrapper<I2CIdRegisterOnBoard, uint_fast16_t, 0, 0>
{
	constexpr explicit I2CIdRegisterOnBoard(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) I2CINA219RoRegisterOnINA219
    : public common::detail::RantWrapper<I2CINA219RoRegisterOnINA219, uint_fast16_t, 3, 0>
{
	constexpr explicit I2CINA219RoRegisterOnINA219(uintmax_t const val = 0) : rant_t(val) {}

	static const I2CINA219RoRegisterOnINA219 shunt;
	static const I2CINA219RoRegisterOnINA219 bus;
	static const I2CINA219RoRegisterOnINA219 power;
	static const I2CINA219RoRegisterOnINA219 current;
};

struct GENPYBIND(inline_base("*")) I2CINA219RwRegisterOnINA219
    : public common::detail::RantWrapper<I2CINA219RwRegisterOnINA219, uint_fast16_t, 1, 0>
{
	constexpr explicit I2CINA219RwRegisterOnINA219(uintmax_t const val = 0) : rant_t(val) {}

	static const I2CINA219RwRegisterOnINA219 config;
	static const I2CINA219RwRegisterOnINA219 calibration;
};

struct GENPYBIND(inline_base("*")) INA219OnBoard
    : public common::detail::RantWrapper<INA219OnBoard, uint_fast16_t, 5, 0>
{
	constexpr explicit INA219OnBoard(uintmax_t const val = 0) : rant_t(val) {}

	static const INA219OnBoard vdd12_digital;
	static const INA219OnBoard vdd25_digital;
	static const INA219OnBoard vdd12_analog;
	static const INA219OnBoard vdd25_analog;
	static const INA219OnBoard vdd12_madc;
	static const INA219OnBoard vdd12_pll;
};

HALCO_COORDINATE_MIXIN(INA219Mixin, INA219OnBoard, ina219)

struct GENPYBIND(inline_base("*INA219Mixin*")) I2CINA219RoRegisterOnBoard
    : public INA219Mixin<I2CINA219RoRegisterOnBoard, I2CINA219RoRegisterOnINA219>
{
private:
	typedef INA219Mixin<I2CINA219RoRegisterOnBoard, I2CINA219RoRegisterOnINA219> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	I2CINA219RoRegisterOnBoard() = default;

	explicit I2CINA219RoRegisterOnBoard(
	    I2CINA219RoRegisterOnINA219 const& reg, INA219OnBoard const& ina = INA219OnBoard()) :
	    base(reg, ina)
	{}

	explicit I2CINA219RoRegisterOnBoard(enum_type const& e) : base(e) {}

	I2CINA219RoRegisterOnINA219 toI2CINA219RoRegisterOnINA219() const { return This(); }
	INA219OnBoard toINA219OnBoard() const { return split().first; }
};

struct GENPYBIND(inline_base("*INA219Mixin*")) I2CINA219RwRegisterOnBoard
    : public INA219Mixin<I2CINA219RwRegisterOnBoard, I2CINA219RwRegisterOnINA219>
{
private:
	typedef INA219Mixin<I2CINA219RwRegisterOnBoard, I2CINA219RwRegisterOnINA219> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	I2CINA219RwRegisterOnBoard() = default;

	explicit I2CINA219RwRegisterOnBoard(
	    I2CINA219RwRegisterOnINA219 const& reg, INA219OnBoard const& ina = INA219OnBoard()) :
	    base(reg, ina)
	{}

	explicit I2CINA219RwRegisterOnBoard(enum_type const& e) : base(e) {}

	I2CINA219RwRegisterOnINA219 toI2CINA219RwRegisterOnINA219() const { return This(); }
	INA219OnBoard toINA219OnBoard() const { return split().first; }
};

/***********\
    SPI
\***********/

struct GENPYBIND(inline_base("*")) SPIShiftRegisterOnBoard
    : public common::detail::RantWrapper<SPIShiftRegisterOnBoard, uint_fast16_t, 0, 0>
{
	constexpr explicit SPIShiftRegisterOnBoard(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) SPIDACDataRegisterOnDAC
    : public common::detail::RantWrapper<SPIDACDataRegisterOnDAC, uint_fast16_t, 7, 0>
{
	constexpr explicit SPIDACDataRegisterOnDAC(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) SPIDACControlRegisterOnDAC
    : public common::detail::RantWrapper<SPIDACControlRegisterOnDAC, uint_fast16_t, 3, 0>
{
	constexpr explicit SPIDACControlRegisterOnDAC(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const SPIDACControlRegisterOnDAC gain_reference;
	static const SPIDACControlRegisterOnDAC ldac;
	static const SPIDACControlRegisterOnDAC power_down;
	static const SPIDACControlRegisterOnDAC reset;
};

/***********\
    Board
\***********/

struct GENPYBIND(inline_base("*")) ShiftRegisterOnBoard
    : public common::detail::RantWrapper<ShiftRegisterOnBoard, uint_fast16_t, 0, 0>
{
	constexpr explicit ShiftRegisterOnBoard(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) ADCSourceOnBoard
    : public common::detail::RantWrapper<ADCSourceOnBoard, uint_fast16_t, 9, 0>
{
	constexpr explicit ADCSourceOnBoard(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const ADCSourceOnBoard readout_chain_0;
	static const ADCSourceOnBoard readout_chain_1;
	static const ADCSourceOnBoard mux_rfu_0;
	static const ADCSourceOnBoard v_reset;
	static const ADCSourceOnBoard vdd_res_meas;
	static const ADCSourceOnBoard mux_dac_25;
	static const ADCSourceOnBoard i_ref;
	static const ADCSourceOnBoard mux_rfu_1;
	static const ADCSourceOnBoard mux_rfu_2;
	static const ADCSourceOnBoard none;
};

struct GENPYBIND(inline_base("*")) LEDOnBoard
    : public common::detail::RantWrapper<LEDOnBoard, uint_fast16_t, 5, 0>
{
	constexpr explicit LEDOnBoard(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const LEDOnBoard led_1;
	static const LEDOnBoard led_2;
	static const LEDOnBoard led_3;
	static const LEDOnBoard led_4;
	static const LEDOnBoard led_7;
	static const LEDOnBoard led_8;
};

struct DACChannelOnBoard;

struct GENPYBIND(inline_base("*")) VDDOnBoard
    : public common::detail::RantWrapper<VDDOnBoard, uint_fast16_t, 5, 0>
{
	constexpr explicit VDDOnBoard(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const VDDOnBoard vdd25_digital;
	static const VDDOnBoard vdd12_digital;
	static const VDDOnBoard vdd25_analog;
	static const VDDOnBoard vdd12_analog;
	static const VDDOnBoard vdd12_madc;
	static const VDDOnBoard vdd12_pll;

	DACChannelOnBoard toDACChannelOnBoard() const;
};

struct GENPYBIND(inline_base("*")) DACOnBoard
    : public common::detail::RantWrapper<DACOnBoard, uint_fast16_t, 1, 0>
{
	constexpr explicit DACOnBoard(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) DACChannelOnDAC
    : public common::detail::RantWrapper<DACChannelOnDAC, uint_fast16_t, 7, 0>
{
	constexpr explicit DACChannelOnDAC(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

HALCO_COORDINATE_MIXIN(DACMixin, DACOnBoard, dac)

struct GENPYBIND(inline_base("*DACMixin*")) DACChannelOnBoard
    : public DACMixin<DACChannelOnBoard, DACChannelOnDAC>
{
private:
	typedef DACMixin<DACChannelOnBoard, DACChannelOnDAC> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	DACChannelOnBoard() = default;

	explicit DACChannelOnBoard(
	    DACChannelOnDAC const& channel, DACOnBoard const& dac = DACOnBoard()) :
	    base(channel, dac)
	{}

	explicit DACChannelOnBoard(enum_type const& e) : base(e) {}

	DACChannelOnDAC toDACChannelOnDAC() const { return This(); }
	DACOnBoard toDACOnBoard() const { return split().first; }

	static const DACChannelOnBoard v_reset;
	static const DACChannelOnBoard v_res_meas;
	static const DACChannelOnBoard mux_rfu_0;
	static const DACChannelOnBoard mux_rfu_1;
	static const DACChannelOnBoard i_ref_board;
	static const DACChannelOnBoard ana_readout_debug_0;
	static const DACChannelOnBoard ana_readout_debug_1;
	static const DACChannelOnBoard mux_dac_25;

	static const DACChannelOnBoard vdd25_digital;
	static const DACChannelOnBoard vdd12_digital;
	static const DACChannelOnBoard vdd25_analog;
	static const DACChannelOnBoard vdd12_analog;
	static const DACChannelOnBoard vdd12_madc;
	static const DACChannelOnBoard vdd12_pll;
	static const DACChannelOnBoard general_purpose_0;
	static const DACChannelOnBoard general_purpose_1;

	VDDOnBoard toVDDOnBoard() const;
};

struct GENPYBIND(inline_base("*DACMixin*")) SPIDACDataRegisterOnBoard
    : public DACMixin<SPIDACDataRegisterOnBoard, SPIDACDataRegisterOnDAC>
{
private:
	typedef DACMixin<SPIDACDataRegisterOnBoard, SPIDACDataRegisterOnDAC> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	SPIDACDataRegisterOnBoard() = default;

	explicit SPIDACDataRegisterOnBoard(
	    SPIDACDataRegisterOnDAC const& channel, DACOnBoard const& dac = DACOnBoard()) :
	    base(channel, dac)
	{}

	explicit SPIDACDataRegisterOnBoard(enum_type const& e) : base(e) {}

	SPIDACDataRegisterOnDAC toSPIDACDataRegisterOnDAC() const { return This(); }
	DACOnBoard toDACOnBoard() const { return split().first; }
};

struct GENPYBIND(inline_base("*DACMixin*")) SPIDACControlRegisterOnBoard
    : public DACMixin<SPIDACControlRegisterOnBoard, SPIDACControlRegisterOnDAC>
{
private:
	typedef DACMixin<SPIDACControlRegisterOnBoard, SPIDACControlRegisterOnDAC> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	SPIDACControlRegisterOnBoard() = default;

	explicit SPIDACControlRegisterOnBoard(
	    SPIDACControlRegisterOnDAC const& channel, DACOnBoard const& dac = DACOnBoard()) :
	    base(channel, dac)
	{}

	explicit SPIDACControlRegisterOnBoard(enum_type const& e) : base(e) {}

	SPIDACControlRegisterOnDAC toSPIDACControlRegisterOnDAC() const { return This(); }
	DACOnBoard toDACOnBoard() const { return split().first; }
};

struct GENPYBIND(inline_base("*")) ADCOnBoard
    : public common::detail::RantWrapper<ADCOnBoard, uint_fast16_t, 0, 0>
{
	constexpr explicit ADCOnBoard(uintmax_t const val = 0) : rant_t(val) {}
};

/**********\
   Neuron
\**********/

struct GENPYBIND(inline_base("*")) NeuronOnNeuronBlock
    : public common::detail::RantWrapper<NeuronOnNeuronBlock, uint_fast16_t, 127, 0>
{
	constexpr explicit NeuronOnNeuronBlock(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) NeuronBlockOnDLS
    : public common::detail::RantWrapper<NeuronBlockOnDLS, uint_fast16_t, 3, 0>
{
	constexpr explicit NeuronBlockOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

HALCO_COORDINATE_MIXIN(NeuronMixin, NeuronBlockOnDLS, neuron)

struct GENPYBIND(inline_base("*NeuronMixin*")) NeuronOnDLS
    : public NeuronMixin<NeuronOnDLS, NeuronOnNeuronBlock>
{
private:
	typedef NeuronMixin<NeuronOnDLS, NeuronOnNeuronBlock> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque);

	NeuronOnDLS() = default;

	explicit NeuronOnDLS(
	    NeuronOnNeuronBlock const& neuron, NeuronBlockOnDLS const& block = NeuronBlockOnDLS()) :
	    base(neuron, block)
	{}

	explicit NeuronOnDLS(enum_type const& e) : base(e) {}

	NeuronOnNeuronBlock toNeuronOnNeuronBlock() const { return This(); }
	NeuronBlockOnDLS toNeuronBlockOnDLS() const { return split().first; }
};

struct GENPYBIND(inline_base("*")) CommonNeuronConfigOnDLS
    : public common::detail::RantWrapper<CommonNeuronConfigOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit CommonNeuronConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

/*****************\
   SynapseDriver
\*****************/

struct CommonSynapseDriverConfigOnDLS;

struct GENPYBIND(inline_base("*")) SynapseDriverOnSynapseDriverBlock
    : public common::detail::RantWrapper<SynapseDriverOnSynapseDriverBlock, uint_fast16_t, 127, 0>
{
	constexpr explicit SynapseDriverOnSynapseDriverBlock(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) SynapseDriverBlockOnDLS
    : public common::detail::RantWrapper<SynapseDriverBlockOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit SynapseDriverBlockOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CommonSynapseDriverConfigOnDLS toCommonSynapseDriverConfigOnDLS() const;

	static const SynapseDriverBlockOnDLS top;
	static const SynapseDriverBlockOnDLS bottom;
};

HALCO_COORDINATE_MIXIN(SynapseDriverMixin, SynapseDriverBlockOnDLS, synapse_driver)

struct GENPYBIND(inline_base("*SynapseDriverMixin*")) SynapseDriverOnDLS
    : public SynapseDriverMixin<SynapseDriverOnDLS, SynapseDriverOnSynapseDriverBlock>
{
private:
	typedef SynapseDriverMixin<SynapseDriverOnDLS, SynapseDriverOnSynapseDriverBlock> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque);

	SynapseDriverOnDLS() = default;

	explicit SynapseDriverOnDLS(
	    SynapseDriverOnSynapseDriverBlock const& synapse_driver, SynapseDriverBlockOnDLS const& block = SynapseDriverBlockOnDLS()) :
	    base(synapse_driver, block)
	{}

	explicit SynapseDriverOnDLS(enum_type const& e) : base(e) {}

	SynapseDriverOnSynapseDriverBlock toSynapseDriverOnSynapseDriverBlock() const { return This(); }
	SynapseDriverBlockOnDLS toSynapseDriverBlockOnDLS() const { return split().first; }
};

struct GENPYBIND(inline_base("*")) CommonSynapseDriverConfigOnDLS
    : public common::detail::RantWrapper<CommonSynapseDriverConfigOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit CommonSynapseDriverConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}

	SynapseDriverBlockOnDLS toSynapseDriverBlockOnDLS() const
	{
		return SynapseDriverBlockOnDLS(toEnum());
	}

	static const CommonSynapseDriverConfigOnDLS top;
	static const CommonSynapseDriverConfigOnDLS bottom;
};


/*****************\
   PADIBus
\*****************/

struct SynramOnDLS;
struct PADIEventOnDLS;
struct CommonPADIBusConfigOnDLS;
struct CommonSTPConfigOnDLS;

struct GENPYBIND(inline_base("*")) PADIBusBlockOnDLS
    : public common::detail::RantWrapper<PADIBusBlockOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit PADIBusBlockOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	SynramOnDLS toSynramOnDLS() const;
	PADIEventOnDLS toPADIEventOnDLS() const;
	CommonPADIBusConfigOnDLS toCommonPADIBusConfigOnDLS() const;
	CommonSTPConfigOnDLS toCommonSTPConfigOnDLS() const;

	static const PADIBusBlockOnDLS top;
	static const PADIBusBlockOnDLS bottom;
};

struct GENPYBIND(inline_base("*")) PADIBusOnPADIBusBlock
    : public common::detail::RantWrapper<PADIBusOnPADIBusBlock, uint_fast16_t, 3, 0>
{
	constexpr explicit PADIBusOnPADIBusBlock(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


HALCO_COORDINATE_MIXIN(PADIBusMixin, PADIBusBlockOnDLS, padi_bus)

struct GENPYBIND(inline_base("*PADIBusMixin*")) PADIBusOnDLS
    : public PADIBusMixin<PADIBusOnDLS, PADIBusOnPADIBusBlock>
{
private:
	typedef PADIBusMixin<PADIBusOnDLS, PADIBusOnPADIBusBlock> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque);

	PADIBusOnDLS() = default;

	explicit PADIBusOnDLS(
	    PADIBusOnPADIBusBlock const& synapse_driver, PADIBusBlockOnDLS const& block = PADIBusBlockOnDLS()) :
	    base(synapse_driver, block)
	{}

	explicit PADIBusOnDLS(enum_type const& e) : base(e) {}

	PADIBusOnPADIBusBlock toPADIBusOnPADIBusBlock() const { return This(); }
	PADIBusBlockOnDLS toPADIBusBlockOnDLS() const { return split().first; }
	CrossbarOutputOnDLS toCrossbarOutputOnDLS() const { return CrossbarOutputOnDLS(toEnum()); }
};

struct GENPYBIND(inline_base("*")) CommonPADIBusConfigOnDLS
    : public common::detail::RantWrapper<CommonPADIBusConfigOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit CommonPADIBusConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}

	PADIBusBlockOnDLS toPADIBusBlockOnDLS() const { return PADIBusBlockOnDLS(toEnum()); }

	static const CommonPADIBusConfigOnDLS top;
	static const CommonPADIBusConfigOnDLS bottom;
};

struct GENPYBIND(inline_base("*")) CommonSTPConfigOnDLS
    : public common::detail::RantWrapper<CommonSTPConfigOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit CommonSTPConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}

	PADIBusBlockOnDLS toPADIBusBlockOnDLS() const { return PADIBusBlockOnDLS(toEnum()); }

	static const CommonSTPConfigOnDLS top;
	static const CommonSTPConfigOnDLS bottom;
};

struct GENPYBIND(inline_base("*")) PADIEventOnDLS
    : public common::detail::RantWrapper<PADIEventOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit PADIEventOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	PADIBusBlockOnDLS toPADIBusBlockOnDLS() const { return PADIBusBlockOnDLS(toEnum()); }

	static const PADIEventOnDLS top;
	static const PADIEventOnDLS bottom;
};

/**********\
   CapMem
\**********/

constexpr size_t num_block_global_capmem_column = 2;

// Max value is num_block_global_capmem_column larger than neuron max due to global capmem columns
struct GENPYBIND(inline_base("*")) CapMemColumnOnCapMemBlock
    : public common::detail::RantWrapper<
          CapMemColumnOnCapMemBlock,
          NeuronOnNeuronBlock::value_type,
          NeuronOnNeuronBlock::max + num_block_global_capmem_column,
          NeuronOnNeuronBlock::min>
    , public common::detail::XRangedTrait
{
	constexpr explicit CapMemColumnOnCapMemBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
	constexpr explicit CapMemColumnOnCapMemBlock(common::X const& x)
	    GENPYBIND(implicit_conversion) :
	    rant_t(x)
	{}
	static const CapMemColumnOnCapMemBlock SharedCapMemColumnOnCapMemBlock;

	bool isShared() const { return value() > (max - num_block_global_capmem_column); }
};

struct GENPYBIND(inline_base("*")) CapMemRowOnCapMemBlock
    : public common::detail::RantWrapper<CapMemRowOnCapMemBlock, uint_fast16_t, 23, 0>
    , public common::detail::YRangedTrait
{
	constexpr explicit CapMemRowOnCapMemBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
	constexpr explicit CapMemRowOnCapMemBlock(common::Y const& y) GENPYBIND(implicit_conversion) :
	    rant_t(y)
	{}
};

struct GENPYBIND(inline_base("*")) CapMemBlockOnDLS
    : public common::detail::RantWrapper<CapMemBlockOnDLS, uint_fast16_t, 3, 0>
{
	constexpr explicit CapMemBlockOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) CapMemBlockConfigOnDLS
    : public common::detail::
          RantWrapper<CapMemBlockConfigOnDLS, uint_fast16_t, CapMemBlockOnDLS::max, 0>
{
	constexpr explicit CapMemBlockConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) CapMemCellOnCapMemBlock
    : public common::detail::
          GridCoordinate<CapMemCellOnCapMemBlock, CapMemColumnOnCapMemBlock, CapMemRowOnCapMemBlock>
{
	GRID_COMMON_CONSTRUCTORS(CapMemCellOnCapMemBlock)

	CapMemColumnOnCapMemBlock toCapMemColumnOnCapMemBlock() const { return x(); }
	CapMemRowOnCapMemBlock toCapMemRowOnCapMemBlock() const { return y(); }

	bool isShared() const;
};

HALCO_COORDINATE_MIXIN(CapMemMixin, CapMemBlockOnDLS, capmem)

struct GENPYBIND(inline_base("*CapMemMixin*")) CapMemCellOnDLS
    : public CapMemMixin<CapMemCellOnDLS, CapMemCellOnCapMemBlock>
{
private:
	typedef CapMemMixin<CapMemCellOnDLS, CapMemCellOnCapMemBlock> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque);

	CapMemCellOnDLS() = default;

	explicit CapMemCellOnDLS(
	    CapMemCellOnCapMemBlock const& cell, CapMemBlockOnDLS const& block = CapMemBlockOnDLS()) :
	    base(cell, block)
	{}

	explicit CapMemCellOnDLS(enum_type const& e) : base(e) {}

	CapMemCellOnCapMemBlock toCapMemCellOnCapMemBlock() const { return This(); }
	CapMemBlockOnDLS toCapMemBlockOnDLS() const { return split().first; }
};

struct GENPYBIND(inline_base("*CapMemMixin*")) CapMemRowOnDLS
    : public CapMemMixin<CapMemRowOnDLS, CapMemRowOnCapMemBlock>
{
private:
	typedef CapMemMixin<CapMemRowOnDLS, CapMemRowOnCapMemBlock> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque);

	CapMemRowOnDLS() = default;

	explicit CapMemRowOnDLS(
	    CapMemRowOnCapMemBlock const& row, CapMemBlockOnDLS const& block = CapMemBlockOnDLS()) :
	    base(row, block)
	{}

	explicit CapMemRowOnDLS(enum_type const& e) : base(e) {}

	CapMemRowOnCapMemBlock toCapMemRowOnCapMemBlock() const { return This(); }
	CapMemBlockOnDLS toCapMemBlockOnDLS() const { return split().first; }
};

struct GENPYBIND(inline_base("*CapMemMixin*")) CapMemColumnOnDLS
    : public CapMemMixin<CapMemColumnOnDLS, CapMemColumnOnCapMemBlock>
{
private:
	typedef CapMemMixin<CapMemColumnOnDLS, CapMemColumnOnCapMemBlock> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque);

	CapMemColumnOnDLS() = default;

	explicit CapMemColumnOnDLS(
	    CapMemColumnOnCapMemBlock const& col, CapMemBlockOnDLS const& block = CapMemBlockOnDLS()) :
	    base(col, block)
	{}

	explicit CapMemColumnOnDLS(enum_type const& e) : base(e) {}

	CapMemColumnOnCapMemBlock toCapMemColumnOnCapMemBlock() const { return This(); }
	CapMemBlockOnDLS toCapMemBlockOnDLS() const { return split().first; }
};

/************\
    Synram
\************/

struct SynramOnDLS;

struct GENPYBIND(inline_base("*")) CommonSynramConfigOnDLS
    : public common::detail::RantWrapper<CommonSynramConfigOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit CommonSynramConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	PPUOnDLS toPPUOnDLS() const { return PPUOnDLS(toEnum()); }
	SynramOnDLS toSynramOnDLS() const;

	static const CommonSynramConfigOnDLS top;
	static const CommonSynramConfigOnDLS bottom;
};

/***********\
   Synapse
\***********/

struct GENPYBIND(inline_base("*")) SynapseQuadColumnOnDLS
    : public common::detail::RantWrapper<
          SynapseQuadColumnOnDLS,
          uint_fast16_t,
          NeuronOnNeuronBlock::size * 2 / 4 - 1,
          0>
    , public common::detail::XRangedTrait
{
	constexpr explicit SynapseQuadColumnOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	constexpr explicit SynapseQuadColumnOnDLS(common::X const& x) GENPYBIND(implicit_conversion) :
	    rant_t(x)
	{}
};

struct GENPYBIND(inline_base("*")) SynapseRowOnSynram
    : public common::detail::RantWrapper<SynapseRowOnSynram, uint_fast16_t, 255, 0>
    , public common::detail::YRangedTrait
{
	constexpr explicit SynapseRowOnSynram(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	constexpr explicit SynapseRowOnSynram(common::Y const& y) GENPYBIND(implicit_conversion) :
	    rant_t(y)
	{}
};

struct GENPYBIND(inline_base("*")) SynapseQuadOnSynram
    : public common::detail::
          GridCoordinate<SynapseQuadOnSynram, SynapseQuadColumnOnDLS, SynapseRowOnSynram>
{
	GRID_COMMON_CONSTRUCTORS(SynapseQuadOnSynram)

	SynapseQuadColumnOnDLS toSynapseQuadColumnOnDLS() const { return x(); }
	SynapseRowOnSynram toSynapseRowOnSynram() const { return y(); }
};

struct GENPYBIND(inline_base("*")) SynramOnDLS
    : public common::detail::RantWrapper<SynramOnDLS, uint_fast16_t, PPUOnDLS::max, PPUOnDLS::min>
{
	constexpr explicit SynramOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CommonSynramConfigOnDLS toCommonSynramConfigOnDLS() const
	{
		return CommonSynramConfigOnDLS(toEnum());
	}
	PPUOnDLS toPPUOnDLS() const { return PPUOnDLS(toEnum()); }

	static const SynramOnDLS top;
	static const SynramOnDLS bottom;
};

HALCO_COORDINATE_MIXIN(SynramMixin, SynramOnDLS, synram)

struct GENPYBIND(inline_base("*SynramMixin*")) SynapseQuadOnDLS
    : public SynramMixin<SynapseQuadOnDLS, SynapseQuadOnSynram>
{
private:
	typedef SynramMixin<SynapseQuadOnDLS, SynapseQuadOnSynram> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	SynapseQuadOnDLS() = default;

	explicit SynapseQuadOnDLS(
	    SynapseQuadOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    base(block, synram)
	{}

	explicit SynapseQuadOnDLS(enum_type const& e) : base(e) {}

	SynapseQuadOnSynram toSynapseQuadOnSynram() const { return This(); }
	SynramOnDLS toSynramOnDLS() const { return split().first; }
};

struct GENPYBIND(inline_base("*")) SynapseOnSynapseQuad
    : public common::detail::RantWrapper<SynapseOnSynapseQuad, uint_fast16_t, 3, 0>
{
	constexpr explicit SynapseOnSynapseQuad(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

/************************\
  ColumnCorrelationQuad
\************************/

struct GENPYBIND(inline_base("*")) ColumnCorrelationQuadOnSynram
    : public common::detail::RantWrapper<
          ColumnCorrelationQuadOnSynram,
          uint_fast16_t,
          SynapseQuadColumnOnDLS::max,
          SynapseQuadColumnOnDLS::min>
    , public common::detail::XRangedTrait
{
	constexpr explicit ColumnCorrelationQuadOnSynram(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	constexpr explicit ColumnCorrelationQuadOnSynram(common::X const& x)
	    GENPYBIND(implicit_conversion) :
	    rant_t(x)
	{}
};

struct GENPYBIND(inline_base("*SynramMixin*")) ColumnCorrelationQuadOnDLS
    : public SynramMixin<ColumnCorrelationQuadOnDLS, ColumnCorrelationQuadOnSynram>
{
private:
	typedef SynramMixin<ColumnCorrelationQuadOnDLS, ColumnCorrelationQuadOnSynram> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	ColumnCorrelationQuadOnDLS() = default;

	explicit ColumnCorrelationQuadOnDLS(
	    ColumnCorrelationQuadOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    base(block, synram)
	{}

	explicit ColumnCorrelationQuadOnDLS(enum_type const& e) : base(e) {}

	ColumnCorrelationQuadOnSynram toColumnCorrelationQuadOnSynram() const { return This(); }
	SynramOnDLS toSynramOnDLS() const { return split().first; }
};

struct GENPYBIND(inline_base("*")) ColumnCorrelationSwitchOnColumnCorrelationQuad
    : public common::detail::
          RantWrapper<ColumnCorrelationSwitchOnColumnCorrelationQuad, uint_fast16_t, 3, 0>
{
	constexpr explicit ColumnCorrelationSwitchOnColumnCorrelationQuad(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

/********************\
  ColumnCurrentQuad
\********************/

struct GENPYBIND(inline_base("*")) ColumnCurrentQuadOnSynram
    : public common::detail::RantWrapper<
          ColumnCurrentQuadOnSynram,
          uint_fast16_t,
          SynapseQuadColumnOnDLS::max,
          SynapseQuadColumnOnDLS::min>
    , public common::detail::XRangedTrait
{
	constexpr explicit ColumnCurrentQuadOnSynram(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	constexpr explicit ColumnCurrentQuadOnSynram(common::X const& x)
	    GENPYBIND(implicit_conversion) :
	    rant_t(x)
	{}
};

struct GENPYBIND(inline_base("*SynramMixin*")) ColumnCurrentQuadOnDLS
    : public SynramMixin<ColumnCurrentQuadOnDLS, ColumnCurrentQuadOnSynram>
{
private:
	typedef SynramMixin<ColumnCurrentQuadOnDLS, ColumnCurrentQuadOnSynram> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	ColumnCurrentQuadOnDLS() = default;

	explicit ColumnCurrentQuadOnDLS(
	    ColumnCurrentQuadOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    base(block, synram)
	{}

	explicit ColumnCurrentQuadOnDLS(enum_type const& e) : base(e) {}

	ColumnCurrentQuadOnSynram toColumnCurrentQuadOnSynram() const { return This(); }
	SynramOnDLS toSynramOnDLS() const { return split().first; }
};

struct GENPYBIND(inline_base("*")) ColumnCurrentSwitchOnColumnCurrentQuad
    : public common::detail::
          RantWrapper<ColumnCurrentSwitchOnColumnCurrentQuad, uint_fast16_t, 3, 0>
{
	constexpr explicit ColumnCurrentSwitchOnColumnCurrentQuad(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

} // namespace vx
} // namespace hicann_dls
} // namespace halco

// std::hash specializations
namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::FPGADeviceDNAOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NullPayloadReadableOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::HicannARQStatusOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::BackgroundSpikeSourceOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CrossbarOutputConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CrossbarOutputOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CrossbarL2OutputOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CrossbarInputOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CrossbarNodeOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PerfTestOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PerfTestStatusOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikePack1ToChipOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikePack2ToChipOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikePack3ToChipOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikePackFromFPGAOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::MADCSamplePackFromFPGAOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SystimeSyncOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SystimeSyncBaseOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryWordOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryWordOnPPU)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryBlockOnPPU)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryOnPPU)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryBlockSize)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUStatusRegisterOnPPU)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUStatusRegisterOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUControlRegisterOnPPU)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUControlRegisterOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronLabel)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SPL1Address)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ADPLLOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PLLClockOutputOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PLLSelfTestOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PLLSelfTestStatusOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PLLClockOutputBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ResetChipOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ResetJTAGTapOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::JTAGClockScalerOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::JTAGIdCodeOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::JTAGPLLRegisterOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::JTAGPhyRegisterOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PhyConfigFPGAOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PhyConfigChipOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PhyStatusOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonPhyConfigFPGAOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonPhyConfigChipOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::TimerOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::OmnibusChipOverJTAGAddress)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::OmnibusChipAddress)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::OmnibusFPGAAddress)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ShiftRegisterOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SPIDACDataRegisterOnDAC)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SPIDACControlRegisterOnDAC)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SPIDACDataRegisterOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SPIDACControlRegisterOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ADCSourceOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::LEDOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::VDDOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::DACOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::DACChannelOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::DACChannelOnDAC)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ADCOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronOnNeuronBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonNeuronConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseDriverOnSynapseDriverBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseDriverBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseDriverOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonSynapseDriverConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemColumnOnCapMemBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemRowOnCapMemBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemBlockConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemCellOnCapMemBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemCellOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemRowOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemColumnOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonSynramConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CIdRegisterOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CINA219RoRegisterOnINA219)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CINA219RwRegisterOnINA219)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::INA219OnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CINA219RoRegisterOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::I2CINA219RwRegisterOnBoard)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseQuadColumnOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseRowOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynramOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseOnSynapseQuad)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PADIBusOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PADIBusBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PADIBusOnPADIBusBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PADIEventOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonPADIBusConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonSTPConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ColumnCorrelationQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ColumnCurrentQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ColumnCorrelationQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ColumnCurrentQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ColumnCorrelationSwitchOnColumnCorrelationQuad)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ColumnCurrentSwitchOnColumnCurrentQuad)

} // namespace std

GENPYBIND(postamble, tag(hicann_dls_vx))
GENPYBIND_MANUAL({
	parent->py::module::import("pyhalco_hicann_dls_vx_patch").attr("patch")(parent);
})
