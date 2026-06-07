# Double Hashing

> Double Hashing is an Open Addressing collision-resolution technique that uses two independent hash functions to generate probe sequences, significantly reducing clustering and improving hash table performance.

---

# Table of Contents

1. Introduction
2. Definition
3. Motivation
4. Core Idea
5. Mathematical Foundation
6. Probe Sequence Generation
7. Search Algorithm
8. Insertion Algorithm
9. Example Walkthrough
10. Complexity Analysis
11. Clustering Analysis
12. Advantages
13. Disadvantages
14. Real-World Applications
15. Comparison with Other Probing Methods
16. Interview Questions
17. Summary

---

# Introduction

Linear Probing and Quadratic Probing suffer from clustering.

As the table becomes crowded:

- Search times increase
- Probe lengths increase
- Performance degrades

Double Hashing was developed to reduce these problems by generating a more random probing sequence.

It is often considered one of the best Open Addressing techniques.

---

# Definition

Double Hashing is an Open Addressing collision-resolution strategy that uses two hash functions:

- Primary Hash Function
- Secondary Hash Function

The second hash function determines the step size used during probing.

---

# Motivation

Suppose:

```text
h(25) = 5
h(35) = 5
h(45) = 5
```

All keys collide.

Linear Probing:

```text
5 → 6 → 7 → 8
```

Creates clusters.

Double Hashing:

```text
5 → 12 → 19 → 26
```

Spreads keys across the table.

---

# Core Idea

Instead of moving by:

```text
+1
+1
+1
```

Move by:

```text
hash2(key)
```

Each key gets its own probe sequence.

---

# Mathematical Foundation

Primary Hash:

h₁(k)

Secondary Hash:

h₂(k)

Probe Formula:

```
h(k, i) = (h₁(k) + i × h₂(k)) mod m
```

Where:

- i = probe number
- m = table size

---

# Example Hash Functions

Primary:

```
h₁(k) = k mod 13
```

Secondary:

```
h₂(k) = 7 - (k mod 7)
```

---

# Probe Sequence Generation

For key:

```text
25
```

Compute:

```
h₁(25) = 12

h₂(25) = 3
```

Sequence:

```text
12
15
18
21
24
...
```

(mod table size)

---

# Search Algorithm

```text
SEARCH(key)

i = 0

while table slot not empty

    index =
    (h1(key) + i*h2(key)) mod m

    if key found
        return FOUND

    i++

return NOT_FOUND
```

---

# Insertion Algorithm

```text
INSERT(key)

i = 0

while slot occupied

    index =
    (h1(key) + i*h2(key)) mod m

    i++

insert key
```

---

# Example Walkthrough

Table Size:

13

Primary:

```
h₁(k)=k mod 13
```

Secondary:

```
h₂(k)=7-(k mod 7)
```

Insert:

25

38

51

---

25

```
h₁=12
```

Store at 12.

---

38

```
h₁=12
```

Collision.

```
h₂=4
```

Probe:

```text
12 + 4 = 16

16 mod 13 = 3
```

Store at 3.

---

51

```
h₁=12
```

Collision.

```
h₂=5
```

Probe:

```text
12 + 5 = 17

17 mod 13 = 4
```

Store at 4.

---

# Complexity Analysis

## Best Case

O(1)

---

## Average Case

O(1)

---

## Worst Case

O(n)

---

# Complexity Table

| Case | Complexity |
|--------|-------------|
| Best | O(1) |
| Average | O(1) |
| Worst | O(n) |

---

# Clustering Analysis

## Primary Clustering

Almost eliminated.

Different keys use different step sizes.

---

## Secondary Clustering

Significantly reduced.

Probe sequences differ.

---

# Advantages

## Excellent Distribution

Keys spread evenly.

## Reduced Clustering

Much better than linear probing.

## Memory Efficient

No linked lists.

## High Performance

Near-uniform probing.

---

# Disadvantages

## Two Hash Functions

More computation.

## Implementation Complexity

More difficult than linear probing.

## Poor Performance at High Load Factors

Still suffers when table becomes full.

---

# Real-World Applications

## In-Memory Databases

Fast indexing.

---

## Embedded Systems

Memory-efficient storage.

---

## Routing Tables

Fast lookup structures.

---

## Caches

High-performance key-value stores.

---

# Comparison

| Feature | Linear | Quadratic | Double |
|-----------|----------|------------|----------|
| Primary Clustering | High | Low | Very Low |
| Secondary Clustering | High | Moderate | Very Low |
| Complexity | Simple | Medium | Higher |
| Distribution | Poor | Good | Excellent |

---

# Interview Questions

1. What is Double Hashing?
2. Why use two hash functions?
3. How does it reduce clustering?
4. Compare Double Hashing with Quadratic Probing.
5. Why must h₂(k) never be zero?

---

# Summary

Double Hashing is one of the most effective Open Addressing collision-resolution techniques. By using a second hash function to determine probe distances, it greatly reduces clustering and provides near-random probe sequences, resulting in excellent average-case lookup performance.
