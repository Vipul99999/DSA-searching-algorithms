# 🔺 Ternary Search

<div align="center">

# Ternary Search Algorithm Family

A divide-and-conquer searching technique that repeatedly divides the search space into three parts instead of two.

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

Ternary Search is a divide-and-conquer searching algorithm that reduces the search space by splitting it into three regions during each iteration.

Unlike Binary Search, which uses one midpoint:

```text
mid
````

Ternary Search uses two midpoints:

```text
mid1
mid2
```

These midpoints divide the search interval into three sections.

---

# 🎯 Core Idea

For a sorted array:

```text
1 3 5 7 9 11 13 15 17
```

Suppose we search for:

```text
13
```

The array is divided into three regions:

```text
Left     Middle      Right

1 3 5 | 7 9 11 | 13 15 17
```

Using:

```text
mid1
mid2
```

we determine which section may contain the target.

The other two sections are discarded.

---

# ⚙️ Algorithm Workflow

```text
Start
  │
  ▼
Find mid1 and mid2
  │
  ▼
Compare Target
  │
  ├── target == mid1
  │        │
  │        ▼
  │      Found
  │
  ├── target == mid2
  │        │
  │        ▼
  │      Found
  │
  ├── target < mid1
  │        │
  │        ▼
  │   Search Left Third
  │
  ├── target > mid2
  │        │
  │        ▼
  │   Search Right Third
  │
  └── Otherwise
           │
           ▼
     Search Middle Third
```

---

# 🧠 Why It Works

Each iteration removes approximately:

```text
2/3
```

of the remaining search space.

Only:

```text
1/3
```

remains for further searching.

This leads to logarithmic complexity.

---

# 🔬 Mathematical Foundation

At every step:

```text
n
↓
n/3
↓
n/9
↓
n/27
↓
...
```

After k steps:

```text
n / 3^k = 1
```

Solving:

```text
k = log₃(n)
```

Thus:

```text
Time Complexity = O(log₃ n)
```

---

# 📝 Generic Pseudocode

```text
TernarySearch(array, left, right, target)

while left <= right

    third = (right - left) / 3

    mid1 = left + third
    mid2 = right - third

    if array[mid1] == target
        return mid1

    if array[mid2] == target
        return mid2

    if target < array[mid1]
        right = mid1 - 1

    else if target > array[mid2]
        left = mid2 + 1

    else
        left = mid1 + 1
        right = mid2 - 1

return -1
```

---

# 🔍 Example

Array:

```text
10 20 30 40 50 60 70 80 90
```

Target:

```text
70
```

---

Step 1

```text
mid1 = 30
mid2 = 70
```

Comparison:

```text
70 == 70
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

Target found at either midpoint.

---

## Average Case

```text
O(log₃ n)
```

---

## Worst Case

```text
O(log₃ n)
```

---

## Space Complexity

Iterative:

```text
O(1)
```

Recursive:

```text
O(log₃ n)
```

---

# 📈 Complexity Table

| Case            | Complexity |
| --------------- | ---------- |
| Best            | O(1)       |
| Average         | O(log₃ n)  |
| Worst           | O(log₃ n)  |
| Iterative Space | O(1)       |
| Recursive Space | O(log₃ n)  |

---

# ⚠️ Prerequisites

Ternary Search requires:

## Sorted Data

Valid:

```text
10 20 30 40 50
```

Invalid:

```text
40 10 20 50 30
```

Without ordering:

```text
Ternary Search does not work.
```

---

# 🔍 Ternary Search vs Binary Search

Many beginners assume:

```text
More divisions
=
Faster algorithm
```

This is not always true.

---

Binary Search:

```text
1 midpoint
1 comparison chain
```

---

Ternary Search:

```text
2 midpoints
More comparisons
```

Although Ternary Search reduces the search space faster, each step performs additional comparisons.

In practice:

```text
Binary Search is usually faster.
```

---

# 📊 Binary vs Ternary

| Feature              | Binary Search | Ternary Search  |
| -------------------- | ------------- | --------------- |
| Divisions            | 2             | 3               |
| Midpoints            | 1             | 2               |
| Time Complexity      | O(log₂ n)     | O(log₃ n)       |
| Comparisons Per Step | Fewer         | More            |
| Practical Speed      | Faster        | Slightly Slower |
| Memory Usage         | Same          | Same            |

---

# 📂 Ternary Search Family

```text
Ternary Search
│
├── Iterative Ternary Search
├── Recursive Ternary Search
└── Unimodal Function Search
```

---

# 1️⃣ Iterative Ternary Search

Uses loops.

Advantages:

* No recursion overhead
* O(1) extra memory
* Preferred in production systems

---

# 2️⃣ Recursive Ternary Search

Uses recursive calls.

Advantages:

* Cleaner implementation
* Easier to understand mathematically

Disadvantage:

```text
O(log₃ n)
```

stack usage.

---

# 3️⃣ Unimodal Function Search

One of the most important applications.

Instead of searching arrays:

```text
Search Mathematical Functions
```

---

A unimodal function:

```text
Strictly increases
then
Strictly decreases
```

or vice versa.

Example:

```text
      ▲
     / \
    /   \
   /     \
```

---

Goal:

```text
Find Maximum
or
Find Minimum
```

efficiently.

---

# 🌎 Real-World Applications

## Optimization Problems

Finding maximum profit.

---

## Machine Learning

Hyperparameter tuning.

---

## Scientific Computing

Function optimization.

---

## Engineering

Parameter estimation.

---

## Signal Processing

Peak detection.

---

## Competitive Programming

Optimization over continuous domains.

---

## Numerical Methods

Finding extrema.

---

# 🔬 Continuous Ternary Search

Ternary Search is commonly used on:

```text
Continuous Functions
```

instead of arrays.

Example:

```text
f(x)
```

For a unimodal function:

```text
Maximum
Minimum
```

can be located efficiently.

---

# 📈 Example of Continuous Search

Function:

```text
f(x) = -(x - 5)² + 25
```

Maximum occurs at:

```text
x = 5
```

Ternary Search can find this maximum without checking every value.

---

# ⚖️ Advantages

### Logarithmic Complexity

Very efficient.

---

### Useful for Optimization

Especially unimodal functions.

---

### Works on Continuous Domains

Unlike many searching algorithms.

---

### Easy Mathematical Analysis

Strong theoretical foundation.

---

# ❌ Disadvantages

### Requires Sorted Data

For array searching.

---

### More Comparisons

Than Binary Search.

---

### Usually Slower Than Binary Search

In practical implementations.

---

### More Complex

To implement correctly.

---

# 🧪 Edge Cases

Always test:

* Empty arrays
* Single element
* Two elements
* Missing targets
* First element
* Last element
* Duplicate values
* Large datasets

---

# 🎓 Interview Questions

### Easy

* What is Ternary Search?
* How is it different from Binary Search?

---

### Medium

* Why does Ternary Search use two midpoints?
* What are its complexity characteristics?

---

### Advanced

* Why is Binary Search often faster?
* Explain Continuous Ternary Search.
* What is a unimodal function?

---

# 🚀 Next Algorithms

Continue with:

```text
Iterative Ternary Search
```

followed by:

```text
Recursive Ternary Search
Unimodal Function Search
```

to explore advanced divide-and-conquer optimization techniques.

---

# 📜 License

Released under the MIT License.

Free for learning, research, education, and production use.
