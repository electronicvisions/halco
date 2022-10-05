#include "halco/hicann-dls/vx/extoll.h"

namespace halco::hicann_dls::vx {

EventSwitchSourceOnFPGA const EventSwitchSourceOnFPGA::to_executor{0};
EventSwitchSourceOnFPGA const EventSwitchSourceOnFPGA::to_asic{1};
EventSwitchSourceOnFPGA const EventSwitchSourceOnFPGA::to_external{2};

EventSwitchReadoutOnFPGA const EventSwitchReadoutOnFPGA::systime_offset{0};
EventSwitchReadoutOnFPGA const EventSwitchReadoutOnFPGA::global_systime{1};
EventSwitchReadoutOnFPGA const EventSwitchReadoutOnFPGA::last_global_systime{2};

ExtollNodeId const ExtollNodeId::self{0x10000ull};

ExtollChipType const ExtollChipType::fpga{0};
ExtollChipType const ExtollChipType::tourmalet{1};
}