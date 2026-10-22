// This file is part of the Luau programming language and is licensed under MIT License; see LICENSE.txt for details
#pragma once

#include <stdint.h>

inline int64_t luai_d2i64(double d)
{
    if (d >= -9223372036854775808.0 && d < 9223372036854775808.0)
        return (int64_t)d;

    if (d != d)
        return 0;

    return d > 0 ? INT64_MAX : INT64_MIN;
}

inline int32_t luai_d2i32(double d)
{
    if (d > -2147483649.0 && d < 2147483648.0)
        return (int32_t)d;

    if (d != d)
        return 0;

    return d > 0 ? INT32_MAX : INT32_MIN;
}

inline uint64_t luai_d2u64(double d)
{
    if (d >= 0)
    {
        if (d < 18446744073709551616.0)
            return (uint64_t)d;

        return d != d ? 0 : UINT64_MAX;
    }

    return (uint64_t)luai_d2i64(d);
}

inline uint32_t luai_d2u32(double d)
{
    return (uint32_t)luai_d2i64(d);
}
