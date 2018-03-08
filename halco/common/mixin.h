#pragma once

#include "halco/common/geometry.h"
#include "halco/common/traits.h"

#ifdef PYPLUSPLUS
#define HALCO_COORDINATE_MIXIN__ENUM_TYPE(...) \
	typename ::halco::common::detail::pypp_maybe_ranged_enum<__VA_ARGS__>::type
#else
#define HALCO_COORDINATE_MIXIN__ENUM_TYPE(...) \
	typename ::halco::common::detail::maybe_ranged_enum<__VA_ARGS__>::type
#endif

#define HALCO_COORDINATE_MIXIN(mixin, cls, fct)                                \
	template <typename Derived, typename T>                                    \
	class mixin : public T {                                                   \
		typedef void value_type;                                               \
                                                                               \
	public:                                                                    \
		typedef cls mixed_in_type;                                             \
		typedef T local_type;                                                  \
		typedef HALCO_COORDINATE_MIXIN__ENUM_TYPE(cls, T) enum_type;           \
                                                                               \
		mixin() {}                                                             \
		explicit mixin(T const t, cls const v) : T(t), mValue(v) {}            \
		explicit mixin(enum_type const& e)                                     \
			: T(::halco::common::Enum(e PYPP_EXCLUDE( % local_type::size)))    \
			, mValue(::halco::common::Enum(e PYPP_EXCLUDE(/ local_type::size))) {} \
                                                                               \
		cls BOOST_PP_CAT(to, cls)() const { return mValue; }                   \
		                                                                       \
		std::pair<cls, T> split() const {                                      \
			return std::make_pair(mValue, This());                             \
		}                                                                      \
                                                                               \
		friend bool operator<(Derived const& a, Derived const& b) {            \
			return a.mValue == b.mValue ? a.This() < b.This()                  \
			                            : a.mValue < b.mValue;                 \
		}                                                                      \
                                                                               \
		friend bool operator==(Derived const& a, Derived const& b) {           \
			return a.mValue == b.mValue && a.This() == b.This();               \
		}                                                                      \
                                                                               \
		friend bool operator!=(Derived const& a, Derived const& b) {           \
			return !(a == b);                                                  \
		}                                                                      \
                                                                               \
		GENPYBIND(stringstream)                                                \
		friend std::ostream& operator<<(std::ostream& os, const Derived& h) {  \
			static std::string const _s = ZTL::typestring<Derived>().substr(   \
			    ZTL::typestring<Derived>().rfind(':') + 1);                    \
			return os << _s << "(" << h.This() << ", " << h.mValue << ")";     \
		}                                                                      \
                                                                               \
		PYPP_DEFAULT(mixin& operator=(mixin const&));                          \
                                                                               \
		GENPYBIND(expose_as(__hash__))                                         \
		size_t hash() const {                                                  \
			static const size_t seed =                                         \
			    boost::hash_value(typeid(Derived).name());                     \
			size_t hash = seed;                                                \
			boost::hash_combine(hash, std::hash<T>()(This()));                 \
			boost::hash_combine(hash, mValue);                                 \
			return hash;                                                       \
		}                                                                      \
		                                                                       \
		friend size_t hash_value(Derived const& t) {                           \
			return t.hash();                                                   \
		}                                                                      \
                                                                               \
		enum_type toEnum() const {                                             \
			return enum_type(                                                  \
				mValue.toEnum() * local_type::size + This().toEnum());         \
		}                                                                      \
                                                                               \
	private:                                                                   \
		PYPP_DELETE(void id());                                                \
                                                                               \
	protected:                                                                 \
		cls mValue;                                                            \
                                                                               \
		T const& This() const { return static_cast<T const&>(*this); }         \
		T& This() { return static_cast<T&>(*this); }                           \
                                                                               \
		friend class boost::serialization::access;                             \
		template <typename Archiver>                                           \
		void serialize(Archiver& ar, unsigned int const v) {                   \
			ar& boost::serialization::make_nvp(BOOST_PP_STRINGIZE(fct),        \
			                                   mValue);                        \
			boost::serialization::access::serialize(ar, This(), v);            \
		}                                                                      \
	};
