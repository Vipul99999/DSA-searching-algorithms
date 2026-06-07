# Locality Sensitive Hashing (LSH)

> Locality Sensitive Hashing (LSH) is a probabilistic hashing technique designed for similarity search in high-dimensional spaces. Unlike traditional hashing, similar items are intentionally mapped to the same buckets with high probability.

---

# Table of Contents

1. Introduction
2. Why Traditional Hashing Fails
3. Definition
4. Core Idea
5. Mathematical Foundation
6. Similarity Metrics
7. LSH Families
8. Search Process
9. Example Walkthrough
10. Approximate Nearest Neighbor Search
11. Complexity Analysis
12. Advantages
13. Disadvantages
14. Real-World Applications
15. LSH in AI Systems
16. Vector Databases
17. Interview Questions
18. Summary

---

# Introduction

Traditional hash tables are designed so that:

```text
Different Keys
↓
Different Buckets
```

This is perfect for exact lookup.

However:

```text
AI
Images
Embeddings
Documents
Vectors
```

often require:

```text
Similarity Search
```

rather than exact matching.

LSH was created for this purpose.

---

# Why Traditional Hashing Fails

Traditional Hashing:

```text
Dog
Dogs
```

produce completely different hashes.

Even though they are semantically similar.

This makes nearest-neighbor search difficult.

---

# Definition

Locality Sensitive Hashing is a hashing technique where similar objects have a high probability of being assigned to the same bucket.

---

# Core Idea

Traditional Hashing:

```text
Similar Objects
↓
Different Buckets
```

LSH:

```text
Similar Objects
↓
Same Bucket
```

with high probability.

---

# Mathematical Foundation

For objects:

```text
x
y
```

Similarity:

```text
sim(x,y)
```

LSH property:

```
P[h(x)=h(y)]
```

increases as:

```
sim(x,y)
```

increases.

---

# Similarity Metrics

LSH supports many metrics.

---

## Cosine Similarity

```
cos(θ)
```

Common in NLP.

---

## Euclidean Distance

```
||x-y||
```

Common in vector search.

---

## Jaccard Similarity

```
|A∩B| / |A∪B|
```

Common in document matching.

---

# LSH Families

## MinHash

For Jaccard Similarity.

---

## SimHash

For text similarity.

---

## Random Projection LSH

For cosine similarity.

---

## p-Stable LSH

For Euclidean distance.

---

# Search Process

Step 1

Hash query vector.

---

Step 2

Locate candidate bucket.

---

Step 3

Retrieve nearby vectors.

---

Step 4

Compute exact similarity.

---

Step 5

Return nearest neighbors.

---

# Example Walkthrough

Document Embeddings:

```text
Doc A
Doc B
Doc C
```

Hash Results:

```text
Bucket 10:
A
B
```

```text
Bucket 25:
C
```

Query:

```text
A
```

Search:

```text
Bucket 10
```

Candidates:

```text
A
B
```

Result:

```text
B is similar
```

---

# Approximate Nearest Neighbor Search

Exact Search:

```text
Compare with all vectors
```

Complexity:

```text
O(n)
```

LSH:

```text
Search only candidate buckets
```

Sub-linear complexity.

---

# Complexity Analysis

| Operation | Complexity |
|------------|------------|
| Build | O(n) |
| Query | O(log n) Approx |
| Similarity Check | O(k) |

k = candidate vectors

---

# Advantages

## Extremely Fast

Massive datasets.

---

## Scalable

Millions or billions of vectors.

---

## High-Dimensional Friendly

Works where KD-Trees fail.

---

## AI Optimized

Designed for embeddings.

---

# Disadvantages

## Approximate Results

Not always exact.

---

## Extra Storage

Multiple hash tables often required.

---

## Parameter Tuning

Requires careful configuration.

---

# Real-World Applications

## Image Search

Find visually similar images.

---

## Face Recognition

Embedding lookup.

---

## Recommendation Systems

Similar users/products.

---

## Plagiarism Detection

Document similarity.

---

## Audio Fingerprinting

Music matching.

---

# LSH in AI Systems

Modern AI relies heavily on vector similarity.

Examples:

```text
Embeddings
Semantic Search
Retrieval Systems
Recommendation Engines
```

LSH accelerates these operations.

---

# Vector Databases

LSH concepts appear in:

- FAISS
- Milvus
- Weaviate
- Pinecone
- Vespa

for approximate nearest-neighbor search.

---

# Interview Questions

1. What is Locality Sensitive Hashing?
2. Why is LSH different from normal hashing?
3. What is Approximate Nearest Neighbor Search?
4. Explain MinHash.
5. Explain SimHash.
6. Why is LSH useful in AI?

---

# Summary

Locality Sensitive Hashing (LSH) is one of the most important similarity-search techniques in modern computing. Unlike traditional hashing, it intentionally groups similar objects together, making it indispensable for AI systems, vector databases, recommendation engines, image retrieval, semantic search, and large-scale nearest-neighbor applications.
