#include <stdio.h>

int moveToFrontSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            int foundElement = arr[i];

            while (i > 0) {
                arr[i] = arr[i - 1];
                i--;
            }

            arr[0] = foundElement;

            return 0;
        }
    }

    return -1;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 40;

    printf("Before Search:\n");
    printArray(arr, size);

    int result = moveToFrontSearch(arr, size, target);

    if (result != -1) {
        printf("Element found and moved to front.\n");
    } else {
        printf("Element not found.\n");
    }

    printf("After Search:\n");
    printArray(arr, size);

    return 0;
}
