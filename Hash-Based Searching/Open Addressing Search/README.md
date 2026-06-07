# Open Addressing Search

> Open Addressing Search is a collision-resolution strategy in hash tables where all elements are stored directly within the table itself. When a collision occurs, the algorithm searches for another available slot according to a probing sequence.

---

# Table of Contents

1. Introduction
2. Definition
3. Why Open Addressing Exists
4. Core Idea
5. Mathematical Foundation
6. General Search Process
7. General Insertion Process
8. Probing Sequences
9. Load Factor Analysis
10. Clustering Problems
11. Complexity Analysis
12. Advantages
13. Disadvantages
14. Real-World Applications
15. Open Addressing Family
16. Comparison with Separate Chaining
17. Interview Questions
18. Summary

---

# Introduction

Hash tables aim to provide O(1) average lookup performance.

However, multiple keys can generate the same hash value.

This situation is known as a collision.

Open Addressing resolves collisions without using linked lists or external storage structures.

Instead, all records remain inside the hash table.

---

# Definition

Open Addressing is a collision-resolution technique in which collisions are resolved by probing alternative locations within the hash table until a suitable slot is found.

Unlike Separate Chaining:

```text
Bucket
 ↓
Linked List
```

Open Addressing uses:

```text
Bucket
 ↓
Another Bucket
 ↓
Another Bucket
```

until an empty slot is found.

---

# Why Open Addressing Exists

Suppose:

h(15) = 5

h(25) = 5

Both keys map to index 5.

Instead of creating a linked list:

```text
5 → [15] → [25]
```

Open Addressing searches for another location:

```text
5 → [15]

6 → [25]
```

All data remains inside the table.

---

# Core Idea

Collision:

```text
Index 5 occupied
```

Find:

```text
Index 6
Index 7
Index 8
...
```

according to a predefined probing strategy.

---

# Mathematical Foundation

Hash Function:

h(k)

Collision Resolution:

h₀(k), h₁(k), h₂(k), ...

where:

- h₀ = original location
- h₁ = first alternative
- h₂ = second alternative

These locations form the probing sequence.

---

# General Search Process

Step 1

Compute hash value.

Step 2

Visit calculated slot.

Step 3

If key found → success.

Step 4

Otherwise follow probing sequence.

Step 5

Repeat until:

- key found
- empty slot encountered
- full cycle completed

---

# General Insertion Process

```text
INSERT(key)

index = HASH(key)

while slot occupied

    index = NEXT_PROBE(index)

place key
```

---

# Probing Sequences

Open Addressing has multiple probing methods:

### Linear Probing

```text
+1
+2
+3
...
```

### Quadratic Probing

```text
+1²
+2²
+3²
...
```

### Double Hashing

Uses a second hash function.

### Robin Hood Hashing

Balances probe lengths.

### Hopscotch Hashing

Maintains locality.

---

# Load Factor Analysis

Load Factor:

α = n / m

Where:

- n = stored elements
- m = table size

---

Low Load Factor

```text
Few collisions
Fast searches
```

---

High Load Factor

```text
Many collisions
Long probe sequences
Slow searches
```

Open Addressing performance strongly depends on load factor.

Most implementations resize before:

```text
α > 0.7
```

---

# Clustering Problems

Open Addressing suffers from clustering.

Clustering occurs when nearby slots become occupied.

This creates long probe chains.

Types:

### Primary Clustering

Long continuous occupied blocks.

### Secondary Clustering

Keys follow identical probing sequences.

---

# Complexity Analysis

## Best Case

O(1)

---

## Average Case

O(1)

for reasonable load factors.

---

## Worst Case

O(n)

when table becomes heavily loaded.

---

# Complexity Table

| Case | Complexity |
|--------|-------------|
| Best | O(1) |
| Average | O(1) |
| Worst | O(n) |

---

# Space Complexity

| Complexity |
|------------|
| O(n) |

No additional linked structures required.

---

# Advantages

## Memory Efficient

No linked lists.

## Excellent Cache Locality

Contiguous memory improves performance.

## Fast Lookups

Near O(1) average time.

## Simple Storage Layout

Array-based implementation.

---

# Disadvantages

## Clustering

Major performance issue.

## Deletion Complexity

Special handling required.

## Sensitive to Load Factor

Performance drops rapidly.

## Resizing Cost

Rehashing may be expensive.

---

# Real-World Applications

## Language Runtime Hash Maps

Many modern runtimes use open addressing.

---

## Embedded Systems

Memory efficiency is critical.

---

## Database Engines

Fast in-memory indexing.

---

## High-Performance Caches

Cache-friendly access patterns.

---

## Networking Software

Packet lookup tables.

---

# Open Addressing Family

This category includes:

- Linear Probing
- Quadratic Probing
- Double Hashing
- Robin Hood Hashing
- Hopscotch Hashing

Each variant attempts to reduce clustering and improve performance.

---

# Comparison with Separate Chaining

| Feature | Open Addressing | Separate Chaining |
|-----------|----------------|------------------|
| Extra Memory | No | Yes |
| Cache Locality | Excellent | Poor |
| Deletion | Harder | Easier |
| High Load Factors | Worse | Better |
| Memory Usage | Lower | Higher |

---

# Interview Questions

1. What is Open Addressing?
2. Why does clustering occur?
3. What is a probing sequence?
4. Why is load factor important?
5. Compare Open Addressing and Chaining.
6. Why is deletion difficult?

---

# Summary

Open Addressing is one of the most widely used collision-resolution strategies in hash tables. It stores all data directly within the table and resolves collisions through probing sequences. Its excellent cache locality and memory efficiency make it highly effective in modern high-performance systems.
