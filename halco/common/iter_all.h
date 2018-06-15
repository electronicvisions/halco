#pragma once
#ifndef PYPLUSPLUS

#include <boost/iterator/iterator_facade.hpp>

#include "halco/common/traits.h"

namespace halco {
namespace common {

namespace detail {

template <typename Coord>
struct CoordinateProxy
{
	typedef detail::limits<Coord> traits;

	struct iterator :
		public boost::iterator_facade<
		iterator,
		Coord,
		boost::bidirectional_traversal_tag,
		Coord
		>
	{
	public:
		iterator() : ii(traits::end)
		{}

		iterator(typename traits::value_type v)
			: ii(v)
		{}

	private:
		friend class boost::iterator_core_access;

		typedef Coord reference;

		bool equal(iterator const & other) const
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

		reference dereference() const
		{
			Coord c;
			using detail::from_number;
			from_number(c, ii);
			return c;
		}

		typename traits::value_type ii;
	};

	static iterator begin() { return iterator(traits::begin); }
	static iterator end()   { return iterator(traits::end); }
};

} // namespace detail

template <typename T>
detail::CoordinateProxy<T> iter_all()
{
	return detail::CoordinateProxy<T>();
}

} // namespace common
} // namespace halco
#endif // !PYPLUSPLUS
