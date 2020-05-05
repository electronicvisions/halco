#pragma once
#include <cereal/cereal.hpp>
#include "halco/common/typed_array.h"

namespace cereal {

// implementation below adapted from <cereal/types/array.hpp>

template <typename Archive, typename Value, typename Key, typename Limits>
inline typename std::enable_if<
    traits::is_output_serializable<BinaryData<Value>, Archive>::value &&
        std::is_arithmetic<Value>::value,
    void>::type
CEREAL_SAVE_FUNCTION_NAME(Archive& ar, halco::common::typed_array<Value, Key, Limits> const& x)
{
	ar(cereal::make_nvp("data", binary_data(x.data(), sizeof(x))));
}

template <typename Archive, typename Value, typename Key, typename Limits>
inline typename std::enable_if<
    traits::is_input_serializable<BinaryData<Value>, Archive>::value &&
        std::is_arithmetic<Value>::value,
    void>::type
CEREAL_LOAD_FUNCTION_NAME(Archive& ar, halco::common::typed_array<Value, Key, Limits>& x)
{
	ar(cereal::make_nvp("data", binary_data(x.data(), sizeof(x))));
}

template <typename Archive, typename Value, typename Key, typename Limits>
inline typename std::enable_if<
    !traits::is_output_serializable<BinaryData<Value>, Archive>::value ||
        !std::is_arithmetic<Value>::value,
    void>::type
CEREAL_SAVE_FUNCTION_NAME(Archive& ar, halco::common::typed_array<Value, Key, Limits> const& x)
{
	for (auto const& entry : x) {
		ar(CEREAL_NVP(entry));
	}
}

template <typename Archive, typename Value, typename Key, typename Limits>
inline typename std::enable_if<
    !traits::is_input_serializable<BinaryData<Value>, Archive>::value ||
        !std::is_arithmetic<Value>::value,
    void>::type
CEREAL_LOAD_FUNCTION_NAME(Archive& ar, halco::common::typed_array<Value, Key, Limits>& x)
{
	for (auto& entry : x) {
		ar(CEREAL_NVP(entry));
	}
}

} // namespace cereal
