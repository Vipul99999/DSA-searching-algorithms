function quadraticBinarySearch(
    arr,
    target
) {

    let low = 0;

    let high =
        arr.length - 1;

    while (
        low <= high
    ) {

        let range =
            high - low;

        let pos =
            low +
            Math.floor(
                (
                    range *
                    range
                )
                /
                (
                    2 *
                    (
                        range + 1
                    )
                )
            );

        if (
            pos > high
        )
            pos =
                low +
                Math.floor(
                    range / 2
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
70,
80,
90
];

console.log(
quadraticBinarySearch(
arr,
70
));
