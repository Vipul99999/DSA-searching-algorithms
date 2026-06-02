# Iterative Ternary Search

## Overview

Iterative Ternary Search is a searching algorithm used to find a target element in a **sorted array**. It works by dividing the search range into **three nearly equal parts** and comparing the target with two middle elements.

Unlike Binary Search, which divides the array into two parts, Ternary Search divides it into three parts. The iterative version avoids recursion, making it more memory-efficient.

---

## How It Works

Given a sorted array:

1. Calculate two middle positions:

   * `mid1 = left + (right - left) / 3`
   * `mid2 = right - (right - left) / 3`

2. Compare the target with:

   * Element at `mid1`
   * Element at `mid2`

3. Cases:

   * If target equals `arr[mid1]`, return `mid1`.
   * If target equals `arr[mid2]`, return `mid2`.
   * If target is smaller than `arr[mid1]`, search the left third.
   * If target is greater than `arr[mid2]`, search the right third.
   * Otherwise, search the middle third.

4. Repeat until the target is found or the search space becomes empty.

---

## Algorithm

```text
IterativeTernarySearch(arr, target):
    left = 0
    right = length(arr) - 1

    while left <= right:
        mid1 = left + (right - left) / 3
        mid2 = right - (right - left) / 3

        if arr[mid1] == target:
            return mid1

        if arr[mid2] == target:
            return mid2

        if target < arr[mid1]:
            right = mid1 - 1

        else if target > arr[mid2]:
            left = mid2 + 1

        else:
            left = mid1 + 1
            right = mid2 - 1

    return -1
```

---

## Example

Array:

```text
[5, 10, 15, 20, 25, 30, 35, 40, 45]
```

Target:

```text
30
```

### Iteration 1

```text
left = 0
right = 8

mid1 = 2 → arr[2] = 15
mid2 = 6 → arr[6] = 35
```

Since:

```text
15 < 30 < 35
```

Search middle section:

```text
left = 3
right = 5
```

### Iteration 2

```text
mid1 = 3 → arr[3] = 20
mid2 = 5 → arr[5] = 30
```

Target found at index:

```text
5
```

---

## Complexity Analysis

| Case         | Time Complexity |
| ------------ | --------------- |
| Best Case    | O(1)            |
| Average Case | O(log₃ n)       |
| Worst Case   | O(log₃ n)       |

### Space Complexity

```text
O(1)
```

No recursion stack is used.

---

## Advantages

* Efficient for searching in sorted arrays.
* Uses constant extra memory.
* Avoids recursion overhead.
* Educational example of divide-and-conquer algorithms.

---

## Disadvantages

* Requires a sorted array.
* More comparisons per iteration than Binary Search.
* In practice, Binary Search is usually faster due to fewer comparisons.

---

## Binary Search vs Ternary Search

| Feature               | Binary Search  | Ternary Search |
| --------------------- | -------------- | -------------- |
| Divisions             | 2              | 3              |
| Mid Points            | 1              | 2              |
| Comparisons/Iteration | Fewer          | More           |
| Time Complexity       | O(log₂ n)      | O(log₃ n)      |
| Practical Performance | Usually Faster | Usually Slower |

---

## Applications

* Searching in sorted datasets.
* Competitive programming.
* Algorithm learning and analysis.
* Divide-and-conquer demonstrations.
* Numerical optimization variants (with modifications).

---

## Conclusion

Iterative Ternary Search is a divide-and-conquer searching algorithm that repeatedly splits a sorted array into three parts and narrows the search space based on two middle comparisons. Although its theoretical complexity is logarithmic, Binary Search is generally preferred in practical applications because it performs fewer comparisons per iteration. Nevertheless, Iterative Ternary Search remains an important algorithm for understanding alternative search strategies and divide-and-conquer techniques.
