#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VECTOR_SIZE 200

void vector_scalar_addition_dynamic(int* vec, int scalar, int chunk_size) {
    #pragma omp parallel for schedule(dynamic, chunk_size)
    for (int i = 0; i < VECTOR_SIZE; i++) {
        vec[i] += scalar;
    }
}

int main() {
    int vec[VECTOR_SIZE];
    int scalar = 10;
    int chunk_size[] = {1, 2, 4, 8, 16, 32}; // Varying chunk sizes
    double start, end;

    // Initialize vector with random values
    srand(time(NULL));
    for (int i = 0; i < VECTOR_SIZE; i++) {
        vec[i] = rand() % 100;
    }

    for (int i = 0; i < 6; i++) {
        start = omp_get_wtime();
        vector_scalar_addition_dynamic(vec, scalar, chunk_size[i]);
        end = omp_get_wtime();
        printf("Dynamic Schedule with chunk size %d took %f seconds\n", chunk_size[i], end - start);
    }

    return 0;
}
