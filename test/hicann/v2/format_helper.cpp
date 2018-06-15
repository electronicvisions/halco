#include <gtest/gtest.h>
#include <string>

#include "halco/hicann/v2/coordinates.h"

using namespace halco::common;

namespace halco {
namespace hicann {
namespace v2 {

TEST(FormatHelper, ShortFormat) {

	Wafer w(2);
	EXPECT_EQ(short_format(w),  "W002");

	HICANNOnWafer h(Enum(3));
	EXPECT_EQ(short_format(h),  "H003");

	HICANNGlobal hg(h,w);
	EXPECT_EQ(short_format(hg), "W002H003");

	FPGAOnWafer f(Enum(4));
	EXPECT_EQ(short_format(f),  "F004");

	FPGAGlobal fg(f,w);
	EXPECT_EQ(short_format(fg), "W002F004");

	HRepeaterOnHICANN hr(Enum(5));
	EXPECT_EQ(short_format(hr), "HR005");

	VRepeaterOnHICANN vr(Enum(6));
	EXPECT_EQ(short_format(vr), "VR006");

	HRepeaterOnWafer hr_on_wafer(hr, h);
	EXPECT_EQ(short_format(hr_on_wafer), "H003HR005");

	VRepeaterOnWafer vr_on_wafer(vr, h);
	EXPECT_EQ(short_format(vr_on_wafer), "H003VR006");

	HLineOnHICANN hl(Enum(5));
	EXPECT_EQ(short_format(hl), "HL005");

	VLineOnHICANN vl(Enum(6));
	EXPECT_EQ(short_format(vl), "VL006");

}

} // namespace v2
} // namespace hicann
} // namespace halco

