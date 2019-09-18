#!/usr/bin/env python

import unittest
from pyhalco_test_utils import parametrize, PyhalcoTest

@parametrize
class Test_PyhalcoHICANNDLSvx(unittest.TestCase, PyhalcoTest):
    # clang-format off
    COORDINATES = """
    EventOutputOnNeuronBackendBlock  => linear, iterable
    DACControlBlockOnBoard           => linear, iterable
    DACChannelBlockOnBoard           => linear, iterable
    CADCSampleRowOnDLS               => iterable
    SpikePackFromFPGAOnDLS           => linear, iterable
    MADCSamplePackFromFPGAOnDLS      => linear, iterable
    NullPayloadReadableOnFPGA        => linear, iterable
    I2CIdRegisterOnBoard             => linear, iterable
    I2CINA219RoRegisterOnINA219      => linear, iterable
    I2CINA219RwRegisterOnINA219      => linear, iterable
    INA219OnBoard                    => linear, iterable
    I2CINA219RoRegisterOnBoard       => linear, iterable
    I2CINA219RwRegisterOnBoard       => linear, iterable
    HicannARQStatusOnFPGA            => linear, iterable
    BackgroundSpikeSourceOnDLS       => linear, iterable
    CrossbarOutputConfigOnDLS        => linear, iterable
    CrossbarOutputOnDLS              => linear, iterable
    CrossbarL2OutputOnDLS            => linear, iterable
    CrossbarInputOnDLS               => linear, iterable
    CrossbarNodeOnDLS                => grid, iterable
    PerfTestOnFPGA                   => linear, iterable
    PerfTestStatusOnFPGA             => linear, iterable
    SpikePack1ToChipOnDLS            => linear, iterable
    SpikePack2ToChipOnDLS            => linear, iterable
    SpikePack3ToChipOnDLS            => linear, iterable
    SystimeSyncOnFPGA                => linear, iterable
    SystimeSyncBaseOnDLS             => linear, iterable
    CADCConfigOnDLS                  => linear, iterable
    PPUMemoryWordOnDLS               => linear, iterable
    PPUMemoryWordOnPPU               => linear, iterable
    PPUMemoryBlockOnDLS              => iterable
    PPUMemoryBlockOnPPU              => interval, iterable
    PPUMemoryOnDLS                   => linear, iterable
    PPUMemoryOnPPU                   => linear, iterable
    PPUMemoryBlockSize               => linear, iterable
    PPUControlRegisterOnPPU          => linear, iterable
    PPUControlRegisterOnDLS          => linear, iterable
    PPUStatusRegisterOnPPU           => linear, iterable
    PPUStatusRegisterOnDLS           => linear, iterable
    PPUOnDLS                         => linear, iterable
    ResetChipOnDLS                   => linear, iterable
    ResetJTAGTapOnDLS                => linear, iterable
    JTAGClockScalerOnDLS             => linear, iterable
    JTAGIdCodeOnDLS                  => linear, iterable
    JTAGPLLRegisterOnDLS             => linear, iterable
    JTAGPhyRegisterOnDLS             => linear, iterable
    PhyConfigFPGAOnDLS               => linear, iterable
    PhyConfigChipOnDLS               => linear, iterable
    PhyStatusOnFPGA                  => linear, iterable
    CommonPhyConfigFPGAOnDLS         => linear, iterable
    CommonPhyConfigChipOnDLS         => linear, iterable
    ADPLLOnDLS                       => linear, iterable
    PLLClockOutputOnDLS              => linear, iterable
    PLLClockOutputBlockOnDLS         => linear, iterable
    PLLSelfTestOnDLS                 => linear, iterable
    PLLSelfTestStatusOnDLS           => linear, iterable
    TimerOnDLS                       => linear, iterable
    OmnibusChipOverJTAGAddress       => linear
    OmnibusChipAddress               => linear
    OmnibusFPGAAddress               => linear
    ShiftRegisterOnBoard             => linear, iterable
    SPIShiftRegisterOnBoard          => linear, iterable
    SPIDACDataRegisterOnBoard        => linear, iterable
    SPIDACControlRegisterOnBoard     => linear, iterable
    SPIDACDataRegisterOnDAC          => linear, iterable
    SPIDACControlRegisterOnDAC       => linear, iterable
    ADCSourceOnBoard                 => linear, iterable
    LEDOnBoard                       => linear, iterable
    VDDOnBoard                       => linear, iterable
    DACOnBoard                       => linear, iterable
    DACChannelOnBoard                => linear, iterable
    DACChannelOnDAC                  => linear, iterable
    ADCOnBoard                       => linear, iterable
    CapMemCellOnDLS                  => iterable
    CapMemCellOnCapMemBlock          => grid, iterable
    CapMemColumnOnCapMemBlock        => linear, iterable
    CapMemRowOnCapMemBlock           => linear, iterable
    CapMemBlockConfigOnDLS           => linear, iterable
    CapMemBlockOnDLS                 => linear, iterable
    CommonNeuronConfigOnDLS          => linear, iterable
    NeuronBackendConfigBlockOnDLS    => linear, iterable
    NeuronConfigBlockOnDLS           => linear, iterable
    NeuronConfigOnNeuronConfigBlock  => linear, iterable
    NeuronConfigOnDLS                => iterable
    NeuronBackendConfigOnNeuronBackendConfigBlock => linear, iterable
    NeuronBackendConfigOnDLS         => iterable
    NeuronResetOnNeuronResetBlock    => linear, iterable
    NeuronResetBlockOnDLS            => linear, iterable
    NeuronResetOnDLS                 => iterable
    NeuronLabel                      => linear, iterable
    SPL1Address                      => linear, iterable
    CommonSynramConfigOnDLS          => linear, iterable
    FPGADeviceDNAOnFPGA              => linear, iterable
    SynapseQuadColumnOnDLS          => linear, iterable
    SynapseRowOnSynram               => linear, iterable
    SynramOnDLS                      => linear, iterable
    SynapseQuadOnSynram             => grid, iterable
    SynapseQuadOnDLS                => iterable
    SynapseOnSynapseRow             => linear, iterable
    SynapseRowOnDLS                 => linear, iterable
    SynapseDriverOnSynapseDriverBlock => linear, iterable
    SynapseDriverBlockOnDLS           => linear, iterable
    SynapseDriverOnDLS                => linear, iterable
    CommonSynapseDriverConfigOnDLS    => linear, iterable
    CommonPADIBusConfigOnDLS          => linear,iterable
    CommonSTPConfigOnDLS              => linear,iterable
    PADIBusBlockOnDLS                 => linear,iterable
    PADIBusOnDLS                      => linear,iterable
    PADIBusOnPADIBusBlock             => linear,iterable
    PADIEventOnDLS                    => linear,iterable
    ColumnCorrelationQuadOnSynram   => linear, iterable
    ColumnCurrentQuadOnSynram       => linear, iterable
    ColumnCorrelationQuadOnDLS      => linear, iterable
    ColumnCurrentQuadOnDLS          => linear, iterable
    CADCChannelType                   => linear,iterable
    CADCReadoutType                   => linear,iterable
    CADCSampleQuadUnspecifiedReadoutOnSynram => iterable
    CADCSampleQuadOnSynram            => iterable
    CADCSampleQuadOnDLS               => iterable
    CADCChannelColumnOnSynram         => linear,iterable
    CADCChannelConfigOnSynram         => iterable
    CADCChannelConfigOnDLS            => iterable
    EntryOnQuad                       => linear, iterable
    """
    # clang-format on
    @staticmethod
    def get_module():
        import pyhalco_hicann_dls_vx
        return pyhalco_hicann_dls_vx

if __name__ == '__main__':
    unittest.main()
