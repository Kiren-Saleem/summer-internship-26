# README

## BLIS DGEMM Performance Benchmark

### Overview

This project benchmarks the performance of the **BLIS (BLAS-like Library Instantiation Software)** library by measuring the floating-point performance (FLOPS) of double-precision matrix multiplication (`DGEMM`). The benchmark was performed on matrices of different sizes (2K, 4K, 8K, and 16K) to observe how computational performance changes with increasing workload.

---

## Objective

The purpose of this project is to:

* Measure the floating-point performance (FLOPS) of BLIS DGEMM.
* Compare performance across different matrix sizes.
* Analyze the consistency of BLIS for dense matrix multiplication.
* Record benchmark results for further analysis.

---

## System Specifications

| Component            | Specification                  |
| -------------------- | ------------------------------ |
| Processor            | Intel Core i7-1355U (13th Gen) |
| Cores / Threads      | 10 Cores / 12 Threads          |
| Operating System     | Ubuntu Linux                   |
| Programming Language | C                              |
| Library Used         | BLIS                           |

---

## Implementation

The benchmark program performs the following steps:

1. Allocates memory for three matrices (**A**, **B**, and **C**).
2. Initializes matrices **A** and **B** with constant values (`1.0`).
3. Resets matrix **C** before every benchmark run.
4. Performs matrix multiplication using the BLIS function:

```c
bli_dgemm(...)
```

5. Measures execution time.
6. Computes FLOPS using:

[
\text{FLOPS} = \frac{2 \times N^3}{\text{Execution Time}}
]

where **N** is the matrix dimension.

7. Stores the FLOPS value for each run in a text file.

---

## Results Summary

The benchmark was executed for four different matrix sizes.

| Matrix Size   | Average FLOPS (Approx.) |
| ------------- | ----------------------: |
| 2048 × 2048   |          **2.8 × 10¹⁰** |
| 4096 × 4096   |          **2.8 × 10¹⁰** |
| 8192 × 8192   |          **2.9 × 10¹⁰** |
| 16384 × 16384 |          **4.7 × 10¹⁰** |

---

## Observations

* **2K Matrix:** Performance remained around **2.8 × 10¹⁰ FLOPS**, with minor variation between runs due to normal system activity.
* **4K Matrix:** Performance was stable and similar to the 2K benchmark, indicating efficient cache utilization.
* **8K Matrix:** FLOPS increased slightly and remained consistent across runs, demonstrating better processor utilization for larger workloads.
* **16K Matrix:** This benchmark achieved the highest performance, averaging approximately **4.7 × 10¹⁰ FLOPS**. The larger matrix size allowed BLIS to utilize the CPU more effectively, resulting in significantly higher computational throughput.

---

## Conclusion

The benchmark demonstrates that the BLIS library provides efficient and consistent performance for dense matrix multiplication. While smaller matrices achieved stable performance, the **16K × 16K** benchmark produced the highest FLOPS, showing that BLIS performs better as the computational workload increases. These results highlight the suitability of BLIS for high-performance numerical and scientific computing applications.



The program generates a text file containing the FLOPS measured for each benchmark run, which can be used for further analysis or visualization.
