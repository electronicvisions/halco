#!/usr/bin/env python

import unittest
from pyhalco_test_utils import parametrize, PyhalcoTest

@parametrize
class Test_PyhalcoCommon(unittest.TestCase, PyhalcoTest):
    COORDINATES = """
    Direction             =>
    Enum                  => linear
    Orientation           => iterable
    Parity                => iterable
    Unique                =>
    Side                  => ignore
    SideHorizontal        => linear
    SideVertical          => linear
    X                     => linear
    Y                     => linear
    IPv4                  => ignore
    """

    @staticmethod
    def get_module():
        import pyhalco_common
        return pyhalco_common

    def test_printable_SideHorizontal(self):
        x = str(self.get_coordinate_class("SideHorizontal")())
        self.assertIn(x, ["left", "right"])

    def test_printable_SideVertical(self):
        x = str(self.get_coordinate_class("SideVertical")())
        self.assertIn(x, ["top", "bottom"])

    def test_printable_Direction(self):
        x = str(self.get_coordinate_class("Direction")())
        self.assertIn(x, ["north", "east", "south", "west"])

    def test_printable_Orientation(self):
        x = str(self.get_coordinate_class("Orientation")())
        self.assertIn(x, ["horizontal", "vertical"])

    def test_printable_Parity(self):
        x = str(self.get_coordinate_class("Parity")())
        self.assertIn(x, ["even", "odd"])

    def test_printable_Unique(self):
        x = str(self.get_coordinate_class("Unique")())
        self.assertEqual(x, "unique")


# There are other types in halco::common; manually tested below
class Test_PyhalcoCommon_MiscTypes(unittest.TestCase):
    def test_ipv4(self):
        from pyhalco_common import IPv4
        self.assertTrue(IPv4([192,168,123,66]).to_string() == '192.168.123.66')
        self.assertTrue(list(IPv4([192,168,123,66]).to_bytes()) == [192,168,123,66])
        self.assertTrue(IPv4.any().to_string() == '0.0.0.0')
        self.assertTrue(IPv4.broadcast().to_string() == '255.255.255.255')
        self.assertTrue(IPv4.from_string('1.2.3.4') == IPv4([1,2,3,4]))
        self.assertTrue(IPv4.from_string('1.2.3.4').is_class_a())
        self.assertTrue(IPv4.from_string('172.1.2.3').is_class_b())
        self.assertTrue(IPv4([192,168,123,66]).is_class_c())
        self.assertTrue(IPv4([224,1,2,3]).is_multicast())
        self.assertTrue(IPv4.loopback().to_string() == '127.0.0.1')
        self.assertTrue(IPv4.netmask(IPv4([192,168,123,66])).to_string() == '255.255.255.0')
        self.assertTrue(IPv4.netmask(IPv4([192,168,123,66])).to_string() == '255.255.255.0')
        self.assertTrue(IPv4([192,168,123,66]).to_ulong() == 3232267074)
        ip_a = IPv4.from_string("1.2.3.4")
        ip_b = ip_a
        self.assertEqual(ip_a, ip_b)

if __name__ == "__main__":
    unittest.main()
