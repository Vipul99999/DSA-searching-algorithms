# Robin Hood Hashing Search

> Robin Hood Hashing is an advanced Open Addressing collision-resolution technique that minimizes search-time variance by allowing elements with larger probe distances to "steal" positions from elements with smaller probe distances.

---

# Table of Contents

1. Introduction
2. Origin of the Name
3. Definition
4. Motivation
5. Core Idea
6. Mathematical Foundation
7. Probe Distance
8. Search Algorithm
9. Insertion Algorithm
10. Example Walkthrough
11. Backward Shift Deletion
12. Complexity Analysis
13. Advantages
14. Disadvantages
15. Real-World Applications
16. Comparison with Other Open Addressing Methods
17. Interview Questions
18. Summary

---

# Introduction

Traditional Open Addressing techniques suffer from uneven probe lengths.

Some keys may be found immediately:

```text
1 probe
```

while others may require:

```text
20+ probes
```

This creates unpredictable performance.

Robin Hood Hashing was designed to reduce this variance.

The goal is not necessarily to minimize average search time, but to make search times more consistent.

---

# Origin of the Name

Inspired by the legendary Robin Hood:

```text
Take from the rich
Give to the poor
```

In hashing:

```text
Keys with short probe distances
lose positions

Keys with long probe distances
gain positions
```

This equalizes probe lengths.

---

# Definition

Robin Hood Hashing is an Open Addressing strategy where, during insertion, an incoming key may replace an existing key if its probe distance is larger.

The displaced key continues probing.

---

# Motivation

Linear Probing example:

```text
A found in 1 probe

B found in 12 probes

C found in 18 probes
```

Large variance.

Robin Hood Hashing attempts:

```text
A found in 5 probes

B found in 6 probes

C found in 7 probes
```

Much more balanced.

---

# Core Idea

Rule:

```text
The key that has traveled farther
gets priority.
```

If:

```text
Incoming probe distance > resident probe distance
```

Swap them.

---

# Mathematical Foundation

Hash Function:

h(k)

Probe Distance:

```
D = CurrentPosition - HomePosition
```

More generally:

```
D = (CurrentPosition - h(k)) mod TableSize
```

---

# Probe Distance

Example:

Hash:

```text
h(25)=5
```

Stored at:

```text
Index 8
```

Probe Distance:

```text
8 - 5 = 3
```

The key has traveled 3 slots.

---

# Search Algorithm

```text
SEARCH(key)

index = hash(key)

while slot occupied

    if key found
        return FOUND

    if probe distance exceeded
        return NOT_FOUND

    move to next slot

return NOT_FOUND
```

---

# Insertion Algorithm

```text
INSERT(key)

current = key

while slot occupied

    if currentProbeDistance >
       residentProbeDistance

        swap(current,resident)

    move to next slot

place key
```

---

# Example Walkthrough

Table:

```text
Index

5 → A
6 → B
7 → C
```

Probe Distances:

```text
A = 0

B = 1

C = 2
```

Insert D:

Probe Distance:

```text
D = 3
```

Since:

```text
3 > 2
```

Swap:

```text
D takes position

C continues probing
```

This balances search cost.

---

# Backward Shift Deletion

Deletion is one of Robin Hood Hashing's strengths.

Instead of tombstones:

```text
Delete key
Shift neighbors backward
```

This maintains compact probe chains.

Benefits:

- Better cache locality
- Faster searches
- Less fragmentation

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

| Operation | Complexity |
|------------|------------|
| Search | O(1) Avg |
| Insert | O(1) Avg |
| Delete | O(1) Avg |
| Worst Case | O(n) |

---

# Advantages

## Reduced Search Variance

More predictable performance.

---

## Better Worst-Case Searches

Probe lengths remain balanced.

---

## Cache Friendly

Array-based structure.

---

## Efficient Deletion

Backward shifting avoids tombstones.

---

# Disadvantages

## Complex Insertion

Swapping logic required.

---

## Longer Insertions

Balancing adds overhead.

---

## More Difficult Implementation

Compared to Linear Probing.

---

# Real-World Applications

## High-Performance Hash Maps

Many modern hash table libraries.

---

## In-Memory Databases

Fast predictable lookups.

---

## Game Engines

Object lookup systems.

---

## Performance-Critical Software

Low-latency search requirements.

---

# Comparison

| Feature | Linear | Robin Hood |
|-----------|---------|------------|
| Probe Variance | High | Low |
| Search Consistency | Poor | Excellent |
| Insert Cost | Lower | Higher |
| Cache Locality | Good | Good |

---

# Interview Questions

1. Why is it called Robin Hood Hashing?
2. What is probe distance?
3. How does insertion work?
4. Why are searches more predictable?
5. Explain backward shift deletion.

---

# Summary

Robin Hood Hashing improves Open Addressing by balancing probe lengths among keys. Through intelligent swapping during insertion, it reduces variance in search times, improves predictability, and delivers excellent real-world performance in modern hash table implementations.
