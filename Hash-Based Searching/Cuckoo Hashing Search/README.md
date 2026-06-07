# Cuckoo Hashing Search

> Cuckoo Hashing is an advanced hash table collision-resolution technique that guarantees O(1) worst-case lookup time by allowing each key to reside in one of two possible locations determined by two hash functions.

---

# Table of Contents

1. Introduction
2. Biological Inspiration
3. Definition
4. Core Idea
5. Mathematical Foundation
6. Data Structure Layout
7. Lookup Algorithm
8. Insertion Algorithm
9. Key Relocation Process
10. Example Walkthrough
11. Rehashing
12. Complexity Analysis
13. Advantages
14. Disadvantages
15. Real-World Applications
16. Comparison with Other Hashing Methods
17. Interview Questions
18. Summary

---

# Introduction

Traditional hash tables often require long probe sequences.

As tables become crowded:

- Search slows down
- Probe lengths increase
- Collisions become expensive

Cuckoo Hashing solves this by allowing every key to occupy one of two possible locations.

Searching only requires checking two locations.

---

# Biological Inspiration

Named after the cuckoo bird.

A cuckoo lays its eggs in another bird's nest.

Existing eggs may be pushed out.

Similarly:

```text
New Key
     ↓
Occupies Slot
     ↓
Old Key Evicted
     ↓
Old Key Moves Elsewhere
```

---

# Definition

Cuckoo Hashing is a collision-resolution technique that uses two hash functions.

Each key may reside in:

```text
h₁(key)
```

or

```text
h₂(key)
```

Only two locations are ever searched.

---

# Core Idea

Every key has two candidate locations.

Example:

```text
Key = 25

Location A = h₁(25)

Location B = h₂(25)
```

Lookup checks only:

```text
A

or

B
```

---

# Mathematical Foundation

Two hash functions:

```
h₁(k)
```

```
h₂(k)
```

Possible locations:

```
L₁ = h₁(k)
```

```
L₂ = h₂(k)
```

---

# Data Structure Layout

Example:

```text
Index

0

1

2

3

4

5

6

7
```

Key:

```text
25
```

May exist only at:

```text
h₁(25)

or

h₂(25)
```

---

# Lookup Algorithm

```text
LOOKUP(key)

if table[h1(key)] == key
    return FOUND

if table[h2(key)] == key
    return FOUND

return NOT_FOUND
```

Only two memory accesses.

---

# Insertion Algorithm

Insert into:

```text
h₁(key)
```

If occupied:

```text
Evict existing key
```

Move evicted key to:

```text
h₂(evicted)
```

Repeat until placement succeeds.

---

# Key Relocation Process

Example:

Insert:

```text
A
```

Location occupied by:

```text
B
```

Result:

```text
A takes slot

B relocated
```

This may trigger additional relocations.

---

# Example Walkthrough

Hash Functions:

```text
h₁(k)=k mod 11
```

```text
h₂(k)=7-(k mod 7)
```

Insert:

```text
22
33
44
```

---

22

Store in first location.

---

33

Collision.

Evict existing key.

Move displaced key.

---

44

Repeat process.

Eventually all keys settle into valid locations.

---

# Rehashing

Sometimes relocation enters a cycle.

Example:

```text
A displaces B

B displaces C

C displaces A
```

Infinite loop.

Solution:

```text
Rebuild table
```

with new hash functions.

---

# Complexity Analysis

## Lookup

O(1)

Worst case guaranteed.

---

## Insert

Average:

O(1)

Worst:

O(n)

during rehashing.

---

## Delete

O(1)

---

# Complexity Table

| Operation | Complexity |
|------------|------------|
| Search | O(1) |
| Insert | O(1) Avg |
| Delete | O(1) |
| Rehash | O(n) |

---

# Advantages

## Guaranteed Lookup

Only two locations checked.

## Extremely Fast Searches

Constant-time access.

## Predictable Performance

Suitable for real-time systems.

## Excellent Cache Locality

Array-based layout.

---

# Disadvantages

## Complex Insertion

Relocations required.

## Rehashing

Cycles force table rebuilds.

## Higher Implementation Complexity

Harder than standard probing.

---

# Real-World Applications

## High-Speed Networking

Packet classification.

---

## Routers

Fast forwarding tables.

---

## Databases

Memory-resident indexes.

---

## Operating Systems

Kernel lookup structures.

---

## Security Systems

Fast signature lookup.

---

# Comparison

| Method | Worst Search |
|-----------|-------------|
| Chaining | O(n) |
| Linear Probing | O(n) |
| Quadratic Probing | O(n) |
| Double Hashing | O(n) |
| Cuckoo Hashing | O(1) |

---

# Interview Questions

1. What is Cuckoo Hashing?
2. Why does lookup require only two checks?
3. Explain key relocation.
4. What causes rehashing?
5. Compare Double Hashing and Cuckoo Hashing.

---

# Summary

Cuckoo Hashing is an advanced collision-resolution technique that provides guaranteed O(1) worst-case lookup time by storing each key in one of two possible locations. Its predictable performance makes it valuable in networking, databases, operating systems, and other high-performance applications.
