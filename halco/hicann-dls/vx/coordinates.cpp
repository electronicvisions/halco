#include "halco/hicann-dls/vx/coordinates.h"

namespace halco {
namespace hicann_dls {
namespace vx {

using namespace halco::common;

PLLClockOutputOnDLS const PLLClockOutputOnDLS::SerdesSerSendClk{0};
PLLClockOutputOnDLS const PLLClockOutputOnDLS::PhyRefClk{1};
PLLClockOutputOnDLS const PLLClockOutputOnDLS::PPUClk{2};
PLLClockOutputOnDLS const PLLClockOutputOnDLS::MADCClk{3};

LEDOnBoard const LEDOnBoard::LED1{0};
LEDOnBoard const LEDOnBoard::LED2{1};
LEDOnBoard const LEDOnBoard::LED3{2};
LEDOnBoard const LEDOnBoard::LED4{3};
LEDOnBoard const LEDOnBoard::LED7{4};
LEDOnBoard const LEDOnBoard::LED8{5};

VDDOnBoard const VDDOnBoard::VDD25Digital{0};
VDDOnBoard const VDDOnBoard::VDD12Digital{1};
VDDOnBoard const VDDOnBoard::VDD25Analog{2};
VDDOnBoard const VDDOnBoard::VDD12Analog{3};
VDDOnBoard const VDDOnBoard::VDD12MADC{4};
VDDOnBoard const VDDOnBoard::VDD12Pll{5};

ADCSourceOnBoard const ADCSourceOnBoard::ReadoutChain0{0};
ADCSourceOnBoard const ADCSourceOnBoard::ReadoutChain1{1};
ADCSourceOnBoard const ADCSourceOnBoard::MuxRfu0{2};
ADCSourceOnBoard const ADCSourceOnBoard::VReset{3};
ADCSourceOnBoard const ADCSourceOnBoard::VDDResMeas{4};
ADCSourceOnBoard const ADCSourceOnBoard::MuxDAC25{5};
ADCSourceOnBoard const ADCSourceOnBoard::IRef{6};
ADCSourceOnBoard const ADCSourceOnBoard::MuxRfu1{7};
ADCSourceOnBoard const ADCSourceOnBoard::MuxRfu2{8};
ADCSourceOnBoard const ADCSourceOnBoard::None{9};

DACChannelOnBoard const DACChannelOnBoard::VReset{DACChannelOnDAC(0), DACOnBoard(0)};
DACChannelOnBoard const DACChannelOnBoard::VResMeas{DACChannelOnDAC(1), DACOnBoard(0)};
DACChannelOnBoard const DACChannelOnBoard::MuxRfu0{DACChannelOnDAC(2), DACOnBoard(0)};
DACChannelOnBoard const DACChannelOnBoard::MuxRfu1{DACChannelOnDAC(3), DACOnBoard(0)};
DACChannelOnBoard const DACChannelOnBoard::IRefBoard{DACChannelOnDAC(4), DACOnBoard(0)};
DACChannelOnBoard const DACChannelOnBoard::AnaReadoutDebug0{DACChannelOnDAC(5), DACOnBoard(0)};
DACChannelOnBoard const DACChannelOnBoard::AnaReadoutDebug1{DACChannelOnDAC(6), DACOnBoard(0)};
DACChannelOnBoard const DACChannelOnBoard::MuxDAC25{DACChannelOnDAC(7), DACOnBoard(0)};

DACChannelOnBoard const DACChannelOnBoard::VDD25Digital{DACChannelOnDAC(0), DACOnBoard(1)};
DACChannelOnBoard const DACChannelOnBoard::VDD12Digital{DACChannelOnDAC(1), DACOnBoard(1)};
DACChannelOnBoard const DACChannelOnBoard::VDD25Analog{DACChannelOnDAC(2), DACOnBoard(1)};
DACChannelOnBoard const DACChannelOnBoard::VDD12Analog{DACChannelOnDAC(3), DACOnBoard(1)};
DACChannelOnBoard const DACChannelOnBoard::VDD12MADC{DACChannelOnDAC(4), DACOnBoard(1)};
DACChannelOnBoard const DACChannelOnBoard::VDD12Pll{DACChannelOnDAC(5), DACOnBoard(1)};
DACChannelOnBoard const DACChannelOnBoard::GeneralPurpose0{DACChannelOnDAC(6), DACOnBoard(1)};
DACChannelOnBoard const DACChannelOnBoard::GeneralPurpose1{DACChannelOnDAC(7), DACOnBoard(1)};

DACChannelOnBoard VDDOnBoard::toDACChannelOnBoard() const
{
	return DACChannelOnBoard(DACChannelOnDAC(toEnum()), DACOnBoard(1));
}

VDDOnBoard DACChannelOnBoard::toVDDOnBoard() const
{
	if ((toDACOnBoard() == DACOnBoard(1)) && (toDACChannelOnDAC() <= DACChannelOnDAC(5))) {
		return VDDOnBoard(toDACChannelOnDAC().toEnum());
	}
	throw std::logic_error("DAC channel not convertible to VDDOnBoard.");
}

} // namespace vx
} // namespace hicann_dls
} // namespace halco
