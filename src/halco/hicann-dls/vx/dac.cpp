#include "halco/hicann-dls/vx/dac.h"

#include "halco/hicann-dls/vx/xboard.h"

namespace halco::hicann_dls::vx {

DACChannelOnBoard const DACChannelOnBoard::v_reset{DACChannelOnDAC(0), DACOnBoard(0)};
DACChannelOnBoard const DACChannelOnBoard::v_res_meas{DACChannelOnDAC(1), DACOnBoard(0)};
DACChannelOnBoard const DACChannelOnBoard::mux_rfu_0{DACChannelOnDAC(2), DACOnBoard(0)};
DACChannelOnBoard const DACChannelOnBoard::mux_rfu_1{DACChannelOnDAC(3), DACOnBoard(0)};
DACChannelOnBoard const DACChannelOnBoard::i_ref_board{DACChannelOnDAC(4), DACOnBoard(0)};
DACChannelOnBoard const DACChannelOnBoard::ana_readout_debug_0{DACChannelOnDAC(5), DACOnBoard(0)};
DACChannelOnBoard const DACChannelOnBoard::ana_readout_debug_1{DACChannelOnDAC(6), DACOnBoard(0)};
DACChannelOnBoard const DACChannelOnBoard::mux_dac_25{DACChannelOnDAC(7), DACOnBoard(0)};

DACChannelOnBoard const DACChannelOnBoard::vdd25_digital{DACChannelOnDAC(0), DACOnBoard(1)};
DACChannelOnBoard const DACChannelOnBoard::vdd12_digital{DACChannelOnDAC(1), DACOnBoard(1)};
DACChannelOnBoard const DACChannelOnBoard::vdd25_analog{DACChannelOnDAC(2), DACOnBoard(1)};
DACChannelOnBoard const DACChannelOnBoard::vdd12_analog{DACChannelOnDAC(3), DACOnBoard(1)};
DACChannelOnBoard const DACChannelOnBoard::vdd12_madc{DACChannelOnDAC(4), DACOnBoard(1)};
DACChannelOnBoard const DACChannelOnBoard::vdd12_pll{DACChannelOnDAC(5), DACOnBoard(1)};
DACChannelOnBoard const DACChannelOnBoard::general_purpose_0{DACChannelOnDAC(6), DACOnBoard(1)};
DACChannelOnBoard const DACChannelOnBoard::general_purpose_1{DACChannelOnDAC(7), DACOnBoard(1)};

VDDOnBoard DACChannelOnBoard::toVDDOnBoard() const
{
	if ((toDACOnBoard() == DACOnBoard(1)) && (toDACChannelOnDAC() <= DACChannelOnDAC(5))) {
		return VDDOnBoard(toDACChannelOnDAC().toEnum());
	}
	throw std::logic_error("DAC channel not convertible to VDDOnBoard.");
}

} // namespace halco::hicann_dls::vx
