# Indexed Sequential Search

Indexed Sequential Search is an indexed searching technique that combines **direct index lookup** with **sequential traversal** to achieve efficient searching in ordered datasets.

Instead of scanning every record, the algorithm first searches a lightweight index to locate the approximate region where the target exists and then performs sequential searching only inside that region.

This approach balances **fast retrieval**, **low memory overhead**, and **sequential storage efficiency**, making it widely used in file organization and indexed storage systems.

---

## Table of Contents

* Introduction
* Motivation
* Core Idea
* Components
* Search Workflow
* Example
* Complexity Analysis
* Advantages
* Limitations
* Applications
* Comparison
* Conclusion

---

# Introduction

Sequential searching becomes inefficient for large datasets.

Binary search improves performance but often assumes direct random access.

Indexed Sequential Search introduces an intermediate structure:

```text
Search Index
     ↓
Locate Segment
     ↓
Sequential Scan
```

This reduces the amount of data examined.

---

# Motivation

Searching every record:

```text
5 → 12 → 18 → 25 → 31 → 40 → ...
```

Indexed Sequential Search:

```text
Search Index
↓
Locate Region
↓
Sequential Search
```

The objective is to reduce search cost while preserving ordered storage.

---

# Core Idea

Data is divided into segments.

Each segment has:

* Representative key
* Pointer/reference
* Data region

Example:

Dataset:

```text
[10,20,30,40,50,60,70,80]
```

Index:

| Key | Segment |
| --- | ------- |
| 10  | A       |
| 50  | B       |

Searching:

```text
Target = 60
```

Process:

```text
Locate Segment B
↓
Sequential Search
↓
Return Result
```

---

# Components

## Data File

Stores original ordered records.

---

## Index File

Stores references to record regions.

---

## Sequential Access

Performs local searching after locating the target area.

---

# Search Workflow

```text
Input Key
    ↓
Search Index
    ↓
Find Segment
    ↓
Sequential Scan
    ↓
Return Match
```

---

# Example

Dataset:

```text
[4,8,12,16,20,24,28,32]
```

Index:

```text
4  → Segment A
20 → Segment B
```

Search:

```text
Target = 24
```

Execution:

```text
Search Index
↓
Locate Segment B
↓
Scan [20,24,28]
↓
Found
```

---

# Complexity Analysis

| Case    | Complexity      |
| ------- | --------------- |
| Best    | O(1)            |
| Average | O(log n) + O(k) |
| Worst   | O(n)            |

Where:

* `k` = size of selected segment

Space Complexity:

```text
O(m)
```

where:

* `m` = number of index entries

---

# Advantages

* Faster than pure sequential search
* Low index storage cost
* Efficient for ordered files
* Supports large datasets
* Simple structure

---

# Limitations

* Requires maintaining index
* Updates may require reorganization
* Performance depends on segment quality

---

# Applications

* Indexed file systems
* Database storage
* Record management
* Sequential data retrieval
* Archive systems

---

# Comparison

| Technique                 | Average Time  |
| ------------------------- | ------------- |
| Linear Search             | O(n)          |
| Indexed Sequential Search | O(log n)+O(k) |
| Binary Search             | O(log n)      |

---

# Conclusion

Indexed Sequential Search combines index-based navigation with sequential access to reduce search overhead while preserving efficient storage organization. It remains an important technique in file indexing and large-scale record retrieval systems.
