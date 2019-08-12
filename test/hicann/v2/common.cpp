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
	AnalogOnDNC,
	AnalogOnHICANN,
	BackgroundGeneratorOnHICANN,
	ChannelOnADC,
	CrossbarSwitchOnHICANN,
	CrossbarSwitchOnCrossbarSwitchRow,
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
	AnanasChannelOnAnanasSlice,
	AnanasGlobal,
	AnanasOnWafer,
	AnanasSliceGlobal,
	AnanasSliceOnAnanas,
	AnanasSliceOnWafer,
	AuxPwrGlobal,
	AuxPwrOnWafer,
	GbitLinkOnHICANN,
	HICANNGlobal,
	HICANNOnDNC,
	HighspeedLinkOnDNC,
	HighspeedLinkOnWafer,
	HICANNOnWafer,
	HLineOnHICANN,
	HLineOnWafer,
	HRepeaterOnHICANN,
	HRepeaterOnWafer,
	IPv4,
	JTAGFrequency,
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
	RepeaterBlockOnWafer,
	RowOnSynapseDriver,
	SendingRepeaterOnHICANN,
	SideHorizontal,
	SideVertical,
	SocketOnWIO,
	SynapseColumnOnHICANN,
	SynapseDriverOnHICANN,
	SynapseDriverOnQuadrant,
	SynapseOnHICANN,
	SynapseOnWafer,
	SynapseRowOnHICANN,
	SynapseRowOnArray,
	SynapseSwitchOnHICANN,
	SynapseSwitchOnSynapseSwitchRow,
	SynapseSwitchRowOnHICANN,
	SynapticInputOnNeuron,
	SynapticInputOnHICANN,
	TriggerOnADC,
	TriggerOnWafer,
	TriggerGlobal,
	TestPortOnRepeaterBlock,
	UDPPort,
	Unique,
	VLineOnHICANN,
	VLineOnWafer,
	VRepeaterOnHICANN,
	VRepeaterOnWafer,
	Wafer,
	WIOOnWafer,
	X,
	Y
> CoordinateTypesNtoZ;
TYPED_TEST_CASE(CommonCoordinateTestNtoZ, CoordinateTypesNtoZ);
#define COMMON_FIXTURE_NAME CommonCoordinateTestAtoM
#include "HALCO_COMMON.cxx"
#undef COMMON_FIXTURE_NAME
#define COMMON_FIXTURE_NAME CommonCoordinateTestNtoZ
#include "HALCO_COMMON.cxx"
#undef COMMON_FIXTURE_NAME

// clang-format on
