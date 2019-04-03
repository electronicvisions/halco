#include "halco/hicann-dls/vx/coordinates.h"

namespace halco {
namespace hicann_dls {
namespace vx {

using namespace halco::common;

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
ADCSourceOnBoard const ADCSourceOnBoard::MuxDac25{5};
ADCSourceOnBoard const ADCSourceOnBoard::IRef{6};
ADCSourceOnBoard const ADCSourceOnBoard::MuxRfu1{7};
ADCSourceOnBoard const ADCSourceOnBoard::MuxRfu2{8};
ADCSourceOnBoard const ADCSourceOnBoard::None{9};

} // namespace vx
} // namespace hicann_dls
} // namespace halco
