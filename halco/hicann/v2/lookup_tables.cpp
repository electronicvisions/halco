#include "halco/hicann/v2/lookup_tables.h"

#include <cstdlib>
#include <cassert>
#include <cstring>
#include <type_traits>

#include <boost/serialization/map.hpp>

using namespace std;
using namespace halco::common;

namespace halco {
namespace hicann {
namespace v2 {

// clang-format off

// this is pretty ugly, but somehow I need to define the wafer grid ... ASCII art for the win
array< pair<int, int>, 384 >  const HICANNOnWaferGrid = {{
                                                                                                                                                            {{12},{ 0}}, {{13},{ 0}}, {{14},{ 0}}, {{15},{ 0}}, {{16},{ 0}}, {{17},{ 0}}, {{18},{ 0}}, {{19},{ 0}}, {{20},{ 0}}, {{21},{ 0}}, {{22},{ 0}}, {{23},{ 0}},

                                                                                                                                                            {{12},{ 1}}, {{13},{ 1}}, {{14},{ 1}}, {{15},{ 1}}, {{16},{ 1}}, {{17},{ 1}}, {{18},{ 1}}, {{19},{ 1}}, {{20},{ 1}}, {{21},{ 1}}, {{22},{ 1}}, {{23},{ 1}},

                                                                                                        {{ 8},{ 2}}, {{ 9},{ 2}}, {{10},{ 2}}, {{11},{ 2}}, {{12},{ 2}}, {{13},{ 2}}, {{14},{ 2}}, {{15},{ 2}}, {{16},{ 2}}, {{17},{ 2}}, {{18},{ 2}}, {{19},{ 2}}, {{20},{ 2}}, {{21},{ 2}}, {{22},{ 2}}, {{23},{ 2}}, {{24},{ 2}}, {{25},{ 2}}, {{26},{ 2}}, {{27},{ 2}},

                                                                                                        {{ 8},{ 3}}, {{ 9},{ 3}}, {{10},{ 3}}, {{11},{ 3}}, {{12},{ 3}}, {{13},{ 3}}, {{14},{ 3}}, {{15},{ 3}}, {{16},{ 3}}, {{17},{ 3}}, {{18},{ 3}}, {{19},{ 3}}, {{20},{ 3}}, {{21},{ 3}}, {{22},{ 3}}, {{23},{ 3}}, {{24},{ 3}}, {{25},{ 3}}, {{26},{ 3}}, {{27},{ 3}},

                                                    {{ 4},{ 4}}, {{ 5},{ 4}}, {{ 6},{ 4}}, {{ 7},{ 4}}, {{ 8},{ 4}}, {{ 9},{ 4}}, {{10},{ 4}}, {{11},{ 4}}, {{12},{ 4}}, {{13},{ 4}}, {{14},{ 4}}, {{15},{ 4}}, {{16},{ 4}}, {{17},{ 4}}, {{18},{ 4}}, {{19},{ 4}}, {{20},{ 4}}, {{21},{ 4}}, {{22},{ 4}}, {{23},{ 4}}, {{24},{ 4}}, {{25},{ 4}}, {{26},{ 4}}, {{27},{ 4}}, {{28},{ 4}}, {{29},{ 4}}, {{30},{ 4}}, {{31},{ 4}},

                                                    {{ 4},{ 5}}, {{ 5},{ 5}}, {{ 6},{ 5}}, {{ 7},{ 5}}, {{ 8},{ 5}}, {{ 9},{ 5}}, {{10},{ 5}}, {{11},{ 5}}, {{12},{ 5}}, {{13},{ 5}}, {{14},{ 5}}, {{15},{ 5}}, {{16},{ 5}}, {{17},{ 5}}, {{18},{ 5}}, {{19},{ 5}}, {{20},{ 5}}, {{21},{ 5}}, {{22},{ 5}}, {{23},{ 5}}, {{24},{ 5}}, {{25},{ 5}}, {{26},{ 5}}, {{27},{ 5}}, {{28},{ 5}}, {{29},{ 5}}, {{30},{ 5}}, {{31},{ 5}},

{{ 0},{ 6}}, {{ 1},{ 6}}, {{ 2},{ 6}}, {{ 3},{ 6}}, {{ 4},{ 6}}, {{ 5},{ 6}}, {{ 6},{ 6}}, {{ 7},{ 6}}, {{ 8},{ 6}}, {{ 9},{ 6}}, {{10},{ 6}}, {{11},{ 6}}, {{12},{ 6}}, {{13},{ 6}}, {{14},{ 6}}, {{15},{ 6}}, {{16},{ 6}}, {{17},{ 6}}, {{18},{ 6}}, {{19},{ 6}}, {{20},{ 6}}, {{21},{ 6}}, {{22},{ 6}}, {{23},{ 6}}, {{24},{ 6}}, {{25},{ 6}}, {{26},{ 6}}, {{27},{ 6}}, {{28},{ 6}}, {{29},{ 6}}, {{30},{ 6}}, {{31},{ 6}}, {{32},{ 6}}, {{33},{ 6}}, {{34},{ 6}}, {{35},{ 6}},

{{ 0},{ 7}}, {{ 1},{ 7}}, {{ 2},{ 7}}, {{ 3},{ 7}}, {{ 4},{ 7}}, {{ 5},{ 7}}, {{ 6},{ 7}}, {{ 7},{ 7}}, {{ 8},{ 7}}, {{ 9},{ 7}}, {{10},{ 7}}, {{11},{ 7}}, {{12},{ 7}}, {{13},{ 7}}, {{14},{ 7}}, {{15},{ 7}}, {{16},{ 7}}, {{17},{ 7}}, {{18},{ 7}}, {{19},{ 7}}, {{20},{ 7}}, {{21},{ 7}}, {{22},{ 7}}, {{23},{ 7}}, {{24},{ 7}}, {{25},{ 7}}, {{26},{ 7}}, {{27},{ 7}}, {{28},{ 7}}, {{29},{ 7}}, {{30},{ 7}}, {{31},{ 7}}, {{32},{ 7}}, {{33},{ 7}}, {{34},{ 7}}, {{35},{ 7}},

{{ 0},{ 8}}, {{ 1},{ 8}}, {{ 2},{ 8}}, {{ 3},{ 8}}, {{ 4},{ 8}}, {{ 5},{ 8}}, {{ 6},{ 8}}, {{ 7},{ 8}}, {{ 8},{ 8}}, {{ 9},{ 8}}, {{10},{ 8}}, {{11},{ 8}}, {{12},{ 8}}, {{13},{ 8}}, {{14},{ 8}}, {{15},{ 8}}, {{16},{ 8}}, {{17},{ 8}}, {{18},{ 8}}, {{19},{ 8}}, {{20},{ 8}}, {{21},{ 8}}, {{22},{ 8}}, {{23},{ 8}}, {{24},{ 8}}, {{25},{ 8}}, {{26},{ 8}}, {{27},{ 8}}, {{28},{ 8}}, {{29},{ 8}}, {{30},{ 8}}, {{31},{ 8}}, {{32},{ 8}}, {{33},{ 8}}, {{34},{ 8}}, {{35},{ 8}},

{{ 0},{ 9}}, {{ 1},{ 9}}, {{ 2},{ 9}}, {{ 3},{ 9}}, {{ 4},{ 9}}, {{ 5},{ 9}}, {{ 6},{ 9}}, {{ 7},{ 9}}, {{ 8},{ 9}}, {{ 9},{ 9}}, {{10},{ 9}}, {{11},{ 9}}, {{12},{ 9}}, {{13},{ 9}}, {{14},{ 9}}, {{15},{ 9}}, {{16},{ 9}}, {{17},{ 9}}, {{18},{ 9}}, {{19},{ 9}}, {{20},{ 9}}, {{21},{ 9}}, {{22},{ 9}}, {{23},{ 9}}, {{24},{ 9}}, {{25},{ 9}}, {{26},{ 9}}, {{27},{ 9}}, {{28},{ 9}}, {{29},{ 9}}, {{30},{ 9}}, {{31},{ 9}}, {{32},{ 9}}, {{33},{ 9}}, {{34},{ 9}}, {{35},{ 9}},

                                                    {{ 4},{10}}, {{ 5},{10}}, {{ 6},{10}}, {{ 7},{10}}, {{ 8},{10}}, {{ 9},{10}}, {{10},{10}}, {{11},{10}}, {{12},{10}}, {{13},{10}}, {{14},{10}}, {{15},{10}}, {{16},{10}}, {{17},{10}}, {{18},{10}}, {{19},{10}}, {{20},{10}}, {{21},{10}}, {{22},{10}}, {{23},{10}}, {{24},{10}}, {{25},{10}}, {{26},{10}}, {{27},{10}}, {{28},{10}}, {{29},{10}}, {{30},{10}}, {{31},{10}},

                                                    {{ 4},{11}}, {{ 5},{11}}, {{ 6},{11}}, {{ 7},{11}}, {{ 8},{11}}, {{ 9},{11}}, {{10},{11}}, {{11},{11}}, {{12},{11}}, {{13},{11}}, {{14},{11}}, {{15},{11}}, {{16},{11}}, {{17},{11}}, {{18},{11}}, {{19},{11}}, {{20},{11}}, {{21},{11}}, {{22},{11}}, {{23},{11}}, {{24},{11}}, {{25},{11}}, {{26},{11}}, {{27},{11}}, {{28},{11}}, {{29},{11}}, {{30},{11}}, {{31},{11}},

                                                                                                        {{ 8},{12}}, {{ 9},{12}}, {{10},{12}}, {{11},{12}}, {{12},{12}}, {{13},{12}}, {{14},{12}}, {{15},{12}}, {{16},{12}}, {{17},{12}}, {{18},{12}}, {{19},{12}}, {{20},{12}}, {{21},{12}}, {{22},{12}}, {{23},{12}}, {{24},{12}}, {{25},{12}}, {{26},{12}}, {{27},{12}},

                                                                                                        {{ 8},{13}}, {{ 9},{13}}, {{10},{13}}, {{11},{13}}, {{12},{13}}, {{13},{13}}, {{14},{13}}, {{15},{13}}, {{16},{13}}, {{17},{13}}, {{18},{13}}, {{19},{13}}, {{20},{13}}, {{21},{13}}, {{22},{13}}, {{23},{13}}, {{24},{13}}, {{25},{13}}, {{26},{13}}, {{27},{13}},

                                                                                                                                                            {{12},{14}}, {{13},{14}}, {{14},{14}}, {{15},{14}}, {{16},{14}}, {{17},{14}}, {{18},{14}}, {{19},{14}}, {{20},{14}}, {{21},{14}}, {{22},{14}}, {{23},{14}},

                                                                                                                                                            {{12},{15}}, {{13},{15}}, {{14},{15}}, {{15},{15}}, {{16},{15}}, {{17},{15}}, {{18},{15}}, {{19},{15}}, {{20},{15}}, {{21},{15}}, {{22},{15}}, {{23},{15}}
}};

array<array<int, 16>, 36> const HICANNOnWaferEnum = detail::generateEnum<16, 36, 384>(HICANNOnWaferGrid);

array< pair<int, int>, 48 > const DNCOnWaferGrid = {{
                                 {{3},{0}}, {{4},{0}}, {{5},{0}},
                      {{2},{1}}, {{3},{1}}, {{4},{1}}, {{5},{1}}, {{6},{1}},
           {{1},{2}}, {{2},{2}}, {{3},{2}}, {{4},{2}}, {{5},{2}}, {{6},{2}}, {{7},{2}},
{{0},{3}}, {{1},{3}}, {{2},{3}}, {{3},{3}}, {{4},{3}}, {{5},{3}}, {{6},{3}}, {{7},{3}}, {{8},{3}},
{{0},{4}}, {{1},{4}}, {{2},{4}}, {{3},{4}}, {{4},{4}}, {{5},{4}}, {{6},{4}}, {{7},{4}}, {{8},{4}},
           {{1},{5}}, {{2},{5}}, {{3},{5}}, {{4},{5}}, {{5},{5}}, {{6},{5}}, {{7},{5}},
                      {{2},{6}}, {{3},{6}}, {{4},{6}}, {{5},{6}}, {{6},{6}},
                                 {{3},{7}}, {{4},{7}}, {{5},{7}}
}};

array<array<int, 8>, 9> const DNCOnWaferEnum = detail::generateEnum<8, 9, 48>(DNCOnWaferGrid);

// power grid numbering starts at ONE!
std::array<int, 48> const reticle_power_grid = {{
                              1   ,    4   ,    5   ,
                     2   ,   45   ,    6   ,    7   ,    8   ,
           44   ,   43   ,    3   ,   12   ,   11   ,   10   ,   14   ,
  41   ,   42   ,   47   ,   48   ,   46   ,    9   ,   15   ,   16   ,   13   ,
  37   ,   40   ,   39   ,   36   ,   34   ,   24   ,   23   ,   18   ,   17   ,
           38   ,   33   ,   35   ,   21   ,   22   ,   19   ,   20   ,
                    32   ,   31   ,   27   ,   28   ,   26   ,
                             29   ,   30   ,   25
}};

//FIXME: move all this to HWDB
// currently PMUs are statically assigned to wafers
// if somebody adds gaps => fix up (we access by operator[])!
static std::map<size_t, size_t> const wafer_pmu_assignment_map = {{
	{0, 0}, // first lab wafer (FACETS/BSS-prototype-style, i.e. 12 FPGAs)
	{1, 1}, // second lab wafer (FACETS/BSS-prototype-style, i.e. 12 FPGAs)
	{3, 3}, // HBP/BSS test wafer in lab
	{18, 18}, // temporary wafer id for wafer in grey room
	{19, 19}, // temporary wafer id for wafer in "Teststand" (ENI Container)
	{20, 20}, // all following wafers are HBP/BSS-production style
	{21, 21},
	{22, 22},
	{23, 23},
	{24, 24},
	{25, 25},
	{26, 26},
	{27, 27},
	{28, 28},
	{29, 29},
	{30, 30},
	{31, 31},
	{32, 32},
	{33, 33},
	{34, 34},
	{35, 35},
	{36, 36},
	{37, 37},
	{38, 38},
	{39, 39},
	{100, 100}
}};

std::array<size_t, 48> const reticle_fpga_grid_bss = {{
             12, 13, 11,
         16, 14, 15, 10,  9,
     20, 17, 19,  7,  6,  8,  3,
 22, 21, 23, 18,  5,  4,  0,  2,  1,
 25, 26, 24, 28, 43, 42, 47, 45, 46,
     27, 29, 30, 41, 40, 38, 44,
         31, 32, 39, 37, 36,
             33, 34, 35
}};

static std::array<size_t, 48> const reverse_fpga_grid = detail::reverseLookup(reticle_fpga_grid_bss);

std::array<size_t, 48> const reticle_adc_trigger_grid = {{
              5,  5,  6,
          4,  5,  5,  6,  6,
      3,  4,  4,  7,  7,  6,  8,
  3,  3,  3,  4,  7,  7,  8,  8,  8,
  2,  2,  2,  1, 10, 10,  9,  9,  9,
      2,  1,  1, 10, 10, 11,  9,
          1,  0, 11, 11, 11,
              0,  0,  0
}};

std::array<size_t, 12> const adc_trigger_ananas_grid = {{0,0,0,1,1,1,1,1,1,0,0,0}};

// clang-format on

static std::array<size_t, 48> const reverse_adc_trigger_grid =
    detail::reverseLookup(reticle_adc_trigger_grid);

FPGAOnWafer gridLookupFPGAOnWafer(DNCGlobal const dnc) {
	auto const local_dnc_id = dnc.toDNCOnWafer().toEnum();
	return FPGAOnWafer(reticle_fpga_grid_bss.at(local_dnc_id));
}

DNCGlobal gridLookupDNCGlobal(FPGAGlobal const f, DNCOnFPGA const /*dnc*/) {
	int id = reverse_fpga_grid.at(f.value());
	return DNCGlobal(DNCOnWafer(Enum(id)), f.toWafer());
}

FPGAOnWafer gridLookupFPGAOnWafer(DNCOnWafer const d)
{
	return FPGAOnWafer(Enum(reticle_fpga_grid_bss.at(d.toEnum())));
}

DNCOnWafer gridLookupDNCOnWafer(FPGAOnWafer const f)
{
	return DNCOnWafer(Enum(reverse_fpga_grid.at(f.toEnum())));
}

TriggerOnWafer gridLookupTriggerOnWafer(DNCOnWafer const dnc)
{
	return TriggerOnWafer(reticle_adc_trigger_grid.at(dnc.toEnum()));
}

ANANASOnWafer gridLookupANANASOnWafer(TriggerOnWafer const trigger)
{
	return ANANASOnWafer(adc_trigger_ananas_grid.at(trigger.toEnum()));
}

} // v2
} // hicann
} // halco

