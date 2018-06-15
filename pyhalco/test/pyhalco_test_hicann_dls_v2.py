#!/usr/bin/env python

import unittest
from pyhalco_test_utils import parametrize, PyhalcoTest

@parametrize
class Test_PyhalcoHICANNDLSv2(unittest.TestCase, PyhalcoTest):
    COORDINATES = """
    CapMemCellOnDLS                  => grid, iterable
    CapMemColumnOnDLS                => linear, iterable
    CapMemRowOnDLS                   => linear, iterable
    ColumnBlockOnDLS                 => linear, iterable
    ColumnCorrelationSwitchOnColumnBlock => linear, iterable
    ColumnCorrelationSwitchOnDLS     => linear, iterable
    ColumnCurrentSwitchOnColumnBlock => linear, iterable
    ColumnCurrentSwitchOnDLS         => linear, iterable
    CommonNeuronParameter            => ignore
    DACOnBoard                       => linear, iterable
    NeuronOnDLS                      => linear, iterable
    NeuronParameter                  => ignore
    PPUMemoryWordOnDLS               => linear, iterable
    SynapseBlockOnDLS                => grid, iterable
    SynapseDriverOnDLS               => linear, iterable
    SynapseOnDLS                     => grid, iterable
    SynapseOnSynapseBlock            => linear, iterable
    """

    @staticmethod
    def get_module():
        import pyhalco_hicann_dls_v2
        return pyhalco_hicann_dls_v2

if __name__ == '__main__':
    unittest.main()
