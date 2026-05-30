# 🔎 Sequential / Linear Searching Algorithms

<div align="center">

# Sequential Search Family

The foundation of all searching algorithms.

Simple • Adaptive • Cache Friendly • Universal

---

### Algorithms Covered

Linear Search • Sentinel Linear Search • Self-Organizing Search

Languages: C • C++ • Java • Python • JavaScript

</div>

---

# 📖 Overview

Sequential searching (also called linear searching) is the most fundamental searching technique in computer science.

Unlike indexed or divide-and-conquer searching methods, sequential searching examines elements one by one until the target is found or the search space is exhausted.

Although simple, sequential searching remains highly relevant in modern software systems because:

* It works on unsorted data.
* It requires no preprocessing.
* It has minimal memory overhead.
* It performs well on small datasets.
* It serves as a building block for more advanced search structures.

Many modern systems still use variations of linear searching internally when dealing with:

* Small arrays
* Cache-resident datasets
* Dynamic collections
* Adaptive data structures
* Recently accessed data

---

# 🎯 Learning Objectives

After completing this section, you will understand:

* How sequential searching works
* Why linear search is still useful
* Adaptive searching techniques
* Self-organizing lists
* Search locality optimization
* Cache-aware searching
* Trade-offs compared to binary search
* Real-world applications

---

# 📂 Folder Structure

```text
Sequential-Linear-Searching
│
├── README.md
│
├── Linear-Search
│   ├── README.md
│   ├── LinearSearch.c
│   ├── LinearSearch.cpp
│   ├── LinearSearch.java
│   ├── LinearSearch.py
│   └── LinearSearch.js
│
├── Sentinel-Linear-Search
│   ├── README.md
│   ├── SentinelLinearSearch.c
│   ├── SentinelLinearSearch.cpp
│   ├── SentinelLinearSearch.java
│   ├── SentinelLinearSearch.py
│   └── SentinelLinearSearch.js
│
└── Self-Organizing-Search
    │
    ├── Move-To-Front-Search
    ├── Transpose-Search
    └── Frequency-Count-Search
```

---

# 🧠 Sequential Searching Family

```text
Sequential Searching
│
├── Linear Search
│
├── Sentinel Linear Search
│
└── Self-Organizing Search
    │
    ├── Move-To-Front Search
    ├── Transpose Search
    └── Frequency Count Search
```

---

# 1️⃣ Linear Search

## Idea

Traverse the collection element-by-element until the target is found.

---

## Workflow

```text
Start
  │
  ▼
Compare Current Element
  │
  ├── Match Found
  │       │
  │       ▼
  │    Return Index
  │
  ▼
Move To Next Element
  │
  ▼
End Of Collection?
  │
  ├── No
  │     │
  │     ▼
  │ Continue
  │
  ▼
Return Not Found
```

---

## Complexity

| Case    | Complexity |
| ------- | ---------- |
| Best    | O(1)       |
| Average | O(n)       |
| Worst   | O(n)       |
| Space   | O(1)       |

---

## Advantages

* Extremely simple
* Works on unsorted data
* No preprocessing required
* Constant memory usage
* Easy to implement

---

## Disadvantages

* Slow for large datasets
* Requires scanning elements sequentially
* Not scalable for huge collections

---

## Applications

* Small datasets
* Configuration tables
* Runtime lookup tables
* Embedded systems
* Quick prototyping

---

# 2️⃣ Sentinel Linear Search

## Idea

Eliminates explicit boundary checking by placing the search key at the end of the collection.

This reduces comparison overhead.

---

## Workflow

```text
Insert Sentinel
        │
        ▼
Compare Elements
        │
        ▼
Found?
        │
        ├── Yes
        │
        ▼
Return Position
```

---

## Complexity

| Case    | Complexity |
| ------- | ---------- |
| Best    | O(1)       |
| Average | O(n)       |
| Worst   | O(n)       |
| Space   | O(1)       |

---

## Benefits Over Linear Search

* Fewer comparisons
* Better constant factors
* Faster practical performance
* Cleaner inner loop

---

## Common Usage

* Compiler internals
* Embedded systems
* Performance-critical loops

---

# 3️⃣ Self-Organizing Search

## Idea

Frequently accessed elements are moved closer to the front.

Future searches become faster.

---

## Principle

```text
Frequently Used Items
            │
            ▼
Move Closer To Front
            │
            ▼
Reduce Future Search Cost
```

---

# Why Self-Organizing Lists Work

Real-world data often follows:

### Locality of Reference

Recently accessed items are likely to be accessed again.

### Frequency Locality

Frequently accessed items tend to remain frequently accessed.

Examples:

* Browser history
* Cache entries
* User preferences
* Search suggestions

---

# 3.1 Move-To-Front Search

## Strategy

Whenever an item is found:

```text
Move Item To Front
```

Example:

Before:

```text
A B C D E
```

Search:

```text
D
```

After:

```text
D A B C E
```

---

## Complexity

| Case           | Complexity |
| -------------- | ---------- |
| Search         | O(n)       |
| Reorganization | O(n)       |
| Space          | O(1)       |

---

## Advantages

* Excellent for repeated accesses
* Easy implementation
* Strong theoretical guarantees

---

## Applications

* Caches
* Symbol tables
* Compression algorithms

---

# 3.2 Transpose Search

## Strategy

Swap found element with its predecessor.

Example:

Before:

```text
A B C D E
```

Search:

```text
D
```

After:

```text
A B D C E
```

---

## Characteristics

* Less aggressive than Move-To-Front
* Preserves ordering better
* Gradual adaptation

---

## Applications

* Adaptive dictionaries
* Lookup systems
* Dynamic lists

---

# 3.3 Frequency Count Search

## Strategy

Maintain access frequency counters.

Frequently accessed elements move toward the front.

---

Example

```text
Item      Count

A           2
B           10
C           5
D           1
```

Reordered:

```text
B C A D
```

---

## Advantages

* Approximates optimal ordering
* Excellent for stable access patterns

---

## Applications

* Database buffers
* Search caches
* Query optimization

---

# 📊 Algorithm Comparison

| Algorithm        | Sorted Data Required | Adaptive | Best Case | Worst Case |
| ---------------- | -------------------- | -------- | --------- | ---------- |
| Linear Search    | No                   | No       | O(1)      | O(n)       |
| Sentinel Search  | No                   | No       | O(1)      | O(n)       |
| Move-To-Front    | No                   | Yes      | O(1)      | O(n)       |
| Transpose Search | No                   | Yes      | O(1)      | O(n)       |
| Frequency Count  | No                   | Yes      | O(1)      | O(n)       |

---

# 🌎 Real-World Usage

## Operating Systems

* Process tables
* Resource lists
* Small lookup structures

---

## Databases

* Buffer management
* Cache replacement heuristics
* Small metadata lookups

---

## Compilers

* Symbol table lookups
* Keyword matching
* Token processing

---

## Networking

* Routing caches
* Session lookups
* Packet processing

---

## Web Browsers

* History suggestions
* Recent searches
* URL matching

---

# 🔬 Research Topics

Advanced extensions include:

* Probabilistic Self-Organizing Lists
* Cache-Aware Linear Search
* SIMD Linear Search
* Parallel Linear Search
* GPU Linear Search
* Learned Sequential Search
* Adaptive Locality Search

---

# 🎓 Interview Questions

### Easy

* What is linear search?
* When should linear search be preferred over binary search?
* What is the time complexity?

### Medium

* What is sentinel search?
* Why is sentinel search faster in practice?

### Advanced

* Explain self-organizing lists.
* Compare Move-To-Front and Frequency Count.
* What is locality of reference?

---

# 📚 Further Reading

Recommended topics:

* Binary Search
* Jump Search
* Interpolation Search
* Hash Tables
* Binary Search Trees
* Skip Lists
* Cache-Aware Algorithms

---

# 🚀 Next Category

After mastering Sequential Searching, continue with:

```text
Divide-and-Conquer Searching
│
├── Binary Search
├── Ternary Search
└── Fractional Cascading
```

These algorithms improve search efficiency from:

```text
O(n)
  ↓
O(log n)
```

and form the foundation of modern searching systems.

---

# 📜 License

Released under the MIT License.

Use freely for education, research, and production systems.
