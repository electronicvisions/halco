#!/usr/bin/env python

import unittest
from pyhalco_test_utils import parametrize, PyhalcoTest

@parametrize
class Test_PyhalcoHICANNDLSvx(unittest.TestCase, PyhalcoTest):
    COORDINATES = """
    PPUMemoryWordOnDLS               => linear, iterable
    PPUMemoryWordOnPPU               => linear, iterable
    PPUOnDLS                         => linear, iterable
    ResetChipOnDLS                   => linear, iterable
    JTAGOnDLS                        => linear, iterable
    JTAGPLLRegisterOnDLS             => linear, iterable
    JTAGPhyRegisterOnDLS             => linear, iterable
    PhyBlockOnDLS                    => linear, iterable
    ADPLLOnDLS                       => linear, iterable
    PLLClockOutputOnDLS              => linear, iterable
    PLLOnDLS                         => linear, iterable
    TimerOnDLS                       => linear, iterable
    OmnibusAddress                   => linear
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
    """

    @staticmethod
    def get_module():
        import pyhalco_hicann_dls_vx
        return pyhalco_hicann_dls_vx

if __name__ == '__main__':
    unittest.main()
