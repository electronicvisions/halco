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


if __name__ == "__main__":
    unittest.main()
