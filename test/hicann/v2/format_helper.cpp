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
	EXPECT_EQ(to_string(w),  "W002");
	EXPECT_EQ(boost::get<Wafer>(from_string("W002")), w);

	ANANASOnWafer a(Enum(1));
	EXPECT_EQ(short_format(a),  "A1");
	EXPECT_EQ(to_string(a),  "A1");
	EXPECT_EQ(boost::get<ANANASOnWafer>(from_string("A1")), a);

	ANANASGlobal ag(a,w);
	EXPECT_EQ(short_format(ag), "W002A1");
	EXPECT_EQ(to_string(ag), "W002A1");
	EXPECT_EQ(boost::get<ANANASGlobal>(from_string("W002A1")), ag);

	AuxPwrOnWafer ap(Enum(1));
	EXPECT_EQ(short_format(ap),  "AP1");
	EXPECT_EQ(to_string(ap),  "AP1");
	EXPECT_EQ(boost::get<AuxPwrOnWafer>(from_string("AP1")), ap);

	AuxPwrGlobal apg(ap,w);
	EXPECT_EQ(short_format(apg), "W002AP1");
	EXPECT_EQ(to_string(apg), "W002AP1");
	EXPECT_EQ(boost::get<AuxPwrGlobal>(from_string("W002AP1")), apg);

	HICANNOnWafer h(Enum(3));
	EXPECT_EQ(short_format(h),  "H003");
	EXPECT_EQ(to_string(h),  "H003");
	EXPECT_EQ(boost::get<HICANNOnWafer>(from_string("H003")), h);

	HICANNGlobal hg(h,w);
	EXPECT_EQ(short_format(hg), "W002H003");
	EXPECT_EQ(to_string(hg), "W002H003");
	EXPECT_EQ(boost::get<HICANNGlobal>(from_string("W002H003")), hg);

	FPGAOnWafer f(Enum(4));
	EXPECT_EQ(short_format(f),  "F004");
	EXPECT_EQ(to_string(f),  "F004");
	EXPECT_EQ(boost::get<FPGAOnWafer>(from_string("F004")), f);

	FPGAGlobal fg(f,w);
	EXPECT_EQ(short_format(fg), "W002F004");
	EXPECT_EQ(to_string(fg), "W002F004");
	EXPECT_EQ(boost::get<FPGAGlobal>(from_string("W002F004")), fg);

	DNCOnWafer d(Enum(4));
	EXPECT_EQ(short_format(d),  "D004");
	EXPECT_EQ(to_string(d),  "D004");
	EXPECT_EQ(boost::get<DNCOnWafer>(from_string("D004")), d);

	DNCGlobal dg(d,w);
	EXPECT_EQ(short_format(dg), "W002D004");
	EXPECT_EQ(to_string(dg), "W002D004");
	EXPECT_EQ(boost::get<DNCGlobal>(from_string("W002D004")), dg);

	TriggerOnWafer t(Enum(3));
	EXPECT_EQ(short_format(t),  "T03");
	EXPECT_EQ(to_string(t), "T03");
	EXPECT_EQ(boost::get<TriggerOnWafer>(from_string("T03")), t);

	TriggerGlobal tg(t,w);
	EXPECT_EQ(short_format(tg), "W002T03");
	EXPECT_EQ(to_string(tg), "W002T03");
	EXPECT_EQ(boost::get<TriggerGlobal>(from_string("W002T03")), tg);

	RepeaterBlockOnHICANN rb(Enum(2));
	EXPECT_EQ(short_format(rb), "RB2");
	EXPECT_EQ(to_string(rb), "RB2");
	EXPECT_EQ(boost::get<RepeaterBlockOnHICANN>(from_string("RB2")), rb);

	HRepeaterOnHICANN hr(Enum(5));
	EXPECT_EQ(short_format(hr), "HR005");
	EXPECT_EQ(to_string(hr), "HR005");
	EXPECT_EQ(boost::get<HRepeaterOnHICANN>(from_string("HR005")), hr);

	VRepeaterOnHICANN vr(Enum(6));
	EXPECT_EQ(short_format(vr), "VR006");
	EXPECT_EQ(to_string(vr), "VR006");
	EXPECT_EQ(boost::get<VRepeaterOnHICANN>(from_string("VR006")), vr);

	RepeaterBlockOnWafer rb_on_wafer(rb, h);
	EXPECT_EQ(short_format(rb_on_wafer), "H003RB2");
	EXPECT_EQ(to_string(rb_on_wafer), "H003RB2");
	EXPECT_EQ(boost::get<RepeaterBlockOnWafer>(from_string("H003RB2")), rb_on_wafer);

	HRepeaterOnWafer hr_on_wafer(hr, h);
	EXPECT_EQ(short_format(hr_on_wafer), "H003HR005");
	EXPECT_EQ(to_string(hr_on_wafer), "H003HR005");
	EXPECT_EQ(boost::get<HRepeaterOnWafer>(from_string("H003HR005")), hr_on_wafer);

	VRepeaterOnWafer vr_on_wafer(vr, h);
	EXPECT_EQ(short_format(vr_on_wafer), "H003VR006");
	EXPECT_EQ(to_string(vr_on_wafer), "H003VR006");
	EXPECT_EQ(boost::get<VRepeaterOnWafer>(from_string("H003VR006")), vr_on_wafer);

	HLineOnHICANN hl(Enum(5));
	EXPECT_EQ(short_format(hl), "HL005");
	EXPECT_EQ(to_string(hl), "HL005");
	EXPECT_EQ(boost::get<HLineOnHICANN>(from_string("HL005")), hl);

	VLineOnHICANN vl(Enum(6));
	EXPECT_EQ(short_format(vl), "VL006");
	EXPECT_EQ(to_string(vl), "VL006");
	EXPECT_EQ(boost::get<VLineOnHICANN>(from_string("VL006")), vl);

	EXPECT_ANY_THROW(from_string(""));
	EXPECT_ANY_THROW(from_string("123W33"));
	EXPECT_ANY_THROW(from_string("W33X"));
	EXPECT_ANY_THROW(from_string("W33F12 "));
	EXPECT_ANY_THROW(from_string(" W33F12"));

	std::vector<std::string> vs = {"W1", "W2", "W3"};
	std::vector<Wafer> const expected_wafers = {Wafer(1), Wafer(2), Wafer(3)};
	EXPECT_EQ(from_string<Wafer>(vs), expected_wafers);

	std::vector<std::string> mixed_types_v = {"W1", "W1F1"};
	EXPECT_ANY_THROW(from_string<Wafer>(mixed_types_v));
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

