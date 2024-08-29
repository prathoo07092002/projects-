#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define ARRAY_SIZE 10000

int main() {
    int array[ARRAY_SIZE];
    long long total_sum = 0;

    // Initialize array with random values
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 100;
    }

    // Parallel region with reduction clause
    // #pragma omp parallel reduction(+:total_sum)
    // {
    //     #pragma omp for
    //     for (int i = 0; i < ARRAY_SIZE; i++) {
    //         total_sum += array[i];
    //     }
    // }

 #pragma omp parallel for reduction(+:total_sum)
     for (int i = 0; i < ARRAY_SIZE; i++) {
            total_sum += array[i];
        }
    printf("Parallel total sum with reduction: %lld\n", total_sum);
    total_sum=0;
  for (int i = 0; i < ARRAY_SIZE; i++) {
        total_sum += array[i];
    }

    printf("Sequential total sum: %lld\n", total_sum);

    return 0;
}
