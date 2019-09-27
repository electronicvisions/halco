#include <gtest/gtest.h>
#include <string>

#include "halco/common/iter_all.h"
#include "halco/hicann/v2/coordinates.h"

using namespace halco::common;

namespace halco {
namespace hicann {
namespace v2 {

TEST(FormatHelper, ShortFormat) {

	Wafer w(2);
	EXPECT_EQ(short_format(w),  "W002");

	ANANASOnWafer a(Enum(1));
	EXPECT_EQ(short_format(a),  "A1");

	ANANASGlobal ag(a,w);
	EXPECT_EQ(short_format(ag), "W002A1");

	HICANNOnWafer h(Enum(3));
	EXPECT_EQ(short_format(h),  "H003");

	HICANNGlobal hg(h,w);
	EXPECT_EQ(short_format(hg), "W002H003");

	FPGAOnWafer f(Enum(4));
	EXPECT_EQ(short_format(f),  "F004");

	FPGAGlobal fg(f,w);
	EXPECT_EQ(short_format(fg), "W002F004");

	TriggerOnWafer t(Enum(3));
	EXPECT_EQ(short_format(t),  "T03");

	TriggerGlobal tg(t,w);
	EXPECT_EQ(short_format(tg), "W002T03");

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

TEST(FormatHelper, SlurmLicense)
{
	// explicitly test first "overflow" of OnWafer coordinates
	EXPECT_EQ(slurm_license(ANANASGlobal(Enum(2))), "W1A0");
	EXPECT_EQ(slurm_license(FPGAGlobal(Enum(48))), "W1F0");
	EXPECT_EQ(slurm_license(HICANNGlobal(Enum(384))), "W1H0");
	EXPECT_EQ(slurm_license(TriggerGlobal(Enum(12))), "W1T0");

	Wafer const wafer1 = Wafer(4);
	Wafer const wafer2 = Wafer(30);
	Wafer const wafer3 = Wafer(123);

	for (auto ananas : iter_all<ANANASOnWafer>()) {
		std::string const teststring1 =
		    "W" + std::to_string(wafer1.toEnum()) + "A" + std::to_string(ananas.toEnum());
		std::string const teststring2 =
		    "W" + std::to_string(wafer2.toEnum()) + "A" + std::to_string(ananas.toEnum());
		std::string const teststring3 =
		    "W" + std::to_string(wafer3.toEnum()) + "A" + std::to_string(ananas.toEnum());
		ASSERT_EQ(teststring1, slurm_license(ANANASGlobal(ananas, wafer1)));
		ASSERT_EQ(teststring2, slurm_license(ANANASGlobal(ananas, wafer2)));
		ASSERT_EQ(teststring3, slurm_license(ANANASGlobal(ananas, wafer3)));
		ASSERT_NE(teststring1, slurm_license(ANANASGlobal(ananas, wafer2)));
	}

	for (auto fpga : iter_all<FPGAOnWafer>()) {
		std::string const teststring1 =
		    "W" + std::to_string(wafer1.toEnum()) + "F" + std::to_string(fpga.toEnum());
		std::string const teststring2 =
		    "W" + std::to_string(wafer2.toEnum()) + "F" + std::to_string(fpga.toEnum());
		std::string const teststring3 =
		    "W" + std::to_string(wafer3.toEnum()) + "F" + std::to_string(fpga.toEnum());
		ASSERT_EQ(teststring1, slurm_license(FPGAGlobal(fpga, wafer1)));
		ASSERT_EQ(teststring2, slurm_license(FPGAGlobal(fpga, wafer2)));
		ASSERT_EQ(teststring3, slurm_license(FPGAGlobal(fpga, wafer3)));
		ASSERT_NE(teststring1, slurm_license(FPGAGlobal(fpga, wafer2)));
	}

	for (auto hicann : iter_all<HICANNOnWafer>()) {
		std::string const teststring1 =
		    "W" + std::to_string(wafer1.toEnum()) + "H" + std::to_string(hicann.toEnum());
		std::string const teststring2 =
		    "W" + std::to_string(wafer2.toEnum()) + "H" + std::to_string(hicann.toEnum());
		std::string const teststring3 =
		    "W" + std::to_string(wafer3.toEnum()) + "H" + std::to_string(hicann.toEnum());
		ASSERT_EQ(teststring1, slurm_license(HICANNGlobal(hicann, wafer1)));
		ASSERT_EQ(teststring2, slurm_license(HICANNGlobal(hicann, wafer2)));
		ASSERT_EQ(teststring3, slurm_license(HICANNGlobal(hicann, wafer3)));
		ASSERT_NE(teststring1, slurm_license(HICANNGlobal(hicann, wafer2)));
	}

	for (auto trigger : iter_all<TriggerOnWafer>()) {
		std::string const teststring1 =
		    "W" + std::to_string(wafer1.toEnum()) + "T" + std::to_string(trigger.toEnum());
		std::string const teststring2 =
		    "W" + std::to_string(wafer2.toEnum()) + "T" + std::to_string(trigger.toEnum());
		std::string const teststring3 =
		    "W" + std::to_string(wafer3.toEnum()) + "T" + std::to_string(trigger.toEnum());
		ASSERT_EQ(teststring1, slurm_license(TriggerGlobal(trigger, wafer1)));
		ASSERT_EQ(teststring2, slurm_license(TriggerGlobal(trigger, wafer2)));
		ASSERT_EQ(teststring3, slurm_license(TriggerGlobal(trigger, wafer3)));
		ASSERT_NE(teststring1, slurm_license(TriggerGlobal(trigger, wafer2)));
	}
}

} // namespace v2
} // namespace hicann
} // namespace halco

