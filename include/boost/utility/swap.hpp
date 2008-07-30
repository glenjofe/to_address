// Copyright (C) 2007, 2008 Steven Watanabe, Joseph Gauterin
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// For more information, see http://www.boost.org
//
// Update:
// 29 June 2008 (Added support for built-in arrays.) Niels Dekker  


#ifndef BOOST_UTILITY_SWAP_HPP
#define BOOST_UTILITY_SWAP_HPP

#include <algorithm> //for std::swap
#include <cstddef> //for std::size_t

namespace boost_swap_impl
{
  template<class T>
  void swap_impl(T& left, T& right)
  {
    using std::swap;//use std::swap if argument dependent lookup fails
    swap(left,right);
  }

  template<class T, std::size_t N>
  void swap_impl(T (& left)[N], T (& right)[N])
  {
    for (std::size_t i = 0; i < N; ++i)
    {
      ::boost_swap_impl::swap_impl(left[i], right[i]);
    }
  }
}

namespace boost
{
  namespace swap_adl_barrier
  {
    template<class T1, class T2>
    void swap(T1& left, T2& right)
    {
      ::boost_swap_impl::swap_impl(left, right);
    }
  }

  using swap_adl_barrier::swap;
}

#endif