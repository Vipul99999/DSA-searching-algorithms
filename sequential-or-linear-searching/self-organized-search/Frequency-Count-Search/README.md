# 📊 Frequency Count Search

<div align="center">

# Frequency Count Search Algorithm

A self-organizing search algorithm that dynamically rearranges elements based on how frequently they are accessed.

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

Frequency Count Search is a self-organizing searching algorithm that improves search efficiency by maintaining elements in descending order of access frequency.

Every time an element is successfully searched:

1. Its frequency counter is increased.
2. The element is repositioned according to its updated frequency.
3. Frequently accessed elements gradually move toward the front.

Unlike Move-To-Front Search, which focuses on recent accesses, Frequency Count Search focuses on long-term popularity.

---

# 🎯 Motivation

Consider the following list:

```text
A B C D E
````

Access frequencies:

```text
A → 2
B → 15
C → 7
D → 25
E → 1
```

A better ordering would be:

```text
D B C A E
```

because the most frequently searched items appear first.

As a result:

```text
Average Search Cost
↓
Search Efficiency
↑
```

---

# 🧠 Core Idea

Frequently accessed items should require fewer comparisons.

After every successful search:

```text
Search
   ↓
Increment Frequency
   ↓
Reorder List
   ↓
Return Result
```

The list continuously adapts to actual usage patterns.

---

# 🔬 Fundamental Principle

Frequency Count Search exploits:

## Frequency Locality

Elements that have been frequently accessed in the past are likely to be frequently accessed in the future.

Examples:

* Popular webpages
* Trending products
* Database records
* Frequently used commands
* Search engine queries

---

# ⚙️ Algorithm Workflow

```text
Start Search
      │
      ▼
Sequential Scan
      │
      ▼
Target Found?
      │
      ├── No
      │      │
      │      ▼
      │ Return -1
      │
      ▼
Increase Frequency
      │
      ▼
Reposition Element
      │
      ▼
Return Result
```

---

# 📝 Pseudocode

```text
FrequencyCountSearch(list, freq, target)

for i = 0 to n-1

    if list[i] == target

        freq[i]++

        while i > 0
              and freq[i] > freq[i-1]

            swap(freq[i], freq[i-1])
            swap(list[i], list[i-1])

            i--

        return i

return -1
```

---

# 🔍 Example

Initial List

```text
A B C D E
```

Frequency Table

```text
A → 3
B → 5
C → 2
D → 1
E → 0
```

---

Search:

```text
D
```

Frequency Update:

```text
D → 2
```

New Table

```text
A → 3
B → 5
C → 2
D → 2
E → 0
```

---

Search D Again

Frequency Update:

```text
D → 3
```

Now:

```text
A → 3
B → 5
D → 3
C → 2
E → 0
```

---

Search D Again

Frequency Update:

```text
D → 4
```

Reorder:

```text
B → 5
D → 4
A → 3
C → 2
E → 0
```

List becomes:

```text
B D A C E
```

---

# 📈 Evolution Example

Initial:

```text
A B C D E
```

Frequency:

```text
0 0 0 0 0
```

---

Search D

```text
0 0 0 1 0
```

List:

```text
D A B C E
```

---

Search D

```text
2 0 0 0 0
```

List:

```text
D A B C E
```

---

Search B

```text
2 1 0 0 0
```

List:

```text
D B A C E
```

---

Search B

```text
2 2 0 0 0
```

List:

```text
D B A C E
```

---

Search B

```text
2 3 0 0 0
```

List:

```text
B D A C E
```

---

Over time:

```text
Most Frequently Accessed Elements
Move Toward Front
```

---

# 📊 Complexity Analysis

Assume:

```text
n = number of elements
```

---

## Search Cost

Best Case

```text
O(1)
```

Target already at front.

---

Average Case

```text
O(n)
```

---

Worst Case

```text
O(n)
```

Target at end or absent.

---

## Reorganization Cost

Worst-case repositioning:

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
| Space   | O(n)       |

---

# 📈 Complexity Table

| Operation        | Complexity |
| ---------------- | ---------- |
| Search           | O(n)       |
| Frequency Update | O(1)       |
| Reordering       | O(n)       |
| Space            | O(n)       |

---

# 🔬 Why It Works

Many real-world systems follow:

## Zipf's Law

A small fraction of items receives most accesses.

Example:

```text
20% of items
generate
80% of accesses
```

Frequency Count Search automatically places those popular items near the front.

---

# ⚖️ Comparison With Other Self-Organizing Searches

| Feature              | Move-To-Front | Transpose | Frequency Count |
| -------------------- | ------------- | --------- | --------------- |
| Adaptation Speed     | Fast          | Medium    | Slow            |
| Long-Term Learning   | Poor          | Moderate  | Excellent       |
| Extra Memory         | No            | No        | Yes             |
| Reordering Stability | Low           | High      | High            |
| Frequency Awareness  | No            | Partial   | Yes             |
| Temporal Locality    | Excellent     | Good      | Moderate        |

---

# 📊 Comparison Example

Suppose:

```text
A accessed 100 times
B accessed once recently
```

---

## Move-To-Front

Recent access dominates.

```text
B A ...
```

---

## Frequency Count

Long-term popularity dominates.

```text
A B ...
```

This makes Frequency Count Search more stable.

---

# 🌎 Real-World Applications

## Search Engines

Popular search terms.

---

## Database Systems

Frequently accessed records.

---

## Web Caches

Popular content.

---

## Recommendation Systems

Frequently viewed products.

---

## Operating Systems

Frequently used resources.

---

## Information Retrieval

Popular documents and indexes.

---

## DNS Systems

Frequently queried domains.

---

# 🔬 Correctness

Frequency Count Search is correct because:

1. Every element is checked sequentially.
2. No element is skipped.
3. Frequency updates occur only after successful search.
4. Reordering preserves all elements.
5. Elements remain associated with their frequencies.

Therefore:

```text
Frequency Count Search
always returns correct results.
```

---

# ✅ Advantages

## Learns Long-Term Behavior

Captures overall popularity.

---

## Stable Ordering

Less sensitive to temporary spikes.

---

## Better For Repeated Workloads

Frequently searched elements naturally rise.

---

## Simple Concept

Easy to understand and implement.

---

## Adaptive

Performance improves automatically over time.

---

# ❌ Disadvantages

## Extra Memory Required

Frequency counters must be stored.

---

## Slower Adaptation

Recently popular elements may take time to move upward.

---

## Reordering Cost

Position adjustments can be expensive.

---

## Worst-Case Complexity Unchanged

Still:

```text
O(n)
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

Return:

```text
0
```

---

## Duplicate Elements

Careful handling required.

Each element should maintain its own frequency.

---

## Equal Frequencies

Ordering policy should be defined.

Common choices:

* Stable ordering
* Recent ordering
* Original ordering

---

## Missing Element

Return:

```text
-1
```

No frequency update.

---

# 🧪 Testing Suggestions

Test:

* Empty lists
* Single-element lists
* Equal frequencies
* Repeated searches
* Random workloads
* Highly skewed workloads
* Large datasets
* Duplicate values

---

# 📚 Relationship To Other Algorithms

```text
Self-Organizing Search
│
├── Move-To-Front Search
│
├── Transpose Search
│
└── Frequency Count Search
```

---

# 📚 Related Concepts

* Locality of Reference
* Zipf's Law
* Adaptive Data Structures
* Self-Organizing Lists
* Caching Algorithms
* Information Retrieval

---

# 🎓 Interview Questions

### Easy

* What is Frequency Count Search?
* How does it differ from Linear Search?

---

### Medium

* Compare Frequency Count and Move-To-Front Search.
* Why does Frequency Count require additional memory?

---

### Advanced

* Explain Zipf's Law and its relation to Frequency Count Search.
* Why is Frequency Count more stable than Move-To-Front Search?
* Compare long-term and short-term adaptation strategies.

---

# 🚀 Next Algorithms

Continue with:

```text
Divide-and-Conquer Searching
│
├── Binary Search
├── Ternary Search
└── Fractional Cascading Search
```

which improve search complexity from:

```text
O(n)
```

to:

```text
O(log n)
```

for ordered datasets.

---

# 📜 License

Released under the MIT License.

Free for learning, education, research, and production use.


and maintains a consistent professional style across the repository.
