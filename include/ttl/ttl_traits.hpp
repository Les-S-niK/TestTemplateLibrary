
#ifndef INCLUDE_TTL_TTL_TRAITS_HPP_
#define INCLUDE_TTL_TTL_TRAITS_HPP_

#include "ttl/numbers.hpp"
#include "ttl/traits.hpp"

namespace ttl::traits {

template <typename Object, typename T>
concept trait_optional = requires(Object object, T value) {
    { object.value() } -> same_as<T>;
    { object.valueView() } -> same_as<const T&>;
    { object.valueOr(value) } -> same_as<T>;
    { object.hasValue() } -> same_as<bool>;
};

template <typename Object, typename T, typename E>
concept trait_result = requires(Object object, T value) {
    { object.error() } -> same_as<E>;
} && trait_optional<Object, T>;

template <typename Array, typename T, typename Opt>
concept trait_array = requires(Array array, T value) {
    { array.data() } -> same_as<T*>;
    { array.first() } -> same_as<Opt>;
    { array.last() } -> same_as<Opt>;
    { array.size() } -> same_as<u64>;
    { array.cbegin() } -> same_as<const T*>;
    { array.cend() } -> same_as<const T*>;
    { array.begin() } -> same_as<T*>;
    { array.end() } -> same_as<T*>;
    { array.isEmpty() } -> same_as<bool>;
    array[0];
} && trait_optional<Opt, T>;

template <typename Str, typename T, typename Opt>
concept trait_string = requires(Str str, T value) {
    { str.length() } -> same_as<u64>;
    { str.cStr() } -> same_as<const char*>;
} && trait_array<Str, T, Opt> && trait_optional<Opt, T>;

}  // namespace ttl::traits
#endif  // INCLUDE_TTL_TTL_TRAITS_HPP_
