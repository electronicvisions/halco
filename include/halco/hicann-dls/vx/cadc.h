#pragma once
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"

#include "halco/hicann-dls/vx/synapse.h"
#include "halco/hicann-dls/vx/synram.h"

#include "hate/visibility.h"

namespace halco::hicann_dls { namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct SynapseRowOnDLS;
struct SynapseWeightRowOnDLS;
struct SynapseLabelRowOnDLS;
struct SynapseCorrelationCalibRowOnDLS;

#include "halco/hicann-dls/vx/hemisphere_fwd.h"

/**********\
    CADC
\**********/

struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) CADCOnDLS
    : public common::detail::RantWrapper<CADCOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<CADCOnDLS>
{
	constexpr explicit CADCOnDLS(uintmax_t const val = 0) : rant_t(val) {}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const SYMBOL_VISIBLE CADCOnDLS top;
	static const SYMBOL_VISIBLE CADCOnDLS bottom;
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) CADCConfigOnDLS
    : public common::detail::RantWrapper<CADCConfigOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<CADCConfigOnDLS>
{
	constexpr explicit CADCConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const SYMBOL_VISIBLE CADCConfigOnDLS top;
	static const SYMBOL_VISIBLE CADCConfigOnDLS bottom;
};


struct GENPYBIND(inline_base("*")) CADCChannelType
    : public common::detail::RantWrapper<CADCChannelType, uint_fast16_t, 1, 0>
{
	constexpr explicit CADCChannelType(uintmax_t const val = 0) : rant_t(val) {}

	static const SYMBOL_VISIBLE CADCChannelType causal;
	static const SYMBOL_VISIBLE CADCChannelType acausal;
};


struct GENPYBIND(inline_base("*")) CADCReadoutType
    : public common::detail::RantWrapper<CADCReadoutType, uint_fast16_t, 1, 0>
{
	constexpr explicit CADCReadoutType(uintmax_t const val = 0) : rant_t(val) {}

	static const SYMBOL_VISIBLE CADCReadoutType trigger_read;
	static const SYMBOL_VISIBLE CADCReadoutType buffered;
};


struct GENPYBIND(inline_base("*")) CADCChannelColumnOnSynram
    : public common::detail::RantWrapper<CADCChannelColumnOnSynram, uint_fast16_t, 255, 0>
{
	constexpr explicit CADCChannelColumnOnSynram(uintmax_t const val = 0) : rant_t(val) {}
};


struct GENPYBIND(inline_base("*SynramMixin*"), inline_base("*CoordinateBase*")) CADCSampleRowOnDLS
    : public SynramMixin<CADCSampleRowOnDLS, SynapseRowOnSynram>
    , common::CoordinateBase<CADCSampleRowOnDLS>
{
private:
	typedef SynramMixin<CADCSampleRowOnDLS, SynapseRowOnSynram> base;

public:
	CADCSampleRowOnDLS() = default;

	explicit CADCSampleRowOnDLS(
	    SynapseRowOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    base(block, synram)
	{}

	explicit CADCSampleRowOnDLS(enum_type const& e) : base(e) {}

	SynapseRowOnSynram toSynapseRowOnSynram() const { return This(); }
	SynramOnDLS toSynramOnDLS() const { return split().first; }

	SynapseRowOnDLS toSynapseRowOnDLS() const SYMBOL_VISIBLE;
	SynapseWeightRowOnDLS toSynapseWeightRowOnDLS() const SYMBOL_VISIBLE;
	SynapseLabelRowOnDLS toSynapseLabelRowOnDLS() const SYMBOL_VISIBLE;
	SynapseCorrelationCalibRowOnDLS toSynapseCorrelationCalibRowOnDLS() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    CADCOffsetSRAMTimingConfigOnDLS
    : public common::detail::RantWrapper<CADCOffsetSRAMTimingConfigOnDLS, uint_fast16_t, 3, 0>
    , common::CoordinateBase<CADCOffsetSRAMTimingConfigOnDLS>
{
	constexpr explicit CADCOffsetSRAMTimingConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*")) CADCSamplesOnDLS
    : public common::detail::RantWrapper<CADCSamplesOnDLS, uint_fast16_t, 0, 0>
    , common::CoordinateBase<CADCSamplesOnDLS>
{
	constexpr explicit CADCSamplesOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};


struct SynapseQuadOnDLS;
struct SynapseWeightQuadOnDLS;
struct SynapseLabelQuadOnDLS;
struct SynapseCorrelationCalibQuadOnDLS;


HALCO_COORDINATE_MIXIN(CADCChannelTypeMixin, CADCChannelType, cadc_channel_type)

struct GENPYBIND(inline_base("*CADCChannelTypeMixin*")) CADCSampleQuadUnspecifiedReadoutOnSynram
    : public CADCChannelTypeMixin<CADCSampleQuadUnspecifiedReadoutOnSynram, SynapseQuadOnSynram>
{
	CADCSampleQuadUnspecifiedReadoutOnSynram() = default;

	explicit CADCSampleQuadUnspecifiedReadoutOnSynram(
	    SynapseQuadOnSynram const& quad, CADCChannelType const& cadc_channel_type) :
	    mixin_t(quad, cadc_channel_type)
	{}

	explicit CADCSampleQuadUnspecifiedReadoutOnSynram(enum_type const& e) : mixin_t(e) {}

	SynapseQuadOnSynram toSynapseQuadOnSynram() const
	{
		return This();
	}
};


HALCO_COORDINATE_MIXIN(CADCReadoutTypeMixin, CADCReadoutType, cadc_readout_type)

struct GENPYBIND(inline_base("*CADCReadoutTypeMixin*")) CADCSampleQuadOnSynram
    : public CADCReadoutTypeMixin<CADCSampleQuadOnSynram, CADCSampleQuadUnspecifiedReadoutOnSynram>
{
	CADCSampleQuadOnSynram() = default;

	explicit CADCSampleQuadOnSynram(
	    SynapseQuadOnSynram const& quad,
	    CADCChannelType const& cadc_channel_type,
	    CADCReadoutType const& cadc_readout_type = CADCReadoutType()) :
	    mixin_t(
	        CADCSampleQuadUnspecifiedReadoutOnSynram(quad, cadc_channel_type), cadc_readout_type)
	{}

	explicit CADCSampleQuadOnSynram(enum_type const& e) : mixin_t(e) {}

	CADCSampleQuadUnspecifiedReadoutOnSynram toCADCSampleQuadUnspecifiedReadoutOnSynram() const
	{
		return This();
	}
};

struct GENPYBIND(inline_base("*SynramMixin*"), inline_base("*CoordinateBase*")) CADCSampleQuadOnDLS
    : public SynramMixin<CADCSampleQuadOnDLS, CADCSampleQuadOnSynram>
    , common::CoordinateBase<CADCSampleQuadOnDLS>
{
	CADCSampleQuadOnDLS() = default;

	explicit CADCSampleQuadOnDLS(CADCSampleQuadOnSynram const& block, SynramOnDLS const& synram) :
	    mixin_t(block, synram)
	{}

	explicit CADCSampleQuadOnDLS(enum_type const& e) : mixin_t(e) {}

	CADCSampleQuadOnSynram toCADCSampleQuadOnSynram() const
	{
		return This();
	}

	SynapseQuadOnDLS toSynapseQuadOnDLS() const SYMBOL_VISIBLE;
	SynapseWeightQuadOnDLS toSynapseWeightQuadOnDLS() const SYMBOL_VISIBLE;
	SynapseLabelQuadOnDLS toSynapseLabelQuadOnDLS() const SYMBOL_VISIBLE;
	SynapseCorrelationCalibQuadOnDLS toSynapseCorrelationCalibQuadOnDLS() const SYMBOL_VISIBLE;
};

struct GENPYBIND(inline_base("*CADCChannelTypeMixin*")) CADCChannelConfigOnSynram
    : public CADCChannelTypeMixin<CADCChannelConfigOnSynram, CADCChannelColumnOnSynram>
{
	CADCChannelConfigOnSynram() = default;

	explicit CADCChannelConfigOnSynram(
	    CADCChannelColumnOnSynram const& quad, CADCChannelType const& cadc_channel_type) :
	    mixin_t(quad, cadc_channel_type)
	{}

	explicit CADCChannelConfigOnSynram(enum_type const& e) : mixin_t(e) {}

	CADCChannelColumnOnSynram toCADCChannelColumnOnSynram() const
	{
		return This();
	}
	SynapseOnSynapseRow toSynapseOnSynapseRow() const
	{
		return SynapseOnSynapseRow(int(toCADCChannelColumnOnSynram().toEnum()));
	}
};


struct GENPYBIND(inline_base("*SynramMixin*"), inline_base("*CoordinateBase*"))
    CADCChannelConfigOnDLS
    : public SynramMixin<CADCChannelConfigOnDLS, CADCChannelConfigOnSynram>
    , common::CoordinateBase<CADCChannelConfigOnDLS>
{
	CADCChannelConfigOnDLS() = default;

	explicit CADCChannelConfigOnDLS(
	    CADCChannelConfigOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit CADCChannelConfigOnDLS(enum_type const& e) : mixin_t(e) {}

	CADCChannelConfigOnSynram toCADCChannelConfigOnSynram() const
	{
		return This();
	}
	NeuronConfigBlockOnDLS toNeuronConfigBlockOnDLS() const SYMBOL_VISIBLE;
};

} // namespace vx
} // namespace halco::hicann_dls

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCChannelType)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCReadoutType)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCChannelColumnOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCSampleRowOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCOffsetSRAMTimingConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCSamplesOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCSampleQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCChannelConfigOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCChannelConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCSampleQuadUnspecifiedReadoutOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCSampleQuadOnSynram)

} // namespace std
