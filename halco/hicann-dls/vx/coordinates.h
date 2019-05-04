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

/**********\
    PPU
\**********/


struct GENPYBIND(inline_base("*")) PPUOnDLS
    : public common::detail::RantWrapper<PPUOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit PPUOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) PPUMemoryWordOnPPU
    : public common::detail::RantWrapper<PPUMemoryWordOnPPU, uint_fast16_t, 0x1000 - 1, 0>
{
	constexpr explicit PPUMemoryWordOnPPU(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

HALCO_COORDINATE_MIXIN(PPUMixin, PPUOnDLS, ppu)

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

struct GENPYBIND(inline_base("*")) JTAGOnDLS
    : public common::detail::RantWrapper<JTAGOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit JTAGOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) JTAGPLLRegisterOnDLS
    : public common::detail::RantWrapper<JTAGPLLRegisterOnDLS, uint_fast16_t, 7, 0>
{
	constexpr explicit JTAGPLLRegisterOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

/**********\
    Phy
\**********/

struct GENPYBIND(inline_base("*")) PhyOnDLS
    : public common::detail::RantWrapper<PhyOnDLS, uint_fast16_t, 7, 0>
{
	constexpr explicit PhyOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) PhyBlockOnDLS
    : public common::detail::RantWrapper<PhyBlockOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit PhyBlockOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
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

struct GENPYBIND(inline_base("*")) OmnibusAddress
    : public common::detail::BaseType<OmnibusAddress, uint32_t>
{
	constexpr explicit OmnibusAddress(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
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
	constexpr explicit SPIDACDataRegisterOnDAC(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) SPIDACControlRegisterOnDAC
    : public common::detail::RantWrapper<SPIDACControlRegisterOnDAC, uint_fast16_t, 3, 0>
{
	constexpr explicit SPIDACControlRegisterOnDAC(uintmax_t const val = 0) : rant_t(val) {}

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
	constexpr explicit DACOnBoard(uintmax_t const val = 0) : rant_t(val) {}
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

} // namespace vx
} // namespace hicann_dls
} // namespace halco

// std::hash specializations
namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryWordOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryWordOnPPU)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ADPLLOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PLLClockOutputOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PLLOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ResetChipOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::JTAGOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::JTAGPLLRegisterOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PhyOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PhyBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::TimerOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::OmnibusAddress)
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

} // namespace std

GENPYBIND(postamble, tag(hicann_dls_vx))
GENPYBIND_MANUAL({
	parent->py::module::import("pyhalco_hicann_dls_vx_patch").attr("patch")(parent);
})
