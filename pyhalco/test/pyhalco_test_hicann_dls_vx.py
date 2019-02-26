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
    JtagOnDLS                        => linear, iterable
    PllRegisterOnDLS                 => linear, iterable
    AdPllOnDLS                       => linear, iterable
    PllClockOutputBlockOnDLS         => linear, iterable
    PllClockOutputOnDLS              => linear, iterable
    TimerOnDLS                       => linear, iterable
    OmnibusAddress                   => linear
    """

    @staticmethod
    def get_module():
        import pyhalco_hicann_dls_vx
        return pyhalco_hicann_dls_vx

if __name__ == '__main__':
    unittest.main()
