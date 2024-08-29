#include <stdio.h>
#include <omp.h>

#define N 4  // You can change this size

int main() {
    int A[N][N], B[N][N], C[N][N];
    
    // Initialize matrices A and B with some values
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = i + j;
            B[i][j] = i - j;
            C[i][j] = 0;  // Initialize matrix C to zero
        }
    }

    // Parallel Matrix-Matrix Multiplication
    #pragma omp parallel for collapse(2) // 'collapse(2)' collapses the two loops into a single loop
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print the resulting matrix C
    printf("Resultant Matrix C:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
