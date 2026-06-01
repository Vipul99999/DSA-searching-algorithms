function searchInsertPosition(arr, target) {
    let left = 0;
    let right = arr.length - 1;

    while (left <= right) {
        const mid =
            Math.floor(
                left + (right - left) / 2
            );

        if (arr[mid] === target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return left;
}

const arr = [1, 3, 5, 6];
const target = 5;

console.log(
    "Position:",
    searchInsertPosition(arr, target)
);
