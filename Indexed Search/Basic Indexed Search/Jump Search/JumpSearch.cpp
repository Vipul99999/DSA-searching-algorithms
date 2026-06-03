#include <iostream>
#include <cmath>

using namespace std;

int jumpSearch(int arr[], int n, int target) {

    int step = sqrt(n);
    int prev = 0;

    while (prev < n && arr[min(step, n) - 1] < target) {
        prev = step;
        step += sqrt(n);

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
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found";

    return 0;
}
