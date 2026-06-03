# Linear Hashing

Linear Hashing is a dynamic hashing technique that expands hash storage **incrementally** instead of rebuilding the entire hash table at once.

Unlike static hash tables that require costly resizing operations, Linear Hashing gradually splits buckets as data grows, allowing efficient insertion and lookup while maintaining stable performance.

This technique is commonly used in **database indexing, storage systems, and scalable retrieval architectures**.

---

## Table of Contents

* Introduction
* Motivation
* Core Idea
* Components
* Search Workflow
* Bucket Splitting
* Example
* Complexity Analysis
* Advantages
* Limitations
* Applications
* Comparison
* Conclusion

---

# Introduction

Traditional hash tables suffer from expensive global resizing.

Typical resizing:

```text
Table Full
↓
Allocate Larger Table
↓
Rehash Entire Dataset
```

Linear Hashing avoids this cost through controlled expansion.

---

# Motivation

Static hashing:

```text
Insert
↓
Overflow
↓
Complete Rebuild
```

Linear hashing:

```text
Insert
↓
Split One Bucket
↓
Continue Operations
```

This enables smoother growth.

---

# Core Idea

Linear Hashing maintains:

* Hash table
* Split pointer
* Hash levels
* Dynamic buckets

Only selected buckets are expanded over time.

---

# Components

## Buckets

Store actual records.

---

## Split Pointer

Tracks which bucket expands next.

---

## Hash Function Levels

Controls current and future bucket mapping.

---

# Search Workflow

```text
Input Key
↓
Compute Hash
↓
Locate Bucket
↓
Retrieve Data
```

If bucket already split:

```text
Apply Expanded Mapping
```

---

# Bucket Splitting

Overflow handling:

```text
Bucket Overflow
↓
Split Current Bucket
↓
Redistribute Records
↓
Move Split Pointer
```

When complete:

```text
Reset Pointer
Increase Hash Level
```

---

# Example

Initial:

```text
Buckets:
0
1
2
3
```

Insert data.

Overflow:

```text
Split Bucket 0
```

Result:

```text
0
1
2
3
4
```

Further growth continues incrementally.

---

# Complexity Analysis

| Operation | Average    |
| --------- | ---------- |
| Search    | O(1)       |
| Insert    | O(1)       |
| Delete    | O(1)       |
| Split     | O(n) Local |

Space Complexity:

```text
O(n)
```

---

# Advantages

* Incremental growth
* No global rehashing
* Efficient insertions
* Stable performance
* Suitable for large datasets

---

# Limitations

* Split management overhead
* More complex than static hashing
* Additional bucket metadata

---

# Applications

* Database indexing
* Dynamic storage systems
* Key-value stores
* Distributed retrieval
* Persistent indexing

---

# Comparison

| Method             | Resize Strategy |
| ------------------ | --------------- |
| Static Hashing     | Global          |
| Extendible Hashing | Directory-Based |
| Linear Hashing     | Incremental     |

---

# Conclusion

Linear Hashing improves scalability by expanding hash storage gradually rather than rebuilding the entire structure. This incremental approach makes it effective for high-volume dynamic storage and indexing systems.
