
#ifndef INCLUDE_IO_OUTPUT_HPP_
#define INCLUDE_IO_OUTPUT_HPP_

#include "ttl/colls/stat_string.hpp"
#include "ttl/sys/io.hpp"

namespace ttl {
constexpr auto printLn(char char_ = '\n') noexcept -> void {
    ttl::sys::putChar(0x01, char_);
}
constexpr auto printLn(const char* str) noexcept -> void {
    ttl::sys::putStrLn(0x01, str);
}

template <u64 Size>
constexpr auto printLn(const ttl::Sstring<Size>& str) noexcept -> void {
    ttl::sys::putStrN(0x01, str.cStr(), str.length());
    printLn('\n');
}
}  // namespace ttl

#endif  // INCLUDE_IO_OUTPUT_HPP_
