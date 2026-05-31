# Iterative Binary Search

## 🔍 Algorithm Overview

**Algorithm Name:** Iterative Binary Search

**Category:** Searching Algorithms

**Difficulty Level:** Easy

**Paradigm:** Divide and Conquer

**Supported Languages:**

* C
* C++
* Java
* Python
* JavaScript

---

# 📖 Overview

Iterative Binary Search is one of the most fundamental and efficient searching algorithms in computer science.

It searches for a target element within a **sorted array** by repeatedly dividing the search space into two halves.

Instead of checking every element one by one (as in Linear Search), Binary Search eliminates half of the remaining elements during each iteration, dramatically reducing the number of comparisons.

---

### Problem It Solves

Given:

```text
Sorted Array
Target Value
```

Find:

```text
Index of Target
```

or determine that the target does not exist.

---

### When To Use

✅ Data is sorted

✅ Fast lookup is required

✅ Large datasets

✅ Memory-efficient searching

✅ Database indexes

✅ Search engines

✅ System software

---

# 🎯 Motivation

Before Binary Search, searching was commonly performed using Linear Search.

### Linear Search

```text
1 2 3 4 5 6 7 8 9 10

Searching for 10

Check:
1
2
3
4
5
6
7
8
9
10
```

Worst Case:

```text
O(n)
```

For millions of elements:

```text
Very Slow
```

---

### Binary Search Idea

Instead of checking every element:

```text
Check Middle Element
```

Then discard half the array.

```text
Remaining Search Space:

n
n/2
n/4
n/8
...
```

Result:

```text
O(log n)
```

which is significantly faster.

---

# 💡 Core Idea

The key observation:

> If the array is sorted, we can determine which half cannot contain the target.

---

### Example

```text
Array:

10 20 30 40 50 60 70

Target = 60

Middle = 40

60 > 40

Discard Left Half

Remaining:

50 60 70
```

---

### Visualization

```text
[10 20 30 40 50 60 70]

         ↑
       Mid=40

Target=60

Discard:

[10 20 30]

Keep:

[50 60 70]
```

---

# ⚙️ How It Works

### Step 1

Initialize:

```text
left = 0
right = n - 1
```

---

### Step 2

Find middle index:

```text
mid = left + (right - left)/2
```

---

### Step 3

Compare:

```text
arr[mid]
```

with

```text
target
```

---

### Step 4

Cases:

#### Found

```text
arr[mid] == target
```

Return index.

---

#### Search Right Half

```text
arr[mid] < target
```

Update:

```text
left = mid + 1
```

---

#### Search Left Half

```text
arr[mid] > target
```

Update:

```text
right = mid - 1
```

---

### Step 5

Repeat until:

```text
left > right
```

---

### Workflow Diagram

```text
Start
  │
  ▼
Initialize Left & Right
  │
  ▼
Compute Mid
  │
  ▼
Target Found?
 ┌───────┐
 │ Yes   │────► Return Index
 └───────┘
  │ No
  ▼
Target > Mid Element?
 ┌───────┐
 │ Yes   │────► Search Right Half
 └───────┘
  │ No
  ▼
Search Left Half
  │
  ▼
Repeat
  │
  ▼
Not Found
```

---

# 🔄 Algorithm Workflow

```text
Input Array
      │
      ▼
Verify Sorted Order
      │
      ▼
Select Middle Element
      │
      ▼
Compare With Target
      │
 ┌────┴────┐
 ▼         ▼
Less      Greater
 ▼         ▼
Right     Left
Half      Half
 ▼         ▼
Continue Iteration
      │
      ▼
Target Found?
      │
 ┌────┴─────┐
 ▼          ▼
Yes         No
 ▼          ▼
Return    Continue
Index
```

---

# 🧮 Mathematical Foundation

Binary Search repeatedly halves the search space.

After each iteration:

```text
n
n/2
n/4
n/8
...
```

After k iterations:

```text
n / 2ᵏ
```

Search stops when:

```text
n / 2ᵏ = 1
```

Therefore:

```text
2ᵏ = n
```

Taking logarithm:

k = \log_2 n

Thus Binary Search performs at most logarithmic comparisons.

---

# 📝 Pseudocode

```text
BinarySearch(array, target)

left = 0
right = length(array) - 1

while left <= right

    mid = left + (right - left)/2

    if array[mid] == target
        return mid

    else if array[mid] < target
        left = mid + 1

    else
        right = mid - 1

return -1
```

---

# 🧪 Dry Run Example

### Input

```text
Array:

[5, 12, 18, 25, 31, 42, 56]

Target = 31
```

---

### Iteration 1

| Left | Right | Mid | Value |
| ---- | ----- | --- | ----- |
| 0    | 6     | 3   | 25    |

```text
31 > 25

Move Right
```

New Range:

```text
[31, 42, 56]
```

---

### Iteration 2

| Left | Right | Mid | Value |
| ---- | ----- | --- | ----- |
| 4    | 6     | 5   | 42    |

```text
31 < 42

Move Left
```

New Range:

```text
[31]
```

---

### Iteration 3

| Left | Right | Mid | Value |
| ---- | ----- | --- | ----- |
| 4    | 4     | 4   | 31    |

Found.

---

### Output

```text
Index = 4
```

---

# 🎨 Visual Illustration

### Initial State

```text
[5 12 18 25 31 42 56]

      ↑
     Mid=25
```

---

### After First Comparison

```text
Discard

[5 12 18 25]

Keep

[31 42 56]
```

---

### Second Comparison

```text
[31 42 56]

    ↑
   Mid=42
```

---

### Third Comparison

```text
[31]

 ↑
Target Found
```

---

# ⏱️ Complexity Analysis

## Best Case

Target is found immediately at middle.

```text
O(1)
```

---

## Average Case

Array is repeatedly halved.

```text
O(log n)
```

---

## Worst Case

Target absent or found near final level.

```text
O(log n)
```

---

## Space Complexity

Only a few variables:

```text
left
right
mid
```

Required.

```text
O(1)
```

---

# 📊 Complexity Table

| Case    | Complexity |
| ------- | ---------- |
| Best    | O(1)       |
| Average | O(log n)   |
| Worst   | O(log n)   |
| Space   | O(1)       |

---

# ✔️ Correctness Explanation

Binary Search works because:

1. Array is sorted.
2. Middle element divides the search space.
3. One comparison determines which half cannot contain the target.
4. Eliminated half is never searched again.
5. Search interval shrinks until:

   * target found
   * interval becomes empty

Therefore the algorithm always returns the correct answer.

---

# 🚀 Advantages

* Extremely fast for large datasets
* Logarithmic time complexity
* Constant memory usage
* Easy to implement
* Widely used in real systems
* Efficient cache behavior
* Foundation of many advanced algorithms

---

# ⚠️ Disadvantages

* Requires sorted data
* Sorting may be expensive
* Inefficient for linked lists
* Not suitable for frequently changing unsorted datasets
* Random access is required

---

# 🧩 Edge Cases

### Empty Array

```text
[]
```

Result:

```text
Not Found
```

---

### Single Element

```text
[5]
```

---

### Target Missing

```text
[1 2 3 4 5]

Target = 10
```

---

### Duplicate Values

```text
[1 2 2 2 3]
```

May return any matching index.

---

### Large Dataset

```text
Millions of elements
```

Binary Search remains efficient.

---

### Integer Overflow

Incorrect:

```text
mid = (left + right)/2
```

Safe:

```text
mid = left + (right-left)/2
```

---

# 🌍 Real-World Applications

## Databases

Searching indexed records.

---

## Search Engines

Fast keyword lookup.

---

## Operating Systems

Memory management tables.

---

## Networking

Routing tables.

---

## Scientific Computing

Searching sorted measurements.

---

## Machine Learning

Threshold and parameter searching.

---

## Game Development

Asset lookup and optimization.

---

## Compiler Design

Symbol-table operations.

---

# ⚖️ Comparison With Related Algorithms

| Feature                | Linear Search | Iterative Binary Search |
| ---------------------- | ------------- | ----------------------- |
| Sorted Data Required   | No            | Yes                     |
| Best Case              | O(1)          | O(1)                    |
| Average Case           | O(n)          | O(log n)                |
| Worst Case             | O(n)          | O(log n)                |
| Space                  | O(1)          | O(1)                    |
| Large Data Performance | Poor          | Excellent               |

---

### Iterative vs Recursive Binary Search

| Feature        | Iterative       | Recursive       |
| -------------- | --------------- | --------------- |
| Time           | O(log n)        | O(log n)        |
| Space          | O(1)            | O(log n)        |
| Stack Usage    | None            | Required        |
| Production Use | Preferred       | Less Preferred  |
| Performance    | Slightly Faster | Slightly Slower |

---

# 🌳 Variants

```text
Binary Search Family
│
├── Iterative Binary Search
├── Recursive Binary Search
├── Lower Bound Search
├── Upper Bound Search
├── Exponential Search
├── Interpolation Search
├── Jump Search
├── Fractional Cascading Search
└── Binary Search on Answer
```

### Variant Summary

* **Recursive Binary Search** → recursion-based implementation
* **Lower Bound** → first valid position
* **Upper Bound** → last valid position
* **Exponential Search** → unknown range sizes
* **Interpolation Search** → uniformly distributed data
* **Binary Search on Answer** → optimization problems

---

# ❌ Common Mistakes

### Wrong Mid Calculation

```text
(left + right)/2
```

May overflow.

---

### Forgetting Sorted Requirement

Binary Search requires sorted data.

---

### Incorrect Loop Condition

Correct:

```text
while(left <= right)
```

---

### Wrong Boundary Updates

Correct:

```text
left = mid + 1
right = mid - 1
```

---

### Infinite Loop

Occurs if boundaries are not updated correctly.

---

# 🧪 Testing Suggestions

### Basic Tests

```text
Target Exists
Target Missing
```

---

### Boundary Tests

```text
First Element
Last Element
```

---

### Edge Tests

```text
Empty Array
Single Element
```

---

### Duplicate Tests

```text
Repeated Values
```

---

### Large Scale Tests

```text
1 Million+
Elements
```

---

### Stress Testing

Random arrays with random targets.

---

# 🎤 Interview Questions

## Easy

1. What is Binary Search?
2. Why must the array be sorted?
3. What is its time complexity?
4. What is its space complexity?

---

## Medium

1. Difference between iterative and recursive Binary Search?
2. How do you find the first occurrence?
3. How do you find the last occurrence?
4. What causes infinite loops?

---

## Advanced

1. Explain Binary Search on Answer.
2. Why use `left + (right-left)/2`?
3. How is Binary Search used in databases?
4. Can Binary Search work on linked lists?
5. Explain lower_bound and upper_bound.

---

# 🔗 Related Concepts

### Algorithms

* Linear Search
* Jump Search
* Interpolation Search
* Exponential Search
* Ternary Search
* Fractional Cascading Search

### Data Structures

* Arrays
* Sorted Arrays
* B-Trees
* Binary Search Trees

### Mathematical Concepts

* Logarithms
* Divide and Conquer
* Complexity Analysis

---


# 📄 License

```text
MIT License

Free for learning, education, research, and production use.
```

---

## ⭐ Key Takeaway

Iterative Binary Search is one of the most important algorithms in computer science. By repeatedly halving the search space, it achieves **O(log n)** time complexity while using **O(1)** extra memory, making it the preferred choice for searching in sorted datasets and a foundational concept for advanced algorithmic problem solving.
