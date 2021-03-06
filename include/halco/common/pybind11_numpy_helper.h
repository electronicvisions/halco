#pragma once
#if !defined(__GENPYBIND__) && !defined(__GENPYBIND_GENERATED__)
#error "This header is only meant for use in genpybind environment"
#endif

#include <stdexcept>
#include <type_traits>
#include <utility>

#include <pybind11/numpy.h>

#include "halco/common/traits.h"

namespace halco::common::detail {

template <typename T, typename = void>
struct has_base_t : std::false_type
{};

template <typename T>
struct has_base_t<T, std::void_t<typename T::base_t>> : std::true_type
{};

template <typename T, typename = void>
struct has_enum_type : std::false_type
{};

template <typename T>
struct has_enum_type<T, std::void_t<typename T::enum_type>> : std::true_type
{};

template <typename T>
auto to_numpy(T const& self)
{
	auto const copy_1d = [](auto const& s, auto& ret) {
		auto access = ret.mutable_unchecked();
		size_t index = 0;
		for (auto const& elem : s) {
			access[index] = elem;
			index++;
		}
	};

	auto const copy_2d = [](auto const& s, auto& ret) {
		auto access = ret.template mutable_unchecked<2>();
		size_t i = 0;
		for (auto const& row : s) {
			size_t j = 0;
			for (auto const& e : row) {
				access(i, j) = e;
				j++;
			}
			i++;
		}
	};

	if constexpr (has_base_t<typename T::value_type>::value) {
		if constexpr (
		    ::halco::common::detail::IsBaseType<typename T::value_type::base_t>::value ||
		    ::halco::common::detail::IsRantWrapper<typename T::value_type::base_t>::value) {
			auto ret = [&] {
				if constexpr (has_enum_type<typename T::value_type>::value) {
					return pybind11::array_t<typename T::value_type::local_type>(
					    std::tuple_size<T>::value);
				} else {
					return pybind11::array_t<typename T::value_type::value_type>(
					    std::tuple_size<T>::value);
				}
			}();
			copy_1d(self, ret);
			return ret;
		}
	} else if constexpr (std::is_arithmetic_v<typename T::value_type>) {
		auto ret = pybind11::array_t<typename T::value_type>(std::tuple_size<T>::value);
		copy_1d(self, ret);
		return ret;
	} else if constexpr ( // 2D
	    ::halco::common::detail::IsTypedArray<typename T::value_type>::value ||
	    ::halco::common::detail::IsTypedHeapArray<typename T::value_type>::value) {
		if constexpr (has_base_t<typename T::value_type::value_type>::value) {
			if constexpr (
			    ::halco::common::detail::IsBaseType<
			        typename T::value_type::value_type::base_t>::value ||
			    ::halco::common::detail::IsRantWrapper<
			        typename T::value_type::value_type::base_t>::value) {
				auto ret = pybind11::array_t<typename T::value_type::value_type::value_type>(
				    {std::tuple_size<T>::value, std::tuple_size<typename T::value_type>::value});
				copy_2d(self, ret);
				return ret;
			}
		} else if constexpr (std::is_arithmetic_v<typename T::value_type::value_type>) {
			auto ret = pybind11::array_t<typename T::value_type::value_type>(
			    {std::tuple_size<T>::value, std::tuple_size<typename T::value_type>::value});
			copy_2d(self, ret);
			return ret;
		}
	}
	throw std::runtime_error("to_numpy: No known conversion of value type to numpy array.");
}

template <typename T>
void from_numpy(T& self, pybind11::array const& array)
{
	auto const check_1d = [](auto const& a, auto const& s) {
		if (a.ndim() != 1) {
			throw std::runtime_error("Number of dimensions to assign to typed_array must be one.");
		}
		if (static_cast<size_t>(a.size()) != s.size()) {
			throw std::runtime_error("Input shape does not match.");
		}
	};

	auto const copy_1d = [](auto const& a, auto& s) {
		size_t index = 0;
		for (auto& elem : s) {
			elem = std::remove_reference_t<std::remove_cv_t<decltype(s.front())>>(a(index));
			index++;
		}
	};

	auto const copy_2d = [](auto const& a, auto& s) {
		if (static_cast<size_t>(a.shape(0)) != s.size() ||
		    static_cast<size_t>(a.shape(1)) !=
		        std::tuple_size<typename std::remove_reference_t<decltype(s)>::value_type>::value) {
			throw std::runtime_error("Input shape does not match.");
		}
		size_t i = 0;
		for (auto& row : s) {
			size_t j = 0;
			for (auto& e : row) {
				e = std::remove_reference_t<std::remove_cv_t<decltype(s.front().front())>>(a(i, j));
				j++;
			}
			i++;
		}
	};

	if constexpr (has_base_t<typename T::value_type>::value) {
		if constexpr (
		    ::halco::common::detail::IsBaseType<typename T::value_type::base_t>::value ||
		    ::halco::common::detail::IsRantWrapper<typename T::value_type::base_t>::value) {
			check_1d(array, self);
			auto const array_t = [&] {
				if constexpr (has_enum_type<typename T::value_type>::value) {
					return pybind11::array_t<typename T::value_type::local_type>(array);
				} else {
					return pybind11::array_t<typename T::value_type::value_type>(array);
				}
			}();
			auto const access = array_t.template unchecked<1>();
			copy_1d(access, self);
			return;
		}
	} else if constexpr (std::is_arithmetic_v<typename T::value_type>) {
		check_1d(array, self);
		auto const array_t = pybind11::array_t<typename T::value_type>(array);
		auto const access = array_t.template unchecked<1>();
		copy_1d(access, self);
		return;
	} else if constexpr ( // 2D
	    ::halco::common::detail::IsTypedArray<typename T::value_type>::value ||
	    ::halco::common::detail::IsTypedHeapArray<typename T::value_type>::value) {
		if (array.ndim() != 2) {
			throw std::runtime_error("Number of dimensions to assign to matrix must be two.");
		}
		if constexpr (has_base_t<typename T::value_type::value_type>::value) {
			if constexpr (
			    ::halco::common::detail::IsBaseType<
			        typename T::value_type::value_type::base_t>::value ||
			    ::halco::common::detail::IsRantWrapper<
			        typename T::value_type::value_type::base_t>::value) {
				auto const array_t =
				    pybind11::array_t<typename T::value_type::value_type::value_type>(array);
				auto const access = array_t.template unchecked<2>();
				copy_2d(access, self);
				return;
			}
		} else if constexpr (std::is_arithmetic_v<typename T::value_type::value_type>) {
			auto const array_t = pybind11::array_t<typename T::value_type::value_type>(array);
			auto const access = array_t.template unchecked<2>();
			copy_2d(access, self);
			return;
		}
	}
	throw std::runtime_error("from_numpy: No known conversion of numpy array to value type.");
}

} // namespace halco::common::detail
