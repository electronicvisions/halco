#pragma once
#include <algorithm>
#include <optional>
#include <random>
#include <vector>

#include "halco/common/iter_all.h"

namespace halco::common {

/**
 * Iterate over iterable type with specified amount of samples to draw with uniform probability from
 * range while guaranteeing order.
 * If the range size is smaller equal than the number of requested samples, all instances in the
 * range will be returned in order.
 * @tparam T Type to iter over
 * @param num Number of samples to draw, first and last are always added, defaults to all
 */
template <typename T>
std::vector<T> iter_sparse(std::optional<size_t> const num = std::nullopt)
{
	std::vector<T> all;
	for (auto const t : halco::common::iter_all<T>()) {
		all.push_back(t);
	}

	if (!num) {
		return all;
	}
	if (all.size() <= 2) {
		return all;
	}
	if (*num < 2) {
		throw std::runtime_error(
		    "iter_sparse always adds first and last in range, provided num is too small.");
	}
	std::vector<T> ret;
	ret.push_back(all.front());
	std::sample(
	    all.begin() + 1, all.end() - 1, std::back_inserter(ret), *num - 2,
	    std::mt19937{std::random_device{}()});
	ret.push_back(all.back());
	return ret;
}

} // namespace halco::common
