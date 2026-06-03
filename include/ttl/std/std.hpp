
#ifndef INCLUDE_STD_STD_HPP_
#define INCLUDE_STD_STD_HPP_

#include "ttl/numbers.hpp"
namespace std {

extern "C" {
auto memset(void* data, u8 value, u64 size) -> void*;
}

template <class _E>
class initializer_list {
   public:
    using value_type = _E;
    using reference = const _E&;
    using const_reference = const _E&;
    using size_type = size_t;
    using iterator = const _E*;
    using const_iterator = const _E*;

   private:
    iterator _M_array;
    size_type _M_len;

    constexpr initializer_list(iterator __a, size_type __l)
        : _M_array(__a), _M_len(__l) {}

   public:
    constexpr initializer_list() noexcept : _M_array(nullptr), _M_len(0) {}

    constexpr size_type size() const noexcept { return _M_len; }
    constexpr iterator begin() const noexcept { return _M_array; }
    constexpr iterator end() const noexcept { return begin() + size(); }
};
}  // namespace std

#endif  // INCLUDE_STD_STD_HPP_
