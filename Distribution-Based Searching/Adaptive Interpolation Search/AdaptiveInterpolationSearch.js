function adaptiveInterpolationSearch(
    arr,
    target
) {

    let low = 0;
    let high =
        arr.length - 1;

    while (
        low <= high &&
        target >= arr[low] &&
        target <= arr[high]
    ) {

        if (
            arr[low] ===
            arr[high]
        ) {
            return (
                arr[low] === target
            )
                ? low
                : -1;
        }

        let pos =
            low +
            Math.floor(
                (
                    (target - arr[low]) *
                    (high - low)
                ) /
                (
                    arr[high]
                    - arr[low]
                )
            );

        if (
            pos < low ||
            pos > high
        ) {
            pos =
                Math.floor(
                    (
                        low +
                        high
                    ) / 2
                );
        }

        if (
            arr[pos] === target
        )
            return pos;

        if (
            arr[pos] <
            target
        )
            low = pos + 1;
        else
            high = pos - 1;

        if (
            high - low < 5
        ) {

            let mid =
                Math.floor(
                    (
                        low +
                        high
                    ) / 2
                );

            if (
                arr[mid] ===
                target
            )
                return mid;

            if (
                arr[mid] <
                target
            )
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    return -1;
}

const arr =
[
10,
20,
25,
35,
50,
70,
100,
150
];

const target = 70;

const result =
adaptiveInterpolationSearch(
    arr,
    target
);

console.log(
    result !== -1
        ? `Found at index ${result}`
        : "Not Found"
);
