#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int doublingSearch(int arr[], int size, int target) {

    if (size == 0)
        return -1;

    if (arr[0] == target)
        return 0;

    int index = 1;

    while (index < size && arr[index] <= target)
        index *= 2;

    int left = index / 2;
    int right = (index < size)
                    ? index
                    : size - 1;

    return binarySearch(
        arr,
        left,
        right,
        target
    );
}

int main() {

    int arr[] =
    {
        5,10,15,20,
        25,30,35,
        40,45,50
    };

    int size =
        sizeof(arr) /
        sizeof(arr[0]);

    int target = 35;

    int result =
        doublingSearch(
            arr,
            size,
            target
        );

    if (result != -1)
        printf(
            "Found at index %d\n",
            result
        );
    else
        printf(
            "Not Found\n"
        );

    return 0;
}
