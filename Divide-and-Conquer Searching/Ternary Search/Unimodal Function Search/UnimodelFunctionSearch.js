function f(x) {
    return -(x - 5) * (x - 5) + 25;
}

function unimodalSearch(left, right, eps) {
    while (right - left > eps) {
        const mid1 = left + (right - left) / 3;
        const mid2 = right - (right - left) / 3;

        if (f(mid1) < f(mid2))
            left = mid1;
        else
            right = mid2;
    }

    return (left + right) / 2;
}

const x = unimodalSearch(0.0, 10.0, 1e-6);

console.log(`Maximum at x = ${x.toFixed(6)}`);
console.log(`Maximum value = ${f(x).toFixed(6)}`);
