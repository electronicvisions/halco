#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

#include "halco/hicann-dls/vx/hemisphere_fwd.h"

/**
 * Identifier for a hemisphere of a DLS chip.
 * A hemisphere consists of all elements _on_ a hemisphere, i.e. a PPU, a synapse array with
 * synapse drivers and a neuron row.
 */
struct GENPYBIND(inline_base("*")) HemisphereOnDLS
    : public common::detail::RantWrapper<HemisphereOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit HemisphereOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const HemisphereOnDLS top;
	static const HemisphereOnDLS bottom;

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"
};


/**
 * Unique identifier for a chip on a DLS setup.
 */
struct GENPYBIND(inline_base("*")) ChipOnDLS
    : public common::detail::RantWrapper<ChipOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit ChipOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


/**
 * Global identifier for a physical DLS chip instance.
 */
struct GENPYBIND(inline_base("*")) DLSGlobal
    : public common::detail::RantWrapper<DLSGlobal, uint_fast32_t, 254, 0> // arbitrary limit, ranged
                                                                           // type needed for mixin
                                                                           // below to work (#3423)
{
	constexpr explicit DLSGlobal(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


HALCO_COORDINATE_MIXIN(DLSMixin, DLSGlobal, dls)

/**
 * Global identifier for a hemisphere on a physical DLS chip instance.
 */
struct GENPYBIND(inline_base("*DLSMixin*")) HemisphereGlobal
    : public DLSMixin<HemisphereGlobal, HemisphereOnDLS>
{
	HemisphereGlobal() = default;

	explicit HemisphereGlobal(HemisphereOnDLS const& half, DLSGlobal const& dls) :
	    mixin_t(half, dls)
	{}

	explicit HemisphereGlobal(enum_type const& e) : mixin_t(e) {}

	HemisphereOnDLS toHemisphereOnDLS() const { return This(); }
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::DLSGlobal)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ChipOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::HemisphereOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::HemisphereGlobal)

} // namespace std
