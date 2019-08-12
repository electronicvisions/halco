#pragma once

extern "C" {
#include <stdint.h>
}

#include "pywrap/compat/macros.hpp"

#include "halco/common/genpybind.h"
#include "halco/common/geometry.h"
#include "halco/common/relations.h"
#include "halco/common/tblr.h"
#include "halco/hicann/v2/fg.h"
#include "halco/hicann/v2/fwd.h"
#include "halco/hicann/v2/hicann.h"

namespace halco {
namespace hicann {
namespace v2 GENPYBIND_TAG_HALCO_HICANN_V2 {

/** Neuron block coordinate.
 * A neuron block is made up of 64 neurons connected to the same priority
 * encoder,
 * of which 32 are in the top and 32 in the bottom HICANN block.
 * There are 8 blocks, so coordinate ranges from 0 (left) to 7(right).
 */
struct GENPYBIND(inline_base("*")) NeuronBlockOnHICANN
    : public common::detail::RantWrapper<NeuronBlockOnHICANN, uint_fast16_t, 7, 0>
{
	PYPP_CONSTEXPR explicit NeuronBlockOnHICANN(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
};

struct GENPYBIND(inline_base("*HICANNMixin*")) NeuronBlockOnWafer
    : public HICANNMixin<NeuronBlockOnWafer, NeuronBlockOnHICANN>
{
private:
	typedef HICANNMixin<NeuronBlockOnWafer, NeuronBlockOnHICANN> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	PYPP_DEFAULT(NeuronBlockOnWafer());

	explicit NeuronBlockOnWafer(NeuronBlockOnHICANN const& block,
	                            HICANNOnWafer const& h = HICANNOnWafer())
	    : base(block, h) {}

	explicit NeuronBlockOnWafer(enum_type const& e) : base(e) {}

	NeuronBlockOnHICANN toNeuronBlockOnHICANN() const { return This(); }
};

struct GENPYBIND(inline_base("*WaferMixin*")) NeuronBlockGlobal
    : public WaferMixin<NeuronBlockGlobal, NeuronBlockOnWafer>
{
private:
	typedef WaferMixin<NeuronBlockGlobal, NeuronBlockOnWafer> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	PYPP_DEFAULT(NeuronBlockGlobal());

	explicit NeuronBlockGlobal(NeuronBlockOnWafer const& block, Wafer const& w = Wafer())
		: base(block, w) {}
	explicit NeuronBlockGlobal(NeuronBlockOnHICANN const& block,
	                           HICANNGlobal const& h = HICANNGlobal())
		: base(NeuronBlockOnWafer(block, h.toHICANNOnWafer()), h.toWafer()) {}
	explicit NeuronBlockGlobal(enum_type const& e) : base(e) {}

	NeuronBlockOnWafer toNeuronBlockOnWafer() const { return This(); }
	HICANNGlobal toHICANNGlobal() const;
}; // NeuronBlockGlobal

struct GENPYBIND(inline_base("*")) NeuronOnNeuronBlock
    : public common::detail::
          GridCoordinate<NeuronOnNeuronBlock, common::XRanged<31, 0>, common::YRanged<1, 0> >
    , public common::detail::HasTopBottom<NeuronOnNeuronBlock>
{
	GRID_COMMON_CONSTRUCTORS(NeuronOnNeuronBlock)

	NeuronOnHICANN toNeuronOnHICANN(NeuronBlockOnHICANN const&) const;
	NeuronGlobal toNeuronGlobal(NeuronBlockGlobal const&) const;
	NeuronOnWafer toNeuronOnWafer(NeuronBlockOnWafer const&) const;
};

/** QuadOnHICANN address.
 * A quad consists of 4 (2x2) neurons.
 * There are 128 quads per HICANN and 16 quads per neuron block.
 */
struct GENPYBIND(inline_base("*")) QuadOnHICANN
    : public common::detail::RantWrapper<QuadOnHICANN, uint_fast16_t, 127, 0>
{
	PYPP_CONSTEXPR explicit QuadOnHICANN(uintmax_t const val = 0) GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	NeuronBlockOnHICANN toNeuronBlockOnHICANN() const {
		return NeuronBlockOnHICANN(value() / 16);
	}
};

// 2D Neuron coordinate relative to neuron quad (0 <= x,y < 2)
struct GENPYBIND(inline_base("*")) NeuronOnQuad
    : public common::detail::
          GridCoordinate<NeuronOnQuad, common::XRanged<1, 0>, common::YRanged<1, 0> >
    , public common::detail::HasTopBottom<NeuronOnQuad>
{
	GRID_COMMON_CONSTRUCTORS(NeuronOnQuad)
};

struct GENPYBIND(inline_base("*")) NeuronOnFGBlock
    : public common::detail::RantWrapper<NeuronOnFGBlock, uint_fast16_t, 127, 0>
{
	PYPP_CONSTEXPR explicit NeuronOnFGBlock(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	NeuronOnHICANN toNeuronOnHICANN(const FGBlockOnHICANN& block) const;
};

// 2D local Neuron coordinate (0..511)
struct GENPYBIND(inline_base("*")) NeuronOnHICANN
    : public common::detail::
          GridCoordinate<NeuronOnHICANN, common::XRanged<255, 0>, common::YRanged<1, 0> >
    , public common::detail::HasTopBottom<NeuronOnHICANN>
{
	GRID_COMMON_CONSTRUCTORS(NeuronOnHICANN)

	// TODO: Replace with conversion member function for consistency
	explicit NeuronOnHICANN(QuadOnHICANN const& q, NeuronOnQuad const& nrn)
	    : grid_type(x_type(q * 2 + nrn.x()), nrn.y()) {}

	// TODO: getter for other NeuronQuad and QuadPos corrdinate
	// hicann::Quad
	// QuadPos
	// NeuronOnQuad

	QuadOnHICANN toQuadOnHICANN() const { return QuadOnHICANN(x() / 2); }
	NeuronOnQuad toNeuronOnQuad() const {
		return NeuronOnQuad(NeuronOnQuad::x_type(x() % 2), NeuronOnQuad::y_type(y()));
	}

	NeuronBlockOnHICANN toNeuronBlockOnHICANN() const {
		return NeuronBlockOnHICANN(x() / NeuronOnNeuronBlock::x_type::end);
	}

	NeuronOnNeuronBlock toNeuronOnNeuronBlock() const {
		return NeuronOnNeuronBlock(common::X(x() % NeuronOnNeuronBlock::x_type::end), y());
	}

	// Shared Neuron Parameter are assigned differently to FGBlocks than
	// individual neuron parameters.
	FGBlockOnHICANN toSharedFGBlockOnHICANN() const {
		return FGBlockOnHICANN(toNeuronOnQuad().toEnum());
	}

	FGBlockOnHICANN toNeuronFGBlock() const { return FGBlockOnHICANN(common::Enum(toEnum() / 128)); }

	NeuronOnFGBlock toNeuronOnFGBlock() const { return NeuronOnFGBlock(toEnum() % 128); }
};

struct GENPYBIND(inline_base("*HICANNMixin*")) NeuronOnWafer
    : public HICANNMixin<NeuronOnWafer, NeuronOnHICANN>
{
private:
	typedef HICANNMixin<NeuronOnWafer, NeuronOnHICANN> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	PYPP_DEFAULT(NeuronOnWafer());

	explicit NeuronOnWafer(NeuronOnHICANN const& nrn, HICANNOnWafer const& h = HICANNOnWafer())
		: base(nrn, h) {}
	explicit NeuronOnWafer(enum_type const& e) : base(e) {}

	NeuronOnHICANN toNeuronOnHICANN() const { return This(); }
	NeuronBlockOnWafer toNeuronBlockOnWafer() const;
};

struct GENPYBIND(inline_base("*WaferMixin*")) NeuronGlobal
    : public WaferMixin<NeuronGlobal, NeuronOnWafer>
{
private:
	typedef WaferMixin<NeuronGlobal, NeuronOnWafer> base;

public:
	typedef base::enum_type enum_type GENPYBIND(opaque(false));

	PYPP_DEFAULT(NeuronGlobal());

	explicit NeuronGlobal(NeuronOnWafer const& nrn, Wafer const& w = Wafer()) : base(nrn, w) {}
	explicit NeuronGlobal(NeuronOnHICANN const& nrn, HICANNGlobal const& h = HICANNGlobal())
		: base(NeuronOnWafer(nrn, h.toHICANNOnWafer()), h.toWafer()) {}
	explicit NeuronGlobal(enum_type const& e) : base(e) {}

	NeuronOnWafer toNeuronOnWafer() const { return This(); }
	NeuronBlockGlobal toNeuronBlockGlobal() const;
	HICANNGlobal toHICANNGlobal() const;
}; // NeuronGlobal

class GENPYBIND(inline_base("*")) SynapticInputOnNeuron
    : public common::detail::RantWrapper<SynapticInputOnNeuron, uint_fast16_t, 1, 0>
{
public:
	PYPP_CONSTEXPR explicit SynapticInputOnNeuron(uintmax_t const val = 0)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}
	PYPP_CONSTEXPR SynapticInputOnNeuron(common::SideHorizontal val)
	    GENPYBIND(implicit_conversion) :
	    rant_t(val)
	{}

	static SynapticInputOnNeuron const default_inh;
	static SynapticInputOnNeuron const default_exc;
}; // SynapticInputOnNeuron

HALCO_COORDINATE_MIXIN(NeuronMixin, NeuronOnHICANN, neuron)

class GENPYBIND(inline_base("*NeuronMixin*")) SynapticInputOnHICANN
    : public NeuronMixin<SynapticInputOnHICANN, SynapticInputOnNeuron>
{
private:
	typedef NeuronMixin<SynapticInputOnHICANN, SynapticInputOnNeuron> base;

public:
	using base::enum_type;

	PYPP_DEFAULT(SynapticInputOnHICANN());

	explicit SynapticInputOnHICANN(SynapticInputOnNeuron const& input,
	                            NeuronOnHICANN const& neuron = NeuronOnHICANN())
	    : base(input, neuron) {}

	explicit SynapticInputOnHICANN(enum_type const& e) : base(e) {}
}; // SynapticInputOnHICANN

} // v2
} // hicann
} // halco

// std::hash specializations
namespace std {

HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::NeuronBlockGlobal)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::NeuronBlockOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::NeuronBlockOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::NeuronGlobal)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::NeuronOnFGBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::NeuronOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::NeuronOnNeuronBlock)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::NeuronOnQuad)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::NeuronOnWafer)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::QuadOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SynapticInputOnNeuron)
HALCO_GEOMETRY_HASH_CLASS(halco::hicann::v2::SynapticInputOnHICANN)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::HICANNMixin<halco::hicann::v2::NeuronBlockOnWafer BOOST_PP_COMMA()
    halco::hicann::v2::NeuronBlockOnHICANN>)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::HICANNMixin<halco::hicann::v2::NeuronOnWafer BOOST_PP_COMMA()
    halco::hicann::v2::NeuronOnHICANN>)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::WaferMixin<halco::hicann::v2::NeuronBlockGlobal BOOST_PP_COMMA()
    halco::hicann::v2::NeuronBlockOnWafer>)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::WaferMixin<halco::hicann::v2::NeuronGlobal BOOST_PP_COMMA()
    halco::hicann::v2::NeuronOnWafer>)
HALCO_GEOMETRY_HASH_CLASS(
    halco::hicann::v2::NeuronMixin<halco::hicann::v2::SynapticInputOnHICANN BOOST_PP_COMMA()
    halco::hicann::v2::SynapticInputOnNeuron>)

} // std
