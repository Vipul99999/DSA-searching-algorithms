# Upper Bound Search

## 🔍 Algorithm Overview

**Algorithm Name:** Upper Bound Search

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

Upper Bound Search is a specialized Binary Search algorithm used to find the **first element strictly greater than a target value** in a sorted array.

Unlike standard Binary Search, which searches for an exact value, Upper Bound Search finds a **position**.

It is one of the most important Binary Search variants and is widely used in:

* C++ STL (`upper_bound`)
* Databases
* Search engines
* Frequency counting
* Range queries
* Competitive programming
* Data indexing systems

---

## Formal Definition

Given a sorted array:

```text
A = [a₀, a₁, a₂, ... , aₙ₋₁]
```

Upper Bound of value `x` is the first index `i` satisfying:

```text
A[i] > x
```

---

### Example

```text
Array:

[1, 3, 3, 3, 5, 7, 9]

Target = 3
```

Upper Bound:

```text
Index = 4
```

Because:

```text
A[4] = 5
```

and:

```text
5 > 3
```

---

# 🎯 Motivation

Suppose we have:

```text
[1, 3, 3, 3, 5, 7]
```

and want to know:

```text
Where do values larger than 3 begin?
```

Standard Binary Search cannot answer this directly.

Upper Bound Search solves exactly this problem.

---

## Why It Exists

Traditional Binary Search answers:

```text
Does x exist?
```

Upper Bound answers:

```text
Where does x stop?
```

This distinction is critical in:

* Duplicate handling
* Range searching
* Frequency counting
* Ordered containers

---

# 💡 Core Idea

The key observation:

> If an element is greater than the target, it is a candidate answer, but there might be an earlier one.

Therefore:

```text
arr[mid] > target
```

means:

```text
Store mid
Search Left Half
```

---

If:

```text
arr[mid] <= target
```

then:

```text
Upper Bound cannot be here
or on the left side.
```

Search:

```text
Right Half
```

---

## Visual Intuition

```text
Array

[1 3 3 3 5 7 9]

Target = 3

Upper Bound ?

          ↑
          5

Answer = 4
```

---

# ⚙️ How It Works

### Step 1

Initialize:

```text
left = 0
right = n - 1
answer = n
```

---

### Step 2

Compute midpoint:

```text
mid = left + (right-left)/2
```

---

### Step 3

Check:

```text
arr[mid] > target ?
```

---

### Case 1

True

```text
Store mid
Search Left Half
```

---

### Case 2

False

```text
Search Right Half
```

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
arr[mid] > target ?
 ┌─────────────┐
 │ Yes         │
 └─────────────┘
        │
        ▼
 Store Answer
 Search Left
        │
        ▼
 Continue
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
Return Upper Bound
```

---

# 🧮 Mathematical Foundation

Upper Bound Search uses Binary Search principles.

At every iteration:

```text
Search Space
     ↓
Half
```

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

Termination:

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
UpperBound(array, target)

left = 0
right = n - 1

answer = n

while left <= right

    mid = left + (right-left)/2

    if array[mid] > target

        answer = mid
        right = mid - 1

    else

        left = mid + 1

return answer
```

---

# 🧪 Dry Run Example

## Input

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

Condition:

```text
3 > 3 ? No
```

Move Right.

---

### Iteration 2

| Left | Right | Mid | Value |
| ---- | ----- | --- | ----- |
| 4    | 6     | 5   | 7     |

Condition:

```text
7 > 3
```

Store:

```text
answer = 5
```

Move Left.

---

### Iteration 3

| Left | Right | Mid | Value |
| ---- | ----- | --- | ----- |
| 4    | 4     | 4   | 5     |

Condition:

```text
5 > 3
```

Store:

```text
answer = 4
```

Move Left.

---

### Search Ends

Result:

```text
Upper Bound = 4
```

---

# 🎨 Visual Illustration

### Initial Search

```text
[1 3 3 3 5 7 9]

      ↑
     Mid

Target = 3
```

---

### Search Right

```text
[5 7 9]

   ↑
  Mid
```

---

### Move Left

```text
[5]

 ↑
```

---

### Result

```text
Upper Bound = 4
```

---

# ⏱️ Complexity Analysis

## Best Case

```text
O(1)
```

Target boundary discovered immediately.

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

Search interval is repeatedly halved.

---

## Space Complexity

```text
O(1)
```

Iterative implementation uses constant memory.

---

# 📊 Complexity Table

| Case             | Complexity |
| ---------------- | ---------- |
| Best Case        | O(1)       |
| Average Case     | O(log n)   |
| Worst Case       | O(log n)   |
| Space Complexity | O(1)       |

---

# ✔️ Correctness Explanation

The algorithm is correct because:

1. Array is sorted.
2. Every candidate answer satisfies:

```text
arr[i] > target
```

3. Whenever a valid candidate is found:

```text
Store Candidate
```

4. Continue searching leftward.

5. Search interval shrinks every iteration.

6. Eventually the earliest valid index is found.

Thus the algorithm always returns the true Upper Bound.

---

# 🚀 Advantages

* Very fast
* Logarithmic complexity
* Handles duplicates efficiently
* Foundation for advanced searching
* Used in STL and database engines
* Excellent for range queries

---

# ⚠️ Disadvantages

* Requires sorted data
* Less intuitive than standard Binary Search
* Cannot be used on unsorted arrays
* Requires random access

---

# 🧩 Edge Cases

## Empty Array

```text
[]
```

Result:

```text
0
```

---

## All Elements Smaller

```text
[1 2 3]

Target = 10
```

Result:

```text
3
```

---

## All Elements Greater

```text
[10 20 30]

Target = 5
```

Result:

```text
0
```

---

## Duplicate Elements

```text
[3 3 3 3]
```

Target:

```text
3
```

Result:

```text
4
```

---

## Single Element

```text
[5]
```

Handled correctly.

---

# 🌍 Real-World Applications

## C++ STL

```cpp
upper_bound()
```

implementation.

---

## Databases

Range index lookups.

---

## Search Engines

Document boundary searches.

---

## Frequency Counting

Count occurrences using:

```text
Upper Bound - Lower Bound
```

---

## Time-Series Systems

Timestamp range queries.

---

## Data Warehousing

Analytical filtering.

---

## Competitive Programming

Range and frequency problems.

---

# ⚖️ Comparison With Related Algorithms

## Binary Search vs Upper Bound

| Feature            | Binary Search | Upper Bound |
| ------------------ | ------------- | ----------- |
| Exact Match        | Yes           | No          |
| Position Search    | No            | Yes         |
| Duplicate Handling | Partial       | Excellent   |
| Complexity         | O(log n)      | O(log n)    |

---

## Lower Bound vs Upper Bound

| Feature                  | Lower Bound | Upper Bound |
| ------------------------ | ----------- | ----------- |
| Condition                | ≥ target    | > target    |
| Duplicate Start          | Yes         | No          |
| Duplicate End            | No          | Yes         |
| First Occurrence Support | Yes         | Indirect    |
| Frequency Counting       | Yes         | Yes         |

---


# ❌ Common Mistakes

### Wrong Comparison

Incorrect:

```text
arr[mid] >= target
```

Correct:

```text
arr[mid] > target
```

---

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

### Incorrect Initialization

Must initialize:

```text
answer = n
```

---

### Overflow Risk

Avoid:

```text
(left + right)/2
```

Use:

```text
left + (right-left)/2
```

---

# 🧪 Testing Suggestions

Test with:

```text
Empty Array
Single Element
Target Missing
Target Smaller Than All
Target Larger Than All
Duplicate Values
Large Arrays
Random Arrays
```

---

# 🎤 Interview Questions

## Easy

1. What is Upper Bound Search?
2. How does it differ from Binary Search?
3. Why must the array be sorted?

---

## Medium

1. How do duplicates affect Upper Bound?
2. Implement Upper Bound without STL.
3. Explain insertion positions.

---

## Advanced

1. How do Lower Bound and Upper Bound work together?
2. How can frequency be computed?
3. Explain Upper Bound in B-Trees.
4. How is Upper Bound used in database indexing?

---

# 🔗 Related Concepts

### Algorithms

* Binary Search
* Lower Bound Search
* First Occurrence Search
* Last Occurrence Search
* Exponential Search

### Data Structures

* Arrays
* Sorted Arrays
* B-Trees
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

**Upper Bound Search** is a powerful Binary Search variant that finds the **first element strictly greater than a target value**. It runs in **O(log n)** time, handles duplicate values naturally, and forms the foundation of frequency counting, range queries, ordered containers, database indexing, STL implementations, and many advanced searching techniques.
