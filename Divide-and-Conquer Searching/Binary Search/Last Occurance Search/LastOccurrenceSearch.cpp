#include <iostream>
#include <vector>

using namespace std;

int lastOccurrenceSearch(
    const vector<int>& arr,
    int target)
{
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;
    int answer = -1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            answer = mid;
            left = mid + 1;
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

    return answer;
}

int main()
{
    vector<int> arr = {
        1, 3, 3, 3, 5, 7, 9
    };

    int target = 3;

    int index = lastOccurrenceSearch(
        arr,
        target
    );

    if (index != -1)
    {
        cout << "Last occurrence of "
             << target
             << " found at index "
             << index
             << endl;
    }
    else
    {
        cout << target
             << " not found in array"
             << endl;
    }

    return 0;
}
