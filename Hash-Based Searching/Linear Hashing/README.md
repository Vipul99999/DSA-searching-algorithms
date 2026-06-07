# Linear Hashing

> Linear Hashing is a Dynamic Hashing technique that grows a hash table incrementally by splitting buckets one at a time, avoiding expensive full-table rehashing operations.

---

# Table of Contents

1. Introduction
2. Definition
3. Motivation
4. Core Idea
5. Hash Functions
6. Split Pointer
7. Bucket Splitting
8. Search Algorithm
9. Insertion Algorithm
10. Example Walkthrough
11. Growth Process
12. Complexity Analysis
13. Advantages
14. Disadvantages
15. Real-World Applications
16. Linear Hashing vs Extendible Hashing
17. Interview Questions
18. Summary

---

# Introduction

Traditional hash tables have a major scalability problem.

When the table becomes full:

```text
Resize
    ↓
Rehash All Records
```

This operation is expensive.

Linear Hashing solves this issue by growing incrementally.

Instead of rebuilding the entire structure:

```text
Split One Bucket
```

at a time.

---

# Definition

Linear Hashing is a Dynamic Hashing technique that expands a hash table gradually through controlled bucket splitting.

Unlike Extendible Hashing, it does not require a directory.

---

# Motivation

Static Hash Table:

```text
100 Buckets
```

Data grows:

```text
1000 Records
```

Result:

```text
Many Collisions
```

Traditional Solution:

```text
Double Table Size
```

Problem:

```text
Rehash Everything
```

Linear Hashing:

```text
Split One Bucket
```

Only a small amount of work.

---

# Core Idea

Maintain:

```text
Current Hash Function
```

and

```text
Split Pointer
```

As data grows:

```text
Split buckets sequentially
```

instead of rebuilding the table.

---

# Hash Functions

Linear Hashing uses two hash functions.

Current Level:

```
hₙ(k)
```

Next Level:

```
hₙ₊₁(k)
```

Example:

```
hₙ(k)=k mod N
```

```
hₙ₊₁(k)=k mod 2N
```

---

# Split Pointer

A special pointer:

```text
S
```

tracks the next bucket to split.

Example:

```text
Bucket 0
Bucket 1
Bucket 2
Bucket 3
```

Split Order:

```text
0
1
2
3
```

Sequential.

---

# Bucket Splitting

When load factor exceeds threshold:

```text
Split Bucket S
```

Create:

```text
New Bucket
```

Redistribute records.

Move:

```text
S++
```

---

# Search Algorithm

```text
SEARCH(key)

Compute bucket

Locate bucket

Search records

Return result
```

---

# Insertion Algorithm

```text
INSERT(key)

Insert into bucket

If load factor exceeded

    Split bucket S

    Move S forward
```

---

# Example Walkthrough

Initial Buckets:

```text
0
1
2
3
```

Split Pointer:

```text
S=0
```

Load Factor becomes large.

Split Bucket 0:

```text
0
1
2
3
4
```

Move:

```text
S=1
```

Next split:

```text
Bucket 1
```

and so on.

---

# Growth Process

Traditional:

```text
4 Buckets
     ↓
8 Buckets
     ↓
16 Buckets
```

Large jumps.

---

Linear Hashing:

```text
4
5
6
7
8
9
10
...
```

Smooth growth.

---

# Complexity Analysis

| Operation | Complexity |
|------------|------------|
| Search | O(1) Avg |
| Insert | O(1) Avg |
| Delete | O(1) Avg |
| Split | O(B) |

B = bucket size

---

# Advantages

## Incremental Growth

No massive rehashing.

---

## No Directory

Simpler than Extendible Hashing.

---

## Good Scalability

Handles growing datasets.

---

## Storage Efficient

Minimal metadata.

---

# Disadvantages

## More Complex than Static Hashing

Additional split logic.

---

## Temporary Overflow Buckets

May exist during growth.

---

## Less Predictable than Extendible Hashing

Search path can vary.

---

# Real-World Applications

## Database Systems

Dynamic indexing.

---

## Storage Engines

Large-scale record lookup.

---

## Distributed Storage

Scalable bucket management.

---

## File Systems

Hash-based metadata access.

---

# Linear Hashing vs Extendible Hashing

| Feature | Linear | Extendible |
|-----------|----------|------------|
| Directory | No | Yes |
| Splitting | Sequential | Target Bucket |
| Metadata | Low | Higher |
| Memory Overhead | Lower | Higher |
| Complexity | Moderate | High |

---

# Interview Questions

1. What is Linear Hashing?
2. What is the Split Pointer?
3. Why does Linear Hashing avoid rehashing?
4. Compare Linear and Extendible Hashing.
5. Why is growth incremental?

---

# Summary

Linear Hashing is one of the most important Dynamic Hashing techniques. By splitting buckets incrementally rather than rebuilding the entire structure, it provides scalable near O(1) search performance and is widely used in database and storage systems.
