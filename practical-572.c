#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include<time.h>
#define ARRAY_SIZE 1000

int main() {
    int array[ARRAY_SIZE];
    int total_sum = 0;

    // Initialize array with random values
    srand(time(0));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Parallel region to calculate sum
    #pragma omp parallel
    {
        #pragma omp for
        for (int i = 0; i < ARRAY_SIZE; i++) {
            total_sum += array[i]; // Potential data race
        }
    }

    printf("Parallel total sum (unsynchronized): %d\n", total_sum);
    total_sum=0;
   for (int i = 0; i < ARRAY_SIZE; i++) {
        total_sum += array[i];
    }

    printf("Serial actual total sum: %d\n", total_sum);

    return 0;
}
