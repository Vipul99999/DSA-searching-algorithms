#ifndef AUBS_CONCEPTS_HPP
#define AUBS_CONCEPTS_HPP

#include <concepts>
#include <iterator>

namespace aubs {

template<typename Iterator>
concept RandomAccessIterator =
    std::random_access_iterator<
        Iterator
    >;

template<
    typename Predicate,
    typename Value
>
concept SearchPredicate =
    requires(
        Predicate predicate,
        Value value
    )
{
    {
        predicate(value)
    } -> std::convertible_to<bool>;
};

}

#endif