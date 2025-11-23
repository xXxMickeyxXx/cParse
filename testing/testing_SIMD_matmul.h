#define ACCELERATE_NEW_LAPACK 1
#include <stdio.h>
#include <Accelerate/Accelerate.h>


void multiply_matrices_accelerate(float *A, float *B, float *C, int M, int N, int P) {
    // A: M rows, P columns
    // B: P rows, N columns
    // C: M rows, N columns
    cblas_sgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
                M, N, P, 
                1.0, A, P, 
                B, N, 
                0.0, C, N);
}


static void __SIMD_intrinsics_example(void) {
    // Example for 4x4 matrices
    int M = 4, N = 4, P = 4;
    
    float A[] = {1, 0, 0, 0, 
                 0, 1, 0, 0, 
                 0, 0, 1, 0, 
                 0, 0, 0, 1}; // Identity matrix
    
    float B[] = {1,  2,  3,  4, 
                 5,  6,  7,  8, 
                 9,  10, 11, 12, 
                 13, 14, 15, 16};
    float C[16] = {0};

    multiply_matrices_accelerate(A, B, C, M, N, P);

    printf("Result matrix C:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.0f ", C[i * N + j]);
        }
        printf("\n");
    }
}
