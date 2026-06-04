# 🔍 Adaptive Interpolation Search

Adaptive Interpolation Search is an optimized variation of **Interpolation Search** that dynamically adjusts its search strategy according to the actual distribution of values inside a sorted dataset.

Unlike standard Interpolation Search—which assumes perfectly uniform distribution—Adaptive Interpolation Search modifies position estimation during execution to maintain better performance across real-world data.

---

# 📂 Files Included

```text
AdaptiveInterpolationSearch.c
AdaptiveInterpolationSearch.cpp
AdaptiveInterpolationSearch.java
AdaptiveInterpolationSearch.py
AdaptiveInterpolationSearch.js
README.md
```

---

# 📘 Algorithm Overview

Traditional Interpolation Search predicts the target location using a fixed interpolation formula.

Adaptive Interpolation Search improves this by:

* Measuring local value distribution
* Detecting uneven spacing
* Dynamically adjusting search movement
* Falling back toward Binary Search behavior when necessary

This creates more stable performance.

---

# ⚙️ Working Principle

1. Start with low and high boundaries.
2. Estimate position using interpolation.
3. Analyze local data density.
4. Adjust probe distance adaptively.
5. Continue narrowing the search space.
6. Return index if found.

---

# 🧮 Position Estimation

Standard interpolation:

```text
position =
low +
((target-arr[low])*(high-low))
/
(arr[high]-arr[low])
```

Adaptive version:

```text
position =
interpolation_prediction
+
adaptive_adjustment
```

Adjustment depends on:

* Distribution density
* Previous probes
* Distance from target

---

# 📈 Complexity Analysis

| Case    | Complexity   |
| ------- | ------------ |
| Best    | O(1)         |
| Average | O(log log n) |
| Worst   | O(log n)     |

---

## Space Complexity

```text
O(1)
```

---

# ✅ Advantages

* Handles non-uniform distributions better
* More reliable than classic interpolation
* Reduces worst-case degradation
* Maintains fast average performance
* Suitable for practical datasets

---

# ❌ Disadvantages

* Slightly more computational overhead
* More implementation complexity
* Limited use in standard libraries

---

# 📌 Example

### Input

```text
Array:
[5, 10, 14, 22, 35, 40, 100, 250]

Target:
100
```

### Search Process

```text
Estimate →
Adjust →
Probe →
Locate
```

### Output

```text
Element found at index 6
```

---

# 🧪 Sample Execution

```text
Enter number of elements:
8

Enter elements:
5 10 14 22 35 40 100 250

Enter target:
100

Output:
Element found at index 6
```

---

# 📊 Comparison

| Feature          | Binary Search | Interpolation Search | Adaptive Interpolation |
| ---------------- | ------------- | -------------------- | ---------------------- |
| Uniform Data     | Good          | Excellent            | Excellent              |
| Non-uniform Data | Stable        | Weak                 | Strong                 |
| Average Time     | O(log n)      | O(log log n)         | O(log log n)           |
| Worst Time       | O(log n)      | O(n)                 | O(log n)               |

---

# 🏗 Algorithm Flow

```text
Start

↓

Estimate Position

↓

Check Distribution

↓

Adjust Position

↓

Move Search Window

↓

Target Found?

YES → Return Index

NO → Continue

↓

Not Found
```

---

# 🌍 Language Implementations

| Language   | File                             |
| ---------- | -------------------------------- |
| C          | AdaptiveInterpolationSearch.c    |
| C++        | AdaptiveInterpolationSearch.cpp  |
| Java       | AdaptiveInterpolationSearch.java |
| Python     | AdaptiveInterpolationSearch.py   |
| JavaScript | AdaptiveInterpolationSearch.js   |

---

# 🚀 Applications

* Large database indexing
* Search optimization
* Analytics systems
* Information retrieval
* Memory-efficient searching
* Distributed datasets
* Real-world uneven numerical data

---

# 🏗 Suggested Repository Structure

```text
Adaptive-Interpolation-Search/
│
├── AdaptiveInterpolationSearch.c
├── AdaptiveInterpolationSearch.cpp
├── AdaptiveInterpolationSearch.java
├── AdaptiveInterpolationSearch.py
├── AdaptiveInterpolationSearch.js
└── README.md
```

---

# 📚 Prerequisites

Before implementing this algorithm:

* Arrays must be sorted
* Understand Binary Search
* Understand Interpolation Search
* Know average/worst-case tradeoffs

---

# ⭐ Contribution

Contributions and performance improvements are welcome.

If this repository helped you, consider giving it a star.

**Happy Coding 🚀**
