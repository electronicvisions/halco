"""
python pendant to halco/common/iter_all.h
"""

def _iter_all(Type):
    """
    Generator to iterate over a coordinate
    """
    try:
        value_type = Type.enum_type
        make = lambda ii: Type(value_type(ii))
    except AttributeError:
        value_type = Type
        make = lambda ii: Type(ii)
    if (Type.is_interval):
        value = 0
        while value < Type.size:
            yield make(value)
            value += 1
            if (value % Type.bound_type.size == Type.bound_type.size - value / Type.bound_type.size):
                value = Type.bound_type.size * (value / Type.bound_type.size + 1)
    else:
        for value in range(value_type.begin, value_type.end):
            yield make(value)

def iter_all(*Types):
    """
    Iterates over all possible values of one or more coordinates, e.g.:
        - for neuron in iter_all(NeuronOnHICANN):
              print neuron
        - for hicann, neuron in iter_all(HICANNOnWafer, NeuronOnHICANN):
              print hicann, neuron
    """
    if len(Types) == 1:
        return _iter_all(Types[0])
    else:
        from itertools import product
        return product(*(_iter_all(T) for T in Types))
