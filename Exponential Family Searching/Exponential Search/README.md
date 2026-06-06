# 🔍 Exponential Search

> Exponential Search is an efficient searching algorithm for **sorted arrays**, especially useful when the search space is **large or its size is unknown**. It works by rapidly expanding the search range exponentially and then applying **Binary Search** to locate the target element.

---

# Table of Contents

* Introduction
* What is Exponential Search
* Why Use Exponential Search
* Core Idea
* Algorithm Workflow
* Step-by-Step Example
* Mathematical Analysis
* Complexity Analysis
* Dry Run
* Visualization
* Pseudocode
* Advantages
* Limitations
* Comparison with Other Searches
* Real-World Applications
* Implementations
* Interview Questions
* Conclusion

---

# Introduction

Searching is one of the most common operations in computer science.

Traditional searching methods include:

* Linear Search
* Binary Search
* Jump Search

Among them, Binary Search performs efficiently but requires:

* Sorted data
* Known search boundaries

Exponential Search extends Binary Search by discovering boundaries dynamically.

---

# What is Exponential Search

Exponential Search is a searching technique that:

1. Starts from a small index.
2. Expands the search interval exponentially.
3. Finds a probable range containing the target.
4. Uses Binary Search inside that range.

Instead of searching entire data:

```text
Search → Expand → Narrow → Locate
```

---

# Why Use Exponential Search

Suppose:

```text
Array Size = Unknown
Target = 450
```

Binary Search cannot start because:

```text
left = 0
right = ?
```

Exponential Search solves this.

Range discovery:

```text
1 → 2 → 4 → 8 → 16 → 32 → 64
```

After locating the range:

```text
Binary Search
```

---

# Core Idea

The algorithm works in two phases.

## Phase 1 — Exponential Expansion

Double the search index repeatedly.

```text
1
2
4
8
16
32
64
...
```

Stop when:

```text
A[i] ≥ Target
```

---

## Phase 2 — Binary Search

Search inside:

```text
A[i/2] → A[i]
```

This dramatically reduces comparisons.

---

# Algorithm Workflow

```text
Start

Check First Element

↓

Expand Range

1
2
4
8
16
32

↓

Range Found

↓

Apply Binary Search

↓

Target Found
```

---

# Step-by-Step Example

Given:

```text
Array:

[2, 4, 8, 15, 23, 30, 40, 55, 70, 90]

Target = 40
```

---

## Expansion Stage

```text
Index 1 → 4
Index 2 → 8
Index 4 → 23
Index 8 → 70
```

Target lies between:

```text
Index 4 → Index 8
```

---

## Binary Search Stage

Search:

```text
[23,30,40,55,70]
```

Result:

```text
Target Found
Index = 6
```

---

# Mathematical Analysis

Exponential growth:

```text
2^0
2^1
2^2
2^3
...
2^k
```

Stop condition:

```text
2^k ≥ n
```

Taking log:

```text
k = log₂(n)
```

Expansion:

```text
O(log n)
```

Binary Search:

```text
O(log n)
```

Overall:

```text
O(log n)
```

---

# Complexity Analysis

| Case             | Complexity |
| ---------------- | ---------- |
| Best Case        | O(1)       |
| Average Case     | O(log n)   |
| Worst Case       | O(log n)   |
| Space Complexity | O(1)       |

---

# Dry Run

Input:

```text
Array:
[5 10 15 20 25 30 35 40]

Target = 30
```

Expansion:

```text
1 → 2 → 4 → 8
```

Range:

```text
4–8
```

Binary Search:

```text
Mid = 6
```

Result:

```text
Found
```

---

# Visualization

```text
Array

[2][4][8][15][23][30][40][55][70]

Jump:

 1
    2
       4
           8

Binary Search

[23][30][40][55]
```

---

# Pseudocode

```text
ExponentialSearch(arr,target):

if arr[0]==target:
    return 0

i=1

while i<n AND arr[i]<=target:
    i=i*2

return BinarySearch(
    arr,
    i/2,
    min(i,n-1),
    target
)
```

---

# Advantages

✅ Faster than Linear Search
✅ Works with unknown sizes
✅ Efficient for huge datasets
✅ Low memory usage
✅ Easy to implement

---

# Limitations

❌ Requires sorted data
❌ Additional range discovery cost
❌ Less efficient for very small arrays

---

# Comparison with Other Algorithms

| Algorithm          | Sorted | Unknown Size | Complexity |
| ------------------ | ------ | ------------ | ---------- |
| Linear Search      | No     | Yes          | O(n)       |
| Binary Search      | Yes    | No           | O(log n)   |
| Jump Search        | Yes    | No           | O(√n)      |
| Exponential Search | Yes    | Yes          | O(log n)   |

---

# Real-World Applications

## Search Engines

Fast index discovery.

## Databases

Large block searching.

## Distributed Systems

Locate data partitions.

## Memory Allocation

Dynamic memory lookup.

## AI Retrieval Systems

Efficient vector indexing.

## Infinite Streams

Unknown-size searching.

---

# Implementations

```text
ExponentialSearch/

├── ExponentialSearch.c
├── ExponentialSearch.cpp
├── ExponentialSearch.java
├── ExponentialSearch.py
└── ExponentialSearch.js
```

---

# Interview Questions

### Why use Exponential Search instead of Binary Search?

Because Binary Search requires known boundaries.

---

### Does Exponential Search require sorting?

Yes.

---

### Can Exponential Search work on infinite arrays?

Yes.

---

### What happens after expansion?

Binary Search executes.

---

# Conclusion

Exponential Search combines:

```text
Exponential Expansion
+
Binary Search
```

This allows efficient searching even when boundaries are unknown.

It is one of the most practical algorithms for modern large-scale searching systems.

---

# License

MIT License

---

⭐ Star this repository if it helped your learning.
