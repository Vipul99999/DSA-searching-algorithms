#include <iostream>
#include <vector>

using namespace std;

int recursiveBinarySearch(
    const vector<int>& arr,
    int left,
    int right,
    int target)
{
    if (left > right)
    {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }

    if (arr[mid] < target)
    {
        return recursiveBinarySearch(
            arr,
            mid + 1,
            right,
            target
        );
    }

    return recursiveBinarySearch(
        arr,
        left,
        mid - 1,
        target
    );
}

int main()
{
    vector<int> arr = {
        5, 12, 18, 25, 31, 42, 56
    };

    int target = 42;

    int index = recursiveBinarySearch(
        arr,
        0,
        static_cast<int>(arr.size()) - 1,
        target
    );

    if (index != -1)
    {
        cout << "Element "
             << target
             << " found at index "
             << index
             << endl;
    }
    else
    {
        cout << "Element "
             << target
             << " not found"
             << endl;
    }

    return 0;
}
