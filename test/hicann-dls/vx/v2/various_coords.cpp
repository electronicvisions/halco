#include <gtest/gtest.h>

#include "halco/common/cerealization_geometry.h"
#include "halco/common/iter_all.h"
#include "halco/common/typed_array.h"
#include "halco/hicann-dls/vx/v2/coordinates.h"

#include <cereal/archives/json.hpp>
#include <cereal/cereal.hpp>

using namespace halco::common;
using namespace halco::hicann_dls::vx::v2;

TEST(LogicalNeuronCompartments, Constructor)
{
	LogicalNeuronCompartments::Compartments correct{
	    {CompartmentOnLogicalNeuron(0),
	     {AtomicNeuronOnLogicalNeuron(Enum(0)), AtomicNeuronOnLogicalNeuron(Enum(1))}},
	    {CompartmentOnLogicalNeuron(1), {AtomicNeuronOnLogicalNeuron(Enum(2))}},
	};
	EXPECT_NO_THROW(LogicalNeuronCompartments{correct});

	LogicalNeuronCompartments::Compartments not_unique_neurons{
	    {CompartmentOnLogicalNeuron(0),
	     {AtomicNeuronOnLogicalNeuron(Enum(1)), AtomicNeuronOnLogicalNeuron(Enum(1))}},
	    {CompartmentOnLogicalNeuron(1), {AtomicNeuronOnLogicalNeuron(Enum(2))}},
	};
	EXPECT_THROW(LogicalNeuronCompartments{not_unique_neurons}, std::runtime_error);

	LogicalNeuronCompartments::Compartments not_unique_neurons_different_compartments{
	    {CompartmentOnLogicalNeuron(0),
	     {AtomicNeuronOnLogicalNeuron(Enum(1)), AtomicNeuronOnLogicalNeuron(Enum(2))}},
	    {CompartmentOnLogicalNeuron(1), {AtomicNeuronOnLogicalNeuron(Enum(2))}}};
	EXPECT_THROW(
	    LogicalNeuronCompartments{not_unique_neurons_different_compartments}, std::runtime_error);
}

TEST(LogicalNeuronCompartments, FlipX)
{
	{
		LogicalNeuronCompartments::Compartments compartments{
		    {CompartmentOnLogicalNeuron(0),
		     {AtomicNeuronOnLogicalNeuron(Enum(0)), AtomicNeuronOnLogicalNeuron(Enum(1))}},
		    {CompartmentOnLogicalNeuron(1), {AtomicNeuronOnLogicalNeuron(Enum(2))}},
		};
		LogicalNeuronCompartments logical_neuron_compartments(compartments);
		auto const flipped_logical_neuron_compartments = logical_neuron_compartments.flip_x();

		LogicalNeuronCompartments::Compartments flipped_compartments{
		    {CompartmentOnLogicalNeuron(0),
		     {AtomicNeuronOnLogicalNeuron(Enum(2)), AtomicNeuronOnLogicalNeuron(Enum(1))}},
		    {CompartmentOnLogicalNeuron(1), {AtomicNeuronOnLogicalNeuron(Enum(0))}},
		};
		EXPECT_EQ(flipped_logical_neuron_compartments.get_compartments(), flipped_compartments);
	}
	{
		LogicalNeuronCompartments::Compartments compartments{
		    {CompartmentOnLogicalNeuron(0),
		     {AtomicNeuronOnLogicalNeuron(Enum(0)), AtomicNeuronOnLogicalNeuron(Enum(1))}},
		    {CompartmentOnLogicalNeuron(1), {AtomicNeuronOnLogicalNeuron(Enum(128))}},
		};
		LogicalNeuronCompartments logical_neuron_compartments(compartments);
		auto const flipped_logical_neuron_compartments = logical_neuron_compartments.flip_x();
		LogicalNeuronCompartments::Compartments flipped_compartments{
		    {CompartmentOnLogicalNeuron(0),
		     {AtomicNeuronOnLogicalNeuron(Enum(1)), AtomicNeuronOnLogicalNeuron(Enum(0))}},
		    {CompartmentOnLogicalNeuron(1), {AtomicNeuronOnLogicalNeuron(Enum(129))}},
		};
		EXPECT_EQ(flipped_logical_neuron_compartments.get_compartments(), flipped_compartments);
	}
}

TEST(LogicalNeuronCompartments, FlipY)
{
	LogicalNeuronCompartments::Compartments compartments{
	    {CompartmentOnLogicalNeuron(0),
	     {AtomicNeuronOnLogicalNeuron(Enum(0)), AtomicNeuronOnLogicalNeuron(Enum(1))}},
	    {CompartmentOnLogicalNeuron(1), {AtomicNeuronOnLogicalNeuron(Enum(128))}},
	};
	LogicalNeuronCompartments logical_neuron_compartments(compartments);
	auto const flipped_logical_neuron_compartments = logical_neuron_compartments.flip_y();

	LogicalNeuronCompartments::Compartments flipped_compartments{
	    {CompartmentOnLogicalNeuron(0),
	     {AtomicNeuronOnLogicalNeuron(Enum(128)), AtomicNeuronOnLogicalNeuron(Enum(129))}},
	    {CompartmentOnLogicalNeuron(1), {AtomicNeuronOnLogicalNeuron(Enum(0))}},
	};
	EXPECT_EQ(flipped_logical_neuron_compartments.get_compartments(), flipped_compartments);
}

TEST(NeuronBackendConfigOnNeuronBackendConfigBlock, toNeuronEventOutputOnNeuronBackendBlock)
{
	{
		NeuronBackendConfigOnNeuronBackendConfigBlock coord(47);
		EXPECT_EQ(
		    coord.toNeuronEventOutputOnNeuronBackendBlock(),
		    NeuronEventOutputOnNeuronBackendBlock(1));
	}
	{
		NeuronBackendConfigOnNeuronBackendConfigBlock coord(128 + 65);
		EXPECT_EQ(
		    coord.toNeuronEventOutputOnNeuronBackendBlock(),
		    NeuronEventOutputOnNeuronBackendBlock(2));
	}
}

TEST(NeuronEventOutputOnDLS, toCrossbarInputOnDLS)
{
	NeuronEventOutputOnDLS coord(Enum(3));
	EXPECT_EQ(coord.toCrossbarInputOnDLS(), CrossbarInputOnDLS(3));
}

TEST(CrossbarInputOnDLS, toNeuronEventOutputOnDLS)
{
	halco::common::typed_array<std::optional<NeuronEventOutputOnDLS>, CrossbarInputOnDLS>
	    expectation = {NeuronEventOutputOnDLS(Enum(0)),
	                   NeuronEventOutputOnDLS(Enum(1)),
	                   NeuronEventOutputOnDLS(Enum(2)),
	                   NeuronEventOutputOnDLS(Enum(3)),
	                   NeuronEventOutputOnDLS(Enum(4)),
	                   NeuronEventOutputOnDLS(Enum(5)),
	                   NeuronEventOutputOnDLS(Enum(6)),
	                   NeuronEventOutputOnDLS(Enum(7)),
	                   std::nullopt,
	                   std::nullopt,
	                   std::nullopt,
	                   std::nullopt,
	                   std::nullopt,
	                   std::nullopt,
	                   std::nullopt,
	                   std::nullopt,
	                   std::nullopt,
	                   std::nullopt,
	                   std::nullopt,
	                   std::nullopt};

	for (auto i : iter_all<CrossbarInputOnDLS>()) {
		EXPECT_EQ(i.toNeuronEventOutputOnDLS(), expectation[i]);
	}
}

TEST(SynapseDriverOnSynapseDriverBlock, toSynapseRowOnSynram)
{
	SynapseDriverOnSynapseDriverBlock coord(23);

	auto const synapse_rows = coord.toSynapseRowOnSynram();
	EXPECT_EQ(synapse_rows[SynapseRowOnSynapseDriver::top], SynapseRowOnSynram(47));
	EXPECT_EQ(synapse_rows[SynapseRowOnSynapseDriver::bottom], SynapseRowOnSynram(46));
}

TEST(SynapseRowOnSynram, toSynapseRowOnSynapseDriver)
{
	{
		SynapseRowOnSynram coord(23);
		EXPECT_EQ(coord.toSynapseRowOnSynapseDriver(), SynapseRowOnSynapseDriver::top);
	}
	{
		SynapseRowOnSynram coord(42);
		EXPECT_EQ(coord.toSynapseRowOnSynapseDriver(), SynapseRowOnSynapseDriver::bottom);
	}
}

TEST(SynapseQuadOnDLS, toNeuronConfigBlockOnDLS)
{
	SynapseQuadOnDLS coord(
	    SynapseQuadOnSynram(SynapseQuadColumnOnDLS(13), SynapseRowOnSynram(23)),
	    SynramOnDLS::bottom);
	EXPECT_EQ(coord.toNeuronConfigBlockOnDLS(), NeuronConfigBlockOnDLS(2));
}

TEST(NeuronConfigOnDLS, toNeuronResetOnDLS)
{
	NeuronConfigOnDLS coord(NeuronConfigOnNeuronConfigBlock(23), NeuronConfigBlockOnDLS(1));
	EXPECT_EQ(
	    coord.toNeuronResetOnDLS(),
	    NeuronResetOnDLS(NeuronResetOnNeuronResetBlock(23), NeuronResetBlockOnDLS(1)));
}

TEST(NeuronConfigBlockOnDLS, toNeuronResetBlockOnDLS)
{
	NeuronConfigBlockOnDLS coord(1);
	EXPECT_EQ(coord.toNeuronResetBlockOnDLS(), NeuronResetBlockOnDLS(1));
}

TEST(NeuronConfigOnDLS, toSpikeCounterReadOnDLS)
{
	NeuronConfigOnDLS coord(NeuronConfigOnNeuronConfigBlock(23), NeuronConfigBlockOnDLS(1));
	EXPECT_EQ(
	    coord.toSpikeCounterReadOnDLS(),
	    SpikeCounterReadOnDLS(
	        SpikeCounterReadOnSpikeCounterReadBlock(23), SpikeCounterReadBlockOnDLS(1)));
}

TEST(NeuronConfigBlockOnDLS, toSpikeCounterReadBlockOnDLS)
{
	NeuronConfigBlockOnDLS coord(1);
	EXPECT_EQ(coord.toSpikeCounterReadBlockOnDLS(), SpikeCounterReadBlockOnDLS(1));
}

TEST(NeuronConfigOnDLS, toSpikeCounterResetOnDLS)
{
	NeuronConfigOnDLS coord(NeuronConfigOnNeuronConfigBlock(23), NeuronConfigBlockOnDLS(1));
	EXPECT_EQ(
	    coord.toSpikeCounterResetOnDLS(),
	    SpikeCounterResetOnDLS(
	        SpikeCounterResetOnSpikeCounterResetBlock(23), SpikeCounterResetBlockOnDLS(1)));
}

TEST(NeuronConfigBlockOnDLS, toSpikeCounterResetBlockOnDLS)
{
	NeuronConfigBlockOnDLS coord(1);
	EXPECT_EQ(coord.toSpikeCounterResetBlockOnDLS(), SpikeCounterResetBlockOnDLS(1));
}

TEST(CrossbarOutputOnDLS, toCrossbarL2OutputOnDLS)
{
	halco::common::typed_array<std::optional<CrossbarL2OutputOnDLS>, CrossbarOutputOnDLS>
	    expectation = {std::nullopt,
	                   std::nullopt,
	                   std::nullopt,
	                   std::nullopt,
	                   std::nullopt,
	                   std::nullopt,
	                   std::nullopt,
	                   std::nullopt,
	                   CrossbarL2OutputOnDLS(0),
	                   CrossbarL2OutputOnDLS(1),
	                   CrossbarL2OutputOnDLS(2),
	                   CrossbarL2OutputOnDLS(3)};

	for (auto o : iter_all<CrossbarOutputOnDLS>()) {
		EXPECT_EQ(o.toCrossbarL2OutputOnDLS(), expectation[o]);
	}
}

TEST(CrossbarOutputOnDLS, toPADIBusOnDLS)
{
	halco::common::typed_array<std::optional<PADIBusOnDLS>, CrossbarOutputOnDLS> expectation = {
	    PADIBusOnDLS(Enum(0)), PADIBusOnDLS(Enum(1)), PADIBusOnDLS(Enum(2)), PADIBusOnDLS(Enum(3)),
	    PADIBusOnDLS(Enum(4)), PADIBusOnDLS(Enum(5)), PADIBusOnDLS(Enum(6)), PADIBusOnDLS(Enum(7)),
	    std::nullopt,          std::nullopt,          std::nullopt,          std::nullopt};

	for (auto o : iter_all<CrossbarOutputOnDLS>()) {
		EXPECT_EQ(o.toPADIBusOnDLS(), expectation[o]);
	}
}

TEST(CrossbarInputOnDLS, toSPL1Address)
{
	halco::common::typed_array<std::optional<SPL1Address>, CrossbarInputOnDLS> expectation = {
	    std::nullopt,   std::nullopt,   std::nullopt, std::nullopt,   std::nullopt,
	    std::nullopt,   std::nullopt,   std::nullopt, SPL1Address(0), SPL1Address(1),
	    SPL1Address(2), SPL1Address(3), std::nullopt, std::nullopt,   std::nullopt,
	    std::nullopt,   std::nullopt,   std::nullopt, std::nullopt,   std::nullopt};

	for (auto i : iter_all<CrossbarInputOnDLS>()) {
		EXPECT_EQ(i.toSPL1Address(), expectation[i]);
	}
}

TEST(SynapseDriverOnSynapseDriverBlock, toSynapseDriverOnPADIBus)
{
	SynapseDriverOnSynapseDriverBlock coord(47);
	EXPECT_EQ(coord.toSynapseDriverOnPADIBus(), SynapseDriverOnPADIBus(11));
}

TEST(CrossbarL2OutputOnDLS, toCrossbarOutputOnDLS)
{
	CrossbarL2OutputOnDLS coord(3);
	EXPECT_EQ(coord.toCrossbarOutputOnDLS(), CrossbarOutputOnDLS(3 + 8));
}

TEST(SPL1Address, toCrossbarInputOnDLS)
{
	SPL1Address coord(3);
	EXPECT_EQ(coord.toCrossbarInputOnDLS(), CrossbarInputOnDLS(3 + 8));
}

TEST(PPUOnDLS, RespectsBounds)
{
	EXPECT_ANY_THROW(PPUOnDLS(2));
	EXPECT_NO_THROW(PPUOnDLS(1));
}

TEST(PPUMemoryWordOnPPU, RespectsBounds)
{
	EXPECT_ANY_THROW(PPUMemoryWordOnPPU(4096));
	EXPECT_NO_THROW(PPUMemoryWordOnPPU(4095));
}

TEST(PPUMemoryWordOnDLS, RespectsBounds)
{
	EXPECT_ANY_THROW(PPUMemoryWordOnDLS(Enum(8192)));
	EXPECT_NO_THROW(PPUMemoryWordOnDLS(Enum(8191)));
	EXPECT_EQ(PPUMemoryWordOnDLS::size, PPUMemoryWordOnPPU::size * PPUOnDLS::size);
	EXPECT_EQ(PPUMemoryWordOnDLS::min, 0);
	EXPECT_EQ(PPUMemoryWordOnDLS::max, PPUMemoryWordOnPPU::size * PPUOnDLS::size - 1);
}

TEST(PPUMemoryWordOnDLS, Conversion)
{
	PPUMemoryWordOnDLS test_coord(PPUMemoryWordOnPPU(1), PPUOnDLS(1));
	EXPECT_EQ(test_coord, PPUMemoryWordOnDLS(Enum(4097)));
	EXPECT_EQ(test_coord.toPPUMemoryWordOnPPU(), PPUMemoryWordOnPPU(1));
	EXPECT_EQ(test_coord.toPPUOnDLS(), PPUOnDLS(1));
}

TEST(DACChannelOnBoard, toVDDOnBoard)
{
	DACChannelOnBoard channel = DACChannelOnBoard::vdd12_madc;
	EXPECT_NO_THROW(channel.toVDDOnBoard());

	DACChannelOnBoard channel2 = DACChannelOnBoard::v_reset;
	EXPECT_ANY_THROW(channel2.toVDDOnBoard());
}

TEST(VDDOnBoard, toDACChannelOnBoard)
{
	for (auto vdd : iter_all<VDDOnBoard>()) {
		DACChannelOnBoard channel = vdd.toDACChannelOnBoard();
		VDDOnBoard res = channel.toVDDOnBoard();
		EXPECT_EQ(vdd, res);
	}
}

TEST(TCA9554ChannelOnBoard, toTCA9554OnBoard)
{
	for (auto channel : iter_all<TCA9554ChannelOnBoard>()) {
		EXPECT_NO_THROW(channel.toTCA9554OnBoard());
	}
}

TEST(PhyConfigChipOnDLS, toJTAGPhyRegisterOnDLS)
{
	PhyConfigChipOnDLS phy_config(3);
	EXPECT_EQ(phy_config.toJTAGPhyRegisterOnDLS(), JTAGPhyRegisterOnDLS(4));
}

TEST(CapMemColumnOnCapMemBlock, isShared)
{
	CapMemColumnOnCapMemBlock shared_1(128);
	CapMemColumnOnCapMemBlock shared_2(129);
	EXPECT_TRUE(shared_1.isShared());
	EXPECT_TRUE(shared_2.isShared());

	for (size_t i = 0; i < 128; ++i) {
		CapMemColumnOnCapMemBlock not_shared(i);
		EXPECT_FALSE(not_shared.isShared());
	}
}

TEST(CrossbarNodeOnDLS, Construction)
{
	// valid node
	auto input = CrossbarInputOnDLS(13);
	auto output = CrossbarOutputOnDLS(9);

	auto node = CrossbarNodeOnDLS(output, input);
	EXPECT_EQ(node.toEnum(), Enum(63));

	// invalid combination of output and input
	EXPECT_THROW(CrossbarNodeOnDLS(output, CrossbarInputOnDLS(2)), std::domain_error);
}

TEST(PADIBusOnDLS, toCrossbarOutputOnDLS)
{
	auto bus = PADIBusOnDLS(PADIBusOnPADIBusBlock(2), PADIBusBlockOnDLS::bottom);
	EXPECT_EQ(bus.toCrossbarOutputOnDLS(), CrossbarOutputOnDLS(6));
}

TEST(BackgroundSpikeSourceOnDLS, toCrossbarInputOnDLS)
{
	auto source = BackgroundSpikeSourceOnDLS(5);
	EXPECT_EQ(source.toCrossbarInputOnDLS(), CrossbarInputOnDLS(17));
}

TEST(BackgroundSpikeSourceOnDLS, toCrossbarL2OutputOnDLS)
{
	auto source = BackgroundSpikeSourceOnDLS(5);
	EXPECT_EQ(source.toCrossbarL2OutputOnDLS(), CrossbarL2OutputOnDLS(1));
}

TEST(CADCSampleQuadOnSynram, Size)
{
	EXPECT_EQ(
	    CADCSampleQuadOnSynram::size,
	    CADCChannelType::size * CADCReadoutType::size * SynapseQuadOnSynram::size);

	EXPECT_EQ(CADCSampleQuadOnSynram::min, 0);

	EXPECT_EQ(
	    CADCSampleQuadOnSynram::max,
	    CADCChannelType::size * CADCReadoutType::size * SynapseQuadOnSynram::size - 1);

	size_t count = 0;
	for (auto coord : iter_all<CADCSampleQuadOnSynram>()) {
		static_cast<void>(coord);
		count++;
	}
	EXPECT_EQ(count++, CADCSampleQuadOnSynram::size);
}

TEST(CADCSampleQuadOnDLS, Size)
{
	EXPECT_EQ(
	    CADCSampleQuadOnDLS::size, CADCChannelType::size * CADCReadoutType::size *
	                                   SynapseQuadOnSynram::size * SynramOnDLS::size);

	EXPECT_EQ(CADCSampleQuadOnDLS::min, 0);

	EXPECT_EQ(
	    CADCSampleQuadOnDLS::max, CADCChannelType::size * CADCReadoutType::size *
	                                      SynapseQuadOnSynram::size * SynramOnDLS::size -
	                                  1);

	size_t count = 0;
	for (auto coord : iter_all<CADCSampleQuadOnDLS>()) {
		static_cast<void>(coord);
		count++;
	}
	EXPECT_EQ(count++, CADCSampleQuadOnDLS::size);
}

template <typename T>
class CommonVerticalHalfCoordinateTest : public ::testing::Test
{};

typedef ::testing::Types<
    PPUOnDLS,
    CommonSynramConfigOnDLS,
    SynramOnDLS,
    CADCConfigOnDLS,
    CommonSTPConfigOnDLS,
    CommonPADIBusConfigOnDLS,
    PADIEventOnDLS>
    CommonVerticalHalfCoordinateTypes;

TYPED_TEST_CASE(CommonVerticalHalfCoordinateTest, CommonVerticalHalfCoordinateTypes);

TYPED_TEST(CommonVerticalHalfCoordinateTest, TopBottom)
{
	TypeParam const top = TypeParam::top;
	TypeParam const bottom = TypeParam::bottom;

	EXPECT_EQ(top.toEnum(), 0);
	EXPECT_EQ(bottom.toEnum(), 1);
}

#define HEMISPHERE_COORDINATE(Name) Name,
#define LAST_HEMISPHERE_COORDINATE(Name) Name
typedef ::testing::Types<
#include "halco/hicann-dls/vx/hemisphere.def"
    >
    CommonHemisphereCoordinateTypes;

template <typename T>
class CommonHemisphereCoordinateTest : public ::testing::Test
{};

TYPED_TEST_CASE(CommonHemisphereCoordinateTest, CommonHemisphereCoordinateTypes);

TYPED_TEST(CommonHemisphereCoordinateTest, toOther)
{
	for (auto const coord : iter_all<TypeParam>()) {
// clang-format off
#define HEMISPHERE_COORDINATE(Name)                                                                \
		{                                                                                          \
			auto const other = coord.to##Name();                                                   \
			EXPECT_EQ(other.toEnum(), coord.toEnum());                                             \
		}
// clang-format on
#include "halco/hicann-dls/vx/hemisphere.def"
	}
}

TEST(SynapseDriverOnDLS, Cerealization)
{
	SynapseDriverOnDLS obj1(SynapseDriverOnSynapseDriverBlock(32), SynapseDriverBlockOnDLS(1));
	SynapseDriverOnDLS obj2;

	std::ostringstream ostream;
	{
		cereal::JSONOutputArchive oa(ostream);
		oa(obj1);
	}

	std::istringstream istream(ostream.str());
	{
		cereal::JSONInputArchive ia(istream);
		ia(obj2);
	}
	EXPECT_EQ(obj2, obj1);
}
