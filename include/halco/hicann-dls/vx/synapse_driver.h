#pragma once
#include <array>
#include <stdint.h>

#include "halco/common/coordinate.h"
#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"
#include "halco/common/typed_array.h"
#include "halco/hicann-dls/vx/synapse.h"
#include "hate/visibility.h"

namespace halco::hicann_dls {
namespace vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

#include "halco/hicann-dls/vx/hemisphere_fwd.h"

/*****************\
   SynapseDriver
\*****************/

struct PADIBusOnPADIBusBlock;
struct SynapseDriverOnPADIBus;
struct SynapseRowOnSynram;
struct SynapseRowOnSynapseDriver;
struct CapMemBlockOnDLS;

struct GENPYBIND(inline_base("*")) SynapseDriverOnSynapseDriverBlock
    : public common::detail::RantWrapper<SynapseDriverOnSynapseDriverBlock, uint_fast16_t, 127, 0>
{
	constexpr explicit SynapseDriverOnSynapseDriverBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	PADIBusOnPADIBusBlock toPADIBusOnPADIBusBlock() const SYMBOL_VISIBLE;
	SynapseDriverOnPADIBus toSynapseDriverOnPADIBus() const SYMBOL_VISIBLE;

	typedef common::typed_array<SynapseRowOnSynram, SynapseRowOnSynapseDriver> synapse_row_type
	    GENPYBIND(opaque(false));
	synapse_row_type toSynapseRowOnSynram() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*")) SynapseDriverOnPADIBus
    : public common::detail::RantWrapper<SynapseDriverOnPADIBus, uint_fast16_t, 31, 0>
{
	constexpr explicit SynapseDriverOnPADIBus(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	typedef common::typed_array<SynapseDriverOnSynapseDriverBlock, PADIBusOnPADIBusBlock>
	    synapse_driver_type GENPYBIND(opaque(false));
	synapse_driver_type toSynapseDriverOnSynapseDriverBlock() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    SynapseDriverBlockOnDLS
    : public common::detail::RantWrapper<SynapseDriverBlockOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<SynapseDriverBlockOnDLS>
{
	constexpr explicit SynapseDriverBlockOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const SYMBOL_VISIBLE SynapseDriverBlockOnDLS top;
	static const SYMBOL_VISIBLE SynapseDriverBlockOnDLS bottom;
};


HALCO_COORDINATE_MIXIN(SynapseDriverMixin, SynapseDriverBlockOnDLS, synapse_driver)

struct GENPYBIND(inline_base("*SynapseDriverMixin*"), inline_base("*CoordinateBase*"))
    SynapseDriverOnDLS
    : public SynapseDriverMixin<SynapseDriverOnDLS, SynapseDriverOnSynapseDriverBlock>
    , common::CoordinateBase<SynapseDriverOnDLS>
{
	SynapseDriverOnDLS() = default;

	explicit SynapseDriverOnDLS(
	    SynapseDriverOnSynapseDriverBlock const& synapse_driver,
	    SynapseDriverBlockOnDLS const& block = SynapseDriverBlockOnDLS()) :
	    mixin_t(synapse_driver, block)
	{}

	explicit SynapseDriverOnDLS(enum_type const& e) : mixin_t(e) {}

	SynapseDriverOnSynapseDriverBlock toSynapseDriverOnSynapseDriverBlock() const { return This(); }
	CapMemBlockOnDLS toCapMemBlockOnDLS() const SYMBOL_VISIBLE;
	std::array<
	    SynapseRowOnDLS,
	    halco::hicann_dls::vx::SynapseRowOnDLS::size /
	        halco::hicann_dls::vx::SynapseDriverMixin<
	            halco::hicann_dls::vx::SynapseDriverOnDLS,
	            halco::hicann_dls::vx::SynapseDriverOnSynapseDriverBlock>::size>
	toSynapseRowOnDLS() const SYMBOL_VISIBLE;
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    CommonSynapseDriverConfigOnDLS
    : public common::detail::RantWrapper<CommonSynapseDriverConfigOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<CommonSynapseDriverConfigOnDLS>
{
	constexpr explicit CommonSynapseDriverConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const SYMBOL_VISIBLE CommonSynapseDriverConfigOnDLS top;
	static const SYMBOL_VISIBLE CommonSynapseDriverConfigOnDLS bottom;
};


struct GENPYBIND(inline_base("*RantWrapper*"), inline_base("*CoordinateBase*"))
    SynapseDriverSRAMTimingConfigOnDLS
    : public common::detail::RantWrapper<SynapseDriverSRAMTimingConfigOnDLS, uint_fast16_t, 1, 0>
    , common::CoordinateBase<SynapseDriverSRAMTimingConfigOnDLS>
{
	constexpr explicit SynapseDriverSRAMTimingConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const SYMBOL_VISIBLE SynapseDriverSRAMTimingConfigOnDLS top;
	static const SYMBOL_VISIBLE SynapseDriverSRAMTimingConfigOnDLS bottom;
};

} // namespace vx
} // namespace halco::hicann_dls

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseDriverOnSynapseDriverBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseDriverBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseDriverOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CommonSynapseDriverConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::SynapseDriverSRAMTimingConfigOnDLS)

} // namespace std
