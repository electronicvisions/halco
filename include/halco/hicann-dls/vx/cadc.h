#pragma once
#include <stdint.h>

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/mixin.h"

#include "halco/hicann-dls/vx/synapse.h"
#include "halco/hicann-dls/vx/synram.h"

namespace halco::hicann_dls::vx GENPYBIND_TAG_HALCO_HICANN_DLS_VX {

struct SynapseRowOnDLS;
struct SynapseWeightRowOnDLS;
struct SynapseLabelRowOnDLS;
struct SynapseCorrelationCalibRowOnDLS;

#include "halco/hicann-dls/vx/hemisphere_fwd.h"

/**********\
    CADC
\**********/

struct GENPYBIND(inline_base("*")) CADCOnDLS
    : public common::detail::RantWrapper<CADCOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit CADCOnDLS(uintmax_t const val = 0) : rant_t(val) {}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

	static const CADCOnDLS top;
	static const CADCOnDLS bottom;
};


struct GENPYBIND(inline_base("*")) CADCConfigOnDLS
    : public common::detail::RantWrapper<CADCConfigOnDLS, uint_fast16_t, 1, 0>
{
	constexpr explicit CADCConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}

#include "halco/hicann-dls/vx/convert_hemisphere_decl.h"

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


struct GENPYBIND(inline_base("*")) CADCChannelColumnOnSynram
    : public common::detail::RantWrapper<CADCChannelColumnOnSynram, uint_fast16_t, 255, 0>
{
	constexpr explicit CADCChannelColumnOnSynram(uintmax_t const val = 0) : rant_t(val) {}
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

	SynapseRowOnDLS toSynapseRowOnDLS() const;
	SynapseWeightRowOnDLS toSynapseWeightRowOnDLS() const;
	SynapseLabelRowOnDLS toSynapseLabelRowOnDLS() const;
	SynapseCorrelationCalibRowOnDLS toSynapseCorrelationCalibRowOnDLS() const;
};


struct GENPYBIND(inline_base("*")) CADCOffsetSRAMTimingConfigOnDLS
    : public common::detail::RantWrapper<CADCOffsetSRAMTimingConfigOnDLS, uint_fast16_t, 3, 0>
{
	constexpr explicit CADCOffsetSRAMTimingConfigOnDLS(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};


struct GENPYBIND(inline_base("*")) CADCSamplesOnDLS
    : public common::detail::RantWrapper<CADCSamplesOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit CADCSamplesOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

} // namespace halco::hicann_dls::vx

namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCChannelType)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCReadoutType)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCChannelColumnOnSynram)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCSampleRowOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCOffsetSRAMTimingConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::vx::CADCSamplesOnDLS)

} // namespace std
