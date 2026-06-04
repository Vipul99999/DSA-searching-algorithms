# 🔍 Quadratic Binary Search

Quadratic Binary Search is a searching technique that extends the idea of **Binary Search** by introducing **quadratic position estimation** to accelerate convergence toward the target element.

Instead of always dividing the search interval exactly in half, this approach estimates a more favorable probe position using a quadratic progression.

It is mainly used as an experimental or optimized searching strategy for specific distributions.

---

# 📂 Files Included

```text
QuadraticBinarySearch.c
QuadraticBinarySearch.cpp
QuadraticBinarySearch.java
QuadraticBinarySearch.py
QuadraticBinarySearch.js
README.md
```

---

# 📘 Algorithm Overview

Traditional Binary Search:

```text
mid = (low + high) / 2
```

Quadratic Binary Search attempts to predict a better position using quadratic movement:

```text
position = low + k²
```

where:

* `k` changes dynamically
* search range narrows after every probe
* estimation attempts faster convergence

The goal is reducing unnecessary comparisons.

---

# ⚙️ Working Principle

1. Start with sorted array boundaries.
2. Estimate probe position using quadratic progression.
3. Compare target with estimated value.
4. Reduce search interval.
5. Repeat until found.

---

# 🧮 Pseudocode

```text
QuadraticBinarySearch(arr, target)

low = 0
high = n - 1

WHILE low <= high

    estimate position

    IF found
        return index

    ELSE IF target < value
        move left

    ELSE
        move right

RETURN -1
```

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

* Potentially fewer comparisons
* Faster convergence for suitable datasets
* Maintains logarithmic worst-case behavior
* Can outperform classic binary search in some cases

---

# ❌ Disadvantages

* More complex implementation
* Benefits depend on data characteristics
* Not widely adopted in standard libraries

---

# 📌 Example

### Input

```text
Array:
[10,20,30,40,50,60,70,80,90]

Target:
80
```

### Search

```text
Quadratic estimate
↓

Probe
↓

Shrink interval
↓

Found
```

### Output

```text
Element found at index 7
```

---

# 🧪 Sample Execution

```text
Enter number of elements:
9

Enter array:
10 20 30 40 50 60 70 80 90

Enter target:
80

Output:
Element found at index 7
```

---

# 📊 Comparison

| Feature       | Binary Search | Interpolation Search | Quadratic Binary |
| ------------- | ------------- | -------------------- | ---------------- |
| Mid Selection | Fixed         | Estimated            | Quadratic        |
| Average       | O(log n)      | O(log log n)         | O(log log n)     |
| Worst         | O(log n)      | O(n)                 | O(log n)         |
| Uniform Data  | Good          | Excellent            | Very Good        |

---

# 🏗 Search Flow

```text
Start

↓

Estimate Position

↓

Compare

↓

Move Left / Right

↓

Repeat

↓

Found / Not Found
```

---

# 🌍 Language Implementations

| Language   | File                       |
| ---------- | -------------------------- |
| C          | QuadraticBinarySearch.c    |
| C++        | QuadraticBinarySearch.cpp  |
| Java       | QuadraticBinarySearch.java |
| Python     | QuadraticBinarySearch.py   |
| JavaScript | QuadraticBinarySearch.js   |

---

# 🚀 Applications

* Experimental search systems
* Search optimization research
* Large sorted datasets
* Performance analysis
* Academic algorithm studies
* Information retrieval

---

# 🏗 Suggested Repository Structure

```text
Quadratic-Binary-Search/
│
├── QuadraticBinarySearch.c
├── QuadraticBinarySearch.cpp
├── QuadraticBinarySearch.java
├── QuadraticBinarySearch.py
├── QuadraticBinarySearch.js
└── README.md
```

---

# 📚 Prerequisites

Before implementing:

* Arrays must be sorted
* Understand Binary Search
* Understand search complexity
* Know estimation-based searching

---

# ⭐ Contribution

Feel free to improve estimation methods and benchmark results.

If this repository helped you, consider giving it a star.

**Happy Coding 🚀**
