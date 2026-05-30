#include <iostream>
#include <vector>

int linearSearch(const std::vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int main() {
    std::vector<int> arr = {12, 7, 15, 9, 21};
    int target = 9;

    int index = linearSearch(arr, target);

    if (index != -1) {
        std::cout << "Element found at index: " << index << '\n';
    } else {
        std::cout << "Element not found\n";
    }

    return 0;
}
