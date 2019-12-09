#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct CapMemColumnOnCapMemBlock;
struct CapMemBlockOnDLS;
struct NeuronResetBlockOnDLS;
struct NeuronResetOnDLS;
struct NeuronSpikeCounterReadBlockOnDLS;
struct NeuronSpikeCounterReadOnDLS;
struct NeuronSpikeCounterResetBlockOnDLS;
struct NeuronSpikeCounterResetOnDLS;
struct NeuronConfigOnDLS;
struct NeuronBackendConfigOnDLS;
struct SynapseOnSynapseRow;

/**********\
   Neuron
\**********/

/**
 * Horizontal neuron location on the two dimensional neuron grid.
 */
struct GENPYBIND(inline_base("*")) NeuronColumnOnDLS
    : public common::detail::RantWrapper<NeuronColumnOnDLS, uint_fast16_t, 255, 0>
    , public common::detail::XRangedTrait
{
	constexpr explicit NeuronColumnOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	SynapseOnSynapseRow toSynapseOnSynapseRow() const;
	CapMemColumnOnCapMemBlock toCapMemColumnOnCapMemBlock() const;
};


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
};


/**
 * DLS-global neuron location on the two dimensional neuron grid.
 */
struct GENPYBIND(inline_base("*")) NeuronOnDLS
    : public common::detail::GridCoordinate<NeuronOnDLS, NeuronColumnOnDLS, NeuronRowOnDLS>
{
	GRID_COMMON_CONSTRUCTORS(NeuronOnDLS)

	NeuronColumnOnDLS toNeuronColumnOnDLS() const { return x(); }
	NeuronRowOnDLS toNeuronRowOnDLS() const { return y(); }

	NeuronResetOnDLS toNeuronResetOnDLS() const;
	NeuronSpikeCounterReadOnDLS toNeuronSpikeCounterReadOnDLS() const;
	NeuronSpikeCounterResetOnDLS toNeuronSpikeCounterResetOnDLS() const;
	NeuronConfigOnDLS toNeuronConfigOnDLS() const;
	NeuronBackendConfigOnDLS toNeuronBackendConfigOnDLS() const;

	CapMemBlockOnDLS toCapMemBlockOnDLS() const;
	CapMemColumnOnCapMemBlock toCapMemColumnOnCapMemBlock() const;
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
	NeuronSpikeCounterReadBlockOnDLS toNeuronSpikeCounterReadBlockOnDLS() const;
	NeuronSpikeCounterResetBlockOnDLS toNeuronSpikeCounterResetBlockOnDLS() const;
};


HALCO_COORDINATE_MIXIN(NeuronConfigMixin, NeuronConfigBlockOnDLS, neuron)

struct GENPYBIND(inline_base("*NeuronConfigMixin*")) NeuronConfigOnDLS
    : public NeuronConfigMixin<NeuronConfigOnDLS, NeuronConfigOnNeuronConfigBlock>
{
	NeuronConfigOnDLS() = default;

	explicit NeuronConfigOnDLS(
	    NeuronConfigOnNeuronConfigBlock const& neuron,
	    NeuronConfigBlockOnDLS const& block = NeuronConfigBlockOnDLS()) :
	    mixin_t(neuron, block)
	{}

	explicit NeuronConfigOnDLS(enum_type const& e) : mixin_t(e) {}

	NeuronConfigOnNeuronConfigBlock toNeuronConfigOnNeuronConfigBlock() const { return This(); }
	NeuronResetOnDLS toNeuronResetOnDLS() const;
	NeuronSpikeCounterReadOnDLS toNeuronSpikeCounterReadOnDLS() const;
	NeuronSpikeCounterResetOnDLS toNeuronSpikeCounterResetOnDLS() const;
};


struct GENPYBIND(inline_base("*")) CommonNeuronConfigOnDLS
    : public common::detail::RantWrapper<CommonNeuronConfigOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit CommonNeuronConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*")) NeuronBackendConfigOnNeuronBackendConfigBlock
    : public common::detail::
          RantWrapper<NeuronBackendConfigOnNeuronBackendConfigBlock, uint_fast16_t, 255, 0>
{
	constexpr explicit NeuronBackendConfigOnNeuronBackendConfigBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) NeuronBackendConfigBlockOnDLS
    : public common::detail::RantWrapper<NeuronBackendConfigBlockOnDLS, uint_fast8_t, 1, 0>
{
	constexpr explicit NeuronBackendConfigBlockOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
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


struct GENPYBIND(inline_base("*")) NeuronSpikeCounterReadOnNeuronSpikeCounterReadBlock
    : public common::detail::
          RantWrapper<NeuronSpikeCounterReadOnNeuronSpikeCounterReadBlock, uint_fast16_t, 255, 0>
{
	constexpr explicit NeuronSpikeCounterReadOnNeuronSpikeCounterReadBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) NeuronSpikeCounterReadBlockOnDLS
    : public common::detail::RantWrapper<NeuronSpikeCounterReadBlockOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit NeuronSpikeCounterReadBlockOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) NeuronSpikeCounterResetOnNeuronSpikeCounterResetBlock
    : public common::detail::
          RantWrapper<NeuronSpikeCounterResetOnNeuronSpikeCounterResetBlock, uint_fast16_t, 255, 0>
{
	constexpr explicit NeuronSpikeCounterResetOnNeuronSpikeCounterResetBlock(
	    uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*")) NeuronSpikeCounterResetBlockOnDLS
    : public common::detail::RantWrapper<NeuronSpikeCounterResetBlockOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit NeuronSpikeCounterResetBlockOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


HALCO_COORDINATE_MIXIN(NeuronBackendConfigMixin, NeuronBackendConfigBlockOnDLS, neuron_backend)

struct GENPYBIND(inline_base("*NeuronBackendConfigMixin*")) NeuronBackendConfigOnDLS
    : public NeuronBackendConfigMixin<
          NeuronBackendConfigOnDLS,
          NeuronBackendConfigOnNeuronBackendConfigBlock>
{
	NeuronBackendConfigOnDLS() = default;

	explicit NeuronBackendConfigOnDLS(
	    NeuronBackendConfigOnNeuronBackendConfigBlock const& neuron,
	    NeuronBackendConfigBlockOnDLS const& block = NeuronBackendConfigBlockOnDLS()) :
	    mixin_t(neuron, block)
	{}

	explicit NeuronBackendConfigOnDLS(enum_type const& e) : mixin_t(e) {}

	NeuronBackendConfigOnNeuronBackendConfigBlock toNeuronBackendConfigOnNeuronBackendConfigBlock()
	    const
	{
		return This();
	}
};


struct GENPYBIND(inline_base("*")) EventOutputOnNeuronBackendBlock
    : public common::detail::RantWrapper<EventOutputOnNeuronBackendBlock, uint_fast16_t, 3, 0>
{
	constexpr explicit EventOutputOnNeuronBackendBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
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


HALCO_COORDINATE_MIXIN(NeuronSpikeCounterReadMixin, NeuronSpikeCounterReadBlockOnDLS, neuron)

struct GENPYBIND(inline_base("*NeuronSpikeCounterReadMixin*")) NeuronSpikeCounterReadOnDLS
    : public NeuronSpikeCounterReadMixin<
          NeuronSpikeCounterReadOnDLS,
          NeuronSpikeCounterReadOnNeuronSpikeCounterReadBlock>
{
	NeuronSpikeCounterReadOnDLS() = default;

	explicit NeuronSpikeCounterReadOnDLS(
	    NeuronSpikeCounterReadOnNeuronSpikeCounterReadBlock const& neuron,
	    NeuronSpikeCounterReadBlockOnDLS const& block = NeuronSpikeCounterReadBlockOnDLS()) :
	    mixin_t(neuron, block)
	{}

	explicit NeuronSpikeCounterReadOnDLS(enum_type const& e) : mixin_t(e) {}

	NeuronSpikeCounterReadOnNeuronSpikeCounterReadBlock
	toNeuronSpikeCounterReadOnNeuronSpikeCounterReadBlock() const
	{
		return This();
	}
};


HALCO_COORDINATE_MIXIN(NeuronSpikeCounterResetMixin, NeuronSpikeCounterResetBlockOnDLS, neuron)

struct GENPYBIND(inline_base("*NeuronSpikeCounterResetMixin*")) NeuronSpikeCounterResetOnDLS
    : public NeuronSpikeCounterResetMixin<
          NeuronSpikeCounterResetOnDLS,
          NeuronSpikeCounterResetOnNeuronSpikeCounterResetBlock>
{
	NeuronSpikeCounterResetOnDLS() = default;

	explicit NeuronSpikeCounterResetOnDLS(
	    NeuronSpikeCounterResetOnNeuronSpikeCounterResetBlock const& neuron,
	    NeuronSpikeCounterResetBlockOnDLS const& block = NeuronSpikeCounterResetBlockOnDLS()) :
	    mixin_t(neuron, block)
	{}

	explicit NeuronSpikeCounterResetOnDLS(enum_type const& e) : mixin_t(e) {}

	NeuronSpikeCounterResetOnNeuronSpikeCounterResetBlock
	toNeuronSpikeCounterResetOnNeuronSpikeCounterResetBlock() const
	{
		return This();
	}
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronColumnOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronRowOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronConfigOnNeuronConfigBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronConfigBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonNeuronConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronBackendConfigOnNeuronBackendConfigBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronBackendConfigBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronBackendConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::EventOutputOnNeuronBackendBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronResetOnNeuronResetBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronResetBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronResetOnDLS)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann_dls::vx::NeuronSpikeCounterReadOnNeuronSpikeCounterReadBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronSpikeCounterReadBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronSpikeCounterReadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann_dls::vx::NeuronSpikeCounterResetOnNeuronSpikeCounterResetBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronSpikeCounterResetBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::NeuronSpikeCounterResetOnDLS)

} // namespace std
