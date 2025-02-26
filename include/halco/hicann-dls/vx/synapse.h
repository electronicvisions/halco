#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"
#include "halco/common/typed_array.h"
#include "halco/hicann-dls/vx/quad.h"
#include "halco/hicann-dls/vx/synram.h"
#include "hate/visibility.h"

namespace halco::hicann_dls {
namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct SynapseDriverOnSynapseDriverBlock;
struct NeuronConfigBlockOnDLS;
struct SynapseRowOnDLS;
struct SynapseWeightRowOnDLS;
struct SynapseLabelRowOnDLS;
struct SynapseCorrelationCalibRowOnDLS;
struct ColumnCorrelationQuadOnSynram;
struct ColumnCurrentQuadOnSynram;
struct NeuronColumnOnDLS;
struct SynapseQuadOnDLS;
struct SynapseWeightQuadOnDLS;
struct SynapseLabelQuadOnDLS;
struct SynapseCorrelationCalibQuadOnDLS;
struct SynapseRowOnSynram;
struct CADCChannelColumnOnSynram;

/***********\
   Synapse
\***********/

struct GENPYBIND(inline_base("*")) SynapseRowOnSynapseDriver
    : public common::detail::RantWrapper<SynapseRowOnSynapseDriver, uint_fast16_t, 1, 0>
{
	constexpr explicit SynapseRowOnSynapseDriver(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const SYMBOL_VISIBLE SynapseRowOnSynapseDriver top;
	static const SYMBOL_VISIBLE SynapseRowOnSynapseDriver bottom;
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

	SynapseDriverOnSynapseDriverBlock toSynapseDriverOnSynapseDriverBlock() const SYMBOL_VISIBLE;
	SynapseRowOnSynapseDriver toSynapseRowOnSynapseDriver() const SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*SynramMixin*"), inline_base("*CoordinateBase*")) SynapseRowOnDLS
    : public SynramMixin<SynapseRowOnDLS, SynapseRowOnSynram>
    , common::CoordinateBase<SynapseRowOnDLS>
{
	SynapseRowOnDLS() = default;

	explicit SynapseRowOnDLS(
	    SynapseRowOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit SynapseRowOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseRowOnSynram toSynapseRowOnSynram() const { return This(); }
	SynapseWeightRowOnDLS toSynapseWeightRowOnDLS() const SYMBOL_VISIBLE;
	SynapseLabelRowOnDLS toSynapseLabelRowOnDLS() const SYMBOL_VISIBLE;
	SynapseCorrelationCalibRowOnDLS toSynapseCorrelationCalibRowOnDLS() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*SynramMixin*"), inline_base("*CoordinateBase*"))
    SynapseWeightRowOnDLS
    : public SynramMixin<SynapseWeightRowOnDLS, SynapseRowOnSynram>
    , common::CoordinateBase<SynapseWeightRowOnDLS>
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
	SynapseRowOnDLS toSynapseRowOnDLS() const SYMBOL_VISIBLE;
	SynapseLabelRowOnDLS toSynapseLabelRowOnDLS() const SYMBOL_VISIBLE;
	SynapseCorrelationCalibRowOnDLS toSynapseCorrelationCalibRowOnDLS() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*SynramMixin*"), inline_base("*CoordinateBase*")) SynapseLabelRowOnDLS
    : public SynramMixin<SynapseLabelRowOnDLS, SynapseRowOnSynram>
    , common::CoordinateBase<SynapseLabelRowOnDLS>
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
	SynapseRowOnDLS toSynapseRowOnDLS() const SYMBOL_VISIBLE;
	SynapseWeightRowOnDLS toSynapseWeightRowOnDLS() const SYMBOL_VISIBLE;
	SynapseCorrelationCalibRowOnDLS toSynapseCorrelationCalibRowOnDLS() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*SynramMixin*"), inline_base("*CoordinateBase*"))
    SynapseCorrelationCalibRowOnDLS
    : public SynramMixin<SynapseCorrelationCalibRowOnDLS, SynapseRowOnSynram>
    , common::CoordinateBase<SynapseCorrelationCalibRowOnDLS>
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
	SynapseRowOnDLS toSynapseRowOnDLS() const SYMBOL_VISIBLE;
	SynapseLabelRowOnDLS toSynapseLabelRowOnDLS() const SYMBOL_VISIBLE;
	SynapseWeightRowOnDLS toSynapseWeightRowOnDLS() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*SynramMixin*"), inline_base("*CoordinateBase*"))
    CorrelationResetRowOnDLS
    : public SynramMixin<CorrelationResetRowOnDLS, SynapseRowOnSynram>
    , common::CoordinateBase<CorrelationResetRowOnDLS>
{
	CorrelationResetRowOnDLS() = default;

	explicit CorrelationResetRowOnDLS(
	    SynapseRowOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit CorrelationResetRowOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseRowOnSynram toSynapseRowOnSynram() const { return This(); }
};


struct GENPYBIND(inline_base("*")) SynapticInputOnNeuron
    : public common::detail::
          RantWrapper<SynapticInputOnNeuron, uint_fast16_t, 1 /* exc. + inh. */, 0>
{
	constexpr explicit SynapticInputOnNeuron(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static const SYMBOL_VISIBLE SynapticInputOnNeuron excitatory;
	static const SYMBOL_VISIBLE SynapticInputOnNeuron inhibitory;
};

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    SynapseBiasSelectionOnDLS
    : public common::detail::RantWrapper<SynapseBiasSelectionOnDLS, uint_fast16_t, 0, 0>
    , common::CoordinateBase<SynapseBiasSelectionOnDLS>
{
	constexpr explicit SynapseBiasSelectionOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    ColumnCorrelationRowOnDLS
    : public common::detail::RantWrapper<ColumnCorrelationRowOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<ColumnCorrelationRowOnDLS>
{
	constexpr explicit ColumnCorrelationRowOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const SYMBOL_VISIBLE ColumnCorrelationRowOnDLS top;
	static const SYMBOL_VISIBLE ColumnCorrelationRowOnDLS bottom;
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    ColumnCurrentRowOnDLS
    : public common::detail::RantWrapper<ColumnCurrentRowOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<ColumnCurrentRowOnDLS>
{
	constexpr explicit ColumnCurrentRowOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const SYMBOL_VISIBLE ColumnCurrentRowOnDLS top;
	static const SYMBOL_VISIBLE ColumnCurrentRowOnDLS bottom;
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    SynapseWeightMatrixOnDLS
    : public common::detail::RantWrapper<SynapseWeightMatrixOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<SynapseWeightMatrixOnDLS>
{
	constexpr explicit SynapseWeightMatrixOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const SYMBOL_VISIBLE SynapseWeightMatrixOnDLS top;
	static const SYMBOL_VISIBLE SynapseWeightMatrixOnDLS bottom;
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    SynapseLabelMatrixOnDLS
    : public common::detail::RantWrapper<SynapseLabelMatrixOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<SynapseLabelMatrixOnDLS>
{
	constexpr explicit SynapseLabelMatrixOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const SYMBOL_VISIBLE SynapseLabelMatrixOnDLS top;
	static const SYMBOL_VISIBLE SynapseLabelMatrixOnDLS bottom;
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    SynapseCorrelationCalibMatrixOnDLS
    : public common::detail::RantWrapper<SynapseCorrelationCalibMatrixOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<SynapseCorrelationCalibMatrixOnDLS>
{
	constexpr explicit SynapseCorrelationCalibMatrixOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const SYMBOL_VISIBLE SynapseCorrelationCalibMatrixOnDLS top;
	static const SYMBOL_VISIBLE SynapseCorrelationCalibMatrixOnDLS bottom;
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) SynapseBlockOnDLS
    : public common::detail::RantWrapper<SynapseBlockOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<SynapseBlockOnDLS>
{
	constexpr explicit SynapseBlockOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const SYMBOL_VISIBLE SynapseBlockOnDLS top;
	static const SYMBOL_VISIBLE SynapseBlockOnDLS bottom;
};


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

	ColumnCorrelationQuadOnSynram toColumnCorrelationQuadOnSynram() const SYMBOL_VISIBLE;
	ColumnCurrentQuadOnSynram toColumnCurrentQuadOnSynram() const SYMBOL_VISIBLE;
	typedef common::typed_array<NeuronColumnOnDLS, EntryOnQuad> neuron_column_type
	    GENPYBIND(opaque(false));
	neuron_column_type toNeuronColumnOnDLS() const SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*")) SynapseQuadOnSynram
    : public common::detail::
          GridCoordinate<SynapseQuadOnSynram, SynapseQuadColumnOnDLS, SynapseRowOnSynram>
{
	GRID_COMMON_CONSTRUCTORS(SynapseQuadOnSynram)

	SynapseQuadColumnOnDLS toSynapseQuadColumnOnDLS() const
	{
		return x();
	}
	SynapseRowOnSynram toSynapseRowOnSynram() const
	{
		return y();
	}
};

struct GENPYBIND(inline_base("*SynramMixin*"), inline_base("*CoordinateBase*")) SynapseQuadOnDLS
    : public SynramMixin<SynapseQuadOnDLS, SynapseQuadOnSynram>
    , common::CoordinateBase<SynapseQuadOnDLS>
{
	SynapseQuadOnDLS() = default;

	explicit SynapseQuadOnDLS(
	    SynapseQuadOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit SynapseQuadOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseQuadOnSynram toSynapseQuadOnSynram() const
	{
		return This();
	}

	NeuronConfigBlockOnDLS toNeuronConfigBlockOnDLS() const SYMBOL_VISIBLE;
	SynapseWeightQuadOnDLS toSynapseWeightQuadOnDLS() const SYMBOL_VISIBLE;
	SynapseLabelQuadOnDLS toSynapseLabelQuadOnDLS() const SYMBOL_VISIBLE;
	SynapseCorrelationCalibQuadOnDLS toSynapseCorrelationCalibQuadOnDLS() const SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*SynramMixin*"), inline_base("*CoordinateBase*"))
    CorrelationResetOnDLS
    : public SynramMixin<CorrelationResetOnDLS, SynapseQuadOnSynram>
    , common::CoordinateBase<CorrelationResetOnDLS>
{
	CorrelationResetOnDLS() = default;

	explicit CorrelationResetOnDLS(
	    SynapseQuadOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit CorrelationResetOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseQuadOnSynram toSynapseQuadOnSynram() const
	{
		return This();
	}
};

struct GENPYBIND(inline_base("*SynramMixin*"), inline_base("*CoordinateBase*"))
    SynapseWeightQuadOnDLS
    : public SynramMixin<SynapseWeightQuadOnDLS, SynapseQuadOnSynram>
    , common::CoordinateBase<SynapseWeightQuadOnDLS>
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

	NeuronConfigBlockOnDLS toNeuronConfigBlockOnDLS() const SYMBOL_VISIBLE;
	SynapseQuadOnDLS toSynapseQuadOnDLS() const SYMBOL_VISIBLE;
	SynapseLabelQuadOnDLS toSynapseLabelQuadOnDLS() const SYMBOL_VISIBLE;
	SynapseCorrelationCalibQuadOnDLS toSynapseCorrelationCalibQuadOnDLS() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*SynramMixin*"), inline_base("*CoordinateBase*"))
    SynapseLabelQuadOnDLS
    : public SynramMixin<SynapseLabelQuadOnDLS, SynapseQuadOnSynram>
    , common::CoordinateBase<SynapseLabelQuadOnDLS>
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

	NeuronConfigBlockOnDLS toNeuronConfigBlockOnDLS() const SYMBOL_VISIBLE;
	SynapseWeightQuadOnDLS toSynapseWeightQuadOnDLS() const SYMBOL_VISIBLE;
	SynapseQuadOnDLS toSynapseQuadOnDLS() const SYMBOL_VISIBLE;
	SynapseCorrelationCalibQuadOnDLS toSynapseCorrelationCalibQuadOnDLS() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*SynramMixin*"), inline_base("*CoordinateBase*"))
    SynapseCorrelationCalibQuadOnDLS
    : public SynramMixin<SynapseCorrelationCalibQuadOnDLS, SynapseQuadOnSynram>
    , common::CoordinateBase<SynapseCorrelationCalibQuadOnDLS>
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

	NeuronConfigBlockOnDLS toNeuronConfigBlockOnDLS() const SYMBOL_VISIBLE;
	SynapseWeightQuadOnDLS toSynapseWeightQuadOnDLS() const SYMBOL_VISIBLE;
	SynapseLabelQuadOnDLS toSynapseLabelQuadOnDLS() const SYMBOL_VISIBLE;
	SynapseQuadOnDLS toSynapseQuadOnDLS() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*")) SynapseOnSynapseRow
    : public common::detail::RantWrapper<SynapseOnSynapseRow, uint_fast16_t, 255, 0>
    , public common::detail::XRangedTrait
{
	constexpr explicit SynapseOnSynapseRow(uintmax_t const value = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(value)
	{}

	explicit SynapseOnSynapseRow(EntryOnQuad const& syn_on_quad, SynapseQuadColumnOnDLS const& quad)
	    SYMBOL_VISIBLE;

	EntryOnQuad toEntryOnQuad() const SYMBOL_VISIBLE;
	SynapseQuadColumnOnDLS toSynapseQuadColumnOnDLS() const SYMBOL_VISIBLE;
	NeuronColumnOnDLS toNeuronColumnOnDLS() const SYMBOL_VISIBLE;
	CADCChannelColumnOnSynram toCADCChannelColumnOnSynram() const SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*")) SynapseOnSynram
    : public common::detail::
          GridCoordinate<SynapseOnSynram, SynapseOnSynapseRow, SynapseRowOnSynram>
{
	GRID_COMMON_CONSTRUCTORS(SynapseOnSynram)

	SynapseOnSynapseRow toSynapseOnSynapseRow() const
	{
		return x();
	}

	SynapseRowOnSynram toSynapseRowOnSynram() const
	{
		return y();
	}
};

struct GENPYBIND(inline_base("*SynramMixin*")) SynapseOnDLS
    : public SynramMixin<SynapseOnDLS, SynapseOnSynram>
{
	SynapseOnDLS() = default;

	explicit SynapseOnDLS(
	    SynapseOnSynram const& synapse, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(synapse, synram)
	{}

	explicit SynapseOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseOnSynram toSynapseOnSynram() const
	{
		return This();
	}
};

/**
 * Value type of a single synapse label configuration.
 */
struct GENPYBIND(inline_base("*")) SynapseLabel
    : public halco::common::detail::RantWrapper<SynapseLabel, uint8_t, 63, 0>
{
	constexpr explicit SynapseLabel(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

} // namespace vx
} // namespace halco::hicann_dls

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseRowOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseRowOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseWeightRowOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseLabelRowOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseCorrelationCalibRowOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapticInputOnNeuron)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseBiasSelectionOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CorrelationResetRowOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ColumnCorrelationRowOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::ColumnCurrentRowOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseWeightMatrixOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseLabelMatrixOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseCorrelationCalibMatrixOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseQuadColumnOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseOnSynapseRow)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseWeightQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseLabelQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseCorrelationCalibQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CorrelationResetOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseLabel)

} // namespace std
