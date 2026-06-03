
#ifndef INCLUDE_TTL_RESULT_HPP_
#define INCLUDE_TTL_RESULT_HPP_

#include "ttl/algorithms.hpp"
#include "ttl/terminate.hpp"
#include "ttl/traits.hpp"
#include "ttl_traits.hpp"

template <typename T, typename E>
    requires(not ttl::traits::same_as<T, E>)
class Result {
   public:
    constexpr Result(T value) : has_value_(true), value_(ttl::move(value)) {}
    constexpr Result(E error) : error_(ttl::move(error)) {}

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
    [[nodiscard]] constexpr auto error() const noexcept -> E { return error_; }

   private:
    bool has_value_ = false;
    T value_{};
    E error_{};
};
static_assert(ttl::traits::trait_result<Result<int, double>, int, double>,
              "Result does not satisfy <trait_result>");
#endif  // INCLUDE_TTL_RESULT_HPP_
