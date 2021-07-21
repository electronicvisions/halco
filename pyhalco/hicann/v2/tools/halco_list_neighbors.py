#!/usr/bin/env python

import argparse
import sys

from pyhalco_hicann_v2 import from_string, to_string, HICANNOnWafer
from pyhalco_common import Direction, iter_all


def to_neighbors(coord):
    if isinstance(coord, HICANNOnWafer):
        return [to_string(coord.move(d)) for d in iter_all(Direction) if coord.can_move(d)]
    else:
        raise TypeError(
            "coordinate type not handled, received: {}".format(type(coord)))


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        "coord_str", help="short format of coordinate, e.g. for HICANNOnWafer H297")

    args = parser.parse_args()

    try:
        print("\n".join(to_neighbors(from_string(args.coord_str))))
    except TypeError as e:
        print(e, file=sys.stderr)


if __name__ == '__main__':
    main()
