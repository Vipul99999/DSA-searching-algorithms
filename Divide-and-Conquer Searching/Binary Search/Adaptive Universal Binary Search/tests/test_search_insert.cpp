#include <cassert>
#include <vector>

#include "../include/search_insert_policy.hpp"

using namespace aubs;

void testInsertPosition()
{
    std::vector<int> data =
    {
        1,3,5,6
    };

    auto result =
        searchInsertPosition(
            data.begin(),
            data.end(),
            2
        );

    assert(result.index == 1);
}