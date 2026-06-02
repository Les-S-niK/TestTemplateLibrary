
#ifndef INCLUDE_CONV_CONVERT_HPP_
#define INCLUDE_CONV_CONVERT_HPP_

#include "ttl/numbers.hpp"

namespace ttl::conv {
constexpr u8 char_number_difference = 0x30;
[[nodiscard]] constexpr auto charToNumber(char char_) noexcept -> i8;
[[nodiscard]] constexpr auto numberToChar(u8 number) noexcept -> char;
}  // namespace ttl::conv

#endif  // INCLUDE_CONV_CONVERT_HPP_
