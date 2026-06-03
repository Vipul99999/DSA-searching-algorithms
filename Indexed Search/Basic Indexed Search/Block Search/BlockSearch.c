#include <stdio.h>
#include <math.h>

int blockSearch(int arr[], int n, int target) {

    int blockSize = (int)sqrt(n);

    int start = 0;

    while (start < n) {

        int end = start + blockSize - 1;

        if (end >= n)
            end = n - 1;

        if (target <= arr[end]) {

            for (int i = start; i <= end; i++) {
                if (arr[i] == target)
                    return i;
            }

            return -1;
        }

        start += blockSize;
    }

    return -1;
}

int main() {

    int arr[] =
    {2,5,8,12,16,20,24,28,32,40};

    int n =
        sizeof(arr)/sizeof(arr[0]);

    int target = 24;

    int index =
        blockSearch(
            arr,
            n,
            target
        );

    if(index!=-1)
        printf(
            "Found at index %d\n",
            index
        );
    else
        printf(
            "Not Found\n"
        );

    return 0;
}
