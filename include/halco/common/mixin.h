#pragma once

#include <boost/core/enable_if.hpp>
#include "halco/common/geometry.h"
#include "halco/common/traits.h"

#if defined(PYPLUSPLUS)
#define HALCO_COORDINATE_MIXIN__ENUM_TYPE(...) \
	typename ::halco::common::detail::pypp_maybe_ranged_enum<__VA_ARGS__>::type
#else
#define HALCO_COORDINATE_MIXIN__ENUM_TYPE(...) \
	typename ::halco::common::detail::maybe_ranged_enum<__VA_ARGS__>::type
#endif

template <typename T, typename Enum, typename = void>
struct EnumMixin : public T
{
	EnumMixin() : T() {}
	EnumMixin(T const& t) : T(t) {}
};

#ifndef PYPLUSPLUS
template <typename T, typename Enum>
struct EnumMixin<T, Enum, typename boost::enable_if_has_type<decltype(Enum::size)>::type> : public T
{
	EnumMixin() : T() {}
	EnumMixin(T const& t) : T(t) {}
	inline static const size_t size = Enum::size;
	inline static const size_t min = Enum::min;
	inline static const size_t max = Enum::max;
};
#endif

#define HALCO_COORDINATE_MIXIN(mixin, cls, fct)                                                    \
	template <typename Derived, typename T>                                                        \
	class GENPYBIND(inline_base("*EnumMixin*")) mixin                                              \
	    : public EnumMixin<T, HALCO_COORDINATE_MIXIN__ENUM_TYPE(cls, T)>                           \
	{                                                                                              \
		typedef void value_type;                                                                   \
                                                                                                   \
	public:                                                                                        \
		typedef cls mixed_in_type;                                                                 \
		typedef T local_type;                                                                      \
		typedef mixin mixin_t;                                                                     \
		typedef HALCO_COORDINATE_MIXIN__ENUM_TYPE(cls, T) enum_type GENPYBIND(opaque(false));      \
		typedef EnumMixin<T, HALCO_COORDINATE_MIXIN__ENUM_TYPE(cls, T)> enum_mixin;                \
                                                                                                   \
		mixin() : enum_mixin(), mValue() {}                                                        \
		explicit mixin(T const t, cls const v) : enum_mixin(t), mValue(v) {}                       \
		explicit mixin(enum_type const& e) :                                                       \
		    enum_mixin(T(::halco::common::Enum(e PYPP_EXCLUDE(% local_type::size)))),              \
		    mValue(::halco::common::Enum(e PYPP_EXCLUDE(/ local_type::size)))                      \
		{}                                                                                         \
                                                                                                   \
		cls BOOST_PP_CAT(to, cls)() const                                                          \
		{                                                                                          \
			return mValue;                                                                         \
		}                                                                                          \
                                                                                                   \
		std::pair<cls, T> split() const                                                            \
		{                                                                                          \
			return std::make_pair(mValue, This());                                                 \
		}                                                                                          \
                                                                                                   \
		friend bool operator<(Derived const& a, Derived const& b)                                  \
		{                                                                                          \
			return a.mValue == b.mValue ? a.This() < b.This() : a.mValue < b.mValue;               \
		}                                                                                          \
                                                                                                   \
		friend bool operator<=(Derived const& a, Derived const& b)                                 \
		{                                                                                          \
			return !(a > b);                                                                       \
		}                                                                                          \
                                                                                                   \
		friend bool operator>(Derived const& a, Derived const& b)                                  \
		{                                                                                          \
			return !(a == b) && !(a < b);                                                          \
		}                                                                                          \
                                                                                                   \
		friend bool operator>=(Derived const& a, Derived const& b)                                 \
		{                                                                                          \
			return !(a < b);                                                                       \
		}                                                                                          \
                                                                                                   \
		friend bool operator==(Derived const& a, Derived const& b)                                 \
		{                                                                                          \
			return a.mValue == b.mValue && a.This() == b.This();                                   \
		}                                                                                          \
                                                                                                   \
		friend bool operator!=(Derived const& a, Derived const& b)                                 \
		{                                                                                          \
			return !(a == b);                                                                      \
		}                                                                                          \
                                                                                                   \
		GENPYBIND(stringstream)                                                                    \
		friend std::ostream& operator<<(std::ostream& os, const Derived& h)                        \
		{                                                                                          \
			static std::string const _s =                                                          \
			    ZTL::typestring<Derived>().substr(ZTL::typestring<Derived>().rfind(':') + 1);      \
			return os << _s << "(" << h.This() << ", " << h.mValue << ")";                         \
		}                                                                                          \
                                                                                                   \
		PYPP_DEFAULT(mixin& operator=(mixin const&));                                              \
                                                                                                   \
		GENPYBIND(expose_as(__hash__))                                                             \
		size_t hash() const                                                                        \
		{                                                                                          \
			static const size_t seed = boost::hash_value(typeid(Derived).name());                  \
			size_t hash = seed;                                                                    \
			boost::hash_combine(hash, std::hash<T>()(This()));                                     \
			boost::hash_combine(hash, mValue);                                                     \
			return hash;                                                                           \
		}                                                                                          \
                                                                                                   \
		friend size_t hash_value(Derived const& t)                                                 \
		{                                                                                          \
			return t.hash();                                                                       \
		}                                                                                          \
                                                                                                   \
		enum_type toEnum() const                                                                   \
		{                                                                                          \
			return enum_type(mValue.toEnum() * local_type::size + This().toEnum());                \
		}                                                                                          \
                                                                                                   \
		GENPYBIND(expose_as(__int__))                                                              \
		PYPP_CONSTEXPR operator typename enum_type::value_type() const                             \
		{                                                                                          \
			return toEnum().value();                                                               \
		}                                                                                          \
                                                                                                   \
		GENPYBIND_MANUAL({                                                                         \
			typedef typename decltype(parent)::type self_type;                                     \
			parent.def(parent->py::pickle(                                                         \
			    [](GENPYBIND_PARENT_TYPE const& self) { return self.toEnum().value(); },           \
			    [](typename self_type::enum_type::value_type const& value) {                       \
				    return self_type(self_type::enum_type(value));                                 \
			    }));                                                                               \
		})                                                                                         \
                                                                                                   \
	protected:                                                                                     \
		cls mValue;                                                                                \
                                                                                                   \
		T const& This() const                                                                      \
		{                                                                                          \
			return static_cast<T const&>(*this);                                                   \
		}                                                                                          \
		T& This()                                                                                  \
		{                                                                                          \
			return static_cast<T&>(*this);                                                         \
		}                                                                                          \
                                                                                                   \
		friend class boost::serialization::access;                                                 \
		template <typename Archiver>                                                               \
		void serialize(Archiver& ar, unsigned int const v)                                         \
		{                                                                                          \
			ar& boost::serialization::make_nvp(BOOST_PP_STRINGIZE(fct), mValue);                   \
			boost::serialization::access::serialize(ar, This(), v);                                \
		}                                                                                          \
	};
