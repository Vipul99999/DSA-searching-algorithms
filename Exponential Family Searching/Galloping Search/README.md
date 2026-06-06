# 🏇 Galloping Search

> Galloping Search (also called **Exponential Galloping Search**) is an efficient searching technique that rapidly expands the search interval using exponentially increasing jumps and then performs **Binary Search** within the identified range.

It is commonly used in **merge operations, sorting systems, search optimization, and large sorted datasets**.

---

# Table of Contents

* Introduction
* Definition
* Purpose
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
* Conclusion

---

# Introduction

Searching large datasets efficiently is one of the most important problems in computer science.

Traditional methods:

* Linear Search → scans one by one
* Binary Search → requires known boundaries

Galloping Search improves efficiency by:

```text
Jumping quickly
↓

Finding range
↓

Performing Binary Search
```

This makes it highly effective when the target is expected to appear relatively close to the current position.

---

# Definition

**Galloping Search** is a searching algorithm that increases the search position exponentially until the search value is exceeded, then performs Binary Search inside the discovered interval.

The term **galloping** comes from the idea of taking increasingly larger jumps.

Example:

```text
1
2
4
8
16
32
64
```

Then:

```text
Binary Search
```

---

# Purpose

Galloping Search was developed to:

* Reduce unnecessary comparisons
* Improve searching speed
* Discover search ranges quickly
* Optimize merging operations
* Handle large sorted collections

Instead of checking:

```text
1
2
3
4
5
6
```

Galloping performs:

```text
1
2
4
8
16
32
```

which significantly reduces operations.

---

# Core Idea

Galloping Search combines:

```text
Exponential Expansion
+
Binary Search
```

Two phases:

---

## Phase 1 — Galloping Expansion

Jump exponentially:

```text
1
2
4
8
16
32
```

Stop when:

```text
A[i] ≥ Target
```

---

## Phase 2 — Binary Refinement

Search inside:

```text
(i/2 , i)
```

using Binary Search.

---

# Method

Galloping Search follows these steps.

---

## Step 1

Check starting position.

---

## Step 2

Increase search interval exponentially.

```text
index *= 2
```

---

## Step 3

Stop once target boundary is exceeded.

---

## Step 4

Perform Binary Search.

---

# Working Process

```text
Start

↓

Read Element

↓

Gallop Forward

1
2
4
8
16

↓

Range Found

↓

Binary Search

↓

Target Located
```

---

# Algorithm

## Procedure

1. Start from index 1.
2. Compare current value.
3. Double index repeatedly.
4. Identify candidate interval.
5. Apply Binary Search.

---

## Pseudocode

```text
GallopingSearch(A,target):

if A[0]==target:
    return 0

index=1

while index<n
and A[index]<target:

    index*=2

return BinarySearch(
A,
index/2,
min(index,n-1),
target
)
```

---

# Example

Input:

```text
Array:

[5,10,15,20,25,30,35,40,45,50]

Target = 35
```

---

## Galloping Phase

```text
Index 1 → 10
Index 2 → 15
Index 4 → 25
Index 8 → 45
```

Range discovered:

```text
4 → 8
```

---

## Binary Search

Search:

```text
[25,30,35,40,45]
```

Result:

```text
Target Found
Index = 6
```

---

# Visualization

```text
Array

[5][10][15][20][25][30][35][40][45]

Gallop

 ↑
   ↑
       ↑
              ↑

Binary Search

[25][30][35][40][45]
```

---

# Complexity Analysis

## Time Complexity

### Best Case

```text
O(1)
```

Target found immediately.

---

### Average Case

```text
O(log k)
```

where:

```text
k = distance to target
```

---

### Worst Case

```text
O(log n)
```

Full expansion plus Binary Search.

---

## Space Complexity

```text
O(1)
```

No additional memory.

---

# Complexity Summary

| Case    | Complexity |
| ------- | ---------- |
| Best    | O(1)       |
| Average | O(log k)   |
| Worst   | O(log n)   |
| Space   | O(1)       |

---

# Applications / Uses

## TimSort

Galloping mode is heavily used during merge optimization.

---

## Merge Algorithms

Reduce repeated comparisons.

---

## Database Indexing

Fast record lookup.

---

## Search Engines

Rapid index discovery.

---

## Distributed Systems

Locate partitions efficiently.

---

## Information Retrieval

Search sorted structures.

---

## Large Data Processing

Efficient range detection.

---

# Advantages

✅ Faster than Linear Search

✅ Efficient on large sorted datasets

✅ Excellent for merge optimization

✅ Reduces comparison operations

✅ Constant memory usage

✅ Performs well when target is nearby

---

# Disadvantages

❌ Requires sorted data

❌ Random access required

❌ Additional expansion overhead

❌ Not ideal for small arrays

❌ More complex than standard Binary Search

---

# Comparison with Other Searching Algorithms

| Algorithm          | Sorted | Unknown Size | Average  |
| ------------------ | ------ | ------------ | -------- |
| Linear Search      | No     | Yes          | O(n)     |
| Binary Search      | Yes    | No           | O(log n) |
| Exponential Search | Yes    | Yes          | O(log n) |
| Galloping Search   | Yes    | Yes          | O(log k) |

---

# Implementation Structure

```text
GallopingSearch/

├── GallopingSearch.c
├── GallopingSearch.cpp
├── GallopingSearch.java
├── GallopingSearch.py
└── GallopingSearch.js
```

---

# When To Use

Use Galloping Search when:

* Data is sorted
* Searching near previous position
* Merge optimization is needed
* Dataset is large

Avoid when:

* Data is unsorted
* Dataset is very small
* Random access is unavailable

---

# Interview Questions

### Why is it called Galloping Search?

Because search intervals increase rapidly like galloping movement.

---

### Where is Galloping Search used?

TimSort and merge optimization.

---

### What happens after expansion?

Binary Search executes.

---

### Does Galloping Search support infinite arrays?

Yes.

---

# Conclusion

Galloping Search accelerates searching by combining:

```text
Fast Expansion
↓

Range Detection

↓

Binary Search
```

Its ability to minimize comparisons makes it useful in **sorting systems, merging algorithms, and large-scale search applications**.

---

# License

MIT License

---

⭐ Star this repository if it helped your DSA learning journey.
