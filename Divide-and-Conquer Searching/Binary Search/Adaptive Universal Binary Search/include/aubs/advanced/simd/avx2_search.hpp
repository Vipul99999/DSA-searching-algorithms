#ifndef AUBS_AVX2_SEARCH_HPP
#define AUBS_AVX2_SEARCH_HPP

#ifdef __AVX2__

#include <immintrin.h>
#include <cstddef>

namespace aubs::simd {

class AVX2Search
{
public:

    static int search(
        const int* data,
        std::size_t size,
        int target
    )
    {
        const __m256i targetVec =
            _mm256_set1_epi32(target);

        std::size_t i = 0;

        while(i + 8 <= size)
        {
            __m256i values =
                _mm256_loadu_si256(
                    reinterpret_cast<
                        const __m256i*
                    >(data + i)
                );

            __m256i cmp =
                _mm256_cmpeq_epi32(
                    values,
                    targetVec
                );

            int mask =
                _mm256_movemask_epi8(cmp);

            if(mask != 0)
            {
                for(std::size_t j = 0; j < 8; ++j)
                {
                    if(data[i + j] == target)
                    {
                        return static_cast<int>(
                            i + j
                        );
                    }
                }
            }

            i += 8;
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