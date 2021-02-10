#pragma once

#include <algorithm>
#include <string>
#include <stdio.h>
#include <vector>

#include <boost/variant.hpp>

#include "halco/hicann/v2/coordinates.h"

#if defined(__GENPYBIND__) || defined(__GENPYBIND_GENERATED__)
// TODO: Issue #3375 move to genpybind as is general
#include <pybind11/stl.h>
namespace pybind11::detail {

template <typename... Ts>
struct type_caster<boost::variant<Ts...>> : variant_caster<boost::variant<Ts...>>
{};

template <>
struct visit_helper<boost::variant>
{
	template <typename... Args>
	static auto call(Args&&... args) -> decltype(boost::apply_visitor(args...))
	{
		return boost::apply_visitor(args...);
	}
};

} // namespace pybind11::detail
#endif

namespace halco {
namespace hicann {
namespace v2 GENPYBIND_TAG_HALCO_HICANN_V2 {

// Order of declaration matters for python bindings:
// Keep globals first!
GENPYBIND(visible)
std::string short_format(const AnanasGlobal& a);
GENPYBIND(visible)
std::string short_format(const AuxPwrGlobal& apg);
GENPYBIND(visible)
std::string short_format(const HICANNGlobal& hg);
GENPYBIND(visible)
std::string short_format(const FPGAGlobal& fg);
GENPYBIND(visible)
std::string short_format(const DNCGlobal& fg);
GENPYBIND(visible)
std::string short_format(const TriggerGlobal& t);
GENPYBIND(visible)
std::string short_format(const AnanasOnWafer& a);
GENPYBIND(visible)
std::string short_format(const AuxPwrOnWafer& a);
GENPYBIND(visible)
std::string short_format(const HICANNOnWafer& h);
GENPYBIND(visible)
std::string short_format(const FPGAOnWafer& f);
GENPYBIND(visible)
std::string short_format(const DNCOnWafer& f);
GENPYBIND(visible)
std::string short_format(const TriggerOnWafer& t);
GENPYBIND(visible)
std::string short_format(const RepeaterBlockOnWafer& rb);
GENPYBIND(visible)
std::string short_format(const HRepeaterOnWafer& hr);
GENPYBIND(visible)
std::string short_format(const VRepeaterOnWafer& vr);
GENPYBIND(visible)
std::string short_format(const HLineOnWafer& hl);
GENPYBIND(visible)
std::string short_format(const VLineOnWafer& vl);
GENPYBIND(visible)
std::string short_format(const Wafer& w);
GENPYBIND(visible)
std::string short_format(const RepeaterBlockOnHICANN& rb);
GENPYBIND(visible)
std::string short_format(const TriggerOnWafer& t);
GENPYBIND(visible)
std::string short_format(const Wafer& w);
GENPYBIND(visible)
std::string short_format(const SendingRepeaterOnWafer& sr);

GENPYBIND(visible)
std::string short_format(const HRepeaterOnHICANN& hr);
GENPYBIND(visible)
std::string short_format(const VRepeaterOnHICANN& vr);
GENPYBIND(visible)
std::string short_format(const HLineOnHICANN& hl);
GENPYBIND(visible)
std::string short_format(const VLineOnHICANN& vl);
GENPYBIND(visible)
std::string short_format(const NeuronOnHICANN& vl);
GENPYBIND(visible)
std::string short_format(const SendingRepeaterOnHICANN& sr);

GENPYBIND(visible)
std::string slurm_license(AnanasGlobal const& ag);
GENPYBIND(visible)
std::string slurm_license(FPGAGlobal const& fg);
GENPYBIND(visible)
std::string slurm_license(HICANNGlobal const& hg);
GENPYBIND(visible)
std::string slurm_license(TriggerGlobal const& tg);

template <typename T>
std::string to_string(T const& t) GENPYBIND(visible)
{
	return short_format(t);
}

template std::string to_string(AnanasGlobal const&);
template std::string to_string(AuxPwrGlobal const&);
template std::string to_string(HICANNGlobal const&);
template std::string to_string(FPGAGlobal const&);
template std::string to_string(DNCGlobal const&);
template std::string to_string(TriggerGlobal const&);
template std::string to_string(AnanasOnWafer const&);
template std::string to_string(AuxPwrOnWafer const&);
template std::string to_string(HICANNOnWafer const&);
template std::string to_string(FPGAOnWafer const&);
template std::string to_string(DNCOnWafer const&);
template std::string to_string(TriggerOnWafer const&);
template std::string to_string(RepeaterBlockOnWafer const&);
template std::string to_string(HRepeaterOnWafer const&);
template std::string to_string(VRepeaterOnWafer const&);
template std::string to_string(HLineOnWafer const&);
template std::string to_string(VLineOnWafer const&);
template std::string to_string(SendingRepeaterOnWafer const&);
template std::string to_string(Wafer const&);

template std::string to_string(RepeaterBlockOnHICANN const&);
template std::string to_string(HRepeaterOnHICANN const&);
template std::string to_string(VRepeaterOnHICANN const&);

template std::string to_string(HLineOnHICANN const&);
template std::string to_string(VLineOnHICANN const&);

template std::string to_string(NeuronOnHICANN const&);

template std::string to_string(SendingRepeaterOnHICANN const&);

typedef boost::variant<
    AnanasGlobal,
    AuxPwrGlobal,
    HICANNGlobal,
    FPGAGlobal,
    DNCGlobal,
    TriggerGlobal,
    HICANNOnWafer,
    FPGAOnWafer,
    DNCOnWafer,
    TriggerOnWafer,
    AnanasOnWafer,
    AuxPwrOnWafer,
    Wafer,
    RepeaterBlockOnHICANN,
    HRepeaterOnHICANN,
    VRepeaterOnHICANN,
    RepeaterBlockOnWafer,
    HRepeaterOnWafer,
    VRepeaterOnWafer,
    HLineOnHICANN,
    VLineOnHICANN,
    HLineOnWafer,
    VLineOnWafer,
    NeuronOnHICANN,
    SendingRepeaterOnWafer,
    SendingRepeaterOnHICANN>
    format_type;

// converts from short format to type
GENPYBIND(visible)
format_type from_string(std::string const& s);

#ifndef PYPLUSPLUS
// converts from an iterable of type I of strings to types T; throws if it cannot convert
template <typename T, typename I>
std::vector<T> from_string(I const& vs)
{
	std::vector<T> types;
	std::transform(std::begin(vs), std::end(vs), std::back_inserter(types), [](auto s) {
		return boost::get<T>(from_string(s));
	});

	return types;
}
#endif

} // v2
} // hicann
} // halco
