#ifndef AUBS_NEON_SEARCH_HPP
#define AUBS_NEON_SEARCH_HPP

#if defined(__ARM_NEON)

#include <arm_neon.h>
#include <cstddef>

namespace aubs::simd {

class NEONSearch
{
public:

    static int search(
        const int* data,
        std::size_t size,
        int target
    )
    {
        int32x4_t targetVec =
            vdupq_n_s32(target);

        std::size_t i = 0;

        while(i + 4 <= size)
        {
            int32x4_t values =
                vld1q_s32(data + i);

            uint32x4_t result =
                vceqq_s32(
                    values,
                    targetVec
                );

            uint32_t tmp[4];

            vst1q_u32(
                tmp,
                result
            );

            for(int j = 0; j < 4; ++j)
            {
                if(tmp[j])
                {
                    return static_cast<int>(
                        i + j
                    );
                }
            }

            i += 4;
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