#include <iostream>
#include <vector>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

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
    vector<vector<int>> catalogs = {
        {1,4,7,10,13},
        {2,5,8,11,14},
        {3,6,9,12,15}
    };

    int target = 11;

    for (int i = 0; i < catalogs.size(); i++) {
        cout << "Catalog "
             << i + 1
             << ": "
             << binarySearch(catalogs[i], target)
             << endl;
    }

    return 0;
}
