
#ifndef INCLUDE_STD_STD_HPP_
#define INCLUDE_STD_STD_HPP_

#include "ttl/numbers.hpp"
namespace std {

extern "C" {
auto memset(void* data, u8 value, u64 size) -> void*;
}

template <typename T>
class initializer_list {
   public:
    using const_iterator = const T*;

   private:
    const_iterator* array_;
    u64 size_;

    constexpr initializer_list(const_iterator begin, u64 size)
        : array_(begin), size_(size) {}

   public:
    constexpr initializer_list() noexcept : array_(nullptr), size_(0) {}

    [[nodiscard]] constexpr auto size() const noexcept -> u64 { return size_; }

    constexpr auto begin() const noexcept -> const_iterator { return array_; }
    constexpr auto end() const noexcept -> const_iterator {
        return array_ + size_;
    }
};

}  // namespace std

#endif  // INCLUDE_STD_STD_HPP_
