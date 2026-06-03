#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int maxValue;
    int start;
} Index;

int indexedSequentialSearch(
    int arr[],
    int n,
    int target
){

    int block =
        (int)sqrt(n);

    int count =
        (n + block - 1)
        / block;

    Index* index =
        malloc(
            count
            *
            sizeof(Index)
        );

    for(
        int i=0;
        i<count;
        i++
    ){

        int start =
            i*block;

        int end =
            start
            +
            block
            -
            1;

        if(end>=n)
            end=n-1;

        index[i].start=
            start;

        index[i].maxValue=
            arr[end];
    }

    int chosen=-1;

    for(
        int i=0;
        i<count;
        i++
    ){

        if(
            target
            <=
            index[i]
            .maxValue
        ){

            chosen=i;

            break;

        }

    }

    if(chosen==-1){

        free(index);

        return -1;

    }

    int start=
        index[
        chosen
        ]
        .start;

    int end=
        start
        +
        block
        -
        1;

    if(end>=n)
        end=n-1;

    for(
        int i=start;
        i<=end;
        i++
    ){

        if(
            arr[i]
            ==
            target
        ){

            free(index);

            return i;

        }

    }

    free(index);

    return -1;

}

int main(){

int arr[]=
{
2,5,8,12,
16,20,24,
28,32,40
};

int n=
sizeof(arr)
/
sizeof(arr[0]);

int result=
indexedSequentialSearch(
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
