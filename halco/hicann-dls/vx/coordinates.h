#pragma once

extern "C"
{
#include <stdint.h>
}

#include "halco/common/common.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.th"
#include "halco/common/mixin.h"

GENPYBIND_TAG_HALCO_HICANN_DLS_VX
GENPYBIND_MANUAL({
	parent.attr("__variant__") = "pybind11";
	parent->py::module::import("pyhalco_common");
})

namespace halco {
namespace hicann_dls {
namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/**********\
    PPU
\**********/


struct GENPYBIND(inline_base("*")) PPUOnDLS
    : public common::detail::RantWrapper<PPUOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit PPUOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) PPUMemoryWordOnPPU
    : public common::detail::RantWrapper<PPUMemoryWordOnPPU, uint_fast16_t, 0x1000 - 1, 0>
{
	constexpr explicit PPUMemoryWordOnPPU(uintmax_t const val = 0) : rant_t(val) {}
};

HALCO_COORDINATE_MIXIN(PPUMixin, PPUOnDLS, ppu)

struct GENPYBIND(inline_base("*PPUMixin*")) PPUMemoryWordOnDLS
    : public PPUMixin<PPUMemoryWordOnDLS, PPUMemoryWordOnPPU>
{
private:
	typedef PPUMixin<PPUMemoryWordOnDLS, PPUMemoryWordOnPPU> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque);

	PPUMemoryWordOnDLS() = default;

	explicit PPUMemoryWordOnDLS(PPUMemoryWordOnPPU const& word, PPUOnDLS const& ppu = PPUOnDLS()) :
	    base(word, ppu)
	{}

	explicit PPUMemoryWordOnDLS(enum_type const& e) : base(e) {}

	PPUMemoryWordOnPPU toPPUMemoryWordOnPPU() const { return This(); }
	PPUOnDLS toPPUOnDLS() const { return split().first; }
};

/***************\
    ResetChip
\***************/

struct GENPYBIND(inline_base("*")) ResetChipOnDLS
    : public common::detail::RantWrapper<ResetChipOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit ResetChipOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

/************\
    Timer
\************/

struct GENPYBIND(inline_base("*")) TimerOnDLS
    : public common::detail::RantWrapper<TimerOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit TimerOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

/***********\
    Jtag
\***********/

struct GENPYBIND(inline_base("*")) JtagOnDLS
    : public common::detail::RantWrapper<JtagOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit JtagOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

/**********\
    Pll
\**********/

struct GENPYBIND(inline_base("*")) PllRegisterOnDLS
    : public common::detail::RantWrapper<PllRegisterOnDLS, uint_fast16_t, 9, 0>
{
	constexpr explicit PllRegisterOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

/**************\
    Omnibus
\**************/

struct GENPYBIND(inline_base("*")) OmnibusAddress
    : public common::detail::BaseType<OmnibusAddress, uint32_t>
{
	constexpr explicit OmnibusAddress(uintmax_t const val = 0) : base_t(val) {}
};

} // namespace vx
} // namespace hicann_dls
} // namespace halco

// std::hash specializations
namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryWordOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryWordOnPPU)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ResetChipOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::JtagOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PllRegisterOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::TimerOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::OmnibusAddress)

} // namespace std

GENPYBIND(postamble, tag(hicann_dls_vx))
GENPYBIND_MANUAL({
	parent->py::module::import("pyhalco_hicann_dls_vx_patch").attr("patch")(parent);
})
