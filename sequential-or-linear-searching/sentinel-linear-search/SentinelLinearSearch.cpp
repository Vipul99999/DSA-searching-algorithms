#include <iostream>
#include <vector>

int sentinelLinearSearch(std::vector<int>& arr, int target) {
    int n = static_cast<int>(arr.size());

    if (n == 0) {
        return -1;
    }

    int last = arr[n - 1];

    arr[n - 1] = target;

    int i = 0;
    while (arr[i] != target) {
        ++i;
    }

    arr[n - 1] = last;

    if (i < n - 1 || last == target) {
        return i;
    }

    return -1;
}

int main() {
    std::vector<int> arr = {10, 25, 7, 14, 30};
    int target = 14;

    int index = sentinelLinearSearch(arr, target);

    if (index != -1) {
        std::cout << "Element found at index: " << index << '\n';
    } else {
        std::cout << "Element not found\n";
    }

    return 0;
}
