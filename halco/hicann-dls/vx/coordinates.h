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

class PPUOnDLS;

/*************************\
   BackgroundSpikeSource
\*************************/

struct GENPYBIND(inline_base("*")) BackgroundSpikeSourceOnDLS
    : public common::detail::RantWrapper<BackgroundSpikeSourceOnDLS, uint_fast16_t, 7, 0>
{
	constexpr explicit BackgroundSpikeSourceOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
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

struct GENPYBIND(inline_base("*")) PLLOnDLS
    : public common::detail::RantWrapper<PLLOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit PLLOnDLS(uintmax_t const val = 0) : rant_t(val) {}
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

	static const PLLClockOutputOnDLS SerdesSerSendClk;
	static const PLLClockOutputOnDLS PhyRefClk;
	static const PLLClockOutputOnDLS PPUClk;
	static const PLLClockOutputOnDLS MADCClk;
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

	static const SPIDACControlRegisterOnDAC GainReference;
	static const SPIDACControlRegisterOnDAC LDAC;
	static const SPIDACControlRegisterOnDAC PowerDown;
	static const SPIDACControlRegisterOnDAC Reset;
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

	static const ADCSourceOnBoard ReadoutChain0;
	static const ADCSourceOnBoard ReadoutChain1;
	static const ADCSourceOnBoard MuxRfu0;
	static const ADCSourceOnBoard VReset;
	static const ADCSourceOnBoard VDDResMeas;
	static const ADCSourceOnBoard MuxDAC25;
	static const ADCSourceOnBoard IRef;
	static const ADCSourceOnBoard MuxRfu1;
	static const ADCSourceOnBoard MuxRfu2;
	static const ADCSourceOnBoard None;
};

struct GENPYBIND(inline_base("*")) LEDOnBoard
    : public common::detail::RantWrapper<LEDOnBoard, uint_fast16_t, 5, 0>
{
	constexpr explicit LEDOnBoard(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const LEDOnBoard LED1;
	static const LEDOnBoard LED2;
	static const LEDOnBoard LED3;
	static const LEDOnBoard LED4;
	static const LEDOnBoard LED7;
	static const LEDOnBoard LED8;
};

struct DACChannelOnBoard;

struct GENPYBIND(inline_base("*")) VDDOnBoard
    : public common::detail::RantWrapper<VDDOnBoard, uint_fast16_t, 5, 0>
{
	constexpr explicit VDDOnBoard(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const VDDOnBoard VDD25Digital;
	static const VDDOnBoard VDD12Digital;
	static const VDDOnBoard VDD25Analog;
	static const VDDOnBoard VDD12Analog;
	static const VDDOnBoard VDD12MADC;
	static const VDDOnBoard VDD12Pll;

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

	static const DACChannelOnBoard VReset;
	static const DACChannelOnBoard VResMeas;
	static const DACChannelOnBoard MuxRfu0;
	static const DACChannelOnBoard MuxRfu1;
	static const DACChannelOnBoard IRefBoard;
	static const DACChannelOnBoard AnaReadoutDebug0;
	static const DACChannelOnBoard AnaReadoutDebug1;
	static const DACChannelOnBoard MuxDAC25;

	static const DACChannelOnBoard VDD25Digital;
	static const DACChannelOnBoard VDD12Digital;
	static const DACChannelOnBoard VDD25Analog;
	static const DACChannelOnBoard VDD12Analog;
	static const DACChannelOnBoard VDD12MADC;
	static const DACChannelOnBoard VDD12Pll;
	static const DACChannelOnBoard GeneralPurpose0;
	static const DACChannelOnBoard GeneralPurpose1;

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

	bool isShared() const { return value() == max; }
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
          RantWrapper<CapMemBlockConfigOnDLS, uint_fast16_t, CapMemBlockOnDLS::end, 0>
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

} // namespace vx
} // namespace hicann_dls
} // namespace halco

// std::hash specializations
namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::BackgroundSpikeSourceOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PerfTestOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PerfTestStatusOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikePack1ToChipOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikePack2ToChipOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikePack3ToChipOnDLS)
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
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PLLOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ResetChipOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ResetJTAGTapOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::JTAGClockScalerOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::JTAGIdCodeOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::JTAGPLLRegisterOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::JTAGPhyRegisterOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PhyConfigFPGAOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PhyConfigChipOnDLS)
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
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemColumnOnCapMemBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemRowOnCapMemBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemBlockConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemCellOnCapMemBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemCellOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemRowOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CapMemColumnOnDLS)

} // namespace std

GENPYBIND(postamble, tag(hicann_dls_vx))
GENPYBIND_MANUAL({
	parent->py::module::import("pyhalco_hicann_dls_vx_patch").attr("patch")(parent);
})
