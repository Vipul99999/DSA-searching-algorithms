#include <iostream>
#include <vector>
using namespace std;

int iterativeTernarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == target)
            return mid1;

        if (arr[mid2] == target)
            return mid2;

        if (target < arr[mid1]) {
            right = mid1 - 1;
        } else if (target > arr[mid2]) {
            left = mid2 + 1;
        } else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {5, 10, 15, 20, 25, 30, 35, 40, 45};
    int target = 30;

    int index = iterativeTernarySearch(arr, target);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
