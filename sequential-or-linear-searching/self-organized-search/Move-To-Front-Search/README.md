# 🚀 Move-To-Front Search

<div align="center">

# Move-To-Front (MTF) Search Algorithm

A self-organizing searching algorithm that adapts to access patterns by moving recently accessed elements to the front of the list.

---

### Category

Sequential / Linear Searching → Self-Organizing Search

### Difficulty

🟡 Intermediate

### Implementations

C • C++ • Java • Python • JavaScript

</div>

---

# 📖 Overview

Move-To-Front Search (MTF Search) is a self-organizing searching algorithm.

It is based on a simple observation:

> Elements that were accessed recently are likely to be accessed again soon.

Whenever an element is found during a search operation:

```text
Move the element to the front of the list.
```

As frequently accessed elements accumulate near the front, future searches become faster.

---

# 🎯 Motivation

Consider the list:

```text
[A, B, C, D, E]
```

Suppose users repeatedly search for:

```text
D
```

With ordinary Linear Search:

```text
A → B → C → D
```

Every search requires:

```text
4 comparisons
```

---

With Move-To-Front Search:

First search:

```text
[A, B, C, D, E]
```

After finding D:

```text
[D, A, B, C, E]
```

---

Second search:

```text
D
```

Now requires:

```text
1 comparison
```

---

# 🧠 Core Idea

Every successful search performs:

```text
Search
   ↓
Found
   ↓
Move To Front
   ↓
Return Result
```

The list continuously reorganizes itself according to usage patterns.

---

# 🔬 Intuition

Move-To-Front exploits:

## Temporal Locality

Recently accessed items tend to be accessed again.

Examples:

* Browser history
* Open files
* Cache entries
* Search suggestions

---

## Access Skew

A small percentage of elements often receive most accesses.

Example:

```text
20% of elements
generate
80% of searches
```

This phenomenon is common in:

* Databases
* Web traffic
* Search engines
* Operating systems

---

# ⚙️ Algorithm Workflow

```text
Start Search
      │
      ▼
Scan Elements
      │
      ▼
Target Found?
      │
      ├── No
      │      │
      │      ▼
      │ Continue Searching
      │
      ▼
Move Element To Front
      │
      ▼
Return Index
```

---

# 📝 Pseudocode

```text
MoveToFrontSearch(list, target)

for i = 0 to n-1

    if list[i] == target

        element = list[i]

        shift all elements
        from 0 to i-1
        one position right

        list[0] = element

        return 0

return -1
```

---

# 🔍 Example

Initial List

```text
A B C D E
```

Target

```text
D
```

---

## Search

```text
A != D
B != D
C != D
D == D
```

Found.

---

## Reorganization

Move D to front.

Before:

```text
A B C D E
```

After:

```text
D A B C E
```

---

## Future Search

Search D again:

```text
D == D
```

Only one comparison required.

---

# 📊 Complexity Analysis

Assume:

```text
n = number of elements
```

---

## Search Cost

Best Case:

```text
O(1)
```

Target already at front.

---

Average Case:

```text
O(n)
```

---

Worst Case:

```text
O(n)
```

Target at end or absent.

---

## Reorganization Cost

Moving element to front requires shifting elements.

Worst Case:

```text
O(n)
```

---

## Total Complexity

| Case    | Complexity |
| ------- | ---------- |
| Best    | O(1)       |
| Average | O(n)       |
| Worst   | O(n)       |
| Space   | O(1)       |

---

# 📈 Complexity Table

| Operation     | Complexity |
| ------------- | ---------- |
| Search        | O(n)       |
| Move-To-Front | O(n)       |
| Space         | O(1)       |

---

# 🌎 Example Evolution

Initial:

```text
A B C D E F
```

---

Search:

```text
E
```

Result:

```text
E A B C D F
```

---

Search:

```text
D
```

Result:

```text
D E A B C F
```

---

Search:

```text
E
```

Result:

```text
E D A B C F
```

---

Search:

```text
E
```

Result:

```text
E D A B C F
```

No movement required.

---

Over time:

Frequently accessed elements remain near the front.

---

# 🔬 Why It Works

Suppose:

```text
D
```

is searched repeatedly.

Without adaptation:

```text
4 comparisons
every time
```

---

With MTF:

First search:

```text
4 comparisons
```

Subsequent searches:

```text
1 comparison
```

Average search cost decreases dramatically.

---

# 📚 Theoretical Foundation

Move-To-Front is closely related to:

## List Update Problem

A classical online algorithm problem.

The goal:

```text
Maintain an ordered list
while minimizing access cost.
```

---

Research has shown:

Move-To-Front is surprisingly effective and often near-optimal for many real workloads.

---

# ⚖️ Comparison With Other Self-Organizing Searches

| Feature                   | Move-To-Front | Transpose | Frequency Count |
| ------------------------- | ------------- | --------- | --------------- |
| Adaptation Speed          | Fastest       | Moderate  | Slow            |
| Extra Memory              | No            | No        | Yes             |
| Reordering Amount         | High          | Medium    | Medium          |
| Locality Exploitation     | Excellent     | Good      | Good            |
| Frequency Awareness       | Moderate      | Moderate  | Excellent       |
| Implementation Simplicity | Very Easy     | Easy      | Medium          |

---

# ✅ Advantages

## Fast Adaptation

One access is enough to move an item to the front.

---

## No Extra Memory

Uses only the original list.

---

## Easy Implementation

Simple to understand and implement.

---

## Exploits Temporal Locality

Ideal when recently accessed items are likely to be accessed again.

---

## Excellent Cache Behavior

Frequently used items remain near the front.

---

# ❌ Disadvantages

## Excessive Reordering

Single access may dramatically alter list order.

---

## Poor for Random Access

Random search patterns provide little benefit.

---

## Not Frequency-Aware

One recent access may outweigh long-term popularity.

---

Example:

```text
Popular item:
100 accesses

Rare item:
1 recent access

Rare item moves ahead.
```

---

# 🌎 Real-World Applications

## Compression Algorithms

Move-To-Front Transform is used in:

* Burrows-Wheeler Compression
* Data compression pipelines

---

## Operating Systems

Frequently accessed resources.

Examples:

* Resource tables
* Device tables

---

## Databases

Adaptive lookup lists.

---

## Browser History

Recently visited items appear first.

---

## Search Suggestions

Recently searched terms are prioritized.

---

## Caching Systems

Frequently used entries remain near the front.

---

# 🔬 Correctness

The algorithm is correct because:

1. Every element is examined sequentially.
2. No elements are skipped.
3. If target exists, it is found.
4. Reordering occurs only after finding the target.
5. Reordering preserves all elements.

Therefore:

```text
Move-To-Front Search
always returns a correct result.
```

---

# 🧪 Edge Cases

## Empty List

```text
[]
```

Return:

```text
-1
```

---

## Single Element

```text
[10]
```

Target:

```text
10
```

Return:

```text
0
```

---

## Element Already At Front

Before:

```text
D A B C
```

Search:

```text
D
```

After:

```text
D A B C
```

No change.

---

## Missing Element

```text
A B C D
```

Target:

```text
X
```

Return:

```text
-1
```

---

# 🧪 Testing Suggestions

Test:

* Empty lists
* Single-element lists
* Repeated searches
* Random access patterns
* Duplicate values
* Large datasets
* Already-front elements

---

# 🎓 Interview Questions

### Easy

* What is Move-To-Front Search?
* Why is it called self-organizing?

---

### Medium

* Explain temporal locality.
* Compare MTF and Linear Search.

---

### Advanced

* Explain the List Update Problem.
* Why does MTF perform well on skewed workloads?
* Compare MTF and Frequency Count Search.

---

# 📚 Related Algorithms

Within this repository:

```text
Self-Organizing Search
│
├── Move-To-Front Search
├── Transpose Search
└── Frequency Count Search
```

---

# 🚀 Next Algorithm

Continue with:

```text
Transpose Search
```

which uses a more conservative reordering strategy by swapping an accessed element with its immediate predecessor.

---

# 📜 License

Released under the MIT License.

Free for learning, research, education, and production use.
