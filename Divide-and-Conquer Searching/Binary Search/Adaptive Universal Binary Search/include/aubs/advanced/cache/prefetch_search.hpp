#ifndef AUBS_PREFETCH_SEARCH_HPP
#define AUBS_PREFETCH_SEARCH_HPP

#include <cstddef>

#if defined(__GNUC__) || defined(__clang__)
#define AUBS_PREFETCH(addr) \
__builtin_prefetch(addr,0,3)
#else
#define AUBS_PREFETCH(addr)
#endif

namespace aubs::cache {

template<typename T>
class PrefetchBinarySearch
{
public:

    static int search(
        const T* data,
        std::size_t size,
        const T& target
    )
    {
        std::size_t left = 0;
        std::size_t right = size;

        while(left < right)
        {
            std::size_t mid =
                left +
                (right - left) / 2;

            std::size_t future =
                mid +
                ((right - mid) / 2);

            if(future < size)
            {
                AUBS_PREFETCH(
                    &data[future]
                );
            }

            if(data[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        if(left < size &&
           data[left] == target)
        {
            return static_cast<int>(
                left
            );
        }

        return -1;
    }
};

}

#endif