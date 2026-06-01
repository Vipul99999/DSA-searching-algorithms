def can_complete(speed, piles, hours):
    total_hours = 0

    for pile in piles:
        total_hours += (pile + speed - 1) // speed

        if total_hours > hours:
            return False

    return True


def binary_search_on_answer(piles, hours):
    left = 1
    right = max(piles)

    answer = right

    while left <= right:
        mid = left + (right - left) // 2

        if can_complete(mid, piles, hours):
            answer = mid
            right = mid - 1
        else:
            left = mid + 1

    return answer


if __name__ == "__main__":
    piles = [3, 6, 7, 11]
    hours = 8

    print(
        "Minimum Speed:",
        binary_search_on_answer(
            piles,
            hours
        )
    )
