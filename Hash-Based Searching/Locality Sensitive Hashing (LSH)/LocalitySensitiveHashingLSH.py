"""
LocalitySensitiveHashingLSH.py
Cosine Similarity LSH using Random Hyperplanes
"""

DIMENSIONS = 4
HYPERPLANES = 3


class Vector:

    def __init__(self, values):
        self.values = values


def dot_product(a, b):

    result = 0.0

    for i in range(DIMENSIONS):

        result += (
            a.values[i]
            * b.values[i]
        )

    return result


def compute_hash(
    point,
    hyperplanes
):

    hash_value = 0

    for i in range(HYPERPLANES):

        if (
            dot_product(
                point,
                hyperplanes[i]
            )
            >= 0
        ):

            hash_value |= (
                1 << i
            )

    return hash_value


if __name__ == "__main__":

    hyperplanes = [

        Vector(
            [1, 0, -1, 0]
        ),

        Vector(
            [0, 1, 0, -1]
        ),

        Vector(
            [1, 1, 1, 1]
        )
    ]

    point1 = Vector(
        [2, 3, 1, 0]
    )

    point2 = Vector(
        [2, 2, 1, 1]
    )

    hash1 = compute_hash(
        point1,
        hyperplanes
    )

    hash2 = compute_hash(
        point2,
        hyperplanes
    )

    print(
        "Point1 Hash:",
        hash1
    )

    print(
        "Point2 Hash:",
        hash2
    )

    if hash1 == hash2:
        print(
            "Likely Similar"
        )
    else:
        print(
            "Likely Different"
        )
