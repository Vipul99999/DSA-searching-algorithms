# Perfect Hashing

Perfect Hashing is a hashing technique that guarantees **collision-free searching** for a predefined set of keys.

Unlike traditional hashing methods that resolve collisions after they occur, Perfect Hashing constructs hash functions in a way that maps each key to a unique storage location.

This allows deterministic constant-time retrieval and makes Perfect Hashing highly effective for **static datasets and read-heavy systems**.

---

## Table of Contents

* Introduction
* Motivation
* Core Idea
* Types of Perfect Hashing
* Search Workflow
* Construction Process
* Example
* Complexity Analysis
* Advantages
* Limitations
* Applications
* Comparison
* Conclusion

---

# Introduction

Standard hashing may create collisions:

```text id="v8ylam"
A → 4
B → 4
```

Perfect hashing eliminates collisions:

```text id="ax75mq"
A → 4
B → 7
```

Each key maps uniquely.

---

# Motivation

Collision handling introduces overhead.

Perfect hashing aims for:

```text id="2thkkd"
Unique Mapping
↓
Direct Retrieval
```

Ideal for fixed datasets.

---

# Core Idea

Construct hash functions so:

```text id="sny7ji"
∀ Keys
Unique Position
```

No probing.

No chaining.

No relocation.

---

# Types of Perfect Hashing

## Minimal Perfect Hashing

Maps:

```text id="ffz7zq"
n Keys → n Slots
```

No unused positions.

---

## Non-Minimal Perfect Hashing

Allows extra space.

Goal:

```text id="0kzh95"
No Collisions
```

---

# Search Workflow

```text id="j2w9j5"
Input Key
↓
Compute Hash
↓
Access Slot
↓
Return Result
```

---

# Construction Process

Build phase:

```text id="5smjlwm"
Input Dataset
↓
Generate Hash Function
↓
Validate Collisions
↓
Store Mapping
```

Search phase:

```text id="4kkg8m"
Compute
↓
Retrieve
```

---

# Example

Dataset:

```text id="twbnj5"
Apple
Orange
Mango
```

Mapping:

```text id="86y20x"
Apple → 2
Orange → 5
Mango → 7
```

Search:

```text id="gl4w0g"
Hash(Key)
↓
Access
↓
Return
```

---

# Complexity Analysis

| Operation | Complexity             |
| --------- | ---------------------- |
| Search    | O(1)                   |
| Insert    | Construction Dependent |
| Delete    | Limited                |
| Build     | O(n)–O(n²)             |

Space Complexity:

```text id="5v5nn0"
O(n)
```

---

# Advantages

* Collision-free retrieval
* Deterministic performance
* Constant lookup
* Excellent read efficiency

---

# Limitations

* Expensive construction
* Limited dynamic updates
* Best for static datasets

---

# Applications

* Compiler symbol tables
* Static dictionaries
* Search engines
* Keyword indexing
* Read-heavy systems
* Embedded lookup tables

---

# Comparison

| Method          | Collision  |
| --------------- | ---------- |
| Hash Table      | Possible   |
| Cuckoo Hashing  | Relocation |
| Perfect Hashing | None       |

---

# Conclusion

Perfect Hashing achieves deterministic constant-time lookup by constructing collision-free mappings for fixed key sets. Its efficiency and predictability make it ideal for static indexing and high-performance retrieval systems.
