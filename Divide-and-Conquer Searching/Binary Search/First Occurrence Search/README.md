# First Occurrence Search

## 🔍 Algorithm Overview

**Algorithm Name:** First Occurrence Search

**Category:** Searching Algorithms

**Difficulty Level:** Medium

**Paradigm:** Binary Search Variant

**Supported Languages:**

* C
* C++
* Java
* Python
* JavaScript

---

# 📖 Overview

First Occurrence Search is a specialized Binary Search algorithm used to find the **first occurrence (leftmost position)** of a target value in a sorted array containing duplicate elements.

Unlike standard Binary Search, which stops immediately when the target is found, First Occurrence Search continues searching toward the left side to ensure the earliest occurrence is located.

---

## Problem Statement

Given a sorted array:

```text
[1, 3, 3, 3, 5, 7, 9]
```

and:

```text
Target = 3
```

Find:

```text
Index = 1
```

instead of any occurrence such as:

```text
1, 2, or 3
```

---

# 🎯 Motivation

Traditional Binary Search answers:

```text
Does the element exist?
```

First Occurrence Search answers:

```text
Where does the element first appear?
```

This distinction becomes important when duplicate values exist.

---

### Example

```text
Array:

[2, 4, 4, 4, 4, 6, 8]

Target = 4
```

Standard Binary Search may return:

```text
2
3
or
4
```

depending on implementation.

---

However many applications require:

```text
2
```

because it is the first occurrence.

---

# 💡 Core Idea

The key insight:

> Finding the target is not enough. We must determine whether an earlier occurrence exists.

Whenever:

```text
arr[mid] == target
```

we:

```text
Store mid as candidate answer
```

and continue searching:

```text
Left Half
```

to find an earlier occurrence.

---

## Important Observation

If:

```text
arr[mid] >= target
```

then:

```text
First occurrence could still be
on the left side.
```

Therefore move:

```text
right = mid - 1
```

---

# ⚙️ How It Works

### Step 1

Initialize:

```text
left = 0
right = n - 1
answer = -1
```

---

### Step 2

Compute midpoint:

```text
mid = left + (right-left)/2
```

---

### Step 3

Compare:

```text
arr[mid]
```

with:

```text
target
```

---

### Case 1

```text
arr[mid] == target
```

Store:

```text
answer = mid
```

Continue searching left.

---

### Case 2

```text
arr[mid] < target
```

Search right.

---

### Case 3

```text
arr[mid] > target
```

Search left.

---

### Step 4

Repeat until:

```text
left > right
```

---

### Step 5

Return:

```text
answer
```

---

# 🔄 Algorithm Workflow

```text
Start
  │
  ▼
Initialize Variables
  │
  ▼
Compute Mid
  │
  ▼
Target Found?
 ┌─────────────┐
 │ Yes         │
 └─────────────┘
        │
        ▼
 Store Mid
 Search Left
        │
        ▼
 Continue
        │
        ▼
Target Smaller?
 ┌─────────────┐
 │ Yes         │
 └─────────────┘
        │
        ▼
 Search Left
        │
        ▼
No
 │
 ▼
Search Right
 │
 ▼
Repeat
 │
 ▼
Return First Occurrence
```

---

# 🧮 Mathematical Foundation

Like Binary Search, the search space is halved at every iteration.

Progression:

```text
n
n/2
n/4
n/8
...
```

After k iterations:

```text
n / 2^k
```

Stopping condition:

```text
n / 2^k = 1
```

Therefore:

k = \log_2(n)

Thus:

```text
Time Complexity = O(log n)
```

---

# 📝 Pseudocode

```text
FirstOccurrence(array, target)

left = 0
right = n - 1

answer = -1

while left <= right

    mid = left + (right-left)/2

    if array[mid] == target

        answer = mid
        right = mid - 1

    else if array[mid] < target

        left = mid + 1

    else

        right = mid - 1

return answer
```

---

# 🧪 Dry Run Example

### Input

```text
Array:

[1, 3, 3, 3, 5, 7, 9]

Target = 3
```

---

### Iteration 1

| Left | Right | Mid | Value |
| ---- | ----- | --- | ----- |
| 0    | 6     | 3   | 3     |

Found target.

Store:

```text
answer = 3
```

Search left.

---

### Iteration 2

| Left | Right | Mid | Value |
| ---- | ----- | --- | ----- |
| 0    | 2     | 1   | 3     |

Store:

```text
answer = 1
```

Search left.

---

### Iteration 3

| Left | Right | Mid | Value |
| ---- | ----- | --- | ----- |
| 0    | 0     | 0   | 1     |

Move right.

Search ends.

---

### Result

```text
First Occurrence = 1
```

---

# 🎨 Visual Illustration

### Initial State

```text
[1 3 3 3 5 7 9]

      ↑
     Mid

Target = 3
```

Store:

```text
Index 3
```

Search left.

---

### Second Search

```text
[1 3 3]

   ↑
  Mid
```

Store:

```text
Index 1
```

Search left.

---

### Final Result

```text
First Occurrence = 1
```

---

# ⏱️ Complexity Analysis

## Best Case

```text
O(1)
```

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

### Iterative Version

```text
O(1)
```

### Recursive Version

```text
O(log n)
```

---

# 📊 Complexity Table

| Case              | Complexity |
| ----------------- | ---------- |
| Best              | O(1)       |
| Average           | O(log n)   |
| Worst             | O(log n)   |
| Space (Iterative) | O(1)       |
| Space (Recursive) | O(log n)   |

---

# ✔️ Correctness Explanation

The algorithm works because:

1. Array is sorted.
2. Every occurrence of target forms a contiguous block.
3. Whenever target is found:

   * Record its position.
   * Continue searching left.
4. Any earlier occurrence must lie in the left half.
5. Search space continuously shrinks.
6. Eventually the leftmost valid occurrence is discovered.

Thus the returned index is always the first occurrence.

---

# 🚀 Advantages

* Finds exact first occurrence
* Efficient for duplicate values
* Logarithmic performance
* Foundation of frequency counting
* Widely used in databases and indexing

---

# ⚠️ Disadvantages

* Requires sorted data
* Slightly more complex than standard Binary Search
* Random access required

---

# 🧩 Edge Cases

### Empty Array

```text
[]
```

Result:

```text
-1
```

---

### Single Element Present

```text
[5]
```

Target:

```text
5
```

Result:

```text
0
```

---

### Single Element Missing

```text
[5]
```

Target:

```text
10
```

Result:

```text
-1
```

---

### All Elements Same

```text
[3 3 3 3 3]
```

Result:

```text
0
```

---

### Target Missing

```text
[1 2 4 5]
```

Target:

```text
3
```

Result:

```text
-1
```

---

# 🌍 Real-World Applications

## Frequency Counting

Finding first occurrence of a value.

---

## Databases

Searching indexed records.

---

## Search Engines

Document indexing.

---

## Analytics Systems

Range calculations.

---

## Competitive Programming

Duplicate handling.

---

## Data Warehouses

Sorted dataset processing.

---

# ⚖️ Comparison With Related Algorithms

| Feature                | Binary Search | First Occurrence Search |
| ---------------------- | ------------- | ----------------------- |
| Exact Match            | Yes           | Yes                     |
| Duplicate Handling     | Limited       | Excellent               |
| Returns Leftmost Index | No            | Yes                     |
| Complexity             | O(log n)      | O(log n)                |

---

## First Occurrence vs Lower Bound

| Feature                  | First Occurrence | Lower Bound        |
| ------------------------ | ---------------- | ------------------ |
| Existing Target Required | Yes              | No                 |
| Returns Exact Occurrence | Yes              | Position           |
| Missing Element Result   | -1               | Insertion Position |

---

# ❌ Common Mistakes

### Returning Immediately

Wrong:

```text
return mid
```

Correct:

```text
Store Answer
Search Left
```

---

### Not Updating Answer

Must save:

```text
answer = mid
```

before continuing.

---

### Wrong Boundary Movement

Correct:

```text
right = mid - 1
```

after finding target.

---

### Overflow Risk

Use:

```text
left + (right-left)/2
```

instead of:

```text
(left + right)/2
```

---

# 🧪 Testing Suggestions

Test:

```text
Empty Array
Single Element
Target Missing
Target Present
Duplicate Values
Large Arrays
Random Arrays
All Elements Equal
```

---

# 🎤 Interview Questions

## Easy

1. What is First Occurrence Search?
2. Why doesn't standard Binary Search guarantee the first occurrence?
3. What is the complexity?

---

## Medium

1. How does it differ from Lower Bound?
2. How do duplicates affect the algorithm?
3. Implement iterative and recursive versions.

---

## Advanced

1. Use First Occurrence Search to count frequency.
2. Compare with Lower Bound.
3. Explain behavior on huge datasets.
4. How would you adapt it for custom comparators?

---

# 🔗 Related Concepts

### Algorithms

* Binary Search
* Lower Bound Search
* Upper Bound Search
* Last Occurrence Search
* Exponential Search

### Data Structures

* Arrays
* Sorted Arrays
* Ordered Sets

### Mathematics

* Logarithms
* Divide and Conquer

---


# 📄 License

```text
MIT License

Free for learning,
education, research,
and production use.
```

---

# ⭐ Key Takeaway

**First Occurrence Search** is a Binary Search variant that finds the **leftmost occurrence of a target value** in a sorted array. By continuing the search toward the left even after finding the target, it guarantees the earliest valid index while maintaining **O(log n)** time complexity. It is a fundamental technique for duplicate handling, frequency counting, indexing systems, and range-query algorithms.
