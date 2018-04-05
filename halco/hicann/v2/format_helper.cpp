#include <iostream>
#include <sstream>
#include <iomanip>
#include "halco/hicann/v2/format_helper.h"

namespace halco {
namespace hicann {
namespace v2 {

std::string short_format(const HICANNOnWafer& h) {
	std::stringstream ss;
	ss << "H" << std::setw(3) << std::setfill('0') << h.id().value();
	return ss.str();
}

std::string short_format(const FPGAOnWafer& f) {
	std::stringstream ss;
	ss << "F" << std::setw(3) << std::setfill('0') << f.value();
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

std::string short_format(const TriggerGlobal& fg) {
	return short_format(fg.toWafer()) + short_format(fg.toTriggerOnWafer());
}

std::string short_format(const ANANASGlobal& fg) {
	return short_format(fg.toWafer()) + short_format(fg.toANANASOnWafer());
}

std::string short_format(const HRepeaterOnHICANN& hr) {
	std::stringstream ss;
	ss << "HR" << std::setw(3) << std::setfill('0') << hr.id().value();
	return ss.str();
}

std::string short_format(const VRepeaterOnHICANN& vr) {
	std::stringstream ss;
	ss << "VR" << std::setw(3) << std::setfill('0') << vr.id().value();
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

} // v2
} // hicann
} // halco
