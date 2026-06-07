#include <iostream>
#include <vector>

constexpr int DIMENSIONS = 4;
constexpr int HYPERPLANES = 3;

struct Vector {

    std::vector<double> values;

    Vector(
        std::initializer_list<double> v
    )
        : values(v) {}
};

double dotProduct(
    const Vector& a,
    const Vector& b
) {

    double result = 0.0;

    for (
        int i = 0;
        i < DIMENSIONS;
        i++
    ) {

        result +=
            a.values[i]
            * b.values[i];
    }

    return result;
}

int computeHash(
    const Vector& point,
    const std::vector<Vector>& planes
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

    std::vector<Vector>
    hyperplanes = {

        {1, 0, -1, 0},
        {0, 1, 0, -1},
        {1, 1, 1, 1}
    };

    Vector point1{
        2,3,1,0
    };

    Vector point2{
        2,2,1,1
    };

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

    std::cout
        << "Point1 Hash: "
        << hash1
        << '\n';

    std::cout
        << "Point2 Hash: "
        << hash2
        << '\n';

    if (hash1 == hash2)
        std::cout
            << "Likely Similar\n";
    else
        std::cout
            << "Likely Different\n";

    return 0;
}
