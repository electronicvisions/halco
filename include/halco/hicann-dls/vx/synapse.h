#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"

#include "halco/hicann-dls/vx/quad.h"
#include "halco/hicann-dls/vx/synram.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct SynapseDriverOnSynapseDriverBlock;
struct NeuronConfigBlockOnDLS;
struct NeuronColumnOnDLS;
struct ColumnCorrelationQuadOnSynram;
struct ColumnCurrentQuadOnSynram;

/***********\
   Synapse
\***********/

struct GENPYBIND(inline_base("*")) SynapseQuadColumnOnDLS
    : public common::detail::RantWrapper<SynapseQuadColumnOnDLS, uint_fast16_t, 63, 0>
    , public common::detail::XRangedTrait
{
	constexpr explicit SynapseQuadColumnOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	constexpr explicit SynapseQuadColumnOnDLS(common::X const& x) GENPYBIND(implicit_conversion) :
	    rant_t(x)
	{}

	ColumnCorrelationQuadOnSynram toColumnCorrelationQuadOnSynram() const;
	ColumnCurrentQuadOnSynram toColumnCurrentQuadOnSynram() const;
};

HALCO_COORDINATE_MIXIN(SynapseQuadColumnMixin, SynapseQuadColumnOnDLS, synapse_quad_column)


struct GENPYBIND(inline_base("*")) SynapseRowOnSynram
    : public common::detail::RantWrapper<SynapseRowOnSynram, uint_fast16_t, 255, 0>
    , public common::detail::YRangedTrait
{
	constexpr explicit SynapseRowOnSynram(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	constexpr explicit SynapseRowOnSynram(common::Y const& y) GENPYBIND(implicit_conversion) :
	    rant_t(y)
	{}

	SynapseDriverOnSynapseDriverBlock toSynapseDriverOnSynapseDriverBlock() const;
};


struct GENPYBIND(inline_base("*SynramMixin*")) SynapseRowOnDLS
    : public SynramMixin<SynapseRowOnDLS, SynapseRowOnSynram>
{
	SynapseRowOnDLS() = default;

	explicit SynapseRowOnDLS(
	    SynapseRowOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit SynapseRowOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseRowOnSynram toSynapseRowOnSynram() const { return This(); }
};


struct GENPYBIND(inline_base("*SynramMixin*")) CorrelationResetRowOnDLS
    : public SynramMixin<CorrelationResetRowOnDLS, SynapseRowOnSynram>
{
	CorrelationResetRowOnDLS() = default;

	explicit CorrelationResetRowOnDLS(
	    SynapseRowOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit CorrelationResetRowOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseRowOnSynram toSynapseRowOnSynram() const { return This(); }
};


struct GENPYBIND(inline_base("*")) SynapseQuadOnSynram
    : public common::detail::
          GridCoordinate<SynapseQuadOnSynram, SynapseQuadColumnOnDLS, SynapseRowOnSynram>
{
	GRID_COMMON_CONSTRUCTORS(SynapseQuadOnSynram)

	SynapseQuadColumnOnDLS toSynapseQuadColumnOnDLS() const { return x(); }
	SynapseRowOnSynram toSynapseRowOnSynram() const { return y(); }
};


struct GENPYBIND(inline_base("*SynramMixin*")) SynapseQuadOnDLS
    : public SynramMixin<SynapseQuadOnDLS, SynapseQuadOnSynram>
{
	SynapseQuadOnDLS() = default;

	explicit SynapseQuadOnDLS(
	    SynapseQuadOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit SynapseQuadOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseQuadOnSynram toSynapseQuadOnSynram() const { return This(); }

	NeuronConfigBlockOnDLS toNeuronConfigBlockOnDLS() const;
};


struct GENPYBIND(inline_base("*SynapseQuadColumnMixin*")) SynapseOnSynapseRow
    : public SynapseQuadColumnMixin<SynapseOnSynapseRow, EntryOnQuad>
{
	SynapseOnSynapseRow() = default;

	explicit SynapseOnSynapseRow(
	    EntryOnQuad const& syn_on_quad, SynapseQuadColumnOnDLS const& quad) :
	    mixin_t(syn_on_quad, quad)
	{}

	explicit SynapseOnSynapseRow(uintmax_t const value) GENPYBIND(implicit_conversion) :
	    mixin_t(enum_type(value))
	{}

	EntryOnQuad toEntryOnQuad() const { return This(); }
	NeuronColumnOnDLS toNeuronColumnOnDLS() const;
};


struct GENPYBIND(inline_base("*")) SynapticInputOnNeuron
    : public common::detail::
          RantWrapper<SynapticInputOnNeuron, uint_fast16_t, 1 /* exc. + inh. */, 0>
{
	constexpr explicit SynapticInputOnNeuron(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const SynapticInputOnNeuron excitatory;
	static const SynapticInputOnNeuron inhibitory;
};

struct GENPYBIND(inline_base("*")) SynapseBiasSelectionOnDLS
    : public common::detail::RantWrapper<SynapseBiasSelectionOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit SynapseBiasSelectionOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*SynramMixin*")) CorrelationResetOnDLS
    : public SynramMixin<CorrelationResetOnDLS, SynapseQuadOnSynram>
{
	CorrelationResetOnDLS() = default;

	explicit CorrelationResetOnDLS(
	    SynapseQuadOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit CorrelationResetOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseQuadOnSynram toSynapseQuadOnSynram() const { return This(); }
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseQuadColumnOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseRowOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseRowOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseOnSynapseRow)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapticInputOnNeuron)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseBiasSelectionOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CorrelationResetOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CorrelationResetRowOnDLS)

} // namespace std
