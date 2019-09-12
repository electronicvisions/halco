#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.th"
#include "halco/common/mixin.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct CADCConfigOnDLS;

/**********\
    PPU
\**********/

struct GENPYBIND(inline_base("*")) PPUOnDLS
    : public common::detail::RantWrapper<PPUOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit PPUOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CADCConfigOnDLS toCADCConfigOnDLS() const;

	static const PPUOnDLS top;
	static const PPUOnDLS bottom;
};

constexpr static uint_fast16_t enum_vertical_top = 0;
constexpr static uint_fast16_t enum_vertical_bottom = 1;


struct GENPYBIND(inline_base("*")) PPUMemoryWordOnPPU
    : public common::detail::RantWrapper<PPUMemoryWordOnPPU, uint_fast16_t, 0x1000 - 1, 0>
{
	constexpr explicit PPUMemoryWordOnPPU(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	/** Return code word location (atop first stack frame). */
	static const PPUMemoryWordOnPPU return_code;
};


struct GENPYBIND(inline_base("*")) PPUMemoryBlockSize
    : public common::detail::
          RantWrapper<PPUMemoryBlockSize, uint_fast16_t, PPUMemoryWordOnPPU::size, 1>
{
	constexpr explicit PPUMemoryBlockSize(uintmax_t const val = 1) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) PPUMemoryBlockOnPPU
    : public common::detail::IntervalCoordinate<PPUMemoryBlockOnPPU, PPUMemoryWordOnPPU>
{
	INTERVAL_COMMON_CONSTRUCTORS(PPUMemoryBlockOnPPU)

	PPUMemoryBlockSize toPPUMemoryBlockSize() const { return PPUMemoryBlockSize(length()); }

	/** Location of mailbox memory area (deprecated). */
	static const PPUMemoryBlockOnPPU mailbox;
};


struct GENPYBIND(inline_base("*")) PPUMemoryOnPPU
    : public common::detail::RantWrapper<PPUMemoryOnPPU, uint_fast16_t, 0, 0>
{
	constexpr explicit PPUMemoryOnPPU(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*")) PPUControlRegisterOnPPU
    : public common::detail::RantWrapper<PPUControlRegisterOnPPU, uint_fast16_t, 0, 0>
{
	constexpr explicit PPUControlRegisterOnPPU(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*")) PPUStatusRegisterOnPPU
    : public common::detail::RantWrapper<PPUStatusRegisterOnPPU, uint_fast16_t, 0, 0>
{
	constexpr explicit PPUStatusRegisterOnPPU(uintmax_t const val = 0) : rant_t(val) {}
};


HALCO_COORDINATE_MIXIN(PPUMixin, PPUOnDLS, ppu)


struct GENPYBIND(inline_base("*PPUMixin*")) PPUMemoryBlockOnDLS
    : public PPUMixin<PPUMemoryBlockOnDLS, PPUMemoryBlockOnPPU>
{
	PPUMemoryBlockOnDLS() = default;

	explicit PPUMemoryBlockOnDLS(PPUMemoryBlockOnPPU const& reg, PPUOnDLS const& ppu = PPUOnDLS()) :
	    mixin_t(reg, ppu)
	{}

	explicit PPUMemoryBlockOnDLS(enum_type const& e) : mixin_t(e) {}

	PPUMemoryBlockOnPPU toPPUMemoryBlockOnPPU() const { return This(); }
};


struct GENPYBIND(inline_base("*PPUMixin*")) PPUMemoryOnDLS
    : public PPUMixin<PPUMemoryOnDLS, PPUMemoryOnPPU>
{
	PPUMemoryOnDLS() = default;

	explicit PPUMemoryOnDLS(PPUMemoryOnPPU const& reg, PPUOnDLS const& ppu = PPUOnDLS()) :
	    mixin_t(reg, ppu)
	{}

	explicit PPUMemoryOnDLS(enum_type const& e) : mixin_t(e) {}

	PPUMemoryOnPPU toPPUMemoryOnPPU() const { return This(); }
};


struct GENPYBIND(inline_base("*PPUMixin*")) PPUControlRegisterOnDLS
    : public PPUMixin<PPUControlRegisterOnDLS, PPUControlRegisterOnPPU>
{
	PPUControlRegisterOnDLS() = default;

	explicit PPUControlRegisterOnDLS(
	    PPUControlRegisterOnPPU const& reg, PPUOnDLS const& ppu = PPUOnDLS()) :
	    mixin_t(reg, ppu)
	{}

	explicit PPUControlRegisterOnDLS(enum_type const& e) : mixin_t(e) {}

	PPUControlRegisterOnPPU toPPUControlRegisterOnPPU() const { return This(); }
};


struct GENPYBIND(inline_base("*PPUMixin*")) PPUStatusRegisterOnDLS
    : public PPUMixin<PPUStatusRegisterOnDLS, PPUStatusRegisterOnPPU>
{
	PPUStatusRegisterOnDLS() = default;

	explicit PPUStatusRegisterOnDLS(
	    PPUStatusRegisterOnPPU const& reg, PPUOnDLS const& ppu = PPUOnDLS()) :
	    mixin_t(reg, ppu)
	{}

	explicit PPUStatusRegisterOnDLS(enum_type const& e) : mixin_t(e) {}

	PPUStatusRegisterOnPPU toPPUStatusRegisterOnPPU() const { return This(); }
};


struct GENPYBIND(inline_base("*PPUMixin*")) PPUMemoryWordOnDLS
    : public PPUMixin<PPUMemoryWordOnDLS, PPUMemoryWordOnPPU>
{
	PPUMemoryWordOnDLS() = default;

	explicit PPUMemoryWordOnDLS(PPUMemoryWordOnPPU const& word, PPUOnDLS const& ppu = PPUOnDLS()) :
	    mixin_t(word, ppu)
	{}

	explicit PPUMemoryWordOnDLS(enum_type const& e) : mixin_t(e) {}

	PPUMemoryWordOnPPU toPPUMemoryWordOnPPU() const { return This(); }
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryWordOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryWordOnPPU)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryBlockOnPPU)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryOnPPU)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryBlockSize)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUStatusRegisterOnPPU)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUStatusRegisterOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUControlRegisterOnPPU)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUControlRegisterOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUOnDLS)

} // namespace std
