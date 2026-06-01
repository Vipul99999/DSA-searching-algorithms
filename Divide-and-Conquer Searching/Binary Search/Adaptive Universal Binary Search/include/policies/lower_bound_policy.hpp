/*
===============================================================================
 Adaptive Universal Binary Search (AUBS)
 File        : lower_bound_policy.hpp
 Version     : 1.0.0
 License     : MIT
===============================================================================
*/

#ifndef AUBS_LOWER_BOUND_POLICY_HPP
#define AUBS_LOWER_BOUND_POLICY_HPP

#include "aubs.hpp"

namespace aubs {

template<
    RandomAccessIterator Iterator,
    typename ValueType,
    typename Comparator = std::less<>
>
class LowerBoundPolicy final
    : public ISearchPolicy<
          Iterator,
          ValueType
      >
{
private:

    Comparator comparator_;

public:

    explicit LowerBoundPolicy(
        Comparator comparator = Comparator{}
    )
        : comparator_(std::move(comparator))
    {
    }

    SearchResult<ValueType> execute(
        Iterator begin,
        Iterator end,
        const ValueType& target
    ) override
    {
        SearchResult<ValueType> result;

        try
        {
            using difference_type =
                typename std::iterator_traits<
                    Iterator
                >::difference_type;

            difference_type left = 0;
            difference_type right =
                std::distance(begin, end);

            while (left < right)
            {
                result.statistics.iterations++;

                difference_type mid =
                    left + (right - left) / 2;

                result.statistics.comparisons++;

                if (comparator_(
                        *(begin + mid),
                        target))
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid;
                }

                result.statistics.branchCount++;
            }

            if (left <
                std::distance(begin, end))
            {
                result.status =
                    SearchStatus::Success;

                result.index =
                    static_cast<std::size_t>(
                        left
                    );

                result.value =
                    *(begin + left);
            }
            else
            {
                result.status =
                    SearchStatus::NotFound;
            }

            return result;
        }
        catch (...)
        {
            result.status =
                SearchStatus::Error;

            return result;
        }
    }

    [[nodiscard]]
    const Comparator&
    comparator() const noexcept
    {
        return comparator_;
    }
};

template<
    RandomAccessIterator Iterator,
    typename ValueType,
    typename Comparator = std::less<>
>
[[nodiscard]]
auto makeLowerBoundPolicy(
    Comparator comparator = Comparator{}
)
{
    return LowerBoundPolicy<
        Iterator,
        ValueType,
        Comparator
    >(
        std::move(comparator)
    );
}

template<
    RandomAccessIterator Iterator,
    typename ValueType,
    typename Comparator = std::less<>
>
[[nodiscard]]
SearchResult<ValueType>
lowerBoundSearch(
    Iterator begin,
    Iterator end,
    const ValueType& target,
    Comparator comparator = Comparator{}
)
{
    LowerBoundPolicy<
        Iterator,
        ValueType,
        Comparator
    > policy(
        std::move(comparator)
    );

    return policy.execute(
        begin,
        end,
        target
    );
}

} // namespace aubs

#endif