#include <stdio.h>

int linearSearch(const int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[] = {12, 7, 15, 9, 21};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    int index = linearSearch(arr, size, target);

    if (index != -1) {
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
