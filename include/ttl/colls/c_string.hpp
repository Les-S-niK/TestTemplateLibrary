
#ifndef INCLUDE_COLLS_STRING_HPP_
#define INCLUDE_COLLS_STRING_HPP_

#include "ttl/numbers.hpp"

namespace ttl::colls::c {
extern "C" {
[[nodiscard]] auto strLen(const char* str) noexcept -> u64;
}
}  // namespace ttl::colls::c

#endif  // INCLUDE_COLLS_STRING_HPP_
