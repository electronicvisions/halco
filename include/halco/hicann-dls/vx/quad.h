#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"

namespace halco::hicann_dls {
namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/**
 * General coordinate used for localisation of an entry inside a coordinate localising a quad block
 * of configuration.
 * Quad-only access is provided for SynapseQuad, CADCSampleQuad, ColumnCorrelationQuad and
 * ColumnCurrentQuad.
 */
struct GENPYBIND(inline_base("*")) EntryOnQuad
    : public common::detail::RantWrapper<EntryOnQuad, uint_fast16_t, 3, 0>
{
	constexpr explicit EntryOnQuad(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

} // namespace vx
} // namespace halco::hicann_dls

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::EntryOnQuad)

} // namespace std
