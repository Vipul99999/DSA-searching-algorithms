function iterativeBinarySearch(arr, target) {
    let left = 0;
    let right = arr.length - 1;

    while (left <= right) {
        const mid = left + Math.floor((right - left) / 2);

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

    return -1;
}

const arr = [5, 12, 18, 25, 31, 42, 56];
const target = 31;

const index = iterativeBinarySearch(arr, target);

if (index !== -1) {
    console.log(
        `Element ${target} found at index ${index}`
    );
} else {
    console.log(
        `Element ${target} not found`
    );
}
