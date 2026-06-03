# Extendible Hashing

Extendible Hashing is a dynamic hashing technique that allows a hash structure to grow and shrink efficiently without rebuilding the entire table.

Instead of resizing a single large table, Extendible Hashing maintains a **directory of buckets** and expands only the necessary portions when overflow occurs.

This makes it highly efficient for database indexing and dynamic storage systems.

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

Standard hash tables may require expensive resizing.

Extendible Hashing introduces:

```text id="0h4s9w"
Directory
     ↓
Bucket
     ↓
Records
```

Only affected buckets expand.

---

# Motivation

Traditional resizing:

```text id="7fizn0"
Overflow
↓
Rebuild Entire Table
```

Extendible hashing:

```text id="l3i8lf"
Overflow
↓
Split Bucket
↓
Update Directory
```

This improves scalability.

---

# Core Idea

The structure maintains:

* Global Depth
* Local Depth
* Directory
* Buckets

Each bucket stores limited records.

---

# Components

## Directory

Stores bucket references.

---

## Global Depth

Number of bits used for indexing.

Example:

```text id="u5yc7o"
Depth = 2
```

Directory:

```text id="80jjnr"
00
01
10
11
```

---

## Local Depth

Tracks bucket-specific depth.

---

## Buckets

Actual storage units.

---

# Search Workflow

```text id="8k6s9o"
Input Key
↓
Hash Function
↓
Directory Lookup
↓
Locate Bucket
↓
Return Result
```

---

# Bucket Splitting

When overflow occurs:

```text id="d1b3to"
Bucket Full
↓
Increase Local Depth
↓
Split Records
↓
Update Directory
```

If necessary:

```text id="0skgdc"
Increase Global Depth
```

---

# Example

Initial:

```text id="8f5h5i"
Directory Depth = 1
```

Insert:

```text id="3y4o2x"
5
9
13
17
```

Overflow:

```text id="bx5ut0"
Split Bucket
```

Result:

```text id="5ctyvh"
Directory Expanded
```

---

# Complexity Analysis

| Operation | Average |
| --------- | ------- |
| Search    | O(1)    |
| Insert    | O(1)    |
| Delete    | O(1)    |
| Split     | O(n)    |

Space Complexity:

```text id="fg01jc"
O(n)
```

---

# Advantages

* Dynamic growth
* Minimal rehashing
* Efficient updates
* Fast retrieval
* Suitable for databases

---

# Limitations

* Directory overhead
* More complex implementation
* Bucket management cost

---

# Applications

* Database systems
* File indexing
* Storage engines
* Dynamic key-value stores
* Large-scale indexing

---

# Comparison

| Method             | Resize Cost |
| ------------------ | ----------- |
| Static Hashing     | High        |
| Extendible Hashing | Incremental |

---

# Conclusion

Extendible Hashing extends traditional hashing by enabling dynamic expansion through directory-based bucket management. It offers fast access and scalable performance for modern storage and indexing systems.
