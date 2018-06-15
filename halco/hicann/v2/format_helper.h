#pragma once

#include <string>
#include <stdio.h>

#include "halco/hicann/v2/coordinates.h"

namespace halco {
namespace hicann {
namespace v2 {

// Order of declaration matters for python bindings:
// Keep globals first!
std::string short_format(const HICANNGlobal& hg);
std::string short_format(const FPGAGlobal& fg);
std::string short_format(const TriggerGlobal& t);
std::string short_format(const HICANNOnWafer& h);
std::string short_format(const FPGAOnWafer& f);
std::string short_format(const TriggerOnWafer& t);
std::string short_format(const Wafer& w);

std::string short_format(const HRepeaterOnHICANN& hr);
std::string short_format(const VRepeaterOnHICANN& vr);

std::string short_format(const HRepeaterOnWafer& hr);
std::string short_format(const VRepeaterOnWafer& vr);

std::string short_format(const HLineOnHICANN& hl);
std::string short_format(const VLineOnHICANN& vl);

} // v2
} // hicann
} // halco
