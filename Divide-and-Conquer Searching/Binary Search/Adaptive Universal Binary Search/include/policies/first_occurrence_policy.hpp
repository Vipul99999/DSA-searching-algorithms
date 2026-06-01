/*
===============================================================================
 Adaptive Universal Binary Search (AUBS)
 File        : first_occurrence_policy.hpp
 Version     : 1.0.0
 License     : MIT
===============================================================================
*/

#ifndef AUBS_FIRST_OCCURRENCE_POLICY_HPP
#define AUBS_FIRST_OCCURRENCE_POLICY_HPP

#include "aubs.hpp"

namespace aubs {

template<
    RandomAccessIterator Iterator,
    typename ValueType,
    typename Comparator = std::less<>
>
class FirstOccurrencePolicy final
    : public ISearchPolicy<
          Iterator,
          ValueType
      >
{
private:

    Comparator comparator_;

public:

    explicit FirstOccurrencePolicy(
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

            difference_type answer = -1;

            while (left < right)
            {
                result.statistics.iterations++;

                difference_type mid =
                    left + (right - left) / 2;

                auto current =
                    *(begin + mid);

                bool less1 =
                    comparator_(current, target);

                bool less2 =
                    comparator_(target, current);

                result.statistics.comparisons += 2;
                result.statistics.branchCount++;

                if (!less1 && !less2)
                {
                    answer = mid;
                    right = mid;
                }
                else if (less1)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid;
                }
            }

            if (left <
                std::distance(begin, end))
            {
                auto current =
                    *(begin + left);

                bool less1 =
                    comparator_(current, target);

                bool less2 =
                    comparator_(target, current);

                if (!less1 && !less2)
                {
                    result.status =
                        SearchStatus::Success;

                    result.index =
                        static_cast<std::size_t>(
                            left
                        );

                    result.value =
                        current;

                    return result;
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
firstOccurrenceSearch(
    Iterator begin,
    Iterator end,
    const ValueType& target,
    Comparator comparator = Comparator{}
)
{
    FirstOccurrencePolicy<
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