#include <iostream>
#include <vector>
using namespace std;

int binarySearch(
    const vector<int>& arr,
    int left,
    int right,
    int target
) {

    while (left <= right) {

        int mid =
            left +
            (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int exponentialSearch(
    const vector<int>& arr,
    int target
) {

    if (arr.empty())
        return -1;

    if (arr[0] == target)
        return 0;

    int bound = 1;

    while (
        bound < arr.size() &&
        arr[bound] <= target
    ) {
        bound *= 2;
    }

    return binarySearch(
        arr,
        bound / 2,
        min(
            bound,
            (int)arr.size() - 1
        ),
        target
    );
}

int main() {

    vector<int> arr = {
        5,10,15,20,
        25,30,35,
        40,45,50
    };

    int target = 35;

    int result =
        exponentialSearch(
            arr,
            target
        );

    if (result != -1)
        cout
            << "Found at index "
            << result
            << endl;
    else
        cout << "Not Found";

    return 0;
}
