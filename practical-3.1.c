#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// Function to compare two elements (for qsort)
int compareAsc(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Function to compare two elements in descending order (for qsort)
int compareDesc(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

// Function to calculate the minimum scalar product
int minScalarProduct(int *vec1, int *vec2, int n) {
    // Sort vec1 in ascending order
    qsort(vec1, n, sizeof(int), compareAsc);

    // Sort vec2 in descending order
    qsort(vec2, n, sizeof(int), compareDesc);

    // Calculate the scalar product using OpenMP
    int product = 0;
    #pragma omp parallel for reduction(+:product)
    for (int i = 0; i < n; i++) {
        product += vec1[i] * vec2[i];
    }
    return product;
}

int main() {
    int vec1[] = {1, 3, 5};
    int vec2[] = {2, 4, 6};
    int n = sizeof(vec1) / sizeof(vec1[0]);

    // Set the number of threads (optional)
    omp_set_num_threads(4);

    int result = minScalarProduct(vec1, vec2, n);

    printf("Minimum Scalar Product: %d\n", result);
    return 0;
}
