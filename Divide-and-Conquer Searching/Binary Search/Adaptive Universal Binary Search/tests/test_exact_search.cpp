#include <cassert>
#include <vector>

#include "../include/aubs.hpp"
#include "../include/exact_search_policy.hpp"

using namespace aubs;

void testExactSearch()
{
    std::vector<int> data =
    {
        10,20,30,40,50
    };

    auto result =
        exactSearch(
            data.begin(),
            data.end(),
            30
        );

    assert(result.found());
    assert(result.index == 2);
    assert(*result.value == 30);
}

void testExactSearchNotFound()
{
    std::vector<int> data =
    {
        10,20,30
    };

    auto result =
        exactSearch(
            data.begin(),
            data.end(),
            99
        );

    assert(!result.found());
}