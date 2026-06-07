# Hopscotch Hashing Search

> Hopscotch Hashing is a cache-efficient and concurrency-friendly Open Addressing technique that maintains elements within a small neighborhood of their original hash location, enabling extremely fast lookups even at high load factors.

---

# Table of Contents

1. Introduction
2. Motivation
3. Definition
4. Core Idea
5. Neighborhood Concept
6. Mathematical Foundation
7. Data Structure Layout
8. Search Algorithm
9. Insertion Algorithm
10. Relocation Mechanism
11. Example Walkthrough
12. Concurrency Features
13. Complexity Analysis
14. Advantages
15. Disadvantages
16. Real-World Applications
17. Comparison with Other Methods
18. Interview Questions
19. Summary

---

# Introduction

Traditional Open Addressing methods often suffer from:

- Long probe sequences
- Poor performance at high load factors
- Difficult concurrent access

Hopscotch Hashing addresses these problems by ensuring that each key remains close to its home bucket.

---

# Motivation

Suppose:

```text
Hash(25)=5
```

Ideally:

```text
Store near bucket 5
```

Instead of:

```text
Bucket 80
```

far away.

Keeping keys nearby improves:

- Cache locality
- Search speed
- Concurrent access

---

# Definition

Hopscotch Hashing is an Open Addressing technique where every key must remain within a fixed-size neighborhood around its original hash bucket.

---

# Core Idea

Each bucket owns a neighborhood.

Example:

Neighborhood Size:

```text
H = 4
```

Bucket 5 controls:

```text
5
6
7
8
```

Any key hashing to bucket 5 must remain inside this range.

---

# Neighborhood Concept

Suppose:

```text
H = 4
```

Bucket:

```text
10
```

Neighborhood:

```text
10
11
12
13
```

Search only examines this neighborhood.

This dramatically reduces search cost.

---

# Mathematical Foundation

Hash Function:

```
h(k)
```

Neighborhood:

```
[h(k), h(k)+H-1]
```

Where:

- H = neighborhood size

---

# Data Structure Layout

Example:

```text
Index

10
11
12
13
```

All keys belonging to bucket 10 must reside within these slots.

---

# Search Algorithm

```text
SEARCH(key)

home = hash(key)

search within neighborhood

if found
    return FOUND

return NOT_FOUND
```

Only a few locations are checked.

---

# Insertion Algorithm

1. Find free slot.
2. If outside neighborhood:
   relocate nearby keys.
3. Move free slot closer.
4. Continue until neighborhood constraint is satisfied.
5. Insert key.

---

# Relocation Mechanism

Suppose:

```text
Free slot at 20
```

Desired:

```text
Bucket 10 neighborhood
```

Hopscotch performs:

```text
Swap nearby entries
```

until free space moves closer.

This resembles "hopping" a free slot toward the target bucket.

---

# Example Walkthrough

Neighborhood Size:

```text
H = 4
```

Key:

```text
25
```

Home Bucket:

```text
10
```

Valid Locations:

```text
10
11
12
13
```

If nearest free slot is:

```text
17
```

Relocation operations move the free slot toward:

```text
13
```

Then insert key.

---

# Concurrency Features

One of Hopscotch Hashing's biggest strengths.

Benefits:

- Fine-grained locking
- Lock-free variants
- Concurrent insertions
- Concurrent searches

Widely studied in parallel systems.

---

# Complexity Analysis

## Search

O(1)

Neighborhood size is fixed.

---

## Insert

O(1) Average

---

## Delete

O(1)

---

## Worst Case

O(n)

Rare.

---

# Complexity Table

| Operation | Complexity |
|------------|------------|
| Search | O(1) |
| Insert | O(1) Avg |
| Delete | O(1) |
| Worst | O(n) |

---

# Advantages

## Excellent Cache Locality

Keys remain nearby.

---

## Fast Searches

Small neighborhood scans.

---

## High Load Factors

Works efficiently even when heavily loaded.

---

## Concurrency Friendly

Designed for parallel environments.

---

## Predictable Performance

Bounded search regions.

---

# Disadvantages

## Complex Implementation

More difficult than linear probing.

---

## Relocation Overhead

Insertions may trigger swaps.

---

## Extra Metadata

Neighborhood tracking required.

---

# Real-World Applications

## Concurrent Hash Tables

Multi-threaded systems.

---

## Database Engines

In-memory indexing.

---

## Network Routers

Fast packet lookups.

---

## Operating Systems

Kernel-level lookup structures.

---

## High-Frequency Trading Systems

Ultra-low latency access.

---

# Comparison

| Feature | Linear | Robin Hood | Hopscotch |
|-----------|---------|------------|-----------|
| Cache Locality | Good | Good | Excellent |
| Concurrency | Poor | Moderate | Excellent |
| Load Factor Tolerance | Moderate | High | Very High |
| Complexity | Simple | Medium | High |

---

# Interview Questions

1. What is a neighborhood?
2. Why is it called Hopscotch Hashing?
3. How does relocation work?
4. Why is it concurrency friendly?
5. Compare Hopscotch and Robin Hood Hashing.

---

# Summary

Hopscotch Hashing is a highly optimized Open Addressing technique that keeps keys close to their home buckets, resulting in exceptional cache locality, predictable searches, and excellent support for concurrent environments. It is particularly valuable in modern high-performance systems where both speed and scalability are critical.
