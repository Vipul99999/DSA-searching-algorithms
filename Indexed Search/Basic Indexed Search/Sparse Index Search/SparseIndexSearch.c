#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int key;
    int position;
} SparseIndex;

int sparseIndexSearch(
    int arr[],
    int n,
    int target
) {

    int step = (int)sqrt(n);

    int count =
        (n + step - 1)
        / step;

    SparseIndex* index =
        malloc(
            count
            *
            sizeof(SparseIndex)
        );

    int k = 0;

    for (
        int i = 0;
        i < n;
        i += step
    ) {

        index[k].key =
            arr[i];

        index[k].position =
            i;

        k++;

    }

    int start = 0;

    for (
        int i = 0;
        i < count;
        i++
    ) {

        if (
            index[i].key
            >
            target
        ) {

            break;

        }

        start =
            index[i]
            .position;

    }

    int end =
        start
        +
        step
        -
        1;

    if (
        end >= n
    )
        end =
            n - 1;

    for (
        int i = start;
        i <= end;
        i++
    ) {

        if (
            arr[i]
            ==
            target
        ) {

            free(index);

            return i;

        }

    }

    free(index);

    return -1;

}

int main() {

int arr[] =
{
2,5,8,12,
16,20,24,
28,32,40
};

int n =
sizeof(arr)
/
sizeof(arr[0]);

int result =
sparseIndexSearch(
arr,
n,
24
);

if(result!=-1)
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
