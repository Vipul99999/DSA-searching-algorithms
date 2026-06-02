function binarySearch(arr, target) {
    let left = 0;
    let right = arr.length - 1;

    while (left <= right) {
        const mid = left + Math.floor((right - left) / 2);

        if (arr[mid] === target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

const catalogs = [
    [1, 4, 7, 10, 13],
    [2, 5, 8, 11, 14],
    [3, 6, 9, 12, 15]
];

const target = 11;

catalogs.forEach((catalog, index) => {
    console.log(
        `Catalog ${index + 1}: ${
            binarySearch(catalog, target)
        }`
    );
});
