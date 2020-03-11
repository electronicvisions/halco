#include "halco/common/typed_array.h"
#include "halco/hicann/v2/external.h"
#include "halco/hicann/v2/lookup_tables.h"
#include "halco/common/iter_all.h"

using namespace halco::common;

namespace halco {
namespace hicann {
namespace v2 {

static_assert(std::is_same<IPv4_array_t, std::array<unsigned char, 4ul> >::value,
              "Boost must use std::array, otherwise the bindings will fail");

DNCOnWafer::x_type DNCOnWafer::to_x(enum_type const& e) {
	if (e >= DNCOnWaferGrid.size())
		throw std::out_of_range(
		    "DNCOnWafer::to_x() Wrong Enum for DNCOnWafer: max value is 47");
	return x_type(DNCOnWaferGrid.at(e).first);
}

DNCOnWafer::y_type DNCOnWafer::to_y(enum_type const& e) {
	if (e >= DNCOnWaferGrid.size())
		throw std::out_of_range(
		    "DNCOnWafer::to_y() Wrong Enum for DNCOnWafer: max value is 47");
	return y_type(DNCOnWaferGrid.at(e).second);
}

DNCOnWafer::enum_type DNCOnWafer::to_enum(x_type const& x, y_type const& y) {
	// throws out_of_range if x or y is not available on wafer.
	int enum_tmp = DNCOnWaferEnum.at(x).at(y);
	if (enum_tmp >= 0)
		return enum_type(enum_tmp);
	else
		throw std::domain_error("Invalid combination of X and Y for a DNCOnWafer.");
}

PowerCoordinate DNCOnWafer::toPowerCoordinate() const {
	int power_coordinate = reticle_power_grid.at(toEnum());
	return PowerCoordinate(power_coordinate);
}

FPGAOnWafer DNCOnWafer::toFPGAOnWafer() const
{
	return gridLookupFPGAOnWafer(*this);
}

TriggerOnWafer DNCOnWafer::toTriggerOnWafer() const
{
	return gridLookupTriggerOnWafer(*this);
}

DNCGlobal DNCOnFPGA::toDNCOnWafer(FPGAGlobal const& f) const {
	return gridLookupDNCGlobal(f, *this);
}

DNCMergerOnHICANN GbitLinkOnHICANN::toDNCMergerOnHICANN() const {
	return DNCMergerOnHICANN(value());
}

DNCOnFPGA DNCGlobal::toDNCOnFPGA() const {
	return DNCOnFPGA(0);
}

FPGAOnWafer DNCGlobal::toFPGAOnWafer() const {
	return gridLookupFPGAOnWafer(*this);
}

FPGAGlobal DNCGlobal::toFPGAGlobal() const {
	return FPGAGlobal(gridLookupFPGAOnWafer(*this), toWafer());
}

HICANNOnDNC HighspeedLinkOnDNC::toHICANNOnDNC() const
{
	static const typed_array<size_t, HighspeedLinkOnDNC> lut{0, 4, 1, 5, 2, 6, 3, 7};
	return HICANNOnDNC(Enum(lut[*this]));
}

DNCOnWafer FPGAOnWafer::toDNCOnWafer() const
{
	return gridLookupDNCOnWafer(*this);
}

TriggerOnWafer FPGAOnWafer::toTriggerOnWafer() const
{
	return gridLookupTriggerOnWafer(gridLookupDNCOnWafer(*this));
}

WIOOnWafer FPGAOnWafer::toWIOOnWafer() const
{
	return WIOOnWafer(value() / SocketOnWIO::size);
}

SocketOnWIO FPGAOnWafer::toSocketOnWIO() const
{
	return SocketOnWIO(value() % SocketOnWIO::size);
}

std::array<HICANNOnWafer, HICANNOnDNC::size> FPGAOnWafer::toHICANNOnWafer() const
{
	std::array<HICANNOnWafer, HICANNOnDNC::size> hicanns;
	for (auto const hod : iter_all<HICANNOnDNC>()) {
		hicanns.at(hod.toEnum()) = hod.toHICANNOnWafer(*this);
	}
	return hicanns;
}

ANANASOnWafer TriggerOnWafer::toANANASOnWafer() const
{
	return gridLookupANANASOnWafer(*this);
}

AuxPwrOnWafer DNCOnWafer::toAuxPwrOnWafer() const
{
	return gridLookupAuxPwrOnWafer(*this);
}

FPGAGlobal::FPGAGlobal()
    : FPGAGlobal(FPGAOnWafer{}, Wafer{}) // delegate to common ctor for range checks
{}

FPGAGlobal::FPGAGlobal(FPGAOnWafer const& h, Wafer const& w) : base(h, w) {
}

FPGAGlobal::FPGAGlobal(enum_type const& e) :
	base(FPGAOnWafer(e % FPGAOnWafer::end), Wafer(e / FPGAOnWafer::end))
{}

std::vector<HICANNGlobal> FPGAGlobal::toHICANNGlobal() const {

	std::vector<HICANNGlobal> hgs;

	for (auto const dnc : iter_all<DNCOnFPGA>()) {
		auto const dow = dnc.toDNCOnWafer(*this);

		for (auto const hod : iter_all<HICANNOnDNC>()) {
			hgs.push_back(HICANNGlobal(hod.toHICANNOnWafer(dow), toWafer()));
		}
	}

	return hgs;

}

TriggerGlobal::TriggerGlobal()
	: TriggerGlobal(TriggerOnWafer{}, Wafer{}) // delegate to common ctor for range checks
{}

TriggerGlobal::TriggerGlobal(TriggerOnWafer const& h, Wafer const& w) : base(h, w) {}

TriggerGlobal::TriggerGlobal(enum_type const& e)
	: base(TriggerOnWafer(e % TriggerOnWafer::end), Wafer(e / TriggerOnWafer::end))
{}

ANANASGlobal::ANANASGlobal()
    : ANANASGlobal(ANANASOnWafer{}, Wafer{}) // delegate to common ctor for range checks
{}

ANANASGlobal::ANANASGlobal(ANANASOnWafer const& h, Wafer const& w) : base(h, w) {
}

ANANASGlobal::ANANASGlobal(enum_type const& e) :
	base(ANANASOnWafer(e % ANANASOnWafer::end), Wafer(e / ANANASOnWafer::end))
{}

AuxPwrGlobal::AuxPwrGlobal()
    : AuxPwrGlobal(AuxPwrOnWafer{}, Wafer{}) // delegate to common ctor for range checks
{}

AuxPwrGlobal::AuxPwrGlobal(AuxPwrOnWafer const& h, Wafer const& w) : base(h, w) {
}

AuxPwrGlobal::AuxPwrGlobal(enum_type const& e) :
	base(AuxPwrOnWafer(e % AuxPwrOnWafer::end), Wafer(e / AuxPwrOnWafer::end))
{}

FPGAOnWafer::FPGAOnWafer(WIOOnWafer const& wio, SocketOnWIO const& s) :
    FPGAOnWafer(wio.value() * s.size + s.value())
{}

const FPGAOnWafer FPGAOnWafer::Master = FPGAOnWafer(12);

const ChannelOnADC ChannelOnADC::GND = ChannelOnADC(-1);

} // v2
} // hicann
} // halco
