/*
===============================================================================
 Adaptive Universal Binary Search (AUBS)
 File        : exact_search_policy.hpp
 Version     : 1.0.0
 Author      : AUBS Research Project
 License     : MIT

 Description:
 ------------------------------------------------------------------------------
 Production-grade Exact Search Policy implementation.

 Features:
 • Generic Iterator Support
 • Generic Comparator Support
 • Statistics Tracking
 • Exception Safe
 • Unit-Test Friendly
 • Compatible with BinarySearchEngine
 • O(log n) Complexity

 Dependencies:
 • aubs.hpp

===============================================================================
*/

#ifndef AUBS_EXACT_SEARCH_POLICY_HPP
#define AUBS_EXACT_SEARCH_POLICY_HPP

#include "aubs.hpp"

namespace aubs {

/*
===============================================================================
 Exact Search Policy
===============================================================================
*/

template<
    RandomAccessIterator Iterator,
    typename ValueType,
    typename Comparator = std::less<>
>
class ExactSearchPolicy final
    : public ISearchPolicy<
          Iterator,
          ValueType
      >
{
private:

    Comparator comparator_;

public:

    using iterator_type = Iterator;
    using value_type = ValueType;
    using comparator_type = Comparator;

    /*
    ===========================================================================
    Constructor
    ===========================================================================
    */

    explicit ExactSearchPolicy(
        Comparator comparator = Comparator{}
    )
        : comparator_(std::move(comparator))
    {
    }

    /*
    ===========================================================================
    Execute Search
    ===========================================================================
    */

    SearchResult<ValueType> execute(
        Iterator begin,
        Iterator end,
        const ValueType& target
    ) override
    {
        SearchResult<ValueType> result;

        try
        {
            if (begin == end)
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
                std::distance(begin, end) - 1;

            while (left <= right)
            {
                result.statistics.iterations++;

                difference_type mid =
                    left + (right - left) / 2;

                auto current =
                    *(begin + mid);

                result.statistics.comparisons++;

                /*
                ---------------------------------------------------------------
                Equality Check
                ---------------------------------------------------------------
                */

                bool less1 =
                    comparator_(current, target);

                bool less2 =
                    comparator_(target, current);

                result.statistics.comparisons += 2;

                if (!less1 && !less2)
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

                result.statistics.branchCount++;

                /*
                ---------------------------------------------------------------
                Go Right
                ---------------------------------------------------------------
                */

                if (less1)
                {
                    left = mid + 1;
                }

                /*
                ---------------------------------------------------------------
                Go Left
                ---------------------------------------------------------------
                */

                else
                {
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

    /*
    ===========================================================================
    Comparator Access
    ===========================================================================
    */

    [[nodiscard]]
    const Comparator&
    comparator() const noexcept
    {
        return comparator_;
    }
};

/*
===============================================================================
 Factory Helper
===============================================================================
*/

template<
    RandomAccessIterator Iterator,
    typename ValueType,
    typename Comparator = std::less<>
>
[[nodiscard]]
auto makeExactSearchPolicy(
    Comparator comparator = Comparator{}
)
{
    return ExactSearchPolicy<
        Iterator,
        ValueType,
        Comparator
    >(
        std::move(comparator)
    );
}

/*
===============================================================================
 Convenience Function
===============================================================================
*/

template<
    RandomAccessIterator Iterator,
    typename ValueType,
    typename Comparator = std::less<>
>
[[nodiscard]]
SearchResult<ValueType>
exactSearch(
    Iterator begin,
    Iterator end,
    const ValueType& target,
    Comparator comparator = Comparator{}
)
{
    ExactSearchPolicy<
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

#endif // AUBS_EXACT_SEARCH_POLICY_HPP