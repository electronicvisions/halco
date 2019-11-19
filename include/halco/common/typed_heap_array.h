#pragma once

#ifndef PYPLUSPLUS
#include <algorithm>
#include <array>
#include <iterator>
#include <stdexcept>
#include <type_traits>
#include <utility>

#include "halco/common/traits.h"

#include "halco/common/genpybind.h"

#include <boost/serialization/array.hpp>

#endif

namespace halco {
namespace common GENPYBIND_TAG_HALCO_COMMON {

/**
 * A fixed-size heap-allocated container that is indexed via (typed) coordinates.
 */
template <typename Value, typename Key, typename Limits = detail::limits<Key> >
struct typed_heap_array
{
	typedef Key key_type;
	typedef Value value_type;
	typedef value_type& reference;
	typedef typename std::vector<value_type>::iterator iterator;
	typedef value_type* pointer;
	typedef value_type const& const_reference;
	typedef typename std::vector<value_type>::const_iterator const_iterator;
	typedef value_type const* const_pointer;
	typedef size_t size_type;
	typedef std::ptrdiff_t difference_type;
	typedef std::reverse_iterator<iterator> reverse_iterator;
	typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

private:
#ifndef PYPLUSPLUS
	std::vector<value_type> elems;

public:
	typed_heap_array() : elems(Limits::size > 0 ? Limits::size : 1) {}
#endif

	void fill(value_type const& val) PYPP_HIDE_BODY({ std::fill(elems.begin(), elems.end(), val); })

#ifndef PYPLUSPLUS
	void GENPYBIND(hidden) swap(typed_heap_array& other) noexcept(
	    std::declval<std::vector<Value> >().swap(std::declval<std::vector<Value> >()))
	{
		std::swap(elems, other.elems);
	}

	iterator GENPYBIND(hidden) begin() noexcept { return elems.begin(); }
	const_iterator GENPYBIND(hidden) begin() const noexcept { return elems.begin(); }
	iterator GENPYBIND(hidden) end() noexcept { return elems.end(); }
	const_iterator GENPYBIND(hidden) end() const noexcept { return elems.end(); }

	reverse_iterator GENPYBIND(hidden) rbegin() noexcept { return reverse_iterator(end()); }
	const_reverse_iterator GENPYBIND(hidden) rbegin() const noexcept
	{
		return const_reverse_iterator(end());
	}
	reverse_iterator GENPYBIND(hidden) rend() noexcept { return reverse_iterator(begin()); }
	const_reverse_iterator GENPYBIND(hidden) rend() const noexcept
	{
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
	PYPP_CONSTEXPR size_type max_size() const
	    PYPP_NOEXCEPT(true) PYPP_HIDE_BODY({ return Limits::size; })
	GENPYBIND(getter_for(empty))
	PYPP_CONSTEXPR bool empty() const PYPP_NOEXCEPT(true)
	    PYPP_HIDE_BODY({ return Limits::size == 0; })

#ifndef PYPLUSPLUS
	reference GENPYBIND(hidden)
	operator[](key_type const& key)
	{
		using detail::to_number;
		return elems[to_number(key) - Limits::min];
	}
	const_reference GENPYBIND(hidden) operator[](key_type const& key) const
	{
		using detail::to_number;
		return elems[to_number(key) - Limits::min];
	}
	reference at(key_type const& key);
	const_reference at(key_type const& key) const;

	reference front() { return elems[0]; }
	constexpr const_reference front() const { return elems[0]; }
	reference back() { return elems[Limits::size > 0 ? Limits::size - 1 : 0]; }
	constexpr const_reference back() const
	{
		return elems[Limits::size > 0 ? Limits::size - 1 : 0];
	}

	value_type* GENPYBIND(hidden) data() noexcept { return elems.data(); }
	value_type const* GENPYBIND(hidden) data() const noexcept { return elems.data(); }
#endif

	GENPYBIND(expose_as(__getitem__), return_value_policy(reference))
	const_reference get(Key const& key) const PYPP_HIDE_BODY({ return at(key); })

	GENPYBIND(expose_as(__setitem__))
	void set(Key const& key, Value const& value)
	    PYPP_HIDE_BODY({ at(key) = value; })

	GENPYBIND_MANUAL({
		parent.def(
		"__iter__",
		[parent](GENPYBIND_PARENT_TYPE& self) {
			return parent->py::make_iterator(self);
		},
		parent->py::template keep_alive<0, 1>());
	})

	bool operator==(typed_heap_array const& other) const { return elems == other.elems; }

	bool operator!=(typed_heap_array const& other) const { return !(*this == other); }

	bool operator<(typed_heap_array const& other) const { return elems < other.elems; }

	bool operator>(typed_heap_array const& other) const { return elems > other.elems; }

	bool operator<=(typed_heap_array const& other) const { return elems <= other.elems; }

	bool operator>=(typed_heap_array const& other) const { return elems >= other.elems; }
};

#ifndef PYPLUSPLUS
namespace typed_heap_array_enum_support {

template <typename T, T End, T Begin = static_cast<T>(0)>
class limits
{
public:
	typedef typename std::underlying_type<T>::type value_type;
	static const value_type begin = static_cast<value_type>(Begin);
	static const value_type end = static_cast<value_type>(End);
	static const value_type size = static_cast<value_type>(End) - static_cast<value_type>(Begin);
	static const value_type min = static_cast<value_type>(Begin);
	static const value_type max = static_cast<value_type>(End) - 1;
};

} // namespace typed_heap_array_enum_support

template <typename Value, typename Key, typename Limits>
auto typed_heap_array<Value, Key, Limits>::at(key_type const& key) -> reference
{
	using detail::to_number;
	size_t idx = to_number(key) - Limits::min;
	if (idx >= Limits::size) {
		throw std::out_of_range("typed_heap_array::at");
	}
	return elems[idx];
}

template <typename Value, typename Key, typename Limits>
auto typed_heap_array<Value, Key, Limits>::at(key_type const& key) const -> const_reference
{
	using detail::to_number;
	size_t idx = to_number(key) - Limits::min;
	if (idx >= Limits::size) {
		throw std::out_of_range("typed_heap_array::at");
	}
	return elems[idx];
}

#endif

} // namespace common
} // namespace halco

namespace boost {
namespace serialization {

template <typename Archiver, typename Value, typename Key, typename Limits>
void serialize(
    Archiver& ar,
    halco::common::typed_heap_array<Value, Key, Limits>& x,
    unsigned int const /*version*/)
    PYPP_HIDE_BODY({ ar& boost::serialization::make_array(x.data(), x.size()); })

} // namespace serialization
} // namespace boost
