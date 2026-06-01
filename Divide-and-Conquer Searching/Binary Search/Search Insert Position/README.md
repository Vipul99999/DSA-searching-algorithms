# 📍 Search Insert Position

<div align="center">

# Search Insert Position Algorithm

A Binary Search variant used to find the index of a target element in a sorted array, or the position where it should be inserted to maintain sorted order.

---

### Category

Searching Algorithms → Divide-and-Conquer Searching → Binary Search Family

### Difficulty

🟡 Easy

### Implementations

C • C++ • Java • Python • JavaScript

</div>

---

# 📖 Overview

Search Insert Position is a Binary Search-based algorithm that determines:

* The index of a target if it exists.
* The correct insertion position if it does not exist.

The resulting position guarantees that the array remains sorted after insertion.

---

# 🎯 Problem Statement

Given a sorted array:

```text
[1, 3, 5, 6]
```

Target:

```text
5
```

Output:

```text
2
```

because:

```text
array[2] = 5
```

---

If the target is not present:

```text
Array:
[1, 3, 5, 6]

Target:
2
```

Output:

```text
1
```

because:

```text
[1, 2, 3, 5, 6]
```

maintains sorted order.

---

# 🧠 Core Idea

A standard Binary Search:

```text
Returns
Found / Not Found
```

Search Insert Position extends this idea:

```text
Returns
Correct Position
```

whether the target exists or not.

---

# 🔬 Key Observation

At the end of Binary Search:

```text
left > right
```

The variable:

```text
left
```

points to the exact location where the target should be inserted.

This makes the solution elegant and efficient.

---

# ⚙️ Algorithm Workflow

```text
Start
  │
  ▼
Initialize
left = 0
right = n - 1
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
  │ Return Mid
  │
  └── No
          │
          ▼
Adjust Bounds
          │
          ▼
Repeat
          │
          ▼
left > right
          │
          ▼
Return left
```

---

# 📝 Pseudocode

```text
SearchInsertPosition(array, target)

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

return left
```

---

# 🔍 Example 1

Array:

```text
[1, 3, 5, 6]
```

Target:

```text
5
```

---

Step 1

```text
mid = 1

array[mid] = 3
```

```text
5 > 3
```

Search right.

---

Step 2

```text
mid = 2

array[mid] = 5
```

Found.

Output:

```text
2
```

---

# 🔍 Example 2

Array:

```text
[1, 3, 5, 6]
```

Target:

```text
2
```

---

Step 1

```text
mid = 1

array[mid] = 3
```

```text
2 < 3
```

Move left.

---

Step 2

```text
mid = 0

array[mid] = 1
```

```text
2 > 1
```

Move right.

---

Search ends.

```text
left = 1
```

Return:

```text
1
```

---

# 🔍 Example 3

Array:

```text
[1, 3, 5, 6]
```

Target:

```text
7
```

Search ends with:

```text
left = 4
```

Return:

```text
4
```

Resulting array:

```text
[1, 3, 5, 6, 7]
```

---

# 🔍 Example 4

Array:

```text
[1, 3, 5, 6]
```

Target:

```text
0
```

Search ends with:

```text
left = 0
```

Return:

```text
0
```

Result:

```text
[0, 1, 3, 5, 6]
```

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

# 📈 Complexity Table

| Case    | Complexity |
| ------- | ---------- |
| Best    | O(1)       |
| Average | O(log n)   |
| Worst   | O(log n)   |
| Space   | O(1)       |

---

# 🔬 Why It Works

Binary Search continuously narrows the valid search range.

When the loop terminates:

```text
left > right
```

The insertion location is exactly:

```text
left
```

because:

```text
All elements before left
<
target

All elements after left
>=
target
```

Thus inserting at:

```text
left
```

preserves sorted order.

---

# 📊 Visual Illustration

Target = 4

```text
Index

0 1 2 3

Array

1 3 5 6
    ↑
Insert Here
```

Result:

```text
1 3 4 5 6
```

---

# 🌎 Real-World Applications

## Ordered Databases

Finding insertion positions.

---

## Search Engines

Maintaining sorted ranking lists.

---

## Leaderboards

Determining player placement.

---

## Financial Systems

Maintaining sorted transaction records.

---

## Scheduling Systems

Ordered event insertion.

---

## Inventory Management

Sorted stock insertion.

---

## Competitive Programming

Frequently appears as a Binary Search variant.

---

# ⚖️ Comparison With Related Algorithms

| Algorithm              | Purpose                  |
| ---------------------- | ------------------------ |
| Binary Search          | Find target              |
| Lower Bound            | First element ≥ target   |
| Upper Bound            | First element > target   |
| Search Insert Position | Exact position to insert |
| First Occurrence       | Leftmost target          |
| Last Occurrence        | Rightmost target         |

---

# 🔗 Relationship With Lower Bound

Search Insert Position is essentially equivalent to:

```text
Lower Bound Search
```

because both return:

```text
First Position
>= Target
```

---

Example:

```text
Array

1 3 5 6

Target

4
```

Lower Bound:

```text
Index 2
```

Search Insert Position:

```text
Index 2
```

Same answer.

---

# ✅ Advantages

### Fast

Logarithmic complexity.

---

### Simple

Easy Binary Search variant.

---

### Memory Efficient

Constant extra space.

---

### Practical

Useful in many ordered systems.

---

### Interview Favorite

Frequently asked in coding interviews.

---

# ❌ Disadvantages

### Requires Sorted Data

Unsorted arrays are not supported.

---

### No Actual Insertion

Only returns the position.

---

### Binary Search Knowledge Required

Understanding boundaries is essential.

---

# 🧪 Edge Cases

Test:

### Empty Array

```text
[]
```

Return:

```text
0
```

---

### Single Element

```text
[5]
```

Target:

```text
2
```

Return:

```text
0
```

---

### Insert At Beginning

```text
Target < First Element
```

---

### Insert At End

```text
Target > Last Element
```

---

### Duplicate Values

Behavior depends on implementation.

Most implementations return:

```text
First Valid Position
```

---

# 🎓 Interview Questions

### Easy

* What is Search Insert Position?
* Why use Binary Search?

---

### Medium

* How is it related to Lower Bound?
* What happens when the target is absent?

---

### Advanced

* Prove that returning `left` is correct.
* How would you handle duplicates?
* Can Search Insert Position be generalized to custom comparators?

---

# 🚀 Next Algorithms

Continue with:

```text
Peak Element Search
```

then:

```text
Rotated Array Search
```

and finally:

```text
Binary Search on Answer
```

to explore more advanced Binary Search applications.

---

# 📜 License

MIT License

Free for learning, education, research, and production use.
