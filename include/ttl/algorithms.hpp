
#ifndef INCLUDE_TTL_ALGORITHMS_HPP_
#define INCLUDE_TTL_ALGORITHMS_HPP_

#include "ttl/traits.hpp"
namespace ttl {

using ttl::traits::is_lvalue_ref;
using ttl::traits::remove_ref_t;

template <typename T>
[[nodiscard]] constexpr auto move(T&& value) noexcept -> remove_ref_t<T>&& {
    return static_cast<remove_ref_t<T>&&>(value);
}

template <typename T>
[[nodiscard]] constexpr auto forward(remove_ref_t<T>& value) -> T&& {
    return static_cast<T&&>(value);
}
template <typename T>
[[nodiscard]] constexpr auto forward(remove_ref_t<T>&& value) -> T&& {
    static_assert(not is_lvalue_ref<T>,
                  "Can not std::forward rvalue to lvalue.");
    return static_cast<T&&>(value);
}

}  // namespace ttl

#endif  // INCLUDE_TTL_ALGORITHMS_HPP_
