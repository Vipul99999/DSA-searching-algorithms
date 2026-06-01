/*
===============================================================================
 Adaptive Universal Binary Search (AUBS)
 File        : binary_search_answer_policy.hpp
 Version     : 1.0.0
 License     : MIT
===============================================================================
*/

#ifndef AUBS_BINARY_SEARCH_ANSWER_POLICY_HPP
#define AUBS_BINARY_SEARCH_ANSWER_POLICY_HPP

#include "aubs.hpp"

namespace aubs {

template<
    typename ValueType,
    typename Predicate
>
requires SearchPredicate<
    Predicate,
    ValueType
>
class BinarySearchAnswerPolicy
{
private:

    Predicate predicate_;

public:

    explicit BinarySearchAnswerPolicy(
        Predicate predicate
    )
        : predicate_(
            std::move(predicate)
        )
    {
    }

    SearchResult<ValueType> execute(
        ValueType low,
        ValueType high
    )
    {
        SearchResult<ValueType> result;

        try
        {
            ValueType answer = high;

            while (low <= high)
            {
                result.statistics.iterations++;

                ValueType mid =
                    low +
                    (high - low) / 2;

                result.statistics.comparisons++;

                if (predicate_(mid))
                {
                    answer = mid;
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }

                result.statistics.branchCount++;
            }

            result.status =
                SearchStatus::Success;

            result.value =
                answer;

            result.index = 0;

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
    typename ValueType,
    typename Predicate
>
requires SearchPredicate<
    Predicate,
    ValueType
>
SearchResult<ValueType>
binarySearchAnswer(
    ValueType low,
    ValueType high,
    Predicate predicate
)
{
    BinarySearchAnswerPolicy<
        ValueType,
        Predicate
    > policy(
        std::move(predicate)
    );

    return policy.execute(
        low,
        high
    );
}

} // namespace aubs

#endif