function objective(
    x
) {

    return (
        (x - 3) *
        (x - 3)
        + 5
    );
}

function goldenRatioSearch(
    left,
    right,
    tolerance
) {

    const phi =
    (
        1 +
        Math.sqrt(5)
    ) / 2;

    let x1 =
    right -
    (
        right-left
    ) / phi;

    let x2 =
    left +
    (
        right-left
    ) / phi;

    while (
        Math.abs(
            right-left
        )
        >
        tolerance
    ) {

        if (
            objective(x1)
            <
            objective(x2)
        ) {

            right = x2;

            x2 = x1;

            x1 =
            right -
            (
                right-left
            ) / phi;

        } else {

            left = x1;

            x1 = x2;

            x2 =
            left +
            (
                right-left
            ) / phi;
        }
    }

    return (
        left +
        right
    ) / 2;
}

const result =
goldenRatioSearch(
    -10,
    10,
    0.0001
);

console.log(
`Minimum near ${result.toFixed(5)}`
);
