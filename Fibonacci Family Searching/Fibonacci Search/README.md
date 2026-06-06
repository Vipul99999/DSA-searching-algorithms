# 🌀 Fibonacci Search

> Fibonacci Search is an efficient searching algorithm that locates an element in a **sorted array** using **Fibonacci numbers** to divide the search space instead of calculating the middle index directly.

It is an alternative to Binary Search and can be advantageous in environments where arithmetic operations or memory access patterns matter.

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

Searching is one of the most fundamental operations in computing.

Popular searching techniques:

* Linear Search
* Binary Search
* Jump Search

Fibonacci Search introduces a different strategy.

Instead of repeatedly computing:

```text id="wznpxt"
middle=(left+right)/2
```

it navigates using Fibonacci numbers.

---

# Definition

**Fibonacci Search** is a searching algorithm that searches a **sorted array** by dividing the search interval according to Fibonacci numbers.

The algorithm progressively reduces the search range until the target is found.

Unlike Binary Search:

```text id="rt8m92"
50%
50%
```

Fibonacci Search partitions using:

```text id="gfc88n"
F(k−1)
F(k−2)
```

---

# Purpose

Fibonacci Search was developed to:

* Reduce expensive arithmetic operations
* Improve predictable memory access
* Support efficient searching in sorted arrays
* Provide an alternative to midpoint division

Main objective:

```text id="t4q74k"
Reduce Search Space
↓

Locate Target
```

---

# Mathematical Foundation

The algorithm relies on the Fibonacci sequence.

Sequence:

```text id="6xv7j5"
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
```

Formula:

```text id="bqt6jq"
F(n)=F(n−1)+F(n−2)
```

Property used:

```text id="9a2a9q"
F(n−2)+F(n−1)=F(n)
```

---

# Core Idea

Instead of using midpoint:

```text id="a6sgrq"
(left+right)/2
```

Fibonacci Search computes:

```text id="u9m1zg"
offset+F(k−2)
```

The interval shrinks according to Fibonacci numbers.

---

# Method

Fibonacci Search follows these phases.

---

## Phase 1 — Generate Fibonacci Range

Generate Fibonacci numbers until:

```text id="mbd4ya"
Fib ≥ Array Size
```

Example:

```text id="pkc0mn"
1
2
3
5
8
13
21
```

---

## Phase 2 — Compare

Choose comparison position.

```text id="vot67l"
offset+F(k−2)
```

---

## Phase 3 — Reduce Search Space

If:

```text id="cw5yul"
Target > Current
```

Move right.

Otherwise:

```text id="yuzvsm"
Move left
```

---

## Phase 4 — Repeat

Continue until:

```text id="uwwsl7"
Target Found
```

---

# Working Process

```text id="hwhzj5"
Start

↓

Generate Fibonacci Number

↓

Calculate Position

↓

Compare

↓

Reduce Range

↓

Repeat

↓

Result
```

---

# Algorithm

## Procedure

1. Generate Fibonacci values.
2. Select comparison index.
3. Compare target.
4. Reduce interval.
5. Repeat until found.

---

## Pseudocode

```text id="wq3l22"
FibonacciSearch(A,target):

fibMMm2=0
fibMMm1=1
fibM=1

while fibM<n:
    fibMMm2=fibMMm1
    fibMMm1=fibM
    fibM=fibMMm2+fibMMm1

offset=-1

while fibM>1:

    i=min(
        offset+fibMMm2,
        n-1
    )

    if A[i]<target:
        move right

    else if A[i]>target:
        move left

    else:
        return i

return -1
```

---

# Example

Input:

```text id="kpp28m"
Array

[10,20,30,40,50,60,70]

Target = 50
```

Generate Fibonacci:

```text id="kpq5pj"
1
2
3
5
8
```

---

## First Comparison

```text id="o0t4gh"
Index = 3

Value = 40
```

Target larger.

Move right.

---

## Second Comparison

```text id="jlwmzx"
Index = 4

Value = 50
```

Result:

```text id="4ts7rb"
Found
```

---

# Visualization

```text id="nhzgwq"
Array

[10][20][30][40][50][60][70]

Compare

         ↑

Reduce

             ↑
```

---

# Complexity Analysis

## Time Complexity

### Best Case

```text id="gskdb7"
O(1)
```

---

### Average Case

```text id="pd54m7"
O(log n)
```

---

### Worst Case

```text id="n8w1xy"
O(log n)
```

---

## Space Complexity

```text id="jyu0mb"
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

## Database Indexing

Efficient record searching.

---

## Embedded Systems

Lower arithmetic overhead.

---

## File Systems

Predictable access.

---

## Scientific Computing

Interval reduction.

---

## Search Engines

Large sorted index traversal.

---

## Memory-Constrained Systems

Reduced resource usage.

---

# Advantages

✅ Efficient for sorted arrays

✅ Constant memory usage

✅ Reduced division operations

✅ Predictable access patterns

✅ Alternative to Binary Search

---

# Disadvantages

❌ Requires sorted data

❌ More complex implementation

❌ Less popular than Binary Search

❌ Limited practical gains on modern hardware

❌ Additional Fibonacci calculations

---

# Comparison with Other Algorithms

| Algorithm        | Sorted | Average  | Space |
| ---------------- | ------ | -------- | ----- |
| Linear Search    | No     | O(n)     | O(1)  |
| Binary Search    | Yes    | O(log n) | O(1)  |
| Fibonacci Search | Yes    | O(log n) | O(1)  |

---

# Implementation Structure

```text id="hz73ei"
FibonacciSearch/

├── FibonacciSearch.c
├── FibonacciSearch.cpp
├── FibonacciSearch.java
├── FibonacciSearch.py
└── FibonacciSearch.js
```

---

# When To Use

Use Fibonacci Search when:

* Data is sorted
* Predictable access is preferred
* Memory efficiency matters

Avoid when:

* Data is unsorted
* Simplicity is preferred
* Arrays are very small

---

# Interview Questions

### Why use Fibonacci Search?

To reduce search intervals using Fibonacci numbers.

---

### Does Fibonacci Search outperform Binary Search?

Usually similar complexity.

---

### Does it require sorting?

Yes.

---

### What makes it unique?

It avoids repeated midpoint division.

---

# Conclusion

Fibonacci Search demonstrates how mathematical sequences can optimize interval reduction.

Core principle:

```text id="fyv6rb"
Fibonacci Numbers
↓

Reduce Search Space

↓

Locate Target
```

It remains a valuable algorithm for understanding alternative search strategies.

---

# License

MIT License

---

⭐ Star this repository if it helped your DSA learning journey.
