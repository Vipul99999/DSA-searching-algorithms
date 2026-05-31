# 🔍 Binary Search

<div align="center">

# Binary Search Algorithm Family

A logarithmic-time searching technique that repeatedly divides a sorted search space into smaller halves until the target element is found.

---

### Category

Searching Algorithms → Divide-and-Conquer Searching

### Difficulty

🟡 Intermediate

### Implementations

C • C++ • Java • Python • JavaScript

</div>

---

# 📖 Overview

Binary Search is one of the most important algorithms in Computer Science.

Unlike Linear Search, which examines elements one by one, Binary Search eliminates half of the remaining search space after every comparison.

This reduction transforms searching from:

```text
O(n)
````

to:

```text
O(log n)
```

making Binary Search dramatically faster for large datasets.

---

# 🎯 Core Idea

Given a sorted array:

```text
1 3 5 7 9 11 13 15
```

Search for:

```text
9
```

Check the middle element:

```text
7
```

Since:

```text
9 > 7
```

the entire left half can be discarded.

New search space:

```text
9 11 13 15
```

Again check the middle.

Repeat until found.

---

# ⚙️ Algorithm Workflow

```text
Start
  │
  ▼
Find Middle
  │
  ▼
Compare Target
  │
  ├── Equal → Found
  │
  ├── Smaller
  │      │
  │      ▼
  │ Search Left Half
  │
  └── Greater
         │
         ▼
    Search Right Half
```

---

# 🧠 Why Binary Search Is Fast

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

Search Space Shrinking:

```text
1,000,000
500,000
250,000
125,000
62,500
31,250
...
20 comparisons
```

---

# 🔬 Mathematical Foundation

Binary Search repeatedly divides the search space by:

```text
2
```

Therefore:

```text
n / 2^k = 1
```

Solving:

```text
k = log₂(n)
```

Thus:

```text
Time Complexity = O(log n)
```

---

# 📝 Generic Pseudocode

```text
BinarySearch(array, target)

left = 0
right = n - 1

while left <= right

    mid = left + (right - left) / 2

    if array[mid] == target
        return mid

    else if target < array[mid]
        right = mid - 1

    else
        left = mid + 1

return -1
```

---

# 🔍 Example

Array:

```text
10 20 30 40 50 60 70
```

Target:

```text
60
```

---

Step 1

```text
Middle = 40
```

```text
60 > 40
```

Discard left half.

---

Step 2

```text
50 60 70
```

Middle:

```text
60
```

Found.

---

# 📊 Complexity Analysis

Assume:

```text
n = number of elements
```

---

## Best Case

```text
O(1)
```

Target is the middle element.

---

## Average Case

```text
O(log n)
```

---

## Worst Case

```text
O(log n)
```

---

## Space Complexity

Iterative:

```text
O(1)
```

Recursive:

```text
O(log n)
```

---

# 📈 Complexity Table

| Case            | Complexity |
| --------------- | ---------- |
| Best            | O(1)       |
| Average         | O(log n)   |
| Worst           | O(log n)   |
| Iterative Space | O(1)       |
| Recursive Space | O(log n)   |

---

# ⚠️ Prerequisites

Binary Search generally requires:

## Sorted Data

Example:

```text
10 20 30 40 50
```

Valid.

---

Example:

```text
40 10 70 20 50
```

Invalid.

---

Without ordering:

```text
Binary Search fails.
```

---

# 🚨 Common Bug

Avoid:

```cpp
mid = (left + right) / 2;
```

because:

```text
left + right
```

can overflow.

---

Use:

```cpp
mid = left + (right - left) / 2;
```

which is safer.

---

# 📂 Binary Search Family

This repository includes the complete Binary Search family.

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

---

# 1️⃣ Iterative Binary Search

Uses loops.

Advantages:

* Faster
* No recursion overhead
* O(1) extra memory

---

# 2️⃣ Recursive Binary Search

Uses recursion.

Advantages:

* Elegant implementation
* Easy to understand

Disadvantage:

```text
O(log n)
```

stack space.

---

# 3️⃣ Lower Bound Search

Find first element:

```text
>= target
```

Example:

```text
Array:
1 2 4 4 4 7

Target:
4

Answer:
Index 2
```

---

# 4️⃣ Upper Bound Search

Find first element:

```text
> target
```

Example:

```text
1 2 4 4 4 7
```

Target:

```text
4
```

Answer:

```text
Index 5
```

---

# 5️⃣ First Occurrence Search

For duplicate values.

Find:

```text
Leftmost occurrence
```

---

# 6️⃣ Last Occurrence Search

Find:

```text
Rightmost occurrence
```

---

# 7️⃣ Search Insert Position

Find location where an element should be inserted.

Example:

```text
1 3 5 7
```

Insert:

```text
4
```

Position:

```text
2
```

---

# 8️⃣ Peak Element Search

Find a local maximum.

Example:

```text
1 3 8 12 7 5 2
```

Peak:

```text
12
```

---

# 9️⃣ Rotated Array Search

Search inside arrays such as:

```text
4 5 6 7 0 1 2
```

without restoring sorting.

---

# 🔟 Binary Search on Answer

One of the most powerful applications.

Instead of searching data:

```text
Search Solution Space
```

Used for:

* Optimization
* Scheduling
* Allocation
* Capacity planning
* Competitive programming

---

# 🌎 Real-World Applications

## Databases

Index lookups.

---

## Search Engines

Fast document retrieval.

---

## Operating Systems

Process management.

---

## Networking

Routing table lookup.

---

## Compilers

Symbol table searching.

---

## Machine Learning

Hyperparameter optimization.

---

## Scientific Computing

Large-scale data analysis.

---

## Game Development

Spatial and object queries.

---

# ⚖️ Binary Search vs Linear Search

| Feature                   | Linear Search | Binary Search |
| ------------------------- | ------------- | ------------- |
| Sorted Data Required      | No            | Yes           |
| Best Case                 | O(1)          | O(1)          |
| Average Case              | O(n)          | O(log n)      |
| Worst Case                | O(n)          | O(log n)      |
| Large Dataset Performance | Poor          | Excellent     |
| Implementation Complexity | Easy          | Moderate      |

---

# ✅ Advantages

### Extremely Fast

Logarithmic growth.

---

### Scalable

Works efficiently on huge datasets.

---

### Low Memory Usage

Iterative version uses:

```text
O(1)
```

memory.

---

### Foundation For Advanced Algorithms

Many algorithms depend on Binary Search.

---

### Widely Used

Appears throughout software engineering.

---

# ❌ Disadvantages

### Requires Ordered Data

Usually needs sorting first.

---

### Harder Than Linear Search

Boundary conditions are tricky.

---

### Not Suitable For Linked Lists

Random access is required.

---

### Off-By-One Errors

Common implementation issue.

---

# 🧪 Edge Cases

Always test:

* Empty array
* Single element
* Two elements
* Duplicates
* Missing target
* First position
* Last position
* Very large arrays

---

# 🎓 Interview Questions

### Easy

* What is Binary Search?
* Why is it faster than Linear Search?

---

### Medium

* Difference between Lower Bound and Upper Bound?
* How do you find first occurrence?

---

### Advanced

* Explain Binary Search on Answer.
* How does Rotated Array Search work?
* Why is Binary Search O(log n)?

---

# 📚 Related Algorithms

```text
Divide-and-Conquer Searching
│
├── Binary Search
│
├── Ternary Search
│
└── Fractional Cascading Search
```

---

# 🚀 Next Algorithms

Continue with:

```text
Iterative Binary Search
```

followed by:

```text
Recursive Binary Search
Lower Bound Search
Upper Bound Search
First Occurrence Search
Last Occurrence Search
Search Insert Position
Peak Element Search
Rotated Array Search
Binary Search on Answer
```

---

# 📜 License

Released under the MIT License.

Free for education, research, learning, and production use.

```
`
