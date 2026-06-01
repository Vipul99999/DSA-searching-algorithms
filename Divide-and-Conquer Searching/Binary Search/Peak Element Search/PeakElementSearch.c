#include <stdio.h>

int findPeakElement(int arr[], int size)
{
    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] < arr[mid + 1])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return left;
}

int main()
{
    int arr[] = {1, 2, 3, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    int peakIndex = findPeakElement(arr, size);

    printf("Peak Element Index: %d\n", peakIndex);
    printf("Peak Element Value: %d\n", arr[peakIndex]);

    return 0;
}
