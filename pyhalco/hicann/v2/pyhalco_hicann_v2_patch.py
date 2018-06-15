"""
pyhalco_hicann_v2.so will load this module and execute patch() during initialization
"""

import sys
import pyhalco_common


def patch(module):
    """
    This hook will be executed at the end of the pyhalco_hicann_v2 module generation
    """
    module.iter_all = pyhalco_common.iter_all
    module.common = pyhalco_common
