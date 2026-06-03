# Indexed Searching

Indexed Searching is an efficient searching technique that accelerates data retrieval by maintaining an **auxiliary index structure** that points to locations of actual data.

Instead of examining every element one by one, the search process first consults the index to determine **where the desired data may exist**, then performs a localized search only within that region.

This reduces unnecessary comparisons and improves performance, especially for **large, ordered, or disk-based datasets**.

---

## Table of Contents

* Introduction
* Problem with Sequential Searching
* What is an Index?
* How Indexed Searching Works
* Search Workflow
* Example
* Time Complexity
* Space Complexity
* Advantages
* Limitations
* Real-World Applications
* Comparison with Other Searching Techniques
* Implementation Notes
* Conclusion

---

# Introduction

Searching is one of the most fundamental operations in computer science.

A traditional linear search scans every element until the target is found.

For small datasets this approach is acceptable, but as data grows, sequential scanning becomes inefficient.

Indexed Searching addresses this limitation by introducing an additional data structure called an **index**, which stores references to locations in the original dataset.

The index acts as a guide that allows the search algorithm to jump closer to the target instead of traversing the entire collection.

---

# Problem with Sequential Searching

Consider the following ordered dataset:

```
[5, 12, 18, 24, 31, 38, 44, 51, 63, 79]
```

Searching for `63` using linear search:

```
5 → 12 → 18 → 24 → 31 → 38 → 44 → 51 → 63
```

Number of comparisons:

```
9 comparisons
```

As dataset size increases, search cost increases linearly.

This becomes expensive for:

* Large files
* Databases
* Search engines
* Distributed systems

---

# What is an Index?

An index is a smaller lookup structure built over the original data.

It stores:

* Representative keys
* Data positions
* References to storage blocks

Example:

Original Data:

```
[5, 12, 18, 24, 31, 38, 44, 51, 63, 79]
```

Index:

| Key | Points To  |
| --- | ---------- |
| 5   | Position 0 |
| 31  | Position 4 |
| 63  | Position 8 |

Instead of searching all records:

```
Search Index
      ↓
Locate Region
      ↓
Search Target Region
```

---

# How Indexed Searching Works

Indexed Searching generally follows four stages:

### 1. Build Index

Create an index from the original dataset.

Example:

```
Index:
5 → Block A
31 → Block B
63 → Block C
```

---

### 2. Search Index

Locate the block containing the target.

Searching:

```
Target = 44
```

Search result:

```
Block B
```

---

### 3. Access Data Region

Move directly to the identified section.

---

### 4. Perform Local Search

Search only inside the selected block.

Final result:

```
Target Found
```

---

# Search Workflow

```
User Query
    ↓
Search Index
    ↓
Find Candidate Location
    ↓
Access Data
    ↓
Return Result
```

---

# Example

Dataset:

```
[10, 20, 30, 40, 50, 60, 70, 80]
```

Index:

```
10 → Block 1
50 → Block 2
```

Search:

```
Target = 70
```

Execution:

```
Step 1 → Search Index
Step 2 → Move to Block 2
Step 3 → Search Block
Step 4 → Return 70
```

---

# Time Complexity

The exact complexity depends on index design.

| Operation      | Complexity        |
| -------------- | ----------------- |
| Index Lookup   | O(log n)          |
| Local Search   | O(1) – O(√n)      |
| Overall Search | O(log n) to O(√n) |
| Worst Case     | O(n)              |

---

# Space Complexity

```
O(k)
```

Where:

* `k` = size of index

Extra memory is required to store references.

---

# Advantages

* Faster than full sequential scanning
* Reduces disk I/O operations
* Efficient for large datasets
* Supports scalable data retrieval
* Improves database performance
* Enables near real-time lookup

---

# Limitations

* Requires additional storage
* Index creation introduces overhead
* Updates may require rebuilding indexes
* Less beneficial for very small datasets

---

# Real-World Applications

### Databases

Indexes accelerate query execution.

Example:

```sql
SELECT * FROM users WHERE id = 100;
```

---

### Search Engines

Keywords point directly to documents.

---

### File Systems

Operating systems maintain indexes for fast file access.

---

### Data Warehousing

Large analytical datasets rely heavily on indexing.

---

### Cloud Storage

Distributed systems maintain indexes for object retrieval.

---

# Comparison with Other Searching Techniques

| Technique      | Time                    | Requires Sorting |
| -------------- | ----------------------- | ---------------- |
| Linear Search  | O(n)                    | No               |
| Binary Search  | O(log n)                | Yes              |
| Indexed Search | O(log n) + Local Search | Usually          |
| Hash Search    | O(1) Average            | No               |

---

# Implementation Notes

A good indexed search system should:

* Minimize index size
* Reduce lookup depth
* Support fast updates
* Balance memory usage
* Avoid excessive block scanning

---

# Conclusion

Indexed Searching improves retrieval efficiency by introducing a structured lookup layer between the user query and the actual dataset.

Rather than scanning everything, the algorithm narrows the search space first and then performs targeted access.

This principle powers modern databases, search engines, storage systems, and large-scale information retrieval platforms.
