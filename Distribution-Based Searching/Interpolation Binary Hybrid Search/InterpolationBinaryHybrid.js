function interpolationBinaryHybrid(
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
            arr[pos]
            ===
            target
        )
            return pos;

        if (
            high -
            low < 6
        ) {

            let mid =
                Math.floor(
                    (
                        low +
                        high
                    ) / 2
                );

            if (
                arr[mid]
                ===
                target
            )
                return mid;

            if (
                arr[mid]
                <
                target
            )
                low =
                    mid + 1;
            else
                high =
                    mid - 1;

            continue;
        }

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
1000,
5000
];

console.log(
interpolationBinaryHybrid(
arr,
1000
));
