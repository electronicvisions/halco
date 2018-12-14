#!/usr/bin/env python

import unittest
from pyhalco_test_utils import parametrize, PyhalcoTest

@parametrize
class Test_PyhalcoHICANNv2(unittest.TestCase, PyhalcoTest):
    COORDINATES = """
    AnalogOnHICANN        => linear, iterable
    BackgroundGeneratorOnHICANN  =>  linear, iterable
    ChannelOnADC          => linear, iterable
    DNCGlobal             =>
    DNCMergerOnHICANN     => linear, iterable
    DNCMergerOnWafer      =>
    DNCOnFPGA             => linear, iterable
    DNCOnWaferEnum        => ignore
    DNCOnWaferGrid        => ignore
    DNCOnWafer            => grid, iterable
    FGBlockOnHICANN       => grid, iterable
    FGCellOnFGBlock       => grid, iterable
    FGRowOnFGBlock        => linear, iterable
    FPGAGlobal            =>
    FPGAOnWafer           => linear, iterable
    ANANASGlobal          =>
    ANANASOnWafer         => linear, iterable
    GbitLinkOnHICANN      => linear, iterable
    HICANNGlobal          =>
    HICANNOnWaferEnum     => ignore
    HICANNOnWaferGrid     => ignore
    HICANNOnDNC           => grid, iterable
    HighspeedLinkOnDNC    => iterable
    HICANNOnWafer         => grid, iterable
    HLineOnHICANN         => linear, iterable
    HRepeaterOnHICANN     => grid, iterable
    HRepeaterOnWafer      =>
    Host                  =>
    IPv4                  =>
    Merger0OnHICANN       => linear, iterable
    Merger1OnHICANN       => linear, iterable
    Merger2OnHICANN       => linear, iterable
    Merger3OnHICANN       => linear, iterable
    NeuronBlockGlobal     =>
    NeuronBlockOnHICANN   => linear, iterable
    NeuronBlockOnWafer    =>
    NeuronGlobal          =>
    NeuronOnFGBlock       => linear, iterable
    NeuronOnHICANN        => grid, iterable
    NeuronOnNeuronBlock   => grid, iterable
    NeuronOnQuad          => grid, iterable
    NeuronOnWafer         =>
    PMU                   =>
    PowerCoordinate       => linear, iterable
    OutputBufferOnHICANN  => ignore
    QuadOnHICANN          => linear, iterable
    QuadrantOnHICANN      => grid, iterable
    TestPortOnRepeaterBlock => linear, iterable
    RepeaterBlockOnHICANN => grid, iterable
    RowOnSynapseDriver    => linear, iterable
    SendingRepeaterOnHICANN => linear, iterable
    SynapseArrayOnHICANN  => linear, iterable
    SynapseColumnOnHICANN => linear, iterable
    SynapseDriverOnHICANN => grid, iterable
    SynapseDriverOnQuadrant => linear, iterable
    SynapseDriverOnWafer  =>
    SynapseOnHICANN       => grid, iterable
    SynapseOnWafer        =>
    SynapseRowOnHICANN    => linear, iterable
    SynapseSwitchOnHICANN => grid, iterable
    SynapseSwitchRowOnHICANN => grid, iterable
    SynapseSwitchRowOnWafer =>
    SynapticInputOnNeuron => linear, iterable
    TriggerOnADC          => linear, iterable
    TriggerOnWafer        => linear, iterable
    TriggerGlobal         =>
    UDPPort               => linear
    TCPPort               => linear
    VLineOnHICANN         => linear, iterable
    VRepeaterOnHICANN     => grid, iterable
    VRepeaterOnWafer      =>
    Wafer                 => linear
    BSSWafer              => ignore
    CubeSetup             => ignore
    FACETSWafer           => ignore
    SetupType             => ignore
    VSetup                => ignore
    """

    @staticmethod
    def get_module():
        import pyhalco_hicann_v2
        return pyhalco_hicann_v2

    def test_kintexVsVirtex(self):
        """Tests ranges of FPGAGlobal coordinate

        for Wafer 0..2 the maximum FPGA coordinate is 11, the FPGAGlobal will throw if an
        FPGAOnWafer larger than 11 is combinend with Wafer 0..2
        """

        import pyhalco_hicann_v2
        x = pyhalco_hicann_v2.FPGAOnWafer(12)
        for w in [0, 1, 2]:
            y = pyhalco_hicann_v2.Wafer(w)
            self.assertRaises(RuntimeError, pyhalco_hicann_v2.FPGAGlobal, x, y)
        for w in range(3, 10):
            y = pyhalco_hicann_v2.Wafer(w)
            try:
                pyhalco_hicann_v2.FPGAGlobal(x, y)
            except:
                self.fail("FPGAGlobal(%s, %s) should not raise" % (x, y))

    def test_implicit_conversion(self):
        import pyhalco_hicann_v2 as C
        dnc = C.DNCMergerOnHICANN(5)
        link = C.GbitLinkOnHICANN(dnc)
        dnc_ = C.DNCMergerOnHICANN(link)
        self.assertEqual(5, link.value())
        self.assertEqual(5, dnc_.value())

    def test_format_helper(self):
        import pyhalco_hicann_v2 as C
        from pyhalco_common import Enum

        w = C.Wafer(2)
        self.assertEqual(C.short_format(w),  "W002")

        h = C.HICANNOnWafer(Enum(3))
        self.assertEqual(C.short_format(h),  "H003")

        hg = C.HICANNGlobal(h,w)
        self.assertEqual(C.short_format(hg), "W002H003")

        f = C.FPGAOnWafer(Enum(4))
        self.assertEqual(C.short_format(f),  "F004")

        fg = C.FPGAGlobal(f,w)
        self.assertEqual(C.short_format(fg), "W002F004")

        hr = C.HRepeaterOnHICANN(Enum(5))
        self.assertEqual(C.short_format(hr), "HR005")

        vr = C.VRepeaterOnHICANN(Enum(6))
        self.assertEqual(C.short_format(vr), "VR006")

        hl = C.HLineOnHICANN(Enum(5))
        self.assertEqual(C.short_format(hl), "HL005")

        vl = C.VLineOnHICANN(Enum(6))
        self.assertEqual(C.short_format(vl), "VL006")

    def test_synapseswitchrow_driver(self):
        import pyhalco_hicann_v2 as C
        from pyhalco_common import Enum, left, Y

        hicann = C.HICANNOnWafer(Enum(5))
        left_hicann = C.HICANNOnWafer(Enum(4))
        row = C.SynapseSwitchRowOnWafer(C.SynapseSwitchRowOnHICANN(left, Y(0)), hicann)

        driver = row.toSynapseDriverOnWafer()
        self.assertEqual(driver.toHICANNOnWafer(), left_hicann)

if __name__ == '__main__':
    unittest.main()
