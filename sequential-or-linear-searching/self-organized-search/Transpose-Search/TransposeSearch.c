#include <stdio.h>

int transposeSearch(int arr[], int size, int target) {

    for (int i = 0; i < size; i++) {

        if (arr[i] == target) {

            if (i > 0) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;

                return i - 1;
            }

            return i;
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

    int index = transposeSearch(arr, size, target);

    if (index != -1) {
        printf("Element found.\n");
    } else {
        printf("Element not found.\n");
    }

    printf("After Search:\n");
    printArray(arr, size);

    return 0;
}
