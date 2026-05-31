# ⚡ Divide-and-Conquer Searching

<div align="center">

# Divide-and-Conquer Search Algorithms

A family of efficient searching algorithms that repeatedly divide the search space into smaller subproblems until the target element is found.

---

### Category

Searching Algorithms → Divide-and-Conquer Searching

### Difficulty

🟡 Intermediate → 🔴 Advanced

### Implementations

C • C++ • Java • Python • JavaScript

</div>

---

# 📖 Overview

Divide-and-Conquer Searching is a class of searching algorithms that significantly improves upon linear scanning by repeatedly reducing the search space.

Instead of examining every element:

```text
Search Entire Dataset
        ↓
Divide Dataset
        ↓
Choose Relevant Portion
        ↓
Repeat
```

Most divide-and-conquer searches achieve:

```text
O(log n)
```

time complexity, making them dramatically faster than:

```text
O(n)
```

linear searches for large datasets.

---

# 🎯 Core Idea

The Divide-and-Conquer paradigm consists of three steps:

## Divide

Split the problem into smaller subproblems.

---

## Conquer

Solve the relevant subproblem.

---

## Combine

Return the final result.

---

For searching:

```text
Search Space
      ↓
Divide
      ↓
Discard Half (or More)
      ↓
Repeat
```

---

# 🧠 Why It Works

Suppose:

```text
n = 1,000,000
```

elements.

---

Linear Search:

```text
Worst Case

1,000,000 comparisons
```

---

Binary Search:

```text
log₂(1,000,000)

≈ 20 comparisons
```

---

The improvement is enormous.

```text
1,000,000
      ↓
20
```

---

# 🔬 Search Space Reduction

Example:

```text
[1 2 3 4 5 6 7 8 9 10]
```

Target:

```text
8
```

---

First division:

```text
[1 2 3 4 5] | [6 7 8 9 10]
```

Discard left half.

---

Second division:

```text
[6 7] | [8 9 10]
```

Discard left portion.

---

Third division:

```text
[8] | [9 10]
```

Target found.

---

# 📂 Algorithms Covered

```text
Divide-and-Conquer Searching
│
├── Binary Search
│   │
│   ├── Iterative Binary Search
│   ├── Recursive Binary Search
│   ├── Lower Bound Search
│   ├── Upper Bound Search
│   ├── First Occurrence Search
│   ├── Last Occurrence Search
│   ├── Search Insert Position
│   ├── Peak Element Search
│   ├── Rotated Array Search
│   └── Binary Search on Answer
│
├── Ternary Search
│   │
│   ├── Iterative Ternary Search
│   ├── Recursive Ternary Search
│   └── Unimodal Function Search
│
└── Fractional Cascading Search
```

---

# 1️⃣ Binary Search Family

## Overview

Binary Search repeatedly divides a sorted search space into two halves.

---

## Principle

```text
Middle Element
       │
       ▼
Compare
       │
 ┌─────┼─────┐
 │     │     │
 ▼     ▼     ▼

<     =     >

Left Found Right
```

---

## Complexity

| Case              | Complexity |
| ----------------- | ---------- |
| Best              | O(1)       |
| Average           | O(log n)   |
| Worst             | O(log n)   |
| Space (Iterative) | O(1)       |
| Space (Recursive) | O(log n)   |

---

## Variants

### Iterative Binary Search

Loop-based implementation.

---

### Recursive Binary Search

Uses recursion.

---

### Lower Bound Search

Find first element:

```text
≥ target
```

---

### Upper Bound Search

Find first element:

```text
> target
```

---

### First Occurrence Search

For duplicates.

---

### Last Occurrence Search

For duplicates.

---

### Search Insert Position

Determine insertion index.

---

### Peak Element Search

Find local maximum.

---

### Rotated Array Search

Search rotated sorted arrays.

---

### Binary Search on Answer

Search solution space instead of data.

Popular in competitive programming.

---

# 2️⃣ Ternary Search Family

## Overview

Ternary Search divides the search space into three regions.

Instead of one midpoint:

```text
mid1
mid2
```

are used.

---

## Principle

```text
Left | Mid1 | Middle | Mid2 | Right
```

---

## Complexity

```text
O(log₃ n)
```

Although fewer levels exist, more comparisons occur per level.

---

## Variants

### Iterative Ternary Search

Loop-based implementation.

---

### Recursive Ternary Search

Recursive implementation.

---

### Unimodal Function Search

Used in optimization problems.

Find:

```text
Maximum
or
Minimum
```

of unimodal functions.

---

# 3️⃣ Fractional Cascading Search

## Overview

Fractional Cascading is an advanced searching technique used when multiple related searches must be performed across several sorted lists.

---

Instead of:

```text
k separate binary searches
```

Fractional Cascading reuses previous search information.

---

## Goal

Reduce:

```text
k × O(log n)
```

to approximately:

```text
O(log n + k)
```

---

## Applications

* Computational Geometry
* Spatial Indexing
* GIS Systems
* Database Engines
* Graphics Pipelines

---

# 📊 Complexity Comparison

| Algorithm            | Best         | Average      | Worst        |
| -------------------- | ------------ | ------------ | ------------ |
| Linear Search        | O(1)         | O(n)         | O(n)         |
| Binary Search        | O(1)         | O(log n)     | O(log n)     |
| Ternary Search       | O(1)         | O(log₃ n)    | O(log₃ n)    |
| Fractional Cascading | O(log n + k) | O(log n + k) | O(log n + k) |

---

# 📈 Visual Comparison

For:

```text
1,000,000 elements
```

Approximate comparisons:

| Algorithm            | Comparisons  |
| -------------------- | ------------ |
| Linear Search        | 1,000,000    |
| Binary Search        | 20           |
| Ternary Search       | 13           |
| Fractional Cascading | Depends on k |

---

# 🌎 Real-World Applications

## Databases

Searching indexed records.

---

## Search Engines

Document retrieval.

---

## Operating Systems

Process lookup.

---

## Compilers

Symbol table lookup.

---

## Scientific Computing

Large dataset searches.

---

## Geographic Information Systems

Spatial searching.

---

## Machine Learning

Hyperparameter optimization.

---

## Competitive Programming

Optimization and search-answer problems.

---

# 🔬 Binary Search on Answer

One of the most important modern applications.

Instead of searching data:

```text
Search Solution Space
```

Example:

```text
Minimum speed
Maximum capacity
Minimum time
Optimal answer
```

---

Typical workflow:

```text
Answer Space
      ↓
Binary Search
      ↓
Check Feasibility
      ↓
Adjust Bounds
```

---

# ⚖️ Comparison With Sequential Searching

| Feature                   | Sequential Search | Divide-and-Conquer Search |
| ------------------------- | ----------------- | ------------------------- |
| Sorted Data Required      | No                | Usually Yes               |
| Average Complexity        | O(n)              | O(log n)                  |
| Large Dataset Performance | Poor              | Excellent                 |
| Implementation Simplicity | Very Easy         | Moderate                  |
| Memory Usage              | Low               | Low                       |
| Scalability               | Limited           | Excellent                 |

---

# ✅ Advantages

## Extremely Fast

Search space shrinks exponentially.

---

## Scales Well

Handles millions and billions of records.

---

## Foundation For Advanced Algorithms

Many advanced data structures rely on binary search principles.

---

## Widely Used

Appears in nearly every software system.

---

## Supports Optimization Problems

Binary Search on Answer is extremely powerful.

---

# ❌ Disadvantages

## Usually Requires Sorted Data

Many divide-and-conquer searches assume ordering.

---

## More Complex

Harder than Linear Search.

---

## Incorrect Boundaries Cause Bugs

Off-by-one errors are common.

---

## Some Variants Require Additional Structures

Example:

```text
Fractional Cascading
```

---

# 🧪 Edge Cases

Always test:

* Empty arrays
* Single-element arrays
* Duplicate values
* Missing targets
* Boundary values
* Large datasets
* Rotated arrays
* Overflow-prone indices

---

# 🔍 Common Binary Search Bug

Avoid:

```text
mid = (left + right) / 2
```

Potential overflow.

Prefer:

```text
mid = left + (right - left) / 2
```

---

# 📚 Relationship To Other Searching Categories

```text
Searching Algorithms
│
├── Sequential Searching
│
├── Divide-and-Conquer Searching
│   │
│   ├── Binary Search
│   ├── Ternary Search
│   └── Fractional Cascading
│
├── Indexed Searching
├── Distribution-Based Searching
├── Exponential Searching
├── Tree-Based Searching
└── Hash-Based Searching
```

---

# 🎓 Interview Questions

### Easy

* What is Divide-and-Conquer?
* How does Binary Search work?

---

### Medium

* Compare Binary Search and Ternary Search.
* Explain Lower Bound and Upper Bound.

---

### Advanced

* What is Binary Search on Answer?
* Explain Fractional Cascading.
* Why is Binary Search considered logarithmic?

---

# 🚀 Next Algorithms

Continue with:

```text
Binary Search
│
├── Iterative Binary Search
├── Recursive Binary Search
├── Lower Bound Search
├── Upper Bound Search
├── First Occurrence Search
├── Last Occurrence Search
├── Search Insert Position
├── Peak Element Search
├── Rotated Array Search
└── Binary Search on Answer
```

These form the foundation of modern searching and optimization techniques.

---

# 📜 License

Released under the MIT License.

Free for learning, research, education, and production use.
