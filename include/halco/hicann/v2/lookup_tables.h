#pragma once

#include <vector>
#include <utility>

#include "pywrap/compat/array.hpp"
#include <boost/serialization/array.h>

#include "halco/common/lookup_tables_helper.h"
#include "halco/hicann/v2/external.h"

namespace halco {
namespace hicann {
namespace v2 {

static const int invalid = halco::common::detail::invalid;
/// List of available HICANNOnWafer Coordinates
extern std::array<std::pair<int, int>, 384> const HICANNOnWaferGrid;

/// HICANNOnWafer (x, y) -> enum
extern std::array<std::array<int, 36>, 16> const HICANNOnWaferEnum;

/// List of available DNCOnWafer Coordinates
extern std::array<std::pair<int, int>, 48> const DNCOnWaferGrid;

/// DNCOnWafer (x, y) -> enum
extern std::array<std::array<int, 9>, 8> const DNCOnWaferEnum;

/// THE power number, rotated by 90, etc.
extern std::array<int, 48> const reticle_power_grid;

// Enum for different setup types
PYPP_CLASS_ENUM(SetupType) {
	VSetup,
	FACETSWafer,
	CubeSetup,
	BSSWafer
};

// Return the FPGA position on a Wafer
FPGAOnWafer gridLookupFPGAOnWafer(DNCGlobal const dnc);

// Return DNCGlobal of FPGAGlobal + DNCOnFPGA
DNCGlobal gridLookupDNCGlobal(FPGAGlobal const f, DNCOnFPGA const dnc);

// Return FPGAOnWafer of DNCOnWafer
FPGAOnWafer gridLookupFPGAOnWafer(DNCOnWafer const f);

// Return DNCOnWAfer of FPGAOnWafer
DNCOnWafer gridLookupDNCOnWafer(FPGAOnWafer const f);

// Return the Trigger position on a Wafer
TriggerOnWafer gridLookupTriggerOnWafer(DNCOnWafer const dnc);

// Return the ANANAS connected to a Trigger
ANANASOnWafer gridLookupANANASOnWafer(TriggerOnWafer const trigger);

// Return the associated AuxPwr on a Wafer
AuxPwrOnWafer gridLookupAuxPwrOnWafer(DNCOnWafer const dnc);

} // v2
} // hicann
} // halco
