
#ifndef INCLUDE_COLLS_STAT_STRING_HPP_
#define INCLUDE_COLLS_STAT_STRING_HPP_

#include "ttl/colls/stat_array.hpp"
#include "ttl/numbers.hpp"
#include "ttl/std/std.hpp"  // NOLINT: initializer_list
#include "ttl/ttl_traits.hpp"

namespace ttl {
template <u64 Size>
class Sstring : public ttl::Sarray<Size + 0x01, char> {
   public:
    Sstring(std::initializer_list<char> init_list)
        : Sarray<Size + 0x01, char>{init_list} {
        this->data()[Size] = '\0';
    }
    Sstring(const Sstring&) = delete;
    Sstring(Sstring&&) = delete;
    Sstring& operator=(const Sstring&) = delete;
    Sstring& operator=(Sstring&&) = delete;

    [[nodiscard]] constexpr auto length() const noexcept -> u64 { return Size; }

    [[nodiscard]] constexpr auto cStr() const noexcept -> const char* {
        return this->data();
    }
};

static_assert(ttl::traits::trait_array<ttl::Sstring<10>, char, Optional<char>>,
              "StatArray does not implement <trait_array>");
static_assert(ttl::traits::trait_string<ttl::Sstring<10>, char, Optional<char>>,
              "Sstring does not implement <trait_string>");
}  // namespace ttl

#endif  // INCLUDE_COLLS_STAT_STRING_HPP_
