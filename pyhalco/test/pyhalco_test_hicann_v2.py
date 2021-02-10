#!/usr/bin/env python

import os
import sys
import unittest
from pyhalco_test_utils import parametrize, PyhalcoTest

GENPYBIND_POSTFIX = os.environ.get("GENPYBIND_POSTFIX", False)

@parametrize
class Test_PyhalcoHICANNv2(unittest.TestCase, PyhalcoTest):
    COORDINATES = """
    AnalogOnDNC           => linear, iterable
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
    AnanasChannelOnAnanasSlice => linear, iterable
    AnanasGlobal          =>
    AnanasSliceGlobal     =>
    AnanasOnWafer         => linear, iterable
    AnanasSliceOnAnanas   => linear, iterable
    AnanasSliceOnWafer    => linear
    AuxPwrGlobal          =>
    AuxPwrOnWafer         => linear, iterable
    GbitLinkOnHICANN      => linear, iterable
    GbitLinkOnWafer       => linear, iterable
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
    IPv4                  => ignore
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
    SendingRepeaterOnWafer => iterable
    SocketOnWIO           => linear, iterable
    SynapseArrayOnHICANN  => linear, iterable
    SynapseColumnOnHICANN => linear, iterable
    SynapseDriverOnHICANN => grid, iterable
    SynapseDriverOnQuadrant => linear, iterable
    SynapseDriverOnWafer  => iterable
    SynapseOnHICANN       => grid, iterable
    SynapseOnWafer        =>
    SynapseRowOnHICANN    => linear, iterable
    SynapseRowOnWafer     => linear, iterable
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
    WIOOnWafer            => linear, iterable
    """

    # remark: JTAGFrequency is iterable and linear but we skip tests as the range is large and
    #         takes allot of time
    # remark: IPv4 is not pickleable only in genpybind-based wrapping
    # remark: AnanasSliceOnWafer is not iterable only for genpybind for python2 wrapping

    @staticmethod
    def get_module():
        if GENPYBIND_POSTFIX:
            import pyhalco_hicann_v2_genpybind as pyhalco_hicann_v2
        else:
            import pyhalco_hicann_v2
        return pyhalco_hicann_v2

    def test_implicit_conversion(self):
        if GENPYBIND_POSTFIX:
            import pyhalco_hicann_v2_genpybind as C
        else:
            import pyhalco_hicann_v2 as C
        dnc = C.DNCMergerOnHICANN(5)
        if GENPYBIND_POSTFIX and sys.version_info.major == 2:
            link = C.GbitLinkOnHICANN(int(dnc))
            dnc_ = C.DNCMergerOnHICANN(int(link))
        else:
            link = C.GbitLinkOnHICANN(dnc)
            dnc_ = C.DNCMergerOnHICANN(link)
        self.assertEqual(5, link.value())
        self.assertEqual(5, dnc_.value())

    def test_format_helper(self):
        if GENPYBIND_POSTFIX:
            import pyhalco_hicann_v2_genpybind as C
            from pyhalco_common_genpybind import Enum
        else:
            import pyhalco_hicann_v2 as C
            from pyhalco_common import Enum

        w = C.Wafer(2)
        self.assertEqual(C.short_format(w),  "W002")
        self.assertEqual(C.to_string(w),  "W002")
        self.assertEqual(C.from_string("W002"), w)
        self.assertEqual(C.from_string("W02"), w)
        self.assertEqual(C.from_string("W2"), w)

        if GENPYBIND_POSTFIX and sys.version_info.major == 2:
            a = C.AnanasOnWafer(int(Enum(1)))
        else:
            a = C.AnanasOnWafer(Enum(1))
        self.assertEqual(C.short_format(a), "A1")
        self.assertEqual(C.to_string(a), "A1")
        self.assertEqual(C.from_string("A1"), a)

        ag = C.AnanasGlobal(a, w)
        self.assertEqual(C.short_format(ag), "W002A1")
        self.assertEqual(C.to_string(ag), "W002A1")
        self.assertEqual(C.from_string("W002A1"), ag)
        self.assertEqual(C.from_string("W02A1"), ag)
        self.assertEqual(C.from_string("W2A1"), ag)

        if GENPYBIND_POSTFIX and sys.version_info.major == 2:
            a = C.AuxPwrOnWafer(int(Enum(1)))
        else:
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

        if GENPYBIND_POSTFIX and sys.version_info.major == 2:
            f = C.FPGAOnWafer(int(Enum(4)))
        else:
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

        d = C.DNCOnWafer(Enum(4))
        self.assertEqual(C.short_format(d),  "D004")
        self.assertEqual(C.to_string(d),  "D004")
        self.assertEqual(C.from_string("D004"), d)
        self.assertEqual(C.from_string("D04"), d)
        self.assertEqual(C.from_string("D4"), d)

        dg = C.DNCGlobal(d,w)
        self.assertEqual(C.short_format(dg), "W002D004")
        self.assertEqual(C.to_string(dg), "W002D004")
        self.assertEqual(C.from_string("W002D004"), dg)
        self.assertEqual(C.from_string("W02D04"), dg)
        self.assertEqual(C.from_string("W2D4"), dg)

        if GENPYBIND_POSTFIX and sys.version_info.major == 2:
            t = C.TriggerOnWafer(int(Enum(1)))
        else:
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

        hr_on_wafer = C.HRepeaterOnWafer(hr, h)
        self.assertEqual(C.short_format(hr_on_wafer), "H003HR005")
        self.assertEqual(C.to_string(hr_on_wafer), "H003HR005")
        self.assertEqual(C.from_string("H003HR005"), hr_on_wafer)
        self.assertEqual(C.from_string("H03HR005"), hr_on_wafer)
        self.assertEqual(C.from_string("H3HR005"), hr_on_wafer)
        self.assertEqual(C.from_string("H003HR05"), hr_on_wafer)
        self.assertEqual(C.from_string("H03HR05"), hr_on_wafer)
        self.assertEqual(C.from_string("H3HR05"), hr_on_wafer)
        self.assertEqual(C.from_string("H003HR5"), hr_on_wafer)
        self.assertEqual(C.from_string("H03HR5"), hr_on_wafer)
        self.assertEqual(C.from_string("H3HR5"), hr_on_wafer)

        vr = C.VRepeaterOnHICANN(Enum(6))
        self.assertEqual(C.short_format(vr), "VR006")
        self.assertEqual(C.to_string(vr), "VR006")
        self.assertEqual(C.from_string("VR006"), vr)
        self.assertEqual(C.from_string("VR06"), vr)
        self.assertEqual(C.from_string("VR6"), vr)

        vr_on_wafer = C.VRepeaterOnWafer(vr, h)
        self.assertEqual(C.short_format(vr_on_wafer), "H003VR006")
        self.assertEqual(C.to_string(vr_on_wafer), "H003VR006")
        self.assertEqual(C.from_string("H003VR006"), vr_on_wafer)
        self.assertEqual(C.from_string("H03VR006"), vr_on_wafer)
        self.assertEqual(C.from_string("H3VR006"), vr_on_wafer)
        self.assertEqual(C.from_string("H003VR06"), vr_on_wafer)
        self.assertEqual(C.from_string("H03VR06"), vr_on_wafer)
        self.assertEqual(C.from_string("H3VR06"), vr_on_wafer)
        self.assertEqual(C.from_string("H003VR6"), vr_on_wafer)
        self.assertEqual(C.from_string("H03VR6"), vr_on_wafer)
        self.assertEqual(C.from_string("H3VR6"), vr_on_wafer)

        if GENPYBIND_POSTFIX and sys.version_info.major == 2:
            hl = C.HLineOnHICANN(int(Enum(5)))
        else:
            hl = C.HLineOnHICANN(Enum(5))
        self.assertEqual(C.short_format(hl), "HL005")
        self.assertEqual(C.to_string(hl), "HL005")
        self.assertEqual(C.from_string("HL005"), hl)
        self.assertEqual(C.from_string("HL05"), hl)
        self.assertEqual(C.from_string("HL5"), hl)

        hl_on_wafer = C.HLineOnWafer(hl, h)
        self.assertEqual(C.short_format(hl_on_wafer), "H003HL005")
        self.assertEqual(C.to_string(hl_on_wafer), "H003HL005")
        self.assertEqual(C.from_string("H003HL005"), hl_on_wafer)
        self.assertEqual(C.from_string("H03HL005"), hl_on_wafer)
        self.assertEqual(C.from_string("H3HL005"), hl_on_wafer)
        self.assertEqual(C.from_string("H003HL05"), hl_on_wafer)
        self.assertEqual(C.from_string("H03HL05"), hl_on_wafer)
        self.assertEqual(C.from_string("H3HL05"), hl_on_wafer)
        self.assertEqual(C.from_string("H003HL5"), hl_on_wafer)
        self.assertEqual(C.from_string("H03HL5"), hl_on_wafer)
        self.assertEqual(C.from_string("H3HL5"), hl_on_wafer)

        if GENPYBIND_POSTFIX and sys.version_info.major == 2:
            vl = C.VLineOnHICANN(int(Enum(6)))
        else:
            vl = C.VLineOnHICANN(Enum(6))
        self.assertEqual(C.short_format(vl), "VL006")
        self.assertEqual(C.to_string(vl), "VL006")
        self.assertEqual(C.from_string("VL006"), vl)
        self.assertEqual(C.from_string("VL06"), vl)
        self.assertEqual(C.from_string("VL6"), vl)

        vl_on_wafer = C.VLineOnWafer(vl, h)
        self.assertEqual(C.short_format(vl_on_wafer), "H003VL006")
        self.assertEqual(C.to_string(vl_on_wafer), "H003VL006")
        self.assertEqual(C.from_string("H003VL006"), vl_on_wafer)
        self.assertEqual(C.from_string("H03VL006"), vl_on_wafer)
        self.assertEqual(C.from_string("H3VL006"), vl_on_wafer)
        self.assertEqual(C.from_string("H003VL06"), vl_on_wafer)
        self.assertEqual(C.from_string("H03VL06"), vl_on_wafer)
        self.assertEqual(C.from_string("H3VL06"), vl_on_wafer)
        self.assertEqual(C.from_string("H003VL6"), vl_on_wafer)
        self.assertEqual(C.from_string("H03VL6"), vl_on_wafer)
        self.assertEqual(C.from_string("H3VL6"), vl_on_wafer)

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

        nrn = C.NeuronOnHICANN(Enum(6))
        self.assertEqual(C.short_format(nrn), "N006")
        self.assertEqual(C.to_string(nrn), "N006")
        self.assertEqual(C.from_string("N006"), nrn)
        self.assertEqual(C.from_string("N06"), nrn)
        self.assertEqual(C.from_string("N6"), nrn)

        if GENPYBIND_POSTFIX and sys.version_info.major == 2:
            sr = C.SendingRepeaterOnHICANN(int(Enum(3)))
        else:
            sr = C.SendingRepeaterOnHICANN(Enum(3))

        self.assertEqual(C.short_format(sr), "SR003")
        self.assertEqual(C.to_string(sr), "SR003")
        self.assertEqual(C.from_string("SR003"), sr)
        self.assertEqual(C.from_string("SR03"), sr)
        self.assertEqual(C.from_string("SR3"), sr)

        sr_on_wafer = C.SendingRepeaterOnWafer(sr, h)
        self.assertEqual(C.short_format(sr_on_wafer), "H003SR003")
        self.assertEqual(C.to_string(sr_on_wafer), "H003SR003")
        self.assertEqual(C.from_string("H003SR003"), sr_on_wafer)
        self.assertEqual(C.from_string("H03SR003"), sr_on_wafer)
        self.assertEqual(C.from_string("H3SR003"), sr_on_wafer)
        self.assertEqual(C.from_string("H003SR03"), sr_on_wafer)
        self.assertEqual(C.from_string("H03SR03"), sr_on_wafer)
        self.assertEqual(C.from_string("H3SR03"), sr_on_wafer)
        self.assertEqual(C.from_string("H003SR3"), sr_on_wafer)
        self.assertEqual(C.from_string("H03SR3"), sr_on_wafer)
        self.assertEqual(C.from_string("H3SR3"), sr_on_wafer)


    def test_synapseswitchrow_driver(self):
        if GENPYBIND_POSTFIX:
            import pyhalco_hicann_v2_genpybind as C
            from pyhalco_common_genpybind import Enum, left, Y
        else:
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
        if GENPYBIND_POSTFIX:
            import pyhalco_hicann_v2_genpybind as C
            from pyhalco_common_genpybind import Enum
        else:
            import pyhalco_hicann_v2 as C
            from pyhalco_common import Enum

        if GENPYBIND_POSTFIX and sys.version_info.major == 2:
            # neighbour HICANN is connected right
            hrepeater = C.HLineOnWafer(C.HLineOnHICANN(int(Enum(3))), C.HICANNOnWafer(Enum(13))).toHRepeaterOnWafer()[0]
            self.assertEqual(hrepeater.toHLineOnWafer()[1],
                             C.HLineOnWafer(C.HLineOnHICANN(int(Enum(5))), C.HICANNOnWafer(Enum(14))))

            # neighbor HICANN is connected left
            hrepeater = C.HLineOnWafer(C.HLineOnHICANN(int(Enum(2))), C.HICANNOnWafer(Enum(13))).toHRepeaterOnWafer()[0]
            self.assertEqual(hrepeater.toHLineOnWafer()[1],
                             C.HLineOnWafer(C.HLineOnHICANN(int(Enum(0))), C.HICANNOnWafer(Enum(12))))

            # neighbor HICANN is connected up
            vrepeater = C.VLineOnWafer(C.VLineOnHICANN(int(Enum(1))), C.HICANNOnWafer(Enum(12))).toVRepeaterOnWafer()[0]
            self.assertEqual(vrepeater.toVLineOnWafer()[1],
                             C.VLineOnWafer(C.VLineOnHICANN(int(Enum(3))), C.HICANNOnWafer(Enum(0))))

            # neighbor HICANN is connected down
            vrepeater = C.VLineOnWafer(C.VLineOnHICANN(int(Enum(2))), C.HICANNOnWafer(Enum(12))).toVRepeaterOnWafer()[0]
            self.assertEqual(vrepeater.toVLineOnWafer()[1],
                             C.VLineOnWafer(C.VLineOnHICANN(int(Enum(0))), C.HICANNOnWafer(Enum(28))))

        else:
            # neighbour HICANN is connected right
            hrepeater = C.HLineOnWafer(C.HLineOnHICANN(Enum(3)), C.HICANNOnWafer(Enum(13))).toHRepeaterOnWafer()[0]
            self.assertEqual(hrepeater.toHLineOnWafer()[1],
                             C.HLineOnWafer(C.HLineOnHICANN(Enum(5)), C.HICANNOnWafer(Enum(14))))

            # neighbor HICANN is connected left
            hrepeater = C.HLineOnWafer(C.HLineOnHICANN(int(Enum(2))), C.HICANNOnWafer(Enum(13))).toHRepeaterOnWafer()[0]
            self.assertEqual(hrepeater.toHLineOnWafer()[1],
                             C.HLineOnWafer(C.HLineOnHICANN(int(Enum(0))), C.HICANNOnWafer(Enum(12))))

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
        if GENPYBIND_POSTFIX:
            import pyhalco_hicann_v2_genpybind as C
            from pyhalco_common_genpybind import Enum
        else:
            import pyhalco_hicann_v2 as C
            from pyhalco_common import Enum

        # neighbour HICANN is connected right
        if GENPYBIND_POSTFIX and sys.version_info.major == 2:
            hline = C.HLineOnWafer(C.HLineOnHICANN(int(Enum(4))), C.HICANNOnWafer(Enum(13)))
        else:
            hline = C.HLineOnWafer(C.HLineOnHICANN(Enum(4)), C.HICANNOnWafer(Enum(13)))
        self.assertEqual(hline.toHRepeaterOnWafer()[1],
                         C.HRepeaterOnWafer(C.HRepeaterOnHICANN(Enum(6)), C.HICANNOnWafer(Enum(14))))

        # neighbour HICANN is connected left
        if GENPYBIND_POSTFIX and sys.version_info.major == 2:
            hline = C.HLineOnWafer(C.HLineOnHICANN(int(Enum(5))), C.HICANNOnWafer(Enum(13)))
        else:
            hline = C.HLineOnWafer(C.HLineOnHICANN(Enum(5)), C.HICANNOnWafer(Enum(13)))
        self.assertEqual(hline.toHRepeaterOnWafer()[1],
                         C.HRepeaterOnWafer(C.HRepeaterOnHICANN(Enum(3)), C.HICANNOnWafer(Enum(12))))

        if GENPYBIND_POSTFIX and sys.version_info.major == 2:
            # neighbour HICANN is connected up
            vline = C.VLineOnWafer(C.VLineOnHICANN(int(Enum(0))), C.HICANNOnWafer(Enum(12)))
            self.assertEqual(vline.toVRepeaterOnWafer()[1],
                             C.VRepeaterOnWafer(C.VLineOnHICANN(int(Enum(2))).toVRepeaterOnHICANN(), C.HICANNOnWafer(Enum(0))))

            # neighbour HICANN is connected down
            vline = C.VLineOnWafer(C.VLineOnHICANN(int(Enum(3))), C.HICANNOnWafer(Enum(12)))
            self.assertEqual(vline.toVRepeaterOnWafer()[1],
                             C.VRepeaterOnWafer(C.VLineOnHICANN(int(Enum(1))).toVRepeaterOnHICANN(), C.HICANNOnWafer(Enum(28))))

            # HICANN 0 does not have a neighbor to the left
            self.assertEqual(None, C.HLineOnWafer(C.HLineOnHICANN(int(Enum(1))), C.HICANNOnWafer(Enum(0))).toHRepeaterOnWafer()[1])

            # HICANN 0 does not have a neighbor up
            self.assertEqual(None, C.VLineOnWafer(C.VLineOnHICANN(int(Enum(0))), C.HICANNOnWafer(Enum(0))).toVRepeaterOnWafer()[1])
        else:
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

    def test_neighbor_l1_repeaters_cardinal(self):
        """
        spot checks moving L1 repeaters in cardinal points
        """
        import pyhalco_hicann_v2 as C
        from pyhalco_common import Enum

        hrepeater = C.HRepeaterOnWafer(C.HRepeaterOnHICANN(Enum(0)), C.HICANNOnWafer(Enum(0)))
        self.assertEqual(None, hrepeater.west())
        self.assertEqual(C.HRepeaterOnWafer(C.HRepeaterOnHICANN(Enum(2)), C.HICANNOnWafer(Enum(1))), hrepeater.east())

        hrepeater = C.HRepeaterOnWafer(C.HRepeaterOnHICANN(Enum(0)), C.HICANNOnWafer(Enum(1)))
        self.assertEqual(C.HRepeaterOnWafer(C.HRepeaterOnHICANN(Enum(62)), C.HICANNOnWafer(Enum(0))), hrepeater.west())

        vrepeater = C.VRepeaterOnWafer(C.VRepeaterOnHICANN(Enum(129)), C.HICANNOnWafer(Enum(0)))
        self.assertEqual(None, vrepeater.north())
        self.assertEqual(C.VRepeaterOnWafer(C.VRepeaterOnHICANN(Enum(128)), C.HICANNOnWafer(Enum(12))), vrepeater.south())

        vrepeater = C.VRepeaterOnWafer(C.VRepeaterOnHICANN(Enum(0)), C.HICANNOnWafer(Enum(12)))
        self.assertEqual(C.VRepeaterOnWafer(C.VRepeaterOnHICANN(Enum(1)), C.HICANNOnWafer(Enum(0))), vrepeater.north())

    def test_explicit_conversion(self):
        if GENPYBIND_POSTFIX:
            import pyhalco_hicann_v2_genpybind as C
        else:
            import pyhalco_hicann_v2 as C

        # use some wafer != 0
        fg = C.FPGAGlobal(C.FPGAOnWafer(), C.Wafer(33))
        self.assertEqual(int(fg), fg.toEnum().value())

        # compare same FPGA on different wafers
        self.assertNotEqual(int(C.FPGAGlobal(C.FPGAOnWafer(), C.Wafer(0))),
                            int(C.FPGAGlobal(C.FPGAOnWafer(), C.Wafer(1))))

if __name__ == '__main__':
    unittest.main()
