#include <iostream>
#include <vector>
#include <algorithm>

class BinarySearchOnAnswer
{
public:

    static bool canComplete(
        int speed,
        const std::vector<int>& piles,
        int hours)
    {
        long long totalHours = 0;

        for (int pile : piles)
        {
            totalHours +=
                (pile + speed - 1) / speed;

            if (totalHours > hours)
            {
                return false;
            }
        }

        return true;
    }

    static int solve(
        const std::vector<int>& piles,
        int hours)
    {
        int left = 1;

        int right =
            *std::max_element(
                piles.begin(),
                piles.end());

        int answer = right;

        while (left <= right)
        {
            int mid =
                left + (right - left) / 2;

            if (canComplete(
                    mid,
                    piles,
                    hours))
            {
                answer = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return answer;
    }
};

int main()
{
    std::vector<int> piles =
    {
        3, 6, 7, 11
    };

    int hours = 8;

    std::cout
        << "Minimum Speed: "
        << BinarySearchOnAnswer::solve(
               piles,
               hours)
        << '\n';

    return 0;
}
