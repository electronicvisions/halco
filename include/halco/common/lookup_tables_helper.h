#pragma once
#include <array>

namespace halco {
namespace common {
namespace detail {

static int const invalid = -1;

#ifndef PYPLUSPLUS

template <typename Data, size_t N>
void set_invalid(std::array<Data, N>& ar)
{
	static_assert(N > 0, "no zero-sized arrays");
	typedef typename std::remove_const<decltype(invalid)>::type type;
	type* begin = reinterpret_cast<type*>(&ar[0]);
	type const* end = reinterpret_cast<type*>(&ar[N]);

	while (end - begin)
		*(begin++) = invalid;
}

/**
 * Generate a dense enum lookup matrix from a list of valid entries in the sparse grid.
 * The matrix follows row-major order, the allowed matrix entries are expected to be of format x,y.
 * @tparam y_size Number of rows
 * @tparam x_size Number of columns
 * @tparam enum_size Number of valid entries
 * @param grid Array of valid entries as pairs in the format {x,y}
 */
template <size_t y_size, size_t x_size, size_t enum_size>
std::array<std::array<int, x_size>, y_size> generateEnum(
    std::array<std::pair<int, int>, enum_size> const& grid)
{
	std::array<std::array<int, x_size>, y_size> result;
	set_invalid(result);
	for (size_t ii = 0; ii < grid.size(); ++ii) {
		auto const& item = grid.at(ii);
		size_t x = item.first;
		size_t y = item.second;
		result[y][x] = ii;
	}
	return result;
}

template <size_t size>
std::array<size_t, size> reverseLookup(const std::array<size_t, size>& data)
{
	std::array<size_t, size> result;
	for (size_t ii = 0; ii < size; ++ii)
		result[data[ii]] = ii;
	return result;
}

#endif

} // detail
} // common
} // halco
