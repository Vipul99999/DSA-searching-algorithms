#include <vector>

#include <rotated_search_policy.hpp>

int main()
{
    std::vector<int> data =
    {
        4,
        5,
        6,
        7,
        0,
        1,
        2
    };

    auto result =
        aubs::rotatedSearch(
            data.begin(),
            data.end(),
            0
        );
}