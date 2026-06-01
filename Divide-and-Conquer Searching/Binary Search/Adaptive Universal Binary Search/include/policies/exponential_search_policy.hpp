/*
===============================================================================
 Adaptive Universal Binary Search (AUBS)
 File        : exponential_search_policy.hpp
 Version     : 1.0.0
 License     : MIT
===============================================================================
*/

#ifndef AUBS_EXPONENTIAL_SEARCH_POLICY_HPP
#define AUBS_EXPONENTIAL_SEARCH_POLICY_HPP

#include "aubs.hpp"

namespace aubs {

template<
    RandomAccessIterator Iterator,
    typename ValueType,
    typename Comparator = std::less<>
>
class ExponentialSearchPolicy final
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
        return !comparator_(a,b)
            && !comparator_(b,a);
    }

public:

    explicit ExponentialSearchPolicy(
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

            if (equals(*begin, target))
            {
                result.status =
                    SearchStatus::Success;

                result.index = 0;
                result.value = *begin;

                return result;
            }

            std::size_t bound = 1;

            while (
                bound <
                static_cast<std::size_t>(size)
                &&
                comparator_(
                    *(begin + bound),
                    target
                )
            )
            {
                result.statistics.iterations++;
                bound *= 2;
            }

            std::size_t left =
                bound / 2;

            std::size_t right =
                std::min(
                    bound,
                    static_cast<std::size_t>(size - 1)
                );

            while (left <= right)
            {
                result.statistics.iterations++;

                std::size_t mid =
                    left + (right - left) / 2;

                const auto& current =
                    *(begin + mid);

                if (equals(current, target))
                {
                    result.status =
                        SearchStatus::Success;

                    result.index = mid;
                    result.value = current;

                    return result;
                }

                result.statistics.comparisons++;

                if (comparator_(
                        current,
                        target))
                {
                    left = mid + 1;
                }
                else
                {
                    if (mid == 0)
                        break;

                    right = mid - 1;
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
exponentialSearch(
    Iterator begin,
    Iterator end,
    const ValueType& target,
    Comparator comparator = Comparator{}
)
{
    ExponentialSearchPolicy<
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