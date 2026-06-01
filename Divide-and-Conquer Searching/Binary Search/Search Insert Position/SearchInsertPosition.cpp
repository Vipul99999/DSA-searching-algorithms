#include <iostream>
#include <vector>

int searchInsertPosition(
    const std::vector<int>& arr,
    int target)
{
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return left;
}

int main()
{
    std::vector<int> arr = {1, 3, 5, 6};
    int target = 5;

    std::cout
        << "Position: "
        << searchInsertPosition(arr, target)
        << '\n';

    return 0;
}
