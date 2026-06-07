# Separate Chaining Search

> Separate Chaining Search is a collision-resolution technique in hash tables where each bucket stores a collection of elements, typically using a linked list, allowing multiple keys to occupy the same hash location.

---

# Table of Contents

1. Introduction
2. Why Separate Chaining Exists
3. Definition
4. Core Idea
5. Mathematical Foundation
6. Data Structure Layout
7. Search Algorithm
8. Example Walkthrough
9. Complexity Analysis
10. Load Factor Analysis
11. Advantages
12. Disadvantages
13. Real-World Applications
14. Comparison with Open Addressing
15. Interview Questions
16. Summary

---

# Introduction

Hash tables aim for O(1) lookup.

However, collisions are unavoidable.

Two different keys may generate the same hash value.

Separate Chaining solves this problem by allowing multiple elements to be stored in the same bucket.

---

# Why Separate Chaining Exists

Suppose:

h(25) = 5

h(35) = 5

h(45) = 5

All three keys map to index 5.

Without collision handling:

```text
Impossible to store all keys
```

Separate chaining solves this issue.

---

# Definition

Separate Chaining is a collision resolution technique in which each hash table slot stores a collection of entries instead of a single entry.

Typically:

```text
Bucket
   ↓
Linked List
```

or

```text
Bucket
   ↓
Dynamic Array
```

---

# Core Idea

Instead of:

```text
Bucket 5
    ↓
Single Item
```

Store:

```text
Bucket 5
    ↓
[25] → [35] → [45]
```

Multiple keys coexist in the same bucket.

---

# Mathematical Foundation

Hash function:

h(k)

maps keys to buckets.

Load Factor:

```
α = n / m
```

Where:

- n = number of elements
- m = number of buckets

Example:

100 elements

20 buckets

```
α = 100 / 20 = 5
```

Average chain length = 5.

---

# Data Structure Layout

Example:

```text
Index

0 → NULL

1 → [11]

2 → [22] → [42]

3 → NULL

4 → [14]

5 → [25] → [35] → [45]
```

Each bucket maintains its own chain.

---

# Search Algorithm

Step 1

Compute hash value.

Step 2

Locate bucket.

Step 3

Traverse chain.

Step 4

Compare keys.

Step 5

Return result if found.

---

Pseudo Code

```text
SEARCH(key)

index = HASH(key)

current = bucket[index]

while current != NULL

    if current.key == key
        return current.value

    current = current.next

return NOT_FOUND
```

---

# Example Walkthrough

Hash Function:

h(k) = k mod 10

Stored Data:

25

35

45

Hashes:

25 mod 10 = 5

35 mod 10 = 5

45 mod 10 = 5

Bucket:

```text
5

[25] → [35] → [45]
```

Searching 45:

1. Compute hash

   h(45) = 5

2. Go to bucket 5

3. Traverse:

   25

   35

   45

4. Found

---

# Complexity Analysis

## Best Case

O(1)

Element appears first.

---

## Average Case

O(1 + α)

where:

α = load factor

---

## Worst Case

O(n)

All elements fall into one bucket.

---

# Complexity Table

| Case | Complexity |
|--------|-------------|
| Best | O(1) |
| Average | O(1 + α) |
| Worst | O(n) |

---

# Space Complexity

Hash Table:

O(m)

Stored Elements:

O(n)

Total:

O(n + m)

---

# Load Factor Analysis

Load factor:

```
α = n / m
```

Low α:

```text
Short chains
Fast search
```

High α:

```text
Long chains
Slow search
```

Performance strongly depends on load factor.

---

# Advantages

## Simple Design

Easy to implement.

## Easy Deletion

No shifting required.

## Flexible Capacity

Can store more elements than buckets.

## High Load Factors

Performs reasonably well even when heavily loaded.

---

# Disadvantages

## Extra Memory

Pointers require additional storage.

## Poor Cache Locality

Linked lists scatter memory.

## Worst Case O(n)

Heavy collisions degrade performance.

---

# Real-World Applications

## Java HashMap

Historically used linked-list chaining.

Modern versions may switch to trees.

---

## Database Hash Indexes

Bucket chains store records.

---

## Symbol Tables

Compiler implementations.

---

## File Systems

Metadata lookup.

---

## Distributed Systems

Bucket-based indexing structures.

---

# Comparison with Open Addressing

| Feature | Chaining | Open Addressing |
|-----------|-----------|----------------|
| Extra Memory | Yes | No |
| Cache Locality | Poor | Better |
| Deletion | Easy | Hard |
| High Load Factors | Better | Worse |
| Implementation | Simple | More Complex |

---

# Interview Questions

### Easy

1. What is separate chaining?

2. Why are chains needed?

### Medium

3. Explain load factor.

4. Why is average complexity O(1 + α)?

### Advanced

5. Compare chaining and open addressing.

6. Why does cache locality matter?

---

# Summary

Separate Chaining Search is one of the most widely used collision-resolution techniques in hash tables. By storing multiple elements within the same bucket using chains, it provides a simple, flexible, and practical solution to collision handling while maintaining near constant-time average lookup performance.
