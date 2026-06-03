# Block Search

Block Search is an indexed searching technique that divides data into multiple blocks and uses block-level information to locate the target efficiently before performing a local search.

Instead of scanning the entire dataset, the algorithm identifies the appropriate block and searches only inside that section.

This method reduces unnecessary comparisons and improves search performance for large datasets.

---

## Table of Contents

* Introduction
* Idea Behind Block Search
* Algorithm Workflow
* Example
* Complexity Analysis
* Advantages
* Limitations
* Applications
* Comparison with Other Algorithms
* Conclusion

---

# Introduction

Searching large datasets sequentially is inefficient.

Block Search organizes data into logical groups:

```text
Block 1
Block 2
Block 3
```

Search proceeds in two stages:

```text
Find Block
     ↓
Search Inside Block
```

---

# Idea Behind Block Search

Data is divided into equal or variable-sized blocks.

Each block maintains:

* Block boundary
* Representative value
* Storage reference

Search process:

```text
Search Metadata
      ↓
Identify Block
      ↓
Local Search
```

---

# Algorithm Workflow

```text
Input Data
     ↓
Divide Into Blocks
     ↓
Locate Block
     ↓
Search Block
     ↓
Return Result
```

---

# Example

Dataset:

```text
[4, 8, 12, 16, 20, 24, 28, 32]
```

Blocks:

```text
Block A → [4,8]
Block B → [12,16]
Block C → [20,24]
Block D → [28,32]
```

Search:

```text
Target = 24
```

Execution:

```text
Locate Block C
↓
Search Inside Block
↓
Return Result
```

---

# Complexity Analysis

Assuming balanced blocks:

| Case    | Complexity |
| ------- | ---------- |
| Best    | O(1)       |
| Average | O(√n)      |
| Worst   | O(n)       |

Space Complexity:

```text
O(k)
```

Where:

* `k` = block metadata size

---

# Advantages

* Faster than sequential scanning
* Suitable for large datasets
* Supports indexed retrieval
* Reduces unnecessary comparisons

---

# Limitations

* Requires block organization
* Additional metadata storage
* Updates may affect block structure

---

# Applications

* File systems
* Database indexing
* Data warehouses
* Sequential access storage
* Large record management

---

# Comparison

| Algorithm     | Average Time |
| ------------- | ------------ |
| Linear Search | O(n)         |
| Block Search  | O(√n)        |
| Binary Search | O(log n)     |

---

# Conclusion

Block Search improves lookup efficiency by dividing datasets into manageable regions and limiting detailed searching to only relevant blocks. It is a foundational indexed searching technique used in storage and retrieval systems.
