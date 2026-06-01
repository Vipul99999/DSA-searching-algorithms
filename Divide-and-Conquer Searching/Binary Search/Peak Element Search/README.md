# ⛰️ Peak Element Search

<div align="center">

# Peak Element Search Algorithm

A Binary Search variant used to efficiently find a peak element in an array without examining every element.

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

Peak Element Search is a specialized Binary Search algorithm that finds a **peak element** in an array.

A peak element is an element that is greater than or equal to its neighboring elements.

For an element:

```text
arr[i]
```

it is considered a peak if:

```text
arr[i] >= arr[i-1]

and

arr[i] >= arr[i+1]
```

---

Unlike ordinary Binary Search:

```text
Search Value
```

Peak Element Search performs:

```text
Search Property
```

It searches for a location satisfying the peak condition.

---

# 🎯 Problem Statement

Given an array:

```text
[1, 3, 20, 4, 1, 0]
```

Find a peak element.

Answer:

```text
20
```

because:

```text
20 > 3

and

20 > 4
```

---

# 🧠 Core Idea

Instead of checking every element:

```text
O(n)
```

Peak Element Search exploits a powerful observation:

If an element is smaller than its right neighbor:

```text
arr[mid] < arr[mid + 1]
```

then a peak must exist on the right side.

Similarly:

```text
arr[mid] > arr[mid + 1]
```

implies a peak exists on the left side (including mid).

This allows Binary Search.

---

# 🔬 Key Observation

Consider:

```text
1 3 8 12 4 2
```

At:

```text
mid = 8
```

Since:

```text
8 < 12
```

the slope is increasing.

A peak must exist somewhere to the right.

---

Similarly:

```text
1 3 8 12 4 2
```

At:

```text
mid = 12
```

Since:

```text
12 > 4
```

a peak exists at or before 12.

---

# ⚙️ Why A Peak Always Exists

Every array contains at least one peak.

Example:

Increasing Array

```text
1 2 3 4 5
```

Peak:

```text
5
```

---

Decreasing Array

```text
5 4 3 2 1
```

Peak:

```text
5
```

---

Mixed Array

```text
1 4 7 3 2
```

Peak:

```text
7
```

---

Therefore:

```text
A peak always exists.
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
Compare arr[mid]
and arr[mid+1]
  │
  ├── arr[mid] < arr[mid+1]
  │          │
  │          ▼
  │ Search Right Half
  │
  └── arr[mid] > arr[mid+1]
             │
             ▼
       Search Left Half
          (including mid)
```

---

# 📝 Pseudocode

```text
PeakElementSearch(array)

left = 0
right = n - 1

while left < right

    mid = left + (right - left) / 2

    if array[mid] < array[mid + 1]
        left = mid + 1

    else
        right = mid

return left
```

---

# 🔍 Example 1

Array:

```text
1 3 20 4 1 0
```

---

Initial

```text
left = 0
right = 5
```

---

Iteration 1

```text
mid = 2

array[mid] = 20
array[mid+1] = 4
```

Since:

```text
20 > 4
```

Move left:

```text
right = 2
```

---

Iteration 2

```text
left = 0
right = 2

mid = 1

array[mid] = 3
array[mid+1] = 20
```

Since:

```text
3 < 20
```

Move right:

```text
left = 2
```

---

Now:

```text
left = right = 2
```

Peak Index:

```text
2
```

Peak Value:

```text
20
```

---

# 🔍 Example 2

Array:

```text
1 2 3 4 5
```

---

Binary Search gradually moves right.

Final answer:

```text
5
```

---

# 🔍 Example 3

Array:

```text
5 4 3 2 1
```

---

Binary Search gradually moves left.

Final answer:

```text
5
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

Peak found immediately.

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

# 📊 Visual Illustration

Example:

```text
Index

0 1 2 3 4 5

Array

1 3 8 12 4 2
      ↑
     mid
```

Since:

```text
8 < 12
```

Search:

```text
Right Half
```

---

Later:

```text
1 3 8 12 4 2
        ↑
       mid
```

Since:

```text
12 > 4
```

Search:

```text
Left Half
```

---

Eventually:

```text
12
```

is identified as a peak.

---

# 🔬 Why It Works

Suppose:

```text
arr[mid] < arr[mid + 1]
```

The sequence is rising.

Moving right must eventually lead to:

* A peak
* The end of the array

Therefore a peak exists on the right.

---

Similarly:

```text
arr[mid] > arr[mid + 1]
```

The sequence is descending.

A peak exists on the left side.

---

Thus Binary Search never discards all peaks.

---

# 📚 Types of Peaks

## Local Peak

```text
1 4 7 3 2
```

Peak:

```text
7
```

---

## Global Peak

Largest element.

```text
1 3 5 9 2
```

Peak:

```text
9
```

---

Peak Element Search guarantees:

```text
Any Valid Peak
```

not necessarily the maximum element.

---

# 🌎 Real-World Applications

## Signal Processing

Finding signal peaks.

---

## Stock Market Analysis

Finding local highs.

---

## Sensor Data Analysis

Detecting peaks in measurements.

---

## Image Processing

Feature detection.

---

## Machine Learning

Optimization landscapes.

---

## Scientific Computing

Local maxima detection.

---

## Audio Processing

Peak amplitude detection.

---

## Time-Series Analysis

Trend identification.

---

# ⚖️ Comparison With Related Algorithms

| Algorithm              | Purpose                           |
| ---------------------- | --------------------------------- |
| Binary Search          | Find target value                 |
| Peak Element Search    | Find peak position                |
| Ternary Search         | Find optimum in unimodal function |
| Search Insert Position | Find insertion location           |
| Lower Bound            | First value ≥ target              |
| Upper Bound            | First value > target              |

---

# 🔄 Peak Search vs Maximum Search

Finding maximum:

```text
Requires O(n)
```

for arbitrary arrays.

---

Finding a peak:

```text
Requires O(log n)
```

using Binary Search.

---

Example:

```text
1 3 7 5 4
```

Peak:

```text
7
```

found efficiently.

---

# ✅ Advantages

### Logarithmic Complexity

Very fast.

---

### No Sorting Required

Works on unsorted arrays.

---

### Constant Space

Memory efficient.

---

### Elegant Binary Search Application

Shows property-based searching.

---

### Useful In Optimization

Many optimization problems rely on peak finding.

---

# ❌ Disadvantages

### Returns Any Peak

Not necessarily the maximum element.

---

### Requires Random Access

Arrays preferred.

---

### Less Intuitive

Than standard Binary Search.

---

### Limited Use Cases

Compared to traditional search algorithms.

---

# 🧪 Edge Cases

### Empty Array

Handle carefully.

---

### Single Element

```text
[10]
```

Peak:

```text
10
```

---

### Two Elements

```text
[5, 10]
```

Peak:

```text
10
```

---

### Strictly Increasing

```text
1 2 3 4 5
```

Peak:

```text
5
```

---

### Strictly Decreasing

```text
5 4 3 2 1
```

Peak:

```text
5
```

---

### Duplicate Values

```text
3 3 3 3
```

Any valid position may be returned.

---

# 🎓 Interview Questions

### Easy

* What is a peak element?
* Does every array contain a peak?

---

### Medium

* Why can Binary Search be applied?
* Why compare with `mid + 1`?

---

### Advanced

* Prove a peak always exists.
* How is Peak Element Search different from Maximum Search?
* Can multiple peaks exist?

---

# 🚀 Next Algorithms

Continue with:

```text
Rotated Array Search
```

followed by:

```text
Binary Search on Answer
```

to explore more advanced Binary Search applications.

---

# 📜 License

MIT License

Free for learning, education, research, and production use.
