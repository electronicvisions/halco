#pragma once

#include <bitset>
#include <ostream>
#include <stdexcept>

#include <boost/serialization/serialization.hpp>
#include <boost/serialization/base_object.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_base_of.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/punctuation/comma.hpp>

#include "pywrap/compat/debug.hpp"
#include "pywrap/compat/rant.hpp"
#include "pywrap/compat/macros.hpp"
#include "pywrap/compat/hash.hpp"

#include "halco/common/genpybind.h"

#ifndef PYPLUSPLUS
#include "halco/common/cerealization.h"
#endif

namespace halco {
namespace common GENPYBIND(tag(common)) {


namespace detail {

#define DETAIL_COMPARE(NAME, OP) \
	friend bool operator OP (NAME const& lhs, NAME const& rhs) \
	{ \
		return lhs.value() OP rhs.value(); \
	}

#define DETAIL_OSTREAM(DERIVED_NAME)                                                               \
	friend std::ostream& operator<<(std::ostream& os, const base_t& d) GENPYBIND(hidden)           \
	{                                                                                              \
		return _write(os, static_cast<const DERIVED_NAME&>(d));                                    \
	}                                                                                              \
	friend std::ostream& operator<<(std::ostream& os, const DERIVED_NAME& d)                       \
		GENPYBIND(stringstream)                                                                    \
	{                                                                                              \
		return _write(os, d);                                                                      \
	}

#define DETAIL_ISTREAM(DERIVED_NAME)                                                               \
	std::istream& operator>>(std::istream& is) GENPYBIND(hidden)                                   \
	{                                                                                              \
		is >> mValue;                                                                              \
		return is;                                                                                 \
	}                                                                                              \
	friend std::istream& operator>>(std::istream& is, DERIVED_NAME& d) GENPYBIND(hidden)           \
	{                                                                                              \
		return d.operator>>(is);                                                                   \
	}

template<typename T>
T _print(T const& t)
{
	return t;
}

inline int _print(unsigned char c)
{
	return c;
}

template<typename T>
std::ostream & _write(std::ostream& os, T const & t)
{
	static std::string const name = ZTL::typestring<T>().substr(
		ZTL::typestring<T>().rfind(':')+1);
	return os << name << "(" << _print(t.value()) << ")";
}

} // namespace detail

struct Enum;

namespace detail {

// Base types
template<typename Derived, typename T>
struct BaseType
{
public:
	typedef T value_type;
	typedef BaseType<Derived, T> base_t;

	PYPP_CONSTEXPR explicit BaseType(value_type const& val = 0) :
		mValue(val) {}

	PYPP_DEFAULT(PYPP_CONSTEXPR BaseType(base_t const&));
	PYPP_DEFAULT(base_t& operator= (base_t const&));
	base_t& operator= (value_type const& rhs)
	{
		mValue = rhs;
		return *this;
	}

	GENPYBIND(expose_as(__int__))
	PYPP_CONSTEXPR operator value_type() const { return mValue; }

	PYPP_CONSTEXPR value_type value() const { return mValue; }
	PYPP_CONSTEXPR Enum toEnum() const;

	DETAIL_COMPARE(Derived, ==)
	DETAIL_COMPARE(Derived, !=)
	DETAIL_COMPARE(Derived, <)
	DETAIL_COMPARE(Derived, >)
	DETAIL_COMPARE(Derived, <=)
	DETAIL_COMPARE(Derived, >=)
	DETAIL_OSTREAM(Derived)
	DETAIL_ISTREAM(Derived)

	GENPYBIND(expose_as(__hash__))
	size_t hash() const
	{
		// We include the type name in the hash to reduce the number of hash collisions in
		// python code, where __hash__ is used in heterogeneous containers.
		static const size_t seed = boost::hash_value(typeid(base_t).name());
		size_t hash = seed;
		boost::hash_combine(hash, value());
		return hash;
	}

	friend size_t hash_value(base_t t) {
		return t.hash();
	}

private:
	value_type mValue;

	friend class boost::serialization::access;
	template<typename Archiver>
	void serialize(Archiver& ar, unsigned int const)
	{
		using namespace boost::serialization;
		ar & make_nvp("value", mValue);
	}

#ifndef PYPLUSPLUS
	friend class cereal::access;
	template <class Archive>
	void cerealize(Archive& ar)
	{
		ar(CEREAL_NVP_("value", mValue));
	}

	static_assert(boost::is_fundamental<T>::value || std::is_same<std::string, T>::value,
				  "BaseType is intended to be used with numbers");
#endif
};

} // namespace detail


struct GENPYBIND(inline_base("*BaseType*")) X : public detail::BaseType<X, size_t>
{
	PYPP_CONSTEXPR explicit X(size_t val = 0) : base_t(val) {}
};

struct GENPYBIND(inline_base("*BaseType*")) Y : public detail::BaseType<Y, size_t>
{
	PYPP_CONSTEXPR explicit Y(size_t val = 0) : base_t(val) {}
};

struct GENPYBIND(inline_base("*BaseType*")) Enum : public detail::BaseType<Enum, size_t>
{
	PYPP_CONSTEXPR explicit Enum(size_t val = 0) : base_t(val) {}
};

template<typename Derived, typename T>
PYPP_CONSTEXPR Enum detail::BaseType<Derived, T>::toEnum() const
{
#ifndef PYPLUSPLUS
	return Enum{mValue};
#endif
}


namespace detail {

template<typename Derived, typename T, T Max, T Min>
class RantWrapper
{
public:
	typedef T value_type;
	typedef Derived derived_type;
	typedef RantWrapper<Derived, T, Max, Min> rant_t;
	typedef RantWrapper<Derived, T, Max, Min> base_t;

	PYPP_CONSTEXPR RantWrapper() : mValue(value_type(0)) {}

	template<typename U>
	PYPP_CONSTEXPR explicit RantWrapper(U const val) : mValue(val) {}

	PYPP_DEFAULT(PYPP_CONSTEXPR RantWrapper(RantWrapper const&));
	PYPP_DEFAULT(RantWrapper& operator= (RantWrapper const&));
	RantWrapper& operator= (value_type const& rhs)
	{
		mValue = rhs;
		return *this;
	}

	GENPYBIND(expose_as(__int__))
	PYPP_CONSTEXPR operator value_type() const { return static_cast<value_type>(mValue); }

	PYPP_CONSTEXPR value_type value() const { return mValue; }
	PYPP_CONSTEXPR Enum toEnum() const { return Enum(mValue); }

	static const T max    = Max;
	static const T end    = Max + 1;
	static const T size   = Max - Min + 1;
	static const T min    = Min;
	static const T begin  = Min;

	DETAIL_COMPARE(Derived, ==)
	DETAIL_COMPARE(Derived, !=)
	DETAIL_COMPARE(Derived, <)
	DETAIL_COMPARE(Derived, >)
	DETAIL_COMPARE(Derived, <=)
	DETAIL_COMPARE(Derived, >=)
	DETAIL_OSTREAM(Derived)
	DETAIL_ISTREAM(Derived)

	GENPYBIND(expose_as(__hash__))
	size_t hash() const
	{
		// We include the type name in the hash to reduce the number of hash collisions in
		// python code, where __hash__ is used in heterogeneous containers.
		static const size_t seed = boost::hash_value(typeid(rant_t).name());
		size_t hash = seed;
		boost::hash_combine(hash, value());
		return hash;
	}

	friend size_t hash_value(rant_t t) {
		return t.hash();
	}

private:
	rant::integral_range<T, Max, Min> mValue;
#ifndef PYPLUSPLUS
	friend class cereal::access;
#endif
	friend class boost::serialization::access;
	template<typename Archiver>
	void serialize(Archiver& ar, unsigned int const x)
	{
		boost::serialization::serialize(ar, mValue, x);
	}

#ifndef PYPLUSPLUS
	template<typename Archive>
	void cerealize(Archive& ar)
	{
		ar(CEREAL_NVP_("value", mValue));
	}
#endif
};

template<typename Derived, typename T, T Max, T Min>
const T RantWrapper<Derived, T, Max, Min>::max;

template<typename Derived, typename T, T Max, T Min>
const T RantWrapper<Derived, T, Max, Min>::end;

template<typename Derived, typename T, T Max, T Min>
const T RantWrapper<Derived, T, Max, Min>::size;

template<typename Derived, typename T, T Max, T Min>
const T RantWrapper<Derived, T, Max, Min>::begin;

template<typename Derived, typename T, T Max, T Min>
const T RantWrapper<Derived, T, Max, Min>::min;

#undef DETAIL_COMPARE
#undef DETAIL_OSTREAM
#undef DETAIL_ISTREAM

struct XRangedTrait {};
struct YRangedTrait {};
struct EnumRangedTrait {};

#define RangedIMPL(name, suffix, derived, type, max, min)                                          \
	struct GENPYBIND(visible(default), inline_base("*")) name suffix PYPP_FINAL                    \
		: public RantWrapper<derived, type ::value_type, max, min>                                 \
		, public BOOST_PP_CAT(name, Trait)                                                         \
	{                                                                                              \
	private:                                                                                       \
		typedef RantWrapper<derived, type ::value_type, max, min> rant_t;                          \
                                                                                                   \
	public:                                                                                        \
		PYPP_CONSTEXPR explicit name(size_t v = 0) : rant_t(v) {}                                  \
		PYPP_CONSTEXPR name(type const& v) GENPYBIND(implicit_conversion) : rant_t(v) {}           \
		PYPP_DEFAULT(PYPP_CONSTEXPR name(name const&));                                            \
		PYPP_DEFAULT(name& operator=(name const&));                                                \
	}

template<X::value_type Max, X::value_type Min>
RangedIMPL(XRanged, /*_*/, XRanged<Max BOOST_PP_COMMA() Min>, X, Max, Min);

template<>
RangedIMPL(XRanged, <1 BOOST_PP_COMMA() 0>, XRanged<1 BOOST_PP_COMMA() 0>, X, 1, 0);

template<Y::value_type Max, Y::value_type Min>
RangedIMPL(YRanged, /*_*/, YRanged<Max BOOST_PP_COMMA() Min>, Y, Max, Min);

template<>
RangedIMPL(YRanged, <1 BOOST_PP_COMMA() 0>, YRanged<1 BOOST_PP_COMMA() 0>, Y, 1, 0);

template<Enum::value_type Size>
RangedIMPL(EnumRanged, /*_*/, EnumRanged<Size>, Enum, /*Max=*/Size - 1, 0);

#undef RangedIMPL


template<X::value_type Max, X::value_type Min>
inline std::ostream & _write(std::ostream& os, const XRanged<Max, Min> & v)
{
	return os << "X(" << v.value() << ")";
}

template<Y::value_type Max, Y::value_type Min>
inline std::ostream & _write(std::ostream& os, const YRanged<Max, Min> & v)
{
	return os << "Y(" << v.value() << ")";
}

template<Enum::value_type Size>
inline std::ostream & _write(std::ostream& os, const EnumRanged<Size> & v)
{
	return os << "Enum(" << v.value() << ")";
}

} // namespace detail

using detail::XRanged;
using detail::YRanged;
using detail::EnumRanged;

namespace detail {

template<typename Derived, typename XT, typename YT, size_t EnumSize = (XT::size * YT::size)>
struct GridCoordinate {
	typedef XT x_type GENPYBIND(opaque(false));
	typedef YT y_type GENPYBIND(opaque(false));

#ifndef PYPLUSPLUS
	static_assert(boost::is_base_of<detail::XRangedTrait, x_type>::value,
		"Only XRanged is allowed as x type of GridCoordinate");
	static_assert(boost::is_base_of<detail::YRangedTrait, y_type>::value,
		"Only YRanged is allowed as y type of GridCoordinate");
#endif

#ifndef PYPLUSPLUS
	static constexpr size_t size = EnumSize;
#else
	static const size_t size = EnumSize;
#endif

	typedef detail::EnumRanged<EnumSize> enum_type GENPYBIND(opaque(false));
	typedef GridCoordinate<Derived, x_type, y_type, EnumSize> grid_type;

	PYPP_CONSTEXPR explicit GridCoordinate(enum_type const& e) :
		mX(static_cast<Derived const*>(this)->to_x(e)),
		mY(static_cast<Derived const*>(this)->to_y(e))
	{}

	GridCoordinate(x_type const& x, y_type const& y) :
		mX(x), mY(y) { id(); /* throws for invalid x/y combination */ }

	PYPP_CONSTEXPR GridCoordinate() :
		mX(static_cast<Derived const*>(this)->to_x(enum_type(0))),
		mY(static_cast<Derived const*>(this)->to_y(enum_type(0)))
	{}

	PYPP_DEFAULT(PYPP_CONSTEXPR GridCoordinate(GridCoordinate const&));
	PYPP_DEFAULT(GridCoordinate& operator= (GridCoordinate const&));

	enum_type id() const { return static_cast<Derived const*>(this)->to_enum(mX, mY); }
	enum_type toEnum() const { return static_cast<Derived const*>(this)->to_enum(mX, mY); }
	x_type    x()  const { return mX; }
	y_type    y()  const { return mY; }

	friend bool operator<(Derived const& a, Derived const&b)
	{
		return a.id() < b.id();
	}

	friend bool operator>(Derived const& a, Derived const&b)
	{
		return a.id() > b.id();
	}

	friend bool operator==(Derived const& a, Derived const&b)
	{
		return a.x() == b.x() && a.y() == b.y();
	}

	friend bool operator!=(Derived const& a, Derived const&b)
	{
		return !(a == b);
	}

	GENPYBIND(stringstream)
	friend std::ostream& operator<<(std::ostream& os, const GridCoordinate& c)
	{
		static std::string const name =
			ZTL::typestring<Derived>().substr(ZTL::typestring<Derived>().rfind(':') + 1);
		os << name << "(" << c.id() << ")";
		return os;
	}

	GENPYBIND(expose_as(__hash__))
	size_t hash() const
	{
		// We include the type name in the hash to reduce the number of hash collisions in
		// python code, where __hash__ is used in heterogeneous containers.
		static const size_t seed = boost::hash_value(typeid(Derived).name());
		size_t hash = seed;
		boost::hash_combine(hash, mX.value());
		boost::hash_combine(hash, mY.value());
		return hash;
	}

	friend size_t hash_value(Derived const& t) {
		return t.hash();
	}

protected:
	x_type mX;
	y_type mY;

	// default to_x implementation (static polymorphism)
	static PYPP_CONSTEXPR x_type to_x(enum_type const& e) GENPYBIND(hidden)
	{
		return x_type(x_type::min + e % x_type::size);
	}

	// default to_y implementation (static polymorphism)
	static PYPP_CONSTEXPR y_type to_y(enum_type const& e) GENPYBIND(hidden)
	{
		return y_type(y_type::min + e / x_type::size);
	}

	// default to_enum implementation (static polymorphism)
	static PYPP_CONSTEXPR enum_type to_enum(x_type const& x, y_type const& y) GENPYBIND(hidden)
	{
		return enum_type((y - y_type::min) * x_type::size + (x - x_type::min));
	}

private:
#ifndef PYPLUSPLUS
	friend class cereal::access;
#endif
	friend class boost::serialization::access;
	template<typename Archiver>
	void serialize(Archiver & ar, unsigned int const)
	{
		using boost::serialization::make_nvp;
		ar & make_nvp("x", mX)
		   & make_nvp("y", mY);

		// despite not part of the class's layout the enum coordinate is
		// serailized as well for Bjoern's visualization.
		enum_type e = id();
		ar & make_nvp("e", e);
	}

#ifndef PYPLUSPLUS
	template<typename Archive>
	void cerealize(Archive& ar)
	{
		ar(CEREAL_NVP_("x", mX));
		ar(CEREAL_NVP_("y", mY));

		// despite not part of the class's layout the enum coordinate is
		// serialized as well for Bjoern's visualization.
		enum_type e = id();
		ar(CEREAL_NVP_("e", e));
	}
#endif
};

#ifndef PYPLUSPLUS
template<typename Derived, typename XT, typename YT, size_t EnumSize>
size_t constexpr GridCoordinate<Derived, XT, YT, EnumSize>::size;
#endif // !PYPLUSPLUS

} // namespace detail

} // namespace common
} // namespace halco


#define GRID_COMMON_CONSTRUCTORS(cls)                                          \
	PYPP_CONSTEXPR explicit cls(const enum_type e) : grid_type(e) {}           \
                                                                               \
	cls(x_type const& x, y_type const& y) : grid_type(x, y) {}                 \
	cls(y_type const& y, x_type const& x) : grid_type(x, y) {}                 \
	cls(common::X const& x, common::Y const& y) : grid_type(x_type(x), y_type(y)) {} \
	cls(common::Y const& y, common::X const& x) : grid_type(x_type(x), y_type(y)) {} \
                                                                               \
	PYPP_DEFAULT(PYPP_CONSTEXPR cls());

#define HALCO_GEOMETRY_HASH(CLASS)                                                       \
	size_t operator()(CLASS const& t) const { return t.hash(); }

#define HALCO_GEOMETRY_HASH_CLASS(CLASS)                                                 \
	template <>                                                                          \
	struct hash<CLASS> {                                                                 \
		size_t operator()(CLASS const& t) const { return t.hash(); }                     \
	};

namespace std {

template<typename Derived, typename T, T Max, T Min>
struct hash< halco::common::detail::RantWrapper<Derived, T, Max, Min> >
{
	typedef halco::common::detail::RantWrapper<Derived, T, Max, Min> _type;
	HALCO_GEOMETRY_HASH(_type)
};

template<typename Derived, typename T>
struct hash< halco::common::detail::BaseType<Derived, T> >
{
	typedef halco::common::detail::BaseType<Derived, T> _type;
	HALCO_GEOMETRY_HASH(_type)
};

template <halco::common::Enum::value_type Size>
struct hash<halco::common::detail::EnumRanged<Size> >
{
	typedef halco::common::detail::EnumRanged<Size> _type;
	HALCO_GEOMETRY_HASH(_type)
};

template< halco::common::X::value_type Max, halco::common::X::value_type Min>
struct hash< halco::common::detail::XRanged<Max, Min> >
{
	typedef halco::common::detail::XRanged<Max, Min> _type;
	HALCO_GEOMETRY_HASH(_type)
};

template< ::halco::common::Y::value_type Max, ::halco::common::Y::value_type Min>
struct hash< halco::common::detail::YRanged<Max, Min> >
{
	typedef halco::common::detail::YRanged<Max, Min> _type;
	HALCO_GEOMETRY_HASH(_type)
};

template<typename Derived, typename XT, typename YT, size_t EnumSize>
struct hash<halco::common::detail::GridCoordinate<Derived, XT, YT, EnumSize> >
{
	typedef halco::common::detail::GridCoordinate<Derived, XT, YT, EnumSize> _type;
	HALCO_GEOMETRY_HASH(_type)
};

HALCO_GEOMETRY_HASH_CLASS(halco::common::X)
HALCO_GEOMETRY_HASH_CLASS(halco::common::Y)
HALCO_GEOMETRY_HASH_CLASS(halco::common::Enum)

} // std
