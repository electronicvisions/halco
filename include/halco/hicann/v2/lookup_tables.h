#pragma once

#include <vector>
#include <utility>

#include "pywrap/compat/array.hpp"
#include <boost/serialization/array.h>

#include "halco/common/genpybind.h"
#include "halco/common/lookup_tables_helper.h"
#include "halco/hicann/v2/external.h"

#include "hate/visibility.h"

namespace halco {
namespace hicann {
namespace v2 GENPYBIND_TAG_HALCO_HICANN_V2 {

static const int invalid = halco::common::detail::invalid;
/// List of available HICANNOnWafer Coordinates
extern SYMBOL_VISIBLE std::array<std::pair<int, int>, 384> const HICANNOnWaferGrid;

/// HICANNOnWafer (x, y) -> enum
extern SYMBOL_VISIBLE std::array<std::array<int, 36>, 16> const HICANNOnWaferEnum;

/// List of available DNCOnWafer Coordinates
extern SYMBOL_VISIBLE std::array<std::pair<int, int>, 48> const DNCOnWaferGrid;

/// DNCOnWafer (x, y) -> enum
extern SYMBOL_VISIBLE std::array<std::array<int, 9>, 8> const DNCOnWaferEnum;

/// THE power number, rotated by 90, etc.
extern SYMBOL_VISIBLE std::array<int, 48> const reticle_power_grid;

// Enum for different setup types
PYPP_CLASS_ENUM(SetupType) {
	VSetup,
	FACETSWafer,
	CubeSetup,
	BSSWafer
};

// Return the FPGA position on a Wafer
SYMBOL_VISIBLE FPGAOnWafer gridLookupFPGAOnWafer(DNCGlobal const dnc);

// Return DNCGlobal of FPGAGlobal + DNCOnFPGA
SYMBOL_VISIBLE DNCGlobal gridLookupDNCGlobal(FPGAGlobal const f, DNCOnFPGA const dnc);

// Return FPGAOnWafer of DNCOnWafer
SYMBOL_VISIBLE FPGAOnWafer gridLookupFPGAOnWafer(DNCOnWafer const f);

// Return DNCOnWAfer of FPGAOnWafer
SYMBOL_VISIBLE DNCOnWafer gridLookupDNCOnWafer(FPGAOnWafer const f);

// Return the Trigger position on a Wafer
SYMBOL_VISIBLE TriggerOnWafer gridLookupTriggerOnWafer(DNCOnWafer const dnc);

// Return the ADCGroup connected to a DNC
// Each group corresponds to {P1|P4,P2|P5,P3|P6}{top_anab,bottom_anab}. c.f. 2240, 3877
SYMBOL_VISIBLE ADCGroupOnWafer gridLookupADCGroupOnWafer(DNCOnWafer const dnc);

// Return the Ananas connected to a Trigger
SYMBOL_VISIBLE AnanasOnWafer gridLookupAnanasOnWafer(TriggerOnWafer const trigger);

// Return the AnanasSlice connected to a Trigger
SYMBOL_VISIBLE AnanasSliceOnAnanas gridLookupAnanasSliceOnAnanas(TriggerOnWafer const trigger);

// Return the AnanasChannel connected to the analog output of a DNC
SYMBOL_VISIBLE AnanasChannelOnAnanasSlice
gridLookupAnanasChannelOnAnanasSlice(AnalogOnDNC const a, DNCOnWafer const d);

// Return the associated AuxPwr on a Wafer
SYMBOL_VISIBLE AuxPwrOnWafer gridLookupAuxPwrOnWafer(DNCOnWafer const dnc);

} // v2
} // hicann
} // halco
