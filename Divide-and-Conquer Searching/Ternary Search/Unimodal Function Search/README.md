# Unimodal Function Search

## Overview

Unimodal Function Search is an optimization technique used to find the **maximum** or **minimum** value of a **unimodal function** within a given interval.

A unimodal function has exactly one peak (maximum) or one valley (minimum):

* Increasing then decreasing → Single Maximum
* Decreasing then increasing → Single Minimum

The algorithm repeatedly narrows the search interval by comparing function values at two interior points, eliminating the portion that cannot contain the optimum.

This technique is commonly implemented using **Ternary Search** on continuous or discrete domains.

---

## What is a Unimodal Function?

### Maximum Type

```text id="cm3x9d"
      Peak
       ▲
      / \
     /   \
    /     \
   /       \
  /         \
```

The function:

```text id="djqz4t"
Increasing → Maximum → Decreasing
```

Example:

```text id="eb0sba"
f(x) = -(x - 5)² + 25
```

Maximum occurs at:

```text id="zsvcs8"
x = 5
```

---

### Minimum Type

```text id="vtxv4k"
  \         /
   \       /
    \     /
     \   /
      \ /
       ▼
    Minimum
```

The function:

```text id="qt6hzh"
Decreasing → Minimum → Increasing
```

Example:

```text id="m6ix3d"
f(x) = (x - 5)²
```

Minimum occurs at:

```text id="39eh7n"
x = 5
```

---

## How It Works

Given interval:

```text id="nknv2n"
[left, right]
```

Choose two interior points:

```text id="u2hmly"
mid1 = left + (right - left) / 3
mid2 = right - (right - left) / 3
```

For a maximum search:

* If `f(mid1) < f(mid2)`

  * Optimum lies in the right portion.
  * Move left boundary.

* Otherwise

  * Optimum lies in the left portion.
  * Move right boundary.

For a minimum search:

* Reverse the comparison.

Repeat until the interval becomes sufficiently small.

---

## Algorithm (Maximum Search)

```text id="jlfdsh"
while (right - left > precision):

    mid1 = left + (right - left) / 3
    mid2 = right - (right - left) / 3

    if f(mid1) < f(mid2):
        left = mid1
    else:
        right = mid2

return (left + right) / 2
```

---

## Example

Find the maximum of:

```text id="b56r2f"
f(x) = -(x - 5)² + 25
```

Search range:

```text id="gvrlvf"
[0, 10]
```

### Iteration 1

```text id="d10xmb"
mid1 = 3.33
mid2 = 6.67
```

Evaluate:

```text id="l7l6el"
f(3.33) ≈ 22.22
f(6.67) ≈ 22.22
```

Search continues around the center.

---

### Later Iterations

The interval shrinks:

```text id="2w6c92"
[4, 6]
→ [4.5, 5.5]
→ [4.9, 5.1]
→ ...
```

Eventually:

```text id="4o6a04"
x ≈ 5
```

Maximum value:

```text id="6yig2r"
f(5) = 25
```

---

## Geometric Interpretation

At every iteration:

```text id="k7g3ih"
left     mid1   mid2    right
 |---------|-----|---------|
```

One-third of the interval is discarded.

The search region continuously converges toward the optimum point.

---

## Complexity Analysis

### Continuous Domain

| Metric            | Complexity       |
| ----------------- | ---------------- |
| Time              | O(log₃((R-L)/ε)) |
| Space (Iterative) | O(1)             |
| Space (Recursive) | O(log₃((R-L)/ε)) |

Where:

* `R` = right boundary
* `L` = left boundary
* `ε` = desired precision

---

### Discrete Domain

For integer ranges:

| Metric | Complexity |
| ------ | ---------- |
| Time   | O(log₃ n)  |
| Space  | O(1)       |

---

## Advantages

* Efficient for optimization problems.
* Does not require derivatives.
* Works for both maximum and minimum searches.
* Easy to implement.
* Applicable to continuous and discrete domains.

---

## Disadvantages

* Requires the function to be unimodal.
* Slower than some derivative-based optimization methods.
* Incorrect results if multiple local optima exist.

---

## Applications

### Competitive Programming

Common problems:

```text id="u3m9eu"
Maximum profit
Minimum cost
Optimal distance
Best position
```

---

### Machine Learning

Used for:

```text id="8iuzd4"
Hyperparameter tuning
Objective optimization
Loss minimization
```

---

### Engineering

Applications include:

```text id="jpj8ul"
Structural optimization
Control systems
Signal processing
```

---

### Economics

Optimization of:

```text id="g7u5db"
Revenue
Profit
Production cost
Resource allocation
```

---

## Binary Search vs Unimodal Function Search

| Feature          | Binary Search      | Unimodal Function Search |
| ---------------- | ------------------ | ------------------------ |
| Goal             | Find Value         | Find Optimum             |
| Data Requirement | Sorted Data        | Unimodal Function        |
| Comparisons      | Elements           | Function Values          |
| Output           | Position of Target | Maximum/Minimum Point    |
| Time Complexity  | O(log n)           | O(log₃ n)                |

---

## When to Use

Use Unimodal Function Search when:

* The function has a single optimum.
* Derivatives are unavailable or expensive.
* High-precision optimization is required.
* Solving competitive programming optimization problems.

Avoid using it when:

* Multiple local maxima/minima exist.
* The function is highly irregular or non-unimodal.

---

## Conclusion

Unimodal Function Search is a powerful optimization technique for locating the maximum or minimum of a function that contains a single optimum point. By repeatedly evaluating two interior points and discarding regions that cannot contain the optimum, the algorithm efficiently converges to the best solution. It forms the foundation of ternary-search-based optimization and is widely used in mathematics, engineering, economics, machine learning, and competitive programming.
