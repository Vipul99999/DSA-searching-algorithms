#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int catalog1[] = {1, 4, 7, 10, 13};
    int catalog2[] = {2, 5, 8, 11, 14};
    int catalog3[] = {3, 6, 9, 12, 15};

    int target = 11;

    printf("Catalog 1: %d\n",
           binarySearch(catalog1, 5, target));

    printf("Catalog 2: %d\n",
           binarySearch(catalog2, 5, target));

    printf("Catalog 3: %d\n",
           binarySearch(catalog3, 5, target));

    return 0;
}
