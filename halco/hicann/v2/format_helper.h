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

template <typename T>
std::string to_string(T const& t)
{
	return short_format(t);
}

template std::string to_string(ANANASGlobal const&);
template std::string to_string(HICANNGlobal const&);
template std::string to_string(FPGAGlobal const&);
template std::string to_string(TriggerGlobal const&);
template std::string to_string(ANANASOnWafer const&);
template std::string to_string(HICANNOnWafer const&);
template std::string to_string(FPGAOnWafer const&);
template std::string to_string(TriggerOnWafer const&);
template std::string to_string(Wafer const&);

template std::string to_string(HRepeaterOnHICANN const&);
template std::string to_string(VRepeaterOnHICANN const&);

template std::string to_string(HRepeaterOnWafer const&);
template std::string to_string(VRepeaterOnWafer const&);

template std::string to_string(HLineOnHICANN const&);
template std::string to_string(VLineOnHICANN const&);

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
