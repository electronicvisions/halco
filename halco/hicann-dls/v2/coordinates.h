#pragma once

extern "C" {
#include <stdint.h>
}

#include "halco/common/common.h"
#include "halco/common/geometry.th"
#include "halco/common/genpybind.h"

GENPYBIND(tag(hicann_dls_v2))
GENPYBIND_MANUAL({
	parent.attr("__variant__") = "pybind11";
	parent->py::module::import("pyhalco_common");
})

namespace halco {
namespace hicann_dls {
namespace v2 GENPYBIND(tag(hicann_dls_v2)) {

struct CapMemColumnOnDLS;
struct ColumnCorrelationSwitchOnDLS;
struct ColumnCurrentSwitchOnDLS;
struct SynapseColumnOnDLS;
struct SynapseRowOnDLS;

/**********\
   NEURON
\**********/

struct GENPYBIND(inline_base("*")) NeuronOnDLS
	: public common::detail::RantWrapper<NeuronOnDLS, uint_fast16_t, 31, 0>
{
	constexpr explicit NeuronOnDLS(uintmax_t const val = 0) : rant_t(val) {}

	CapMemColumnOnDLS toCapMemColumnOnDLS() const;
	ColumnCorrelationSwitchOnDLS toColumnCorrelationSwitchOnDLS() const;
	ColumnCurrentSwitchOnDLS toColumnCurrentSwitchOnDLS() const;
	SynapseColumnOnDLS toSynapseColumnOnDLS() const;
};

struct GENPYBIND(inline_base("*")) CommonNeuronConfigOnDLS
	: public common::detail::RantWrapper<CommonNeuronConfigOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit CommonNeuronConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

/*********************\
   SynapseDriverBlock
\*********************/

struct GENPYBIND(inline_base("*")) SynapseDriverBlockOnDLS
	: public common::detail::RantWrapper<SynapseDriverBlockOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit SynapseDriverBlockOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) SynapseDriverOnDLS
	: public common::detail::RantWrapper<SynapseDriverOnDLS, uint_fast16_t, 31, 0>
	, public common::detail::YRangedTrait
{
	constexpr explicit SynapseDriverOnDLS(uintmax_t const val = 0) : rant_t(val) {}
	constexpr explicit SynapseDriverOnDLS(common::Y const& y) : rant_t(y) {}

	SynapseRowOnDLS toSynapseRowOnDLS() const;
};

/***********\
   Synapse
\***********/

struct GENPYBIND(inline_base("*")) ColumnBlockOnDLS
	: public common::detail::RantWrapper<ColumnBlockOnDLS, uint_fast16_t, 7, 0>
	, public common::detail::XRangedTrait
{
	constexpr explicit ColumnBlockOnDLS(uintmax_t const val = 0) : rant_t(val) {}
	constexpr explicit ColumnBlockOnDLS(common::X const& x) : rant_t(x) {}
};

struct GENPYBIND(inline_base("*")) SynapseBlockOnDLS
	: public common::detail::GridCoordinate<
		  SynapseBlockOnDLS, ColumnBlockOnDLS, SynapseDriverOnDLS>
{
	GRID_COMMON_CONSTRUCTORS(SynapseBlockOnDLS)

	ColumnBlockOnDLS toColumnBlockOnDLS() const { return x(); }
	SynapseDriverOnDLS toSynapseDriverOnDLS() const { return y(); }
};

struct GENPYBIND(inline_base("*")) SynapseOnSynapseBlock
	: public common::detail::RantWrapper<SynapseOnSynapseBlock, uint_fast16_t, 3, 0>
	, public common::detail::XRangedTrait
{
	constexpr explicit SynapseOnSynapseBlock(uintmax_t const val = 0) : rant_t(val) {}
	constexpr explicit SynapseOnSynapseBlock(common::X const& x) : rant_t(x) {}
};

struct GENPYBIND(inline_base("*")) SynapseColumnOnDLS
	: public common::detail::RantWrapper<SynapseColumnOnDLS, uint_fast16_t, 31, 0>
	, public common::detail::XRangedTrait
{
	constexpr explicit SynapseColumnOnDLS(uintmax_t const val = 0) : rant_t(val) {}
	constexpr explicit SynapseColumnOnDLS(common::X const& x) : rant_t(x) {}

	NeuronOnDLS toNeuronOnDLS() const { return NeuronOnDLS(value()); }
};

struct GENPYBIND(inline_base("*")) SynapseRowOnDLS
	: public common::detail::RantWrapper<SynapseRowOnDLS, uint_fast16_t, 31, 0>
	, public common::detail::YRangedTrait
{
	constexpr explicit SynapseRowOnDLS(uintmax_t const val = 0) : rant_t(val) {}
	constexpr explicit SynapseRowOnDLS(common::Y const& y) : rant_t(y) {}

	SynapseDriverOnDLS toSynapseDriverOnDLS() const { return SynapseDriverOnDLS(value()); }
};

struct GENPYBIND(inline_base("*")) SynapseOnDLS
	: public common::detail::GridCoordinate<SynapseOnDLS, SynapseColumnOnDLS, SynapseRowOnDLS>
{
	GRID_COMMON_CONSTRUCTORS(SynapseOnDLS)

	SynapseColumnOnDLS toSynapseColumnOnDLS() const { return x(); }
	SynapseRowOnDLS toSynapseRowOnDLS() const { return y(); }
	NeuronOnDLS toNeuronOnDLS() const { return NeuronOnDLS(x()); }
	SynapseDriverOnDLS toSynapseDriverOnDLS() const { return SynapseDriverOnDLS(y()); }
	SynapseBlockOnDLS toSynapseBlockOnDLS() const;
	SynapseOnSynapseBlock toSynapseOnSynapseBlock() const;
	ColumnCorrelationSwitchOnDLS toColumnCorrelationSwitchOnDLS() const;
	ColumnCurrentSwitchOnDLS toColumnCurrentSwitchOnDLS() const;
};


/*****************\
  SynapseSwitches
\*****************/

struct GENPYBIND(inline_base("*")) ColumnCorrelationSwitchOnColumnBlock
	: public common::detail::RantWrapper<
		  ColumnCorrelationSwitchOnColumnBlock, SynapseOnSynapseBlock::value_type,
		  SynapseOnSynapseBlock::max, SynapseOnSynapseBlock::min>
	, public common::detail::XRangedTrait
{
	constexpr explicit ColumnCorrelationSwitchOnColumnBlock(uintmax_t const val = 0) : rant_t(val) {}
	constexpr explicit ColumnCorrelationSwitchOnColumnBlock(common::X const& x) : rant_t(x) {}

	SynapseOnSynapseBlock toSynapseOnSynapseBlock() const { return SynapseOnSynapseBlock(value()); }
};

struct GENPYBIND(inline_base("*")) ColumnCorrelationSwitchOnDLS
	: public common::detail::RantWrapper<
		  ColumnCorrelationSwitchOnDLS, NeuronOnDLS::value_type, NeuronOnDLS::max, NeuronOnDLS::min>
	, public common::detail::XRangedTrait
{
	constexpr explicit ColumnCorrelationSwitchOnDLS(uintmax_t const val = 0) : rant_t(val) {}
	constexpr explicit ColumnCorrelationSwitchOnDLS(common::X const& x) : rant_t(x) {}

	ColumnCorrelationSwitchOnColumnBlock toColumnCorrelationSwitchOnColumnBlock() const;
	ColumnBlockOnDLS toColumnBlockOnDLS() const;
	ColumnCurrentSwitchOnDLS toColumnCurrentSwitchOnDLS() const;
	NeuronOnDLS toNeuronOnDLS() const { return NeuronOnDLS(value()); }
};

struct GENPYBIND(inline_base("*")) ColumnCurrentSwitchOnColumnBlock
	: public common::detail::RantWrapper<
		  ColumnCurrentSwitchOnColumnBlock, SynapseOnSynapseBlock::value_type,
		  SynapseOnSynapseBlock::max, SynapseOnSynapseBlock::min>
	, public common::detail::XRangedTrait
{
	constexpr explicit ColumnCurrentSwitchOnColumnBlock(uintmax_t const val = 0) : rant_t(val) {}
	constexpr explicit ColumnCurrentSwitchOnColumnBlock(common::X const& x) : rant_t(x) {}

	SynapseOnSynapseBlock toSynapseOnSynapseBlock() const { return SynapseOnSynapseBlock(value()); }
};

struct GENPYBIND(inline_base("*")) ColumnCurrentSwitchOnDLS
	: public common::detail::RantWrapper<
		  ColumnCurrentSwitchOnDLS, NeuronOnDLS::value_type, NeuronOnDLS::max, NeuronOnDLS::min>
	, public common::detail::XRangedTrait
{
	constexpr explicit ColumnCurrentSwitchOnDLS(uintmax_t const val = 0) : rant_t(val) {}
	constexpr explicit ColumnCurrentSwitchOnDLS(common::X const& x) : rant_t(x) {}

	ColumnCurrentSwitchOnColumnBlock toColumnCurrentSwitchOnColumnBlock() const;
	ColumnBlockOnDLS toColumnBlockOnDLS() const;
	ColumnCorrelationSwitchOnDLS toColumnCorrelationSwitchOnDLS() const;
	NeuronOnDLS toNeuronOnDLS() const { return NeuronOnDLS(value()); }
};

struct GENPYBIND(inline_base("*")) CorrelationConfigOnDLS
	: public common::detail::RantWrapper<CorrelationConfigOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit CorrelationConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

/**********\
   CapMem
\**********/

// Max value is 1 larger than neuron max due to global capmem column
struct GENPYBIND(inline_base("*")) CapMemColumnOnDLS
	: public common::detail::RantWrapper<
		  CapMemColumnOnDLS, NeuronOnDLS::value_type, NeuronOnDLS::max + 1, NeuronOnDLS::min>
	, public common::detail::XRangedTrait
{
	constexpr explicit CapMemColumnOnDLS(uintmax_t const val = 0) : rant_t(val) {}
	constexpr explicit CapMemColumnOnDLS(common::X const& x) : rant_t(x) {}
	static constexpr CapMemColumnOnDLS SharedCapMemColumnOnDLS() { return CapMemColumnOnDLS(max); }

	bool isShared() const { return value() == max; }
};

struct GENPYBIND(inline_base("*")) CapMemRowOnDLS
	: public common::detail::RantWrapper<CapMemRowOnDLS, uint_fast16_t, 23, 0>
	, public common::detail::YRangedTrait
{
	constexpr explicit CapMemRowOnDLS(uintmax_t const val = 0) : rant_t(val) {}
	constexpr explicit CapMemRowOnDLS(common::Y const& y) : rant_t(y) {}
};

struct GENPYBIND(inline_base("*")) CapMemConfigOnDLS
	: public common::detail::RantWrapper<CapMemConfigOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit CapMemConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) CapMemOnDLS
	: public common::detail::RantWrapper<CapMemOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit CapMemOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

enum class GENPYBIND(visible) NeuronParameter
{
	v_leak = 0,
	v_treshold = 1,
	v_exc_syn_input_reference = 2,
	v_inh_syn_input_reference = 3,
	i_bias_spike_comparator = 9,
	i_spike_comparator_delay = 10,
	i_bias_leak_main = 11,
	i_bias_leak_sd = 12,
	i_bias_readout_buffer = 13,
	i_refractory_time = 14,
	i_bias_exc_syn_input_main = 15,
	i_bias_exc_syn_input_sd = 16,
	i_bias_exc_syn_input_resistor = 17,
	i_bias_exc_syn_input_offset = 18,
	i_bias_inh_syn_input_main = 20,
	i_bias_inh_syn_input_sd = 22,
	i_bias_inh_syn_input_resistor = 19,
	i_bias_inh_syn_input_offset = 23,
};

enum class GENPYBIND(visible) CommonNeuronParameter
{
	e_reset = 0,
	i_bias_correlation_output = 8,
	i_bias_vstore = 9,
	i_bias_vramp = 10,
	i_bias_vdac = 11
};

struct GENPYBIND(inline_base("*")) CapMemCellOnDLS
	: public common::detail::GridCoordinate<CapMemCellOnDLS, CapMemColumnOnDLS, CapMemRowOnDLS>
{
	GRID_COMMON_CONSTRUCTORS(CapMemCellOnDLS)

	CapMemCellOnDLS(NeuronOnDLS const& neuron, NeuronParameter const& parameter);
	CapMemCellOnDLS(CommonNeuronParameter const& parameter);

	CapMemColumnOnDLS toCapMemColumnOnDLS() const { return x(); }
	CapMemRowOnDLS toCapMemRowOnDLS() const { return y(); }
	NeuronOnDLS toNeuronOnDLS() const;

	bool isShared() const;
};

/**********\
    PPU
\**********/

struct GENPYBIND(inline_base("*")) PPUMemoryWordOnDLS
	: public common::detail::RantWrapper<PPUMemoryWordOnDLS, uint_fast16_t, 0x1000 - 1, 0>
{
	constexpr explicit PPUMemoryWordOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) PPUMemoryOnDLS
	: public common::detail::RantWrapper<PPUMemoryOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit PPUMemoryOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) PPUControlRegisterOnDLS
	: public common::detail::RantWrapper<PPUControlRegisterOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit PPUControlRegisterOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) PPUStatusRegisterOnDLS
	: public common::detail::RantWrapper<PPUStatusRegisterOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit PPUStatusRegisterOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

class GENPYBIND(inline_base("*")) DACOnBoard
	: public common::detail::RantWrapper<DACOnBoard, uint_fast16_t, 1, 0>
{
public:
	constexpr explicit DACOnBoard(uintmax_t const val = 0) : rant_t(val) {}

	static DACOnBoard const DAC_25_DECIVOLT;
	static DACOnBoard const DAC_12_DECIVOLT;
}; // DACOnBoard

/****************\
   Rate Counters
\****************/

struct GENPYBIND(inline_base("*")) RateCounterConfigOnDLS
	: public common::detail::RantWrapper<RateCounterConfigOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit RateCounterConfigOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

struct GENPYBIND(inline_base("*")) RateCounterOnDLS
	: public common::detail::RantWrapper<RateCounterOnDLS, uint_fast16_t, 0, 0>
{
	constexpr explicit RateCounterOnDLS(uintmax_t const val = 0) : rant_t(val) {}
};

} // namespace v2
} // namespace hicann_dls
} // namespace halco

// std::hash specializations
namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::CapMemCellOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::CapMemColumnOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::CapMemRowOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::CapMemConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::CapMemOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::CommonNeuronConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::ColumnBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::ColumnCorrelationSwitchOnColumnBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::ColumnCorrelationSwitchOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::ColumnCurrentSwitchOnColumnBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::ColumnCurrentSwitchOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::CorrelationConfigOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::NeuronOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::PPUMemoryWordOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::PPUMemoryOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::PPUControlRegisterOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::PPUStatusRegisterOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::SynapseBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::SynapseDriverOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::SynapseDriverBlockOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::SynapseOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::SynapseOnSynapseBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::RateCounterOnDLS)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann_dls::v2::RateCounterConfigOnDLS)

} // namespace std

GENPYBIND(postamble, tag(hicann_dls_v2))
GENPYBIND_MANUAL({ parent->py::module::import("pyhalco_hicann_dls_v2_patch").attr("patch")(parent); })
