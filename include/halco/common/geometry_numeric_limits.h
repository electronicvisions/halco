#pragma once
#include <limits>

#define HALCO_GEOMETRY_NUMERIC_LIMITS_CLASS(CLASS)                                                 \
	template <>                                                                                    \
	struct numeric_limits<CLASS>                                                                   \
	{                                                                                              \
		static constexpr bool is_specialized = true;                                               \
                                                                                                   \
		static constexpr CLASS min() noexcept                                                      \
		{                                                                                          \
			return CLASS(CLASS::min);                                                              \
		}                                                                                          \
                                                                                                   \
		static constexpr CLASS max() noexcept                                                      \
		{                                                                                          \
			return CLASS(CLASS::max);                                                              \
		}                                                                                          \
                                                                                                   \
		static constexpr CLASS lowest() noexcept                                                   \
		{                                                                                          \
			return CLASS(CLASS::lowest);                                                           \
		}                                                                                          \
                                                                                                   \
		static constexpr int digits = std::numeric_limits<CLASS::value_type>::digits;              \
		static constexpr int digits10 = std::numeric_limits<CLASS::value_type>::digits10;          \
		static constexpr int max_digits10 = std::numeric_limits<CLASS::value_type>::max_digits10;  \
                                                                                                   \
		static constexpr bool is_signed = std::numeric_limits<CLASS::value_type>::is_signed;       \
		static constexpr bool is_integer = std::numeric_limits<CLASS::value_type>::is_integer;     \
		static constexpr bool is_exact = std::numeric_limits<CLASS::value_type>::is_exact;         \
		static constexpr int radix = std::numeric_limits<CLASS::value_type>::radix;                \
                                                                                                   \
		static constexpr CLASS epsilon() noexcept                                                  \
		{                                                                                          \
			return CLASS(std::numeric_limits<CLASS::value_type>::epsilon());                       \
		}                                                                                          \
                                                                                                   \
		static constexpr CLASS round_error() noexcept                                              \
		{                                                                                          \
			return CLASS(std::numeric_limits<CLASS::value_type>::round_error());                   \
		}                                                                                          \
                                                                                                   \
		static constexpr int min_exponent = std::numeric_limits<CLASS::value_type>::min_exponent;  \
		static constexpr int min_exponent10 =                                                      \
		    std::numeric_limits<CLASS::value_type>::min_exponent10;                                \
		static constexpr int max_exponent = std::numeric_limits<CLASS::value_type>::max_exponent;  \
		static constexpr int max_exponent10 =                                                      \
		    std::numeric_limits<CLASS::value_type>::max_exponent10;                                \
                                                                                                   \
		static constexpr bool has_infinity = std::numeric_limits<CLASS::value_type>::has_infinity; \
		static constexpr bool has_quiet_NaN =                                                      \
		    std::numeric_limits<CLASS::value_type>::has_quiet_NaN;                                 \
		static constexpr bool has_signaling_NaN =                                                  \
		    std::numeric_limits<CLASS::value_type>::has_signaling_NaN;                             \
		static constexpr float_denorm_style has_denorm =                                           \
		    std::numeric_limits<CLASS::value_type>::has_denorm;                                    \
		static constexpr bool has_denorm_loss =                                                    \
		    std::numeric_limits<CLASS::value_type>::has_denorm_loss;                               \
                                                                                                   \
		static constexpr CLASS infinity() noexcept                                                 \
		{                                                                                          \
			return CLASS(std::numeric_limits<CLASS::value_type>::infinity());                      \
		}                                                                                          \
                                                                                                   \
		static constexpr CLASS quiet_NaN() noexcept                                                \
		{                                                                                          \
			return CLASS(std::numeric_limits<CLASS::value_type>::quiet_NaN());                     \
		}                                                                                          \
                                                                                                   \
		static constexpr CLASS signaling_NaN() noexcept                                            \
		{                                                                                          \
			return CLASS(std::numeric_limits<CLASS::value_type>::signaling_NaN());                 \
		}                                                                                          \
                                                                                                   \
		static constexpr CLASS denorm_min() noexcept                                               \
		{                                                                                          \
			return CLASS(std::numeric_limits<CLASS::value_type>::denorm_min());                    \
		}                                                                                          \
                                                                                                   \
		static constexpr bool is_iec559 = std::numeric_limits<CLASS::value_type>::is_iec559;       \
		static constexpr bool is_bounded = std::numeric_limits<CLASS::value_type>::is_bounded;     \
		static constexpr bool is_modulo = std::numeric_limits<CLASS::value_type>::is_modulo;       \
                                                                                                   \
		static constexpr bool traps = std::numeric_limits<CLASS::value_type>::traps;               \
		static constexpr bool tinyness_before =                                                    \
		    std::numeric_limits<CLASS::value_type>::tinyness_before;                               \
		static constexpr float_round_style round_style =                                           \
		    std::numeric_limits<CLASS::value_type>::round_style;                                   \
	};
