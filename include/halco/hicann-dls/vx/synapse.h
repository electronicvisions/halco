#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"
#include "halco/common/typed_array.h"

#include "halco/hicann-dls/vx/quad.h"
#include "halco/hicann-dls/vx/synram.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct SynapseDriverOnSynapseDriverBlock;
struct NeuronConfigBlockOnDLS;
struct NeuronColumnOnDLS;
struct ColumnCorrelationQuadOnSynram;
struct ColumnCurrentQuadOnSynram;
struct SynapseRowOnDLS;
struct SynapseWeightRowOnDLS;
struct SynapseLabelRowOnDLS;
struct SynapseCorrelationCalibRowOnDLS;
struct SynapseQuadOnDLS;
struct SynapseWeightQuadOnDLS;
struct SynapseLabelQuadOnDLS;
struct SynapseCorrelationCalibQuadOnDLS;

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
	common::typed_array<NeuronColumnOnDLS, EntryOnQuad> toNeuronColumnOnDLS() const;
};

HALCO_COORDINATE_MIXIN(SynapseQuadColumnMixin, SynapseQuadColumnOnDLS, synapse_quad_column)


struct GENPYBIND(inline_base("*")) SynapseRowOnSynapseDriver
    : public common::detail::RantWrapper<SynapseRowOnSynapseDriver, uint_fast16_t, 1, 0>
{
	constexpr explicit SynapseRowOnSynapseDriver(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const SynapseRowOnSynapseDriver top;
	static const SynapseRowOnSynapseDriver bottom;
};

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
	SynapseRowOnSynapseDriver toSynapseRowOnSynapseDriver() const;
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
	SynapseWeightRowOnDLS toSynapseWeightRowOnDLS() const;
	SynapseLabelRowOnDLS toSynapseLabelRowOnDLS() const;
	SynapseCorrelationCalibRowOnDLS toSynapseCorrelationCalibRowOnDLS() const;
};


struct GENPYBIND(inline_base("*SynramMixin*")) SynapseWeightRowOnDLS
    : public SynramMixin<SynapseWeightRowOnDLS, SynapseRowOnSynram>
{
	SynapseWeightRowOnDLS() = default;

	explicit SynapseWeightRowOnDLS(
	    SynapseRowOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit SynapseWeightRowOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseRowOnSynram toSynapseRowOnSynram() const
	{
		return This();
	}
	SynapseRowOnDLS toSynapseRowOnDLS() const;
	SynapseLabelRowOnDLS toSynapseLabelRowOnDLS() const;
	SynapseCorrelationCalibRowOnDLS toSynapseCorrelationCalibRowOnDLS() const;
};


struct GENPYBIND(inline_base("*SynramMixin*")) SynapseLabelRowOnDLS
    : public SynramMixin<SynapseLabelRowOnDLS, SynapseRowOnSynram>
{
	SynapseLabelRowOnDLS() = default;

	explicit SynapseLabelRowOnDLS(
	    SynapseRowOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit SynapseLabelRowOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseRowOnSynram toSynapseRowOnSynram() const
	{
		return This();
	}
	SynapseRowOnDLS toSynapseRowOnDLS() const;
	SynapseWeightRowOnDLS toSynapseWeightRowOnDLS() const;
	SynapseCorrelationCalibRowOnDLS toSynapseCorrelationCalibRowOnDLS() const;
};


struct GENPYBIND(inline_base("*SynramMixin*")) SynapseCorrelationCalibRowOnDLS
    : public SynramMixin<SynapseCorrelationCalibRowOnDLS, SynapseRowOnSynram>
{
	SynapseCorrelationCalibRowOnDLS() = default;

	explicit SynapseCorrelationCalibRowOnDLS(
	    SynapseRowOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit SynapseCorrelationCalibRowOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseRowOnSynram toSynapseRowOnSynram() const
	{
		return This();
	}
	SynapseRowOnDLS toSynapseRowOnDLS() const;
	SynapseLabelRowOnDLS toSynapseLabelRowOnDLS() const;
	SynapseWeightRowOnDLS toSynapseWeightRowOnDLS() const;
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
	SynapseWeightQuadOnDLS toSynapseWeightQuadOnDLS() const;
	SynapseLabelQuadOnDLS toSynapseLabelQuadOnDLS() const;
	SynapseCorrelationCalibQuadOnDLS toSynapseCorrelationCalibQuadOnDLS() const;
};


struct GENPYBIND(inline_base("*SynramMixin*")) SynapseWeightQuadOnDLS
    : public SynramMixin<SynapseWeightQuadOnDLS, SynapseQuadOnSynram>
{
	SynapseWeightQuadOnDLS() = default;

	explicit SynapseWeightQuadOnDLS(
	    SynapseQuadOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit SynapseWeightQuadOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseQuadOnSynram toSynapseQuadOnSynram() const
	{
		return This();
	}

	NeuronConfigBlockOnDLS toNeuronConfigBlockOnDLS() const;
	SynapseQuadOnDLS toSynapseQuadOnDLS() const;
	SynapseLabelQuadOnDLS toSynapseLabelQuadOnDLS() const;
	SynapseCorrelationCalibQuadOnDLS toSynapseCorrelationCalibQuadOnDLS() const;
};


struct GENPYBIND(inline_base("*SynramMixin*")) SynapseLabelQuadOnDLS
    : public SynramMixin<SynapseLabelQuadOnDLS, SynapseQuadOnSynram>
{
	SynapseLabelQuadOnDLS() = default;

	explicit SynapseLabelQuadOnDLS(
	    SynapseQuadOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit SynapseLabelQuadOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseQuadOnSynram toSynapseQuadOnSynram() const
	{
		return This();
	}

	NeuronConfigBlockOnDLS toNeuronConfigBlockOnDLS() const;
	SynapseWeightQuadOnDLS toSynapseWeightQuadOnDLS() const;
	SynapseQuadOnDLS toSynapseQuadOnDLS() const;
	SynapseCorrelationCalibQuadOnDLS toSynapseCorrelationCalibQuadOnDLS() const;
};


struct GENPYBIND(inline_base("*SynramMixin*")) SynapseCorrelationCalibQuadOnDLS
    : public SynramMixin<SynapseCorrelationCalibQuadOnDLS, SynapseQuadOnSynram>
{
	SynapseCorrelationCalibQuadOnDLS() = default;

	explicit SynapseCorrelationCalibQuadOnDLS(
	    SynapseQuadOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit SynapseCorrelationCalibQuadOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseQuadOnSynram toSynapseQuadOnSynram() const
	{
		return This();
	}

	NeuronConfigBlockOnDLS toNeuronConfigBlockOnDLS() const;
	SynapseWeightQuadOnDLS toSynapseWeightQuadOnDLS() const;
	SynapseLabelQuadOnDLS toSynapseLabelQuadOnDLS() const;
	SynapseQuadOnDLS toSynapseQuadOnDLS() const;
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


struct GENPYBIND(inline_base("*")) SynapseWeightMatrixOnDLS
    : public common::detail::RantWrapper<SynapseWeightMatrixOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit SynapseWeightMatrixOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const SynapseWeightMatrixOnDLS top;
	static const SynapseWeightMatrixOnDLS bottom;
};


struct GENPYBIND(inline_base("*")) SynapseLabelMatrixOnDLS
    : public common::detail::RantWrapper<SynapseLabelMatrixOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit SynapseLabelMatrixOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const SynapseLabelMatrixOnDLS top;
	static const SynapseLabelMatrixOnDLS bottom;
};


struct GENPYBIND(inline_base("*")) SynapseCorrelationCalibMatrixOnDLS
    : public common::detail::RantWrapper<SynapseCorrelationCalibMatrixOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit SynapseCorrelationCalibMatrixOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const SynapseCorrelationCalibMatrixOnDLS top;
	static const SynapseCorrelationCalibMatrixOnDLS bottom;
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseQuadColumnOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseRowOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseRowOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseWeightRowOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseLabelRowOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseCorrelationCalibRowOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseWeightQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseLabelQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseCorrelationCalibQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseOnSynapseRow)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapticInputOnNeuron)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseBiasSelectionOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CorrelationResetOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CorrelationResetRowOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseWeightMatrixOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseLabelMatrixOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseCorrelationCalibMatrixOnDLS)

} // namespace std
