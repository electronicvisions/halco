#pragma once
#include "halco/common/genpybind.h"
#include "hate/visibility.h"
#if (not defined(__ppu__)) and (not defined(PYPLUSPLUS))
#include <iosfwd>
#include <memory>
#include <typeindex>
#endif

namespace halco {
namespace common GENPYBIND_TAG_HALCO_COMMON {

/**
 * Coordinate base type for containers.
 */
struct SYMBOL_VISIBLE GENPYBIND(visible) Coordinate
{
#if (not defined(__ppu__)) and (not defined(PYPLUSPLUS))
	virtual ~Coordinate() = 0;

	virtual std::unique_ptr<Coordinate> clone() const GENPYBIND(hidden) = 0;

	virtual std::ostream& print(std::ostream& os) const GENPYBIND(hidden) = 0;

	friend std::ostream& operator<<(std::ostream& os, Coordinate const& coordinate) SYMBOL_VISIBLE;

	virtual bool operator==(Coordinate const& other) const = 0;
	virtual bool operator!=(Coordinate const& other) const = 0;
	virtual bool operator<(Coordinate const& other) const = 0;
	virtual bool operator>(Coordinate const& other) const = 0;
	virtual bool operator<=(Coordinate const& other) const = 0;
	virtual bool operator>=(Coordinate const& other) const = 0;
#endif
};


template <typename Derived>
struct CoordinateBase : public Coordinate
{
#if (not defined(__ppu__)) and (not defined(PYPLUSPLUS))
	virtual std::unique_ptr<common::Coordinate> clone() const GENPYBIND(hidden)
	{
		return std::make_unique<Derived>(static_cast<Derived const&>(*this));
	}

	virtual std::ostream& print(std::ostream& os) const GENPYBIND(hidden)
	{
		return os << static_cast<Derived const&>(*this);
	}

	virtual bool operator==(Coordinate const& other) const
	{
		if (auto const other_ptr = dynamic_cast<Derived const*>(&other)) {
			return static_cast<Derived const&>(*this) == *other_ptr;
		}
		return false;
	}

	virtual bool operator!=(Coordinate const& other) const
	{
		return !(*this == other);
	}

	/**
	 * Less comparison operator.
	 * For coordinates of equal type use their comparison, for different types use comparison
	 * operator of std::type_index.
	 */
	virtual bool operator<(Coordinate const& other) const
	{
		if (auto const other_ptr = dynamic_cast<Derived const*>(&other)) {
			return static_cast<Derived const&>(*this) < *other_ptr;
		}
		return std::type_index{typeid(*this)} < std::type_index{typeid(other)};
	}

	/**
	 * Greater comparison operator.
	 * For coordinates of equal type use their comparison, for different types use comparison
	 * operator of std::type_index.
	 */
	virtual bool operator>(Coordinate const& other) const
	{
		if (auto const other_ptr = dynamic_cast<Derived const*>(&other)) {
			return static_cast<Derived const&>(*this) > *other_ptr;
		}
		return std::type_index{typeid(*this)} > std::type_index{typeid(other)};
	}

	virtual bool operator<=(Coordinate const& other) const
	{
		return !(*this > other);
	}

	virtual bool operator>=(Coordinate const& other) const
	{
		return !(*this < other);
	}
#endif
};

} // namespace common
} // namespace halco
