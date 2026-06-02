
#ifndef INCLUDE_CONV_CONVERT_HPP_
#define INCLUDE_CONV_CONVERT_HPP_

#include "ttl/numbers.hpp"

namespace ttl::conv {
constexpr u8 char_number_difference = 0x30;
[[nodiscard]] constexpr auto charToNumber(char char_) noexcept -> i8 {
    return static_cast<i8>(char_ - char_number_difference);
}

[[nodiscard]] constexpr auto numberToChar(u8 number) noexcept -> char {
    return static_cast<char>(number + char_number_difference);
}
}  // namespace ttl::conv

#endif  // INCLUDE_CONV_CONVERT_HPP_
