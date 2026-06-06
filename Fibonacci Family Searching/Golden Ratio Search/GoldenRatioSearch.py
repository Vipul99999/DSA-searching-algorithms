import math


def objective(x):
    return (
        (x - 3) ** 2
        + 5
    )


def golden_ratio_search(
        left,
        right,
        tolerance
):

    phi = (
        1 +
        math.sqrt(5)
    ) / 2

    x1 = (
        right -
        (
            right - left
        ) / phi
    )

    x2 = (
        left +
        (
            right - left
        ) / phi
    )

    while (
        abs(
            right - left
        )
        > tolerance
    ):

        if (
            objective(x1)
            <
            objective(x2)
        ):

            right = x2

            x2 = x1

            x1 = (
                right -
                (
                    right -
                    left
                ) / phi
            )

        else:

            left = x1

            x1 = x2

            x2 = (
                left +
                (
                    right -
                    left
                ) / phi
            )

    return (
        left +
        right
    ) / 2


result = (
    golden_ratio_search(
        -10,
        10,
        0.0001
    )
)

print(
    f"Minimum near {result:.5f}"
)
