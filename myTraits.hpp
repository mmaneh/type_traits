#ifndef MY_TRAITS_HPP
#define MY_TRAITS_HPP
#include <iostream>

namespace my_traits {

template <typename T>
struct remove_reference {
    using type = T;
};

template <typename T>
struct remove_reference <T&>{
    using type = T;
};

template <typename T>
struct remove_reference <T&&>{
    using type = T;
};
template <typename T, typename U>
struct is_same {
    constexpr static bool value = false;
};

template <typename T>
struct is_same <T,T> {
    constexpr static bool value = true;
};
template <typename T>
struct is_pointer {
    constexpr static bool value = false;
};

template <typename T>
struct is_pointer<T*> {
    constexpr static bool value = true;
};
template <typename T>
struct is_array {
    constexpr static bool value = false;
};
template <typename T>
struct is_array<T[]> {
    constexpr static bool value = true;
};
template <typename T, size_t N>
struct is_array<T[N]> {
    constexpr static bool value = true;
}; 
template <typename T>
struct is_integral {
	constexpr static bool value = false;
};

template <>
struct is_integral<int> {
        constexpr static bool value = true;
};

template <>
struct is_integral<short> {
        constexpr static bool value = true;
};

template <>
struct is_integral<long> {
        constexpr static bool value = true;
};

template <>
struct is_integral<long long> {
        constexpr static bool value = true;
};

template <>
struct is_integral<char> {
        constexpr static bool value = true;
};

template <>
struct is_integral<wchar_t> {
        constexpr static bool value = true;
};

template <>
struct is_integral<char32_t> {
        constexpr static bool value = true;
};
template <typename T>
struct is_floating_point {
	constexpr static bool value = false;
};

template <>
struct is_floating_point<float> {
        constexpr static bool value = true;
};

template <>
struct is_floating_point<double> {
        constexpr static bool value = true;
};

template <>
struct is_floating_point<long double> {
        constexpr static bool value = true;
};

template <typename T>
struct remove_extent {
    using type = T;
};
template <typename T>
struct remove_extent<T[]> {
    using type = T;
};
template <typename T, size_t N>
struct remove_extent<T[N]> {
    using type = T;
};
template <typename T>
struct add_pointer {
    using type = T*;
};

template <typename T>
struct add_const {
    using type = const T;
};

template <typename T>
struct remove_const {
    using type = T;
};

template <typename T>
struct remove_const<const T> {
    using type = T;
};

template <typename T>
struct remove_cv {
    using type = T;
};
template <typename T>
struct remove_cv<const T>{
    using type = T;
};
template<typename T>
struct remove_cv<volatile T> {
    using type = T;
};
template <typename T>
struct remove_cv<const volatile T>{
    using type = T;
};
template <bool B, typename Truetype, typename Falsetype>
struct conditional {
    using type = Falsetype;
};
template <typename Truetype, typename Falsetype>
struct conditional<true, Truetype,Falsetype>{
    using type = Truetype;
};

template <bool B, typename T>
struct enable_if {};

template <typename T>
struct enable_if<true,T>{
    using type = T;
};

}
#endif
