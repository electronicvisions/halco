#pragma once

#ifndef PYPLUSPLUS
#include <type_traits>
#endif

#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_base_and_derived.hpp>

#include "halco/common/geometry.h"

namespace halco {
namespace common {

template <typename Value, typename Key, typename Limits>
struct typed_array;

template <typename Value, typename Key, typename Limits>
struct typed_heap_array;

namespace detail {

#if defined(PYPLUSPLUS)
// nothing
#elif (__cplusplus < 201703L) || (defined(__clang_major__) && (__clang_major__ <= 14))
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


/* some Py++ wrapping stuff (duplicates stuff in C++98) */
template <
	typename T1,
	typename T2 = void,
	typename T3 = void,
	typename T4 = void,
	typename T5 = void,
	typename T6 = void,
	typename T7 = void,
	typename T8 = void,
	typename T9 = void
>
struct pypp_make_void {
	typedef void type;
};

template<size_t I>
struct pypp_takesIntegral {};

template <size_t S0, size_t S1 = 1, size_t S2 = 1, size_t S3 = 1, size_t S4 = 1, size_t S5 = 1>
struct pypp_size_product {
	static const size_t value = S0 * S1 * S2 * S3 * S4 * S5;
};

// it's odr used by the boost python wrapper code
template <size_t S0, size_t S1, size_t S2, size_t S3, size_t S4, size_t S5>
const size_t pypp_size_product<S0, S1, S2, S3, S4, S5>::value;

template <typename T0 = void, typename T1 = void, typename T2 = void, typename T3 = void, typename T4 = void, typename T5 = void, typename = void>
struct pypp_maybe_ranged_enum
{
	typedef Enum type;
};

template<typename T0, typename T1, typename T2, typename T3, typename T4, typename T5>
struct pypp_maybe_ranged_enum<
	T0,
	T1,
	T2,
	T3,
	T4,
	T5,
	typename pypp_make_void <
		pypp_takesIntegral<T0::size>,
		pypp_takesIntegral<T1::size>,
		pypp_takesIntegral<T2::size>,
		pypp_takesIntegral<T3::size>,
		pypp_takesIntegral<T4::size>,
		pypp_takesIntegral<T5::size>
	>::type
> {
	typedef EnumRanged<pypp_size_product<T0::size, T1::size, T2::size, T3::size, T4::size, T5::size>::value> type;
};

template<typename T0, typename T1, typename T2, typename T3, typename T4>
struct pypp_maybe_ranged_enum<
	T0,
	T1,
	T2,
	T3,
	T4,
	typename pypp_make_void <
		pypp_takesIntegral<T0::size>,
		pypp_takesIntegral<T1::size>,
		pypp_takesIntegral<T2::size>,
		pypp_takesIntegral<T3::size>,
		pypp_takesIntegral<T4::size>
	>::type
> {
	typedef EnumRanged<pypp_size_product<T0::size, T1::size, T2::size, T3::size, T4::size>::value> type;
};

template<typename T0, typename T1, typename T2, typename T3>
struct pypp_maybe_ranged_enum<
	T0,
	T1,
	T2,
	T3,
	typename pypp_make_void <
		pypp_takesIntegral<T0::size>,
		pypp_takesIntegral<T1::size>,
		pypp_takesIntegral<T2::size>,
		pypp_takesIntegral<T3::size>
	>::type
> {
	typedef EnumRanged<pypp_size_product<T0::size, T1::size, T2::size, T3::size>::value> type;
};

template<typename T0, typename T1, typename T2>
struct pypp_maybe_ranged_enum<
	T0,
	T1,
	T2,
	typename pypp_make_void <
		pypp_takesIntegral<T0::size>,
		pypp_takesIntegral<T1::size>,
		pypp_takesIntegral<T2::size>
	>::type
> {
	typedef EnumRanged<pypp_size_product<T0::size, T1::size, T2::size>::value> type;
};

template<typename T0, typename T1>
struct pypp_maybe_ranged_enum<
	T0,
	T1,
	typename pypp_make_void <
		pypp_takesIntegral<T0::size>,
		pypp_takesIntegral<T1::size>
	>::type
> {
	typedef EnumRanged<pypp_size_product<T0::size, T1::size>::value> type;
};

template<typename T0>
struct pypp_maybe_ranged_enum<
	T0,
	typename pypp_make_void <
		pypp_takesIntegral<T0::size>
	>::type
> {
	typedef EnumRanged<T0::size> type;
};

/* end of Py++ duplication area */


#ifndef PYPLUSPLUS
template <typename T, typename = void>
struct has_mixin_t : std::false_type
{};

template <typename T>
struct has_mixin_t<T, void_t<typename T::mixin_t>> : std::true_type
{};

template <typename T>
struct limits<T, void_t<typename T::enum_type> > : public limits<typename T::enum_type> {};

template <typename T>
struct limits<T, void_t<typename T::value_type, std::enable_if_t<!has_mixin_t<T>::value>>>
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

/** Check whether a type is derived from BaseType. */
template <typename Derived, typename = void>
struct IsBaseType : std::false_type
{};

template <typename Derived, typename Value>
struct IsBaseType<BaseType<Derived, Value>> : std::true_type
{};

/** Check whether a type is derived from RantWrapper. */
template <typename Derived, typename = void>
struct IsRantWrapper : std::false_type
{};

template <typename Derived, typename T, T Max, T Min>
struct IsRantWrapper<RantWrapper<Derived, T, Max, Min>> : std::true_type
{};

/** Check whether a type is a typed_array. */
template <typename T>
struct IsTypedArray : std::false_type
{};

template <typename Value, typename Key, typename Limits>
struct IsTypedArray<typed_array<Value, Key, Limits>> : std::true_type
{};

/** Check whether a type is a typed_heap_array. */
template <typename T>
struct IsTypedHeapArray : std::false_type
{};

template <typename Value, typename Key, typename Limits>
struct IsTypedHeapArray<typed_heap_array<Value, Key, Limits>> : std::true_type
{};

#endif // !PYPLUSPLUS

} // namespace detail
} // namespace common
} // namespace halco
