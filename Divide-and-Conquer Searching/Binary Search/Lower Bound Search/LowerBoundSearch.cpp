#include <iostream>
#include <vector>

using namespace std;

int lowerBoundSearch(const vector<int>& arr, int target)
{
    int left = 0;
    int right = static_cast<int>(arr.size()) - 1;
    int answer = static_cast<int>(arr.size());

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= target)
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

int main()
{
    vector<int> arr = {1, 3, 3, 3, 5, 7, 9};
    int target = 3;

    int index = lowerBoundSearch(arr, target);

    if (index < arr.size())
    {
        cout << "Lower Bound of "
             << target
             << " is at index "
             << index
             << endl;
    }
    else
    {
        cout << "Lower Bound position is at end of array ("
             << index
             << ")"
             << endl;
    }

    return 0;
}
