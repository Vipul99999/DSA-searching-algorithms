#include <iostream>
#include <vector>

class PeakElementSearch
{
public:

    static int findPeakElement(
        const std::vector<int>& nums)
    {
        int left = 0;
        int right =
            static_cast<int>(nums.size()) - 1;

        while (left < right)
        {
            int mid =
                left + (right - left) / 2;

            if (nums[mid] < nums[mid + 1])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }
};

int main()
{
    std::vector<int> nums =
    {
        1, 2, 3, 1
    };

    int peakIndex =
        PeakElementSearch::findPeakElement(nums);

    std::cout
        << "Peak Element Index: "
        << peakIndex
        << '\n';

    std::cout
        << "Peak Element Value: "
        << nums[peakIndex]
        << '\n';

    return 0;
}
