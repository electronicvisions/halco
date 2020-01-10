#!/usr/bin/env python

import unittest
from pyhalco_test_utils import parametrize, PyhalcoTest

@parametrize
class Test_PyhalcoHICANNv2(unittest.TestCase, PyhalcoTest):
    COORDINATES = """
    AnalogOnHICANN        => linear, iterable
    BackgroundGeneratorOnHICANN  =>  linear, iterable
    ChannelOnADC          => linear, iterable
    CrossbarSwitchOnHICANN => grid, iterable
    CrossbarSwitchOnCrossbarSwitchRow => grid, iterable
    DNCGlobal             =>
    DNCMergerOnHICANN     => linear, iterable
    DNCMergerOnWafer      => iterable
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
    AuxPwrGlobal          =>
    AuxPwrOnWafer         => linear, iterable
    GbitLinkOnHICANN      => linear, iterable
    HICANNGlobal          =>
    HICANNOnWaferEnum     => ignore
    HICANNOnWaferGrid     => ignore
    HICANNOnDNC           => grid, iterable
    HighspeedLinkOnDNC    => iterable
    HighspeedLinkOnWafer  => iterable
    HICANNOnWafer         => grid, iterable
    HLineOnHICANN         => linear, iterable
    HLineOnWafer          => iterable
    HRepeaterOnHICANN     => grid, iterable
    HRepeaterOnWafer      => iterable
    Host                  =>
    IPv4                  =>
    JTAGFrequency         =>
    Merger0OnHICANN       => linear, iterable
    Merger1OnHICANN       => linear, iterable
    Merger2OnHICANN       => linear, iterable
    Merger3OnHICANN       => linear, iterable
    NeuronBlockGlobal     =>
    NeuronBlockOnHICANN   => linear, iterable
    NeuronBlockOnWafer    => iterable
    NeuronGlobal          =>
    NeuronOnFGBlock       => linear, iterable
    NeuronOnHICANN        => grid, iterable
    NeuronOnNeuronBlock   => grid, iterable
    NeuronOnQuad          => grid, iterable
    NeuronOnWafer         => iterable
    PMU                   =>
    PowerCoordinate       => linear, iterable
    OutputBufferOnHICANN  => ignore
    QuadOnHICANN          => linear, iterable
    QuadrantOnHICANN      => grid, iterable
    TestPortOnRepeaterBlock => linear, iterable
    RepeaterBlockOnHICANN => grid, iterable
    RepeaterBlockOnWafer  => iterable
    RowOnSynapseDriver    => linear, iterable
    SendingRepeaterOnHICANN => linear, iterable
    SynapseArrayOnHICANN  => linear, iterable
    SynapseColumnOnHICANN => linear, iterable
    SynapseDriverOnHICANN => grid, iterable
    SynapseDriverOnQuadrant => linear, iterable
    SynapseDriverOnWafer  => iterable
    SynapseOnHICANN       => grid, iterable
    SynapseOnWafer        =>
    SynapseRowOnHICANN    => linear, iterable
    SynapseRowOnArray     => linear, iterable
    SynapseSwitchOnHICANN => grid, iterable
    SynapseSwitchOnSynapseSwitchRow => grid, iterable
    SynapseSwitchRowOnHICANN => grid, iterable
    SynapseSwitchRowOnWafer => iterable
    SynapticInputOnNeuron => linear, iterable
    SynapticInputOnHICANN => linear, iterable
    TriggerOnADC          => linear, iterable
    TriggerOnWafer        => linear, iterable
    TriggerGlobal         =>
    UDPPort               => linear
    TCPPort               => linear
    VLineOnHICANN         => linear, iterable
    VLineOnWafer          => iterable
    VRepeaterOnHICANN     => grid, iterable
    VRepeaterOnWafer      => iterable
    Wafer                 => linear
    BSSWafer              => ignore
    CubeSetup             => ignore
    FACETSWafer           => ignore
    SetupType             => ignore
    VSetup                => ignore
    """

    # remark: JTAGFrequency is iterable and linear but we skip tests as the range is large and
    #         takes allot of time

    @staticmethod
    def get_module():
        import pyhalco_hicann_v2
        return pyhalco_hicann_v2

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
        self.assertEqual(C.to_string(w),  "W002")
        self.assertEqual(C.from_string("W002"), w)
        self.assertEqual(C.from_string("W02"), w)
        self.assertEqual(C.from_string("W2"), w)

        a = C.ANANASOnWafer(Enum(1))
        self.assertEqual(C.short_format(a), "A1")
        self.assertEqual(C.to_string(a), "A1")
        self.assertEqual(C.from_string("A1"), a)

        ag = C.ANANASGlobal(a, w)
        self.assertEqual(C.short_format(ag), "W002A1")
        self.assertEqual(C.to_string(ag), "W002A1")
        self.assertEqual(C.from_string("W002A1"), ag)
        self.assertEqual(C.from_string("W02A1"), ag)
        self.assertEqual(C.from_string("W2A1"), ag)

        a = C.AuxPwrOnWafer(Enum(1))
        self.assertEqual(C.short_format(a), "AP1")
        self.assertEqual(C.to_string(a), "AP1")
        self.assertEqual(C.from_string("AP1"), a)

        apg = C.AuxPwrGlobal(a, w)
        self.assertEqual(C.short_format(apg), "W002AP1")
        self.assertEqual(C.to_string(apg), "W002AP1")
        self.assertEqual(C.from_string("W002AP1"), apg)
        self.assertEqual(C.from_string("W02AP1"), apg)
        self.assertEqual(C.from_string("W2AP1"), apg)

        h = C.HICANNOnWafer(Enum(3))
        self.assertEqual(C.short_format(h),  "H003")
        self.assertEqual(C.to_string(h),  "H003")
        self.assertEqual(C.from_string("H003"), h)
        self.assertEqual(C.from_string("H03"), h)
        self.assertEqual(C.from_string("H3"), h)

        hg = C.HICANNGlobal(h,w)
        self.assertEqual(C.short_format(hg), "W002H003")
        self.assertEqual(C.to_string(hg), "W002H003")
        self.assertEqual(C.from_string("W002H003"), hg)
        self.assertEqual(C.from_string("W02H03"), hg)
        self.assertEqual(C.from_string("W2H3"), hg)

        f = C.FPGAOnWafer(Enum(4))
        self.assertEqual(C.short_format(f),  "F004")
        self.assertEqual(C.to_string(f),  "F004")
        self.assertEqual(C.from_string("F004"), f)
        self.assertEqual(C.from_string("F04"), f)
        self.assertEqual(C.from_string("F4"), f)

        fg = C.FPGAGlobal(f,w)
        self.assertEqual(C.short_format(fg), "W002F004")
        self.assertEqual(C.to_string(fg), "W002F004")
        self.assertEqual(C.from_string("W002F004"), fg)
        self.assertEqual(C.from_string("W02F04"), fg)
        self.assertEqual(C.from_string("W2F4"), fg)

        t = C.TriggerOnWafer(Enum(1))
        self.assertEqual(C.short_format(t), "T01")
        self.assertEqual(C.to_string(t), "T01")
        self.assertEqual(C.from_string("T01"), t)
        self.assertEqual(C.from_string("T1"), t)

        tg = C.TriggerGlobal(t,w)
        self.assertEqual(C.short_format(tg), "W002T01")
        self.assertEqual(C.to_string(tg), "W002T01")
        self.assertEqual(C.from_string("W002T01"), tg)
        self.assertEqual(C.from_string("W02T1"), tg)
        self.assertEqual(C.from_string("W2T1"), tg)

        rb = C.RepeaterBlockOnHICANN(Enum(2))
        self.assertEqual(C.short_format(rb), "RB2")
        self.assertEqual(C.to_string(rb), "RB2")
        self.assertEqual(C.from_string("RB2"), rb)

        hr = C.HRepeaterOnHICANN(Enum(5))
        self.assertEqual(C.short_format(hr), "HR005")
        self.assertEqual(C.to_string(hr), "HR005")
        self.assertEqual(C.from_string("HR005"), hr)
        self.assertEqual(C.from_string("HR05"), hr)
        self.assertEqual(C.from_string("HR5"), hr)

        vr = C.VRepeaterOnHICANN(Enum(6))
        self.assertEqual(C.short_format(vr), "VR006")
        self.assertEqual(C.to_string(vr), "VR006")
        self.assertEqual(C.from_string("VR006"), vr)
        self.assertEqual(C.from_string("VR06"), vr)
        self.assertEqual(C.from_string("VR6"), vr)

        hl = C.HLineOnHICANN(Enum(5))
        self.assertEqual(C.short_format(hl), "HL005")
        self.assertEqual(C.to_string(hl), "HL005")
        self.assertEqual(C.from_string("HL005"), hl)
        self.assertEqual(C.from_string("HL05"), hl)
        self.assertEqual(C.from_string("HL5"), hl)

        vl = C.VLineOnHICANN(Enum(6))
        self.assertEqual(C.short_format(vl), "VL006")
        self.assertEqual(C.to_string(vl), "VL006")
        self.assertEqual(C.from_string("VL006"), vl)
        self.assertEqual(C.from_string("VL06"), vl)
        self.assertEqual(C.from_string("VL6"), vl)

        rb_on_wafer = C.RepeaterBlockOnWafer(rb, h)
        self.assertEqual(C.short_format(rb_on_wafer), "H003RB2")
        self.assertEqual(C.to_string(rb_on_wafer), "H003RB2")
        self.assertEqual(C.from_string("H003RB2"), rb_on_wafer)
        self.assertEqual(C.from_string("H03RB2"), rb_on_wafer)
        self.assertEqual(C.from_string("H3RB2"), rb_on_wafer)

        with self.assertRaises(RuntimeError):
            C.from_string("")

        with self.assertRaises(RuntimeError):
            C.from_string("123W33")

        with self.assertRaises(RuntimeError):
            C.from_string("W33X")

        with self.assertRaises(RuntimeError):
            C.from_string("W33F12 ")

        with self.assertRaises(RuntimeError):
            C.from_string(" W33F12")

    def test_synapseswitchrow_driver(self):
        import pyhalco_hicann_v2 as C
        from pyhalco_common import Enum, left, Y

        hicann = C.HICANNOnWafer(Enum(5))
        left_hicann = C.HICANNOnWafer(Enum(4))
        row = C.SynapseSwitchRowOnWafer(C.SynapseSwitchRowOnHICANN(left, Y(0)), hicann)

        driver = row.toSynapseDriverOnWafer()
        self.assertEqual(driver.toHICANNOnWafer(), left_hicann)

    def test_neighbor_l1_lines(self):
        """
        spot checks conversion to L1 lines on neighbor HICANN
        """
        import pyhalco_hicann_v2 as C
        from pyhalco_common import Enum

        # neighbour HICANN is connected right
        hrepeater = C.HLineOnWafer(C.HLineOnHICANN(Enum(3)), C.HICANNOnWafer(Enum(13))).toHRepeaterOnWafer()[0]
        self.assertEqual(hrepeater.toHLineOnWafer()[1],
                         C.HLineOnWafer(C.HLineOnHICANN(Enum(5)), C.HICANNOnWafer(Enum(14))))

        # neighbor HICANN is connected left
        hrepeater = C.HLineOnWafer(C.HLineOnHICANN(Enum(2)), C.HICANNOnWafer(Enum(13))).toHRepeaterOnWafer()[0]
        self.assertEqual(hrepeater.toHLineOnWafer()[1],
                         C.HLineOnWafer(C.HLineOnHICANN(Enum(0)), C.HICANNOnWafer(Enum(12))))

        # neighbor HICANN is connected up
        vrepeater = C.VLineOnWafer(C.VLineOnHICANN(Enum(1)), C.HICANNOnWafer(Enum(12))).toVRepeaterOnWafer()[0]
        self.assertEqual(vrepeater.toVLineOnWafer()[1],
                         C.VLineOnWafer(C.VLineOnHICANN(Enum(3)), C.HICANNOnWafer(Enum(0))))

        # neighbor HICANN is connected down
        vrepeater = C.VLineOnWafer(C.VLineOnHICANN(Enum(2)), C.HICANNOnWafer(Enum(12))).toVRepeaterOnWafer()[0]
        self.assertEqual(vrepeater.toVLineOnWafer()[1],
                         C.VLineOnWafer(C.VLineOnHICANN(Enum(0)), C.HICANNOnWafer(Enum(28))))

        # HICANN 0 does not have a neighbor to the left
        self.assertEqual(None, C.HRepeaterOnWafer(C.HRepeaterOnHICANN(Enum(0)), C.HICANNOnWafer(Enum(0))).toHLineOnWafer()[1])

        # HICANN 0 does not have a neighbor up
        self.assertEqual(None, C.VRepeaterOnWafer(C.VRepeaterOnHICANN(Enum(0)), C.HICANNOnWafer(Enum(0))).toVLineOnWafer()[1])

    def test_neighbor_l1_repeaters(self):
        """
        spot checks conversion to L1 repeaters on neighbor HICANN
        """
        import pyhalco_hicann_v2 as C
        from pyhalco_common import Enum

        # neighbour HICANN is connected right
        hline = C.HLineOnWafer(C.HLineOnHICANN(Enum(4)), C.HICANNOnWafer(Enum(13)))
        self.assertEqual(hline.toHRepeaterOnWafer()[1],
                         C.HRepeaterOnWafer(C.HRepeaterOnHICANN(Enum(6)), C.HICANNOnWafer(Enum(14))))

        # neighbour HICANN is connected left
        hline = C.HLineOnWafer(C.HLineOnHICANN(Enum(5)), C.HICANNOnWafer(Enum(13)))
        self.assertEqual(hline.toHRepeaterOnWafer()[1],
                         C.HRepeaterOnWafer(C.HRepeaterOnHICANN(Enum(3)), C.HICANNOnWafer(Enum(12))))

        # neighbour HICANN is connected up
        vline = C.VLineOnWafer(C.VLineOnHICANN(Enum(0)), C.HICANNOnWafer(Enum(12)))
        self.assertEqual(vline.toVRepeaterOnWafer()[1],
                         C.VRepeaterOnWafer(C.VLineOnHICANN(Enum(2)).toVRepeaterOnHICANN(), C.HICANNOnWafer(Enum(0))))

        # neighbour HICANN is connected down
        vline = C.VLineOnWafer(C.VLineOnHICANN(Enum(3)), C.HICANNOnWafer(Enum(12)))
        self.assertEqual(vline.toVRepeaterOnWafer()[1],
                         C.VRepeaterOnWafer(C.VLineOnHICANN(Enum(1)).toVRepeaterOnHICANN(), C.HICANNOnWafer(Enum(28))))

        # HICANN 0 does not have a neighbor to the left
        self.assertEqual(None, C.HLineOnWafer(C.HLineOnHICANN(Enum(1)), C.HICANNOnWafer(Enum(0))).toHRepeaterOnWafer()[1])

        # HICANN 0 does not have a neighbor up
        self.assertEqual(None, C.VLineOnWafer(C.VLineOnHICANN(Enum(0)), C.HICANNOnWafer(Enum(0))).toVRepeaterOnWafer()[1])

if __name__ == '__main__':
    unittest.main()
