#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define ARRAY_SIZE 1000000

int main() {
    int array[ARRAY_SIZE];
    int total_sum = 0;

    // Initialize array with random values
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Measure serial execution time
    double start = omp_get_wtime();
    total_sum = 0;  // Reset total_sum
    for (int i = 0; i < ARRAY_SIZE; i++) {
        total_sum += array[i];
    }
    double end = omp_get_wtime();
    printf("Serial execution time: %f seconds\n", end - start);

    // Measure parallel execution time with critical
    start = omp_get_wtime();
    total_sum = 0;  // Reset total_sum
    #pragma omp parallel
    {
        int local_sum = 0;

        #pragma omp for
        for (int i = 0; i < ARRAY_SIZE; i++) {
            local_sum += array[i];
        }

        #pragma omp critical
        {
            total_sum += local_sum;
        }
    }
    end = omp_get_wtime();
    printf("Parallel execution time (critical): %f seconds\n", end - start);

    // Measure parallel execution time with atomic
    start = omp_get_wtime();
    total_sum = 0;  // Reset total_sum
    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < ARRAY_SIZE; i++) {
            #pragma omp atomic
            total_sum += array[i];
        }
    }
    end = omp_get_wtime();
    printf("Parallel execution time (atomic): %f seconds\n", end - start);

    return 0;
}
