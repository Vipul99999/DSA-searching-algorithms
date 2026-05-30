# 🔍 Linear Search

<div align="center">

# Linear Search Algorithm

The simplest and most fundamental searching algorithm.

Works on sorted and unsorted data structures.

---

### Implementations

C • C++ • Java • Python • JavaScript

### Difficulty

🟢 Beginner

### Category

Sequential / Linear Searching

</div>

---

# 📖 Overview

Linear Search (also known as Sequential Search) is the simplest searching algorithm.

The algorithm scans elements one-by-one from the beginning of the collection until:

* The target element is found, or
* The entire collection has been searched.

Unlike Binary Search, Linear Search does not require sorted data.

Because of its simplicity and flexibility, Linear Search is commonly used for:

* Small datasets
* Unsorted collections
* Dynamic data
* Embedded systems
* Initial algorithm learning

---

# 🎯 Problem Statement

Given a collection of elements and a target value, determine whether the target exists in the collection and return its position.

---

## Example

Input:

```text
Array = [15, 8, 21, 10, 5]
Target = 10
```

Output:

```text
Index = 3
```

---

# 🧠 Core Idea

Start from the first element.

Compare every element with the target.

If a match is found:

```text
Return Index
```

Otherwise:

```text
Continue Searching
```

Until the end of the collection is reached.

---

# ⚙️ Algorithm Workflow

```text
Start
  │
  ▼
Read Array & Target
  │
  ▼
Compare Current Element
  │
  ├── Match Found?
  │         │
  │         ├── Yes
  │         │
  │         ▼
  │     Return Index
  │
  ▼
Move To Next Element
  │
  ▼
End Of Array?
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

# 📝 Pseudocode

```text
LinearSearch(array, target)

for each element in array

    if element == target

        return index

return -1
```

---

# 🔬 Step-by-Step Example

Array:

```text
[12, 7, 15, 9, 21]
```

Target:

```text
9
```

---

### Iteration 1

```text
12 == 9 ?
```

No

---

### Iteration 2

```text
7 == 9 ?
```

No

---

### Iteration 3

```text
15 == 9 ?
```

No

---

### Iteration 4

```text
9 == 9 ?
```

Yes

Return:

```text
Index = 3
```

---

# 📊 Complexity Analysis

## Best Case

Target found at first position.

```text
O(1)
```

Example:

```text
[5, 10, 15, 20]

Target = 5
```

Only one comparison required.

---

## Average Case

Target found somewhere in the middle.

```text
O(n)
```

Approximately:

```text
n / 2 comparisons
```

---

## Worst Case

Target is:

* Last element, or
* Not present

```text
O(n)
```

Example:

```text
[5, 10, 15, 20]

Target = 100
```

Entire array must be scanned.

---

## Space Complexity

```text
O(1)
```

No additional memory is required.

---

# 📈 Complexity Table

| Case    | Time Complexity |
| ------- | --------------- |
| Best    | O(1)            |
| Average | O(n)            |
| Worst   | O(n)            |
| Space   | O(1)            |

---

# ✅ Advantages

## Simple Implementation

Easy to understand and implement.

---

## Works on Unsorted Data

No sorting required.

---

## Memory Efficient

Requires constant extra memory.

---

## Universal

Works with:

* Arrays
* Lists
* Linked Lists
* Vectors
* Dynamic Collections

---

## Suitable for Small Data

For small datasets, Linear Search can be competitive with more complex algorithms.

---

# ❌ Disadvantages

## Slow for Large Datasets

Performance degrades linearly with input size.

---

## Not Scalable

Large collections require many comparisons.

---

## Ignores Data Ordering

Even if data is sorted, Linear Search does not utilize that information.

---

# 📋 Comparison with Binary Search

| Feature               | Linear Search | Binary Search |
| --------------------- | ------------- | ------------- |
| Sorted Data Required  | No            | Yes           |
| Best Case             | O(1)          | O(1)          |
| Average Case          | O(n)          | O(log n)      |
| Worst Case            | O(n)          | O(log n)      |
| Easy Implementation   | Yes           | Moderate      |
| Works on Linked Lists | Yes           | Poorly        |
| Extra Space           | O(1)          | O(1)          |

---

# 🌎 Real-World Applications

## Small Datasets

When dataset size is small, Linear Search is often preferred due to simplicity.

Examples:

* Configuration settings
* User preferences
* Runtime flags

---

## Unsorted Collections

Examples:

* Log files
* Event streams
* Temporary buffers

---

## Embedded Systems

Used where memory constraints are strict.

Examples:

* Microcontrollers
* IoT devices
* Sensor systems

---

## Database Internals

Small lookup tables frequently use sequential scanning.

---

## Operating Systems

Examples:

* Process lists
* Resource tables
* Device lists

---

## Compilers

Examples:

* Token matching
* Small symbol tables
* Keyword detection

---

# 🔍 Variants of Linear Search

This repository also contains related algorithms:

---

## Sentinel Linear Search

Reduces boundary checking overhead.

---

## Move-To-Front Search

Recently accessed elements move to the front.

---

## Transpose Search

Found elements gradually move toward the front.

---

## Frequency Count Search

Frequently accessed elements stay near the front.

---

# 🧪 Edge Cases

## Empty Array

Input:

```text
[]
```

Output:

```text
Not Found
```

---

## Single Element Found

Input:

```text
[5]
```

Target:

```text
5
```

Output:

```text
0
```

---

## Single Element Not Found

Input:

```text
[5]
```

Target:

```text
10
```

Output:

```text
-1
```

---

## Duplicate Values

Input:

```text
[10, 20, 20, 30]
```

Target:

```text
20
```

Output:

```text
1
```

Returns first occurrence.

---

# 🔬 Correctness

Linear Search is correct because:

1. Every element is examined sequentially.
2. No element is skipped.
3. If the target exists, it will eventually be compared.
4. If the target does not exist, the algorithm examines all elements and reports failure.

Therefore:

```text
Linear Search always returns the correct result.
```

---

# 📚 Mathematical Analysis

For an array of size:

```text
n
```

Worst-case comparisons:

```text
n
```

Average-case comparisons:

```text
n / 2
```

Best-case comparisons:

```text
1
```

Therefore:

```text
T(n) = O(n)
```

---

# 🏗 Implementation Files

This folder contains:

```text
Linear-Search
│
├── README.md
│
├── LinearSearch.c
├── LinearSearch.cpp
├── LinearSearch.java
├── LinearSearch.py
└── LinearSearch.js
```

---

# 🧪 Testing Suggestions

Test with:

* Empty arrays
* Single element arrays
* Sorted arrays
* Unsorted arrays
* Duplicate elements
* Large datasets
* Missing targets

---

# 🎓 Interview Questions

### Easy

* What is Linear Search?
* What is its time complexity?

---

### Medium

* Why does Linear Search work on unsorted data?
* Compare Linear Search and Binary Search.

---

### Advanced

* When can Linear Search outperform Binary Search?
* Explain cache locality effects in Linear Search.
* What are self-organizing search algorithms?

---

# 📚 Further Reading

Recommended next algorithms:

1. Sentinel Linear Search
2. Move-To-Front Search
3. Transpose Search
4. Frequency Count Search
5. Binary Search
6. Jump Search
7. Interpolation Search

---

# 🚀 Next Algorithm

Continue with:

```text
Sentinel Linear Search
```

which optimizes Linear Search by reducing unnecessary boundary checks.

---

# 📜 License

Released under the MIT License.

Free for learning, research, education, and production use.
