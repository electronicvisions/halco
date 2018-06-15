#pragma once

#ifndef PYPLUSPLUS
#include <type_traits>
#include <array>
#include <utility>
#include <iterator>
#include <algorithm>
#include <stdexcept>

#include "halco/common/traits.h"

#include <boost/serialization/array.hpp>

namespace halco {
namespace common {

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

	value_type elems[Limits::size > 0 ? Limits::size : 1];

	// aggregate types may not have explicit constructor / destructor

	void fill(value_type const& val) { std::fill_n(elems, Limits::size, val); }

	void swap(typed_array& other)
	  noexcept(noexcept(std::declval<std::array<Value, Limits::size> >().swap(
	    std::declval<std::array<Value, Limits::size> >()))) {
		std::swap_ranges(elems, elems + Limits::size, other.elems);
	}

	iterator begin() noexcept { return iterator(elems); }
	const_iterator begin() const noexcept { return const_iterator(elems); }
	iterator end() noexcept { return iterator(elems + Limits::size); }
	const_iterator end() const noexcept { return const_iterator(elems + Limits::size); }

	reverse_iterator rbegin() noexcept { return reverse_iterator(end()); }
	const_reverse_iterator rbegin() const noexcept {
		return const_reverse_iterator(end());
	}
	reverse_iterator rend() noexcept { return reverse_iterator(begin()); }
	const_reverse_iterator rend() const noexcept {
		return const_reverse_iterator(begin());
	}

	const_iterator cbegin() const noexcept { return begin(); }
	const_iterator cend() const noexcept { return end(); }
	const_reverse_iterator crbegin() const noexcept { return rbegin(); }
	const_reverse_iterator crend() const noexcept { return rend(); }

	constexpr size_type size() const noexcept { return Limits::size; }
	constexpr size_type max_size() const noexcept { return Limits::size; }
	constexpr bool empty() const noexcept { return Limits::size == 0; }

	reference operator[](key_type const& key) {
		using detail::to_number;
		return elems[to_number(key) - Limits::min];
	}
	const_reference operator[](key_type const& key) const {
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

	value_type* data() noexcept { return elems; }
	value_type const* data() const noexcept { return elems; }
};

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

template <typename Value, typename Key, typename Limits>
inline bool operator==(typed_array<Value, Key, Limits> const& x,
                       typed_array<Value, Key, Limits> const& y) {
	return std::equal(x.elems, x.elems + Limits::size, y.elems);
}

template <typename Value, typename Key, typename Limits>
inline bool operator!=(typed_array<Value, Key, Limits> const& x,
                       typed_array<Value, Key, Limits> const& y) {
	return !(x == y);
}

template <typename Value, typename Key, typename Limits>
inline bool operator<(typed_array<Value, Key, Limits> const& x,
                      typed_array<Value, Key, Limits> const& y) {
	return std::lexicographical_compare(x.elems, x.elems + Limits::size, y.elems,
	                                    y.elems + Limits::size);
}

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
class tuple_size<halco::common::typed_array<Value, Key, Limits> >
  : public std::integral_constant<size_t, Limits::size> {};

template <size_t Pos, typename Value, typename Key, typename Limits>
class tuple_element<Pos, halco::common::typed_array<Value, Key, Limits> > {
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

namespace boost {
namespace serialization {

template <typename Archiver, typename Value, typename Key, typename Limits>
void
serialize(Archiver& ar, halco::common::typed_array<Value, Key, Limits>& x,
          unsigned int const /*version*/) {
	ar & boost::serialization::make_array(x.data(), x.size());
}

} // namespace serialization
} // namespace boost
#endif // PYPLUSPLUS
