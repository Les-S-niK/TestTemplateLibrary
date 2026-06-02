
#ifndef INCLUDE_STD_STD_HPP_
#define INCLUDE_STD_STD_HPP_

#include "ttl/numbers.hpp"
namespace std {

extern "C" {
auto memset(void* data, u8 value, u64 size) -> void*;
}

}  // namespace std

#endif  // INCLUDE_STD_STD_HPP_
