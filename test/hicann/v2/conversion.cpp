#include <gtest/gtest.h>

#include "halco/hicann/v2/coordinates.h"
#include "halco/common/iter_all.h"

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
