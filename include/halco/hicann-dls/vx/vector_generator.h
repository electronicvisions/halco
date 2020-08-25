#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

#include "halco/hicann-dls/vx/hemisphere_fwd.h"

/**
 * Coordinate describing the location of a vector generator on the FPGA.
 */
struct GENPYBIND(inline_base("*")) VectorGeneratorOnFPGA
    : public common::detail::RantWrapper<VectorGeneratorOnFPGA, uint_fast16_t, 1, 0>
{
	constexpr explicit VectorGeneratorOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const VectorGeneratorOnFPGA top;
	static const VectorGeneratorOnFPGA bottom;
};

/**
 * Coordinate describing the location of a vector generator control on the FPGA.
 */
struct GENPYBIND(inline_base("*")) VectorGeneratorControlOnFPGA
    : public common::detail::RantWrapper<VectorGeneratorControlOnFPGA, uint_fast16_t, 1, 0>
{
	constexpr explicit VectorGeneratorControlOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const VectorGeneratorControlOnFPGA top;
	static const VectorGeneratorControlOnFPGA bottom;
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
struct GENPYBIND(inline_base("*")) VectorGeneratorLUTOnFPGA
    : public common::detail::RantWrapper<VectorGeneratorLUTOnFPGA, uint_fast16_t, 1, 0>
{
	constexpr explicit VectorGeneratorLUTOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const VectorGeneratorLUTOnFPGA top;
	static const VectorGeneratorLUTOnFPGA bottom;
};


HALCO_COORDINATE_MIXIN(VectorGeneratorLUTMixin, VectorGeneratorLUTOnFPGA, lookup_table)

/**
 * Coordinate describing the location of a vector generator lookup table entry on the FPGA.
 */
struct GENPYBIND(inline_base("*VectorGeneratorLUTMixin*")) VectorGeneratorLUTEntryOnFPGA
    : public VectorGeneratorLUTMixin<
          VectorGeneratorLUTEntryOnFPGA,
          VectorGeneratorLUTEntryOnVectorGeneratorLUT>
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
struct GENPYBIND(inline_base("*")) VectorGeneratorNotificationAddressOnFPGA
    : public common::detail::
          RantWrapper<VectorGeneratorNotificationAddressOnFPGA, uint_fast16_t, 1, 0>
{
	constexpr explicit VectorGeneratorNotificationAddressOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const VectorGeneratorNotificationAddressOnFPGA top;
	static const VectorGeneratorNotificationAddressOnFPGA bottom;
};


/**
 * Coordinate describing the location of a vector generator trigger on the FPGA.
 */
struct GENPYBIND(inline_base("*")) VectorGeneratorTriggerOnFPGA
    : public common::detail::RantWrapper<VectorGeneratorTriggerOnFPGA, uint_fast16_t, 1, 0>
{
	constexpr explicit VectorGeneratorTriggerOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const VectorGeneratorTriggerOnFPGA top;
	static const VectorGeneratorTriggerOnFPGA bottom;
};


/**
 * Coordinate describing the location of a vector generator input FIFO on the FPGA.
 */
struct GENPYBIND(inline_base("*")) VectorGeneratorFIFOWordOnFPGA
    : public common::detail::RantWrapper<VectorGeneratorFIFOWordOnFPGA, uint_fast16_t, 1, 0>
{
	constexpr explicit VectorGeneratorFIFOWordOnFPGA(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const VectorGeneratorFIFOWordOnFPGA top;
	static const VectorGeneratorFIFOWordOnFPGA bottom;
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

} // namespace halco::hicann_dls::vx

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
