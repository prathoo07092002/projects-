#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define ARRAY_SIZE 10000

int main() {
    int array[ARRAY_SIZE];
    int total_sum = 0;

    // Initialize array with random values
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Parallel region to calculate sum
    #pragma omp parallel
    {
        int local_sum = 0; // Local sum for each thread

        #pragma omp for
        for (int i = 0; i < ARRAY_SIZE; i++) {
            local_sum += array[i];
        }

        // Critical section to safely update the total sum
        #pragma omp critical
        {
            total_sum += local_sum;
        }
    }

    printf("Parallel total sum (using critical): %d\n", total_sum);

    return 0;
}
