#pragma once

#include <utility>
#include <ostream>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/utility.hpp>

#include "pywrap/compat/macros.hpp"
#include "pywrap/compat/hash.hpp"

namespace halco {
namespace hicann {
namespace v2 {

template<typename A, typename B>
class MergerProxy
{
public:
	PYPP_CONSTEXPR MergerProxy(A const& a, B const& b) :
		mValues(a, b) {}
	PYPP_DEFAULT(PYPP_CONSTEXPR MergerProxy());
	PYPP_DEFAULT(PYPP_CONSTEXPR MergerProxy(MergerProxy const&));
	PYPP_DEFAULT(MergerProxy& operator=(MergerProxy const&));

	A const& left()  const { return mValues.first; }
	B const& right() const { return mValues.second; }

	friend std::ostream& operator<< (std::ostream& os, MergerProxy<A, B> const& m)
	{
		return os << "left: " << m.left() << " right: " << m.right();
	}

private:
	std::pair<A, B> mValues;

	friend class boost::serialization::access;
	template<typename Archiver>
	void serialize(Archiver& ar, unsigned int const)
	{
		ar & boost::serialization::make_nvp("values", mValues);
	}
};

} // v2
} // hicann
} // halco

namespace std {

template<typename A, typename B>
struct hash< ::halco::hicann::v2::MergerProxy<A, B> >
{
	size_t operator()( ::halco::hicann::v2::MergerProxy<A, B> const & t) const
	{
		static size_t seed = boost::hash_value(typeid(t).name());
		size_t hash = seed;
		boost::hash_combine(hash, t.left());
		boost::hash_combine(hash, t.right());
		return hash;
	}
};

} // std
