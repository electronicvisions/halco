"""
pyhalco_common.so will load this module and execute patch() during initialization
"""

def patch(module):
    """
    This hook will be executed at the end of the pyhalco_common module generation
    """
    from pyhalco_coordinate_iter_all import iter_all
    module.iter_all = iter_all
