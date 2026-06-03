# Jump Search

Jump Search is an efficient searching algorithm designed for **sorted datasets**. Instead of checking every element sequentially, it skips fixed-size intervals and narrows the search to a smaller region before performing a linear scan.

This approach reduces the total number of comparisons and provides better performance than linear search while remaining simpler than binary search.

---

## Table of Contents

* Introduction
* Idea Behind Jump Search
* Algorithm Workflow
* Example
* Complexity Analysis
* Advantages
* Limitations
* Applications
* Comparison with Other Algorithms
* Conclusion

---

# Introduction

Linear Search scans elements one by one:

```text
1 → 2 → 3 → 4 → 5 → ...
```

Jump Search improves this process by making controlled jumps.

Example:

```text
1 → 4 → 7 → 10
         ↓
     Linear Scan
```

This reduces unnecessary comparisons.

---

# Idea Behind Jump Search

Jump Search divides traversal into two phases:

### Phase 1 — Jump

Move forward using a fixed step size.

### Phase 2 — Linear Search

Once the target range is found, perform sequential search.

Optimal jump size:

```text
√n
```

where:

* `n` = total elements

---

# Algorithm Workflow

```text
Start
 ↓
Jump Forward
 ↓
Target Range Found?
 ↓
Linear Search
 ↓
Return Result
```

---

# Example

Dataset:

```text
[2, 5, 8, 12, 16, 21, 29, 35, 42, 50]
```

Search:

```text
Target = 29
```

Jump size:

```text
√10 ≈ 3
```

Execution:

```text
2 → 12 → 21 → 35
          ↓
Search Range:
21 → 29
```

Result:

```text
Found at Index 6
```

---

# Complexity Analysis

| Case    | Complexity |
| ------- | ---------- |
| Best    | O(1)       |
| Average | O(√n)      |
| Worst   | O(√n)      |

Space Complexity:

```text
O(1)
```

---

# Advantages

* Faster than linear search
* Simple implementation
* Requires no extra memory
* Efficient for medium-sized sorted datasets

---

# Limitations

* Works only on sorted data
* Slower than binary search
* Fixed jump sizes may reduce efficiency

---

# Applications

* Indexed searching
* Sorted arrays
* Sequential storage systems
* Lightweight lookup systems

---

# Comparison

| Algorithm     | Average Time |
| ------------- | ------------ |
| Linear Search | O(n)         |
| Jump Search   | O(√n)        |
| Binary Search | O(log n)     |

---

# Conclusion

Jump Search improves retrieval efficiency by skipping portions of sorted data and limiting detailed examination to smaller ranges. It provides a practical middle ground between linear and binary search.
