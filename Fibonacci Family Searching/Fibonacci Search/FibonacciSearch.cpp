#include <iostream>
#include <vector>
using namespace std;

int fibonacciSearch(
        const vector<int>& arr,
        int target
) {

    int fibMMm2 = 0;
    int fibMMm1 = 1;
    int fibM =
        fibMMm1 +
        fibMMm2;

    while (
        fibM <
        arr.size()
    ) {

        fibMMm2 =
        fibMMm1;

        fibMMm1 =
        fibM;

        fibM =
        fibMMm1 +
        fibMMm2;
    }

    int offset = -1;

    while (
        fibM > 1
    ) {

        int i =
        min(
            offset +
            fibMMm2,
            (int)
            arr.size()
            - 1
        );

        if (
            arr[i]
            <
            target
        ) {

            fibM =
            fibMMm1;

            fibMMm1 =
            fibMMm2;

            fibMMm2 =
            fibM -
            fibMMm1;

            offset = i;

        }

        else if (
            arr[i]
            >
            target
        ) {

            fibM =
            fibMMm2;

            fibMMm1 =
            fibMMm1 -
            fibMMm2;

            fibMMm2 =
            fibM -
            fibMMm1;
        }

        else {
            return i;
        }
    }

    if (
        fibMMm1 &&
        offset + 1 <
        arr.size()
        &&
        arr[offset+1]
        ==
        target
    ) {
        return offset+1;
    }

    return -1;
}

int main() {

    vector<int> arr = {
        10,20,30,
        40,50,60,
        70,80,90
    };

    int target = 50;

    int result =
    fibonacciSearch(
        arr,
        target
    );

    if (result != -1)
        cout
        << "Found at index "
        << result
        << endl;

    else
        cout
        << "Not Found";

    return 0;
}
