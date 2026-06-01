#include <cassert>
#include <vector>

#include "../include/lower_bound_policy.hpp"

using namespace aubs;

void testLowerBound()
{
    std::vector<int> data =
    {
        1,2,2,2,5
    };

    auto result =
        lowerBoundSearch(
            data.begin(),
            data.end(),
            2
        );

    assert(result.found());
    assert(result.index == 1);
}