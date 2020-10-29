#include "halco/hicann-dls/vx/v1/pycoordinates.h"

namespace halco::hicann_dls::vx::v1 {

pybind11::list get_coordinates_list(pybind11::module& m)
{
	pybind11::list ret;
#define COORDINATE(Name, Type) ret.append(m.attr(#Name));
#include "halco/hicann-dls/vx/v1/coordinates.def"
	return ret;
}

} // halco::hicann_dls::vx::v1
