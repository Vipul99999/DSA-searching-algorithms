# Extendible Hashing

> Extendible Hashing is a Dynamic Hashing technique that uses a directory of pointers and bucket splitting to support efficient growth while maintaining near O(1) search performance.

---

# Table of Contents

1. Introduction
2. Definition
3. Motivation
4. Core Components
5. Global Depth
6. Local Depth
7. Directory Structure
8. Search Algorithm
9. Insertion Algorithm
10. Bucket Splitting
11. Directory Doubling
12. Example Walkthrough
13. Complexity Analysis
14. Advantages
15. Disadvantages
16. Real-World Applications
17. Interview Questions
18. Summary

---

# Introduction

Extendible Hashing was designed to solve the growth problem of traditional hash tables.

Instead of rebuilding:

```text
Entire Table
```

it expands only where necessary.

---

# Definition

Extendible Hashing is a Dynamic Hashing technique that uses:

- Directory
- Global Depth
- Local Depth
- Bucket Splitting

to dynamically manage data growth.

---

# Motivation

Traditional Hashing:

```text
Bucket Full
 ↓
Resize Entire Table
```

Extendible Hashing:

```text
Bucket Full
 ↓
Split Bucket
```

Much cheaper.

---

# Core Components

## Directory

Array of pointers.

---

## Buckets

Store records.

---

## Global Depth

Number of bits used by directory.

---

## Local Depth

Number of bits identifying a bucket.

---

# Global Depth

Example:

```text
Global Depth = 2
```

Directory:

```text
00
01
10
11
```

Four entries.

---

# Local Depth

Indicates how many bits determine bucket membership.

Example:

```text
Local Depth = 1
```

Bucket identified by:

```text
0*
```

or

```text
1*
```

---

# Directory Structure

Example:

```text
00 → Bucket A
01 → Bucket B
10 → Bucket A
11 → Bucket C
```

Multiple directory entries may point to same bucket.

---

# Search Algorithm

```text
SEARCH(key)

Hash key

Extract bits

Follow directory pointer

Search bucket
```

---

# Insertion Algorithm

```text
INSERT(key)

Locate bucket

If bucket not full

    Insert

Else

    Split bucket

    If needed

        Double directory
```

---

# Bucket Splitting

Example:

```text
Bucket A full
```

Split into:

```text
Bucket A
Bucket D
```

Redistribute records.

---

# Directory Doubling

When:

```text
Local Depth
=
Global Depth
```

and split occurs:

```text
Double directory size
```

Example:

```text
2 entries
 ↓
4 entries
 ↓
8 entries
```

---

# Example Walkthrough

Global Depth:

```text
2
```

Directory:

```text
00
01
10
11
```

Bucket:

```text
01
```

becomes full.

Split:

```text
01
101
```

Update pointers.

Continue insertion.

---

# Complexity Analysis

| Operation | Complexity |
|------------|------------|
| Search | O(1) |
| Insert | O(1) Avg |
| Delete | O(1) Avg |
| Split | O(B) |

B = bucket size

---

# Advantages

## Incremental Growth

No full rebuild.

---

## Fast Searches

Near constant time.

---

## Efficient Storage

Buckets split only when necessary.

---

## Database Friendly

Excellent disk behavior.

---

# Disadvantages

## Directory Overhead

Additional memory.

---

## Complex Implementation

More difficult than standard hashing.

---

## Pointer Management

Requires maintenance.

---

# Real-World Applications

## Database Systems

Dynamic indexing.

---

## DBMS Storage Engines

Hash-based access methods.

---

## Distributed Databases

Scalable storage.

---

## Large File Systems

Efficient record lookup.

---

# Interview Questions

1. What is Extendible Hashing?
2. What is Global Depth?
3. What is Local Depth?
4. Why is directory doubling needed?
5. How does bucket splitting work?

---

# Summary

Extendible Hashing is one of the most important Dynamic Hashing techniques. By combining directories, bucket splitting, and adaptive growth, it provides scalable near O(1) search performance and forms the basis of many database indexing systems.
