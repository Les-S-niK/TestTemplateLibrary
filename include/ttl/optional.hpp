
#ifndef INCLUDE_TTL_OPTIONAL_HPP_
#define INCLUDE_TTL_OPTIONAL_HPP_

#include "ttl/algorithms.hpp"
#include "ttl/terminate.hpp"
#include "ttl/ttl_traits.hpp"

template <typename T>
class Optional {
   public:
    constexpr Optional(T value) : has_value_(true), value_(ttl::move(value)) {}
    constexpr Optional() = default;

    [[nodiscard]] constexpr auto value() const noexcept -> T {
        if (not has_value_) {
            ttl::terminate();
        }
        return value_;
    }
    [[nodiscard]] constexpr auto valueView() const noexcept -> const T& {
        return value();
    }
    [[nodiscard]] constexpr auto valueOr(T value) noexcept -> T {
        if (not has_value_) {
            return value;
        }
        return value_;
    }
    [[nodiscard]] constexpr auto hasValue() const noexcept -> bool {
        return has_value_;
    }

   private:
    bool has_value_ = false;
    T value_{};
};
static_assert(ttl::traits::trait_optional<Optional<int>, int>,
              "Result does not satisfy <trait_result>");

#endif  // INCLUDE_TTL_OPTIONAL_HPP_
