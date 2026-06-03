# Hash Table Search

Hash Table Search is a searching technique that retrieves data by transforming a search key into a storage location using a **hash function**.

Instead of traversing records sequentially or searching through ordered structures, hash tables compute the target position directly and perform retrieval with near constant-time complexity.

Hash tables are widely used in **databases, caches, compilers, operating systems, distributed systems, and high-performance applications**.

---

## Table of Contents

* Introduction
* Motivation
* Core Idea
* Components
* Search Workflow
* Collision Handling
* Example
* Complexity Analysis
* Advantages
* Limitations
* Applications
* Comparison
* Conclusion

---

# Introduction

Searching traditionally requires scanning or navigating through data structures.

Hash tables use direct addressing:

```text id="5m0r7h"
Search Key
     ↓
Hash Function
     ↓
Array Index
     ↓
Retrieve Data
```

This minimizes search time.

---

# Motivation

Traditional searching:

```text id="2smqqr"
A → B → C → D → E
```

Hash table search:

```text id="4lz4c5"
Hash(Key)
↓
Index
↓
Result
```

The objective is rapid lookup.

---

# Core Idea

Keys are converted into positions.

Example:

```text id="7twgc0"
Hash(45)=5
```

Table:

| Index | Value      |
| ----- | ---------- |
| 5     | Record(45) |

Searching:

```text id="jlwm1g"
Search 45
↓
Compute Hash
↓
Access Position 5
↓
Return Result
```

---

# Components

## Key

Unique lookup value.

Examples:

* User ID
* Email
* Product ID

---

## Hash Function

Maps keys to storage positions.

Example:

```text id="4v4fml"
index = key % size
```

---

## Hash Table

Stores records using computed indexes.

---

# Search Workflow

```text id="a04k14"
Input Key
↓
Hash Function
↓
Locate Bucket
↓
Collision Check
↓
Return Data
```

---

# Collision Handling

Multiple keys may map to the same index.

Example:

```text id="8d2btx"
Hash(A)=4
Hash(B)=4
```

Solutions:

### Separate Chaining

```text id="qgjzxr"
4 → A → B
```

---

### Open Addressing

Methods:

* Linear Probing
* Quadratic Probing
* Double Hashing

---

# Example

Hash Table Size:

```text id="dmthii"
10
```

Insert:

```text id="g1x0mu"
15 → 5
22 → 2
35 → 5
```

Search:

```text id="n9cf1x"
Search 35
↓
Bucket 5
↓
Traverse
↓
Found
```

---

# Complexity Analysis

| Operation | Average | Worst |
| --------- | ------- | ----- |
| Search    | O(1)    | O(n)  |
| Insert    | O(1)    | O(n)  |
| Delete    | O(1)    | O(n)  |

Space Complexity:

```text id="yjlwmk"
O(n)
```

---

# Advantages

* Extremely fast lookup
* Efficient insertion
* Simple implementation
* Scalable for large datasets

---

# Limitations

* Collision overhead
* Memory consumption
* Poor range query performance
* Rehashing cost

---

# Applications

* Database indexing
* Caching
* Symbol tables
* Session storage
* DNS systems
* Authentication systems

---

# Comparison

| Structure     | Search       |
| ------------- | ------------ |
| Array         | O(n)         |
| Binary Search | O(log n)     |
| Hash Table    | O(1) Average |

---

# Conclusion

Hash Table Search provides fast retrieval by converting keys into storage positions through hashing. It remains one of the most widely used searching techniques for high-performance data access systems.
