# Binary Search Tree (BST)

> The Binary Search Tree (BST) is one of the most fundamental ordered data structures in computer science. It organizes data hierarchically while maintaining a strict ordering property that enables efficient searching, insertion, deletion, and traversal. Nearly every advanced search tree—from AVL Trees to Red-Black Trees and B-Trees—builds upon the concepts introduced by the BST.

---

# Table of Contents

- Why This Tree Exists
- Core Idea
- Mental Model
- Historical Background
- Properties
- Terminology
- Binary Search Tree Property
- Invariants
- Node Structure
- Example Trees
- How BST Organizes Data
- Common Edge Cases
- Summary

---

# Why This Tree Exists

Imagine you have thousands or even millions of values.

```
15 8 21 4 10 17 28 2 6 9 13 ...
```

How should they be stored?

One possibility is an array.

Searching inside an unsorted array requires checking elements one by one.

```
1
5
8
12
...
```

Worst Case

```
O(n)
```

A sorted array improves searching.

```
1 3 5 7 9 12 18
```

Searching becomes

```
O(log n)
```

using Binary Search.

However, inserting a new value into a sorted array requires shifting many elements.

```
Insert 6

1 3 5 7 9

↓

1 3 5 6 7 9
```

Insertion becomes

```
O(n)
```

Likewise, deletion also requires shifting elements.

Arrays therefore have conflicting strengths:

| Operation | Sorted Array |
|------------|-------------|
| Search | Excellent |
| Insert | Poor |
| Delete | Poor |

The Binary Search Tree was invented to solve this problem.

Instead of storing data linearly, BST stores it hierarchically.

Searching follows only one path from the root instead of scanning the entire dataset.

Insertion does not require shifting memory.

Deletion changes only a few links instead of moving many elements.

---

# Historical Background

Binary Search Trees originated from early work on dynamic ordered sets.

Unlike binary search on arrays, BSTs support continuous insertion and deletion without reorganizing the entire structure.

They became the conceptual foundation for almost every balanced search tree developed later.

Examples include

- AVL Tree
- Red-Black Tree
- Treap
- Splay Tree
- WAVL Tree
- B-Tree family
- Order Statistic Tree

Understanding BST means understanding the language spoken by almost every modern search tree.

---

# Core Idea

The BST follows one simple rule.

## Smaller values go left.

## Larger values go right.

Everything else follows naturally.

Consider

```
50
30
80
20
40
70
90
```

The tree becomes

```text
          50
        /    \
      30      80
     /  \    /  \
   20   40 70   90
```

Observe

Every left child is smaller.

Every right child is larger.

This ordering recursively applies to every subtree.

That recursive ordering is the entire power of BST.

---

# Mental Model

Imagine a company hierarchy.

```
CEO

Employees with smaller IDs
      ↓
Left Department

Employees with larger IDs
      ↓
Right Department
```

Whenever a new employee arrives,

you ask only one question.

```
Smaller?

Go Left.

Larger?

Go Right.
```

Repeat until an empty position appears.

No searching through every employee.

No shifting existing employees.

Only decisions.

---

Another way to think about BST:

Imagine a sequence of doors.

```
          50

      Is x < 50 ?

       Yes     No

      30       80

 Is x <30?  Is x<80?

...
```

Every node is a decision.

Eventually one decision leads directly to the answer.

---

# Properties

A Binary Search Tree has several important properties.

| Property | Description |
|-----------|-------------|
| Binary Tree | Every node has at most two children. |
| Ordered | Left subtree contains smaller keys. |
| Recursive | Every subtree is also a BST. |
| Dynamic | Supports insertion and deletion without shifting memory. |
| Hierarchical | Data is organized into levels. |
| Traversable | Supports multiple traversal orders. |

---

# Important Terminology

## Root

Top-most node.

```
      50
```

---

## Parent

Node directly above another node.

```
      50
     /
   30
```

50 is parent of 30.

---

## Child

Node directly below another node.

```
30
```

is child of

```
50
```

---

## Leaf

Node with no children.

```
20

40

70

90
```

---

## Internal Node

Any node having at least one child.

```
50

30

80
```

---

## Height

Longest path from node to a leaf.

---

## Depth

Distance from root.

---

## Subtree

Every node is itself the root of another tree.

Example

```
      80
     /  \
   70   90
```

This entire structure is a subtree.

---

# Binary Search Tree Property

The defining property is:

For every node:

```
Left Subtree

<

Current Node

<

Right Subtree
```

Notice carefully:

It does **not** only compare immediate children.

It compares entire subtrees.

Example

```
        40

      /    \

    20      60

   /  \

10   35
```

Everything under 20 must remain smaller than 40.

Even

```
35
```

must satisfy

```
35 < 40
```

not merely

```
35 > 20
```

This recursive property guarantees efficient searching.

---

# Invariants

An invariant is a rule that must always remain true.

If an invariant breaks,

the structure is no longer a Binary Search Tree.

---

## Invariant 1

Every key in the left subtree

is smaller than the current node.

```
        50

      /

    30

   /

20
```

Valid.

---

## Invariant 2

Every key in the right subtree

is larger than the current node.

```
50

  \

   80
```

Valid.

---

## Invariant 3

Every subtree is itself a Binary Search Tree.

```
          50

        /    \

      30      80

     /  \

   20   40
```

The subtree rooted at 30 satisfies all BST rules independently.

Likewise, the subtree rooted at 80 does too.

---

## Invariant 4

No cycles.

The structure must remain a tree.

```
A → B → C

↑     |

└─────┘
```

Invalid.

---

## Invariant 5

Every node has exactly one parent

except the root.

---

# Node Structure

Conceptually, every BST node stores:

- A key (used for ordering)
- Associated value (optional)
- Left child reference
- Right child reference

Conceptually:

```text
+----------------------+
|        Node          |
+----------------------+
| Key                  |
| Value (optional)     |
| Left Child           |
| Right Child          |
+----------------------+
```

The key determines where the node belongs.

The left and right references connect the hierarchical structure.

Nothing more is required for a basic BST.

---

# Example BST

Suppose we insert

```
50

30

80

20

40

70

90

10

25

35

45
```

The resulting tree becomes

```text
                 50
              /      \
            30        80
          /   \      /  \
        20    40    70   90
       / \    / \
     10 25  35 45
```

Observe:

- All left descendants are smaller.
- All right descendants are larger.
- Every subtree independently satisfies BST ordering.

This recursive structure is what enables efficient operations.

---

# How BST Organizes Data

Unlike arrays, a BST does **not** store elements in insertion order or contiguous memory.

Instead, each comparison guides the new key into its correct position.

For example, inserting `35`:

```text
35 < 50  → go left
35 > 30  → go right
35 < 40  → go left

Insert here.
```

Only a single path is explored from the root to a leaf. The rest of the tree is never examined.

This decision-making process is the essence of BST efficiency.

---

# Common Edge Cases

Keep these situations in mind when reasoning about BSTs:

| Scenario | What Happens |
|----------|--------------|
| Empty tree | First inserted node becomes the root. |
| Single node | Root is also a leaf. |
| Strictly increasing insertions | Tree becomes completely right-skewed. |
| Strictly decreasing insertions | Tree becomes completely left-skewed. |
| Duplicate keys | Depends on implementation (reject, count frequency, or store duplicates consistently). |
| Random insertions | Often produce a reasonably balanced tree, though not guaranteed. |

These edge cases are important because the shape of the tree directly affects performance.

---

# Part 1 Summary

After this section, you should understand:

- Why Binary Search Trees were invented.
- The ordering rule that defines a BST.
- The recursive nature of BSTs.
- The essential invariants that must always hold.
- The conceptual structure of a BST node.
- How keys are organized within the tree.
- Why the tree's shape determines its efficiency.

In the next part, we'll cover the conceptual workflows for **Search, Insert, Delete, Update, Traversals**, along with complexity analysis and visual walkthroughs.

# Types of Binary Search Trees

Although people often refer to "the Binary Search Tree" as a single data structure, there are several important variants. Most advanced search trees are improvements or specializations of the basic BST.

---

## 1. Standard (Unbalanced) BST

This is the classical Binary Search Tree.

Characteristics:

- No balancing mechanism.
- Simple implementation.
- Performance depends on insertion order.
- Can become skewed.

Example

```text
        50
       /  \
     30    80
    / \    / \
   20 40 70 90
```

### Advantages

- Very easy to understand.
- Minimal implementation complexity.
- Good for learning.

### Disadvantages

- Worst-case operations become O(n).

---

## 2. Balanced BST

A balanced BST maintains its height close to `log₂(n)`.

Instead of allowing arbitrary growth, the tree reorganizes itself after updates.

Examples include:

- AVL Tree
- Red-Black Tree
- WAVL Tree
- AA Tree
- Scapegoat Tree

Example

```text
            40
          /    \
        20      60
       / \     / \
     10 30   50 70
```

Balanced trees guarantee efficient operations.

---

## 3. Self-Balancing BST

A self-balancing BST automatically restores balance after insertion or deletion.

Instead of relying on random insertion order, the tree actively maintains height constraints.

Examples

- AVL Tree
- Red-Black Tree
- Treap
- Splay Tree
- Scapegoat Tree
- WAVL Tree

These are the trees commonly used in production systems.

---

## 4. Threaded BST

A Threaded BST replaces some `NULL` child pointers with links to predecessor or successor nodes.

Instead of

```text
NULL
```

the pointer may reference

```text
Previous Node

or

Next Node
```

Benefits

- Faster inorder traversal
- Less recursion
- No stack required for traversal

---

## 5. Persistent BST

A Persistent BST preserves previous versions of the tree.

Every modification creates a new version without destroying older versions.

Example

```
Version 1

↓

Version 2

↓

Version 3
```

Applications

- Version control
- Functional programming
- Time-travel queries

---

## 6. Randomized BST

Randomized BSTs use randomness to keep the tree approximately balanced.

Instead of deterministic balancing rules,

probability is used to prevent degeneration.

Examples

- Randomized BST
- Treap
- Zip Tree

---

## 7. Augmented BST

An augmented BST stores additional information in every node.

Examples

```text
Node

Key

Left

Right

Subtree Size

Height

Color

Priority

Frequency
```

Augmentations enable efficient implementation of

- Order Statistic Trees
- Interval Trees
- Segment Trees
- Range Trees

---

## BST Family Overview

| Tree | Balanced | Worst Case | Typical Use |
|------|----------|------------|-------------|
| BST | ❌ | O(n) | Learning, simple ordered sets |
| AVL | ✅ | O(log n) | Search-heavy applications |
| Red-Black | ✅ | O(log n) | Standard libraries |
| Treap | Probabilistic | Expected O(log n) | Competitive programming |
| Splay | Adaptive | Amortized O(log n) | Locality of reference |
| Scapegoat | ✅ | O(log n) | Rotation-free balancing |
| WAVL | ✅ | O(log n) | Balanced search tree research |

---

# Comparison with Other Trees

The Binary Search Tree is the foundation of nearly every ordered tree structure.

Understanding its strengths and weaknesses explains why many other trees were invented.

---

## BST vs Sorted Array

| Feature | BST | Sorted Array |
|----------|-----|--------------|
| Search | O(log n) average | O(log n) |
| Insert | O(log n) average | O(n) |
| Delete | O(log n) average | O(n) |
| Memory | Dynamic | Contiguous |
| Traversal | Easy | Easy |

Choose a sorted array when the dataset rarely changes.

Choose a BST when insertions and deletions are frequent.

---

## BST vs AVL Tree

| BST | AVL |
|------|-----|
| Simpler | More complex |
| May become skewed | Always balanced |
| Faster insertion (less maintenance) | Faster searching |
| O(n) worst case | O(log n) guaranteed |

AVL is essentially a BST with automatic balancing.

---

## BST vs Red-Black Tree

| BST | Red-Black |
|------|-----------|
| No balancing | Self-balancing |
| Simpler | More implementation complexity |
| Unpredictable height | Guaranteed logarithmic height |
| Better for teaching | Better for production |

---

## BST vs B-Tree

| BST | B-Tree |
|------|---------|
| Binary children | Multiple children |
| RAM oriented | Disk oriented |
| Small branching factor | Large branching factor |
| Pointer-heavy | Cache-friendly |

B-Trees dominate database indexing.

---

## BST vs Trie

| BST | Trie |
|------|------|
| Ordered keys | Prefix-based strings |
| General comparable keys | Mainly strings |
| Logarithmic search | Search depends on key length |
| Compact | Can consume more memory |

---

## BST vs Hash Table

| BST | Hash Table |
|------|------------|
| Ordered | Unordered |
| Supports range queries | Does not |
| Min/Max efficient | Difficult |
| O(log n) average | O(1) average |

If ordering matters,

BST is preferable.

If only exact lookup matters,

hash tables are often faster.

---

# Real-World Usage

Although self-balancing trees are more common in production, the basic BST remains conceptually important.

---

## Compiler Design

Compilers use BST-based concepts for

- symbol tables
- identifier lookup
- optimization passes

---

## Database Systems

Modern databases typically use B+ Trees rather than plain BSTs, but the underlying concepts of ordered searching and hierarchical indexing originate from BST principles.

---

## In-Memory Ordered Collections

BSTs are useful when

- maintaining sorted data
- supporting predecessor/successor queries
- implementing ordered dictionaries
- educational implementations

---

## Competitive Programming

BST concepts appear frequently in problems involving

- ordered sets
- interval management
- coordinate compression
- order statistics
- balanced tree reasoning

While contestants often use library containers, understanding BST mechanics is essential.

---

## Operating Systems

Tree-based indexing concepts appear in

- schedulers
- virtual memory management
- filesystem indexing

Usually through balanced variants rather than plain BSTs.

---

# Common Mistakes

## Mistake 1

Thinking only immediate children matter.

Incorrect

```text
      40
     /
   20
     \
      50
```

Although `50 > 20`, it is in the left subtree of `40`, violating the BST property.

Always consider the **entire subtree**, not just parent-child relationships.

---

## Mistake 2

Believing a BST is always balanced.

A plain BST provides **no balancing guarantee**.

---

## Mistake 3

Ignoring insertion order.

The same values inserted in different orders can produce very different tree shapes and performance.

---

## Mistake 4

Assuming deletion is simple.

Deleting a node with two children requires careful restructuring using the inorder successor or predecessor.

---

## Mistake 5

Confusing BSTs with heaps.

A BST maintains **ordering**.

A heap maintains **priority**.

They solve different problems.

---

## Mistake 6

Assuming inorder traversal works for any binary tree.

Only a Binary Search Tree guarantees that inorder traversal produces sorted output.

---

## Mistake 7

Ignoring duplicate key policy.

Every implementation must clearly define how duplicate keys are handled.

Common strategies include:

- Reject duplicates.
- Store a frequency count.
- Consistently place duplicates on one side.

Ambiguity here can lead to incorrect behavior.
