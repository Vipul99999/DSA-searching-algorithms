# 🔍 Distribution-Based Searching Algorithms

A collection of advanced **distribution-aware searching algorithms** that improve searching performance by exploiting the expected distribution of data rather than relying only on fixed partitioning.

These algorithms are especially useful when data is **sorted** and values are **uniformly or predictably distributed**.

---

## 📚 Included Algorithms

### 1. Interpolation Search
### 2. Adaptive Interpolation Search
### 3. Quadratic Binary Search
### 4. Interpolation-Binary Hybrid Search

---

# 1. Interpolation Search

## Overview
Interpolation Search is an improved version of Binary Search for **uniformly distributed sorted arrays**.

Instead of checking the middle element, it estimates the probable position using interpolation.

### Formula

```text
pos = low + ((key − arr[low]) × (high − low))
              / (arr[high] − arr[low])
```

---

## Time Complexity

| Case | Complexity |
|------|------------|
| Best | O(1) |
| Average | O(log log n) |
| Worst | O(n) |

---

## Space Complexity

```text
O(1)
```

---

## Advantages

✔ Extremely fast on uniformly distributed data  
✔ Better than Binary Search in ideal conditions  
✔ Constant memory usage

---

## Disadvantages

✖ Performance degrades on skewed distributions  
✖ Requires sorted data

---

## Example

```text
Array:
[10,20,30,40,50,60,70]

Search: 50

Estimated position → index 4
```

---

# 2. Adaptive Interpolation Search

## Overview

Adaptive Interpolation Search dynamically adjusts the interpolation strategy based on actual data distribution.

It improves reliability when data is partially non-uniform.

---

## Working Principle

1. Estimate using interpolation.
2. Evaluate local distribution.
3. Adjust probing distance.
4. Continue recursively/iteratively.

---

## Time Complexity

| Case | Complexity |
|------|------------|
| Best | O(1) |
| Average | O(log log n) |
| Worst | O(log n) |

---

## Space Complexity

```text
O(1)
```

---

## Advantages

✔ More stable than Interpolation Search  
✔ Handles irregular distributions  
✔ Reduces worst-case degradation

---

## Disadvantages

✖ Slightly more computational overhead  
✖ More implementation complexity

---

## Example

```text
Uniform region:
Fast interpolation

Dense region:
Adjust toward binary behavior
```

---

# 3. Quadratic Binary Search

## Overview

Quadratic Binary Search combines:

- Binary Search partitioning
- Quadratic prediction of search position

It attempts to predict the target location more accurately than standard midpoint division.

---

## Working Principle

Instead of:

```text
mid = (low + high)/2
```

Quadratic estimation approximates:

```text
position ≈ low + k²
```

where k adapts during iterations.

---

## Time Complexity

| Case | Complexity |
|------|------------|
| Best | O(1) |
| Average | O(log log n) |
| Worst | O(log n) |

---

## Space Complexity

```text
O(1)
```

---

## Advantages

✔ Faster convergence in some distributions  
✔ Better than classic binary search for clustered values

---

## Disadvantages

✖ Rarely used in production  
✖ Complex tuning

---

# 4. Interpolation-Binary Hybrid Search

## Overview

Hybrid Search combines:

- **Interpolation Search** for prediction
- **Binary Search** for fallback

This achieves both speed and stability.

---

## Algorithm

```text
IF distribution is uniform:
    Use Interpolation

ELSE:
    Use Binary Search
```

---

## Time Complexity

| Case | Complexity |
|------|------------|
| Best | O(1) |
| Average | O(log log n) |
| Worst | O(log n) |

---

## Space Complexity

```text
O(1)
```

---

## Advantages

✔ Robust across datasets  
✔ Avoids interpolation worst cases  
✔ Production-friendly

---

## Disadvantages

✖ Slightly more logic

---

## Example

```text
Dataset:
[5,12,19,27,1000]

Interpolation →
Prediction unstable

Fallback →
Binary Search
```

---

# 📊 Algorithm Comparison

| Algorithm | Best | Average | Worst | Uniform Data | Non-Uniform Data |
|-----------|------|---------|-------|-------------|----------------|
| Interpolation | O(1) | O(log log n) | O(n) | ⭐⭐⭐⭐⭐ | ⭐ |
| Adaptive Interpolation | O(1) | O(log log n) | O(log n) | ⭐⭐⭐⭐ | ⭐⭐⭐⭐ |
| Quadratic Binary | O(1) | O(log log n) | O(log n) | ⭐⭐⭐ | ⭐⭐⭐ |
| Interpolation-Binary Hybrid | O(1) | O(log log n) | O(log n) | ⭐⭐⭐⭐⭐ | ⭐⭐⭐⭐⭐ |

---

# 🧠 When To Use

| Scenario | Recommended |
|----------|-------------|
| Uniform sorted data | Interpolation Search |
| Real-world datasets | Adaptive Interpolation |
| Experimental optimization | Quadratic Binary |
| Production systems | Interpolation-Binary Hybrid |

---

# 🚀 Applications

- Database indexing
- Search engines
- Memory optimization
- Information retrieval
- Large sorted datasets
- Distributed storage systems
- Analytics pipelines

---

# 📂 Suggested Repository Structure

```text
Distribution-Based-Searching/
│
├── InterpolationSearch.c
├── InterpolationSearch.cpp
├── InterpolationSearch.java
├── InterpolationSearch.py
├── InterpolationSearch.js
│
├── AdaptiveInterpolationSearch.c
├── AdaptiveInterpolationSearch.cpp
├── AdaptiveInterpolationSearch.java
├── AdaptiveInterpolationSearch.py
├── AdaptiveInterpolationSearch.js
│
├── QuadraticBinarySearch.c
├── QuadraticBinarySearch.cpp
├── QuadraticBinarySearch.java
├── QuadraticBinarySearch.py
├── QuadraticBinarySearch.js
│
├── InterpolationBinaryHybrid.c
├── InterpolationBinaryHybrid.cpp
├── InterpolationBinaryHybrid.java
├── InterpolationBinaryHybrid.py
├── InterpolationBinaryHybrid.js
│
└── README.md
```

---

## ⭐ If this repository helped you

Give it a star and contribute more advanced searching algorithms.

**Happy Coding 🚀**
