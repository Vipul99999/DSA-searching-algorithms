#include <stdio.h>
#include <math.h>

int jumpSearch(int arr[], int n, int target) {

    int step = (int)sqrt(n);
    int prev = 0;

    while (prev < n && arr[(step < n ? step : n) - 1] < target) {
        prev = step;
        step += (int)sqrt(n);

        if (prev >= n)
            return -1;
    }

    while (prev < n && arr[prev] < target)
        prev++;

    if (prev < n && arr[prev] == target)
        return prev;

    return -1;
}

int main() {

    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 23;

    int result = jumpSearch(arr, n, target);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
