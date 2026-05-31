function recursiveBinarySearch(
    arr,
    left,
    right,
    target
) {
    if (left > right) {
        return -1;
    }

    const mid =
        left + Math.floor((right - left) / 2);

    if (arr[mid] === target) {
        return mid;
    }

    if (arr[mid] < target) {
        return recursiveBinarySearch(
            arr,
            mid + 1,
            right,
            target
        );
    }

    return recursiveBinarySearch(
        arr,
        left,
        mid - 1,
        target
    );
}

const arr = [
    5, 12, 18, 25, 31, 42, 56
];

const target = 42;

const index = recursiveBinarySearch(
    arr,
    0,
    arr.length - 1,
    target
);

if (index !== -1) {
    console.log(
        `Element ${target} found at index ${index}`
    );
} else {
    console.log(
        `Element ${target} not found`
    );
}
