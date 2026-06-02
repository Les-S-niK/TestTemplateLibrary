
#ifndef INCLUDE_SYS_EXIT_HPP_
#define INCLUDE_SYS_EXIT_HPP_

#include "ttl/numbers.hpp"

namespace ttl::sys {
extern "C" {
[[noreturn]] auto exit(u32 status_code) noexcept -> void;
}
}  // namespace ttl::sys

#endif  // INCLUDE_SYS_EXIT_HPP_
