#pragma once
#include "halco/common/geometry.h"
#include <cereal/cereal.hpp>

namespace cereal {

template <typename Archive, typename Derived, typename T>
void CEREAL_SERIALIZE_FUNCTION_NAME(Archive& ar, halco::common::detail::BaseType<Derived, T>& base)
{
	auto value = base.value();
	ar(CEREAL_NVP(value));
	base = halco::common::detail::BaseType<Derived, T>(value);
}

template <typename Archive, typename Derived, typename T>
std::enable_if_t<std::is_base_of_v<
    halco::common::detail::BaseType<Derived, typename Derived::value_type>,
    Derived>>
CEREAL_SERIALIZE_FUNCTION_NAME(Archive& ar, Derived& base)
{
	auto value = base.value();
	ar(CEREAL_NVP(value));
	base = Derived(value);
}

template <typename Archive, typename Derived, typename T, T Max, T Min>
void CEREAL_SERIALIZE_FUNCTION_NAME(
    Archive& ar, halco::common::detail::RantWrapper<Derived, T, Max, Min>& rant)
{
	auto value = rant.value();
	ar(CEREAL_NVP(value));
	rant = halco::common::detail::RantWrapper<Derived, T, Max, Min>(value);
}

template <typename Archive, typename Derived, typename T, T Max, T Min>
std::enable_if_t<std::is_base_of_v<
    halco::common::detail::
        RantWrapper<Derived, typename Derived::value_type, Derived::max, Derived::min>,
    Derived>>
CEREAL_SERIALIZE_FUNCTION_NAME(Archive& ar, Derived& rant)
{
	auto value = rant.value();
	ar(CEREAL_NVP(value));
	rant = Derived(value);
}

template <typename Archive, typename Derived, typename XT, typename YT, size_t EnumSize>
void CEREAL_SERIALIZE_FUNCTION_NAME(
    Archive& ar, halco::common::detail::GridCoordinate<Derived, XT, YT, EnumSize>& grid)
{
	auto x = grid.x();
	auto y = grid.y();
	ar(CEREAL_NVP(x));
	ar(CEREAL_NVP(y));
	grid = halco::common::detail::GridCoordinate<Derived, XT, YT, EnumSize>(x, y);

	// despite not part of the class's layout the enum coordinate is
	// serialized as well for Bjoern's visualization.
	auto e = grid.toEnum();
	ar(CEREAL_NVP(e));
	if (halco::common::detail::GridCoordinate<Derived, XT, YT, EnumSize>(e) != grid) {
		throw std::runtime_error("Deserialized enum and x, y of GridCoordinate don't match.");
	}
}

template <typename Archive, typename Derived>
std::enable_if_t<std::is_base_of_v<
    halco::common::detail::
        GridCoordinate<Derived, typename Derived::x_type, typename Derived::y_type, Derived::size>,
    Derived>>
CEREAL_SERIALIZE_FUNCTION_NAME(Archive& ar, Derived& grid)
{
	auto x = grid.x();
	auto y = grid.y();
	ar(CEREAL_NVP(x));
	ar(CEREAL_NVP(y));
	grid = Derived(x, y);

	// despite not part of the class's layout the enum coordinate is
	// serialized as well for Bjoern's visualization.
	auto e = grid.toEnum();
	ar(CEREAL_NVP(e));
	if (Derived(e) != grid) {
		throw std::runtime_error("Deserialized enum and x, y of GridCoordinate don't match.");
	}
}

template <typename Archive, typename Derived, typename T, size_t EnumSize>
void CEREAL_SERIALIZE_FUNCTION_NAME(
    Archive& ar, halco::common::detail::IntervalCoordinate<Derived, T, EnumSize>& interval)
{
	auto min = interval.toMin();
	auto max = interval.toMax();
	ar(CEREAL_NVP(min));
	ar(CEREAL_NVP(max));
	interval = halco::common::detail::IntervalCoordinate<Derived, T, EnumSize>(min, max);

	// despite not part of the class's layout the enum coordinate is
	// serialized as well for Bjoern's visualization.
	auto e = interval.toEnum();
	ar(CEREAL_NVP(e));
	if (halco::common::detail::IntervalCoordinate<Derived, T, EnumSize>(e) != interval) {
		throw std::runtime_error(
		    "Deserialized enum and min, max of IntervalCoordinate don't match.");
	}
}

} // namespace cereal
