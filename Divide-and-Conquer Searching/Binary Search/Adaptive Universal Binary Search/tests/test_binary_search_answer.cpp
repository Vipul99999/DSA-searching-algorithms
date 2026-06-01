#include <cassert>

#include "../include/binary_search_answer_policy.hpp"

using namespace aubs;

void testBinarySearchAnswer()
{
    auto result =
        binarySearchAnswer(
            0LL,
            100LL,
            [](long long x)
            {
                return x * x >= 81;
            }
        );

    assert(result.found());
    assert(*result.value == 9);
}