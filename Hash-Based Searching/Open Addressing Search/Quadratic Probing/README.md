# Quadratic Probing

> Quadratic Probing is an Open Addressing collision-resolution technique that uses quadratic increments instead of linear increments to reduce clustering.

---

# Definition

Instead of moving:

```text
+1
+2
+3
+4
```

Quadratic probing moves:

```text
+1²
+2²
+3²
+4²
```

---

# Mathematical Formula

General form:

hᵢ(k) = (h(k) + c₁i + c₂i²) mod m

Common form:

hᵢ(k) = (h(k) + i²) mod m

---

# Core Idea

Spread probes farther apart.

Reduce clustering.

Improve table utilization.

---

# Example

Table Size = 11

Hash Function:

h(k) = k mod 11

Insert:

22

33

44

All hash to:

0

---

# Probe Sequence

22:

```text
0
```

33:

```text
0 occupied

0 + 1² = 1
```

Store at 1.

44:

```text
0 occupied

1 occupied

0 + 2² = 4
```

Store at 4.

Result:

```text
0 → 22

1 → 33

4 → 44
```

---

# Search Algorithm

```text
SEARCH(key)

i = 0

while slot occupied

    index = (hash(key) + i²) mod table_size

    if key found
        return FOUND

    i++

return NOT_FOUND
```

---

# Complexity

| Case | Complexity |
|--------|-------------|
| Best | O(1) |
| Average | O(1) |
| Worst | O(n) |

---

# Secondary Clustering

Quadratic Probing removes most primary clustering.

However:

Keys with same hash value follow the same sequence.

This causes:

```text
Secondary Clustering
```

---

# Advantages

- Less clustering than Linear Probing
- Better distribution
- Good cache locality
- Efficient memory usage

---

# Disadvantages

- Secondary clustering remains
- More complex implementation
- May not visit all table slots
- Requires careful table sizing

---

# Real-World Usage

- Database indexing
- High-performance hash maps
- Memory-sensitive systems

---

# Comparison with Linear Probing

| Feature | Linear | Quadratic |
|-----------|---------|------------|
| Primary Clustering | Severe | Reduced |
| Secondary Clustering | Present | Present |
| Complexity | Simpler | More Complex |
| Performance | Lower | Better |

---

# Summary

Quadratic Probing improves upon Linear Probing by using quadratic offsets, significantly reducing primary clustering while maintaining efficient memory usage and good cache performance. It remains one of the most popular open-addressing collision-resolution techniques.
