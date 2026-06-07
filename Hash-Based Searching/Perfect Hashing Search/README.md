# Perfect Hashing Search

> Perfect Hashing is a hashing technique that guarantees zero collisions for a predefined set of keys, enabling worst-case O(1) search operations.

---

# Table of Contents

1. Introduction
2. Definition
3. Motivation
4. Core Idea
5. Mathematical Foundation
6. Perfect vs Minimal Perfect Hashing
7. Search Process
8. Construction Process
9. Two-Level Perfect Hashing
10. Example Walkthrough
11. Complexity Analysis
12. Advantages
13. Disadvantages
14. Real-World Applications
15. Comparison with Traditional Hashing
16. Interview Questions
17. Summary

---

# Introduction

Traditional hash tables suffer from collisions.

Example:

```text
Hash(A) = 5
Hash(B) = 5
```

Both keys map to the same location.

Collision resolution techniques:

- Chaining
- Linear Probing
- Double Hashing

all add overhead.

Perfect Hashing eliminates collisions completely.

---

# Definition

A Perfect Hash Function maps every key in a fixed key set to a unique table location.

Formally:

For all keys:

```text
x ≠ y
```

then:

```text
h(x) ≠ h(y)
```

No collisions occur.

---

# Motivation

Traditional Search:

```text
Hash
 ↓
Collision?
 ↓
Resolve
 ↓
Search
```

Perfect Hashing:

```text
Hash
 ↓
Direct Access
```

No collision resolution needed.

---

# Core Idea

Given:

```text
{Apple, Mango, Orange, Banana}
```

Construct a hash function:

```text
Apple  → 0
Mango  → 1
Orange → 2
Banana → 3
```

Every key receives a unique slot.

---

# Mathematical Foundation

For key set:

```text
S = {k₁,k₂,k₃,...,kₙ}
```

Perfect Hash Function:

```text
h : S → {0,1,...,m−1}
```

such that:

```text
h(kᵢ) ≠ h(kⱼ)
```

for all:

```text
i ≠ j
```

---

# Perfect vs Minimal Perfect Hashing

## Perfect Hashing

```text
n keys
m ≥ n slots
```

No collisions.

Unused slots possible.

---

## Minimal Perfect Hashing

```text
n keys
n slots
```

No collisions.

No wasted space.

---

# Search Process

```text
SEARCH(key)

index = hash(key)

return table[index]
```

Only one lookup.

---

# Construction Process

Most of the complexity occurs during construction.

Steps:

1. Analyze key set
2. Generate candidate hash functions
3. Detect collisions
4. Refine hash function
5. Build collision-free table

---

# Two-Level Perfect Hashing

Common implementation.

Level 1:

```text
Primary hash
```

Level 2:

```text
Collision-free secondary tables
```

Provides:

```text
O(1)
```

worst-case search.

---

# Example Walkthrough

Keys:

```text
Dog
Cat
Bird
Fish
```

Generated table:

```text
0 → Bird
1 → Dog
2 → Fish
3 → Cat
```

Search:

```text
Cat
 ↓
Hash
 ↓
Index 3
 ↓
Found
```

---

# Complexity Analysis

## Search

O(1)

Worst Case Guaranteed

---

## Insert

O(n)

May require rebuilding.

---

## Delete

O(1)

---

# Complexity Table

| Operation | Complexity |
|------------|------------|
| Search | O(1) |
| Insert | O(n) |
| Delete | O(1) |
| Space | O(n) |

---

# Advantages

## Zero Collisions

Guaranteed.

---

## Constant-Time Search

Worst-case O(1).

---

## Predictable Performance

No probing.

No chaining.

---

## Ideal for Static Data

Fixed key sets.

---

# Disadvantages

## Expensive Construction

Building hash function is difficult.

---

## Poor for Dynamic Data

Insertions may require rebuilding.

---

## Complex Implementation

Advanced algorithms needed.

---

# Real-World Applications

## Compiler Design

Reserved keyword lookup.

---

## Programming Languages

Token recognition.

---

## Network Protocol Parsers

Command lookup.

---

## Static Dictionaries

Fast word lookup.

---

## Database Query Optimizers

Metadata indexing.

---

# Comparison

| Feature | Traditional Hashing | Perfect Hashing |
|-----------|--------------------|----------------|
| Collisions | Possible | Impossible |
| Search | O(1) Avg | O(1) Worst |
| Dynamic Updates | Easy | Difficult |
| Construction | Easy | Hard |

---

# Interview Questions

1. What is Perfect Hashing?
2. Why does it guarantee O(1)?
3. What is Minimal Perfect Hashing?
4. Why is it best for static data?
5. Explain two-level perfect hashing.

---

# Summary

Perfect Hashing eliminates collisions entirely for a fixed set of keys. It provides guaranteed O(1) search performance and is widely used in compilers, parsers, static dictionaries, and other systems where the key set rarely changes.
