#ifndef AUBS_BRANCHLESS_UPPER_BOUND_HPP
#define AUBS_BRANCHLESS_UPPER_BOUND_HPP

#include <cstddef>
#include <functional>

namespace aubs::branchless {

template<
    typename T,
    typename Comparator = std::less<>
>
class BranchlessUpperBound
{
public:

    static std::size_t search(
        const T* data,
        std::size_t size,
        const T& target,
        Comparator comp = Comparator{}
    )
    {
        std::size_t left = 0;
        std::size_t count = size;

        while(count > 0)
        {
            std::size_t step =
                count >> 1;

            std::size_t mid =
                left + step;

            bool moveRight =
                !comp(
                    target,
                    data[mid]
                );

            left =
                moveRight
                ? mid + 1
                : left;

            count =
                moveRight
                ? count - step - 1
                : step;
        }

        return left;
    }
};

template<
    typename T,
    typename Comparator = std::less<>
>
std::size_t branchlessUpperBound(
    const T* data,
    std::size_t size,
    const T& target,
    Comparator comp = Comparator{}
)
{
    return BranchlessUpperBound<
        T,
        Comparator
    >::search(
        data,
        size,
        target,
        comp
    );
}

}

#endif