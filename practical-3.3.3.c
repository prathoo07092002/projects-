#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VECTOR_SIZE 200

void vector_scalar_addition_nowait(int* vec, int scalar) {
    #pragma omp parallel
    {
        #pragma omp for nowait
        for (int i = 0; i < VECTOR_SIZE / 2; i++) {
            vec[i] += scalar;
        }

        #pragma omp for nowait
        for (int i = VECTOR_SIZE / 2; i < VECTOR_SIZE; i++) {
            vec[i] += scalar;
        }

        // Other independent parallel work can be done here
        #pragma omp for
        for (int i = 0; i < VECTOR_SIZE; i++) {
            vec[i] *= 2;
        }
    }
}

int main() {
    int vec[VECTOR_SIZE];
    int scalar = 10;
    double start, end;

    // Initialize vector with random values
    srand(time(NULL));
    for (int i = 0; i < VECTOR_SIZE; i++) {
        vec[i] = rand() % 100;
    }

    start = omp_get_wtime();
    vector_scalar_addition_nowait(vec, scalar);
    end = omp_get_wtime();
    printf("Vector Scalar Addition with nowait took %f seconds\n", end - start);

    return 0;
}
