# Linear Probing

> Linear Probing is the simplest Open Addressing collision-resolution technique where collisions are resolved by checking consecutive table positions until an empty slot or target key is found.

---

# Definition

Linear Probing resolves collisions by searching sequentially through the hash table.

---

# Mathematical Formula

Initial position:

h(k)

Probe sequence:

hᵢ(k) = (h(k) + i) mod m

Where:

- i = probe number
- m = table size

---

# Core Idea

If index is occupied:

```text
Check next slot

+1
+2
+3
...
```

until success.

---

# Example

Table Size = 10

Hash Function:

h(k) = k mod 10

Insert:

15

25

35

Hashes:

15 → 5

25 → 5

35 → 5

Storage:

```text
Index

5 → 15

6 → 25

7 → 35
```

---

# Search Example

Search 35

Step 1

Hash:

35 mod 10 = 5

Step 2

Check:

Index 5 → 15

Index 6 → 25

Index 7 → 35

Found

---

# Algorithm

```text
SEARCH(key)

index = HASH(key)

while slot occupied

    if key found
        return FOUND

    index = (index + 1) mod table_size

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

# Primary Clustering

Major weakness.

Example:

```text
[ ][ ][A][B][C][D][E][ ]
```

Large occupied blocks form.

New keys likely join the cluster.

Cluster grows larger.

Performance decreases.

---

# Advantages

- Simple implementation
- Cache-friendly
- Memory efficient
- Fast for low load factors

---

# Disadvantages

- Primary clustering
- Performance degrades quickly
- High load factors cause long probes

---

# Real-World Usage

- Embedded systems
- High-performance hash tables
- Memory-constrained applications

---

# Summary

Linear Probing is the simplest open-addressing technique. It offers excellent cache performance and low memory overhead but suffers from primary clustering, making it less efficient at high load factors.
