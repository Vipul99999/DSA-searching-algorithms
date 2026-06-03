# Basic Indexed Search

Basic Indexed Search is a category of searching techniques that improve lookup efficiency by dividing data into manageable sections and using lightweight indexing or positional jumps to reduce unnecessary comparisons.

Unlike linear search, which scans every element sequentially, Basic Indexed Search narrows the search space before performing the final lookup.

These algorithms are designed for situations where datasets are **ordered, partially indexed, or block organized**, providing better performance while keeping implementation simpler than advanced tree or database indexing systems.

---

## Table of Contents

* Introduction
* Motivation
* Core Idea
* Search Workflow
* Characteristics
* Algorithms Included
* Complexity Analysis
* Comparison with Other Search Techniques
* Applications
* Repository Structure
* Conclusion

---

# Introduction

Searching is one of the most frequent operations in computing systems.

A direct sequential scan becomes increasingly inefficient as dataset size grows.

Basic Indexed Search techniques address this problem by introducing **controlled skipping, block-level access, or lightweight indexing mechanisms** that reduce the number of examined elements.

These methods are commonly used as foundational search approaches before moving to advanced indexing systems.

---

# Motivation

Traditional searching methods face limitations:

* Linear Search examines every element.
* Binary Search requires complete ordering and direct access.
* Advanced indexes may introduce high storage overhead.

Basic Indexed Search offers a balance:

```text
Lower Complexity
        +
Low Memory Usage
        +
Simple Implementation
```

---

# Core Idea

Instead of searching every position:

```text
Data
↓
Locate Candidate Region
↓
Search Smaller Region
↓
Return Result
```

The algorithm first reduces the search area and then performs a localized lookup.

This approach minimizes comparisons while keeping additional storage requirements low.

---

# Search Workflow

```text
Input Dataset
      ↓
Create Logical Sections
      ↓
Locate Candidate Section
      ↓
Search Within Section
      ↓
Return Match
```

---

# Characteristics

* Faster than full sequential scanning
* Suitable for ordered datasets
* Reduces unnecessary comparisons
* Often requires minimal additional memory
* Easier to implement than complex indexing structures

---

# Algorithms Included

## 1. Jump Search

Searches by jumping fixed intervals through sorted data.

Process:

```text
Jump → Jump → Locate Range → Linear Scan
```

Characteristics:

* Works on sorted arrays
* Reduces search iterations
* Balanced between linear and binary search

Typical Complexity:

```text
O(√n)
```

---

## 2. Block Search

Divides data into blocks and searches block metadata first.

Process:

```text
Search Block
      ↓
Search Inside Block
```

Characteristics:

* Suitable for grouped datasets
* Efficient for partial indexing
* Reduces full dataset traversal

Typical Complexity:

```text
O(√n)
```

---

## 3. Indexed Sequential Search

Uses an auxiliary index table pointing to ordered data regions.

Process:

```text
Search Index
      ↓
Locate Segment
      ↓
Sequential Search
```

Characteristics:

* Combines indexing and sequential access
* Common in file organization systems
* Supports large datasets

Typical Complexity:

```text
O(log n) + Local Search
```

---

## 4. Sparse Index Search

Stores indexes only for selected records instead of every record.

Process:

```text
Sparse Index
      ↓
Locate Block
      ↓
Search Records
```

Characteristics:

* Lower memory consumption
* Efficient for large files
* Reduced indexing overhead

Typical Complexity:

```text
O(log n)
```

---

# Complexity Analysis

| Algorithm                 | Best     | Average  | Worst |
| ------------------------- | -------- | -------- | ----- |
| Jump Search               | O(1)     | O(√n)    | O(√n) |
| Block Search              | O(1)     | O(√n)    | O(n)  |
| Indexed Sequential Search | O(log n) | O(log n) | O(n)  |
| Sparse Index Search       | O(log n) | O(log n) | O(n)  |

---

# Comparison with Other Search Techniques

| Technique            | Time           | Extra Space |
| -------------------- | -------------- | ----------- |
| Linear Search        | O(n)           | O(1)        |
| Binary Search        | O(log n)       | O(1)        |
| Basic Indexed Search | O(log n)–O(√n) | Low         |
| Hash Search          | O(1) Average   | Moderate    |

---

# Applications

Basic Indexed Search is commonly used in:

* Database storage systems
* File indexing
* Information retrieval
* Log processing
* Data archival systems
* Search optimization
* Large sequential datasets

---


# Conclusion

Basic Indexed Search represents a family of lightweight indexing techniques that improve retrieval efficiency without the complexity of advanced index structures.

By reducing the amount of data examined during lookup operations, these algorithms provide a practical balance between performance, simplicity, and memory usage, making them valuable building blocks for larger search systems.
