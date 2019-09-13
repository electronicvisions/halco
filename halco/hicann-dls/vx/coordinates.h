#pragma once

extern "C"
{
#include <stdint.h>
}

#include "halco/common/common.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.th"
#include "halco/common/mixin.h"

#include "halco/hicann-dls/vx/background.h"
#include "halco/hicann-dls/vx/capmem.h"
#include "halco/hicann-dls/vx/dac.h"
#include "halco/hicann-dls/vx/event.h"
#include "halco/hicann-dls/vx/fpga.h"
#include "halco/hicann-dls/vx/highspeed_link.h"
#include "halco/hicann-dls/vx/i2c.h"
#include "halco/hicann-dls/vx/jtag.h"
#include "halco/hicann-dls/vx/neuron.h"
#include "halco/hicann-dls/vx/omnibus.h"
#include "halco/hicann-dls/vx/pll.h"
#include "halco/hicann-dls/vx/ppu.h"
#include "halco/hicann-dls/vx/reset.h"
#include "halco/hicann-dls/vx/routing_crossbar.h"
#include "halco/hicann-dls/vx/spi.h"
#include "halco/hicann-dls/vx/switch_rows.h"
#include "halco/hicann-dls/vx/synapse.h"
#include "halco/hicann-dls/vx/synapse_driver.h"
#include "halco/hicann-dls/vx/synram.h"
#include "halco/hicann-dls/vx/timing.h"
#include "halco/hicann-dls/vx/xboard.h"

GENPYBIND_TAG_HALCO_HICANN_DLS_VX
GENPYBIND_MANUAL({
	parent.attr("__variant__") = "pybind11";
	parent->py::module::import("pyhalco_common");
})

namespace halco {
namespace hicann_dls {
namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct CrossbarInputOnDLS;
struct CrossbarL2OutputOnDLS;

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

/*****************\
   PADIBus
\*****************/

struct PADIEventOnDLS;
struct CommonPADIBusConfigOnDLS;
struct CommonSTPConfigOnDLS;

struct GENPYBIND(inline_base("*")) PADIBusBlockOnDLS
    : public common::detail::RantWrapper<PADIBusBlockOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit PADIBusBlockOnDLS(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	SynramOnDLS toSynramOnDLS() const;
	PADIEventOnDLS toPADIEventOnDLS() const;
	CommonPADIBusConfigOnDLS toCommonPADIBusConfigOnDLS() const;
	CommonSTPConfigOnDLS toCommonSTPConfigOnDLS() const;

	static const PADIBusBlockOnDLS top;
	static const PADIBusBlockOnDLS bottom;
};

struct GENPYBIND(inline_base("*")) PADIBusOnPADIBusBlock
    : public common::detail::RantWrapper<PADIBusOnPADIBusBlock, uint_fast16_t, 3, 0>
{
	constexpr explicit PADIBusOnPADIBusBlock(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


HALCO_COORDINATE_MIXIN(PADIBusMixin, PADIBusBlockOnDLS, padi_bus)

struct GENPYBIND(inline_base("*PADIBusMixin*")) PADIBusOnDLS
    : public PADIBusMixin<PADIBusOnDLS, PADIBusOnPADIBusBlock>
{
	PADIBusOnDLS() = default;

	explicit PADIBusOnDLS(
	    PADIBusOnPADIBusBlock const& synapse_driver,
	    PADIBusBlockOnDLS const& block = PADIBusBlockOnDLS()) :
	    mixin_t(synapse_driver, block)
	{}

	explicit PADIBusOnDLS(enum_type const& e) : mixin_t(e) {}

	PADIBusOnPADIBusBlock toPADIBusOnPADIBusBlock() const { return This(); }
	CrossbarOutputOnDLS toCrossbarOutputOnDLS() const { return CrossbarOutputOnDLS(toEnum()); }
};

struct GENPYBIND(inline_base("*")) CommonPADIBusConfigOnDLS
    : public common::detail::RantWrapper<CommonPADIBusConfigOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit CommonPADIBusConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}

	PADIBusBlockOnDLS toPADIBusBlockOnDLS() const { return PADIBusBlockOnDLS(toEnum()); }

	static const CommonPADIBusConfigOnDLS top;
	static const CommonPADIBusConfigOnDLS bottom;
};

struct GENPYBIND(inline_base("*")) CommonSTPConfigOnDLS
    : public common::detail::RantWrapper<CommonSTPConfigOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit CommonSTPConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}

	PADIBusBlockOnDLS toPADIBusBlockOnDLS() const { return PADIBusBlockOnDLS(toEnum()); }

	static const CommonSTPConfigOnDLS top;
	static const CommonSTPConfigOnDLS bottom;
};

struct GENPYBIND(inline_base("*")) PADIEventOnDLS
    : public common::detail::RantWrapper<PADIEventOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit PADIEventOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	PADIBusBlockOnDLS toPADIBusBlockOnDLS() const { return PADIBusBlockOnDLS(toEnum()); }

	static const PADIEventOnDLS top;
	static const PADIEventOnDLS bottom;
};

/******\
  CADC
\******/

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
HALCO_COORDINATE_MIXIN(CADCReadoutTypeMixin, CADCReadoutType, cadc_readout_type)

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

struct GENPYBIND(inline_base("*")) CADCSampleOnCADCSampleQuad
    : public common::detail::RantWrapper<CADCSampleOnCADCSampleQuad, uint_fast16_t, 3, 0>
{
	constexpr explicit CADCSampleOnCADCSampleQuad(uintmax_t const val = 0) : rant_t(val) {}
};

} // namespace vx
} // namespace hicann_dls
} // namespace halco

// std::hash specializations
namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PADIBusOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PADIBusBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PADIBusOnPADIBusBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::PADIEventOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonPADIBusConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonSTPConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCChannelType)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCReadoutType)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCSampleQuadOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCSampleQuadUnspecifiedReadoutOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCSampleQuadOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCChannelColumnOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCChannelConfigOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCChannelConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCSampleOnCADCSampleQuad)

} // namespace std

GENPYBIND(postamble, tag(hicann_dls_vx))
GENPYBIND_MANUAL({
	parent->py::module::import("pyhalco_hicann_dls_vx_patch").attr("patch")(parent);
})
