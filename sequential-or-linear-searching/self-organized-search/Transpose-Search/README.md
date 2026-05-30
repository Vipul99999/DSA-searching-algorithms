# 🔄 Transpose Search

<div align="center">

# Transpose Search Algorithm

A self-organizing searching algorithm that gradually improves search performance by swapping accessed elements with their immediate predecessor.

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

Transpose Search is a self-organizing search algorithm.

Unlike ordinary Linear Search, which leaves the collection unchanged after a search, Transpose Search adapts the ordering of elements according to access patterns.

Whenever an element is successfully found:

```text
Swap it with the element immediately before it.
```

This gradual movement allows frequently accessed elements to migrate toward the front of the list over time.

---

# 🎯 Motivation

Consider the following list:

```text
A B C D E
```

Suppose users repeatedly search for:

```text
D
```

Ordinary Linear Search always requires:

```text
A → B → C → D
```

or:

```text
4 comparisons
```

for every search.

---

Transpose Search improves performance incrementally.

First search:

```text
A B C D E
```

After transposition:

```text
A B D C E
```

---

Second search:

```text
A B D C E
```

After transposition:

```text
A D B C E
```

---

Third search:

```text
A D B C E
```

After transposition:

```text
D A B C E
```

Now future searches become significantly faster.

---

# 🧠 Core Idea

Instead of moving a found element directly to the front:

```text
Move-To-Front Search
↓
Aggressive Reordering
```

Transpose Search performs:

```text
Found Element
↓
Swap With Previous Element
↓
Return Result
```

This creates smoother and more stable adaptation.

---

# 🔬 Why It Works

Transpose Search exploits:

## Temporal Locality

Recently accessed elements are likely to be accessed again.

Examples:

* Browser history
* Open files
* Cache entries
* User sessions

---

## Access Frequency

Frequently accessed elements gradually drift toward the front.

Unlike Move-To-Front:

```text
One access
≠
Move directly to front
```

which helps preserve ordering stability.

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
      │ Continue Searching
      │
      ▼
Swap With Previous Element
      │
      ▼
Return Result
```

---

# 📝 Pseudocode

```text
TransposeSearch(list, target)

for i = 0 to n-1

    if list[i] == target

        if i > 0

            swap(list[i], list[i-1])

        return i

return -1
```

---

# 🔍 Example

Initial List

```text
10 20 30 40 50
```

Target

```text
40
```

---

## Search

```text
10 != 40
20 != 40
30 != 40
40 == 40
```

Found at:

```text
Index 3
```

---

## Transpose

Swap:

```text
40 ↔ 30
```

Result:

```text
10 20 40 30 50
```

---

# 📈 Multiple Searches Example

Initial:

```text
A B C D E
```

---

Search:

```text
D
```

Result:

```text
A B D C E
```

---

Search:

```text
D
```

Result:

```text
A D B C E
```

---

Search:

```text
D
```

Result:

```text
D A B C E
```

---

Notice:

```text
D gradually moves forward.
```

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

Element already at front.

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

Element at end or absent.

---

## Transposition Cost

Single swap:

```text
O(1)
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

| Operation | Complexity |
| --------- | ---------- |
| Search    | O(n)       |
| Swap      | O(1)       |
| Total     | O(n)       |
| Space     | O(1)       |

---

# 🔬 Comparison With Move-To-Front

Move-To-Front:

```text
A B C D E

Search D

D A B C E
```

One search completely changes ordering.

---

Transpose Search:

```text
A B C D E

Search D

A B D C E
```

Only one small adjustment.

---

This makes Transpose Search:

```text
More Stable
Less Aggressive
```

---

# ⚖️ Algorithm Comparison

| Feature           | Linear Search | Move-To-Front | Transpose Search |
| ----------------- | ------------- | ------------- | ---------------- |
| Adaptive          | No            | Yes           | Yes              |
| Reordering        | None          | High          | Low              |
| Extra Memory      | No            | No            | No               |
| Search Complexity | O(n)          | O(n)          | O(n)             |
| Stability         | High          | Low           | High             |
| Adaptation Speed  | None          | Fast          | Medium           |

---

# 🌎 Real-World Applications

## Adaptive Lookup Tables

Frequently accessed entries move toward optimal positions.

---

## Operating Systems

Dynamic resource tables.

Examples:

* Device lists
* Process tables
* Resource tracking

---

## Databases

Adaptive indexing structures.

---

## Caching Systems

Gradual cache optimization.

---

## Networking

Routing and lookup optimizations.

---

## Interactive Systems

User preferences and frequently accessed commands.

---

# 🔬 Theoretical Properties

Transpose Search belongs to the family of:

```text
Self-Organizing Lists
```

which attempt to minimize future search costs based on previous accesses.

---

Unlike Move-To-Front:

```text
Immediate adaptation
```

Transpose Search uses:

```text
Incremental adaptation
```

which often produces more stable ordering.

---

# ✅ Advantages

## Simple Implementation

Only one swap is required.

---

## No Extra Memory

Operates directly on the original list.

---

## Stable Reordering

Ordering changes gradually.

---

## Good Practical Performance

Frequently accessed elements slowly migrate toward the front.

---

## Low Maintenance Cost

Each reorganization requires only:

```text
O(1)
```

time.

---

# ❌ Disadvantages

## Slower Adaptation

Frequently accessed items require multiple searches to reach the front.

---

## Worst Case Remains O(n)

No asymptotic improvement.

---

## Limited Benefit For Random Access

Random workloads provide little advantage.

---

# 🔍 Correctness

Transpose Search is correct because:

1. Every element is examined sequentially.
2. No elements are skipped.
3. Target is returned immediately when found.
4. Transposition occurs only after a successful match.
5. Swapping preserves all elements.

Therefore:

```text
Transpose Search always returns correct results.
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

Search:

```text
10
```

Return:

```text
0
```

No swap required.

---

## Element Already At Front

Before:

```text
D A B C
```

After:

```text
D A B C
```

No change.

---

## Element At End

Before:

```text
A B C D E
```

Search:

```text
E
```

After:

```text
A B C E D
```

Single swap.

---

## Missing Element

Return:

```text
-1
```

No reorganization.

---

# 🧪 Testing Suggestions

Test:

* Empty lists
* Single-element lists
* Already-front elements
* End-position elements
* Repeated searches
* Duplicate values
* Large datasets
* Random workloads

---

# 🎓 Interview Questions

### Easy

* What is Transpose Search?
* How does it differ from Linear Search?

---

### Medium

* Compare Move-To-Front and Transpose Search.
* Why does Transpose Search preserve ordering better?

---

### Advanced

* Explain self-organizing lists.
* Compare adaptation speed of MTF and Transpose.
* Why is transposition considered a stable optimization?

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
Frequency Count Search
```

which organizes elements according to long-term access frequency rather than recent access history.

---

# 📜 License

Released under the MIT License.

Free for learning, teaching, research, and production use.
