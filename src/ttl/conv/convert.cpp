

#include "ttl/conv/convert.hpp"

[[nodiscard]] constexpr auto ttl::conv::charToNumber(char char_) noexcept
    -> i8 {
    return static_cast<i8>(char_ - char_number_difference);
}

[[nodiscard]] constexpr auto ttl::conv::numberToChar(u8 number) noexcept
    -> char {
    return static_cast<char>(number + char_number_difference);
}
