/*
===============================================================================
 Adaptive Universal Binary Search (AUBS)
 File        : rotated_search_policy.hpp
 Version     : 1.0.0
 License     : MIT
===============================================================================
*/

#ifndef AUBS_ROTATED_SEARCH_POLICY_HPP
#define AUBS_ROTATED_SEARCH_POLICY_HPP

#include "aubs.hpp"

namespace aubs {

template<
    RandomAccessIterator Iterator,
    typename ValueType,
    typename Comparator = std::less<>
>
class RotatedSearchPolicy final
    : public ISearchPolicy<
          Iterator,
          ValueType
      >
{
private:

    Comparator comparator_;

    bool equals(
        const ValueType& a,
        const ValueType& b
    ) const
    {
        return !comparator_(a, b)
            && !comparator_(b, a);
    }

public:

    explicit RotatedSearchPolicy(
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
            auto size =
                std::distance(begin, end);

            if (size <= 0)
            {
                result.status =
                    SearchStatus::NotFound;

                return result;
            }

            using difference_type =
                typename std::iterator_traits<
                    Iterator
                >::difference_type;

            difference_type left = 0;
            difference_type right =
                size - 1;

            while (left <= right)
            {
                result.statistics.iterations++;

                difference_type mid =
                    left + (right - left) / 2;

                const auto& current =
                    *(begin + mid);

                result.statistics.comparisons++;

                if (equals(current, target))
                {
                    result.status =
                        SearchStatus::Success;

                    result.index =
                        static_cast<std::size_t>(
                            mid
                        );

                    result.value =
                        current;

                    return result;
                }

                const auto& leftValue =
                    *(begin + left);

                const auto& rightValue =
                    *(begin + right);

                result.statistics.branchCount++;

                bool leftSorted =
                    !comparator_(
                        current,
                        leftValue
                    );

                if (leftSorted)
                {
                    bool inRange =
                        !comparator_(
                            target,
                            leftValue
                        )
                        &&
                        comparator_(
                            target,
                            current
                        );

                    if (inRange)
                    {
                        right = mid - 1;
                    }
                    else
                    {
                        left = mid + 1;
                    }
                }
                else
                {
                    bool inRange =
                        comparator_(
                            current,
                            target
                        )
                        &&
                        !comparator_(
                            rightValue,
                            target
                        );

                    if (inRange)
                    {
                        left = mid + 1;
                    }
                    else
                    {
                        right = mid - 1;
                    }
                }
            }

            result.status =
                SearchStatus::NotFound;

            return result;
        }
        catch (...)
        {
            result.status =
                SearchStatus::Error;

            return result;
        }
    }
};

template<
    RandomAccessIterator Iterator,
    typename ValueType,
    typename Comparator = std::less<>
>
SearchResult<ValueType>
rotatedSearch(
    Iterator begin,
    Iterator end,
    const ValueType& target,
    Comparator comparator = Comparator{}
)
{
    RotatedSearchPolicy<
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