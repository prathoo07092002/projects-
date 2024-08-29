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

    // Parallel region to calculate sum
    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < ARRAY_SIZE; i++) {
            #pragma omp atomic
            total_sum += array[i];
        }
    }

    printf("Parallel total sum (using atomic): %d\n", total_sum);

    return 0;
}
