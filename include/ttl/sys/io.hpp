
#ifndef INCLUDE_SYS_IO_HPP_
#define INCLUDE_SYS_IO_HPP_

#include "ttl/numbers.hpp"

using fd_t = u32;

namespace ttl::sys {

extern "C" {
auto putStr(fd_t fd, const char* str) noexcept -> void;
auto putStrLn(fd_t fd, const char* str) noexcept -> void;
auto putStrN(fd_t fd, const char* str, u64 length) noexcept -> void;
auto putChar(fd_t fd, char char_) noexcept -> void;
}
}  // namespace ttl::sys

#endif  // INCLUDE_SYS_IO_HPP_
