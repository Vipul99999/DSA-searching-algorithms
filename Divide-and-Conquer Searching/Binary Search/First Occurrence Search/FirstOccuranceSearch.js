function firstOccurrenceSearch(
    arr,
    target
) {
    let left = 0;
    let right = arr.length - 1;
    let answer = -1;

    while (left <= right) {
        const mid =
            left + Math.floor(
                (right - left) / 2
            );

        if (arr[mid] === target) {
            answer = mid;
            right = mid - 1;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return answer;
}

const arr = [
    1, 3, 3, 3, 5, 7, 9
];

const target = 3;

const index =
    firstOccurrenceSearch(
        arr,
        target
    );

if (index !== -1) {
    console.log(
        `First occurrence of ${target} ` +
        `found at index ${index}`
    );
} else {
    console.log(
        `${target} not found in array`
    );
}
