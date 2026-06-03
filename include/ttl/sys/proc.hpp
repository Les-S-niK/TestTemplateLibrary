
#ifndef INCLUDE_SYS_PROC_HPP_
#define INCLUDE_SYS_PROC_HPP_

#include "ttl/numbers.hpp"

namespace ttl::sys {
extern "C" {
enum class Signals : i32 {
    sigint = 0x02,
    sigterm = 0x0F,
    sigsegv = 0x0B,
};
[[nodiscard]] auto getpid() noexcept -> i32;
auto sendSig(i32 pid, i32 signal) noexcept -> void;
}
}  // namespace ttl::sys

#endif  // INCLUDE_SYS_PROC_HPP_
