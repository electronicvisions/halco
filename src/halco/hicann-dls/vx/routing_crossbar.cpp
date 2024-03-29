#include "halco/hicann-dls/vx/routing_crossbar.h"

#include "halco/common/lookup_tables_helper.h"
#include "halco/hicann-dls/vx/event.h"
#include "halco/hicann-dls/vx/neuron.h"
#include "halco/hicann-dls/vx/padi.h"

#ifdef __ppu__
extern void exit(int32_t);
#endif

namespace halco::hicann_dls::vx {

std::optional<PADIBusOnDLS> CrossbarOutputOnDLS::toPADIBusOnDLS() const
{
	if (toEnum() >= PADIBusOnDLS::size) {
		return std::nullopt;
	}
	return PADIBusOnDLS(toEnum());
}

std::optional<CrossbarL2OutputOnDLS> CrossbarOutputOnDLS::toCrossbarL2OutputOnDLS() const
{
	if (toPADIBusOnDLS()) {
		return std::nullopt;
	}
	return CrossbarL2OutputOnDLS(toEnum() - PADIBusOnDLS::size);
}

CrossbarOutputOnDLS CrossbarL2OutputOnDLS::toCrossbarOutputOnDLS() const
{
	return CrossbarOutputOnDLS(
	    toEnum() + (CrossbarOutputOnDLS::size - CrossbarL2OutputOnDLS::size));
}

std::optional<SPL1Address> CrossbarInputOnDLS::toSPL1Address() const
{
	if ((toEnum() < NeuronEventOutputOnDLS::size) ||
	    toEnum() >= (NeuronEventOutputOnDLS::size + SPL1Address::size)) {
		return std::nullopt;
	}
	return SPL1Address(toEnum() - NeuronEventOutputOnDLS::size);
}

std::optional<NeuronEventOutputOnDLS> CrossbarInputOnDLS::toNeuronEventOutputOnDLS() const
{
	if (toEnum() >= NeuronEventOutputOnDLS::size) {
		return std::nullopt;
	}
	return NeuronEventOutputOnDLS(toEnum());
}

// clang-format off
std::array<std::pair<int, int>, CrossbarNodeOnDLS::size> const CrossbarNodeOnDLSGrid = {
    {{ 0,  0},                               { 4,  0},                               { 8,  0},
               { 1,  1},                               { 5,  1},                               { 9,  1},
                         { 2,  2},                               { 6,  2},                               {10,  2},
                                   { 3,  3},                               { 7,  3},                               {11,  3},

     { 0,  4},                               { 4,  4},                               { 8,  4},
               { 1,  5},                               { 5,  5},                               { 9,  5},
                         { 2,  6},                               { 6,  6},                               {10,  6},
                                   { 3,  7},                               { 7,  7},                               {11,  7},
     { 0,  8}, { 1,  8}, { 2,  8}, { 3,  8}, { 4,  8}, { 5,  8}, { 6,  8}, { 7,  8}, { 8,  8},
     { 0,  9}, { 1,  9}, { 2,  9}, { 3,  9}, { 4,  9}, { 5,  9}, { 6,  9}, { 7,  9},           { 9,  9},
     { 0, 10}, { 1, 10}, { 2, 10}, { 3, 10}, { 4, 10}, { 5, 10}, { 6, 10}, { 7, 10},                     {10, 10},
     { 0, 11}, { 1, 11}, { 2, 11}, { 3, 11}, { 4, 11}, { 5, 11}, { 6, 11}, { 7, 11},                               {11, 11},
     { 0, 12},                                                                       { 8, 12},
               { 1, 13},                                                                       { 9, 13},
                         { 2, 14},                                                                       {10, 14},
                                   { 3, 15},                                                                       {11, 15},
                                             { 4, 16},                               { 8, 16},
                                                       { 5, 17},                               { 9, 17},
                                                                 { 6, 18},                               {10, 18},
                                                                           { 7, 19},                               {11, 19}
}};
// clang-format on

auto const CrossbarNodeOnDLSEnum = halco::common::detail::
    generateEnum<CrossbarInputOnDLS::size, CrossbarOutputOnDLS::size, CrossbarNodeOnDLS::size>(
        CrossbarNodeOnDLSGrid);

CrossbarNodeOnDLS::x_type CrossbarNodeOnDLS::to_x(enum_type const& e)
{
	return x_type(CrossbarNodeOnDLSGrid.at(e).first);
}

CrossbarNodeOnDLS::y_type CrossbarNodeOnDLS::to_y(enum_type const& e)
{
	return y_type(CrossbarNodeOnDLSGrid.at(e).second);
}

CrossbarNodeOnDLS::enum_type CrossbarNodeOnDLS::to_enum(x_type const& x, y_type const& y)
{
	// throws out_of_range if x or y is not available on wafer.
	int const en = CrossbarNodeOnDLSEnum.at(y).at(x);
	if (en == halco::common::detail::invalid)
#ifndef __ppu__
		throw std::domain_error("Invalid combination of X and Y for a CrossbarNode");
#else
		exit(1);
#endif
	return enum_type(en);
}

} // namespace halco::hicann_dls::vx
