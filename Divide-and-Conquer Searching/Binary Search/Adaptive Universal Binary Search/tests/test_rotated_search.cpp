#include <cassert>
#include <vector>

#include "../include/rotated_search_policy.hpp"

using namespace aubs;

void testRotatedSearch()
{
    std::vector<int> data =
    {
        4,5,6,7,0,1,2
    };

    auto result =
        rotatedSearch(
            data.begin(),
            data.end(),
            0
        );

    assert(result.found());
    assert(result.index == 4);
}