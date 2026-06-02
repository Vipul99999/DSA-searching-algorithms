#include <stdio.h>
#include <math.h>

double f(double x) {
    return -(x - 5) * (x - 5) + 25;
}

double unimodalSearch(double left, double right, double eps) {
    while (right - left > eps) {
        double mid1 = left + (right - left) / 3.0;
        double mid2 = right - (right - left) / 3.0;

        if (f(mid1) < f(mid2))
            left = mid1;
        else
            right = mid2;
    }

    return (left + right) / 2.0;
}

int main() {
    double x = unimodalSearch(0.0, 10.0, 1e-6);

    printf("Maximum at x = %.6f\n", x);
    printf("Maximum value = %.6f\n", f(x));

    return 0;
}
