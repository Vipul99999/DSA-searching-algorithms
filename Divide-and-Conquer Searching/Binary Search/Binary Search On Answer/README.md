# 🎯 Binary Search on Answer

<div align="center">

# Binary Search on Answer Algorithm

A powerful optimization technique that applies Binary Search to the solution space instead of directly searching for an element.

---

### Category

Searching Algorithms → Divide-and-Conquer Searching → Binary Search Family

### Difficulty

🔴 Advanced

### Implementations

C • C++ • Java • Python • JavaScript

</div>

---

# 📖 Overview

Binary Search on Answer is one of the most important advanced applications of Binary Search.

Unlike traditional Binary Search:

```text
Search Value
```

Binary Search on Answer performs:

```text
Search Solution Space
```

Instead of searching an array element, we search for the optimal answer that satisfies a condition.

---

# 🎯 Core Idea

Suppose we need to find:

```text
Minimum Possible Value
```

or

```text
Maximum Possible Value
```

that satisfies a certain requirement.

Rather than testing every possible answer:

```text
1
2
3
4
5
...
```

we use Binary Search to efficiently find the correct solution.

---

# 🧠 Key Observation

Binary Search on Answer works when the problem exhibits a:

```text
Monotonic Property
```

Meaning:

```text
False False False False True True True True
```

or

```text
True True True True False False False False
```

A clear transition point exists.

That transition point becomes the answer.

---

# 🔬 Visual Representation

Example:

```text
Answer Space

1 2 3 4 5 6 7 8 9 10

✗ ✗ ✗ ✗ ✓ ✓ ✓ ✓ ✓ ✓
```

The first:

```text
✓
```

is the answer.

Binary Search finds it efficiently.

---

# ⚙️ Algorithm Workflow

```text
Start
  │
  ▼
Define Search Space
  │
  ▼
Choose Mid Answer
  │
  ▼
Check Feasibility
  │
  ├── Valid
  │      │
  │      ▼
  │ Search Better Answer
  │
  └── Invalid
         │
         ▼
    Search Other Half
  │
  ▼
Repeat
  │
  ▼
Optimal Answer
```

---

# 📊 Traditional Binary Search

Normal Binary Search:

```text
Array

1 3 5 7 9 11
```

Search:

```text
7
```

Goal:

```text
Find Existing Element
```

---

# 🎯 Binary Search on Answer

Search Space:

```text
1 2 3 4 5 6 7 8 9 10
```

Goal:

```text
Find Smallest Valid Answer
```

No actual sorted array is required.

Only a monotonic condition.

---

# 📝 Generic Pseudocode

```text
BinarySearchOnAnswer()

left = minimum_possible_answer
right = maximum_possible_answer

answer = right

while left <= right

    mid = left + (right - left) / 2

    if isPossible(mid)

        answer = mid
        right = mid - 1

    else

        left = mid + 1

return answer
```

---

# 🔍 Example 1: Minimum Eating Speed

Popular interview problem.

Given:

```text
Bananas
```

Find the minimum eating speed.

---

Search Space:

```text
1
...
max(pile)
```

---

Check:

```text
Can speed = k
finish all bananas?
```

If:

```text
YES
```

try a smaller speed.

---

If:

```text
NO
```

increase speed.

---

# 🔍 Example 2: Allocate Books

Given:

```text
Books
Students
```

Find:

```text
Minimum Possible Maximum Pages
```

assigned to any student.

---

Answer Space:

```text
max(book)
...
sum(book)
```

Binary Search over answers.

---

# 🔍 Example 3: Painter's Partition

Find:

```text
Minimum Time
```

needed to paint boards.

---

Instead of searching boards:

```text
Search Time
```

---

# 🔍 Example 4: Capacity To Ship Packages

Find:

```text
Minimum Ship Capacity
```

required to transport packages within given days.

---

Answer Space:

```text
max(weight)
...
sum(weight)
```

---

# 🔬 Monotonic Predicate

The most important concept.

Suppose:

```text
Answer = x
```

Check:

```text
isPossible(x)
```

Example:

```text
1 → False
2 → False
3 → False
4 → True
5 → True
6 → True
```

Once it becomes:

```text
True
```

it stays:

```text
True
```

This monotonic behavior enables Binary Search.

---

# 📊 Example Walkthrough

Find minimum valid answer.

Search Space:

```text
1 2 3 4 5 6 7 8
```

---

Iteration 1

```text
mid = 4
```

Check:

```text
Valid
```

Move left.

---

Iteration 2

```text
mid = 2
```

Check:

```text
Invalid
```

Move right.

---

Iteration 3

```text
mid = 3
```

Check:

```text
Invalid
```

Move right.

---

Final:

```text
4
```

Answer found.

---

# 📈 Complexity Analysis

Assume:

```text
R = Answer Range

right - left
```

and

```text
F = Feasibility Check Cost
```

---

Binary Search iterations:

```text
O(log R)
```

---

Total Complexity:

```text
O(F × log R)
```

---

# 📊 Complexity Table

| Operation                | Complexity   |
| ------------------------ | ------------ |
| Binary Search Iterations | O(log R)     |
| Feasibility Check        | O(F)         |
| Total                    | O(F × log R) |
| Space                    | O(1)         |

---

# 🔬 Why It Works

Binary Search requires:

```text
Sorted Property
```

Binary Search on Answer replaces sorting with:

```text
Monotonic Property
```

If answers can be divided into:

```text
Invalid
↓
Valid
```

or

```text
Valid
↓
Invalid
```

Binary Search can locate the boundary.

---

# 🌎 Real-World Applications

## Resource Allocation

Servers.

Memory.

Storage.

Bandwidth.

---

## Cloud Computing

Capacity planning.

---

## Logistics

Truck loading.

Package shipping.

Delivery optimization.

---

## Manufacturing

Machine scheduling.

Production planning.

---

## Networking

Minimum bandwidth determination.

---

## Databases

Optimal partition sizing.

---

## Operating Systems

CPU allocation.

Task scheduling.

---

## Competitive Programming

One of the most frequently used advanced techniques.

---

# ⚖️ Binary Search vs Binary Search on Answer

| Feature                      | Binary Search | Binary Search on Answer |
| ---------------------------- | ------------- | ----------------------- |
| Searches Array               | Yes           | No                      |
| Searches Solution Space      | No            | Yes                     |
| Requires Sorted Data         | Yes           | No                      |
| Requires Monotonic Condition | No            | Yes                     |
| Difficulty                   | Easy          | Advanced                |
| Interview Frequency          | High          | Very High               |

---

# 🔄 Common Problem Patterns

## Minimize Maximum

Examples:

```text
Allocate Books
Painter Partition
Ship Capacity
```

---

## Maximize Minimum

Examples:

```text
Aggressive Cows
Magnetic Force
Router Placement
```

---

## Find Threshold

Examples:

```text
Minimum Speed
Minimum Capacity
Minimum Time
```

---

## Optimization Problems

Most optimization problems with monotonic answers.

---

# 🚨 Common Mistakes

## Wrong Search Space

Incorrect lower and upper bounds.

---

## Non-Monotonic Predicate

Binary Search fails.

---

## Overflow In Mid Calculation

Avoid:

```text
(left + right) / 2
```

Use:

```text
left + (right - left) / 2
```

---

## Incorrect Feasibility Function

Most bugs occur here.

---

## Returning Wrong Boundary

Confusing:

```text
left
right
answer
```

---

# 🧪 Edge Cases

### Single Answer

```text
left == right
```

---

### Extremely Large Range

```text
1 → 10^18
```

Still efficient.

---

### Impossible Cases

Return special value if no valid answer exists.

---

### Large Input Sizes

Often designed for:

```text
10^5
10^6
```

elements.

---

# 🎓 Interview Questions

### Easy

* What is Binary Search on Answer?
* How is it different from Binary Search?

---

### Medium

* What is a monotonic predicate?
* Why does the technique work?

---

### Advanced

* Explain Aggressive Cows.
* Explain Allocate Books.
* Explain Painter Partition.
* Design a feasibility function.
* Prove correctness.

---

# 📚 Famous Problems

```text
Allocate Books
Painter's Partition
Aggressive Cows
Ship Packages Within D Days
Koko Eating Bananas
Minimum Days To Make Bouquets
Magnetic Force Between Balls
Split Array Largest Sum
Minimum Speed To Arrive On Time
```

---

# 📜 License

MIT License

Free for learning, education, research, and production use.
