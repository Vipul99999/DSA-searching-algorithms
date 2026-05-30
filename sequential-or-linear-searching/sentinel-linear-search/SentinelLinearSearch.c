#include <stdio.h>

int sentinelLinearSearch(int arr[], int size, int target) {
    if (size == 0) {
        return -1;
    }

    int last = arr[size - 1];

    arr[size - 1] = target;

    int i = 0;
    while (arr[i] != target) {
        i++;
    }

    arr[size - 1] = last;

    if (i < size - 1 || last == target) {
        return i;
    }

    return -1;
}

int main() {
    int arr[] = {10, 25, 7, 14, 30};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 14;

    int index = sentinelLinearSearch(arr, size, target);

    if (index != -1) {
        printf("Element found at index: %d\n", index);
    } else {
        printf("Element not found\n");
    }

    return 0;
}
