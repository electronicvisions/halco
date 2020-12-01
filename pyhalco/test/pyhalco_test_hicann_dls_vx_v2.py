#!/usr/bin/env python

import unittest
from pyhalco_test_utils import parametrize, PyhalcoTest


@parametrize
class Test_PyhalcoHICANNDLSvx(unittest.TestCase, PyhalcoTest):
    COORDINATES = """
    CADCOffsetSRAMTimingConfigOnDLS => linear,iterable
    NeuronSRAMTimingConfigOnDLS => linear,iterable
    NeuronBackendSRAMTimingConfigOnDLS => linear,iterable
    SynapseDriverSRAMTimingConfigOnDLS => linear,iterable
    ChipOnDLS => linear,iterable
    DLSGlobal => linear,iterable
    HemisphereOnDLS => linear,iterable
    HemisphereGlobal => linear,iterable
    NeuronEventOutputOnNeuronBackendBlock => linear,iterable
    NeuronEventOutputOnDLS => iterable
    DACControlBlockOnBoard => linear,iterable
    DACChannelBlockOnBoard => linear,iterable
    CADCSampleRowOnDLS => iterable
    SpikePackFromFPGAOnDLS => linear,iterable
    MADCSamplePackFromFPGAOnDLS => linear,iterable
    NullPayloadReadableOnFPGA => linear,iterable
    EventRecordingConfigOnFPGA => linear,iterable
    I2CIdRegisterOnBoard => linear,iterable
    I2CINA219RoRegisterOnINA219 => linear,iterable
    I2CINA219RwRegisterOnINA219 => linear,iterable
    I2CTCA9554RoRegisterOnTCA9554 => linear,iterable
    I2CTCA9554RwRegisterOnTCA9554 => linear,iterable
    TCA9554OnBoard => linear,iterable
    TCA9554ChannelOnBoard => linear,iterable
    TCA9554ConfigOnBoard => linear,iterable
    TCA9554InputsOnBoard => linear,iterable
    INA219OnBoard => linear,iterable
    INA219ConfigOnBoard => linear,iterable
    INA219StatusOnBoard => linear,iterable
    I2CINA219RoRegisterOnBoard => linear,iterable
    I2CINA219RwRegisterOnBoard => linear,iterable
    I2CTCA9554RoRegisterOnBoard => linear,iterable
    I2CTCA9554RwRegisterOnBoard => linear,iterable
    AD5252OnBoard => linear,iterable
    AD5252ChannelOnAD5252 => linear,iterable
    AD5252ChannelOnBoard => linear,iterable
    I2CAD5252RwRegisterOnAD5252Channel => linear,iterable
    I2CAD5252RwRegisterOnBoard => linear,iterable
    AD5252ChannelConfigOnBoard => linear,iterable
    AD5252ChannelConfigPersistentOnBoard => linear,iterable
    HicannARQStatusOnFPGA => linear,iterable
    BackgroundSpikeSourceOnDLS => linear,iterable
    CrossbarOnDLS => linear,iterable
    CrossbarOutputConfigOnDLS => linear,iterable
    CrossbarOutputOnDLS => linear,iterable
    CrossbarL2OutputOnDLS => linear,iterable
    CrossbarInputOnDLS => linear,iterable
    CrossbarNodeOnDLS => grid,iterable
    PerfTestOnFPGA => linear,iterable
    PerfTestStatusOnFPGA => linear,iterable
    SpikePack1ToChipOnDLS => linear,iterable
    SpikePack2ToChipOnDLS => linear,iterable
    SpikePack3ToChipOnDLS => linear,iterable
    SystimeSyncOnFPGA => linear,iterable
    SystimeSyncBaseOnDLS => linear,iterable
    CADCConfigOnDLS => linear,iterable
    ExternalPPUMemoryByteOnFPGA => linear, iterable
    ExternalPPUMemoryBlockSize => linear, iterable
    ExternalPPUMemoryBlockOnFPGA => iterable
    PPUMemoryWordOnDLS => linear,iterable
    PPUMemoryWordOnPPU => linear,iterable
    PPUMemoryBlockOnDLS => iterable
    PPUMemoryBlockOnPPU => interval,iterable
    PPUMemoryOnDLS => linear,iterable
    PPUMemoryBlockSize => linear,iterable
    PPUControlRegisterOnDLS => linear,iterable
    PPUStatusRegisterOnDLS => linear,iterable
    PPUOnDLS => linear,iterable
    ResetChipOnDLS => linear,iterable
    ResetJTAGTapOnDLS => linear,iterable
    JTAGClockScalerOnDLS => linear,iterable
    JTAGIdCodeOnDLS => linear,iterable
    JTAGPLLRegisterOnDLS => linear,iterable
    JTAGPhyRegisterOnDLS => linear,iterable
    PhyConfigFPGAOnDLS => linear,iterable
    PhyConfigChipOnDLS => linear,iterable
    PhyStatusOnFPGA => linear,iterable
    CommonPhyConfigFPGAOnDLS => linear,iterable
    CommonPhyConfigChipOnDLS => linear,iterable
    ADPLLOnDLS => linear,iterable
    PLLClockOutputOnDLS => linear,iterable
    PLLClockOutputBlockOnDLS => linear,iterable
    PLLSelfTestOnDLS => linear,iterable
    PLLSelfTestStatusOnDLS => linear,iterable
    TimerOnDLS => linear,iterable
    OmnibusChipOverJTAGAddress => linear
    OmnibusAddress => linear
    ShiftRegisterOnBoard => linear,iterable
    SPIShiftRegisterOnBoard => linear,iterable
    SPIDACDataRegisterOnBoard => linear,iterable
    SPIDACControlRegisterOnBoard => linear,iterable
    SPIDACDataRegisterOnDAC => linear,iterable
    SPIDACControlRegisterOnDAC => linear,iterable
    ADCSourceOnBoard => linear,iterable
    LEDOnBoard => linear,iterable
    VDDOnBoard => linear,iterable
    DACOnBoard => linear,iterable
    DACChannelOnBoard => linear,iterable
    DACChannelOnDAC => linear,iterable
    ADCOnBoard => linear,iterable
    CapMemCellOnDLS => iterable
    CapMemCellOnCapMemBlock => grid,iterable
    CapMemColumnOnCapMemBlock => linear,iterable
    CapMemRowOnCapMemBlock => linear,iterable
    CapMemBlockConfigOnDLS => linear,iterable
    CapMemBlockOnHemisphere => linear,iterable
    CapMemBlockOnDLS => linear,iterable
    CommonNeuronBackendConfigOnDLS => linear,iterable
    NeuronBackendConfigBlockOnDLS => linear,iterable
    NeuronRowOnDLS => linear,iterable
    NeuronColumnOnDLS => linear,iterable
    AtomicNeuronOnDLS => grid,iterable
    NeuronConfigBlockOnDLS => linear,iterable
    NeuronConfigOnNeuronConfigBlock => linear,iterable
    NeuronConfigOnDLS => iterable
    NeuronBackendConfigOnNeuronBackendConfigBlock => linear,iterable
    NeuronBackendConfigOnDLS => iterable
    NeuronResetOnNeuronResetBlock => linear,iterable
    NeuronResetBlockOnDLS => linear,iterable
    NeuronResetOnDLS => iterable
    SpikeCounterReadOnSpikeCounterReadBlock => linear,iterable
    SpikeCounterReadBlockOnDLS => linear,iterable
    SpikeCounterReadOnDLS => iterable
    SpikeCounterResetOnSpikeCounterResetBlock => linear,iterable
    SpikeCounterResetBlockOnDLS => linear,iterable
    SpikeCounterResetOnDLS => iterable
    NeuronLabel => linear,iterable
    SPL1Address => linear,iterable
    CommonSynramConfigOnDLS => linear,iterable
    FPGADeviceDNAOnFPGA => linear,iterable
    SynapseQuadColumnOnDLS => linear,iterable
    SynapseRowOnSynram => linear,iterable
    SynapseRowOnSynapseDriver => linear, iterable
    SynramOnDLS => linear,iterable
    SynapseQuadOnSynram => grid,iterable
    SynapseQuadOnDLS => iterable
    SynapseWeightQuadOnDLS => iterable
    SynapseLabelQuadOnDLS => iterable
    SynapseCorrelationCalibQuadOnDLS => iterable
    SynapseOnSynapseRow => linear,iterable
    SynapseRowOnDLS => linear,iterable
    SynapseWeightRowOnDLS => linear,iterable
    SynapseLabelRowOnDLS => linear,iterable
    SynapseCorrelationCalibRowOnDLS => linear,iterable
    SynapseWeightMatrixOnDLS => linear,iterable
    SynapseLabelMatrixOnDLS => linear,iterable
    SynapseCorrelationCalibMatrixOnDLS => linear,iterable
    SynapseDriverOnSynapseDriverBlock => linear,iterable
    SynapseDriverOnPADIBus => linear,iterable
    SynapseDriverBlockOnDLS => linear,iterable
    SynapseDriverOnDLS => linear,iterable
    CommonSynapseDriverConfigOnDLS => linear,iterable
    CommonPADIBusConfigOnDLS => linear,iterable
    CommonSTPConfigOnDLS => linear,iterable
    PADIBusBlockOnDLS => linear,iterable
    PADIBusOnDLS => linear,iterable
    PADIBusOnPADIBusBlock => linear,iterable
    PADIEventOnDLS => linear,iterable
    ColumnCorrelationQuadOnSynram => linear,iterable
    ColumnCurrentQuadOnSynram => linear,iterable
    ColumnCorrelationQuadOnDLS => linear,iterable
    ColumnCurrentQuadOnDLS => linear,iterable
    CADCChannelType => linear,iterable
    CADCReadoutType => linear,iterable
    CADCSamplesOnDLS => linear, iterable
    WaitUntilOnFPGA => linear, iterable
    BarrierOnFPGA => linear, iterable
    PollingOmnibusBlockOnFPGA => linear, iterable
    PollingOmnibusBlockConfigOnFPGA => linear, iterable
    CADCOnDLS => linear, iterable
    CADCSampleQuadUnspecifiedReadoutOnSynram => iterable
    CADCSampleQuadOnSynram => iterable
    CADCSampleQuadOnDLS => iterable
    CADCChannelColumnOnSynram => linear,iterable
    CADCChannelConfigOnSynram => iterable
    CADCChannelConfigOnDLS => iterable
    EntryOnQuad => linear,iterable
    SynapticInputOnNeuron => linear,iterable
    MADCControlOnDLS => linear,iterable
    MADCConfigOnDLS => linear,iterable
    SynapseBiasSelectionOnDLS => linear,iterable
    ReferenceGeneratorConfigOnDLS => linear,iterable
    PadMultiplexerConfigOnDLS => linear,iterable
    ReadoutSourceSelectionOnDLS => linear,iterable
    SourceMultiplexerOnReadoutSourceSelection => linear,iterable
    CorrelationResetOnDLS => iterable
    NeuronResetQuadOnDLS => iterable
    CommonCorrelationConfigOnDLS => linear,iterable
    BlockPostPulseOnDLS => linear,iterable
    CorrelationResetRowOnDLS => iterable
    Coordinate => ignore
    """

    @staticmethod
    def get_module():
        import pyhalco_hicann_dls_vx_v2
        return pyhalco_hicann_dls_vx_v2


if __name__ == '__main__':
    unittest.main()