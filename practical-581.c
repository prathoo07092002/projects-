#include <stdio.h>
#include <stdlib.h>
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

    // Calculate sum sequentially
    for (int i = 0; i < ARRAY_SIZE; i++) {
        total_sum += array[i];
    }

    printf("Sequential total sum: %lld\n", total_sum);

    return 0;
}
