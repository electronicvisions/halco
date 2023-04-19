#pragma once
#include "halco/common/genpybind.h"
#if (not defined(__ppu__)) and (not defined(PYPLUSPLUS))
#include <iosfwd>
#include <memory>
#endif

namespace halco {
namespace common GENPYBIND_TAG_HALCO_COMMON {

/**
 * Coordinate base type for containers.
 */
struct GENPYBIND(visible) Coordinate
{
#if (not defined(__ppu__)) and (not defined(PYPLUSPLUS))
	virtual ~Coordinate() = 0;

	virtual std::unique_ptr<Coordinate> clone() const GENPYBIND(hidden) = 0;

	virtual std::ostream& print(std::ostream& os) const GENPYBIND(hidden) = 0;

	friend std::ostream& operator<<(std::ostream& os, Coordinate const& coordinate);

	virtual bool operator==(Coordinate const& other) const = 0;
	virtual bool operator!=(Coordinate const& other) const = 0;
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
#endif
};

} // namespace common
} // namespace halco