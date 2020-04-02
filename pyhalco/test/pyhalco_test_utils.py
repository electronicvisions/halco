#!/usr/bin/env python

import functools
import inspect
import itertools
import sys
import string
import unittest


def for_coordinates_with_category(category):
    def decorator(method):
        method.category = category
        return method
    return decorator

# TODO: Use meta-class instead of class decorator?
def parametrize(cls):
    for method_name, method in inspect.getmembers(cls, predicate=lambda x: inspect.isfunction(x) or inspect.ismethod(x)):
        if hasattr(method, "category"):
            coordinates = cls.coordinates_with_category(method.category)
            for name_ in coordinates:
                new_method_name = '{}_{}'.format(method.__name__, name_)
                if new_method_name in cls.__dict__:
                    continue

                def wrapper(self, name=name_, method=method):
                    method(self, name=name)
                functools.update_wrapper(wrapper, method)
                wrapper.__name__ = new_method_name
                setattr(cls, new_method_name, wrapper)
            setattr(cls, method_name, None)
    return cls

class PyhalcoTest(object):
    @staticmethod
    def get_module():
        raise NotImplemented("failed to import module")

    COORDINATES = ""
    CATEGORIES = ["all", "linear", "interval", "iterable", "ignore", "grid"]

    @staticmethod
    def _extract_categories(categories, text):
        by_category = { k: set() for k in categories }

        for line in text.split('\n'):
            if not '=>' in line:
                continue

            name, categories = line.split('=>')
            for cat in categories.split(',') + ['all']:
                cat = cat.strip().lower()
                if not cat:
                    continue

                by_category[cat].add(name.strip())

        by_category['all'].difference_update(by_category['ignore'])

        return {k: frozenset(v) for k, v in by_category.items()}

    @classmethod
    def coordinates_with_category(cls, name):
        if not hasattr(cls, "_BY_CATEGORY"):
            cls._BY_CATEGORY = cls._extract_categories(
                cls.CATEGORIES, cls.COORDINATES)
        return cls._BY_CATEGORY.get(name, frozenset())

    def get_coordinate_class(self, name):
        module = self.get_module()
        cls = getattr(module, name, None)
        self.assertIsNotNone(cls, name + " not found")
        return cls

    def get_coordinate_instances(self, name):
        cls = self.get_coordinate_class(name)
        for name in ['value_type', 'enum_type']:
            value_type = getattr(cls, name, None)
            try:
                small = value_type.min
                large = value_type.max
                break
            except AttributeError:
                continue
        else:
            small = getattr(cls, 'min', 11)
            large = getattr(cls, 'max', 12)

        try:
            if small != large:
                return (cls, cls(small), cls(large))
        except:
            pass
        return (None, None, None)

    #  --- Test that apply to all coordinates ----------------------------------

    def test_coverage(self):
        """
        Check that all objects in the module are in the 'all' category.
        We do not autogenerate it since they also need to be added to the other
        lists / categorized.
        """

        module = self.get_module()
        in_namespace = set(name for name in dir(module)
                           if (name[0] in string.ascii_uppercase
                               and '_' not in name))
        in_namespace.difference_update(self.coordinates_with_category('ignore'))
        in_namespace.difference_update(self.coordinates_with_category('all'))

        self.assertFalse(
            in_namespace,
            'Some coordinates are not in the list of coordinates '
            'to be tested:\n  ' + '\n  '.join( sorted(in_namespace)))

    @for_coordinates_with_category('linear')
    def test_convertable_to_int(self, name):
        cls = self.get_coordinate_class(name)
        x = int(cls())

    @for_coordinates_with_category('linear')
    def test_convertable_to_bool(self, name):
        cls = self.get_coordinate_class(name)
        x = bool(cls())

    @for_coordinates_with_category('linear')
    def test_usable_as_index(self, name):
        # __index__ only implemented for genpybind-based wrapping
        if getattr(self.get_module(), "__variant__", None) != "pybind11":
            return
        cls = self.get_coordinate_class(name)
        x = hex(cls())
        x = bin(cls())
        l = []
        l.insert(cls(), None)

    @for_coordinates_with_category('all')
    def test_copy_constructor(self, name):
        cls = self.get_coordinate_class(name)
        cls(cls())

    @for_coordinates_with_category('all')
    def test_printable(self, name):
        x = str(self.get_coordinate_class(name)())
        self.assertTrue(x.startswith(name), x)

    @for_coordinates_with_category('all')
    def test_comparable(self, name):
        cls = self.get_coordinate_class(name)
        x = cls()
        y = cls()
        self.assertEqual(x, y)
        self.assertTrue(x == y)
        self.assertFalse(x != y)

    @for_coordinates_with_category('all')
    def test_orderable(self, name):
        cls, a, b = self.get_coordinate_instances(name)

        if cls is None:
            self.skipTest(name + " is not int constructible")
            return

        self.assertTrue(a < b)
        self.assertTrue(a <= b)
        self.assertTrue(a != b)
        self.assertFalse(a == b)
        self.assertTrue(b >= a)
        self.assertTrue(b > a)

    @for_coordinates_with_category('all')
    def test_container_membership(self, name):
        cls = self.get_coordinate_class(name)
        x = cls()

        d = {x: ''}
        v = [x]
        s = {x}
        t = (x,)

        self.assertTrue(x in d)
        self.assertTrue(x in v)
        self.assertTrue(x in s)
        self.assertTrue(x in t)

    @for_coordinates_with_category('all')
    def test_usage_as_container_key(self, name):
        cls = self.get_coordinate_class(name)

        x = cls()

        d = {}
        d[x] = True
        self.assertTrue(d.get(x, False))
        self.assertTrue(x in d)

        y = cls()
        self.assertTrue(d.get(y, False))
        self.assertTrue(y in d)

    @for_coordinates_with_category('all')
    def test_pickling(self, name):
        module = self.get_module()
        if getattr(module, "__variant__", None) == "pybind11":
            self.skipTest(
                "pickling has not been implemented yet")
        import pickle
        cls = self.get_coordinate_class(name)
        obj = cls()
        d = pickle.dumps(obj)
        self.assertEqual(obj, pickle.loads(d))

    @for_coordinates_with_category('all')
    def test_pickling_keeps_value(self, name):
        module = self.get_module()
        if getattr(module, "__variant__", None) == "pybind11":
            self.skipTest(
                "pickling has not been implemented yet")
        import pickle
        cls, a, b = self.get_coordinate_instances(name)

        if cls is None:
            self.skipTest(name + " is not int constructible")
            return

        for obj in [a, b]:
            d = pickle.dumps(obj)
            self.assertEqual(obj, pickle.loads(d))

    @for_coordinates_with_category('iterable')
    def test_iter_all(self, name):
        import pyhalco_common
        cls = self.get_coordinate_class(name)

        if cls.is_interval:
            # only test cornercase of overstepped enum
            # i.e. until 2*bound_type.size
            coords = []
            for c in pyhalco_common.iter_all(cls):
                if c.toEnum().value() > cls.bound_type.size * 2:
                    break
                self.assertLessEqual(c.toMin(), c.toMax())
                coords.append(c)
            self.assertEqual(len(coords), cls.bound_type.size * 2 - 1)
        else:
            coords = [c for c in pyhalco_common.iter_all(cls)]
            for coord in coords:
                self.assertIsInstance(coord, cls)

            set_coords = set(c for c in pyhalco_common.iter_all(cls))
            self.assertEqual(len(set_coords), len(coords))

    @for_coordinates_with_category('grid')
    def test_can_be_constructed_from_x_and_y(self, name):
        from pyhalco_common import X, Y, iter_all
        cls = self.get_coordinate_class(name)

        num_x = len(list(iter_all(cls.x_type)))
        num_y = len(list(iter_all(cls.y_type)))
        num_enum = len(list(iter_all(cls.enum_type)))

        self.assertLess(0, num_x)
        self.assertLess(0, num_y)
        self.assertLess(0, num_enum)
        # For some coordinates, e.g. HICANNOnWafer, not all possible combinations are allowed.
        # Thus, the actual number of possible coordinates may be less than num_x * num_y.
        self.assertLessEqual(num_enum, num_x * num_y)

        for x, y in itertools.product(
                iter_all(cls.x_type), iter_all(cls.y_type)):
            try:
                c = cls(x, y)
                break
            except (RuntimeError, ValueError):
                pass
        else:
            self.fail(
                "Failed to construct from any X, Y combination")

        self.assertEqual(c, cls(x, y))
        self.assertEqual(c, cls(X(int(x)), Y(int(y))))

        self.assertEqual(c, cls(y, x))
        self.assertEqual(c, cls(Y(int(y)), X(int(x))))

    @for_coordinates_with_category('interval')
    def test_can_be_constructed_from_bounds(self, name):
        from pyhalco_common import iter_all
        cls = self.get_coordinate_class(name)

        num_bound = cls.bound_type.size
        num_enum = cls.enum_type.size

        self.assertLess(0, num_bound)
        self.assertLess(0, num_enum)
        self.assertEqual(num_enum, num_bound * num_bound)

        for min, max in itertools.product(
                iter_all(cls.bound_type), iter_all(cls.bound_type)):
            try:
                c = cls(min, max)
                break
            except (RuntimeError, ValueError):
                pass
        else:
            self.fail(
                "Failed to construct from any min, max combination")

        self.assertEqual(c, cls(min, max))
        self.assertEqual(c, cls(cls.bound_type(int(min)), cls.bound_type(int(max))))

        self.assertRaises(RuntimeError, c = cls(max, min))
        self.assertRaises(RuntimeError, c = cls(cls.bound_type(int(max)), cls.bound_type(int(min))))
