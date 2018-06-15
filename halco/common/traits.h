#pragma once

#ifndef PYPLUSPLUS
#include <type_traits>

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_base_and_derived.hpp>

#include "halco/common/geometry.h"

namespace halco {
namespace common {
namespace detail {

#if (__cplusplus < 201703L) || (defined(__clang_major__) && (__clang_major__ <= 6))
/* clang seems buggy w.r.t. "Equivalent but not functionally-equivalent redeclarations"
 * cf. https://clang.llvm.org/cxx_dr_status.html
 * easily tested here: https://wandbox.org/permlink/OkzrYjpCOuSHWTZC
 */
template <typename... Ts>
struct make_void {
	typedef void type;
};
template <typename... Ts>
using void_t = typename make_void<Ts...>::type;
#else
template <typename... Ts>
using void_t = std::void_t<Ts...>;
#endif

/**
 * @brief Limits of the specified coordinate class.
 * If the passed-in coordinate contains a nested \c value_type it is assumed to provide
 * an interface similar to \c RantWrapper.  For grid-like coordinates (detected by a
 * nested \c enum_type) the nested type is examined recursively.
 */
template <typename T, typename = void>
struct limits {
	static_assert(sizeof(T) == 0, "Limits not defined for this coordinate type");
};

template <typename T>
struct limits<T, void_t<typename T::enum_type> > : public limits<typename T::enum_type> {};

template <typename T>
struct limits<T, void_t<typename T::value_type> >
{
	typedef typename T::value_type value_type;
	static const value_type size = T::size;
	static const value_type min = T::min;
	static const value_type max = T::max;
	static const value_type begin = T::begin;
	static const value_type end = T::end;
};

template <size_t size, size_t... sizes>
struct size_product {
	static const size_t value = size * size_product<sizes...>::value;
};

template <size_t size>
struct size_product<size> {
	static const size_t value = size;
};

template <typename = void, typename... Ts>
struct maybe_ranged_enum_impl{
	typedef Enum type;
};

// FIXME: As the coordinate mixins currently do not define a `size` member
// (in contrast to `RantWrapper::size` and `GridCoordinate::size`, which this code uses),
// we will have to look for `enum_type::size` or eventually define a `size` member in
// the mixin CRTP class. (e.g. via C++17 `inline static`, which does not need an
// out-of-class definition)
template<typename... Ts>
struct maybe_ranged_enum_impl<void_t<decltype(Ts::size)...>, Ts...> {
	typedef EnumRanged<size_product<Ts::size...>::value> type;
};

template <typename... Ts>
using maybe_ranged_enum = maybe_ranged_enum_impl<void, Ts...>;

template <typename T, typename U>
auto from_number(T& t, U const val) -> decltype(std::declval<typename T::value_type>(), void()) {
	t = T(val);
}

template <typename T, typename U>
auto from_number(T& t, U const val) -> decltype(typename T::enum_type(val), void()) {
	t = T(typename T::enum_type(val));
}

template <typename T>
auto to_number(T const& val) -> decltype(val.toEnum()) {
	return val.toEnum();
}

namespace kludge {

// Using std::underlying_type on non-enum types is ill-formed.
template <typename T, typename Enable = void>
struct safe_underlying_type {};

template <typename T>
struct safe_underlying_type<T, typename std::enable_if<std::is_enum<T>::value >::type>
  : public std::underlying_type<T> {};

} // namespace kludge

template <typename T>
typename std::enable_if<std::is_enum<T>::value >::type
from_number(T& t, typename std::underlying_type<T>::type const val) {
	t = static_cast<T>(val);
}

template <typename T>
typename std::enable_if<std::is_enum<T>::value,
                        typename kludge::safe_underlying_type<T>::type>::type
to_number(T const& val) {
	return static_cast<typename std::underlying_type<T>::type>(val);
}

} // namespace detail
} // namespace common
} // namespace halco
#endif // PYPLUSPLUS
