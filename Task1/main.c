#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <blis.h>

int main()
{
    dim_t m = 16384;
    dim_t n = 16384;
    dim_t k = 16384;

    double alpha = 1.0;
    double beta = 0.0;

    double *A = (double *)malloc(m * k * sizeof(double));
    double *B = (double *)malloc(k * n * sizeof(double));
    double *C = (double *)malloc(m * n * sizeof(double));

    if (A == NULL || B == NULL || C == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (long long i = 0; i < (long long)m * k; i++)
        A[i] = 1.0;

    for (long long i = 0; i < (long long)k * n; i++)
        B[i] = 1.0;

    FILE *fp = fopen("flops_results_16k.txt", "w");

    if (fp == NULL)
    {
        printf("Unable to create file.\n");
        return 1;
    }

    fprintf(fp, "Run\tTime(s)\tFLOPS\n");

    for (int run = 1; run <=20; run++)
    {
        for (long long i = 0; i < (long long)m * n; i++)
            C[i] = 0.0;

        clock_t start = clock();

        bli_dgemm(
            BLIS_NO_TRANSPOSE,
            BLIS_NO_TRANSPOSE,
            m,
            n,
            k,
            &alpha,
            A,
            1,
            m,
            B,
            1,
            k,
            &beta,
            C,
            1,
            m);

        clock_t end = clock();

        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

        double operations = 2.0 * m * n * k;

        double flops = operations / time_taken;

        fprintf(fp, "%.2e\n", flops);

        printf("Run %d completed\n", run);
    }

    fclose(fp);

    free(A);
    free(B);
    free(C);

    printf("Results saved to flops_results_2k.txt\n");

    return 0;
}