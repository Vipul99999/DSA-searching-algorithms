function interpolationSearch(
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
            arr[low]
            ===
            arr[high]
        )
            return (
                arr[low]
                ===
                target
            )
                ? low
                : -1;

        let pos =
            low +
            Math.floor(
                (
                    (
                        target
                        -
                        arr[low]
                    )
                    *
                    (
                        high
                        -
                        low
                    )
                )
                /
                (
                    arr[high]
                    -
                    arr[low]
                )
            );

        if (
            arr[pos]
            ===
            target
        )
            return pos;

        if (
            arr[pos]
            <
            target
        )
            low =
                pos + 1;
        else
            high =
                pos - 1;
    }

    return -1;
}

const arr =
[
10,
20,
30,
40,
50,
60,
70
];

console.log(
interpolationSearch(
arr,
50
));
