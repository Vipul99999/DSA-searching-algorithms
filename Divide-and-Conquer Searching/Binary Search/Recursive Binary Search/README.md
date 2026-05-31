# Recursive Binary Search

## 🔍 Algorithm Overview

**Algorithm Name:** Recursive Binary Search

**Category:** Searching Algorithms

**Difficulty Level:** Easy–Medium

**Paradigm:** Divide and Conquer, Recursion

**Supported Languages:**

* C
* C++
* Java
* Python
* JavaScript

---

# 📖 Overview

Recursive Binary Search is a searching algorithm that locates a target element within a **sorted array** by repeatedly dividing the search interval into two halves using recursion.

Unlike Iterative Binary Search, which uses loops, Recursive Binary Search solves the problem by calling itself on progressively smaller subarrays until either:

* The target is found.
* The search interval becomes empty.

Because each recursive call eliminates half of the remaining search space, the algorithm achieves logarithmic search performance.

---

## What Problem Does It Solve?

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

## Why Does It Exist?

The recursive version provides a more natural implementation of the Divide-and-Conquer strategy.

Each recursive call handles:

```text
Smaller Search Problem
```

making the code elegant and mathematically intuitive.

---

## When Should It Be Used?

✅ Educational purposes

✅ Divide-and-Conquer demonstrations

✅ Recursive programming practice

✅ Interview preparation

✅ Functional programming styles

---

# 🎯 Motivation

Before Binary Search, searching was typically performed using Linear Search.

### Linear Search

```text
[1 2 3 4 5 6 7 8 9 10]

Target = 10

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

Complexity:

```text
O(n)
```

---

For very large datasets:

```text
Millions
Billions
Trillions
```

Linear Search becomes inefficient.

---

### Binary Search Observation

If data is sorted:

```text
Middle element tells us
which half cannot contain
the target.
```

Thus we can eliminate:

```text
50%
```

of remaining elements after every comparison.

---

# 💡 Core Idea

The core idea is:

> Compare the target with the middle element and recursively search only the half that may still contain the target.

---

## Fundamental Observation

For a sorted array:

```text
arr[mid] < target
```

means:

```text
Target cannot be
on the left side.
```

---

Similarly:

```text
arr[mid] > target
```

means:

```text
Target cannot be
on the right side.
```

---

### Visual Example

```text
Array

10 20 30 40 50 60 70

Target = 60

Middle = 40

60 > 40

Discard:

10 20 30 40

Search:

50 60 70
```

---

# ⚙️ How It Works

### Step 1

Start with:

```text
left = 0
right = n - 1
```

---

### Step 2

Calculate:

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

### Step 4

Three possibilities:

#### Case 1

```text
arr[mid] == target
```

Return index.

---

#### Case 2

```text
arr[mid] < target
```

Recursively search:

```text
mid+1 → right
```

---

#### Case 3

```text
arr[mid] > target
```

Recursively search:

```text
left → mid-1
```

---

### Step 5

Base Condition

If:

```text
left > right
```

Return:

```text
Not Found
```

---

# 🔄 Algorithm Workflow

```text
Start
  │
  ▼
Receive Array
  │
  ▼
Receive Target
  │
  ▼
Calculate Mid
  │
  ▼
Target Found?
 ┌───────┐
 │ Yes   │──► Return Index
 └───────┘
  │ No
  ▼
Target > Mid?
 ┌───────┐
 │ Yes   │──► Recurse Right Half
 └───────┘
  │ No
  ▼
Recurse Left Half
  │
  ▼
Repeat
  │
  ▼
Search Space Empty?
 ┌───────┐
 │ Yes   │──► Not Found
 └───────┘
```

---

# 🧠 Recursive Execution Flow

Suppose:

```text
Array:

[5 12 18 25 31 42 56]

Target = 42
```

Call Tree:

```text
binarySearch(0,6)

         25
          |
          |
binarySearch(4,6)

         42
          |
          |
        Found
```

---

# 🧮 Mathematical Foundation

Binary Search repeatedly halves the search interval.

Search sizes:

```text
n
n/2
n/4
n/8
n/16
...
```

After k recursive calls:

```text
n / 2^k
```

Search stops when:

```text
n / 2^k = 1
```

Therefore:

```text
2^k = n
```

Taking logarithm:

k = \log_2(n)

Thus:

```text
Time Complexity = O(log n)
```

---

## Recursion Depth

Maximum recursion depth:

```text
log₂(n)
```

For:

```text
n = 1,000,000
```

Depth:

```text
≈ 20
```

which is very small.

---

# 📝 Pseudocode

```text
RecursiveBinarySearch(
    array,
    left,
    right,
    target
)

IF left > right
    RETURN -1

mid = left + (right-left)/2

IF array[mid] == target
    RETURN mid

IF array[mid] < target

    RETURN RecursiveBinarySearch(
        array,
        mid+1,
        right,
        target
    )

ELSE

    RETURN RecursiveBinarySearch(
        array,
        left,
        mid-1,
        target
    )
```

---

# 🧪 Dry Run Example

## Input

```text
Array

[5, 12, 18, 25, 31, 42, 56]

Target = 42
```

---

### Call #1

```text
left = 0
right = 6

mid = 3

arr[3] = 25
```

Comparison:

```text
42 > 25
```

Recursive call:

```text
binarySearch(4,6)
```

---

### Call #2

```text
left = 4
right = 6

mid = 5

arr[5] = 42
```

Target found.

---

### Output

```text
Index = 5
```

---

# 🎨 Visual Illustration

### Initial Search

```text
[5 12 18 25 31 42 56]

      ↑
     Mid

Target = 42
```

---

### Recursive Right Search

```text
Discard

[5 12 18 25]

Search

[31 42 56]
```

---

### Second Recursive Call

```text
[31 42 56]

    ↑
   Mid

Found
```

---

# ⏱️ Complexity Analysis

## Best Case

Target found at first midpoint.

```text
O(1)
```

---

## Average Case

Repeated halving.

```text
O(log n)
```

---

## Worst Case

Target absent or found at deepest level.

```text
O(log n)
```

---

## Space Complexity

Unlike Iterative Binary Search:

```text
Recursive calls
consume stack space.
```

Maximum depth:

```text
log₂(n)
```

Therefore:

```text
O(log n)
```

---

# 📊 Complexity Table

| Case            | Complexity |
| --------------- | ---------- |
| Best Case       | O(1)       |
| Average Case    | O(log n)   |
| Worst Case      | O(log n)   |
| Auxiliary Space | O(log n)   |

---

# ✔️ Correctness Explanation

Recursive Binary Search is correct because:

1. Array is sorted.
2. Midpoint divides search space.
3. One comparison determines which half cannot contain target.
4. Invalid half is discarded permanently.
5. Recursion continues only on valid half.
6. Search interval shrinks every call.
7. Eventually:

   * Target is found, or
   * Search space becomes empty.

Therefore Recursive Binary Search always produces the correct result.
