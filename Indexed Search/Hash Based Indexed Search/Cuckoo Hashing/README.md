# Cuckoo Hashing

Cuckoo Hashing is an advanced hashing technique that guarantees **constant-time lookup performance** by storing each key in one of multiple possible locations determined by independent hash functions.

When collisions occur, existing keys are relocated to their alternative positions instead of forming chains or probing sequences.

This strategy provides highly predictable lookup performance and is widely used in **high-performance storage systems, databases, networking, and memory-efficient indexing structures**.

---

## Table of Contents

* Introduction
* Motivation
* Core Idea
* Components
* Search Workflow
* Insertion Process
* Rehashing
* Example
* Complexity Analysis
* Advantages
* Limitations
* Applications
* Comparison
* Conclusion

---

# Introduction

Traditional hashing handles collisions by:

```text id="b1qg54"
Collision
↓
Chain
```

or

```text id="ykpg6x"
Collision
↓
Probe Next Location
```

Cuckoo Hashing introduces relocation:

```text id="n32jvb"
Insert
↓
Move Existing Key
↓
Insert New Key
```

This enables fast lookups.

---

# Motivation

Standard collision handling can increase search cost.

Cuckoo hashing maintains:

```text id="g2ndes"
Constant Lookup Time
+
Controlled Collision Resolution
```

---

# Core Idea

Each key has multiple candidate positions.

Example:

```text id="0j90rq"
h1(key)
h2(key)
```

Search checks only these locations.

---

# Components

## Hash Functions

Multiple independent functions.

Example:

```text id="smnrmz"
h1(x)
h2(x)
```

---

## Hash Table

Stores records.

---

## Relocation Logic

Moves keys during insertion.

---

# Search Workflow

```text id="xf14n2"
Input Key
↓
Compute h1
↓
Compute h2
↓
Check Locations
↓
Return Result
```

Only limited positions are examined.

---

# Insertion Process

Insert:

```text id="n3o1x4"
Place Key
```

If occupied:

```text id="p2bdq0"
Evict Existing Key
↓
Move To Alternate Position
↓
Repeat
```

Example:

```text id="g23qqm"
Insert A
↓
Insert B
↓
Move A
```

---

# Rehashing

Cycles may occur.

Recovery:

```text id="mhc0r5"
Generate New Hash Functions
↓
Rebuild Table
```

---

# Example

Hash Functions:

```text id="r22vjq"
h1(x)=x mod 7
h2(x)=x mod 5
```

Insert:

```text id="ey5c62"
12
18
24
```

Search:

```text id="6pzwu2"
Compute h1,h2
↓
Check Locations
↓
Found
```

---

# Complexity Analysis

| Operation | Average | Worst |
| --------- | ------- | ----- |
| Search    | O(1)    | O(1)  |
| Insert    | O(1)    | O(n)  |
| Delete    | O(1)    | O(1)  |

Space Complexity:

```text id="e32v0v"
O(n)
```

---

# Advantages

* Constant lookup time
* No linked chains
* Cache friendly
* Deterministic search cost
* High retrieval performance

---

# Limitations

* Complex insertion logic
* Possible rehash operations
* Extra hash computation

---

# Applications

* Database indexing
* High-speed caches
* Networking systems
* Memory-efficient lookup
* Key-value stores

---

# Comparison

| Method          | Collision Handling |
| --------------- | ------------------ |
| Chaining        | Linked Structure   |
| Open Addressing | Probe Sequence     |
| Cuckoo Hashing  | Relocation         |

---

# Conclusion

Cuckoo Hashing improves retrieval performance by resolving collisions through key relocation instead of traversal. This design provides fast and predictable lookups, making it highly suitable for performance-critical systems.
