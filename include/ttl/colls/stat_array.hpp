

#ifndef INCLUDE_COLLS_STAT_ARRAY_HPP_
#define INCLUDE_COLLS_STAT_ARRAY_HPP_

#include "ttl/numbers.hpp"
#include "ttl/optional.hpp"
#include "ttl/std/std.hpp"  //NOLINT: initializer_list
#include "ttl/terminate.hpp"
#include "ttl/ttl_traits.hpp"

namespace ttl {
template <u64 Size, typename T>
class Sarray {
   public:
    constexpr Sarray() = default;
    constexpr Sarray(std::initializer_list<T> init_list) {
        u64 index = 0;
        for (T value : init_list) {
            this->data()[index++] = value;
        }
    }
    [[nodiscard]] constexpr auto data() noexcept -> T* { return data_; }
    [[nodiscard]] constexpr auto data() const noexcept -> const T* {
        return data_;
    }
    [[nodiscard]] constexpr auto first() const noexcept -> Optional<T> {
        if (Size > 0) {
            return {data_[0]};
        }
        return {};
    }
    [[nodiscard]] constexpr auto last() const noexcept -> Optional<T> {
        if (Size > 0) {
            return {data_[Size - 1]};
        }
        return {};
    }
    [[nodiscard]] constexpr auto size() const -> u64 { return Size; }
    [[nodiscard]] constexpr auto cbegin() const noexcept -> const T* {
        return &data_[0];
    }
    [[nodiscard]] constexpr auto cend() const noexcept -> const T* {
        return &data_[Size];
    }
    [[nodiscard]] constexpr auto begin() noexcept -> T* { return &data_[0]; }
    [[nodiscard]] constexpr auto end() noexcept -> T* { return &data_[Size]; }
    [[nodiscard]] constexpr auto isEmpty() const noexcept -> bool {
        return Size == 0;
    }
    template <typename Self>
    [[nodiscard]] constexpr auto operator[](this Self&& self,
                                            u64 index) noexcept {
        if (index < Size) {
            return self.data_[index];
        }
        ttl::terminate("Can not access static array by this index.");
    }

   private:
    T data_[Size]{};
};
static_assert(ttl::traits::trait_array<Sarray<10, int>, int, Optional<int>>,
              "StatArray does not implement <trait_array>");
}  // namespace ttl

#endif  // INCLUDE_COLLS_STAT_ARRAY_HPP_
