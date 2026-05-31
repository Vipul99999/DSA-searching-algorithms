# Last Occurrence Search

## 🔍 Algorithm Overview

**Algorithm Name:** Last Occurrence Search

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

Last Occurrence Search is a specialized Binary Search algorithm used to find the **last occurrence (rightmost position)** of a target value in a sorted array containing duplicate elements.

Unlike standard Binary Search, which stops when it finds a matching element, Last Occurrence Search continues searching toward the right side to ensure the final occurrence is located.

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
Index = 3
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

Last Occurrence Search answers:

```text
Where does the element appear last?
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
1
2
3
or
4
```

depending on implementation.

However, many applications specifically require:

```text
4
```

because it is the last occurrence.

---

# 💡 Core Idea

The key insight:

> Finding the target is not enough. We must determine whether a later occurrence exists.

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
Right Half
```

to find a later occurrence.

---

## Important Observation

If:

```text
arr[mid] <= target
```

then:

```text
Last occurrence could still be
on the right side.
```

Therefore move:

```text
left = mid + 1
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

Continue searching right.

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
 Search Right
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
 Search Right
        │
        ▼
No
 │
 ▼
Search Left
 │
 ▼
Repeat
 │
 ▼
Return Last Occurrence
```

---

# 🧮 Mathematical Foundation

Like Binary Search, the search interval is halved at every iteration.

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
LastOccurrence(array, target)

left = 0
right = n - 1

answer = -1

while left <= right

    mid = left + (right-left)/2

    if array[mid] == target

        answer = mid
        left = mid + 1

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

Search right.

---

### Iteration 2

| Left | Right | Mid | Value |
| ---- | ----- | --- | ----- |
| 4    | 6     | 5   | 7     |

Move left.

---

### Iteration 3

| Left | Right | Mid | Value |
| ---- | ----- | --- | ----- |
| 4    | 4     | 4   | 5     |

Move left.

Search ends.

---

### Result

```text
Last Occurrence = 3
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

Search right.

---

### Right Portion

```text
[5 7 9]

   ↑
  Mid
```

No more occurrences found.

---

### Final Result

```text
Last Occurrence = 3
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
2. All occurrences of a value appear consecutively.
3. Whenever the target is found:

   * Record its position.
   * Continue searching right.
4. Any later occurrence must lie in the right half.
5. Search interval continuously shrinks.
6. Eventually the rightmost valid occurrence is discovered.

Thus the returned index is always the last occurrence.

---

# 🚀 Advantages

* Finds exact last occurrence
* Excellent duplicate handling
* Logarithmic complexity
* Useful for frequency calculations
* Efficient on very large datasets
* Widely used in databases and indexing systems

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
4
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

Frequency can be computed using:

```text
Last Occurrence - First Occurrence + 1
```

---

## Databases

Finding the last matching record in an indexed dataset.

---

## Search Engines

Determining the ending boundary of matching documents.

---

## Analytics Systems

Range-based computations.

---

## Competitive Programming

Duplicate value processing.

---

## Data Warehouses

Efficient searching in sorted data.

---

# ⚖️ Comparison With Related Algorithms

## Binary Search vs Last Occurrence Search

| Feature                 | Binary Search | Last Occurrence Search |
| ----------------------- | ------------- | ---------------------- |
| Exact Match             | Yes           | Yes                    |
| Duplicate Handling      | Limited       | Excellent              |
| Returns Rightmost Index | No            | Yes                    |
| Complexity              | O(log n)      | O(log n)               |

---

## First vs Last Occurrence

| Feature                      | First Occurrence | Last Occurrence |
| ---------------------------- | ---------------- | --------------- |
| Search Direction After Match | Left             | Right           |
| Returns                      | Leftmost Index   | Rightmost Index |
| Duplicate Start              | Yes              | No              |
| Duplicate End                | No               | Yes             |

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
Search Right
```

---

### Forgetting to Update Answer

Must save:

```text
answer = mid
```

before continuing.

---

### Wrong Boundary Movement

Correct:

```text
left = mid + 1
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
Target Present
Target Missing
Duplicate Values
Large Arrays
Random Arrays
All Elements Equal
```

---

# 🎤 Interview Questions

## Easy

1. What is Last Occurrence Search?
2. Why is standard Binary Search insufficient for duplicates?
3. What is its complexity?

---

## Medium

1. How does it differ from First Occurrence Search?
2. How can it be implemented iteratively?
3. What happens if the target is missing?

---

## Advanced

1. How can frequency be computed using first and last occurrence?
2. Compare Last Occurrence Search with Upper Bound Search.
3. Explain correctness.
4. Adapt it for generic comparable objects.

---

# 🔗 Related Concepts

### Algorithms

* Binary Search
* Lower Bound Search
* Upper Bound Search
* First Occurrence Search
* Frequency Count Search
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

**Last Occurrence Search** is a Binary Search variant that finds the **rightmost occurrence of a target value** in a sorted array. By continuing the search toward the right even after finding a match, it guarantees the final occurrence while maintaining **O(log n)** time complexity. It is widely used for duplicate handling, frequency counting, indexing systems, database engines, and advanced range-query algorithms.
