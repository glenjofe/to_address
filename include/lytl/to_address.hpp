/*
Copyright 2017 Glen Joseph Fernandes (glenjofe@gmail.com)
Distributed under the Boost Software License, Version 1.0.
*/
#ifndef LYTL_TO_ADDRESS_HPP
#define LYTL_TO_ADDRESS_HPP

#include <memory>

namespace lytl {

template<class T>
constexpr T* to_address(T* p) noexcept
{
    return p;
}

template<class T>
inline auto to_address(const T& p) noexcept
-> decltype(std::pointer_traits<T>::to_address(p))
{
    return std::pointer_traits<T>::to_address(p);
}

template<class T, class... U>
inline auto to_address(const T& p, U...) noexcept
{
    return lytl::to_address(p.operator->());
}

} /* lytl */

#endif
