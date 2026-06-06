# ♾️ Unbounded Binary Search

> Unbounded Binary Search is an advanced searching technique used to find an element in a **sorted collection whose upper boundary is unknown**. It first discovers a valid search interval using exponential expansion and then applies **Binary Search** inside the discovered range.

This algorithm is especially useful for **infinite arrays, unknown-size datasets, streaming systems, and dynamically expanding storage structures**.

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

Binary Search is one of the fastest searching algorithms.

However, Binary Search assumes:

```text id="a92ik3"
left boundary
+
right boundary
```

are already known.

Many real-world systems do not provide this information:

* Infinite arrays
* Streams
* Dynamic memory
* Unknown-size containers
* Large distributed storage

Unbounded Binary Search solves this limitation.

---

# Definition

**Unbounded Binary Search** is a searching algorithm that locates a target element in a **sorted structure with an unknown upper limit** by:

1. Discovering an upper bound through exponential growth.
2. Applying Binary Search inside the discovered interval.

Instead of:

```text id="ljl4j5"
Search Entire Dataset
```

it performs:

```text id="k66svh"
Discover Range
↓

Binary Search
```

---

# Purpose

The purpose of Unbounded Binary Search is to:

* Search efficiently when array size is unknown
* Avoid linear scanning
* Discover boundaries dynamically
* Support infinite or expanding datasets
* Preserve Binary Search efficiency

Without discovering boundaries:

```text id="lm6rfq"
Binary Search
cannot begin
```

This algorithm removes that limitation.

---

# Core Idea

Unbounded Binary Search operates in two stages.

---

## Stage 1 — Boundary Discovery

Increase index exponentially.

```text id="tdm3pn"
1
2
4
8
16
32
64
128
```

Continue until:

```text id="jlwmrj"
A[index] ≥ target
```

---

## Stage 2 — Binary Search

Search inside:

```text id="3p9i9j"
(index/2 , index)
```

---

# Method

The algorithm follows these steps.

---

## Step 1

Check first position.

---

## Step 2

Initialize:

```text id="s1d5cr"
index = 1
```

---

## Step 3

Expand search range.

```text id="c25n9m"
index *= 2
```

until:

```text id="y38gta"
Target ≤ Current Value
```

---

## Step 4

Apply Binary Search.

---

# Working Process

```text id="wglllv"
Start

↓

Read Element

↓

Expand Boundaries

1
2
4
8
16

↓

Locate Interval

↓

Binary Search

↓

Return Result
```

---

# Algorithm

## Procedure

1. Compare first element.
2. Double search index.
3. Continue until range is found.
4. Perform Binary Search.

---

## Pseudocode

```text id="tfbdkq"
UnboundedBinarySearch(
A,
target
):

if A[0]==target:
    return 0

index=1

while A[index]<target:

    index*=2

return BinarySearch(
A,
index/2,
index,
target
)
```

---

# Example

Input:

```text id="4wgc5j"
Array

[5,10,15,20,25,30,35,40,45,50]

Target = 35
```

---

## Boundary Discovery

```text id="fjlwmn"
Index 1 → 10
Index 2 → 15
Index 4 → 25
Index 8 → 45
```

Boundary found:

```text id="rsg9gt"
4 → 8
```

---

## Binary Search

Search interval:

```text id="jqd8jh"
[25,30,35,40,45]
```

Result:

```text id="s25u9l"
Target Found
Index = 6
```

---

# Visualization

```text id="h89jzw"
Infinite Array

[5][10][15][20][25][30][35][40]

Expand

 ↑
   ↑
      ↑
          ↑

Binary Search

[25][30][35][40]
```

---

# Complexity Analysis

Boundary discovery:

```text id="qolp3m"
O(log p)
```

where:

```text id="c7cg6m"
p = target position
```

Binary Search:

```text id="vkqu1n"
O(log p)
```

Total:

```text id="zzny94"
O(log p)
```

---

## Time Complexity

| Case    | Complexity |
| ------- | ---------- |
| Best    | O(1)       |
| Average | O(log p)   |
| Worst   | O(log p)   |

---

## Space Complexity

```text id="2gms6h"
O(1)
```

No additional storage.

---

# Applications / Uses

## Infinite Arrays

Search without known size.

---

## Streaming Systems

Locate elements dynamically.

---

## Search Engines

Efficient index expansion.

---

## Databases

Discover partitions quickly.

---

## Distributed Systems

Search across expanding nodes.

---

## Memory Managers

Locate dynamic blocks.

---

## Cloud Storage

Handle scalable datasets.

---

# Advantages

✅ Works with unknown-size arrays

✅ Efficient boundary discovery

✅ Preserves Binary Search performance

✅ Constant memory usage

✅ Scales to huge datasets

✅ Suitable for streaming systems

---

# Disadvantages

❌ Requires sorted data

❌ Random access required

❌ Additional boundary discovery phase

❌ More complex than Binary Search

❌ Not useful for small arrays

---

# Comparison with Other Searching Algorithms

| Algorithm               | Sorted | Unknown Size | Complexity |
| ----------------------- | ------ | ------------ | ---------- |
| Linear Search           | No     | Yes          | O(n)       |
| Binary Search           | Yes    | No           | O(log n)   |
| Exponential Search      | Yes    | Yes          | O(log n)   |
| Unbounded Binary Search | Yes    | Yes          | O(log p)   |

---

# Implementation Structure

```text id="7pohcz"
UnboundedBinarySearch/

├── UnboundedBinarySearch.c
├── UnboundedBinarySearch.cpp
├── UnboundedBinarySearch.java
├── UnboundedBinarySearch.py
└── UnboundedBinarySearch.js
```

---

# When To Use

Use Unbounded Binary Search when:

* Dataset is sorted
* Upper bound is unknown
* Data grows dynamically
* Infinite arrays are modeled

Avoid when:

* Data is unsorted
* Dataset is tiny
* Sequential access only

---

# Interview Questions

### Why not use Binary Search directly?

Because Binary Search requires known boundaries.

---

### Why expand exponentially?

To discover boundaries quickly.

---

### Does this work on infinite arrays?

Yes.

---

### What happens after boundary discovery?

Binary Search executes.

---

# Conclusion

Unbounded Binary Search extends traditional Binary Search by introducing:

```text id="tw9e1g"
Boundary Discovery
↓

Binary Search
```

This allows efficient searching in systems where the dataset size is unknown or continuously growing.

It is widely applicable in **large-scale systems and modern data infrastructures**.

---

# License

MIT License

---

⭐ Star this repository if it helped your DSA learning journey.
