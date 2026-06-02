
#ifndef INCLUDE_TTL_CONCEPTS_HPP_
#define INCLUDE_TTL_CONCEPTS_HPP_

namespace ttl::traits {

template <typename T>
auto declval() -> T;

// Constexpr boolean structs.
template <bool Value>
struct Bool {
    static constexpr bool value = Value;
};
using True = Bool<true>;
using False = Bool<false>;

// Is same.
template <typename T, typename U>
struct is_same : False {};

template <typename T>
struct is_same<T, T> : True {};

template <typename T, typename U>
concept same_as = is_same<T, U>::value;

// Convertible from-to.
template <typename From, typename To>
concept expl_convertible_to = requires() { static_cast<To>(declval<From>()); };

template <typename From, typename To>
concept impl_convertible_to = requires() { To(declval<From>()); };

// Remove reference.
template <typename T>
struct remove_ref {
    using type = T;
};

template <typename T>
struct remove_ref<T&> {
    using type = T;
};

template <typename T>
struct remove_ref<T&&> {
    using type = T;
};

template <typename T>
using remove_ref_t = remove_ref<T>::type;

// Is lvalue ref.
template <typename T>
struct trait_is_lvalue_ref : False {};

template <typename T>
struct trait_is_lvalue_ref<T&> : True {};

template <typename T>
struct trait_is_lvalue_ref<T&&> : False {};

template <typename T>
concept is_lvalue_ref = trait_is_lvalue_ref<T>::value;

// Is rvalue ref.
template <typename T>
struct trait_is_rvalue_ref : False {};

template <typename T>
struct trait_is_rvalue_ref<T&> : False {};

template <typename T>
struct trait_is_rvalue_ref<T&&> : True {};

template <typename T>
concept is_rvalue_ref = trait_is_rvalue_ref<T>::value;

// Is lvalue.
template <typename T>
struct trait_is_lvalue : True {};

template <typename T>
struct trait_is_lvalue<T&> : False {};

template <typename T>
struct trait_is_lvalue<T&&> : False {};

template <typename T>
concept is_lvalue = trait_is_lvalue<T>::value;

}  // namespace ttl::traits
#endif  // INCLUDE_TTL_CONCEPTS_HPP_
