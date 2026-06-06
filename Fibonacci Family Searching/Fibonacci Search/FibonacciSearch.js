function fibonacciSearch(
    arr,
    target
) {

    let fibMMm2 = 0;

    let fibMMm1 = 1;

    let fibM =
        fibMMm1 +
        fibMMm2;

    while (
        fibM <
        arr.length
    ) {

        fibMMm2 =
        fibMMm1;

        fibMMm1 =
        fibM;

        fibM =
        fibMMm1 +
        fibMMm2;
    }

    let offset = -1;

    while (
        fibM > 1
    ) {

        const i =
        Math.min(
            offset +
            fibMMm2,
            arr.length - 1
        );

        if (
            arr[i]
            <
            target
        ) {

            fibM =
            fibMMm1;

            fibMMm1 =
            fibMMm2;

            fibMMm2 =
            fibM -
            fibMMm1;

            offset = i;

        }

        else if (
            arr[i]
            >
            target
        ) {

            fibM =
            fibMMm2;

            fibMMm1 =
            fibMMm1 -
            fibMMm2;

            fibMMm2 =
            fibM -
            fibMMm1;

        }

        else {
            return i;
        }
    }

    if (
        fibMMm1 &&
        offset + 1 <
        arr.length &&
        arr[offset+1]
        === target
    ) {
        return offset+1;
    }

    return -1;
}

const arr = [
    10,20,30,
    40,50,60,
    70,80,90
];

const target = 50;

const result =
fibonacciSearch(
    arr,
    target
);

console.log(
result !== -1
?
`Found at index ${result}`
:
"Not Found"
);
