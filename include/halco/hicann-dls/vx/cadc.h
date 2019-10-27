#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"

#include "halco/hicann-dls/vx/synapse.h"
#include "halco/hicann-dls/vx/synram.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

/**********\
    CADC
\**********/

struct GENPYBIND(inline_base("*")) CADCConfigOnDLS
    : public common::detail::RantWrapper<CADCConfigOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit CADCConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}

	PPUOnDLS toPPUOnDLS() const;

	static const CADCConfigOnDLS top;
	static const CADCConfigOnDLS bottom;
};


struct GENPYBIND(inline_base("*")) CADCChannelType
    : public common::detail::RantWrapper<CADCChannelType, uint_fast16_t, 1, 0>
{
	constexpr explicit CADCChannelType(uintmax_t const val = 0) : rant_t(val) {}

	static const CADCChannelType causal;
	static const CADCChannelType acausal;
};


struct GENPYBIND(inline_base("*")) CADCReadoutType
    : public common::detail::RantWrapper<CADCReadoutType, uint_fast16_t, 1, 0>
{
	constexpr explicit CADCReadoutType(uintmax_t const val = 0) : rant_t(val) {}

	static const CADCReadoutType trigger_read;
	static const CADCReadoutType buffered;
};


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

	SynapseQuadOnSynram toSynapseQuadOnSynram() const { return This(); }
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


struct GENPYBIND(inline_base("*SynramMixin*")) CADCSampleQuadOnDLS
    : public SynramMixin<CADCSampleQuadOnDLS, CADCSampleQuadOnSynram>
{
	CADCSampleQuadOnDLS() = default;

	explicit CADCSampleQuadOnDLS(CADCSampleQuadOnSynram const& block, SynramOnDLS const& synram) :
	    mixin_t(block, synram)
	{}

	explicit CADCSampleQuadOnDLS(enum_type const& e) : mixin_t(e) {}

	CADCSampleQuadOnSynram toCADCSampleQuadOnSynram() const { return This(); }
};


struct GENPYBIND(inline_base("*")) CADCChannelColumnOnSynram
    : public common::detail::RantWrapper<CADCChannelColumnOnSynram, uint_fast16_t, 255, 0>
{
	constexpr explicit CADCChannelColumnOnSynram(uintmax_t const val = 0) : rant_t(val) {}
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

	CADCChannelColumnOnSynram toCADCChannelColumnOnSynram() const { return This(); }
	SynapseOnSynapseRow toSynapseOnSynapseRow() const
	{
		return SynapseOnSynapseRow(int(toCADCChannelColumnOnSynram().toEnum()));
	}
};


struct GENPYBIND(inline_base("*SynramMixin*")) CADCChannelConfigOnDLS
    : public SynramMixin<CADCChannelConfigOnDLS, CADCChannelConfigOnSynram>
{
	CADCChannelConfigOnDLS() = default;

	explicit CADCChannelConfigOnDLS(
	    CADCChannelConfigOnSynram const& block, SynramOnDLS const& synram = SynramOnDLS()) :
	    mixin_t(block, synram)
	{}

	explicit CADCChannelConfigOnDLS(enum_type const& e) : mixin_t(e) {}

	CADCChannelConfigOnSynram toCADCChannelConfigOnSynram() const { return This(); }
};


struct GENPYBIND(inline_base("*SynramMixin*")) CADCSampleRowOnDLS
    : public SynramMixin<CADCSampleRowOnDLS, SynapseRowOnSynram>
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
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCChannelType)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCReadoutType)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCSampleQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCSampleQuadUnspecifiedReadoutOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCSampleQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCChannelColumnOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCChannelConfigOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCChannelConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCSampleRowOnDLS)

} // namespace std
