# Dynamic Hashing

> Dynamic Hashing is a family of hashing techniques that automatically adjust the hash structure as data grows or shrinks, eliminating the need for expensive full-table rebuilding.

---

# Table of Contents

1. Introduction
2. Definition
3. Motivation
4. Static vs Dynamic Hashing
5. Core Idea
6. Bucket Splitting
7. Directory Concepts
8. Search Process
9. Insertion Process
10. Dynamic Hashing Family
11. Complexity Analysis
12. Advantages
13. Disadvantages
14. Real-World Applications
15. Interview Questions
16. Summary

---

# Introduction

Traditional hash tables use a fixed size.

Problems:

```text
Table too small
 ↓
Many collisions
 ↓
Poor performance
```

Solution:

```text
Resize table
 ↓
Rehash everything
```

Very expensive.

Dynamic Hashing avoids this issue.

---

# Definition

Dynamic Hashing is a hashing technique that allows the hash structure to expand or shrink incrementally as data changes.

---

# Motivation

Static Hashing:

```text
100 buckets
```

Data grows:

```text
1000 records
```

Results:

```text
Heavy collisions
```

Dynamic Hashing:

```text
Automatically creates
new buckets
```

without rebuilding everything.

---

# Static vs Dynamic Hashing

| Feature | Static | Dynamic |
|----------|---------|---------|
| Bucket Count | Fixed | Variable |
| Growth | Difficult | Easy |
| Rehashing | Full | Incremental |
| Scalability | Limited | Excellent |

---

# Core Idea

Instead of rebuilding:

```text
Entire Table
```

split only:

```text
Affected Bucket
```

This greatly improves scalability.

---

# Bucket Splitting

When bucket becomes full:

```text
Split Bucket
```

Move some records into:

```text
New Bucket
```

Update routing information.

---

# Search Process

```text
SEARCH(key)

Compute hash

Locate bucket

Search bucket

Return result
```

---

# Insertion Process

```text
INSERT(key)

Locate bucket

If bucket full

    Split bucket

Insert key
```

---

# Dynamic Hashing Family

Major algorithms:

- Extendible Hashing
- Linear Hashing

Both belong to Dynamic Hashing.

---

# Complexity Analysis

| Operation | Complexity |
|------------|------------|
| Search | O(1) |
| Insert | O(1) Avg |
| Delete | O(1) Avg |

---

# Advantages

- Scalable
- Supports large datasets
- Incremental growth
- Reduces rehashing costs

---

# Disadvantages

- More metadata
- More complex implementation
- Additional storage overhead

---

# Real-World Applications

## Database Systems

Dynamic indexes.

---

## File Systems

Directory structures.

---

## Distributed Storage

Scalable bucket management.

---

## Cloud Databases

Elastic growth.

---

# Interview Questions

1. What is Dynamic Hashing?
2. Why is it better than static hashing?
3. What is bucket splitting?
4. Name two Dynamic Hashing algorithms.

---

# Summary

Dynamic Hashing allows hash structures to grow incrementally without expensive full-table rebuilds. It is the foundation for scalable database indexing and modern storage systems.
