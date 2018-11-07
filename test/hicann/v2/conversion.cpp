#include <gtest/gtest.h>

#include "halco/common/iter_all.h"
#include "halco/common/typed_array.h"
#include "halco/hicann/v2/coordinates.h"

using namespace halco::common;
using namespace halco::hicann::v2;

TEST(HMFCoordinateConversion, HICANNOnDNCToHICANNOnWafer)
{
	std::set<HICANNOnWafer> hicann_on_wafer;
	for (auto dnc : iter_all<DNCOnWafer>())
	{
		for (auto hicann : iter_all<HICANNOnDNC>())
		{
			hicann_on_wafer.insert(hicann.toHICANNOnWafer(dnc));
		}
	}
	ASSERT_EQ(HICANNOnWafer::enum_type::size, hicann_on_wafer.size());
}

TEST(HMFCoordinateConversion, DNCOnWafertoFPGAOnWafer)
{
	for (auto dnc : iter_all<DNCOnWafer>())
	{
		auto const fpga = dnc.toFPGAOnWafer();
		ASSERT_EQ(dnc, fpga.toDNCOnWafer());
	}
}

TEST(HMFCoordinateConversion, HICANNOnDNCToHICANNOnHS)
{
	std::vector<HICANNOnHS> const expected_hicanns_on_hs = {
	    HICANNOnHS(0), HICANNOnHS(2), HICANNOnHS(4), HICANNOnHS(6),
	    HICANNOnHS(1), HICANNOnHS(3), HICANNOnHS(5), HICANNOnHS(7)};

	std::vector<HICANNOnHS> hicanns_on_hs;

	for (auto hicann_on_dnc : iter_all<HICANNOnDNC>()) {
		auto const hicann_on_hs = hicann_on_dnc.toHICANNOnHS();
		hicanns_on_hs.push_back(hicann_on_hs);
	}
	ASSERT_EQ(expected_hicanns_on_hs, hicanns_on_hs);
}

TEST(HMFCoordinateConversion, HICANNOnHStoHICANNOnDNC)
{
	for (auto hicann_on_dnc : iter_all<HICANNOnDNC>()) {
		ASSERT_EQ(hicann_on_dnc, hicann_on_dnc.toHICANNOnHS().toHICANNOnDNC());
	}
}
