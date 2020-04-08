#include <iostream>
#include <sstream>
#include <iomanip>
#include "halco/hicann/v2/format_helper.h"

#include <regex>

namespace halco {
namespace hicann {
namespace v2 {

std::string short_format(const HICANNOnWafer& h) {
	std::stringstream ss;
	ss << "H" << std::setw(3) << std::setfill('0') << h.toEnum().value();
	return ss.str();
}

std::string short_format(const FPGAOnWafer& f) {
	std::stringstream ss;
	ss << "F" << std::setw(3) << std::setfill('0') << f.value();
	return ss.str();
}

std::string short_format(const DNCOnWafer& f) {
	std::stringstream ss;
	ss << "D" << std::setw(3) << std::setfill('0') << f.toEnum().value();
	return ss.str();
}

std::string short_format(const TriggerOnWafer& f)
{
	std::stringstream ss;
	ss << "T" << std::setw(2) << std::setfill('0') << f.value();
	return ss.str();
}

std::string short_format(const ANANASOnWafer& f) {
	std::stringstream ss;
	ss << "A" << std::setw(1) << std::setfill('0') << f.value();
	return ss.str();
}

std::string short_format(const AuxPwrOnWafer& ap) {
	std::stringstream ss;
	ss << "AP" << std::setw(1) << std::setfill('0') << ap.value();
	return ss.str();
}

std::string short_format(const Wafer& w) {
	std::stringstream ss;
	ss << "W" << std::setw(3) << std::setfill('0') << w.value();
	return ss.str();
}

std::string short_format(const HICANNGlobal& hg) {
	return short_format(hg.toWafer()) + short_format(hg.toHICANNOnWafer());
}

std::string short_format(const FPGAGlobal& fg) {
	return short_format(fg.toWafer()) + short_format(fg.toFPGAOnWafer());
}

std::string short_format(const DNCGlobal& dg) {
	return short_format(dg.toWafer()) + short_format(dg.toDNCOnWafer());
}

std::string short_format(const TriggerGlobal& fg) {
	return short_format(fg.toWafer()) + short_format(fg.toTriggerOnWafer());
}

std::string short_format(const ANANASGlobal& fg) {
	return short_format(fg.toWafer()) + short_format(fg.toANANASOnWafer());
}

std::string short_format(const AuxPwrGlobal& apg) {
	return short_format(apg.toWafer()) + short_format(apg.toAuxPwrOnWafer());
}

std::string short_format(const RepeaterBlockOnHICANN& rb) {
	std::stringstream ss;
	ss << "RB" << rb.toEnum().value();
	return ss.str();
}

std::string short_format(const HRepeaterOnHICANN& hr) {
	std::stringstream ss;
	ss << "HR" << std::setw(3) << std::setfill('0') << hr.toEnum().value();
	return ss.str();
}

std::string short_format(const VRepeaterOnHICANN& vr) {
	std::stringstream ss;
	ss << "VR" << std::setw(3) << std::setfill('0') << vr.toEnum().value();
	return ss.str();
}

std::string short_format(const RepeaterBlockOnWafer& rb) {
	std::stringstream ss;
	ss << short_format(rb.toHICANNOnWafer()) + short_format(rb.toRepeaterBlockOnHICANN());
	return ss.str();
}

std::string short_format(const HRepeaterOnWafer& hr) {
	std::stringstream ss;
	ss << short_format(hr.toHICANNOnWafer()) + short_format(hr.toHRepeaterOnHICANN());
	return ss.str();
}

std::string short_format(const VRepeaterOnWafer& vr) {
	std::stringstream ss;
	ss << short_format(vr.toHICANNOnWafer()) + short_format(vr.toVRepeaterOnHICANN());
	return ss.str();
}

std::string short_format(const HLineOnHICANN& hl) {
	std::stringstream ss;
	ss << "HL" << std::setw(3) << std::setfill('0') << hl.value();
	return ss.str();
}

std::string short_format(const VLineOnHICANN& vl) {
	std::stringstream ss;
	ss << "VL" << std::setw(3) << std::setfill('0') << vl.value();
	return ss.str();
}

std::string short_format(const NeuronOnHICANN& nrn)
{
	std::stringstream ss;
	ss << "N" << std::setw(3) << std::setfill('0') << nrn.toEnum().value();
	return ss.str();
}

std::string short_format(const HLineOnWafer& hl) {
	return short_format(hl.toHICANNOnWafer()) + short_format(hl.toHLineOnHICANN());
}

std::string short_format(const VLineOnWafer& vl) {
	return short_format(vl.toHICANNOnWafer()) + short_format(vl.toVLineOnHICANN());
}

std::string slurm_license(ANANASGlobal const& ag)
{
	return "W" + std::to_string(ag.toWafer().toEnum()) + "A" +
	       std::to_string(ag.toANANASOnWafer().toEnum());
}

std::string slurm_license(FPGAGlobal const& fg)
{
	return "W" + std::to_string(fg.toWafer().toEnum()) + "F" +
	       std::to_string(fg.toFPGAOnWafer().toEnum());
}

std::string slurm_license(HICANNGlobal const& hg)
{
	return "W" + std::to_string(hg.toWafer().toEnum()) + "H" +
	       std::to_string(hg.toHICANNOnWafer().toEnum());
}

std::string slurm_license(TriggerGlobal const& tg)
{
	return "W" + std::to_string(tg.toWafer().toEnum()) + "T" +
	       std::to_string(tg.toTriggerOnWafer().toEnum());
}

namespace {

// all local types
typedef boost::variant<
    HICANNOnWafer,
    FPGAOnWafer,
    DNCOnWafer,
    TriggerOnWafer,
    ANANASOnWafer,
    AuxPwrOnWafer,
    Wafer,
    RepeaterBlockOnHICANN,
    HRepeaterOnHICANN,
    VRepeaterOnHICANN,
    HLineOnHICANN,
    VLineOnHICANN,
    NeuronOnHICANN>
    local_type;

// all compound types
typedef boost::variant<
    ANANASGlobal,
    AuxPwrGlobal,
    HICANNGlobal,
    FPGAGlobal,
    DNCGlobal,
    TriggerGlobal,
    RepeaterBlockOnWafer,
    HRepeaterOnWafer,
    VRepeaterOnWafer,
    HLineOnWafer,
    VLineOnWafer>
    compound_type;

// converts type and value to a local type
local_type to_local(std::string const& type, std::string const& value)
{
	size_t const num(std::stoul(value));
	halco::common::Enum const e(num);

	if (type == "H") {
		return HICANNOnWafer(e);
	} else if (type == "F") {
		return FPGAOnWafer(e);
	} else if (type == "D") {
		return DNCOnWafer(e);
	} else if (type == "W") {
		return Wafer(num);
	} else if (type == "T") {
		return TriggerOnWafer(e);
	} else if (type == "RB") {
		return RepeaterBlockOnHICANN(e);
	} else if (type == "HR") {
		return HRepeaterOnHICANN(e);
	} else if (type == "VR") {
		return VRepeaterOnHICANN(e);
	} else if (type == "HL") {
		return HLineOnHICANN(e);
	} else if (type == "VL") {
		return VLineOnHICANN(e);
	} else if (type == "N") {
		return NeuronOnHICANN(e);
	} else if (type == "A") {
		return ANANASOnWafer(e);
	} else if (type == "AP") {
		return AuxPwrOnWafer(e);
	} else {
		throw std::runtime_error(
		    "halco::hicann::v2::to_local: unknown local type \"" + type + "\"");
	}
}

// converts to a compound type
struct to_compound : public boost::static_visitor<compound_type>
{
	HICANNGlobal operator()(Wafer const& w, HICANNOnWafer const& h) const
	{
		return HICANNGlobal(h, w);
	}
	FPGAGlobal operator()(Wafer const& w, FPGAOnWafer const& f) const { return FPGAGlobal(f, w); }
	DNCGlobal operator()(Wafer const& w, DNCOnWafer const& f) const { return DNCGlobal(f, w); }
	ANANASGlobal operator()(Wafer const& w, ANANASOnWafer const& a) const
	{
		return ANANASGlobal(a, w);
	}
	AuxPwrGlobal operator()(Wafer const& w, AuxPwrOnWafer const& a) const
	{
		return AuxPwrGlobal(a, w);
	}
	TriggerGlobal operator()(Wafer const& w, TriggerOnWafer const& t) const
	{
		return TriggerGlobal(t, w);
	}
	RepeaterBlockOnWafer operator()(HICANNOnWafer const& h, RepeaterBlockOnHICANN const& rb) const
	{
		return RepeaterBlockOnWafer(rb, h);
	}
	HRepeaterOnWafer operator()(HICANNOnWafer const& h, HRepeaterOnHICANN const& hr) const
	{
		return HRepeaterOnWafer(hr, h);
	}
	VRepeaterOnWafer operator()(HICANNOnWafer const& h, VRepeaterOnHICANN const& hr) const
	{
		return VRepeaterOnWafer(hr, h);
	}
	HLineOnWafer operator()(HICANNOnWafer const& h, HLineOnHICANN const& hl) const
	{
		return HLineOnWafer(hl, h);
	}
	VLineOnWafer operator()(HICANNOnWafer const& h, VLineOnHICANN const& vl) const
	{
		return VLineOnWafer(vl, h);
	}

	template <typename T, typename V>
	compound_type operator()(T const& t, V const& v) const
	{
		throw std::runtime_error(
		    "halco::hicann::v2::to_compound: cannot convert " + short_format(t) + " and " +
		    short_format(v) + " to a compound type");
	}
};
}

format_type from_string(std::string const& s)
{
	std::string message = s;
	std::smatch result;

	std::vector<local_type> local_types;
	std::regex const local_pattern("^([A-Z]{1,2})([0-9]+)");

	while (std::regex_search(message, result, local_pattern)) {
		std::string const type(result[1].first, result[1].second);
		std::string const value(result[2].first, result[2].second);
		local_types.push_back(to_local(type, value));
		message = result.suffix();
	}

	if (!message.empty()) {
		throw std::runtime_error(
		    "halco::hicann::v2::from_string: cannot parse \"" + message + "\"");
	}

	if (local_types.size() == 1) {
		return local_types.front();
	} else if (local_types.size() == 2) {
		return boost::apply_visitor(to_compound(), local_types.front(), local_types.back());
	} else {
		throw std::runtime_error(
		    "halco::hicann::v2::from_string: cannot construct local or compound type from \"" +
		    message + "\"");
	}
}

} // v2
} // hicann
} // halco
