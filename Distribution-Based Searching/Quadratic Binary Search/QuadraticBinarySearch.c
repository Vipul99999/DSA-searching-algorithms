// Position estimation:

// pos=low+(high−low /2)^2/(high−low)
#include <stdio.h>

int quadraticBinarySearch(
    int arr[],
    int n,
    int target
) {

    int low = 0;
    int high = n - 1;

    while (low <= high) {

        int range =
            high - low;

        int pos =
            low +
            (
                range *
                range
            ) /
            (
                2 *
                (
                    range + 1
                )
            );

        if (pos > high)
            pos = low + range / 2;

        if (arr[pos] == target)
            return pos;

        if (arr[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

int main() {

    int arr[] =
    {
        10,
        20,
        30,
        40,
        50,
        60,
        70,
        80,
        90
    };

    int n =
        sizeof(arr)
        /
        sizeof(arr[0]);

    int target = 70;

    int result =
        quadraticBinarySearch(
            arr,
            n,
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
