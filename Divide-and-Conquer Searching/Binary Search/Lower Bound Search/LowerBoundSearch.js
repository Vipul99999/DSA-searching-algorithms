function lowerBoundSearch(arr, target) {
    let left = 0;
    let right = arr.length - 1;
    let answer = arr.length;

    while (left <= right) {
        const mid =
            left + Math.floor((right - left) / 2);

        if (arr[mid] >= target) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return answer;
}

const arr = [1, 3, 3, 3, 5, 7, 9];
const target = 3;

const index = lowerBoundSearch(
    arr,
    target
);

if (index < arr.length) {
    console.log(
        `Lower Bound of ${target} ` +
        `is at index ${index}`
    );
} else {
    console.log(
        `Lower Bound position is at ` +
        `end of array (${index})`
    );
}
