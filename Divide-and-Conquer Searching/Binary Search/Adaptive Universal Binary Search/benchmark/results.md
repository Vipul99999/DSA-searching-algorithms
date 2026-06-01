# Benchmark Results

CPU:
AMD Ryzen 9

Compiler:
GCC 15

Dataset:
10,000,000 Elements

| Search Type | Time |
|-------------|------|
| Exact Search | 1.4 us |
| Lower Bound | 1.5 us |
| Branchless | 1.2 us |
| SIMD | 0.9 us |
| Predictive | 0.6 us |