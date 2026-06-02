
#ifndef INCLUDE_TTL_TERMINATE_HPP_
#define INCLUDE_TTL_TERMINATE_HPP_

#include "ttl/sys/exit.hpp"
#include "ttl/sys/io.hpp"

namespace ttl {
[[noreturn]] inline auto terminate() -> void {
    ttl::sys::putStrLn(0x01, "Called ttl::terminate().");
    ttl::sys::exit(1);
}
}  // namespace ttl

#endif  // INCLUDE_TTL_TERMINATE_HPP_
