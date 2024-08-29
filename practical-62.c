#include <stdio.h>
#include <omp.h>

#define N 4  // You can change this size

int main() {
    int A[N][N], x[N], y[N];
    
    // Initialize matrix A and vector x with some values
    for (int i = 0; i < N; i++) {
        x[i] = i;  // Initialize vector x
        y[i] = 0;  // Initialize result vector y to zero
        for (int j = 0; j < N; j++) {
            A[i][j] = i + j;  // Initialize matrix A
        }
    }

    // Parallel Matrix-Vector Multiplication
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            y[i] += A[i][j] * x[j];
        }
    }

    // Print the resulting vector y
    printf("Resultant Vector y:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", y[i]);
    }
    printf("\n");

    return 0;
}

