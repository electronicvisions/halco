#pragma once

#include <string>
#include <stdio.h>

#include <boost/variant.hpp>

#include "halco/hicann/v2/coordinates.h"

namespace halco {
namespace hicann {
namespace v2 {

// Order of declaration matters for python bindings:
// Keep globals first!
std::string short_format(const ANANASGlobal& a);
std::string short_format(const HICANNGlobal& hg);
std::string short_format(const FPGAGlobal& fg);
std::string short_format(const TriggerGlobal& t);
std::string short_format(const ANANASOnWafer& a);
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

std::string slurm_license(ANANASGlobal const& ag);
std::string slurm_license(FPGAGlobal const& fg);
std::string slurm_license(HICANNGlobal const& hg);
std::string slurm_license(TriggerGlobal const& tg);

typedef boost::variant<
    ANANASGlobal,
    HICANNGlobal,
    FPGAGlobal,
    TriggerGlobal,
    HICANNOnWafer,
    FPGAOnWafer,
    TriggerOnWafer,
    ANANASOnWafer,
    Wafer,
    HRepeaterOnHICANN,
    VRepeaterOnHICANN,
    HRepeaterOnWafer,
    VRepeaterOnWafer,
    HLineOnHICANN,
    VLineOnHICANN>
    format_type;

// converts from short format to type
format_type from_string(std::string const& s);

} // v2
} // hicann
} // halco
