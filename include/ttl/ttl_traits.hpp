
#ifndef INCLUDE_TTL_TTL_TRAITS_HPP_
#define INCLUDE_TTL_TTL_TRAITS_HPP_

#include "ttl/traits.hpp"

namespace ttl::traits {
//
// template <typename Object>
// concept trait_object = requires(Object object) {
//     { object.toString() } ->
// }

template <typename Object, typename T, typename E>
concept trait_result = requires(Object object, T value) {
    { object.value() } -> same_as<T>;
    { object.valueView() } -> same_as<const T&>;
    { object.valueOr(value) } -> same_as<T>;
    { object.hasValue() } -> same_as<bool>;
    { object.error() } -> same_as<E>;
};

}  // namespace ttl::traits
#endif  // INCLUDE_TTL_TTL_TRAITS_HPP_
