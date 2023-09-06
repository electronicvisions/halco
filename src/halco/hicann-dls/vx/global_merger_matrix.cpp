#include "halco/hicann-dls/vx/global_merger_matrix.h"

#include "halco/common/lookup_tables_helper.h"
#include "halco/hicann-dls/vx/event.h"
#include "halco/hicann-dls/vx/neuron.h"
#include "halco/hicann-dls/vx/padi.h"

#ifdef __ppu__
extern void exit(int32_t);
#endif

namespace halco::hicann_dls::vx {

// clang-format off
std::array<std::pair<int, int>, GlobalMergerMatrixIntersectionOnDLS::size> const GlobalMergerMatrixIntersectionOnDLSGrid = {{
               { 1,  0}, { 2,  0}, { 3,  0},  { 4,  0},  { 5,  0},
     { 0,  1},           { 2,  1}, { 3,  1},  { 4,  1},            { 6,  1},
     { 0,  2}, { 1,  2},           { 3,  2},  { 4,  2},                      { 7,  2},
     { 0,  3}, { 1,  3}, { 2,  3},            { 4,  3},                                { 8,  3},

     { 0,  4}, { 1,  4}, { 2,  4}, { 3,  4},  { 4,  4},  { 5,  4}, { 6,  4}, { 7,  4}, { 8,  4},

     { 0,  5}, { 1,  5}, { 2,  5}, { 3,  5},
     { 0,  6}, { 1,  6}, { 2,  6}, { 3,  6},
     { 0,  7}, { 1,  7}, { 2,  7}, { 3,  7},
     { 0,  8}, { 1,  8}, { 2,  8}, { 3,  8},

                                              { 4,  9},  { 5,  9},
                                              { 4, 10},            { 6, 10},
                                              { 4, 11},                      { 7,  11},
                                              { 4, 12},                                { 8, 12},
}};
// clang-format on

auto const GlobalMergerMatrixIntersectionOnDLSEnum = halco::common::detail::generateEnum<
    GlobalMergerMatrixInputOnDLS::size,
    GlobalMergerMatrixOutputOnDLS::size,
    GlobalMergerMatrixIntersectionOnDLS::size>(GlobalMergerMatrixIntersectionOnDLSGrid);

GlobalMergerMatrixIntersectionOnDLS::x_type GlobalMergerMatrixIntersectionOnDLS::to_x(
    enum_type const& e)
{
	return x_type(GlobalMergerMatrixIntersectionOnDLSGrid.at(e).first);
}

GlobalMergerMatrixIntersectionOnDLS::y_type GlobalMergerMatrixIntersectionOnDLS::to_y(
    enum_type const& e)
{
	return y_type(GlobalMergerMatrixIntersectionOnDLSGrid.at(e).second);
}

GlobalMergerMatrixIntersectionOnDLS::enum_type GlobalMergerMatrixIntersectionOnDLS::to_enum(
    x_type const& x, y_type const& y)
{
	// throws out_of_range if x or y is not available on wafer.
	int const en = GlobalMergerMatrixIntersectionOnDLSEnum.at(y).at(x);
	if (en == halco::common::detail::invalid)
#ifndef __ppu__
		throw std::domain_error(
		    "Invalid combination of X and Y for a GlobalMergerMatrixIntersection");
#else
		exit(1);
#endif
	return enum_type(en);
}


namespace {

std::array<std::pair<size_t, size_t>, GlobalMergerMatrixIntersectionOnDLS::size> const
    GlobalMergerMatrixIntersectionOnDLSShapes = {{
        {GMM_EMUL, GMM_EMUL},
        {GMM_EMUL, GMM_EMUL},
        {GMM_EMUL, GMM_EMUL},
        {GMM_TORLUT, GMM_EMUL},
        {1, 1},
        {GMM_EMUL, GMM_EMUL},
        {GMM_EMUL, GMM_EMUL},
        {GMM_EMUL, GMM_EMUL},
        {GMM_TORLUT, GMM_EMUL},
        {1, 1},
        {GMM_EMUL, GMM_EMUL},
        {GMM_EMUL, GMM_EMUL},
        {GMM_EMUL, GMM_EMUL},
        {GMM_TORLUT, GMM_EMUL},
        {1, 1},
        {GMM_EMUL, GMM_EMUL},
        {GMM_EMUL, GMM_EMUL},
        {GMM_EMUL, GMM_EMUL},
        {GMM_TORLUT, GMM_EMUL},
        {1, 1},

        {GMM_EMUL, GMM_FROMRLUT},
        {GMM_EMUL, GMM_FROMRLUT},
        {GMM_EMUL, GMM_FROMRLUT},
        {GMM_EMUL, GMM_FROMRLUT},
        {GMM_TORLUT, GMM_FROMRLUT},
        {1, GMM_FROMRLUT},
        {1, GMM_FROMRLUT},
        {1, GMM_FROMRLUT},
        {1, GMM_FROMRLUT},

        {GMM_EMUL, 1},
        {GMM_EMUL, 1},
        {GMM_EMUL, 1},
        {GMM_EMUL, 1},
        {GMM_EMUL, 1},
        {GMM_EMUL, 1},
        {GMM_EMUL, 1},
        {GMM_EMUL, 1},
        {GMM_EMUL, 1},
        {GMM_EMUL, 1},
        {GMM_EMUL, 1},
        {GMM_EMUL, 1},
        {GMM_EMUL, 1},
        {GMM_EMUL, 1},
        {GMM_EMUL, 1},
        {GMM_EMUL, 1},

        {GMM_TORLUT, 1},
        {1, 1},
        {GMM_TORLUT, 1},
        {1, 1},
        {GMM_TORLUT, 1},
        {1, 1},
        {GMM_TORLUT, 1},
        {1, 1},
    }};

size_t check_and_calculate_node_enum(
    NodeOnGlobalMergerMatrixIntersection const& node_on_intersection,
    GlobalMergerMatrixIntersectionOnDLS const& intersection)
{
	auto const& intersection_shape =
	    GlobalMergerMatrixIntersectionOnDLSShapes.at(intersection.toEnum().value());
	if (node_on_intersection.toInputChannelOnGlobalMergerMatrixIntersection() >=
	    intersection_shape.second) {
#ifndef __ppu__
		throw std::out_of_range(
		    "Requested input channel on intersection out of range of [0, " +
		    std::to_string(intersection_shape.second) + ").");
#else
		exit(1);
#endif
	}
	if (node_on_intersection.toOutputChannelOnGlobalMergerMatrixIntersection() >=
	    intersection_shape.first) {
#ifndef __ppu__
		throw std::out_of_range(
		    "Requested output channel on intersection out of range of [0, " +
		    std::to_string(intersection_shape.first) + ").");
#else
		exit(1);
#endif
	}

	size_t node_on_dls = 0;
	for (size_t i = 0; i < intersection.toEnum().value(); ++i) {
		node_on_dls += GlobalMergerMatrixIntersectionOnDLSShapes.at(i).first *
		               GlobalMergerMatrixIntersectionOnDLSShapes.at(i).second;
	}
	node_on_dls += node_on_intersection.toInputChannelOnGlobalMergerMatrixIntersection() *
	                   intersection_shape.first +
	               node_on_intersection.toOutputChannelOnGlobalMergerMatrixIntersection();
	return node_on_dls;
}

} // namespace


GlobalMergerMatrixNodeOnDLS::GlobalMergerMatrixNodeOnDLS(
    NodeOnGlobalMergerMatrixIntersection const& node_on_intersection,
    GlobalMergerMatrixIntersectionOnDLS const& intersection) :
    rant_t(check_and_calculate_node_enum(node_on_intersection, intersection))
{}

NodeOnGlobalMergerMatrixIntersection
GlobalMergerMatrixNodeOnDLS::toNodeOnGlobalMergerMatrixIntersection() const
{
	size_t intersection_enum = 0;
	size_t node_on_dls = 0;
	for (; intersection_enum < GlobalMergerMatrixIntersectionOnDLS::size; ++intersection_enum) {
		node_on_dls += GlobalMergerMatrixIntersectionOnDLSShapes.at(intersection_enum).first *
		               GlobalMergerMatrixIntersectionOnDLSShapes.at(intersection_enum).second;
		if (node_on_dls > value()) {
			break;
		}
	}
	node_on_dls -= GlobalMergerMatrixIntersectionOnDLSShapes.at(intersection_enum).first *
	               GlobalMergerMatrixIntersectionOnDLSShapes.at(intersection_enum).second;
	return NodeOnGlobalMergerMatrixIntersection(common::Enum(value() - node_on_dls));
}

GlobalMergerMatrixIntersectionOnDLS
GlobalMergerMatrixNodeOnDLS::toGlobalMergerMatrixIntersectionOnDLS() const
{
	size_t intersection_enum = 0;
	size_t node_on_dls = 0;
	for (; intersection_enum < GlobalMergerMatrixIntersectionOnDLS::size; ++intersection_enum) {
		node_on_dls += GlobalMergerMatrixIntersectionOnDLSShapes.at(intersection_enum).first *
		               GlobalMergerMatrixIntersectionOnDLSShapes.at(intersection_enum).second;
		if (node_on_dls > value()) {
			break;
		}
	}
	return GlobalMergerMatrixIntersectionOnDLS(common::Enum(intersection_enum));
}

} // namespace halco::hicann_dls::vx
