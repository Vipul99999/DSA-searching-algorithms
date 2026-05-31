#include <iostream>
#include <vector>

using namespace std;

int iterativeBinarySearch(const vector<int>& arr, int target)
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

    return -1;
}

int main()
{
    vector<int> arr = {5, 12, 18, 25, 31, 42, 56};
    int target = 31;

    int index = iterativeBinarySearch(arr, target);

    if (index != -1)
    {
        cout << "Element " << target
             << " found at index "
             << index << endl;
    }
    else
    {
        cout << "Element " << target
             << " not found" << endl;
    }

    return 0;
}
