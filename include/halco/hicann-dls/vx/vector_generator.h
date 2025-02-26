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

/**
 * Coordinate describing the location of a vector generator on the FPGA.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    VectorGeneratorOnFPGA
    : public common::detail::RantWrapper<VectorGeneratorOnFPGA, uint_fast16_t, 1, 0>
    , common::CoordinateBase<VectorGeneratorOnFPGA>
{
	constexpr explicit VectorGeneratorOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const SYMBOL_VISIBLE VectorGeneratorOnFPGA top;
	static const SYMBOL_VISIBLE VectorGeneratorOnFPGA bottom;
};

/**
 * Coordinate describing the location of a vector generator control on the FPGA.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    VectorGeneratorControlOnFPGA
    : public common::detail::RantWrapper<VectorGeneratorControlOnFPGA, uint_fast16_t, 1, 0>
    , common::CoordinateBase<VectorGeneratorControlOnFPGA>
{
	constexpr explicit VectorGeneratorControlOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const SYMBOL_VISIBLE VectorGeneratorControlOnFPGA top;
	static const SYMBOL_VISIBLE VectorGeneratorControlOnFPGA bottom;
};


/**
 * Coordinate describing the location of a vector generator lookup table entry on a vector generator
 * lookup table.
 */
struct GENPYBIND(inline_base("*")) VectorGeneratorLUTEntryOnVectorGeneratorLUT
    : public common::detail::
          RantWrapper<VectorGeneratorLUTEntryOnVectorGeneratorLUT, uint_fast16_t, 255, 0>
{
	constexpr explicit VectorGeneratorLUTEntryOnVectorGeneratorLUT(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

/**
 * Coordinate describing the location of a vector generator lookup table on the FPGA.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    VectorGeneratorLUTOnFPGA
    : public common::detail::RantWrapper<VectorGeneratorLUTOnFPGA, uint_fast16_t, 1, 0>
    , common::CoordinateBase<VectorGeneratorLUTOnFPGA>
{
	constexpr explicit VectorGeneratorLUTOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const SYMBOL_VISIBLE VectorGeneratorLUTOnFPGA top;
	static const SYMBOL_VISIBLE VectorGeneratorLUTOnFPGA bottom;
};


HALCO_COORDINATE_MIXIN(VectorGeneratorLUTMixin, VectorGeneratorLUTOnFPGA, lookup_table)

/**
 * Coordinate describing the location of a vector generator lookup table entry on the FPGA.
 */
struct GENPYBIND(inline_base("*VectorGeneratorLUTMixin*"), inline_base("*CoordinateBase*"))
    VectorGeneratorLUTEntryOnFPGA
    : public VectorGeneratorLUTMixin<
          VectorGeneratorLUTEntryOnFPGA,
          VectorGeneratorLUTEntryOnVectorGeneratorLUT>
    , common::CoordinateBase<VectorGeneratorLUTEntryOnFPGA>
{
	VectorGeneratorLUTEntryOnFPGA() = default;

	explicit VectorGeneratorLUTEntryOnFPGA(
	    VectorGeneratorLUTEntryOnVectorGeneratorLUT const& entry,
	    VectorGeneratorLUTOnFPGA const& hemisphere = VectorGeneratorLUTOnFPGA()) :
	    mixin_t(entry, hemisphere)
	{}

	explicit VectorGeneratorLUTEntryOnFPGA(enum_type const& e) : mixin_t(e) {}

	VectorGeneratorLUTEntryOnVectorGeneratorLUT toVectorGeneratorLUTEntryOnVectorGeneratorLUT()
	    const
	{
		return This();
	}
};


/**
 * Coordinate describing the location of a vector generator notification address on the FPGA.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    VectorGeneratorNotificationAddressOnFPGA
    : public common::detail::
          RantWrapper<VectorGeneratorNotificationAddressOnFPGA, uint_fast16_t, 1, 0>
    , common::CoordinateBase<VectorGeneratorNotificationAddressOnFPGA>
{
	constexpr explicit VectorGeneratorNotificationAddressOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const SYMBOL_VISIBLE VectorGeneratorNotificationAddressOnFPGA top;
	static const SYMBOL_VISIBLE VectorGeneratorNotificationAddressOnFPGA bottom;
};


/**
 * Coordinate describing the location of a vector generator trigger on the FPGA.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    VectorGeneratorTriggerOnFPGA
    : public common::detail::RantWrapper<VectorGeneratorTriggerOnFPGA, uint_fast16_t, 1, 0>
    , common::CoordinateBase<VectorGeneratorTriggerOnFPGA>
{
	constexpr explicit VectorGeneratorTriggerOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const SYMBOL_VISIBLE VectorGeneratorTriggerOnFPGA top;
	static const SYMBOL_VISIBLE VectorGeneratorTriggerOnFPGA bottom;
};


/**
 * Coordinate describing the location of a vector generator input FIFO on the FPGA.
 */
struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    VectorGeneratorFIFOWordOnFPGA
    : public common::detail::RantWrapper<VectorGeneratorFIFOWordOnFPGA, uint_fast16_t, 1, 0>
    , common::CoordinateBase<VectorGeneratorFIFOWordOnFPGA>
{
	constexpr explicit VectorGeneratorFIFOWordOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const SYMBOL_VISIBLE VectorGeneratorFIFOWordOnFPGA top;
	static const SYMBOL_VISIBLE VectorGeneratorFIFOWordOnFPGA bottom;
};

/**
 * Coordinate describing a source on a vector generator.
 */
struct GENPYBIND(inline_base("*")) SourceOnVectorGenerator
    : public common::detail::RantWrapper<SourceOnVectorGenerator, uint_fast16_t, 1, 0>
{
	constexpr explicit SourceOnVectorGenerator(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

} // namespace vx
} // namespace halco::hicann_dls

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::VectorGeneratorOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::VectorGeneratorControlOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::VectorGeneratorLUTEntryOnVectorGeneratorLUT)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::VectorGeneratorLUTOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::VectorGeneratorLUTEntryOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::VectorGeneratorNotificationAddressOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::VectorGeneratorTriggerOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::VectorGeneratorFIFOWordOnFPGA)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SourceOnVectorGenerator)

} // namespace std
