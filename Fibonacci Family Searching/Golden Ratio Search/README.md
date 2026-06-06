# ✨ Golden Ratio Search

> Golden Ratio Search is a searching and interval reduction technique that divides the search space according to the **Golden Ratio (φ ≈ 1.618)** instead of splitting equally like Binary Search.

It is widely associated with **optimization, interval narrowing, numerical analysis, and mathematically guided search strategies**.

---

# Table of Contents

* Introduction
* Definition
* Purpose
* Mathematical Foundation
* Core Idea
* Method
* Working Process
* Algorithm
* Example
* Complexity Analysis
* Applications / Uses
* Advantages
* Disadvantages
* Comparison with Other Searches
* Implementation Structure
* Interview Questions
* Conclusion

---

# Introduction

Searching algorithms traditionally reduce a problem into smaller parts.

Common approaches:

* Linear Search → sequential reduction
* Binary Search → equal division
* Fibonacci Search → Fibonacci intervals

Golden Ratio Search introduces a mathematical approach.

Instead of:

```text
50% | 50%
```

it partitions using:

```text
61.8% | 38.2%
```

This allows efficient interval reuse and fewer recalculations in repeated search operations.

---

# Definition

**Golden Ratio Search** is a search and optimization technique that reduces the search interval using the **Golden Ratio (φ)** to determine comparison points.

The algorithm repeatedly eliminates portions of the search space until the desired value or optimal interval is found.

General principle:

```text
Divide

↓

Compare

↓

Reduce

↓

Repeat
```

---

# Purpose

Golden Ratio Search was designed to:

* Reduce interval calculations
* Minimize unnecessary comparisons
* Reuse previously evaluated positions
* Improve efficiency in interval optimization
* Support mathematical search models

Main goal:

```text
Reduce Search Region
↓

Converge Efficiently
```

---

# Mathematical Foundation

The algorithm is built on the **Golden Ratio**.

Definition:

```text
φ = (1 + √5) / 2
```

Approximation:

```text
1.6180339887...
```

Inverse ratio:

```text
1 / φ ≈ 0.618
```

Relationship:

```text
61.8%
38.2%
```

These proportions naturally appear in interval reduction.

---

# Core Idea

Binary Search divides:

```text
50%
50%
```

Golden Ratio Search divides:

```text
61.8%
38.2%
```

This allows one comparison point to remain useful after interval reduction.

General visualization:

```text
|-----------|
      |
      φ
```

---

# Method

Golden Ratio Search follows these phases.

---

## Phase 1 — Initialize Interval

Select:

```text
left
right
```

Compute:

```text
x1
x2
```

using:

```text
0.618
```

---

## Phase 2 — Compare

Evaluate:

```text
f(x1)
f(x2)
```

---

## Phase 3 — Eliminate Region

Discard the interval that cannot contain the result.

---

## Phase 4 — Repeat

Continue until:

```text
Desired Precision
```

---

# Working Process

```text
Start

↓

Compute Ratio Points

↓

Compare

↓

Reduce Interval

↓

Reuse Previous Point

↓

Repeat

↓

Finish
```

---

# Algorithm

## Procedure

1. Select search interval.
2. Compute internal points.
3. Compare values.
4. Eliminate one side.
5. Repeat until convergence.

---

## Pseudocode

```text
GoldenRatioSearch(L,R):

phi=1.618

while interval > tolerance:

x1 =
R-(R-L)/phi

x2 =
L+(R-L)/phi

if f(x1)<f(x2):

L=x1

else:

R=x2

return result
```

---

# Example

Suppose:

```text
Interval

0 → 100
```

Compute:

```text
x1 = 38.2
x2 = 61.8
```

Compare:

```text
f(x1)
f(x2)
```

Reduce interval.

Repeat.

Final output:

```text
Optimal Point
```

---

# Visualization

```text
0----------------100

      x1

             x2

38.2       61.8
```

After reduction:

```text
38.2-----------100
```

Continue until convergence.

---

# Complexity Analysis

## Time Complexity

Each iteration reduces interval proportionally.

### Best Case

```text
O(1)
```

---

### Average Case

```text
O(log n)
```

---

### Worst Case

```text
O(log n)
```

---

## Space Complexity

```text
O(1)
```

---

# Complexity Summary

| Case    | Complexity |
| ------- | ---------- |
| Best    | O(1)       |
| Average | O(log n)   |
| Worst   | O(log n)   |
| Space   | O(1)       |

---

# Applications / Uses

## Numerical Optimization

Function minimization.

---

## Scientific Computing

Efficient interval reduction.

---

## Machine Learning

Hyperparameter optimization.

---

## Engineering

Design optimization.

---

## Data Analysis

Search refinement.

---

## Simulation Systems

Parameter tuning.

---

## Mathematical Modeling

Optimization workflows.

---

# Advantages

✅ Efficient interval reduction

✅ Reuses previous evaluations

✅ Constant memory usage

✅ Fewer recalculations

✅ Mathematically elegant approach

---

# Disadvantages

❌ More complex than Binary Search

❌ Requires interval assumptions

❌ Less common in standard searching

❌ Limited use for discrete datasets

❌ Not ideal for unsorted search problems

---

# Comparison with Other Algorithms

| Algorithm           | Division Strategy | Complexity |
| ------------------- | ----------------- | ---------- |
| Binary Search       | 50 / 50           | O(log n)   |
| Fibonacci Search    | Fibonacci Split   | O(log n)   |
| Golden Ratio Search | 61.8 / 38.2       | O(log n)   |

---

# Implementation Structure

```text
GoldenRatioSearch/

├── GoldenRatioSearch.c
├── GoldenRatioSearch.cpp
├── GoldenRatioSearch.java
├── GoldenRatioSearch.py
└── GoldenRatioSearch.js
```

---

# When To Use

Use Golden Ratio Search when:

* Solving optimization problems
* Reducing intervals repeatedly
* Minimizing recalculations
* Working with continuous domains

Avoid when:

* Searching unsorted data
* Exact index lookup is required
* Simpler methods are sufficient

---

# Interview Questions

### Why is it called Golden Ratio Search?

Because interval reduction uses the Golden Ratio.

---

### Is it better than Binary Search?

Depends on the problem type.

---

### Is it used for optimization?

Yes.

---

### Does it require sorting?

Not necessarily—commonly used for interval optimization.

---

# Conclusion

Golden Ratio Search demonstrates how mathematical proportions can guide efficient search behavior.

Core principle:

```text
Golden Ratio
↓

Interval Reduction

↓

Convergence
```

It is especially valuable in **optimization, scientific computing, and numerical search techniques**.

---

# License

MIT License

---

⭐ Star this repository if it helped your DSA learning journey.
