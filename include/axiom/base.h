#pragma once

#include <cassert>
#include <cstdint>
#include <iostream>

namespace axiom {

using i8  = std::int8_t;
using u8  = std::uint8_t;
using i16 = std::int16_t;
using u16 = std::uint16_t;
using i32 = std::int32_t;
using u32 = std::uint32_t;
using i64 = std::int64_t;
using u64 = std::uint64_t;

using f32 = float;
using f64 = double;

} // namespace axiom

#ifndef NDEBUG

#define AXIOM_ASSERT(expr) \
    assert(expr)

#define AXIOM_ASSERT_MSG(expr, msg)                     \
    do {                                                \
        if (!(expr)) [[unlikely]] {                     \
            std::cerr << "Assertion failed: " #expr     \
                      << "\nMessage: " << msg           \
                      << "\nFile: " << __FILE__         \
                      << ":" << __LINE__ << '\n';       \
            assert(expr);                               \
        }                                               \
    } while (false)

#else

#define AXIOM_ASSERT(expr) ((void)0)
#define AXIOM_ASSERT_MSG(expr, msg) ((void)0)

#endif
