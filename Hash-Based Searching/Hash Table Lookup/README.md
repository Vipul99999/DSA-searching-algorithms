# Hash Table Lookup

> Hash Table Lookup is the fundamental search operation in a hash table where a key is transformed into a memory location using a hash function, allowing direct access to stored data.

---

# Table of Contents

1. Introduction
2. Definition
3. Core Concept
4. Mathematical Foundation
5. Working Principle
6. Lookup Algorithm
7. Example Walkthrough
8. Complexity Analysis
9. Best, Average, and Worst Cases
10. Advantages
11. Disadvantages
12. Real-World Applications
13. Implementation Considerations
14. Comparison with Other Searches
15. Interview Questions
16. Summary

---

# Introduction

Hash Table Lookup is one of the fastest searching techniques in computer science.

Instead of examining multiple elements, the search operation computes the location of an element directly using a hash function.

The lookup process is the primary reason hash tables are widely used in:

- Databases
- Compilers
- Operating Systems
- Networking
- Web Applications
- AI Systems

---

# Definition

Hash Table Lookup is a search operation that uses a hash function to calculate the storage location of a key and retrieves the associated value directly.

Formally:

Lookup(Key)

returns

Value

by computing:

h(Key)

where:

- h = hash function
- Key = search key

---

# Core Concept

Traditional Search:

```text
Search Key
    ↓
Check Element 1
    ↓
Check Element 2
    ↓
Check Element 3
    ↓
Found
```

Hash Table Lookup:

```text
Search Key
    ↓
Hash Function
    ↓
Memory Address
    ↓
Found
```

Direct access eliminates most searching overhead.

---

# Mathematical Foundation

A hash function maps keys to table indices.

General form:

h(k)

Example:

h(k) = k mod m

Where:

- k = key
- m = table size

Example:

h(47) = 47 mod 10 = 7

Store key at index 7.

Searching:

h(47)

→ 7

Check table[7].

---

# Working Principle

Step 1

Receive search key.

Step 2

Compute hash value.

Step 3

Access calculated index.

Step 4

Verify key.

Step 5

Return value if found.

---

# Lookup Algorithm

Pseudo Code:

```text
LOOKUP(key)

index = HASH(key)

if table[index].key == key
    return table[index].value

return NOT_FOUND
```

---

# Example Walkthrough

Hash Function:

h(k) = k mod 10

Stored Data:

| Key | Value |
|------|--------|
| 25 | Alice |
| 32 | Bob |
| 48 | Carol |

Locations:

| Key | Hash | Index |
|------|--------|--------|
| 25 | 5 | 5 |
| 32 | 2 | 2 |
| 48 | 8 | 8 |

Searching Key = 32

Step 1:

h(32)

Step 2:

32 mod 10 = 2

Step 3:

Access table[2]

Result:

Bob

---

# Complexity Analysis

## Best Case

O(1)

Direct access.

---

## Average Case

O(1)

Assuming:

- Good hash function
- Uniform distribution
- Low load factor

---

## Worst Case

O(n)

Occurs when many keys collide.

---

# Best, Average, and Worst Cases

| Case | Complexity |
|--------|-------------|
| Best | O(1) |
| Average | O(1) |
| Worst | O(n) |

---

# Space Complexity

| Scenario | Complexity |
|-----------|------------|
| Storage | O(n) |

---

# Advantages

## Extremely Fast

Near constant-time retrieval.

## Simple

Easy implementation.

## Scalable

Handles millions of records efficiently.

## Dynamic

Supports insertion and deletion efficiently.

---

# Disadvantages

## Collisions

Multiple keys may map to same index.

## No Ordering

Cannot perform efficient range queries.

## Memory Usage

Requires preallocated table.

---

# Real-World Applications

## Databases

Primary-key lookup.

Example:

Customer ID → Customer Record

---

## Web Applications

Session retrieval.

Example:

Session Token → User Session

---

## Operating Systems

Page table entries.

---

## Compilers

Symbol table lookup.

Variable name → Metadata

---

## Networking

IP routing caches.

DNS lookup caches.

---

## AI Systems

Embedding retrieval.

Feature indexing.

---

# Implementation Considerations

A good lookup performance depends on:

- Quality hash function
- Table size
- Collision resolution strategy
- Load factor management

---

# Comparison with Other Searches

| Algorithm | Average Search |
|------------|---------------|
| Linear Search | O(n) |
| Binary Search | O(log n) |
| BST Search | O(log n) |
| AVL Tree Search | O(log n) |
| Hash Table Lookup | O(1) |

---

# Interview Questions

### Easy

1. What is a hash table lookup?
2. What is a hash function?

### Medium

3. Why is lookup O(1)?
4. What causes lookup degradation?

### Advanced

5. How does load factor affect lookup?
6. How do collisions impact performance?

---

# Summary

Hash Table Lookup is the foundational operation of hash-based searching. By converting keys directly into storage locations through hashing, it provides near constant-time retrieval, making it one of the fastest search techniques used in modern software systems.
