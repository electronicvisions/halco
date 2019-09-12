#pragma once

#include "halco/common/traits.h"
#include "halco/common/relations.h"


namespace halco {
namespace common {
namespace detail {

#ifndef PYPLUSPLUS
namespace tblr {

/**
 * @brief Type trait that returns the RantWrapper type corresponding to the horizontal
 *        component of \c T or \c T itself.
 * This either choses \c x_type (e.g. for grid coordinates) or \c value_type (e.g. when
 * the type itself inherits from RantWrapper).
 * @note This does not check for \c XRangedTrait.
 */
template <typename T, typename = void>
struct HorizontalType {
	static_assert(sizeof(T) == 0, "HorizontalType not defined for this coordinate type");
};

template <typename T>
struct HorizontalType<T, void_t<typename T::value_type> > {
	typedef T type;
	typedef typename T::value_type (T::*function_type)() const;

	static constexpr function_type getter = &T::value;
};

template<typename T>
constexpr typename HorizontalType<T, void_t<typename T::value_type> >::function_type
    HorizontalType<T, void_t<typename T::value_type> >::getter;

template <typename T>
struct HorizontalType<T, void_t<typename T::x_type> > {
	typedef typename T::x_type type;
	typedef type (T::*function_type)() const;

	static constexpr function_type getter = &T::x;
};

template<typename T>
constexpr typename HorizontalType<T, void_t<typename T::x_type> >::function_type
    HorizontalType<T, void_t<typename T::x_type> >::getter;

/**
 * @brief Type trait that returns the RantWrapper type corresponding to the vertical
 *        component of \c T or \c T itself.
 * This either choses \c y_type (e.g. for grid coordinates) or \c value_type (e.g. when
 * the type itself inherits from RantWrapper).
 * @note This does not check for \c YRangedTrait.
 */
template <typename T, typename = void>
struct VerticalType {
	static_assert(sizeof(T) == 0, "VerticalType not defined for this coordinate type");
};

template <typename T>
struct VerticalType<T, void_t<typename T::value_type> > {
	typedef T type;
	typedef typename T::value_type (T::*function_type)() const;

	static constexpr function_type getter = &T::value;
};

template<typename T>
constexpr typename VerticalType<T, void_t<typename T::value_type> >::function_type
    VerticalType<T, void_t<typename T::value_type> >::getter;

template<typename T>
struct VerticalType<T, void_t<typename T::y_type> > {
	typedef typename T::y_type type;
	typedef type (T::*function_type)() const;

	static constexpr function_type getter = &T::y;
};

template<typename T>
constexpr typename VerticalType<T, void_t<typename T::y_type> >::function_type
    VerticalType<T, void_t<typename T::y_type> >::getter;

} // namespace tblr
#endif

/**
 * @brief Mixin for a coordinate that has natural top and bottom regions.
 */
template <typename Derived>
class HasTopBottom {
#ifndef PYPLUSPLUS
	typedef tblr::VerticalType<Derived> vertical_type;
#endif

public:
	bool isTop() const {
#ifndef PYPLUSPLUS
		static_assert(vertical_type::type::end % 2 == 0,
		              "HasTopBottom is only defined for even ranges");
		return ((static_cast<Derived const*>(this)->*vertical_type::getter)() <
		        vertical_type::type::end / 2);
#else
		return false;
#endif
	}

	bool isBottom() const { return !isTop(); }

	SideVertical toSideVertical() const { return isTop() ? top : bottom; }
};

/**
 * @brief Mixin for a coordinate that has natural left and right regions.
 */
template <typename Derived>
class HasLeftRight {
#ifndef PYPLUSPLUS
	typedef tblr::HorizontalType<Derived> horizontal_type;
#endif

public:
	bool isLeft() const {
#ifndef PYPLUSPLUS
		static_assert(horizontal_type::type::end % 2 == 0,
		              "HasLeftRight is only defined for even ranges");
		return ((static_cast<Derived const*>(this)->*horizontal_type::getter)() <
		        horizontal_type::type::end / 2);
#else
		return false;
#endif
	}

	bool isRight() const { return !isLeft(); }

	SideHorizontal toSideHorizontal() const { return isLeft() ? left : right; }
};

} // namespace detail
} // namespace common
} // namespace halco
