#include <cassert>
#include <vector>

#include "../include/upper_bound_policy.hpp"

using namespace aubs;

void testUpperBound()
{
    std::vector<int> data =
    {
        1,2,2,2,5
    };

    auto result =
        upperBoundSearch(
            data.begin(),
            data.end(),
            2
        );

    assert(result.index == 4);
}