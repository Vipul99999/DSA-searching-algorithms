#include <iostream>
#include <cmath>

using namespace std;

int blockSearch(
    int arr[],
    int n,
    int target
){

    int block =
        sqrt(n);

    int start = 0;

    while(start<n){

        int end =
            min(
                start+block-1,
                n-1
            );

        if(
            target
            <=
            arr[end]
        ){

            for(
                int i=start;
                i<=end;
                i++
            )
                if(
                    arr[i]
                    ==
                    target
                )
                    return i;

            return -1;
        }

        start+=block;
    }

    return -1;
}

int main(){

int arr[]=
{
2,5,8,12,16,
20,24,28,32,40
};

int n=
sizeof(arr)
/sizeof(arr[0]);

int target=24;

int result=
blockSearch(
arr,
n,
target
);

if(result!=-1)
cout
<<"Found at "
<<result;

else
cout
<<"Not Found";
}
