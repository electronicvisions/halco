#pragma once
#ifndef PYPLUSPLUS

#include <boost/iterator/iterator_facade.hpp>

namespace halco {
namespace common {

namespace detail {

template <class Coord>
struct CoordinateIterator :
	public boost::iterator_facade<
	CoordinateIterator<Coord>,
	Coord,
	boost::bidirectional_traversal_tag,
	Coord
	>
{
public:
	CoordinateIterator() : ii()
	{}

	CoordinateIterator(typename Coord::value_type c)
		: ii(c)
	{}

private:
	friend class boost::iterator_core_access;

	bool equal(CoordinateIterator const & other) const
	{
		return ii == other.ii;
	}

	void decrement()
	{
		--ii;
	}

	void increment()
	{
		++ii;
	}

	Coord dereference() const
	{
		return Coord(ii);
	}

	typename Coord::value_type ii;
};

} // namespace detail

} // namespace common
} // namespace halco
#endif // !PYPLUSPLUS
