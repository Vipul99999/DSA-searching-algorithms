function binarySearch(
    arr,
    left,
    right,
    target
) {

    while (left <= right) {

        const mid =
            Math.floor(
                left +
                (right - left) / 2
            );

        if (arr[mid] === target)
            return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

function doublingSearch(
    arr,
    target
) {

    if (arr.length === 0)
        return -1;

    if (arr[0] === target)
        return 0;

    let index = 1;

    while (
        index < arr.length &&
        arr[index] <= target
    ) {
        index *= 2;
    }

    return binarySearch(
        arr,
        Math.floor(
            index / 2
        ),
        Math.min(
            index,
            arr.length - 1
        ),
        target
    );
}

const arr =
[
    5,10,15,20,
    25,30,35,
    40,45,50
];

const target = 35;

const result =
    doublingSearch(
        arr,
        target
    );

console.log(
    result !== -1
        ? `Found at index ${result}`
        : "Not Found"
);
