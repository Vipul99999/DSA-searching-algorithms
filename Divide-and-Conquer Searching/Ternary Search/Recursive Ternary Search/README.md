# Recursive Ternary Search

## Overview

Recursive Ternary Search is a divide-and-conquer searching algorithm used to locate a target element in a **sorted array**. It repeatedly divides the search space into **three nearly equal parts** and recursively searches the relevant section until the target is found or the search range becomes empty.

Unlike Iterative Ternary Search, this implementation uses recursion, making the code concise and mathematically elegant.

---

## Prerequisites

* The array must be sorted in ascending or descending order.
* Random access to elements should be available.
* Suitable for static datasets where searching operations are frequent.

---

## How It Works

Given a sorted array:

1. Calculate two middle positions:

   * `mid1 = left + (right - left) / 3`
   * `mid2 = right - (right - left) / 3`

2. Compare the target with:

   * `arr[mid1]`
   * `arr[mid2]`

3. Cases:

   * If target equals `arr[mid1]`, return `mid1`.
   * If target equals `arr[mid2]`, return `mid2`.
   * If target is smaller than `arr[mid1]`, recursively search the left third.
   * If target is greater than `arr[mid2]`, recursively search the right third.
   * Otherwise, recursively search the middle third.

4. Continue until:

   * Target is found.
   * Search interval becomes invalid (`left > right`).

---

## Algorithm

```text
RecursiveTernarySearch(arr, left, right, target):

    if left > right:
        return -1

    mid1 = left + (right - left) / 3
    mid2 = right - (right - left) / 3

    if arr[mid1] == target:
        return mid1

    if arr[mid2] == target:
        return mid2

    if target < arr[mid1]:
        return RecursiveTernarySearch(
            arr,
            left,
            mid1 - 1,
            target
        )

    else if target > arr[mid2]:
        return RecursiveTernarySearch(
            arr,
            mid2 + 1,
            right,
            target
        )

    else:
        return RecursiveTernarySearch(
            arr,
            mid1 + 1,
            mid2 - 1,
            target
        )
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

### Recursive Call 1

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

---

### Recursive Call 2

```text
mid1 = 3 → arr[3] = 20
mid2 = 5 → arr[5] = 30
```

Target found at:

```text
index = 5
```

---

## Recursion Tree Illustration

```text
                [0..8]
               /  |  \
              /   |   \
             /    |    \
         Left  Middle Right

Target = 30

                [0..8]
                    |
                [3..5]
                    |
                 Found
```

---

## Complexity Analysis

### Time Complexity

| Case         | Complexity |
| ------------ | ---------- |
| Best Case    | O(1)       |
| Average Case | O(log₃ n)  |
| Worst Case   | O(log₃ n)  |

---

### Space Complexity

| Component       | Complexity |
| --------------- | ---------- |
| Recursive Stack | O(log₃ n)  |

Total:

```text
O(log₃ n)
```

---

## Advantages

* Elegant recursive implementation.
* Demonstrates divide-and-conquer principles.
* Easy to understand mathematically.
* Useful for educational purposes and algorithm analysis.

---

## Disadvantages

* Requires a sorted array.
* Uses recursive stack memory.
* More comparisons per step than Binary Search.
* Generally slower than Binary Search in practical systems.

---

## Binary Search vs Recursive Ternary Search

| Feature               | Binary Search | Recursive Ternary Search |
| --------------------- | ------------- | ------------------------ |
| Divisions             | 2             | 3                        |
| Midpoints Checked     | 1             | 2                        |
| Time Complexity       | O(log₂ n)     | O(log₃ n)                |
| Comparisons per Step  | Fewer         | More                     |
| Recursive Stack       | O(log₂ n)     | O(log₃ n)                |
| Practical Performance | Faster        | Usually Slower           |

---

## Applications

* Searching in sorted arrays.
* Educational demonstrations of recursion.
* Divide-and-conquer algorithm studies.
* Competitive programming.
* Mathematical optimization concepts (with modifications).

---

## When to Use

Use Recursive Ternary Search when:

* Learning recursive divide-and-conquer algorithms.
* Studying search algorithm variations.
* Implementing educational or academic projects.

For production systems, Binary Search is typically preferred due to its lower comparison overhead and better practical performance.

---

## Conclusion

Recursive Ternary Search is a logarithmic-time searching algorithm that repeatedly divides a sorted array into three sections and recursively searches the appropriate segment. While its theoretical efficiency is excellent, Binary Search often outperforms it in real-world applications because it requires fewer comparisons. Nevertheless, Recursive Ternary Search remains an important algorithm for understanding recursion, divide-and-conquer strategies, and advanced searching techniques.
