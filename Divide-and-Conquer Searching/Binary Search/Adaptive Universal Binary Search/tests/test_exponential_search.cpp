#include <cassert>
#include <vector>

#include "../include/exponential_search_policy.hpp"

using namespace aubs;

void testExponentialSearch()
{
    std::vector<int> data =
    {
        2,4,6,8,10,12,14
    };

    auto result =
        exponentialSearch(
            data.begin(),
            data.end(),
            10
        );

    assert(result.found());
    assert(result.index == 4);
}