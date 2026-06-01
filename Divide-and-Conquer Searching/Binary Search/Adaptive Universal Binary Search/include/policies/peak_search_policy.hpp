/*
===============================================================================
 Adaptive Universal Binary Search (AUBS)
 File        : peak_search_policy.hpp
 Version     : 1.0.0
 License     : MIT
===============================================================================
*/

#ifndef AUBS_PEAK_SEARCH_POLICY_HPP
#define AUBS_PEAK_SEARCH_POLICY_HPP

#include "aubs.hpp"

namespace aubs {

template<
    RandomAccessIterator Iterator,
    typename ValueType,
    typename Comparator = std::less<>
>
class PeakSearchPolicy final
    : public ISearchPolicy<
          Iterator,
          ValueType
      >
{
private:

    Comparator comparator_;

public:

    explicit PeakSearchPolicy(
        Comparator comparator = Comparator{}
    )
        : comparator_(std::move(comparator))
    {
    }

    SearchResult<ValueType> execute(
        Iterator begin,
        Iterator end,
        const ValueType&
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

            while (left < right)
            {
                result.statistics.iterations++;

                difference_type mid =
                    left + (right - left) / 2;

                auto current =
                    *(begin + mid);

                auto next =
                    *(begin + mid + 1);

                result.statistics.comparisons++;

                if (comparator_(
                        current,
                        next))
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid;
                }

                result.statistics.branchCount++;
            }

            result.status =
                SearchStatus::Success;

            result.index =
                static_cast<std::size_t>(
                    left
                );

            result.value =
                *(begin + left);

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
peakSearch(
    Iterator begin,
    Iterator end,
    Comparator comparator = Comparator{}
)
{
    PeakSearchPolicy<
        Iterator,
        ValueType,
        Comparator
    > policy(
        std::move(comparator)
    );

    return policy.execute(
        begin,
        end,
        ValueType{}
    );
}

} // namespace aubs

#endif