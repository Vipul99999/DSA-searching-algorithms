# 🔍 Interpolation Search

Interpolation Search is an advanced searching algorithm designed for **sorted and uniformly distributed arrays**.

Unlike Binary Search, which always checks the middle element, Interpolation Search estimates the likely position of the target using a mathematical formula.

It performs significantly faster than Binary Search when values are evenly distributed.

---

# 📂 Files Included

```text
InterpolationSearch.c
InterpolationSearch.cpp
InterpolationSearch.java
InterpolationSearch.py
InterpolationSearch.js
README.md
```

---

# 📘 Algorithm Overview

Interpolation Search estimates where the target value should appear.

Instead of:

```text
mid = (low + high) / 2
```

it calculates:

```text
pos = low +
      ((target - arr[low]) × (high - low))
      /
      (arr[high] - arr[low])
```

This estimation allows jumping closer to the expected position.

---

# ⚙️ Working Process

1. Start with low and high indexes.
2. Estimate probable position.
3. Compare target with estimated position.
4. Move left or right accordingly.
5. Repeat until found.

---

# 🧮 Algorithm

```text
InterpolationSearch(arr, low, high, key)

WHILE low ≤ high

    position =
    low +
    ((key-arr[low])*(high-low))
    /
    (arr[high]-arr[low])

    IF arr[position] == key
        RETURN position

    ELSE IF arr[position] < key
        low = position + 1

    ELSE
        high = position - 1

RETURN -1
```

---

# 📈 Complexity Analysis

| Case    | Time Complexity |
| ------- | --------------- |
| Best    | O(1)            |
| Average | O(log log n)    |
| Worst   | O(n)            |

### Space Complexity

```text
O(1)
```

---

# ✅ Advantages

* Faster than Binary Search for uniform datasets
* Constant memory usage
* Efficient on large sorted arrays
* Fewer comparisons in ideal conditions

---

# ❌ Disadvantages

* Requires sorted input
* Poor performance on skewed distributions
* Can degrade to linear search

---

# 📌 Example

### Input

```text
Array:
[10,20,30,40,50,60,70,80,90]

Target:
70
```

### Output

```text
Element found at index 6
```

---

# 🧪 Sample Execution

```text
Enter number of elements:
9

Enter elements:
10 20 30 40 50 60 70 80 90

Enter target:
70

Output:
Element found at index 6
```

---

# 🌍 Language Implementations

| Language   | File                     |
| ---------- | ------------------------ |
| C          | InterpolationSearch.c    |
| C++        | InterpolationSearch.cpp  |
| Java       | InterpolationSearch.java |
| Python     | InterpolationSearch.py   |
| JavaScript | InterpolationSearch.js   |

---

# 🚀 Applications

* Database indexing
* Search engines
* Memory-efficient retrieval
* Uniform numerical datasets
* Data analytics
* Distributed systems

---

# 🔬 Comparison with Binary Search

| Feature            | Binary Search | Interpolation Search |
| ------------------ | ------------- | -------------------- |
| Partition          | Fixed         | Estimated            |
| Average Complexity | O(log n)      | O(log log n)         |
| Uniform Data       | Good          | Excellent            |
| Worst Case         | O(log n)      | O(n)                 |

---

# 🏗 Suggested Repository Structure

```text
Interpolation-Search/
│
├── InterpolationSearch.c
├── InterpolationSearch.cpp
├── InterpolationSearch.java
├── InterpolationSearch.py
├── InterpolationSearch.js
└── README.md
```

---

# ⭐ Contribution

Feel free to improve implementations and add benchmarks.

If this project helped you, consider starring the repository.

**Happy Coding 🚀**
