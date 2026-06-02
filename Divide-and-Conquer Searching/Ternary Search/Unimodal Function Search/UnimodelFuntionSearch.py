def f(x):
    return -(x - 5) ** 2 + 25


def unimodal_search(left, right, eps):
    while right - left > eps:
        mid1 = left + (right - left) / 3
        mid2 = right - (right - left) / 3

        if f(mid1) < f(mid2):
            left = mid1
        else:
            right = mid2

    return (left + right) / 2


x = unimodal_search(0.0, 10.0, 1e-6)

print(f"Maximum at x = {x:.6f}")
print(f"Maximum value = {f(x):.6f}")
