/*
    LocalitySensitiveHashingLSH.js
    Cosine Similarity LSH using Random Hyperplanes
*/

const DIMENSIONS = 4;
const HYPERPLANES = 3;

class Vector {

    constructor(values) {

        this.values = values;
    }
}

function dotProduct(
    a,
    b
) {

    let result = 0.0;

    for (
        let i = 0;
        i < DIMENSIONS;
        i++
    ) {

        result +=
            a.values[i]
            * b.values[i];
    }

    return result;
}

function computeHash(
    point,
    hyperplanes
) {

    let hash = 0;

    for (
        let i = 0;
        i < HYPERPLANES;
        i++
    ) {

        if (
            dotProduct(
                point,
                hyperplanes[i]
            ) >= 0
        ) {

            hash |= (1 << i);
        }
    }

    return hash;
}

/* Driver */

const hyperplanes = [

    new Vector(
        [1,0,-1,0]
    ),

    new Vector(
        [0,1,0,-1]
    ),

    new Vector(
        [1,1,1,1]
    )
];

const point1 =
    new Vector(
        [2,3,1,0]
    );

const point2 =
    new Vector(
        [2,2,1,1]
    );

const hash1 =
    computeHash(
        point1,
        hyperplanes
    );

const hash2 =
    computeHash(
        point2,
        hyperplanes
    );

console.log(
    "Point1 Hash:",
    hash1
);

console.log(
    "Point2 Hash:",
    hash2
);

if (hash1 === hash2)
    console.log(
        "Likely Similar"
    );
else
    console.log(
        "Likely Different"
    );
