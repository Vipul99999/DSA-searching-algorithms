# 🌀 Fibonacci Family Searching

> A collection of searching algorithms based on **Fibonacci progression and proportional interval partitioning** for efficient searching in sorted datasets.

This family focuses on reducing search space using mathematical sequences instead of traditional midpoint division.

---

# Table of Contents

* Introduction
* What is Fibonacci Family Searching
* Motivation
* Mathematical Foundation
* Family Members
* Fibonacci Search
* Golden Ratio Search
* Comparison
* Complexity Analysis
* Applications
* Advantages
* Limitations
* Repository Structure
* Learning Outcomes
* References

---

# Introduction

Searching algorithms are fundamental to computer science.

Traditional methods:

* Linear Search → sequential comparison
* Binary Search → midpoint division

Fibonacci-based searching introduces a different strategy.

Instead of dividing equally:

```text
50% | 50%
```

these algorithms divide using mathematical ratios:

```text
61.8% | 38.2%
```

or

```text
Fibonacci(n−1)
Fibonacci(n−2)
```

This can reduce computation overhead in certain environments.

---

# What is Fibonacci Family Searching

Fibonacci Family Searching refers to algorithms that search by progressively reducing the search interval using:

* Fibonacci Numbers
* Golden Ratio (φ)

The search space shrinks without requiring exact midpoint calculations.

General workflow:

```text
Estimate Interval
↓

Compare

↓

Reduce Interval

↓

Repeat
```

---

# Motivation

This family exists to address cases where:

* Division operations are expensive
* Memory access patterns matter
* Sequential access is preferred
* Sorted arrays dominate

Typical environments:

* Embedded systems
* Low-level hardware
* Storage optimization
* Numerical optimization

---

# Mathematical Foundation

## Fibonacci Sequence

```text
0
1
1
2
3
5
8
13
21
34
55
...
```

Formula:

```text
F(n)=F(n−1)+F(n−2)
```

---

## Golden Ratio

Defined as:

```text
φ = (1 + √5)/2
```

Approximation:

```text
φ ≈ 1.618
```

Relation:

```text
F(n+1)/F(n) → φ
```

---

# Family Members

```text
Fibonacci Family Searching
│
├── Fibonacci Search
└── Golden Ratio Search
```

---

# 1. Fibonacci Search

## Definition

Fibonacci Search locates an element in a sorted array using Fibonacci numbers to determine comparison positions.

Unlike Binary Search:

```text
Middle = (L+R)/2
```

Fibonacci Search computes:

```text
Offset + Fibonacci(k−2)
```

---

## Characteristics

* Uses Fibonacci numbers
* Works on sorted data
* Eliminates repeated division
* Efficient memory access

---

## Complexity

| Metric  | Complexity |
| ------- | ---------- |
| Best    | O(1)       |
| Average | O(log n)   |
| Worst   | O(log n)   |
| Space   | O(1)       |

---

## Example

```text
Array

[10 20 30 40 50 60 70]

Target = 50
```

Search:

```text
34 → 21 → 13 → Locate
```

---

# 2. Golden Ratio Search

## Definition

Golden Ratio Search divides the search interval according to the golden ratio.

Partition:

```text
61.8%
38.2%
```

instead of:

```text
50%
50%
```

This minimizes recalculation in repeated interval reductions.

---

## Characteristics

* Ratio-based searching
* Efficient interval reuse
* Mathematical optimization

---

## Complexity

| Metric  | Complexity |
| ------- | ---------- |
| Best    | O(1)       |
| Average | O(log n)   |
| Worst   | O(log n)   |

---

## Example

```text
Search Interval

0----------------100

Split

61.8

38.2
```

---

# Complexity Comparison

| Algorithm           | Average  | Worst    | Space |
| ------------------- | -------- | -------- | ----- |
| Binary Search       | O(log n) | O(log n) | O(1)  |
| Fibonacci Search    | O(log n) | O(log n) | O(1)  |
| Golden Ratio Search | O(log n) | O(log n) | O(1)  |

---

# Applications

## Databases

Efficient indexed retrieval.

---

## Embedded Systems

Lower arithmetic cost.

---

## Search Engines

Large sorted indexes.

---

## Numerical Optimization

Interval minimization.

---

## Memory-Constrained Systems

Reduced computation overhead.

---

## Scientific Computing

Optimization workflows.

---

# Advantages

✅ Reduced arithmetic complexity

✅ Efficient interval reduction

✅ Constant memory usage

✅ Suitable for sorted collections

✅ Mathematical optimization

---

# Limitations

❌ Requires sorted data

❌ Less common than Binary Search

❌ More difficult implementation

❌ Limited practical advantage on modern CPUs

---

# Repository Structure

```text
Fibonacci-Family-Searching/

README.md

FibonacciSearch/
│
├── FibonacciSearch.c
├── FibonacciSearch.cpp
├── FibonacciSearch.java
├── FibonacciSearch.py
└── FibonacciSearch.js

GoldenRatioSearch/
│
├── GoldenRatioSearch.c
├── GoldenRatioSearch.cpp
├── GoldenRatioSearch.java
├── GoldenRatioSearch.py
└── GoldenRatioSearch.js
```

---

# Learning Outcomes

After completing this repository, users will understand:

* Fibonacci interval reduction
* Golden ratio partitioning
* Search optimization techniques
* Complexity trade-offs
* Mathematical searching models

---

# References

* Fibonacci Sequence
* Golden Ratio
* Search Algorithm Design
* Numerical Optimization

---

# Conclusion

Fibonacci Family Searching demonstrates how mathematical sequences can guide efficient search behavior.

Core principle:

```text
Mathematics
↓

Interval Reduction

↓

Efficient Search
```

These algorithms provide alternative approaches to traditional Binary Search.

---

# License

MIT License

---

⭐ Star this repository if it improved your understanding of mathematical searching algorithms.
