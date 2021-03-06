#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"
#include "halco/common/typed_array.h"

#include "halco/hicann-dls/vx/synapse.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

#include "halco/hicann-dls/vx/hemisphere_fwd.h"
struct CapMemColumnOnCapMemBlock;
struct CapMemBlockOnDLS;
struct NeuronResetBlockOnDLS;
struct NeuronResetOnDLS;
struct SpikeCounterReadBlockOnDLS;
struct SpikeCounterReadOnDLS;
struct SpikeCounterResetBlockOnDLS;
struct SpikeCounterResetOnDLS;
struct NeuronEventOutputOnNeuronBackendBlock;
struct NeuronEventOutputOnDLS;
struct CrossbarInputOnDLS;
struct NeuronBackendConfigBlockOnDLS;
struct BlockPostPulseOnDLS;
struct ColumnCorrelationQuadOnDLS;
struct ColumnCurrentQuadOnDLS;

/**********\
   Neuron
\**********/

/**
 * Vertical neuron location on the two dimensional neuron grid.
 */
struct GENPYBIND(inline_base("*")) NeuronRowOnDLS
    : public common::detail::RantWrapper<NeuronRowOnDLS, uint_fast16_t, 1, 0>
    , public common::detail::YRangedTrait
{
	constexpr explicit NeuronRowOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const NeuronRowOnDLS top;
	static const NeuronRowOnDLS bottom;
};


struct GENPYBIND(inline_base("*")) NeuronConfigOnNeuronConfigBlock
    : public common::detail::RantWrapper<NeuronConfigOnNeuronConfigBlock, uint_fast16_t, 127, 0>
{
	constexpr explicit NeuronConfigOnNeuronConfigBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CapMemColumnOnCapMemBlock toCapMemColumnOnCapMemBlock() const;
};


struct GENPYBIND(inline_base("*")) NeuronConfigBlockOnDLS
    : public common::detail::RantWrapper<NeuronConfigBlockOnDLS, uint_fast16_t, 3, 0>
{
	constexpr explicit NeuronConfigBlockOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	CapMemBlockOnDLS toCapMemBlockOnDLS() const;
	NeuronResetBlockOnDLS toNeuronResetBlockOnDLS() const;
	SpikeCounterReadBlockOnDLS toSpikeCounterReadBlockOnDLS() const;
	SpikeCounterResetBlockOnDLS toSpikeCounterResetBlockOnDLS() const;
};


struct GENPYBIND(inline_base("*")) NeuronBackendConfigOnNeuronBackendConfigBlock
    : public common::detail::
          RantWrapper<NeuronBackendConfigOnNeuronBackendConfigBlock, uint_fast16_t, 255, 0>
{
	constexpr explicit NeuronBackendConfigOnNeuronBackendConfigBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	NeuronEventOutputOnNeuronBackendBlock toNeuronEventOutputOnNeuronBackendBlock() const;
};

struct GENPYBIND(inline_base("*")) CommonNeuronBackendConfigOnDLS
    : public common::detail::RantWrapper<CommonNeuronBackendConfigOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit CommonNeuronBackendConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	NeuronBackendConfigBlockOnDLS toNeuronBackendConfigBlockOnDLS() const;
};

struct GENPYBIND(inline_base("*")) NeuronBackendConfigBlockOnDLS
    : public common::detail::RantWrapper<NeuronBackendConfigBlockOnDLS, uint_fast8_t, 1, 0>
{
	constexpr explicit NeuronBackendConfigBlockOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	BlockPostPulseOnDLS toBlockPostPulseOnDLS() const;
	CommonNeuronBackendConfigOnDLS toCommonNeuronBackendConfigOnDLS() const;
};


struct GENPYBIND(inline_base("*")) NeuronResetOnNeuronResetBlock
    : public common::detail::RantWrapper<NeuronResetOnNeuronResetBlock, uint_fast16_t, 255, 0>
{
	constexpr explicit NeuronResetOnNeuronResetBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) NeuronResetBlockOnDLS
    : public common::detail::RantWrapper<NeuronResetBlockOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit NeuronResetBlockOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) BlockPostPulseOnDLS
    : public common::detail::RantWrapper<BlockPostPulseOnDLS, uint_fast8_t, 1, 0>
{
	constexpr explicit BlockPostPulseOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	NeuronBackendConfigBlockOnDLS toNeuronBackendConfigBlockOnDLS() const;
};


struct GENPYBIND(inline_base("*")) SpikeCounterReadOnSpikeCounterReadBlock
    : public common::detail::
          RantWrapper<SpikeCounterReadOnSpikeCounterReadBlock, uint_fast16_t, 255, 0>
{
	constexpr explicit SpikeCounterReadOnSpikeCounterReadBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) SpikeCounterReadBlockOnDLS
    : public common::detail::RantWrapper<SpikeCounterReadBlockOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit SpikeCounterReadBlockOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) SpikeCounterResetOnSpikeCounterResetBlock
    : public common::detail::
          RantWrapper<SpikeCounterResetOnSpikeCounterResetBlock, uint_fast16_t, 255, 0>
{
	constexpr explicit SpikeCounterResetOnSpikeCounterResetBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) SpikeCounterResetBlockOnDLS
    : public common::detail::RantWrapper<SpikeCounterResetBlockOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit SpikeCounterResetBlockOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) NeuronEventOutputOnNeuronBackendBlock
    : public common::detail::RantWrapper<NeuronEventOutputOnNeuronBackendBlock, uint_fast16_t, 3, 0>
{
	constexpr explicit NeuronEventOutputOnNeuronBackendBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

HALCO_COORDINATE_MIXIN(NeuronBackendConfigMixin, NeuronBackendConfigBlockOnDLS, neuron_backend)

struct GENPYBIND(inline_base("*NeuronBackendConfigMixin*")) NeuronEventOutputOnDLS
    : public NeuronBackendConfigMixin<NeuronEventOutputOnDLS, NeuronEventOutputOnNeuronBackendBlock>
{
	NeuronEventOutputOnDLS() = default;

	explicit NeuronEventOutputOnDLS(
	    NeuronEventOutputOnNeuronBackendBlock const& output,
	    NeuronBackendConfigBlockOnDLS const& block = NeuronBackendConfigBlockOnDLS()) :
	    mixin_t(output, block)
	{}

	explicit NeuronEventOutputOnDLS(enum_type const& e) : mixin_t(e) {}

	NeuronEventOutputOnNeuronBackendBlock toNeuronEventOutputOnNeuronBackendBlock() const
	{
		return This();
	}

	CrossbarInputOnDLS toCrossbarInputOnDLS() const;
};

HALCO_COORDINATE_MIXIN(NeuronResetMixin, NeuronResetBlockOnDLS, neuron)

struct GENPYBIND(inline_base("*NeuronResetMixin*")) NeuronResetOnDLS
    : public NeuronResetMixin<NeuronResetOnDLS, NeuronResetOnNeuronResetBlock>
{
	NeuronResetOnDLS() = default;

	explicit NeuronResetOnDLS(
	    NeuronResetOnNeuronResetBlock const& neuron,
	    NeuronResetBlockOnDLS const& block = NeuronResetBlockOnDLS()) :
	    mixin_t(neuron, block)
	{}

	explicit NeuronResetOnDLS(enum_type const& e) : mixin_t(e) {}

	NeuronResetOnNeuronResetBlock toNeuronResetOnNeuronResetBlock() const { return This(); }
};


HALCO_COORDINATE_MIXIN(SpikeCounterReadMixin, SpikeCounterReadBlockOnDLS, neuron)

struct GENPYBIND(inline_base("*SpikeCounterReadMixin*")) SpikeCounterReadOnDLS
    : public SpikeCounterReadMixin<SpikeCounterReadOnDLS, SpikeCounterReadOnSpikeCounterReadBlock>
{
	SpikeCounterReadOnDLS() = default;

	explicit SpikeCounterReadOnDLS(
	    SpikeCounterReadOnSpikeCounterReadBlock const& neuron,
	    SpikeCounterReadBlockOnDLS const& block = SpikeCounterReadBlockOnDLS()) :
	    mixin_t(neuron, block)
	{}

	explicit SpikeCounterReadOnDLS(enum_type const& e) : mixin_t(e) {}

	SpikeCounterReadOnSpikeCounterReadBlock toSpikeCounterReadOnSpikeCounterReadBlock() const
	{
		return This();
	}
};


HALCO_COORDINATE_MIXIN(SpikeCounterResetMixin, SpikeCounterResetBlockOnDLS, neuron)

struct GENPYBIND(inline_base("*SpikeCounterResetMixin*")) SpikeCounterResetOnDLS
    : public SpikeCounterResetMixin<
          SpikeCounterResetOnDLS,
          SpikeCounterResetOnSpikeCounterResetBlock>
{
	SpikeCounterResetOnDLS() = default;

	explicit SpikeCounterResetOnDLS(
	    SpikeCounterResetOnSpikeCounterResetBlock const& neuron,
	    SpikeCounterResetBlockOnDLS const& block = SpikeCounterResetBlockOnDLS()) :
	    mixin_t(neuron, block)
	{}

	explicit SpikeCounterResetOnDLS(enum_type const& e) : mixin_t(e) {}

	SpikeCounterResetOnSpikeCounterResetBlock toSpikeCounterResetOnSpikeCounterResetBlock() const
	{
		return This();
	}
};


struct GENPYBIND(inline_base("*")) NeuronSRAMTimingConfigOnDLS
    : public common::detail::RantWrapper<NeuronSRAMTimingConfigOnDLS, uint_fast16_t, 3, 0>
{
	constexpr explicit NeuronSRAMTimingConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) NeuronBackendSRAMTimingConfigOnDLS
    : public common::detail::RantWrapper<NeuronBackendSRAMTimingConfigOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit NeuronBackendSRAMTimingConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronRowOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronConfigOnNeuronConfigBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronConfigBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonNeuronBackendConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronBackendConfigOnNeuronBackendConfigBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronBackendConfigBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronEventOutputOnNeuronBackendBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronEventOutputOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronResetOnNeuronResetBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronResetBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronResetOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::BlockPostPulseOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikeCounterReadOnSpikeCounterReadBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikeCounterReadBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikeCounterReadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikeCounterResetOnSpikeCounterResetBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikeCounterResetBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SpikeCounterResetOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronSRAMTimingConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronBackendSRAMTimingConfigOnDLS)

} // namespace std
