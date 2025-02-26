#pragma once
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"
#include "hate/visibility.h"

namespace halco::hicann_dls {
namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

#include "halco/hicann-dls/vx/hemisphere_fwd.h"

/**********\
    PPU
\**********/

struct GENPYBIND(inline_base("*")) PPUOnDLS
    : public common::detail::RantWrapper<PPUOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit PPUOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const SYMBOL_VISIBLE PPUOnDLS top;
	static const SYMBOL_VISIBLE PPUOnDLS bottom;
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
	static const SYMBOL_VISIBLE PPUMemoryWordOnPPU return_code;
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
	static const SYMBOL_VISIBLE PPUMemoryBlockOnPPU mailbox;
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) PPUMemoryOnDLS
    : public common::detail::RantWrapper<PPUMemoryOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<PPUMemoryOnDLS>
{
	constexpr explicit PPUMemoryOnDLS(uintmax_t const val = 0) : rant_t(val) {}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    PPUControlRegisterOnDLS
    : public common::detail::RantWrapper<PPUControlRegisterOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<PPUControlRegisterOnDLS>
{
	constexpr explicit PPUControlRegisterOnDLS(uintmax_t const val = 0) : rant_t(val) {}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    PPUStatusRegisterOnDLS
    : public common::detail::RantWrapper<PPUStatusRegisterOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<PPUStatusRegisterOnDLS>
{
	constexpr explicit PPUStatusRegisterOnDLS(uintmax_t const val = 0) : rant_t(val) {}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"
};


HALCO_COORDINATE_MIXIN(PPUMixin, PPUOnDLS, ppu)


struct GENPYBIND(inline_base("*PPUMixin*"), inline_base("*CoordinateBase*")) PPUMemoryBlockOnDLS
    : public PPUMixin<PPUMemoryBlockOnDLS, PPUMemoryBlockOnPPU>
    , common::CoordinateBase<PPUMemoryBlockOnDLS>
{
	PPUMemoryBlockOnDLS() = default;

	explicit PPUMemoryBlockOnDLS(PPUMemoryBlockOnPPU const& reg, PPUOnDLS const& ppu = PPUOnDLS()) :
	    mixin_t(reg, ppu)
	{}

	explicit PPUMemoryBlockOnDLS(enum_type const& e) : mixin_t(e) {}

	PPUMemoryBlockOnPPU toPPUMemoryBlockOnPPU() const { return This(); }
};


struct GENPYBIND(inline_base("*PPUMixin*"), inline_base("*CoordinateBase*")) PPUMemoryWordOnDLS
    : public PPUMixin<PPUMemoryWordOnDLS, PPUMemoryWordOnPPU>
    , common::CoordinateBase<PPUMemoryWordOnDLS>
{
	PPUMemoryWordOnDLS() = default;

	explicit PPUMemoryWordOnDLS(PPUMemoryWordOnPPU const& word, PPUOnDLS const& ppu = PPUOnDLS()) :
	    mixin_t(word, ppu)
	{}

	explicit PPUMemoryWordOnDLS(enum_type const& e) : mixin_t(e) {}

	PPUMemoryWordOnPPU toPPUMemoryWordOnPPU() const { return This(); }
};

} // namespace vx
} // namespace halco::hicann_dls

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryWordOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryWordOnPPU)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryBlockOnPPU)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUMemoryBlockSize)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUStatusRegisterOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUControlRegisterOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PPUOnDLS)

} // namespace std
