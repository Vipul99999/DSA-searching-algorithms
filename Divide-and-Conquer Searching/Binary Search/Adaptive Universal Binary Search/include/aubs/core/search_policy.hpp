#ifndef AUBS_SEARCH_POLICY_HPP
#define AUBS_SEARCH_POLICY_HPP

#include "search_result.hpp"

namespace aubs {

template<
    typename Iterator,
    typename Value
>
class ISearchPolicy
{
public:

    virtual
    ~ISearchPolicy() = default;

    virtual SearchResult<Value>
    execute(
        Iterator begin,
        Iterator end,
        const Value& target
    ) = 0;
};

}

#endif