#include <stdio.h>
#include <stdlib.h>

#define DIMENSIONS 4
#define HYPERPLANES 3

typedef struct {
    double values[DIMENSIONS];
} Vector;

double dotProduct(
    Vector a,
    Vector b
) {
    double result = 0.0;

    for (
        int i = 0;
        i < DIMENSIONS;
        i++
    ) {
        result +=
            a.values[i] *
            b.values[i];
    }

    return result;
}

int computeHash(
    Vector point,
    Vector planes[]
) {

    int hash = 0;

    for (
        int i = 0;
        i < HYPERPLANES;
        i++
    ) {

        if (
            dotProduct(
                point,
                planes[i]
            ) >= 0
        ) {
            hash |= (1 << i);
        }
    }

    return hash;
}

int main() {

    Vector hyperplanes[
        HYPERPLANES
    ] = {
        {{1, 0, -1, 0}},
        {{0, 1, 0, -1}},
        {{1, 1, 1, 1}}
    };

    Vector point1 =
        {{2, 3, 1, 0}};

    Vector point2 =
        {{2, 2, 1, 1}};

    int hash1 =
        computeHash(
            point1,
            hyperplanes
        );

    int hash2 =
        computeHash(
            point2,
            hyperplanes
        );

    printf(
        "Point1 Hash: %d\n",
        hash1
    );

    printf(
        "Point2 Hash: %d\n",
        hash2
    );

    if (hash1 == hash2)
        printf(
            "Likely Similar\n"
        );
    else
        printf(
            "Likely Different\n"
        );

    return 0;
}
