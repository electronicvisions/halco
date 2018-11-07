#include <gtest/gtest.h>

#include <sstream>

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/nvp.hpp>

#include "halco/hicann/v2/coordinates.h"

using namespace halco::common;
using namespace halco::hicann::v2;

// clang-format off

template<typename T>
class CommonCoordinateTestAtoM : public ::testing::Test {};
template<typename T>
class CommonCoordinateTestNtoZ : public ::testing::Test {};

typedef ::testing::Types<
	AnalogOnHICANN,
	BackgroundGeneratorOnHICANN,
	ChannelOnADC,
	DNCGlobal,
	DNCMergerOnHICANN,
	DNCMergerOnWafer,
	DNCOnFPGA,
	DNCOnWafer,
	Direction,
	Enum,
	FGBlockOnHICANN,
	FGCellOnFGBlock,
	FGRowOnFGBlock,
	FPGAGlobal,
	FPGAOnWafer,
	ANANASGlobal,
	ANANASOnWafer,
	GbitLinkOnHICANN,
	HICANNGlobal,
	HICANNOnDNC,
	HICANNOnHS,
	HICANNOnWafer,
	HLineOnHICANN,
	HRepeaterOnHICANN,
	HRepeaterOnWafer,
	IPv4,
	Merger0OnHICANN,
	Merger1OnHICANN,
	Merger2OnHICANN,
	Merger3OnHICANN
> CoordinateTypesAtoM;
TYPED_TEST_CASE(CommonCoordinateTestAtoM, CoordinateTypesAtoM);

typedef ::testing::Types<
	NeuronBlockGlobal,
	NeuronBlockOnHICANN,
	NeuronBlockOnWafer,
	NeuronGlobal,
	NeuronOnFGBlock,
	NeuronOnHICANN,
	NeuronOnNeuronBlock,
	NeuronOnQuad,
	NeuronOnWafer,
	Orientation,
	Parity,
	QuadOnHICANN,
	QuadrantOnHICANN,
	RepeaterBlockOnHICANN,
	RowOnSynapseDriver,
	SendingRepeaterOnHICANN,
	SideHorizontal,
	SideVertical,
	SynapseColumnOnHICANN,
	SynapseDriverOnHICANN,
	SynapseDriverOnQuadrant,
	SynapseOnHICANN,
	SynapseOnWafer,
	SynapseRowOnHICANN,
	SynapseSwitchOnHICANN,
	SynapseSwitchRowOnHICANN,
	SynapticInputOnNeuron,
	TriggerOnADC,
	TriggerOnWafer,
	TriggerGlobal,
	TestPortOnRepeaterBlock,
	UDPPort,
	Unique,
	VLineOnHICANN,
	VRepeaterOnHICANN,
	VRepeaterOnWafer,
	Wafer,
	X,
	Y
> CoordinateTypesNtoZ;
TYPED_TEST_CASE(CommonCoordinateTestNtoZ, CoordinateTypesNtoZ);
#define COMMON_FIXTURE_NAME CommonCoordinateTestAtoM
#include "test/HALCO_COMMON.cxx"
#undef COMMON_FIXTURE_NAME
#define COMMON_FIXTURE_NAME CommonCoordinateTestNtoZ
#include "test/HALCO_COMMON.cxx"
#undef COMMON_FIXTURE_NAME

// clang-format on
