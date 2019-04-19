#!/usr/bin/env python

import unittest
from pyhalco_test_utils import parametrize, PyhalcoTest

@parametrize
class Test_PyhalcoHICANNDLSv2(unittest.TestCase, PyhalcoTest):
    COORDINATES = """
    CapMemCellOnDLS                  => grid, iterable
    CapMemColumnOnDLS                => linear, iterable
    CapMemRowOnDLS                   => linear, iterable
    CapMemOnDLS                      => linear, iterable
    CapMemConfigOnDLS                => linear, iterable
    CommonNeuronConfigOnDLS          => linear, iterable
    CommonSynramConfigOnDLS          => linear, iterable
    ColumnBlockOnDLS                 => linear, iterable
    ColumnCorrelationBlockOnDLS      => linear, iterable
    ColumnCorrelationSwitchOnColumnCorrelationBlock => linear, iterable
    ColumnCorrelationSwitchOnDLS     => linear, iterable
    ColumnCurrentBlockOnDLS      => linear, iterable
    ColumnCurrentSwitchOnColumnCurrentBlock => linear, iterable
    ColumnCurrentSwitchOnDLS         => linear, iterable
    CommonNeuronParameter            => ignore
    DACOnBoard                       => linear, iterable
    NeuronOnDLS                      => linear, iterable
    NeuronParameter                  => ignore
    PPUMemoryBlockOnDLS              => interval, iterable
    PPUMemoryBlockSize               => linear, iterable
    PPUMemoryWordOnDLS               => linear, iterable
    PPUMemoryOnDLS                   => linear, iterable
    PPUStatusRegisterOnDLS           => linear, iterable
    PPUControlRegisterOnDLS          => linear, iterable
    SynapseBlockOnDLS                => grid, iterable
    SynapseDriverOnDLS               => linear, iterable
    SynapseColumnOnDLS               => linear, iterable
    SynapseRowOnDLS                  => linear, iterable
    SynapseOnDLS                     => grid, iterable
    SynapseOnSynapseBlock            => linear, iterable
    SynapseDriverBlockOnDLS          => linear, iterable
    CorrelationConfigOnDLS           => linear, iterable
    RateCounterOnDLS                 => linear, iterable
    RateCounterConfigOnDLS           => linear, iterable
    """

    @staticmethod
    def get_module():
        import pyhalco_hicann_dls_v2
        return pyhalco_hicann_dls_v2

if __name__ == '__main__':
    unittest.main()
