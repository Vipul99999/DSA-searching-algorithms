# 🔍 Doubling Search

> Doubling Search is an efficient searching algorithm used to locate an element in a **sorted collection** by expanding the search interval exponentially and then applying **Binary Search** within the discovered range.

It is particularly useful when the **upper bound of the search space is unknown or very large**.

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

Searching is one of the most important operations in computer science.

Traditional searching methods work well under certain conditions:

* Linear Search → no ordering required
* Binary Search → requires known boundaries

However, many modern systems operate on:

* Dynamic arrays
* Unknown-size collections
* Infinite streams
* Distributed datasets

Doubling Search addresses these problems efficiently.

---

# Definition

**Doubling Search** is a searching technique that repeatedly **doubles the search index (or search interval)** until the target value is expected to lie inside a discovered range.

After identifying the candidate interval, **Binary Search** is applied to locate the exact position.

---

# Purpose

The primary purpose of Doubling Search is to:

* Discover search boundaries efficiently
* Reduce unnecessary comparisons
* Enable searching in unknown-sized collections
* Improve performance over Linear Search
* Support scalable searching in large datasets

Instead of checking every element:

```text
Search Entire Array
```

Doubling Search performs:

```text
Expand → Detect Range → Binary Search
```

---

# Core Idea

The algorithm expands search positions exponentially.

Example:

```text
1
2
4
8
16
32
64
128
```

Stop when:

```text
A[i] ≥ target
```

Then:

```text
Binary Search
```

inside:

```text
(i/2 , i)
```

---

# Method

Doubling Search works in two major phases.

---

## Phase 1 — Range Expansion

Start from a small position.

Repeatedly multiply index by 2.

Example:

```text
1 → 2 → 4 → 8 → 16
```

Continue until:

```text
Target ≤ Current Value
```

---

## Phase 2 — Binary Search

Once range is identified:

```text
Left = Previous Index
Right = Current Index
```

Perform:

```text
Binary Search
```

---

# Working Process

```text
Start

↓

Check First Element

↓

Double Search Interval

↓

Locate Candidate Range

↓

Apply Binary Search

↓

Return Result
```

---

# Algorithm

## Step 1

If first element equals target:

```text
return index
```

---

## Step 2

Initialize:

```text
index = 1
```

---

## Step 3

Expand range:

```text
while index < n
and A[index] <= target

index *= 2
```

---

## Step 4

Apply Binary Search:

```text
BinarySearch(
A,
index/2,
min(index,n−1)
)
```

---

## Pseudocode

```text
DoublingSearch(A,target):

if A[0]==target:
    return 0

index=1

while index<n
and A[index]<=target:

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

Given:

```text
Array:

[5,10,15,20,25,30,35,40,45,50]

Target = 35
```

---

## Expansion

```text
Index 1 → 10
Index 2 → 15
Index 4 → 25
Index 8 → 45
```

Range:

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
O(log n)
```

Range expansion plus Binary Search.

---

### Worst Case

```text
O(log n)
```

Full expansion and search.

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
| Average | O(log n)   |
| Worst   | O(log n)   |
| Space   | O(1)       |

---

# Applications / Uses

## Large Sorted Datasets

Efficient searching in huge collections.

---

## Unknown Size Arrays

Discover search boundaries dynamically.

---

## Database Systems

Fast record range discovery.

---

## Distributed Systems

Locate partitions efficiently.

---

## Search Engines

Rapid index lookup.

---

## Streaming Platforms

Support incremental searching.

---

## Memory Management

Dynamic block discovery.

---

# Advantages

✅ Faster than Linear Search

✅ Efficient for huge datasets

✅ Handles unknown boundaries

✅ Requires minimal memory

✅ Combines fast expansion with accurate search

✅ Easy implementation

---

# Disadvantages

❌ Requires sorted data

❌ Additional expansion phase

❌ Random access required

❌ Less beneficial for small datasets

❌ Slightly more complex than Binary Search

---

# Comparison with Other Searching Algorithms

| Algorithm       | Sorted | Unknown Size | Complexity |
| --------------- | ------ | ------------ | ---------- |
| Linear Search   | No     | Yes          | O(n)       |
| Binary Search   | Yes    | No           | O(log n)   |
| Jump Search     | Yes    | No           | O(√n)      |
| Doubling Search | Yes    | Yes          | O(log n)   |

---

# Implementation Structure

```text
DoublingSearch/

├── DoublingSearch.c
├── DoublingSearch.cpp
├── DoublingSearch.java
├── DoublingSearch.py
└── DoublingSearch.js
```

---

# When To Use

Use Doubling Search when:

* Data is sorted
* Dataset is large
* Upper bound is unknown
* Binary Search cannot directly start

Avoid when:

* Data is unsorted
* Dataset is very small

---

# Conclusion

Doubling Search extends Binary Search by introducing **exponential range discovery**.

Its strategy:

```text
Expand
↓

Discover Range

↓

Binary Search
```

makes it highly effective for searching in **large and dynamically bounded datasets**.

---

# License

MIT License

---

⭐ Star this repository if it helped your DSA learning.
