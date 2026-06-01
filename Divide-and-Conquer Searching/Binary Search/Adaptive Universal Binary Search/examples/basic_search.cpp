#include <vector>

#include <aubs.hpp>

int main()
{
    std::vector<int> values =
    {
        10,
        20,
        30,
        40,
        50
    };

    auto result =
        aubs::exactSearch(
            values.begin(),
            values.end(),
            30
        );

    return result.found()
        ? 0
        : 1;
}