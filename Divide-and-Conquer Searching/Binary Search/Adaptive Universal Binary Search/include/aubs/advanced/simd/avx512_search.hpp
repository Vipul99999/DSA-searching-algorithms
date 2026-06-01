#ifndef AUBS_AVX512_SEARCH_HPP
#define AUBS_AVX512_SEARCH_HPP

#ifdef __AVX512F__

#include <immintrin.h>
#include <cstddef>

namespace aubs::simd {

class AVX512Search
{
public:

    static int search(
        const int* data,
        std::size_t size,
        int target
    )
    {
        const __m512i targetVec =
            _mm512_set1_epi32(target);

        std::size_t i = 0;

        while(i + 16 <= size)
        {
            __m512i values =
                _mm512_loadu_si512(
                    data + i
                );

            __mmask16 mask =
                _mm512_cmpeq_epi32_mask(
                    values,
                    targetVec
                );

            if(mask)
            {
                return static_cast<int>(
                    i + __builtin_ctz(mask)
                );
            }

            i += 16;
        }

        for(; i < size; ++i)
        {
            if(data[i] == target)
            {
                return static_cast<int>(i);
            }
        }

        return -1;
    }
};

}

#endif

#endif