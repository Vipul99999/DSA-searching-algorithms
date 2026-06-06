#include <iostream>
#include <cmath>
using namespace std;

double objective(
        double x
) {
    return
    (x - 3) *
    (x - 3) + 5;
}

double goldenRatioSearch(
        double left,
        double right,
        double tolerance
) {

    const double phi =
    (1 + sqrt(5.0)) / 2;

    double x1 =
    right -
    (right - left) / phi;

    double x2 =
    left +
    (right - left) / phi;

    while (
    fabs(
        right - left
    ) > tolerance
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
            (right-left)/phi;

        } else {

            left = x1;

            x1 = x2;

            x2 =
            left +
            (right-left)/phi;
        }
    }

    return
    (left + right) / 2;
}

int main() {

    double result =
    goldenRatioSearch(
        -10,
        10,
        0.0001
    );

    cout
    << "Minimum near "
    << result
    << endl;

    return 0;
}
