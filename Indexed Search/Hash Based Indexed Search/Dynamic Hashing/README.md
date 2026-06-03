# Dynamic Hashing

Dynamic Hashing is a hashing technique that automatically adjusts its structure as the dataset changes.

Instead of relying on fixed-size storage, Dynamic Hashing grows or reorganizes storage dynamically to maintain efficient searching, insertion, and deletion performance.

It is designed for environments where data volume changes continuously.

---

## Table of Contents

* Introduction
* Motivation
* Core Idea
* Components
* Search Workflow
* Dynamic Expansion
* Example
* Complexity Analysis
* Advantages
* Limitations
* Applications
* Comparison
* Conclusion

---

# Introduction

Static hashing assumes a fixed storage size.

As datasets grow:

```text
Overflow
↓
Performance Drop
```

Dynamic hashing solves this by adapting automatically.

---

# Motivation

Traditional hashing:

```text
Fixed Capacity
↓
Overflow
↓
Rebuild
```

Dynamic hashing:

```text
Growth
↓
Adjust Structure
↓
Continue Operations
```

This minimizes interruptions.

---

# Core Idea

Dynamic hashing allows:

* Bucket expansion
* Bucket splitting
* Storage adaptation
* Dynamic index adjustment

Search performance remains efficient as data changes.

---

# Components

## Hash Function

Generates storage locations.

---

## Dynamic Buckets

Grow or split when required.

---

## Metadata Layer

Tracks storage organization.

---

## Expansion Logic

Controls resizing operations.

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

Overflow handling:

```text
Expand Structure
↓
Continue Search
```

---

# Dynamic Expansion

When capacity reaches threshold:

```text
Overflow
↓
Split Bucket
↓
Adjust Mapping
↓
Redistribute Records
```

This avoids complete rebuilding.

---

# Example

Initial:

```text
Bucket A
Bucket B
```

Insert more data:

```text
Overflow
↓
Create Bucket C
```

Result:

```text
A
B
C
```

Search continues normally.

---

# Complexity Analysis

| Operation | Average    |
| --------- | ---------- |
| Search    | O(1)       |
| Insert    | O(1)       |
| Delete    | O(1)       |
| Resize    | O(n) Local |

Space Complexity:

```text
O(n)
```

---

# Advantages

* Automatic scalability
* Efficient updates
* Better storage utilization
* Supports changing workloads

---

# Limitations

* More implementation complexity
* Metadata overhead
* Expansion management cost

---

# Applications

* Database systems
* Storage engines
* Distributed indexing
* Cloud infrastructure
* Dynamic caches

---

# Comparison

| Method             | Growth          |
| ------------------ | --------------- |
| Static Hashing     | Fixed           |
| Dynamic Hashing    | Adaptive        |
| Linear Hashing     | Incremental     |
| Extendible Hashing | Directory-Based |

---

# Conclusion

Dynamic Hashing maintains efficient lookup performance by adapting storage structures automatically as datasets evolve. Its flexibility and scalability make it valuable for modern data-intensive systems.
