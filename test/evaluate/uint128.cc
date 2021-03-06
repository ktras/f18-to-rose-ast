// Copyright (c) 2019, NVIDIA CORPORATION.  All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#define AVOID_NATIVE_UINT128_T 1
#include "../../lib/common/uint128.h"
#include "testing.h"
#include <cinttypes>
#include <iostream>

#if (defined __GNUC__ || defined __clang__) && defined __SIZEOF_INT128__
#define HAS_NATIVE_UINT128_T 1
#else
#undef HAS_NATIVE_UINT128_T
#endif

using U128 = Fortran::common::UnsignedInt128;

static void Test(std::uint64_t x) {
  U128 n{x};
  MATCH(x, static_cast<std::uint64_t>(n));
  MATCH(~x, static_cast<std::uint64_t>(~n));
  MATCH(-x, static_cast<std::uint64_t>(-n));
  MATCH(!x, static_cast<std::uint64_t>(!n));
  TEST(n == n);
  TEST(n + n == n * static_cast<U128>(2));
  TEST(n - n == static_cast<U128>(0));
  TEST(n + n == n << static_cast<U128>(1));
  TEST(n + n == n << static_cast<U128>(1));
  TEST((n + n) - n == n);
  TEST(((n + n) >> static_cast<U128>(1)) == n);
  if (x != 0) {
    TEST(static_cast<U128>(0) / n == static_cast<U128>(0));
    TEST(static_cast<U128>(n - 1) / n == static_cast<U128>(0));
    TEST(static_cast<U128>(n) / n == static_cast<U128>(1));
    TEST(static_cast<U128>(n + n - 1) / n == static_cast<U128>(1));
    TEST(static_cast<U128>(n + n) / n == static_cast<U128>(2));
  }
}

static void Test(std::uint64_t x, std::uint64_t y) {
  U128 m{x}, n{y};
  MATCH(x, static_cast<std::uint64_t>(m));
  MATCH(y, static_cast<std::uint64_t>(n));
  MATCH(x & y, static_cast<std::uint64_t>(m & n));
  MATCH(x | y, static_cast<std::uint64_t>(m | n));
  MATCH(x ^ y, static_cast<std::uint64_t>(m ^ n));
  MATCH(x + y, static_cast<std::uint64_t>(m + n));
  MATCH(x - y, static_cast<std::uint64_t>(m - n));
  MATCH(x * y, static_cast<std::uint64_t>(m * n));
  if (n != 0) {
    MATCH(x / y, static_cast<std::uint64_t>(m / n));
  }
}

#if HAS_NATIVE_UINT128_T
static __uint128_t ToNative(U128 n) {
  return static_cast<__uint128_t>(static_cast<std::uint64_t>(n >> 64)) << 64 |
      static_cast<std::uint64_t>(n);
}

static U128 FromNative(__uint128_t n) {
  return U128{static_cast<std::uint64_t>(n >> 64)} << 64 |
      U128{static_cast<std::uint64_t>(n)};
}

static void TestVsNative(__uint128_t x, __uint128_t y) {
  U128 m{FromNative(x)}, n{FromNative(y)};
  TEST(ToNative(m) == x);
  TEST(ToNative(n) == y);
  TEST(ToNative(~m) == ~x);
  TEST(ToNative(-m) == -x);
  TEST(ToNative(!m) == !x);
  TEST(ToNative(m < n) == (x < y));
  TEST(ToNative(m <= n) == (x <= y));
  TEST(ToNative(m == n) == (x == y));
  TEST(ToNative(m != n) == (x != y));
  TEST(ToNative(m >= n) == (x >= y));
  TEST(ToNative(m > n) == (x > y));
  TEST(ToNative(m & n) == (x & y));
  TEST(ToNative(m | n) == (x | y));
  TEST(ToNative(m ^ n) == (x ^ y));
  if (y < 128) {
    TEST(ToNative(m << n) == (x << y));
    TEST(ToNative(m >> n) == (x >> y));
  }
  TEST(ToNative(m + n) == (x + y));
  TEST(ToNative(m - n) == (x - y));
  TEST(ToNative(m * n) == (x * y));
  if (y > 0) {
    TEST(ToNative(m / n) == (x / y));
    TEST(ToNative(m % n) == (x % y));
    TEST(ToNative(m - n * (m / n)) == (x % y));
  }
}

static void TestVsNative() {
  for (int j{0}; j < 128; ++j) {
    for (int k{0}; k < 128; ++k) {
      __uint128_t m{1}, n{1};
      m <<= j, n <<= k;
      TestVsNative(m, n);
      TestVsNative(~m, n);
      TestVsNative(m, ~n);
      TestVsNative(~m, ~n);
      TestVsNative(m ^ n, n);
      TestVsNative(m, m ^ n);
      TestVsNative(m ^ ~n, n);
      TestVsNative(m, ~m ^ n);
      TestVsNative(m ^ ~n, m ^ n);
      TestVsNative(m ^ n, ~m ^ n);
      TestVsNative(m ^ ~n, ~m ^ n);
      Test(m, 10000000000000000);  // important case for decimal conversion
      Test(~m, 10000000000000000);
    }
  }
}
#endif

int main() {
  for (std::uint64_t j{0}; j < 64; ++j) {
    Test(j);
    Test(~j);
    Test(std::uint64_t(1) << j);
    for (std::uint64_t k{0}; k < 64; ++k) {
      Test(j, k);
    }
  }
#if HAS_NATIVE_UINT128_T
  std::cout << "Environment has native __uint128_t\n";
  TestVsNative();
#else
  std::cout << "Environment lacks native __uint128_t\n";
#endif
  return testing::Complete();
}
