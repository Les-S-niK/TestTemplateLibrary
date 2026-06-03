
#ifndef INCLUDE_TTL_TERMINATE_HPP_
#define INCLUDE_TTL_TERMINATE_HPP_

#include "ttl/sys/exit.hpp"
#include "ttl/sys/io.hpp"
#include "ttl/sys/proc.hpp"

namespace ttl {
[[noreturn]] inline auto terminate(const char* message = "") -> void {
    constexpr u8 sigterm_status = 143;
    ttl::sys::putStrLn(0x01, "Called ttl::terminate().");
    ttl::sys::putStrLn(0x01, message);
    ttl::sys::exit(sigterm_status);
}
}  // namespace ttl

#endif  // INCLUDE_TTL_TERMINATE_HPP_
