# 🔄 Rotated Array Search

<div align="center">

# Rotated Sorted Array Search

A Binary Search variant used to efficiently search for an element in a sorted array that has been rotated around an unknown pivot.

---

### Category

Searching Algorithms → Divide-and-Conquer Searching → Binary Search Family

### Difficulty

🟡 Intermediate

### Implementations

C • C++ • Java • Python • JavaScript

</div>

---

# 📖 Overview

Rotated Array Search is a modified Binary Search algorithm designed for searching in a sorted array that has been rotated at some pivot point.

Unlike standard Binary Search, the array is no longer completely sorted.

Example:

Original Sorted Array:

```text
1 2 3 4 5 6 7
```

Rotated Array:

```text
4 5 6 7 1 2 3
```

The goal is to locate a target value efficiently without restoring the original order.

---

# 🎯 Problem Statement

Given a rotated sorted array:

```text
[4, 5, 6, 7, 0, 1, 2]
```

Find:

```text
0
```

Output:

```text
4
```

because:

```text
arr[4] = 0
```

---

# 🧠 Core Idea

Although the entire array is not sorted:

```text
4 5 6 7 0 1 2
```

one half is always sorted.

This observation allows Binary Search to remain applicable.

At every iteration:

* One half is sorted.
* Determine whether the target lies inside that half.
* Discard the irrelevant half.

---

# 🔬 Key Observation

Consider:

```text
4 5 6 7 0 1 2
        ↑
       mid
```

At:

```text
mid = 7
```

Left portion:

```text
4 5 6 7
```

is sorted.

Right portion:

```text
0 1 2
```

contains the rotation.

If the target belongs to the sorted side:

```text
Search Left
```

Otherwise:

```text
Search Right
```

---

# ⚙️ Algorithm Workflow

```text
Start
  │
  ▼
Find Mid
  │
  ▼
Target Found?
  │
  ├── Yes
  │      │
  │      ▼
  │   Return Index
  │
  └── No
          │
          ▼
Determine Sorted Half
          │
          ├── Left Half Sorted
          │        │
          │        ▼
          │ Check Target Range
          │
          └── Right Half Sorted
                   │
                   ▼
             Check Target Range
```

---

# 📊 Visual Illustration

Example:

```text
Index

0 1 2 3 4 5 6

Array

4 5 6 7 0 1 2
      ↑
     mid
```

Left side:

```text
4 5 6
```

Sorted.

Right side:

```text
7 0 1 2
```

Contains rotation.

---

# 🔍 Example 1

Array:

```text
[4, 5, 6, 7, 0, 1, 2]
```

Target:

```text
0
```

---

Iteration 1

```text
left = 0
right = 6

mid = 3

arr[mid] = 7
```

Left half:

```text
4 5 6 7
```

Sorted.

Target:

```text
0
```

is not inside this range.

Search right.

---

Iteration 2

```text
left = 4
right = 6

mid = 5

arr[mid] = 1
```

Target:

```text
0
```

is in the left portion.

---

Iteration 3

```text
mid = 4

arr[mid] = 0
```

Found.

Output:

```text
4
```

---

# 🔍 Example 2

Array:

```text
[6, 7, 8, 1, 2, 3, 4, 5]
```

Target:

```text
3
```

Output:

```text
5
```

---

# 🔍 Example 3

Array:

```text
[3, 1]
```

Target:

```text
1
```

Output:

```text
1
```

---

# 📝 Pseudocode

```text
RotatedArraySearch(array, target)

left = 0
right = n - 1

while left <= right

    mid = left + (right - left) / 2

    if array[mid] == target
        return mid

    if array[left] <= array[mid]

        if target >= array[left]
           and target < array[mid]

            right = mid - 1

        else

            left = mid + 1

    else

        if target > array[mid]
           and target <= array[right]

            left = mid + 1

        else

            right = mid - 1

return -1
```

---

# 🔬 Why It Works

In every rotated sorted array:

```text
At least one half
is always sorted.
```

This guarantees that we can determine:

```text
Which half may contain the target.
```

Therefore:

```text
Half of the search space
can always be discarded.
```

This preserves Binary Search efficiency.

---

# 📈 Complexity Analysis

Assume:

```text
n = number of elements
```

---

## Best Case

```text
O(1)
```

Target found immediately.

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

---

# 📊 Complexity Table

| Case    | Complexity |
| ------- | ---------- |
| Best    | O(1)       |
| Average | O(log n)   |
| Worst   | O(log n)   |
| Space   | O(1)       |

---

# 🔄 Rotation Explained

Original:

```text
1 2 3 4 5 6 7
```

Rotate by 3:

```text
5 6 7 1 2 3 4
```

Rotate by 5:

```text
3 4 5 6 7 1 2
```

The array remains composed of two sorted segments.

---

# 🌎 Real-World Applications

## Circular Buffers

Searching in cyclic data structures.

---

## Rotating Logs

Log management systems.

---

## Time-Based Data Storage

Periodic data retention systems.

---

## Embedded Systems

Ring-buffer searching.

---

## Database Partitioning

Rotated storage segments.

---

## Network Systems

Circular routing tables.

---

## Competitive Programming

Very common interview and contest problem.

---

# ⚖️ Comparison With Binary Search

| Feature          | Binary Search | Rotated Array Search |
| ---------------- | ------------- | -------------------- |
| Sorted Array     | Required      | Not Required         |
| Rotated Array    | Fails         | Works                |
| Time Complexity  | O(log n)      | O(log n)             |
| Space Complexity | O(1)          | O(1)                 |
| Difficulty       | Easy          | Intermediate         |

---

# 🔄 Rotated Search vs Linear Search

| Feature      | Linear Search | Rotated Search |
| ------------ | ------------- | -------------- |
| Best Case    | O(1)          | O(1)           |
| Average Case | O(n)          | O(log n)       |
| Worst Case   | O(n)          | O(log n)       |
| Large Arrays | Slow          | Fast           |

---

# ⚠️ Common Mistakes

## Forgetting To Identify The Sorted Half

This is the most common bug.

---

## Incorrect Boundary Conditions

Using:

```text
<
```

instead of:

```text
<=
```

may skip valid elements.

---

## Ignoring Single-Element Arrays

Always test:

```text
[5]
```

---

## Mishandling Pivot Locations

The pivot can occur anywhere.

---

# 🧪 Edge Cases

### Empty Array

```text
[]
```

Return:

```text
-1
```

---

### Single Element

```text
[5]
```

Target:

```text
5
```

Return:

```text
0
```

---

### No Rotation

```text
1 2 3 4 5
```

Works like normal Binary Search.

---

### Full Rotation

```text
1 2 3 4 5
```

Same result.

---

### Target Missing

```text
4 5 6 7 0 1 2
```

Target:

```text
9
```

Return:

```text
-1
```

---

# 🎓 Interview Questions

### Easy

* What is a rotated sorted array?
* Why does Binary Search fail directly?

---

### Medium

* How do you identify the sorted half?
* Why is one half always sorted?

---

### Advanced

* How would you handle duplicates?
* Can you find the pivot first?
* Compare pivot-based and direct approaches.

---

# 🔀 Variants

```text
Rotated Array Search
│
├── Search In Rotated Sorted Array
├── Search With Duplicates
├── Find Rotation Count
├── Find Pivot Element
├── Find Minimum In Rotated Array
└── Find Maximum In Rotated Array
```
---

# 🚀 Next Algorithm

Continue with:

```text
Binary Search on Answer
```

One of the most powerful applications of Binary Search used in optimization, scheduling, allocation, capacity planning, and advanced competitive programming.

---

# 📜 License

MIT License

Free for learning, education, research, and production use.
