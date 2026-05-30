#include <iostream>
#include <vector>

int moveToFrontSearch(std::vector<int>& arr, int target) {
    int n = static_cast<int>(arr.size());

    for (int i = 0; i < n; ++i) {
        if (arr[i] == target) {
            int foundElement = arr[i];

            while (i > 0) {
                arr[i] = arr[i - 1];
                --i;
            }

            arr[0] = foundElement;

            return 0;
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

    int index = moveToFrontSearch(arr, target);

    if (index != -1) {
        std::cout << "Element found and moved to front.\n";
    } else {
        std::cout << "Element not found.\n";
    }

    std::cout << "After Search: ";
    printArray(arr);

    return 0;
}
