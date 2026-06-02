#include <iostream>
#include <vector>
using namespace std;

int recursiveTernarySearch(const vector<int>& arr, int left, int right, int target) {
    if (left > right)
        return -1;

    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right - left) / 3;

    if (arr[mid1] == target)
        return mid1;

    if (arr[mid2] == target)
        return mid2;

    if (target < arr[mid1])
        return recursiveTernarySearch(arr, left, mid1 - 1, target);

    if (target > arr[mid2])
        return recursiveTernarySearch(arr, mid2 + 1, right, target);

    return recursiveTernarySearch(arr, mid1 + 1, mid2 - 1, target);
}

int main() {
    vector<int> arr = {5, 10, 15, 20, 25, 30, 35, 40, 45};
    int target = 30;

    int index = recursiveTernarySearch(arr, 0, arr.size() - 1, target);

    if (index != -1)
        cout << "Element found at index " << index << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
