#!/usr/bin/env python

import unittest
from pyhalco_test_utils import parametrize, PyhalcoTest

@parametrize
class Test_PyhalcoHICANNDLSvx(unittest.TestCase, PyhalcoTest):
    # clang-format off
    COORDINATES = """
    PerfTestOnFPGA                   => linear, iterable
    PerfTestStatusOnFPGA             => linear, iterable
    PPUMemoryWordOnDLS               => linear, iterable
    PPUMemoryWordOnPPU               => linear, iterable
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
    CommonPhyConfigFPGAOnDLS         => linear, iterable
    CommonPhyConfigChipOnDLS         => linear, iterable
    ADPLLOnDLS                       => linear, iterable
    PLLClockOutputOnDLS              => linear, iterable
    PLLOnDLS                         => linear, iterable
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
    CapMemColumnOnDLS                => linear, iterable
    CapMemRowOnDLS                   => linear, iterable
    CapMemBlockConfigOnDLS           => linear, iterable
    CapMemBlockOnDLS                 => linear, iterable
    CommonNeuronConfigOnDLS          => linear, iterable
    NeuronOnBlock                    => linear, iterable
    """
    # clang-format on
    @staticmethod
    def get_module():
        import pyhalco_hicann_dls_vx
        return pyhalco_hicann_dls_vx

if __name__ == '__main__':
    unittest.main()
