#include <iostream>
#include <vector>

int transposeSearch(std::vector<int>& arr, int target) {
    int n = static_cast<int>(arr.size());

    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {

            if (i > 0) {
                std::swap(arr[i], arr[i - 1]);
                return i - 1;
            }

            return i;
        }
    }

    return -1;
}

void printArray(const std::vector<int>& arr) {
    for (int value : arr) {
        std::cout << value << " ";
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> arr = {10, 20, 30, 40, 50};
    int target = 40;

    std::cout << "Before Search: ";
    printArray(arr);

    int index = transposeSearch(arr, target);

    if (index != -1) {
        std::cout << "Element found.\n";
    } else {
        std::cout << "Element not found.\n";
    }

    std::cout << "After Search: ";
    printArray(arr);

    return 0;
}
