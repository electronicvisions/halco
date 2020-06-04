#pragma once

#ifndef PYPLUSPLUS
#include <type_traits>
#include <array>
#include <utility>
#include <iterator>
#include <algorithm>
#include <stdexcept>

#include "halco/common/traits.h"

#include "halco/common/genpybind.h"

#include <boost/serialization/array.hpp>

#endif

#if defined(__GENPYBIND__) || defined(__GENPYBIND_GENERATED__)
#include "halco/common/pybind11_numpy_helper.h"
#endif

namespace halco {
namespace common GENPYBIND_TAG_HALCO_COMMON {

/**
 * @brief A fixed-size container that is indexed via (typed) coordinates.
 *
 * Apart from element access functions this behaves the same as
 * \c std::array and has largely been thrown together from the
 * reference and libcxx / libstdc++ implementations.
 */

template <typename Value, typename Key, typename Limits = detail::limits<Key> >
struct typed_array {
	typedef Key key_type;
	typedef Value value_type;
	typedef value_type& reference;
	typedef value_type* iterator;
	typedef value_type* pointer;
	typedef value_type const& const_reference;
	typedef value_type const* const_iterator;
	typedef value_type const* const_pointer;
	typedef size_t size_type;
	typedef std::ptrdiff_t difference_type;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

#ifndef PYPLUSPLUS
	value_type elems[Limits::size > 0 ? Limits::size : 1] GENPYBIND(hidden);
#endif

	// aggregate types may not have explicit constructor / destructor

	void fill(value_type const& val) PYPP_HIDE_BODY({ std::fill_n(elems, Limits::size, val); })

#ifndef PYPLUSPLUS
	void GENPYBIND(hidden) swap(typed_array& other)
	  noexcept(noexcept(std::declval<std::array<Value, Limits::size> >().swap(
	    std::declval<std::array<Value, Limits::size> >()))) {
		std::swap_ranges(elems, elems + Limits::size, other.elems);
	}

	iterator GENPYBIND(hidden) begin() noexcept { return iterator(elems); }
	const_iterator GENPYBIND(hidden) begin() const noexcept { return const_iterator(elems); }
	iterator GENPYBIND(hidden) end() noexcept { return iterator(elems + Limits::size); }
	const_iterator GENPYBIND(hidden) end() const noexcept { return const_iterator(elems + Limits::size); }

	reverse_iterator GENPYBIND(hidden) rbegin() noexcept { return reverse_iterator(end()); }
	const_reverse_iterator GENPYBIND(hidden) rbegin() const noexcept {
		return const_reverse_iterator(end());
	}
	reverse_iterator GENPYBIND(hidden) rend() noexcept { return reverse_iterator(begin()); }
	const_reverse_iterator GENPYBIND(hidden) rend() const noexcept {
		return const_reverse_iterator(begin());
	}

	const_iterator GENPYBIND(hidden) cbegin() const noexcept { return begin(); }
	const_iterator GENPYBIND(hidden) cend() const noexcept { return end(); }
	const_reverse_iterator GENPYBIND(hidden) crbegin() const noexcept { return rbegin(); }
	const_reverse_iterator GENPYBIND(hidden) crend() const noexcept { return rend(); }
#endif

	GENPYBIND(getter_for(size))
	PYPP_CONSTEXPR size_type size() const PYPP_NOEXCEPT(true)
		PYPP_HIDE_BODY({ return Limits::size; })
	GENPYBIND(getter_for(max_size))
	PYPP_CONSTEXPR size_type max_size() const PYPP_NOEXCEPT(true)
		PYPP_HIDE_BODY({ return Limits::size; })
	GENPYBIND(getter_for(empty))
	PYPP_CONSTEXPR bool empty() const PYPP_NOEXCEPT(true)
		PYPP_HIDE_BODY({ return Limits::size == 0; })

#ifndef PYPLUSPLUS
	reference GENPYBIND(hidden) operator[](key_type const& key) {
		using detail::to_number;
		return elems[to_number(key) - Limits::min];
	}
	const_reference GENPYBIND(hidden) operator[](key_type const& key) const {
		using detail::to_number;
		return elems[to_number(key) - Limits::min];
	}
	reference at(key_type const& key);
	const_reference at(key_type const& key) const;

	reference front() { return elems[0]; }
	constexpr const_reference front() const { return elems[0]; }
	reference back() { return elems[Limits::size > 0 ? Limits::size - 1 : 0]; }
	constexpr const_reference back() const {
		return elems[Limits::size > 0 ? Limits::size - 1 : 0];
	}

	value_type* GENPYBIND(hidden) data() noexcept { return elems; }
	value_type const* GENPYBIND(hidden) data() const noexcept { return elems; }
#endif

	GENPYBIND(expose_as(__getitem__), return_value_policy(reference))
	const_reference get(Key const& key) const PYPP_HIDE_BODY({ return at(key); })

	GENPYBIND(expose_as(__setitem__))
	void set(Key const& key, Value const& value) PYPP_HIDE_BODY({ at(key) = value; })

	GENPYBIND_MANUAL({
		parent.def(
		    "__iter__",
		    [parent](GENPYBIND_PARENT_TYPE& self) { return parent->py::make_iterator(self); },
		    parent->py::template keep_alive<0, 1>());

		parent.def("to_numpy", [](GENPYBIND_PARENT_TYPE const& self) {
			return ::halco::common::detail::to_numpy(self);
		});
		parent.def("from_numpy", [](GENPYBIND_PARENT_TYPE& self, pybind11::array const& array) {
			::halco::common::detail::from_numpy(self, array);
		});
	})
};

#ifndef PYPLUSPLUS
namespace typed_array_enum_support {

template <typename T, T End, T Begin = static_cast<T>(0)>
class limits {
public:
	typedef typename std::underlying_type<T>::type value_type;
	static const value_type begin = static_cast<value_type>(Begin);
	static const value_type end = static_cast<value_type>(End);
	static const value_type size =
	  static_cast<value_type>(End) - static_cast<value_type>(Begin);
	static const value_type min = static_cast<value_type>(Begin);
	static const value_type max = static_cast<value_type>(End) - 1;
};

} // namespace typed_array_enum_support

template <typename Value, typename Key, typename Limits>
auto typed_array<Value, Key, Limits>::at(key_type const& key) -> reference {
	using detail::to_number;
	size_t idx = to_number(key) - Limits::min;
	if (idx >= Limits::size) {
		throw std::out_of_range("typed_array::at");
	}
	return elems[idx];
}

template <typename Value, typename Key, typename Limits>
auto typed_array<Value, Key, Limits>::at(key_type const& key) const -> const_reference {
	using detail::to_number;
	size_t idx = to_number(key) - Limits::min;
	if (idx >= Limits::size) {
		throw std::out_of_range("typed_array::at");
	}
	return elems[idx];
}

#endif

template <typename Value, typename Key, typename Limits>
inline bool operator==(typed_array<Value, Key, Limits> const& x,
                       typed_array<Value, Key, Limits> const& y)
	PYPP_HIDE_BODY({return std::equal(x.elems, x.elems + Limits::size, y.elems); })

template <typename Value, typename Key, typename Limits>
inline bool operator!=(typed_array<Value, Key, Limits> const& x,
                       typed_array<Value, Key, Limits> const& y) {
	return !(x == y);
}

template <typename Value, typename Key, typename Limits>
inline bool operator<(typed_array<Value, Key, Limits> const& x,
                      typed_array<Value, Key, Limits> const& y)
	PYPP_HIDE_BODY({return std::lexicographical_compare(
				x.elems, x.elems + Limits::size, y.elems, y.elems + Limits::size); })

template <typename Value, typename Key, typename Limits>
inline bool operator>(typed_array<Value, Key, Limits> const& x,
                      typed_array<Value, Key, Limits> const& y) {
	return y < x;
}

template <typename Value, typename Key, typename Limits>
inline bool operator<=(typed_array<Value, Key, Limits> const& x,
                       typed_array<Value, Key, Limits> const& y) {
	return !(y < x);
}

template <typename Value, typename Key, typename Limits>
inline bool operator>=(typed_array<Value, Key, Limits> const& x,
                       typed_array<Value, Key, Limits> const& y) {
	return !(x < y);
}

} // namespace common
} // namespace halco

#ifndef PYPLUSPLUS
namespace std {

// FIXME: unlike libstdc++, libcxx has enable_if here:
// enable_if<is_swappable<Value>::value, void>::type
template <typename Value, typename Key, typename Limits>
void
swap(halco::common::typed_array<Value, Key, Limits> const& x,
     halco::common::typed_array<Value, Key, Limits> const& y)
  noexcept(noexcept(x.swap(y))) {
	x.swap(y);
}

template <typename Value, typename Key, typename Limits>
struct tuple_size<halco::common::typed_array<Value, Key, Limits> >
  : public std::integral_constant<size_t, Limits::size> {};

template <size_t Pos, typename Value, typename Key, typename Limits>
struct tuple_element<Pos, halco::common::typed_array<Value, Key, Limits> > {
public:
	typedef Value type;
};

template <size_t Pos, typename Value, typename Key, typename Limits>
inline constexpr Value&
get(halco::common::typed_array<Value, Key, Limits>& a) noexcept {
	static_assert(Pos < Limits::size, "Index out of bounds in std::get<> (typed_array)");
	return a.elems[Pos];
}

template <size_t Pos, typename Value, typename Key, typename Limits>
inline constexpr Value const&
get(halco::common::typed_array<Value, Key, Limits> const& a) noexcept {
	static_assert(Pos < Limits::size, "Index out of bounds in std::get<> (typed_array)");
	return a.elems[Pos];
}

template <size_t Pos, typename Value, typename Key, typename Limits>
inline constexpr Value&&
get(halco::common::typed_array<Value, Key, Limits>&& a) noexcept {
	static_assert(Pos < Limits::size, "Index out of bounds in std::get<> (typed_array)");
	return std::move(a.elems[Pos]);
}

} // namespace std
#endif // PYPLUSPLUS


namespace boost {
namespace serialization {

template <typename Archiver, typename Value, typename Key, typename Limits>
void
serialize(Archiver& ar, halco::common::typed_array<Value, Key, Limits>& x,
          unsigned int const /*version*/)
	PYPP_HIDE_BODY({ar & boost::serialization::make_array(x.data(), x.size()); })

} // namespace serialization
} // namespace boost
